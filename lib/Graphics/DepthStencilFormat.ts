export enum DepthStencilFormat {
	NoDepthAndStencil = 0,
	DepthOnly = 1,
	DepthAutoStencilAuto = 2,

	// This is platform specific
	Depth24Stencil8 = 3,
	Depth32Stencil8 = 4,
	Depth16 = 5,
}
