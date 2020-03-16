
/**
 * Interface representing a generic application resource.
 * E.G images, to sound or music, videos or blobs.
 */
export interface Resource {
    /**
	 * Unload the resource from memory. Normally called by the Loader.
	 */
    unload(): void;
}