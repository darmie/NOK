import { VertexShader } from "./VertexShader"
import { FragmentShader } from "./FragmentShader"
import { GeometryShader } from "./GeometryShader"
import { VertexStructure } from "./VertexStructure"
import { CullMode } from "./CullMode"
import { CompareMode } from "./CompareMode"
import { StencilAction } from "./StencilAction"
import { StencilValue } from "./StencilValue"
import { BlendingFactor } from "./BlendingFactor"
import { BlendingOperation } from "./BlendingOperation"
import { TessellationControlShader } from "./TessellationControlShader"
import { TessellationEvaluationShader } from "./TessellationEvaluationShader"

export class PipelineStateBase {

	public inputLayout: Array<VertexStructure> = [];
	public vertexShader: VertexShader;
	public fragmentShader: FragmentShader;
	public geometryShader: GeometryShader;
	public tessellationControlShader: TessellationControlShader;
	public tessellationEvaluationShader: TessellationEvaluationShader;

	public cullMode: CullMode;

	public depthWrite: boolean;
	public depthMode: CompareMode;

	public stencilMode: CompareMode;
	public stencilBothPass: StencilAction;
	public stencilDepthFail: StencilAction;
	public stencilFail: StencilAction;
	public stencilReferenceValue: StencilValue;
	public stencilReadMask: number;
	public stencilWriteMask: number;

	// One, Zero deactivates blending
	public blendSource: BlendingFactor;
	public blendDestination: BlendingFactor;
	public blendOperation: BlendingOperation;
	public alphaBlendSource: BlendingFactor;
	public alphaBlendDestination: BlendingFactor;
	public alphaBlendOperation: BlendingOperation;

	public colorWriteMasksRed: Array<boolean>;
	public colorWriteMasksGreen: Array<boolean>;
	public colorWriteMasksBlue: Array<boolean>;
	public colorWriteMasksAlpha: Array<boolean>;

	public conservativeRasterization: boolean;

	constructor() {
		this.inputLayout = [];
		this.vertexShader = null;
		this.fragmentShader = null;
		this.geometryShader = null;
		this.tessellationControlShader = null;
		this.tessellationEvaluationShader = null;

		this.cullMode = CullMode.None;

		this.depthWrite = false;
		this.depthMode = CompareMode.Always;

		this.stencilMode = CompareMode.Always;
		this.stencilBothPass = StencilAction.Keep;
		this.stencilDepthFail = StencilAction.Keep;
		this.stencilFail = StencilAction.Keep;
		this.stencilReferenceValue = StencilValue.Static(0);
		this.stencilReadMask = 0xff;
		this.stencilWriteMask = 0xff;

		this.blendSource = BlendingFactor.BlendOne;
		this.blendDestination = BlendingFactor.BlendZero;
		this.blendOperation = BlendingOperation.Add;
		this.alphaBlendSource = BlendingFactor.BlendOne;
		this.alphaBlendDestination = BlendingFactor.BlendZero;
		this.alphaBlendOperation = BlendingOperation.Add;

		this.colorWriteMasksRed = [];
		this.colorWriteMasksGreen = [];
		this.colorWriteMasksBlue = [];
		this.colorWriteMasksAlpha = [];
		for (let i = 0; i < 8; i++) this.colorWriteMasksRed.push(true);
		for (let i = 0; i < 8; i++) this.colorWriteMasksGreen.push(true);
		for (let i = 0; i < 8; i++) this.colorWriteMasksBlue.push(true);
		for (let i = 0; i < 8; i++) this.colorWriteMasksAlpha.push(true);

		this.conservativeRasterization = false;
	}


	set colorWriteMask(value: boolean) {
		this.colorWriteMaskRed = this.colorWriteMaskBlue = this.colorWriteMaskGreen = this.colorWriteMaskAlpha = value;
	}

	get colorWriteMaskRed(): boolean {
		return this.colorWriteMasksRed[0];
	}

	set colorWriteMaskRed(value: boolean) {
		this.colorWriteMasksRed[0] = value;
	}

	get colorWriteMaskGreen(): boolean {
		return this.colorWriteMasksGreen[0];
	}

	set colorWriteMaskGreen(value: boolean) {
		this.colorWriteMasksGreen[0] = value;
	}

	get colorWriteMaskBlue(): boolean {
		return this.colorWriteMasksBlue[0];
	}

	set colorWriteMaskBlue(value: boolean) {
		this.colorWriteMasksBlue[0] = value;
	}

	get colorWriteMaskAlpha(): boolean {
		return this.colorWriteMasksAlpha[0];
	}

	set colorWriteMaskAlpha(value: boolean) {
		this.colorWriteMasksAlpha[0] = value;
	}


}