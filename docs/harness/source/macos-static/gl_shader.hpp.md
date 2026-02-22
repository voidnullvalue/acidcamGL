# Harness Doc: `source/macos-static/gl_shader.hpp`

## File-level
- **File path:** `source/macos-static/gl_shader.hpp`
- **Purpose of file:** Declares the `acidcam::ShaderProgram` wrapper for loading/compiling/linking OpenGL shaders.
- **Dependencies/includes/imports:** `<iostream>`, `<string>`, `<glad/glad.h>`, `<GLFW/glfw3.h>`.
- **Key classes/structs/types/globals/macros:** `acidcam::ShaderProgram`.
- **External resources touched:** OpenGL program/shader objects (via API calls in implementation).
- **Build role:** Public interface for shader utilities used by the macOS static build.
- **Risks/footguns:** `id()` returns `int` while internal storage is `GLuint`; potential narrowing/sign confusion.

## Functions / Methods

### `ShaderProgram::ShaderProgram()`
- **Signature:** `ShaderProgram()`
- **Location:** `source/macos-static/gl_shader.hpp:12`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Default-constructor declaration.
- **Inputs:** None.
- **Outputs / Return value:** Constructed object.
- **Side effects:** None at declaration level.
- **Preconditions:** None.
- **Postconditions:** Instance can be initialized in implementation.
- **Error handling / failure modes:** None at declaration level.
- **Called by (best-effort):** Class construction sites.
- **Calls into (best-effort):** Constructor body in `gl_shader.cpp`.
- **Performance notes:** Trivial.
- **Threading notes:** Thread-safe construction semantics; GL use occurs later.
- **Agent modification guidance:** Keep signature stable to avoid ABI breaks.
- **Related symbols:** `shader_id`, `ShaderProgram(GLuint)`.

### `ShaderProgram::ShaderProgram(GLuint)`
- **Signature:** `ShaderProgram(GLuint id)`
- **Location:** `source/macos-static/gl_shader.hpp:13`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Construct wrapper around an existing program handle.
- **Inputs:** `id` OpenGL program handle.
- **Outputs / Return value:** Constructed object.
- **Side effects:** None at declaration level.
- **Preconditions:** Caller passes valid/expected program handle semantics.
- **Postconditions:** Instance tracks supplied handle.
- **Error handling / failure modes:** None at declaration level.
- **Called by (best-effort):** Wrapper construction paths.
- **Calls into (best-effort):** Constructor body in `gl_shader.cpp`.
- **Performance notes:** Trivial.
- **Threading notes:** Safe for value init.
- **Agent modification guidance:** Preserve lightweight-handle behavior.
- **Related symbols:** `id()`, `useProgram()`.

### `ShaderProgram::operator=`
- **Signature:** `ShaderProgram &operator=(const ShaderProgram &p)`
- **Location:** `source/macos-static/gl_shader.hpp:14`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Copy assignment declaration.
- **Inputs:** `p` source wrapper.
- **Outputs / Return value:** Assigned object reference.
- **Side effects:** Overwrites object state in implementation.
- **Preconditions:** Valid source object.
- **Postconditions:** Target mirrors source state.
- **Error handling / failure modes:** None declared.
- **Called by (best-effort):** Assignment expressions.
- **Calls into (best-effort):** `std::string` assignment in implementation.
- **Performance notes:** O(name length).
- **Threading notes:** External synchronization required for shared objects.
- **Agent modification guidance:** Do not introduce ownership-transfer semantics silently.
- **Related symbols:** `name_`, `shader_id`.

### `ShaderProgram::printShaderLog`
- **Signature:** `int printShaderLog(GLuint err)`
- **Location:** `source/macos-static/gl_shader.hpp:15`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Declare compile-log reporting helper.
- **Inputs:** Shader object handle.
- **Outputs / Return value:** Integer status code.
- **Side effects:** Logging in implementation.
- **Preconditions:** Valid GL context and handle.
- **Postconditions:** Diagnostics may be printed.
- **Error handling / failure modes:** Depends on GL API state.
- **Called by (best-effort):** `createProgram` failure paths.
- **Calls into (best-effort):** GL query APIs in implementation.
- **Performance notes:** Proportional to log size.
- **Threading notes:** GL context thread affinity applies.
- **Agent modification guidance:** Prefer RAII buffer management if refactoring.
- **Related symbols:** `printProgramLog`.

### `ShaderProgram::printProgramLog`
- **Signature:** `void printProgramLog(int p)`
- **Location:** `source/macos-static/gl_shader.hpp:16`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Declare link-log reporting helper.
- **Inputs:** Program ID.
- **Outputs / Return value:** None.
- **Side effects:** Logging in implementation.
- **Preconditions:** Valid GL context/program.
- **Postconditions:** Diagnostics may be printed.
- **Error handling / failure modes:** Depends on GL API state.
- **Called by (best-effort):** `createProgram` link failure path.
- **Calls into (best-effort):** GL query APIs in implementation.
- **Performance notes:** Proportional to log size.
- **Threading notes:** GL context thread affinity applies.
- **Agent modification guidance:** Consider `GLuint` parameter type for API consistency.
- **Related symbols:** `createProgram`.

### `ShaderProgram::checkError`
- **Signature:** `bool checkError()`
- **Location:** `source/macos-static/gl_shader.hpp:17`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Declare GL error-drain helper.
- **Inputs:** None.
- **Outputs / Return value:** `true` if errors were present.
- **Side effects:** Consumes GL error queue in implementation.
- **Preconditions:** Active GL context.
- **Postconditions:** Error queue drained.
- **Error handling / failure modes:** Logs numeric GL codes.
- **Called by (best-effort):** Shader compile/link workflow.
- **Calls into (best-effort):** `glGetError` in implementation.
- **Performance notes:** Loop count equals queued error count.
- **Threading notes:** GL context affinity applies.
- **Agent modification guidance:** Keep deterministic error-drain behavior.
- **Related symbols:** `acidcam::checkForError` in `gl_window`.

### `ShaderProgram::createProgram`
- **Signature:** `GLuint createProgram(const char *vert, const char *frag)`
- **Location:** `source/macos-static/gl_shader.hpp:18`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Declare in-memory shader compile/link entrypoint.
- **Inputs:** Vertex and fragment shader source C-strings.
- **Outputs / Return value:** Program ID or failure sentinel.
- **Side effects:** Creates GL shader/program objects in implementation.
- **Preconditions:** Valid GL context and GLSL source.
- **Postconditions:** Linked program may be produced.
- **Error handling / failure modes:** Failure handled by logging and zero-return in implementation.
- **Called by (best-effort):** `createProgramFromFile`.
- **Calls into (best-effort):** Multiple GL compile/link APIs in implementation.
- **Performance notes:** Shader compile/link is expensive setup work.
- **Threading notes:** Must run on GL context thread.
- **Agent modification guidance:** Preserve return-value contract expected by callers.
- **Related symbols:** `loadProgram`, `useProgram`.

### `ShaderProgram::createProgramFromFile`
- **Signature:** `GLuint createProgramFromFile(const std::string &vert, const std::string &frag)`
- **Location:** `source/macos-static/gl_shader.hpp:19`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Declare file-based shader loading helper.
- **Inputs:** Vertex/fragment file paths.
- **Outputs / Return value:** Program ID or failure sentinel.
- **Side effects:** File I/O and GL object creation in implementation.
- **Preconditions:** Shader files accessible; GL context valid.
- **Postconditions:** Program may be linked from file contents.
- **Error handling / failure modes:** Logs and updates global error state in implementation.
- **Called by (best-effort):** `loadProgram`.
- **Calls into (best-effort):** `createProgram`.
- **Performance notes:** Includes disk I/O plus compile/link time.
- **Threading notes:** File I/O thread-safe; GL operations context-bound.
- **Agent modification guidance:** Keep path-based API behavior stable for caller configs.
- **Related symbols:** `loadProgram`, `updateError`.

### `ShaderProgram::loadProgram`
- **Signature:** `bool loadProgram(const std::string &text1, const std::string &text2)`
- **Location:** `source/macos-static/gl_shader.hpp:21`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Declare high-level shader-loading helper.
- **Inputs:** Vertex and fragment shader file paths.
- **Outputs / Return value:** Success flag.
- **Side effects:** Updates internal program ID in implementation.
- **Preconditions:** Valid inputs and GL context.
- **Postconditions:** `shader_id` updated on success/failure path.
- **Error handling / failure modes:** Returns false on compile/link/load failures.
- **Called by (best-effort):** Rendering setup routines.
- **Calls into (best-effort):** `createProgramFromFile`.
- **Performance notes:** Setup-time operation.
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** Keep boolean contract and side-effect expectations.
- **Related symbols:** `id()`, `useProgram`.

### `ShaderProgram::id`
- **Signature:** `int id() const`
- **Location:** `source/macos-static/gl_shader.hpp:22`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Return current program ID.
- **Inputs:** None.
- **Outputs / Return value:** Stored program ID (as `int`).
- **Side effects:** None.
- **Preconditions:** None.
- **Postconditions:** Caller receives snapshot value.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Code binding uniforms/program state.
- **Calls into (best-effort):** None.
- **Performance notes:** O(1).
- **Threading notes:** Read-only accessor.
- **Agent modification guidance:** Changing return type impacts callers.
- **Related symbols:** `shader_id`, `useProgram`.

### `ShaderProgram::useProgram`
- **Signature:** `void useProgram()`
- **Location:** `source/macos-static/gl_shader.hpp:23`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Declare API to bind active GL program.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** GL state change in implementation.
- **Preconditions:** Valid GL context and compiled program.
- **Postconditions:** Program becomes current for subsequent draws.
- **Error handling / failure modes:** Depends on GL state/program validity.
- **Called by (best-effort):** Render passes.
- **Calls into (best-effort):** `glUseProgram` in implementation.
- **Performance notes:** Lightweight state change.
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** Avoid hidden state mutations beyond binding.
- **Related symbols:** `id()`, `loadProgram`.

### `ShaderProgram::setName`
- **Signature:** `void setName(const std::string &n)`
- **Location:** `source/macos-static/gl_shader.hpp:24`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Declare metadata setter for friendly shader name.
- **Inputs:** Name string.
- **Outputs / Return value:** None.
- **Side effects:** Updates internal `name_` in implementation.
- **Preconditions:** None.
- **Postconditions:** `name_` stores provided string.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Shader registry/setup code.
- **Calls into (best-effort):** `std::string` assignment.
- **Performance notes:** O(length of `n`).
- **Threading notes:** External synchronization if shared.
- **Agent modification guidance:** Keep metadata non-functional unless redesigning API.
- **Related symbols:** `name()`.

### `ShaderProgram::name`
- **Signature:** `std::string name() const`
- **Location:** `source/macos-static/gl_shader.hpp:25`
- **Belongs to:** `acidcam::ShaderProgram`
- **Purpose:** Return stored shader name metadata.
- **Inputs:** None.
- **Outputs / Return value:** Copy of `name_`.
- **Side effects:** None.
- **Preconditions:** None.
- **Postconditions:** Caller gets current name snapshot.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Diagnostics/UI text paths.
- **Calls into (best-effort):** `std::string` copy constructor.
- **Performance notes:** O(name length).
- **Threading notes:** Read accessor; sharing still requires synchronization for race-free access.
- **Agent modification guidance:** Consider `const std::string&` only with ABI and lifetime review.
- **Related symbols:** `setName`, `name_`.
