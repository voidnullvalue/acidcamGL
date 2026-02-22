# Harness Doc: `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/SyphonImage.h`

## File-level
- **File path:** `source/macos-static/app/acidcamGL.app/Contents/Frameworks/Syphon.framework/Versions/A/Headers/SyphonImage.h`
- **Purpose of file:** Declares a lightweight wrapper describing a Syphon frame texture.
- **Dependencies/includes/imports:** `Cocoa/Cocoa.h`, `OpenGL/OpenGL.h`.
- **Key classes/structs/types/globals/macros:** `@interface SyphonImage`; properties `textureName`, `textureSize`.
- **External resources touched:** OpenGL texture objects (referenced, not created here).
- **Build role:** Public framework type used by Syphon client/server APIs.
- **Risks/footguns:** Texture lifetime/ownership is external; header provides no guarantees beyond property access.

## Symbols

### Property `textureName`
- **Signature:** `@property (readonly) GLuint textureName;`
- **Location:** `source/.../SyphonImage.h:44`
- **Belongs to:** `SyphonImage`.
- **Purpose:** Exposes underlying rectangle texture name.
- **Inputs:** None.
- **Outputs / Return value:** OpenGL texture object identifier.
- **Side effects:** None.
- **Preconditions:** Image object still valid.
- **Postconditions:** Caller can bind/use texture in compatible context.
- **Error handling / failure modes:** Invalid if used after releasing image/context.
- **Called by (best-effort):** Renderers sampling Syphon frames.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Trivial accessor.
- **Threading notes:** Accessor is cheap; GL use remains context/thread constrained.
- **Agent modification guidance:** Keep property readonly and type-stable.
- **Related symbols:** `textureSize`.

### Property `textureSize`
- **Signature:** `@property (readonly) NSSize textureSize;`
- **Location:** `source/.../SyphonImage.h:49`
- **Belongs to:** `SyphonImage`.
- **Purpose:** Reports dimensions of texture payload.
- **Inputs:** None.
- **Outputs / Return value:** `NSSize` width/height.
- **Side effects:** None.
- **Preconditions:** Image valid.
- **Postconditions:** Caller can compute UV/rectangle mapping.
- **Error handling / failure modes:** Undefined once backing resources are gone.
- **Called by (best-effort):** Layout/render logic.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Constant-time accessor.
- **Threading notes:** Metadata read only.
- **Agent modification guidance:** Preserve texture coordinate assumptions.
- **Related symbols:** `textureName`.
