# Harness Doc: `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/SyphonServer.h`

## File-level
- **File path:** `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/SyphonServer.h`
- **Purpose of file:** Declares Syphon server API for publishing OpenGL textures and advertising server metadata.
- **Dependencies/includes/imports:** `Cocoa/Cocoa.h`, `OpenGL/OpenGL.h`, forward reference to `SyphonImage` return type.
- **Key classes/structs/types/globals/macros:** Option constants, `@interface SyphonServer`, publishing methods/properties.
- **External resources touched:** OpenGL contexts/FBOs and Syphon inter-process frame publication.
- **Build role:** Public framework interface consumed by apps producing Syphon streams.
- **Risks/footguns:** Requires careful GL context locking and explicit publish lifecycle pairing.

## Symbols

### Constant `SyphonServerOptionIsPrivate`
- **Signature:** `extern NSString * const SyphonServerOptionIsPrivate;`
- **Location:** `source/.../SyphonServer.h:40`
- **Belongs to:** Global Syphon server options namespace.
- **Purpose:** Controls whether server is hidden from global discovery.
- **Inputs:** Option dictionary key.
- **Outputs / Return value:** N/A.
- **Side effects:** Changes visibility behavior when used.
- **Preconditions:** Passed during server init options.
- **Postconditions:** Private servers require manual description sharing.
- **Error handling / failure modes:** Ignored/misused key yields default public behavior.
- **Called by (best-effort):** Host app option construction.
- **Calls into (best-effort):** N/A.
- **Performance notes:** None.
- **Threading notes:** Immutable constant.
- **Agent modification guidance:** Keep exact symbol name for ABI/API compatibility.
- **Related symbols:** `serverDescription`, directory keys.

### Constant `SyphonServerOptionAntialiasSampleCount`
- **Signature:** `extern NSString * const SyphonServerOptionAntialiasSampleCount;`
- **Location:** `source/.../SyphonServer.h:47`
- **Belongs to:** Global options.
- **Purpose:** Requests MSAA sample count when using bind/unbind publish path.
- **Inputs:** NSNumber sample count.
- **Outputs / Return value:** N/A.
- **Side effects:** Influences FBO creation quality/cost.
- **Preconditions:** Context supports requested AA level.
- **Postconditions:** Best-supported sample count applied or ignored.
- **Error handling / failure modes:** Unsupported values degrade gracefully.
- **Called by (best-effort):** Server initialization code.
- **Calls into (best-effort):** Internal Syphon FBO setup.
- **Performance notes:** Higher sample counts increase GPU cost.
- **Threading notes:** Immutable constant.
- **Agent modification guidance:** Preserve docs and symbol identity.
- **Related symbols:** bind/unbind methods.

### Constant `SyphonServerOptionDepthBufferResolution`
- **Signature:** `extern NSString * const SyphonServerOptionDepthBufferResolution;`
- **Location:** `source/.../SyphonServer.h:53`
- **Belongs to:** Global options.
- **Purpose:** Requests depth buffer bit depth for server FBO path.
- **Inputs:** NSNumber depth precision (16/24/32).
- **Outputs / Return value:** N/A.
- **Side effects:** May attach depth buffer to published draw target.
- **Preconditions:** Applicable to bind/unbind workflow.
- **Postconditions:** Depth buffer attached best-effort.
- **Error handling / failure modes:** Implementation may substitute nearest supported format.
- **Called by (best-effort):** Advanced rendering publishers.
- **Calls into (best-effort):** Internal GL resource setup.
- **Performance notes:** Adds memory and depth test cost.
- **Threading notes:** Constant only.
- **Agent modification guidance:** ABI-stable public key.
- **Related symbols:** `bindToDrawFrameOfSize:`.

### Constant `SyphonServerOptionStencilBufferResolution`
- **Signature:** `extern NSString * const SyphonServerOptionStencilBufferResolution;`
- **Location:** `source/.../SyphonServer.h:59`
- **Belongs to:** Global options.
- **Purpose:** Requests stencil buffer precision in server FBO mode.
- **Inputs:** NSNumber stencil bit depth.
- **Outputs / Return value:** N/A.
- **Side effects:** Enables stencil-backed draw buffers.
- **Preconditions:** Hardware/context support.
- **Postconditions:** Stencil attachment configured best-effort.
- **Error handling / failure modes:** Unsupported request can be ignored/substituted.
- **Called by (best-effort):** Apps with stencil-dependent rendering.
- **Calls into (best-effort):** Internal FBO setup.
- **Performance notes:** Additional memory/bandwidth overhead.
- **Threading notes:** Constant only.
- **Agent modification guidance:** Maintain compatibility.
- **Related symbols:** AA/depth options.

### Method `-initWithName:context:options:`
- **Signature:** `- (id)initWithName:(NSString*)serverName context:(CGLContextObj)context options:(NSDictionary *)options;`
- **Location:** `source/.../SyphonServer.h:110`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Starts a server bound to a GL context and option set.
- **Inputs:** Display name, CGL context, options dictionary.
- **Outputs / Return value:** Initialized server instance or `nil` on failure.
- **Side effects:** Publishes server availability.
- **Preconditions:** Context valid and accessible.
- **Postconditions:** Server started and discoverable unless private.
- **Error handling / failure modes:** Returns `nil` on startup failure.
- **Called by (best-effort):** Producer app initialization.
- **Calls into (best-effort):** Syphon registration and GL setup internals.
- **Performance notes:** One-time setup overhead.
- **Threading notes:** Caller must lock context if shared across threads.
- **Agent modification guidance:** Keep init contract and options semantics.
- **Related symbols:** `serverDescription`, `stop`.

### Property `context`
- **Signature:** `@property (readonly) CGLContextObj context;`
- **Location:** `source/.../SyphonServer.h:120`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Provides context used for server draw/publish operations.
- **Inputs/Outputs / Return value:** No input; returns `CGLContextObj`.
- **Side effects:** None.
- **Preconditions/Postconditions:** Server alive.
- **Error handling / failure modes:** N/A.
- **Called by / Calls into (best-effort):** Used for explicit lock/unlock discipline.
- **Performance notes:** Accessor cost only.
- **Threading notes:** Read-safe; GL operations require synchronization.
- **Agent modification guidance:** Preserve readonly property.
- **Related symbols:** `bindToDrawFrameOfSize:`.

### Property `name`
- **Signature:** `@property (retain) NSString* name;`
- **Location:** `source/.../SyphonServer.h:126`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Human-readable server name shown to clients.
- **Inputs:** Assigned NSString.
- **Outputs / Return value:** Getter returns current name.
- **Side effects:** Updates metadata seen in discovery dictionaries.
- **Preconditions:** Server object valid.
- **Postconditions:** Name change may propagate to watchers.
- **Error handling / failure modes:** Nil/empty allowed.
- **Called by (best-effort):** UI and runtime naming logic.
- **Calls into (best-effort):** Internal metadata publication.
- **Performance notes:** Minor metadata update cost.
- **Threading notes:** Property mutation should be serialized by caller.
- **Agent modification guidance:** Keep memory semantics consistent with Obj-C ownership model in target SDK.
- **Related symbols:** `serverDescription`.

### Property `serverDescription`
- **Signature:** `@property (readonly) NSDictionary* serverDescription;`
- **Location:** `source/.../SyphonServer.h:132`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Exposes serialized description required for private-server clients.
- **Inputs:** None.
- **Outputs / Return value:** Dictionary conforming to NSCoding content.
- **Side effects:** None.
- **Preconditions:** Server initialized.
- **Postconditions:** Caller can transmit dictionary to clients.
- **Error handling / failure modes:** Key set not strictly guaranteed.
- **Called by (best-effort):** IPC/bridging code.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Accessor-level overhead.
- **Threading notes:** Read-only dictionary usage recommended.
- **Agent modification guidance:** Maintain compatibility with client init expectations.
- **Related symbols:** privacy option and directory constants.

### Property `hasClients`
- **Signature:** `@property (readonly) BOOL hasClients;`
- **Location:** `source/.../SyphonServer.h:138`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Indicates whether any consumers are currently attached.
- **Inputs:** None.
- **Outputs / Return value:** `YES`/`NO`.
- **Side effects:** None.
- **Preconditions:** Running server.
- **Postconditions:** Caller may skip rendering when no clients.
- **Error handling / failure modes:** None explicit.
- **Called by (best-effort):** Producer performance gating logic.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Useful optimization signal.
- **Threading notes:** Snapshot indicator; clients can connect/disconnect concurrently.
- **Agent modification guidance:** Keep as cheap readonly query.
- **Related symbols:** publish methods.

### Method `-publishFrameTexture:textureTarget:imageRegion:textureDimensions:flipped:`
- **Signature:** `- (void)publishFrameTexture:(GLuint)texID textureTarget:(GLenum)target imageRegion:(NSRect)region textureDimensions:(NSSize)size flipped:(BOOL)isFlipped;`
- **Location:** `source/.../SyphonServer.h:158`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Publishes a specified texture region to connected clients.
- **Inputs:** Texture id/target, sub-rect, full texture dimensions, flipped flag.
- **Outputs / Return value:** None.
- **Side effects:** Copies/queues frame for client consumption.
- **Preconditions:** Texture must be valid in server context.
- **Postconditions:** Latest published frame becomes available to clients.
- **Error handling / failure modes:** No direct status return.
- **Called by (best-effort):** Frame producer render loop.
- **Calls into (best-effort):** Syphon GL transfer/publish internals.
- **Performance notes:** GPU copy and synchronization cost per frame.
- **Threading notes:** Caller must handle GL context locking.
- **Agent modification guidance:** Preserve no-state-pollution guarantees in docs.
- **Related symbols:** `bindToDrawFrameOfSize:`, `hasClients`.

### Method `-bindToDrawFrameOfSize:`
- **Signature:** `- (BOOL)bindToDrawFrameOfSize:(NSSize)size;`
- **Location:** `source/.../SyphonServer.h:171`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Binds server-managed FBO for direct drawing publish workflow.
- **Inputs:** Frame size.
- **Outputs / Return value:** `YES` on successful bind.
- **Side effects:** Replaces FBO binding in caller context.
- **Preconditions:** Valid server and compatible GL context.
- **Postconditions:** On success, caller must call `unbindAndPublish`.
- **Error handling / failure modes:** Returns `NO` when setup fails.
- **Called by (best-effort):** Alternate publish path for render-to-texture.
- **Calls into (best-effort):** Internal FBO allocation/bind logic.
- **Performance notes:** Possible allocation/reconfiguration overhead.
- **Threading notes:** Requires explicit context synchronization.
- **Agent modification guidance:** Preserve pairing contract with unbind.
- **Related symbols:** `unbindAndPublish`.

### Method `-unbindAndPublish`
- **Signature:** `- (void)unbindAndPublish;`
- **Location:** `source/.../SyphonServer.h:181`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Restores prior/default FBO and publishes frame drawn since bind.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Flushes GL context and emits frame.
- **Preconditions:** Successful prior `bindToDrawFrameOfSize:`.
- **Postconditions:** Frame published and FBO binding restored.
- **Error handling / failure modes:** Undefined behavior if called unpaired.
- **Called by (best-effort):** Draw/publish loops using bind workflow.
- **Calls into (best-effort):** Internal flush and publish code.
- **Performance notes:** Includes flush cost.
- **Threading notes:** Same locking requirements as bind/publish.
- **Agent modification guidance:** Keep sequencing invariant.
- **Related symbols:** `bindToDrawFrameOfSize:`.

### Method `-newFrameImage`
- **Signature:** `- (SyphonImage *)newFrameImage;`
- **Location:** `source/.../SyphonServer.h:188`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Returns most recent frame as `SyphonImage` in server context.
- **Inputs:** None.
- **Outputs / Return value:** Retained `SyphonImage`.
- **Side effects:** May touch GPU resources.
- **Preconditions:** Server has produced or can provide a frame.
- **Postconditions:** Caller can inspect/use current output texture.
- **Error handling / failure modes:** Lifetime-sensitive; caller responsible for release.
- **Called by (best-effort):** Debug previews or in-process consumers.
- **Calls into (best-effort):** Internal frame buffer read path.
- **Performance notes:** Potential copy/synchronization.
- **Threading notes:** Context ownership must be respected.
- **Agent modification guidance:** Preserve ownership semantics.
- **Related symbols:** `publishFrameTexture...`.

### Method `-stop`
- **Signature:** `- (void)stop;`
- **Location:** `source/.../SyphonServer.h:194`
- **Belongs to:** `SyphonServer`.
- **Purpose:** Stops publishing and tears down server resources.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Withdraws server from discovery; frees resources.
- **Preconditions:** Server exists.
- **Postconditions:** Clients no longer receive frames.
- **Error handling / failure modes:** Equivalent lifecycle effect to deallocation.
- **Called by (best-effort):** Shutdown and cleanup code.
- **Calls into (best-effort):** Internal Syphon teardown path.
- **Performance notes:** Cleanup cost depends on active resources.
- **Threading notes:** Coordinate with render thread/context.
- **Agent modification guidance:** Maintain safe idempotent shutdown behavior.
- **Related symbols:** initializer, `hasClients`.
