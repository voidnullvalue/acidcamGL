# Harness Doc: `source/gl_shader.hpp`

## File-level
- **File path:** `source/gl_shader.hpp`
- **Purpose of file:** Declares `acidcam::ShaderProgram`, a wrapper around OpenGL shader-program creation/loading and use.
- **Dependencies/includes/imports:** `<glad/glad.h>`, `<GLFW/glfw3.h>`, STL string/iostream.
- **Key classes/structs/types/globals/macros:** class `ShaderProgram`.
- **External resources touched:** OpenGL program/shader handles.
- **Build role:** Public interface for shader compilation/linking helper.
- **Risks/footguns:** No RAII cleanup API exposed for shader/program deletion.

## Symbols

### `ShaderProgram::ShaderProgram()`
- **Signature:** `ShaderProgram()`
- **Location:** `source/gl_shader.hpp:12`
- **Belongs to:** class `ShaderProgram`
- **Purpose:** Default-constructs wrapper object.
- **Inputs:** none
- **Outputs / Return value:** object with default state.
- **Side effects:** none
- **Preconditions:** none
- **Postconditions:** `shader_id` expected to be zero-initialized in implementation.
- **Error handling / failure modes:** none
- **Called by:** object creation sites.
- **Calls into:** none (decl).
- **Performance notes:** trivial.
- **Threading notes:** object-local.
- **Agent modification guidance:** keep initialization behavior matched with `.cpp`.
- **Related symbols:** `shader_id`.

### `ShaderProgram::ShaderProgram(GLuint id)`
- **Signature:** `ShaderProgram(GLuint id)`
- **Location:** `source/gl_shader.hpp:13`
- **Belongs to:** class `ShaderProgram`
- **Purpose:** Construct wrapper from an existing GL program ID.
- **Inputs:** `id` program handle.
- **Outputs:** initialized object.
- **Side effects:** none.
- **Preconditions:** `id` should refer to a valid linked program or zero.
- **Postconditions:** `shader_id == id`.
- **Error handling:** none.
- **Called by/Calls into:** construction flow.
- **Performance notes:** trivial.
- **Threading notes:** OpenGL context ownership still applies at use-time.
- **Agent modification guidance:** avoid implicit ownership semantics unless adding deletion policy.
- **Related symbols:** `id()`, `useProgram()`.

### `ShaderProgram::operator=`
- **Signature:** `ShaderProgram &operator=(const ShaderProgram &p)`
- **Location:** `source/gl_shader.hpp:14`
- **Belongs to:** class `ShaderProgram`
- **Purpose:** Copies `shader_id` and debug name.
- **Inputs:** source object `p`.
- **Outputs:** `*this`.
- **Side effects:** overwrites current wrapper state.
- **Preconditions:** none.
- **Postconditions:** copied values mirror `p`.
- **Error handling:** none.
- **Called by:** assignment at call sites.
- **Calls into:** none (decl).
- **Performance notes:** O(1) + string copy.
- **Threading notes:** external synchronization needed for shared objects.
- **Agent modification guidance:** maintain copy semantics consistency.
- **Related symbols:** `name_`, `shader_id`.

### `printShaderLog`, `printProgramLog`, `checkError`, `createProgram`, `createProgramFromFile`, `loadProgram`, `useProgram`, `setName`, `name`, `id`
- **Signature:** Declared at `source/gl_shader.hpp:15-24`.
- **Location:** Header declarations; implemented in `source/gl_shader.cpp`.
- **Belongs to:** class `ShaderProgram`.
- **Purpose:** Diagnostics, compile/link pipeline, program activation, and metadata access.
- **Inputs/Outputs:** See implementation doc for behavior details.
- **Agent modification guidance:** keep declaration/definition signatures synchronized.
