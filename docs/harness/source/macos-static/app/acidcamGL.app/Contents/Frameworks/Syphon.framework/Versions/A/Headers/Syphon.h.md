# Harness Doc: `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/Syphon.h`

## File-level
- **File path:** `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/Syphon.h`
- **Purpose of file:** Umbrella Syphon framework header importing client/server/directory/image APIs and embedding developer documentation.
- **Dependencies/includes/imports:** `SyphonServerDirectory.h`, `SyphonServer.h`, `SyphonClient.h`, `SyphonImage.h`.
- **Key classes/structs/types/globals/macros:** Imported Syphon Objective-C classes; Doxygen `\mainpage` documentation block.
- **External resources touched:** None directly; documents runtime interoperability between macOS apps.
- **Build role:** Public framework include for consumers of Syphon APIs.
- **Risks/footguns:** Vendored framework header in app bundle path; local edits can diverge from upstream SDK.

## Symbols

### Header import `SyphonServerDirectory.h`
- **Signature:** `#import "SyphonServerDirectory.h"`
- **Location:** `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/Syphon.h:30`
- **Belongs to:** Syphon framework umbrella header.
- **Purpose:** Re-exports server discovery API.
- **Inputs/Outputs / Return value:** N/A.
- **Side effects:** Makes directory symbols visible to include consumers.
- **Preconditions:** Header exists in framework include path.
- **Postconditions:** `SyphonServerDirectory` types available.
- **Error handling / failure modes:** Compile error if include path broken.
- **Called by / Calls into (best-effort):** N/A.
- **Performance notes:** Compile-time include only.
- **Threading notes:** N/A.
- **Agent modification guidance:** Keep umbrella imports synchronized with framework contents.
- **Related symbols:** other `#import` lines.

### Header import `SyphonServer.h`
- **Signature:** `#import "SyphonServer.h"`
- **Location:** `source/.../Syphon.h:31`
- **Belongs to:** Syphon framework umbrella header.
- **Purpose:** Re-exports server publish API.
- **Inputs/Outputs/Side effects/Pre/Post/Error handling:** Same class as above.
- **Called by / Calls into:** N/A.
- **Performance notes:** Compile-time only.
- **Threading notes:** N/A.
- **Agent modification guidance:** Treat as vendored.
- **Related symbols:** `SyphonClient.h`, `SyphonImage.h`.

### Header import `SyphonClient.h`
- **Signature:** `#import "SyphonClient.h"`
- **Location:** `source/.../Syphon.h:32`
- **Belongs to:** Syphon framework umbrella header.
- **Purpose:** Re-exports client receive API.
- **Inputs/Outputs / Return value:** N/A.
- **Side effects:** Include exposure.
- **Preconditions/Postconditions/Error handling:** Header availability requirement.
- **Called by / Calls into:** N/A.
- **Performance notes:** Compile-time only.
- **Threading notes:** N/A.
- **Agent modification guidance:** Keep unchanged unless updating SDK snapshot.
- **Related symbols:** `SyphonImage.h`.

### Header import `SyphonImage.h`
- **Signature:** `#import "SyphonImage.h"`
- **Location:** `source/.../Syphon.h:33`
- **Belongs to:** Syphon framework umbrella header.
- **Purpose:** Re-exports frame image wrapper API.
- **Inputs/Outputs / Return value:** N/A.
- **Side effects:** Include exposure.
- **Preconditions/Postconditions/Error handling:** Header availability requirement.
- **Called by / Calls into:** N/A.
- **Performance notes:** Compile-time only.
- **Threading notes:** N/A.
- **Agent modification guidance:** Treat as vendored SDK content.
- **Related symbols:** Other umbrella imports.

## Function/Method Inventory
- No C/C++/Objective-C function or method bodies are defined in this file; functionality is provided by imported Syphon headers.
