# Harness Doc: `source/gl_shader.cpp`

## File-level
- **File path:** `source/gl_shader.cpp`
- **Purpose of file:** Implements shader compilation/linking helpers for runtime GLSL program loading.
- **Dependencies/includes/imports:** `gl_shader.hpp`, `<fstream>`, `<sstream>`; OpenGL API.
- **Key classes/structs/types/globals/macros:** `acidcam::ShaderProgram`; external `updateError()` declaration.
- **External resources touched:** OpenGL shader/program state, shader source files.
- **Build role:** Runtime GL utility implementation.
- **Risks/footguns:** No explicit shader/program object deletion; potential leaks if frequently recompiled.

## Functions / Methods

### `ShaderProgram::ShaderProgram()` / `ShaderProgram::ShaderProgram(GLuint)`
- **Signature:** constructors.
- **Location:** `source/gl_shader.cpp:8-14`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Initialize wrapper with empty/explicit program ID.
- **Inputs:** optional program handle.
- **Outputs / Return value:** constructed object.
- **Side effects:** internal state set.
- **Preconditions:** none.
- **Postconditions:** `shader_id` holds provided/default value.
- **Error handling / failure modes:** none.
- **Called by:** object creation sites.
- **Calls into:** none.
- **Performance notes:** trivial.
- **Threading notes:** thread-safe as plain value init.
- **Agent modification guidance:** preserve lightweight behavior.
- **Related symbols:** `operator=`, `id()`.

### `ShaderProgram::operator=`
- **Signature:** `ShaderProgram &operator=(const ShaderProgram &p)`
- **Location:** `source/gl_shader.cpp:16-20`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Copy assign wrapper metadata and handle.
- **Inputs:** source wrapper.
- **Outputs:** assigned object reference.
- **Side effects:** overwrites `shader_id`, `name_`.
- **Preconditions/Postconditions:** none / mirrors source state.
- **Error handling:** none.
- **Called by:** assignment expressions.
- **Calls into:** `std::string` assignment.
- **Performance notes:** O(len(name_)).
- **Threading notes:** external locking for shared instances.
- **Agent modification guidance:** keep shallow-handle semantics unless ownership model changes.
- **Related symbols:** `name_`, `shader_id`.

### `printShaderLog`
- **Signature:** `int printShaderLog(GLuint shader)`
- **Location:** `source/gl_shader.cpp:22-33`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Print GLSL compile log for shader object.
- **Inputs:** shader handle.
- **Outputs:** returns `0` (status not used).
- **Side effects:** heap alloc/free; writes to stdout.
- **Preconditions:** valid GL context and shader handle.
- **Postconditions:** diagnostic log emitted when available.
- **Error handling / failure modes:** if handle invalid, OpenGL error state may be set.
- **Called by:** `createProgram` on compile failure.
- **Calls into:** `glGetShaderiv`, `glGetShaderInfoLog`.
- **Performance notes:** proportional to log length.
- **Threading notes:** GL context-thread affinity applies.
- **Agent modification guidance:** prefer `std::vector<char>` to avoid manual new/delete if refactoring.
- **Related symbols:** `printProgramLog`.

### `printProgramLog`
- **Signature:** `void printProgramLog(int p)`
- **Location:** `source/gl_shader.cpp:34-45`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Print link-time program log.
- **Inputs:** program object ID (`int`, though GL API expects GLuint).
- **Outputs:** none.
- **Side effects:** stdout logging.
- **Preconditions:** valid GL context.
- **Postconditions:** link diagnostics emitted if present.
- **Error handling:** none.
- **Called by:** `createProgram` on link failure.
- **Calls into:** `glGetShaderiv` (likely intended `glGetProgramiv` for log length), `glGetProgramInfoLog`.
- **Performance notes:** proportional to log length.
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** potential bug/quirk: uses `glGetShaderiv` for program log length.
- **Related symbols:** `createProgram`.

### `checkError`
- **Signature:** `bool checkError()`
- **Location:** `source/gl_shader.cpp:46-56`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Drain and print current OpenGL error queue.
- **Inputs:** none.
- **Outputs:** `true` if any errors were present.
- **Side effects:** consumes GL error state; logs values.
- **Preconditions:** valid GL context.
- **Postconditions:** GL error queue emptied.
- **Error handling:** reports numeric codes only.
- **Called by:** compile/link path.
- **Calls into:** `glGetError`.
- **Performance notes:** loops until no errors.
- **Threading notes:** context-thread affinity.
- **Agent modification guidance:** keep behavior deterministic; avoid swallowing errors silently.
- **Related symbols:** free function `acidcam::checkForError` in `gl_window.cpp`.

### `createProgram`
- **Signature:** `GLuint createProgram(const char *vshaderSource, const char *fshaderSource)`
- **Location:** `source/gl_shader.cpp:58-102`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Compile vertex/fragment shaders and link them into a program.
- **Inputs:** in-memory vertex + fragment shader source strings.
- **Outputs:** linked program ID or `0` on failure.
- **Side effects:** creates GL shader/program objects; logs failures.
- **Preconditions:** active GL context; valid GLSL sources.
- **Postconditions:** linked program available when successful.
- **Error handling / failure modes:** returns 0 on compile/link errors after logging.
- **Called by:** `createProgramFromFile`.
- **Calls into:** `glCreateShader`, `glShaderSource`, `glCompileShader`, `glGetShaderiv`, `glCreateProgram`, `glAttachShader`, `glLinkProgram`, `glGetProgramiv`.
- **Performance notes:** shader compilation/link are expensive setup-time operations.
- **Threading notes:** must run on context-owning thread.
- **Agent modification guidance:** consider cleanup of intermediate shaders/programs on failure/success in future pass.
- **Related symbols:** `loadProgram`, `printShaderLog`, `printProgramLog`.

### `createProgramFromFile`
- **Signature:** `GLuint createProgramFromFile(const std::string &vert, const std::string &frag)`
- **Location:** `source/gl_shader.cpp:104-121`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Load shader source files, then compile/link.
- **Inputs:** vertex + fragment file paths.
- **Outputs:** program ID or 0.
- **Side effects:** filesystem reads; may call global `updateError()` on file-open failure.
- **Preconditions:** files readable.
- **Postconditions:** compile attempted even after open failure (streams may be empty).
- **Error handling / failure modes:** prints file errors and sets global error flag via `updateError()`.
- **Called by:** `loadProgram`.
- **Calls into:** fstream APIs, `createProgram`.
- **Performance notes:** file I/O + compile/link costs.
- **Threading notes:** file I/O thread-safe; GL call part context-bound.
- **Agent modification guidance:** uncertainty: function continues after failed open; guard may be tightened later.
- **Related symbols:** `updateError` (external).

### `loadProgram`
- **Signature:** `bool loadProgram(const std::string &v, const std::string &f)`
- **Location:** `source/gl_shader.cpp:123-128`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Convenience wrapper to set `shader_id` from file-based load.
- **Inputs:** vertex/fragment paths.
- **Outputs:** `true` when `shader_id != 0`.
- **Side effects:** mutates object state.
- **Preconditions:** valid context + readable files.
- **Postconditions:** `shader_id` updated.
- **Error handling / failure modes:** relies on called functions.
- **Called by:** shader-loading runtime.
- **Calls into:** `createProgramFromFile`.
- **Performance notes:** setup-time path.
- **Threading notes:** context-thread affinity.
- **Agent modification guidance:** keep boolean success semantics stable.
- **Related symbols:** `shader_id`, `useProgram`.

### `setName`, `useProgram`
- **Signature:** `void setName(const std::string &n)`, `void useProgram()`
- **Location:** `source/gl_shader.cpp:130-136`
- **Belongs to:** `ShaderProgram`
- **Purpose:** Store debug/display name and bind program for rendering.
- **Inputs:** name string / none.
- **Outputs:** none.
- **Side effects:** mutate `name_`; changes active GL program (`glUseProgram`).
- **Preconditions:** `useProgram` requires valid context and program ID.
- **Postconditions:** active shader program switched.
- **Error handling:** none explicit.
- **Called by:** rendering pipeline.
- **Calls into:** `glUseProgram`.
- **Performance notes:** inexpensive.
- **Threading notes:** `glUseProgram` is context-thread bound.
- **Agent modification guidance:** avoid calling `useProgram` with zero unless intended.
- **Related symbols:** `id()`, `name()`.
