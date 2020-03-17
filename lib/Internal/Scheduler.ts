import { GameView } from "../GameView";


export class TimeTask {
    public task: () => boolean;
    public start: number;
    public period: number;
    public duration: number;
    public next: number;

    public id: number;
    public groupId: number;
    public active: boolean;
    public paused: boolean;

    constructor() {

    }
}

export class FrameTask {
    public task: () => boolean;
    public priority: number;
    public id: number;
    public active: boolean;
    public paused: boolean;

    constructor(task: () => boolean, priority: number, id: number) {
        this.task = task;
        this.priority = priority;
        this.id = id;
        this.active = true;
        this.paused = false;
    }

}

export class Scheduler {
    private static timeTasks: Array<TimeTask>;
    private static pausedTimeTasks: Array<TimeTask>;
    private static outdatedTimeTasks: Array<TimeTask>;
    private static timeTasksScratchpad: Array<TimeTask>;
    private static timeWarpSaveTime: number = 10.0;

    private static frameTasks: Array<FrameTask>;
    private static toDeleteFrame: Array<FrameTask>;

    private static current: number;
    private static lastTime: number;

    private static frame_tasks_sorted: boolean;
    private static stopped: boolean;
    private static vsync: boolean;

    private static onedifhz: number;

    private static currentFrameTaskId: number;
    private static currentTimeTaskId: number;
    private static currentGroupId: number;

    private static DIF_COUNT = 3;
    private static maxframetime = 0.5;

    private static deltas: Array<number>;

    private static startTime: number = 0;

    private static activeTimeTask: TimeTask = null;


    static init() {
        this.deltas = new Array<number>();
        for (let i = 0; i < this.DIF_COUNT; i++) this.deltas[i] = 0;

        this.stopped = true;
        this.frame_tasks_sorted = true;
        this.current = this.lastTime = this.realTime();

        this.currentFrameTaskId = 0;
        this.currentTimeTaskId = 0;
        this.currentGroupId = 0;

        this.timeTasks = [];
        this.pausedTimeTasks = [];
        this.outdatedTimeTasks = [];
        this.timeTasksScratchpad = [];
        this.frameTasks = [];
        this.toDeleteFrame = [];
    }

    static start(restartTimers: boolean = false): void {
        this.vsync = true;
        const hz = 60 // frequency
        this.onedifhz = 1.0 / hz;

        this.stopped = false;
        this.resetTime();
        this.lastTime = this.realTime() - this.startTime;
        for (let i = 0; i < this.DIF_COUNT; i++) this.deltas[i] = 0;

        if (restartTimers) {
            for (let timeTask of this.timeTasks) {
                timeTask.paused = false;
            }

            for (let frameTask of this.frameTasks) {
                frameTask.paused = false;
            }
        }
    }

    static stop(): void {
        this.stopped = true;
    }

    static isStopped(): boolean {
        return this.stopped;
    }

    static warpTimeTasksBack(time: number, tasks: Array<TimeTask>): void {
        for (let timeTask of tasks) {
            if (timeTask.start >= time) {
                timeTask.next = timeTask.start;
            }
            else if (timeTask.period > 0) {
                var sinceStart = time - timeTask.start;
                var times = Math.ceil(sinceStart / timeTask.period);
                timeTask.next = timeTask.start + times * timeTask.period;
            }
        }
    }

    static warp(time: number): void {
        if (time < this.lastTime) {
            this.current = time;
            this.lastTime = time;

            this.warpTimeTasksBack(time, this.outdatedTimeTasks);
            this.warpTimeTasksBack(time, this.timeTasks);

            for (let task of this.outdatedTimeTasks) {
                if (task.next >= time) {
                    this.timeTasksScratchpad.push(task);
                }
            }
            for (let task of this.timeTasksScratchpad) {
                this.outdatedTimeTasks.splice(this.outdatedTimeTasks.indexOf(task), 1);
            }
            for (let task of this.timeTasksScratchpad) {
                this.insertSorted(this.timeTasks, task);
            }
            while (this.timeTasksScratchpad.length > 0) {
                this.timeTasksScratchpad.splice(0, 1)
            }
        }
        else if (time > this.lastTime) {
            // TODO: Changing startTime line prevents clients from falling into a
            // warp-forward-then-wait-for-systemtime-to-catch-up-loop that causes
            // choppy movement (e.g. every 3rd frame forward 3 times).
            // But it causes backwards jumps in originally constant movements.
            // And on HTML5 packets are received while no frames are executed,
            // which causes the client to overtakes the server and then move
            // farther away with each packet while being unable to synch back
            // (backwards warping is not allowed to change startTime).
            this.startTime -= (time - this.lastTime);

            this.current = time;
            this.lastTime = time;

            this.executeTimeTasks(time);
        }
    }


    static executeFrame(): void {
        var now: number = this.realTime() - this.startTime;
        var delta = now - this.lastTime;

        var frameEnd: number = this.current;

        if (delta >= 0) {
            // if (kha.netsync.Session.the() == null) {
            // 	//tdif = 1.0 / 60.0; //force fixed frame rate

            // 	if (delta > maxframetime) {
            // 		startTime += delta - maxframetime;
            // 		delta = maxframetime;
            // 		frameEnd += delta;
            // 	}
            // 	else {
            // 		if (vsync) {
            // 			// this is optimized not to run at exact speed
            // 			// but to run as fluid as possible
            // 			var realdif = onedifhz;
            // 			while (realdif < delta - onedifhz) {
            // 				realdif += onedifhz;
            // 			}

            // 			delta = realdif;
            // 			for (i in 0...DIF_COUNT - 2) {
            // 				delta += deltas[i];
            // 				deltas[i] = deltas[i + 1];
            // 			}
            // 			delta += deltas[DIF_COUNT - 2];
            // 			delta /= DIF_COUNT;
            // 			deltas[DIF_COUNT - 2] = realdif;

            // 			frameEnd += delta;
            // 		}
            // 		else {
            // 			for (i in 0...DIF_COUNT - 1) {
            // 				deltas[i] = deltas[i + 1];
            // 			}
            // 			deltas[DIF_COUNT - 1] = delta;

            // 			var next:number = 0;
            // 			for (i in 0...DIF_COUNT) {
            // 				next += deltas[i];
            // 			}
            // 			next /= DIF_COUNT;

            // 			//delta = interpolated_delta; // average the frame end estimation

            // 			//lastTime = now;
            // 			frameEnd += next;
            // 		}
            // 	}
            // }
            // else {
            frameEnd += delta;
            // }

            this.lastTime = frameEnd;
            if (!this.stopped) { // Stop simulation time
                this.current = frameEnd;
            }

            // Extend endpoint by paused time (individually paused tasks)
            for (let pausedTask of this.pausedTimeTasks) {
                pausedTask.next += delta;
            }

            if (this.stopped) {
                // Extend endpoint by paused time (running tasks)
                for (let timeTask of this.timeTasks) {
                    timeTask.next += delta;
                }
            }

            this.executeTimeTasks(frameEnd);

            // Maintain outdated task list
            for (let task of this.outdatedTimeTasks) {
                if (task.next < frameEnd - this.timeWarpSaveTime) {
                    this.timeTasksScratchpad.push(task);
                }
            }
            for (let task of this.timeTasksScratchpad) {
                const i = this.timeTasksScratchpad.indexOf(task)
                this.outdatedTimeTasks.splice(i, 1);
            }
            while (this.timeTasksScratchpad.length > 0) {
                this.timeTasksScratchpad.splice(0, 1);
            }

        }

        this.sortFrameTasks();
        for (let frameTask of this.frameTasks) {
            if (!this.stopped && !frameTask.paused && frameTask.active) {
                if (!frameTask.task()) frameTask.active = false;
            }
        }

        for (let frameTask of this.frameTasks) {
            if (!frameTask.active) {
                this.toDeleteFrame.push(frameTask);
            }
        }

        while (this.toDeleteFrame.length > 0) {
            const i = this.frameTasks.indexOf(this.toDeleteFrame.pop())
            this.frameTasks.splice(i, 1)
        }
    }

    static executeTimeTasks(until: number) {
        while (this.timeTasks.length > 0) {
            this.activeTimeTask = this.timeTasks[0];

            if (this.activeTimeTask.next <= until) {
                this.activeTimeTask.next += this.activeTimeTask.period;
                const i = this.timeTasks.indexOf(this.activeTimeTask)
                this.timeTasks.splice(i, 1)

                if (this.activeTimeTask.active && this.activeTimeTask.task()) {
                    if (this.activeTimeTask.period > 0 && (this.activeTimeTask.duration == 0 || this.activeTimeTask.duration >= this.activeTimeTask.start + this.activeTimeTask.next)) {
                        this.insertSorted(this.timeTasks, this.activeTimeTask);
                    }
                    else {
                        this.archiveTimeTask(this.activeTimeTask, until);
                    }
                }
                else {
                    this.activeTimeTask.active = false;
                    this.archiveTimeTask(this.activeTimeTask, until);
                }
            }
            else {
                break;
            }
        }
        this.activeTimeTask = null;
    }

    static archiveTimeTask(timeTask: TimeTask, frameEnd: number) {
        if (timeTask.next > frameEnd - this.timeWarpSaveTime) {
            this.outdatedTimeTasks.push(timeTask);
        }
    }

    /**
	 * An approximation of the amount of time (in fractional seconds) that elapsed while the game was active.
	 * This value is optimized for achieving smooth framerates.
	 */
    static time(): number {
        return this.current;
    }

    /**
	 * The amount of time (in fractional seconds) that elapsed since the game started.
	*/
    public static realTime(): number {
        return GameView.time
    }


    static resetTime(): void {
        var now = this.realTime();
        var dif = now - this.startTime;
        this.startTime = now;
        for (let timeTask of this.timeTasks) {
            timeTask.start -= dif;
            timeTask.next -= dif;
        }
        for (let i = 0; i < this.DIF_COUNT; i++) this.deltas[i] = 0;
        this.current = 0;
        this.lastTime = 0;
    }

    static addBreakableFrameTask(task: () => boolean, priority: number): number {
        this.frameTasks.push(new FrameTask(task, priority, ++this.currentFrameTaskId));
        this.frame_tasks_sorted = false;
        return this.currentFrameTaskId;
    }

    static addFrameTask(task: () => void, priority: number): number {
        return this.addBreakableFrameTask(() => {
            task();
            return true;
        }, priority);
    }

    static pauseFrameTask(id: number, paused: boolean): void {
        for (let frameTask of this.frameTasks) {
            if (frameTask.id == id) {
                frameTask.paused = paused;
                break;
            }
        }
    }

    static removeFrameTask(id: number): void {
        for (let frameTask of this.frameTasks) {
            if (frameTask.id == id) {
                frameTask.active = false;
                break;
            }
        }
    }

    static generateGroupId(): number {
        return ++this.currentGroupId;
    }

    static addBreakableTimeTaskToGroup(groupId: number, task: () => boolean, start: number, period: number = 0, duration: number = 0): number {
        var t = new TimeTask();
        t.active = true;
        t.task = task;
        t.id = ++this.currentTimeTaskId;
        t.groupId = groupId;

        t.start = this.current + start;
        t.period = 0;
        if (period != 0) t.period = period;
        t.duration = 0; //infinite
        if (duration != 0) t.duration = t.start + duration;

        t.next = t.start;
        this.insertSorted(this.timeTasks, t);
        return t.id;
    }

    static addTimeTaskToGroup(groupId: number, task: () => void, start: number, period: number = 0, duration: number = 0): number {
        return this.addBreakableTimeTaskToGroup(groupId, () => {
            task();
            return true;
        }, start, period, duration);
    }

    static addBreakableTimeTask(task: () => boolean, start: number, period: number = 0, duration: number = 0): number {
        return this.addBreakableTimeTaskToGroup(0, task, start, period, duration);
    }

    static addTimeTask(task: () => void, start: number, period: number = 0, duration: number = 0): number {
        return this.addTimeTaskToGroup(0, task, start, period, duration);
    }

    static getTimeTask(id: number): TimeTask {
        if (this.activeTimeTask != null && this.activeTimeTask.id == id) return this.activeTimeTask;
        for (let timeTask of this.timeTasks) {
            if (timeTask.id == id) {
                return timeTask;
            }
        }
        for (let timeTask of this.pausedTimeTasks) {
            if (timeTask.id == id) {
                return timeTask;
            }
        }
        return null;
    }

    static pauseTimeTask(id: number, paused: boolean): void {
        var timeTask = this.getTimeTask(id);
        if (timeTask != null) {
            this.pauseRunningTimeTask(timeTask, paused);
        }
        if (this.activeTimeTask != null && this.activeTimeTask.id == id) {
            this.activeTimeTask.paused = paused;
        }
    }

    static pauseRunningTimeTask(timeTask: TimeTask, paused: boolean): void {
        timeTask.paused = paused;
        if (paused) {
            this.timeTasks.splice(this.timeTasks.indexOf(timeTask), 1);
            this.pausedTimeTasks.push(timeTask);
        }
        else {
            this.insertSorted(this.timeTasks, timeTask);
            this.pausedTimeTasks.splice(this.pausedTimeTasks.indexOf(timeTask), 1)
        }
    }

    static pauseTimeTasks(groupId: number, paused: boolean): void {
        for (let timeTask of this.timeTasks) {
            if (timeTask.groupId == groupId) {
                this.pauseRunningTimeTask(timeTask, paused);
            }
        }
        if (this.activeTimeTask != null && this.activeTimeTask.groupId == groupId) {
            this.activeTimeTask.paused = paused;
        }
    }

    static removeTimeTask(id: number): void {
        var timeTask = this.getTimeTask(id);
        if (timeTask != null) {
            timeTask.active = false;
            this.timeTasks.splice(this.timeTasks.indexOf(timeTask), 1);
        }
    }

    static removeTimeTasks(groupId: number): void {
        for (let timeTask of this.timeTasks) {
            if (timeTask.groupId == groupId) {
                timeTask.active = false;
                this.timeTasksScratchpad.push(timeTask);
            }
        }
        for (let timeTask of this.timeTasksScratchpad) {
            this.timeTasks.splice(this.timeTasks.indexOf(timeTask), 1);
        }
        while (this.timeTasksScratchpad.length > 0) {
            this.timeTasksScratchpad.splice(0, 1);
        }

        if (this.activeTimeTask != null && this.activeTimeTask.groupId == groupId) {
            this.activeTimeTask.active = false;
        }
    }

    static numTasksInSchedule(): number {
        return this.timeTasks.length + this.frameTasks.length;
    }

    static insertSorted(list: Array<TimeTask>, task: TimeTask) {
        for (let i = 0; i < list.length; i++) {
            if (list[i].next > task.next) {
                list[i] = task;
                return;
            }
        }
        list.push(task);
    }

    static sortFrameTasks(): void {
        if (this.frame_tasks_sorted) return;
        this.frameTasks.sort(function (a: FrameTask, b: FrameTask): number {
            return a.priority > b.priority ? 1 : ((a.priority < b.priority) ? -1 : 0);
        });
        this.frame_tasks_sorted = true;
    }

}