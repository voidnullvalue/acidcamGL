# Harness Doc: `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/SyphonClient.h`

## File-level
- **File path:** `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/SyphonClient.h`
- **Purpose of file:** Declares the Syphon client interface used to subscribe to remote Syphon server frames.
- **Dependencies/includes/imports:** `Cocoa/Cocoa.h`, `OpenGL/OpenGL.h`; forward declaration `SyphonImage`.
- **Key classes/structs/types/globals/macros:** `@interface SyphonClient`; properties `context`, `isValid`, `serverDescription`, `hasNewFrame`.
- **External resources touched:** Remote Syphon frame-sharing service and OpenGL contexts (by contract/docs).
- **Build role:** Public Objective-C framework header consumed by Syphon clients.
- **Risks/footguns:** Vendored SDK header; methods that touch GL contexts require caller-side context/thread coordination.

## Symbols

### Method `-initWithServerDescription:context:options:newFrameHandler:`
- **Signature:** `- (id)initWithServerDescription:(NSDictionary *)description context:(CGLContextObj)context options:(NSDictionary *)options newFrameHandler:(void (^)(SyphonClient *client))handler;`
- **Location:** `source/.../SyphonClient.h:66`
- **Belongs to:** `SyphonClient`.
- **Purpose:** Initializes a client bound to a specific server description and GL context.
- **Inputs:** Server description dictionary, CGL context, options dictionary (currently ignored), optional new-frame callback block.
- **Outputs / Return value:** Initialized `SyphonClient` or `nil` on failure.
- **Side effects:** Establishes server connection state; may register callback.
- **Preconditions:** Valid Syphon server description and GL context.
- **Postconditions:** Client either valid/connected or initialization fails.
- **Error handling / failure modes:** Returns `nil`; validity should be checked via `isValid`.
- **Called by (best-effort):** App code creating Syphon consumer sessions.
- **Calls into (best-effort):** Internal Syphon connection manager implementation.
- **Performance notes:** One-time setup cost; callback can reduce polling overhead.
- **Threading notes:** Handler may be invoked off creator thread.
- **Agent modification guidance:** Preserve signature and documented threading semantics.
- **Related symbols:** `isValid`, `newFrameImage`, `stop`.

### Property `context`
- **Signature:** `@property (readonly) CGLContextObj context;`
- **Location:** `source/.../SyphonClient.h:71`
- **Belongs to:** `SyphonClient`.
- **Purpose:** Exposes GL context associated with this client.
- **Inputs:** None.
- **Outputs / Return value:** `CGLContextObj`.
- **Side effects:** None.
- **Preconditions:** Client initialized.
- **Postconditions:** Caller can coordinate GL calls with this context.
- **Error handling / failure modes:** Undefined if object lifetime has ended.
- **Called by (best-effort):** Rendering code coordinating texture reads.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Trivial accessor.
- **Threading notes:** Reading property is safe; GL usage still needs locking discipline.
- **Agent modification guidance:** Keep readonly contract.
- **Related symbols:** `newFrameImage`.

### Property `isValid`
- **Signature:** `@property (readonly) BOOL isValid;`
- **Location:** `source/.../SyphonClient.h:77`
- **Belongs to:** `SyphonClient`.
- **Purpose:** Reports whether server connection remains valid.
- **Inputs:** None.
- **Outputs / Return value:** `YES` when connected, `NO` when no further frames will arrive.
- **Side effects:** None.
- **Preconditions:** Client allocated.
- **Postconditions:** Caller can gate frame polling.
- **Error handling / failure modes:** Signals invalid/retired connection.
- **Called by (best-effort):** Client lifecycle and UI state checks.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Constant-time accessor.
- **Threading notes:** Safe status check across threads per header docs.
- **Agent modification guidance:** Do not weaken validity semantics.
- **Related symbols:** initializer, `stop`.

### Property `serverDescription`
- **Signature:** `@property (readonly) NSDictionary *serverDescription;`
- **Location:** `source/.../SyphonClient.h:83`
- **Belongs to:** `SyphonClient`.
- **Purpose:** Returns metadata dictionary describing attached server.
- **Inputs:** None.
- **Outputs / Return value:** Server description dictionary.
- **Side effects:** None.
- **Preconditions:** Client initialized.
- **Postconditions:** Metadata can be shown/queried by caller.
- **Error handling / failure modes:** Keys are not guaranteed.
- **Called by (best-effort):** UI and discovery/debug tools.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Accessor-level cost.
- **Threading notes:** Read-only data usage expected.
- **Agent modification guidance:** Maintain compatibility with directory keys.
- **Related symbols:** `SyphonServerDirectory` constants.

### Property `hasNewFrame`
- **Signature:** `@property (readonly) BOOL hasNewFrame;`
- **Location:** `source/.../SyphonClient.h:89`
- **Belongs to:** `SyphonClient`.
- **Purpose:** Indicates whether a frame newer than last retrieval exists.
- **Inputs:** None.
- **Outputs / Return value:** `YES`/`NO`.
- **Side effects:** None.
- **Preconditions:** Active client.
- **Postconditions:** Caller can skip unnecessary frame pulls.
- **Error handling / failure modes:** None explicit.
- **Called by (best-effort):** Timer/display-link loops.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Enables reduced polling work.
- **Threading notes:** Status check is thread-safe by intent.
- **Agent modification guidance:** Preserve semantics tied to `newFrameImage`.
- **Related symbols:** `newFrameImage`.

### Method `-newFrameImage`
- **Signature:** `- (SyphonImage *)newFrameImage;`
- **Location:** `source/.../SyphonClient.h:100`
- **Belongs to:** `SyphonClient`.
- **Purpose:** Returns the current server frame wrapped as a `SyphonImage`.
- **Inputs:** None.
- **Outputs / Return value:** Retained `SyphonImage` to be released by caller.
- **Side effects:** May execute OpenGL work/context state transitions.
- **Preconditions:** Connected client and correctly synchronized GL context.
- **Postconditions:** Latest frame object available for rendering.
- **Error handling / failure modes:** Can fail implicitly if connection invalid.
- **Called by (best-effort):** Rendering/compositing loop.
- **Calls into (best-effort):** Internal texture copy/update path.
- **Performance notes:** May incur GPU synchronization/copy cost.
- **Threading notes:** Caller must prevent simultaneous context use.
- **Agent modification guidance:** Keep ownership and GL-thread caveats explicit.
- **Related symbols:** `hasNewFrame`, `context`.

### Method `-stop`
- **Signature:** `- (void)stop;`
- **Location:** `source/.../SyphonClient.h:108`
- **Belongs to:** `SyphonClient`.
- **Purpose:** Ends frame reception and disconnects client.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Tears down connection/resources.
- **Preconditions:** Client exists.
- **Postconditions:** No further frames produced by this instance.
- **Error handling / failure modes:** Idempotence not specified but expected safe lifecycle call.
- **Called by (best-effort):** Shutdown paths and deallocation workflows.
- **Calls into (best-effort):** Internal Syphon teardown.
- **Performance notes:** Teardown cost proportional to held GPU/IPC resources.
- **Threading notes:** May perform GL-context work; synchronize context access.
- **Agent modification guidance:** Preserve behavior equivalent to releasing all references.
- **Related symbols:** initializer, `isValid`.
