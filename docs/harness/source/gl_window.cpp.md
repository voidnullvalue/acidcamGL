# Harness Doc: `source/gl_window.cpp`

## File-level
- **File path:** `source/gl_window.cpp`
- **Purpose of file:** Implements common GLFW window setup and render loop for `glWindow`.
- **Dependencies/includes/imports:** `gl_window.hpp`.
- **Key classes/structs/types/globals/macros:** `acidcam::glWindow`; free `checkForError`.
- **External resources touched:** GLFW monitor/window objects, OpenGL context.
- **Build role:** Core runtime window bootstrap.
- **Risks/footguns:** Calls `exit(EXIT_FAILURE)` on GLAD load failure; abrupt process termination.

## Functions / Methods

### `glWindow::create`
- **Signature:** `int glWindow::create(bool record, bool full, bool resize, std::string name, int w, int h, int monitor)`
- **Location:** `source/gl_window.cpp:5-51`
- **Belongs to:** `glWindow`
- **Purpose:** Configure window hints, choose monitor/mode, create window/context, init GLAD, and call `init()`.
- **Inputs:** recording/fullscreen/resize flags, title, dimensions, monitor index.
- **Outputs:** `1` on success, `0` on window create failure.
- **Side effects:** creates/destroys GLFW resources, sets swap interval, may lock window size when recording.
- **Preconditions:** GLFW initialized; monitor list available.
- **Postconditions:** valid `window`, width/height cached, derived `init()` executed.
- **Error handling / failure modes:** logs and returns `0` on `glfwCreateWindow` failure; on GLAD failure logs, destroys window, terminates GLFW, exits process.
- **Called by:** startup in concrete app window.
- **Calls into:** GLFW APIs, `gladLoadGLLoader`, virtual `init()`.
- **Performance notes:** one-time startup.
- **Threading notes:** run on context-owning/main thread.
- **Agent modification guidance:** monitor bounds check currently `if(monitor > count)` (not `>=`); keep compatibility unless intentionally fixing.
- **Related symbols:** `loop`, `quit`, `window_width`, `window_height`.

### `glWindow::loop`
- **Signature:** `void glWindow::loop()`
- **Location:** `source/gl_window.cpp:53-62`
- **Belongs to:** `glWindow`
- **Purpose:** Run render/update loop until window-close or `quit()` signal.
- **Inputs:** none.
- **Outputs:** none.
- **Side effects:** repeatedly calls `update`, swaps buffers, polls events; destroys window on exit.
- **Preconditions:** `window` created and `init()` completed.
- **Postconditions:** GLFW window destroyed.
- **Error handling / failure modes:** no explicit handling inside loop.
- **Called by:** main application control flow.
- **Calls into:** virtual `update`, GLFW functions.
- **Performance notes:** frame-critical path.
- **Threading notes:** should stay on UI/render thread.
- **Agent modification guidance:** avoid expensive blocking work per-iteration.
- **Related symbols:** `active`, `quit`.

### `glWindow::quit`
- **Signature:** `void glWindow::quit()`
- **Location:** `source/gl_window.cpp:64-66`
- **Belongs to:** `glWindow`
- **Purpose:** Signal loop termination by flipping active flag.
- **Inputs/Outputs:** none.
- **Side effects:** sets `active = false`.
- **Preconditions:** none.
- **Postconditions:** next loop check exits.
- **Error handling:** none.
- **Called by:** user/event handlers.
- **Calls into:** none.
- **Performance notes:** trivial.
- **Threading notes:** write from another thread is not synchronized.
- **Agent modification guidance:** add atomic/synchronization only with broader thread model updates.
- **Related symbols:** `loop`.

### `checkForError`
- **Signature:** `bool checkForError()`
- **Location:** `source/gl_window.cpp:68-79`
- **Belongs to:** namespace `acidcam` free function.
- **Purpose:** Drain and print OpenGL errors.
- **Inputs:** none.
- **Outputs:** `true` if at least one GL error existed.
- **Side effects:** consumes GL error queue; logs to stdout.
- **Preconditions:** active GL context.
- **Postconditions:** GL error queue cleared.
- **Error handling / failure modes:** numeric errors only.
- **Called by:** best-effort diagnostics in rendering code.
- **Calls into:** `glGetError`.
- **Performance notes:** loops per pending error.
- **Threading notes:** context-thread affinity.
- **Agent modification guidance:** similar behavior to `ShaderProgram::checkError`; keep semantics aligned.
- **Related symbols:** `ShaderProgram::checkError`.
