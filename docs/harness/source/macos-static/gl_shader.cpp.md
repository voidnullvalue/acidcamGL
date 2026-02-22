# Harness Doc: `source/macos-static/gl_shader.cpp`

## File-level
- **File path:** `source/macos-static/gl_shader.cpp`
- **Purpose of file:** Implements OpenGL shader compile/link helpers and wrapper methods for program loading.
- **Dependencies/includes/imports:** `gl_shader.hpp`, `<sstream>`, `<fstream>`.
- **Key classes/structs/types/globals/macros:** `acidcam::ShaderProgram`; external `updateError()`.
- **External resources touched:** OpenGL shader/program state and shader source files on disk.
- **Build role:** GL helper implementation for macOS static variant.
- **Risks/footguns:** Early returns can leave created shader objects undeleted; `printProgramLog` queries log length with `glGetShaderiv`.

## Functions / Methods

### `ShaderProgram::ShaderProgram()`
- **Signature:** `ShaderProgram::ShaderProgram()`
- **Location:** `source/macos-static/gl_shader.cpp:9-11`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Initialize wrapper with zero program ID.
- **Inputs:** None.
- **Outputs / Return value:** Constructed object.
- **Side effects:** Sets `shader_id` to `0`.
- **Preconditions:** None.
- **Postconditions:** Object begins in unloaded state.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Default construction sites.
- **Calls into (best-effort):** None.
- **Performance notes:** Trivial.
- **Threading notes:** Safe value initialization.
- **Agent modification guidance:** Preserve default zero-id semantics.
- **Related symbols:** `loadProgram`, `id()`.

### `ShaderProgram::ShaderProgram(GLuint)`
- **Signature:** `ShaderProgram::ShaderProgram(GLuint id)`
- **Location:** `source/macos-static/gl_shader.cpp:13-15`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Initialize wrapper with an existing program handle.
- **Inputs:** `id`.
- **Outputs / Return value:** Constructed object.
- **Side effects:** Stores provided handle in `shader_id`.
- **Preconditions:** Caller provides intended GL handle.
- **Postconditions:** Wrapper references provided program ID.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Handle wrapping paths.
- **Calls into (best-effort):** None.
- **Performance notes:** Trivial.
- **Threading notes:** Safe value initialization.
- **Agent modification guidance:** Keep non-owning handle semantics unless redesigning resource management.
- **Related symbols:** `useProgram`.

### `ShaderProgram::operator=`
- **Signature:** `ShaderProgram &ShaderProgram::operator=(const ShaderProgram &p)`
- **Location:** `source/macos-static/gl_shader.cpp:17-21`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Copy assign shader handle/name.
- **Inputs:** Source wrapper.
- **Outputs / Return value:** `*this`.
- **Side effects:** Overwrites `shader_id` and `name_`.
- **Preconditions:** Valid source object.
- **Postconditions:** Target mirrors source state.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Assignment expressions.
- **Calls into (best-effort):** `std::string` assignment.
- **Performance notes:** O(name length).
- **Threading notes:** Guard shared instances externally.
- **Agent modification guidance:** Preserve expected copy behavior.
- **Related symbols:** Constructors, `setName`.

### `ShaderProgram::printShaderLog`
- **Signature:** `int ShaderProgram::printShaderLog(GLuint shader)`
- **Location:** `source/macos-static/gl_shader.cpp:23-35`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Print compile diagnostics for a shader object.
- **Inputs:** Shader object ID.
- **Outputs / Return value:** Returns `0`.
- **Side effects:** Allocates temporary buffer; writes to stdout.
- **Preconditions:** Valid GL context.
- **Postconditions:** Available info log emitted.
- **Error handling / failure modes:** Invalid handle/context may set GL errors.
- **Called by (best-effort):** `createProgram` when compilation fails.
- **Calls into (best-effort):** `glGetShaderiv`, `glGetShaderInfoLog`.
- **Performance notes:** O(log length).
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** Prefer RAII container over raw new/delete if touched.
- **Related symbols:** `printProgramLog`.

### `ShaderProgram::printProgramLog`
- **Signature:** `void ShaderProgram::printProgramLog(int p)`
- **Location:** `source/macos-static/gl_shader.cpp:36-47`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Print program link diagnostics.
- **Inputs:** Program ID.
- **Outputs / Return value:** None.
- **Side effects:** Allocates temporary buffer; logs to stdout.
- **Preconditions:** Valid GL context/program.
- **Postconditions:** Program info log emitted when present.
- **Error handling / failure modes:** Uses `glGetShaderiv` for length query (likely bug/quirk).
- **Called by (best-effort):** `createProgram` on link failure.
- **Calls into (best-effort):** `glGetShaderiv`, `glGetProgramInfoLog`.
- **Performance notes:** O(log length).
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** Consider switching length query to `glGetProgramiv` if fixing behavior.
- **Related symbols:** `createProgram`.

### `ShaderProgram::checkError`
- **Signature:** `bool ShaderProgram::checkError()`
- **Location:** `source/macos-static/gl_shader.cpp:48-58`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Drain OpenGL error queue and print numeric errors.
- **Inputs:** None.
- **Outputs / Return value:** `true` when one or more errors were found.
- **Side effects:** Consumes GL error state; console logging.
- **Preconditions:** Valid GL context.
- **Postconditions:** GL error queue drained.
- **Error handling / failure modes:** Numeric-only diagnostics.
- **Called by (best-effort):** `createProgram` after compile/link calls.
- **Calls into (best-effort):** `glGetError`.
- **Performance notes:** Linear in number of pending errors.
- **Threading notes:** Must execute on context-owning thread.
- **Agent modification guidance:** Keep callsites around compile/link for diagnostics continuity.
- **Related symbols:** `acidcam::checkForError`.

### `ShaderProgram::createProgram`
- **Signature:** `GLuint ShaderProgram::createProgram(const char *vshaderSource, const char *fshaderSource)`
- **Location:** `source/macos-static/gl_shader.cpp:60-102`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Compile vertex/fragment shaders and link them into one GL program.
- **Inputs:** Vertex/fragment shader source strings.
- **Outputs / Return value:** Linked program ID; `0` on any failure.
- **Side effects:** Creates shader/program objects and mutates GL state.
- **Preconditions:** Active GL context; valid GLSL inputs.
- **Postconditions:** Successful return yields link-ready program.
- **Error handling / failure modes:** Logs compile/link errors and returns `0` early.
- **Called by (best-effort):** `createProgramFromFile`.
- **Calls into (best-effort):** `glCreateShader`, `glShaderSource`, `glCompileShader`, `glGetShaderiv`, `glCreateProgram`, `glAttachShader`, `glLinkProgram`, `glGetProgramiv`, helpers above.
- **Performance notes:** High relative cost (shader compilation/linking).
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** If refactoring, add explicit shader cleanup to avoid object leaks.
- **Related symbols:** `printShaderLog`, `printProgramLog`, `checkError`.

### `ShaderProgram::createProgramFromFile`
- **Signature:** `GLuint ShaderProgram::createProgramFromFile(const std::string &vert, const std::string &frag)`
- **Location:** `source/macos-static/gl_shader.cpp:104-120`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Read shader files then delegate to `createProgram`.
- **Inputs:** Paths to vertex/fragment source files.
- **Outputs / Return value:** Program ID or `0`.
- **Side effects:** File I/O and global error update calls.
- **Preconditions:** Paths should be valid/readable.
- **Postconditions:** Attempts compile/link using loaded file contents.
- **Error handling / failure modes:** Logs and calls `acidcam::updateError()` if files cannot be opened.
- **Called by (best-effort):** `loadProgram`.
- **Calls into (best-effort):** `std::fstream::open`, `createProgram`, `acidcam::updateError`.
- **Performance notes:** Disk I/O + compilation cost.
- **Threading notes:** File I/O thread-safe, GL operations remain context-bound.
- **Agent modification guidance:** Consider returning early when file open fails if tightening behavior.
- **Related symbols:** `loadProgram`.

### `ShaderProgram::loadProgram`
- **Signature:** `bool ShaderProgram::loadProgram(const std::string &v, const std::string &f)`
- **Location:** `source/macos-static/gl_shader.cpp:122-127`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Load program from files and store handle.
- **Inputs:** Vertex and fragment shader file paths.
- **Outputs / Return value:** `true` on success, else `false`.
- **Side effects:** Updates `shader_id`.
- **Preconditions:** GL context active and files available.
- **Postconditions:** `shader_id` updated with resulting program handle.
- **Error handling / failure modes:** False return communicates failure.
- **Called by (best-effort):** Rendering initialization.
- **Calls into (best-effort):** `createProgramFromFile`.
- **Performance notes:** Setup-time operation.
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** Keep success/failure contract simple for callers.
- **Related symbols:** `useProgram`, `id`.

### `ShaderProgram::setName`
- **Signature:** `void ShaderProgram::setName(const std::string &n)`
- **Location:** `source/macos-static/gl_shader.cpp:129-131`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Store friendly name metadata.
- **Inputs:** Name string.
- **Outputs / Return value:** None.
- **Side effects:** Updates `name_`.
- **Preconditions:** None.
- **Postconditions:** `name_` equals `n`.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Shader registration paths.
- **Calls into (best-effort):** `std::string` assignment.
- **Performance notes:** O(length of name).
- **Threading notes:** Synchronize when shared.
- **Agent modification guidance:** Keep metadata role separate from GL behavior.
- **Related symbols:** `name`.

### `ShaderProgram::useProgram`
- **Signature:** `void ShaderProgram::useProgram()`
- **Location:** `source/macos-static/gl_shader.cpp:133-135`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Bind stored GL program for rendering.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Sets current GL program state.
- **Preconditions:** Valid GL context; `shader_id` should reference linked program.
- **Postconditions:** Program bound via `glUseProgram`.
- **Error handling / failure modes:** GL may signal errors for invalid program/context.
- **Called by (best-effort):** Render/update code before draw calls.
- **Calls into (best-effort):** `glUseProgram`.
- **Performance notes:** Lightweight state change.
- **Threading notes:** Context-thread affinity required.
- **Agent modification guidance:** Keep direct binding behavior predictable.
- **Related symbols:** `id`, `loadProgram`.
