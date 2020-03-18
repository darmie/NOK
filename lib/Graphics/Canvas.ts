import {Graphics} from "../Graphics/Graphics4/Graphics"
import {Graphics2} from "../Graphics/Graphics4/Graphics2"
/**
 * Interface for a generic Canvas with different APIs,
 * that can be used to draw graphics.
 */
export interface Canvas {
    /**
    * The width of the canvas in pixels.
    */
    width: number;
    /**
     * The height of the canvas in pixels.
     */
    height: number;

    /**
     * The Graphics2 interface object.<br>
     * Use this for 2D operations.
     */
    g2: Graphics2;
    /**
     * The Graphics4 interface object.<br>
     * Use this for 3D operations.
     */
    g4: Graphics;
}