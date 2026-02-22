# Harness Doc: `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/SyphonServerDirectory.h`

## File-level
- **File path:** `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/SyphonServerDirectory.h`
- **Purpose of file:** Declares shared discovery directory for available Syphon servers and related metadata keys/notifications.
- **Dependencies/includes/imports:** `Cocoa/Cocoa.h`.
- **Key classes/structs/types/globals/macros:** Server description key constants, notification constants, `SyphonServerDirectory` class.
- **External resources touched:** Syphon service discovery state exposed through Cocoa notifications.
- **Build role:** Public header for clients that browse/track available Syphon servers.
- **Risks/footguns:** Keys may be absent in dictionaries; watcher code must tolerate partial metadata.

## Symbols

### Constant `SyphonServerDescriptionUUIDKey`
- **Signature:** `extern NSString * const SyphonServerDescriptionUUIDKey;`
- **Location:** `source/.../SyphonServerDirectory.h:41`
- **Belongs to:** Global server-description key set.
- **Purpose:** Stable unique identifier key for a specific server instance.
- **Inputs/Outputs / Return value:** Dictionary lookup key.
- **Side effects:** None.
- **Preconditions:** Used against server-description dictionaries.
- **Postconditions:** Enables identity comparison across updates.
- **Error handling / failure modes:** Key may be absent.
- **Called by / Calls into (best-effort):** Used by client discovery code; N/A for calls.
- **Performance notes:** Constant lookup token.
- **Threading notes:** Immutable constant.
- **Agent modification guidance:** Preserve symbol name for API compatibility.
- **Related symbols:** Name/App/Icon keys.

### Constant `SyphonServerDescriptionNameKey`
- **Signature:** `extern NSString * const SyphonServerDescriptionNameKey;`
- **Location:** `source/.../SyphonServerDirectory.h:48`
- **Belongs to:** Description key set.
- **Purpose:** Human-readable server name key.
- **Inputs/Outputs / Return value:** Dictionary key constant.
- **Side effects/Pre/Post/Error handling:** None; may be absent in dictionaries.
- **Called by / Calls into (best-effort):** UI list labeling logic; N/A.
- **Performance notes:** Constant.
- **Threading notes:** Immutable.
- **Agent modification guidance:** Maintain existing public constant.
- **Related symbols:** App name key.

### Constant `SyphonServerDescriptionAppNameKey`
- **Signature:** `extern NSString * const SyphonServerDescriptionAppNameKey;`
- **Location:** `source/.../SyphonServerDirectory.h:55`
- **Belongs to:** Description key set.
- **Purpose:** Localized host application name key.
- **Inputs/Outputs / Return value:** Dictionary key.
- **Side effects:** None.
- **Preconditions/Postconditions:** Used when available for UI context.
- **Error handling / failure modes:** Optional presence.
- **Called by / Calls into (best-effort):** Discovery UIs; N/A.
- **Performance notes:** Constant.
- **Threading notes:** Immutable.
- **Agent modification guidance:** Keep ABI stable.
- **Related symbols:** Name/icon keys.

### Constant `SyphonServerDescriptionIconKey`
- **Signature:** `extern NSString * const SyphonServerDescriptionIconKey;`
- **Location:** `source/.../SyphonServerDirectory.h:62`
- **Belongs to:** Description key set.
- **Purpose:** Key for server host app icon image.
- **Inputs/Outputs / Return value:** Dictionary key.
- **Side effects:** None.
- **Preconditions/Postconditions:** Optional icon extraction for UI.
- **Error handling / failure modes:** May be missing.
- **Called by / Calls into (best-effort):** UI rendering; N/A.
- **Performance notes:** Constant.
- **Threading notes:** Immutable.
- **Agent modification guidance:** Preserve symbol.
- **Related symbols:** Name/app keys.

### Constant `SyphonServerAnnounceNotification`
- **Signature:** `extern NSString * const SyphonServerAnnounceNotification;`
- **Location:** `source/.../SyphonServerDirectory.h:74`
- **Belongs to:** Notification constants.
- **Purpose:** Notification posted when a new server appears.
- **Inputs/Outputs / Return value:** Notification name.
- **Side effects:** Enables observer callbacks.
- **Preconditions:** Observer registered with notification center.
- **Postconditions:** User info may contain server-description keys.
- **Error handling / failure modes:** Consumers must validate payload.
- **Called by / Calls into (best-effort):** Posted by Syphon internals; consumed by client apps.
- **Performance notes:** Event-driven; avoids polling.
- **Threading notes:** Delivery thread depends on posting context.
- **Agent modification guidance:** Keep names unchanged.
- **Related symbols:** update/retire notifications.

### Constant `SyphonServerUpdateNotification`
- **Signature:** `extern NSString * const SyphonServerUpdateNotification;`
- **Location:** `source/.../SyphonServerDirectory.h:81`
- **Belongs to:** Notification constants.
- **Purpose:** Notification for changed server metadata.
- **Inputs/Outputs / Return value:** Notification name.
- **Side effects:** Triggers UI/model refreshes.
- **Preconditions/Postconditions:** Observer workflow similar to announce notification.
- **Error handling / failure modes:** User-info may be partial.
- **Called by / Calls into (best-effort):** Syphon runtime -> observers.
- **Performance notes:** Event-driven updates.
- **Threading notes:** Handle potential off-main-thread delivery.
- **Agent modification guidance:** Preserve published constant.
- **Related symbols:** announce/retire notifications.

### Constant `SyphonServerRetireNotification`
- **Signature:** `extern NSString * const SyphonServerRetireNotification;`
- **Location:** `source/.../SyphonServerDirectory.h:88`
- **Belongs to:** Notification constants.
- **Purpose:** Notification when server is no longer available.
- **Inputs/Outputs / Return value:** Notification name.
- **Side effects:** Allows consumer cleanup/disconnect.
- **Preconditions/Postconditions:** Observers receive retiring server description.
- **Error handling / failure modes:** Payload still optional/partial.
- **Called by / Calls into (best-effort):** Syphon runtime -> observers.
- **Performance notes:** Event-based lifecycle handling.
- **Threading notes:** Synchronize shared data updates.
- **Agent modification guidance:** Preserve API constant.
- **Related symbols:** announce/update notifications.

### Method `+sharedDirectory`
- **Signature:** `+ (SyphonServerDirectory *)sharedDirectory;`
- **Location:** `source/.../SyphonServerDirectory.h:110`
- **Belongs to:** `SyphonServerDirectory` class object.
- **Purpose:** Provides singleton discovery directory.
- **Inputs:** None.
- **Outputs / Return value:** Shared directory instance.
- **Side effects:** Lazily initializes internal tracking resources.
- **Preconditions:** Cocoa runtime available.
- **Postconditions:** Caller can query servers and observe notifications.
- **Error handling / failure modes:** No explicit failure mode documented.
- **Called by (best-effort):** Any Syphon browser UI or connection chooser.
- **Calls into (best-effort):** Internal singleton allocation/init.
- **Performance notes:** One-time init then cached access.
- **Threading notes:** Shared mutable state guarded internally.
- **Agent modification guidance:** Maintain singleton semantics.
- **Related symbols:** `servers`, `serversMatchingName:appName:`.

### Property `servers`
- **Signature:** `@property (readonly) NSArray *servers;`
- **Location:** `source/.../SyphonServerDirectory.h:116`
- **Belongs to:** `SyphonServerDirectory`.
- **Purpose:** Returns current snapshot of available server dictionaries.
- **Inputs:** None.
- **Outputs / Return value:** Array of dictionaries keyed by server-description constants.
- **Side effects:** None.
- **Preconditions:** Directory initialized.
- **Postconditions:** Caller can enumerate available endpoints.
- **Error handling / failure modes:** Dictionaries may have missing keys.
- **Called by (best-effort):** Discovery UI population and polling fallback.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Snapshot read cost depends on list size.
- **Threading notes:** Treat as snapshot; reconcile with notifications.
- **Agent modification guidance:** Preserve readonly data exposure.
- **Related symbols:** key constants and notifications.

### Method `-serversMatchingName:appName:`
- **Signature:** `- (NSArray *)serversMatchingName:(NSString *)name appName:(NSString *)appname;`
- **Location:** `source/.../SyphonServerDirectory.h:125`
- **Belongs to:** `SyphonServerDirectory`.
- **Purpose:** Filters currently available servers by optional server/app names.
- **Inputs:** Optional `name`, optional `appname`.
- **Outputs / Return value:** Array of matching server description dictionaries.
- **Side effects:** None.
- **Preconditions:** Directory is active.
- **Postconditions:** Result set constrained to provided filter terms.
- **Error handling / failure modes:** Nil arguments are accepted (wildcard behavior).
- **Called by (best-effort):** Search/filter UI and auto-connect logic.
- **Calls into (best-effort):** Internal server list matcher.
- **Performance notes:** Linear scan of server list expected.
- **Threading notes:** Results may stale as availability changes.
- **Agent modification guidance:** Keep optional-parameter semantics.
- **Related symbols:** `servers`, description-name/app keys.
