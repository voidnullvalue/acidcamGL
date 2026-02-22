# Harness Doc: `source/macos-static/gl_window.cpp`

## File-level
- **File path:** `source/macos-static/gl_window.cpp`
- **Purpose of file:** Implements GLFW window/context creation and the main render/event loop.
- **Dependencies/includes/imports:** `gl_window.hpp`.
- **Key classes/structs/types/globals/macros:** `acidcam::glWindow`, `acidcam::checkForError`.
- **External resources touched:** GLFW monitors/windows, OpenGL context and error queue.
- **Build role:** Core runtime windowing glue for macOS static build.
- **Risks/footguns:** `exit(EXIT_FAILURE)` on GLAD failure terminates process; monitor index check uses `>` not `>=`.

## Functions / Methods

### `glWindow::create`
- **Signature:** `int glWindow::create(bool record, bool full, bool resize, std::string name, int w, int h, int monitor)`
- **Location:** `source/macos-static/gl_window.cpp:6-51`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Create and configure a GLFW window + GL context, then run subclass initialization.
- **Inputs:** Runtime flags (`record`, `full`, `resize`), window name, dimensions, monitor index.
- **Outputs / Return value:** `1` on success, `0` on window-creation failure.
- **Side effects:** Sets GLFW hints, may choose fullscreen monitor mode, creates/destroys window, initializes GLAD, sets swap interval and size limits.
- **Preconditions:** GLFW library initialized; monitor index generally valid.
- **Postconditions:** On success `window`, `window_width`, and `window_height` are set and `init()` has run.
- **Error handling / failure modes:** Logs and returns `0` if window creation fails; logs and terminates process on GLAD init failure.
- **Called by (best-effort):** Application startup code.
- **Calls into (best-effort):** `glfwGetMonitors`, `glfwGetVideoMode`, `glfwWindowHint`, `glfwCreateWindow`, `glfwMakeContextCurrent`, `gladLoadGLLoader`, `glfwSetWindowSizeLimits`, `glfwSwapInterval`, virtual `init()`.
- **Performance notes:** Setup-time operation.
- **Threading notes:** Should run on thread designated for GLFW context ownership.
- **Agent modification guidance:** Avoid changing record/fullscreen semantics without auditing CLI/UI expectations.
- **Related symbols:** `loop`, `quit`.

### `glWindow::loop`
- **Signature:** `void glWindow::loop()`
- **Location:** `source/macos-static/gl_window.cpp:53-61`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Drive frame updates until window close or explicit quit request.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Calls `update`, swaps buffers, polls events, destroys window when done.
- **Preconditions:** `window` created and context current.
- **Postconditions:** Event/render loop stopped and window destroyed.
- **Error handling / failure modes:** Depends on behavior of callbacks and GLFW internals.
- **Called by (best-effort):** Runtime control flow after successful creation.
- **Calls into (best-effort):** `glfwWindowShouldClose`, virtual `update`, `glfwSwapBuffers`, `glfwPollEvents`, `glfwDestroyWindow`.
- **Performance notes:** Work per frame determined by `update` and swap interval.
- **Threading notes:** Must stay on context-owning thread.
- **Agent modification guidance:** Keep cleanup call to `glfwDestroyWindow` on loop exit.
- **Related symbols:** `quit`, `active`.

### `glWindow::quit`
- **Signature:** `void glWindow::quit()`
- **Location:** `source/macos-static/gl_window.cpp:63-65`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Request loop termination.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Sets `active` to `false`.
- **Preconditions:** Object exists.
- **Postconditions:** `loop` condition will fail on next iteration.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Input handlers or shutdown logic.
- **Calls into (best-effort):** None.
- **Performance notes:** O(1).
- **Threading notes:** Cross-thread callers require synchronization to avoid data races.
- **Agent modification guidance:** Keep method lightweight and non-blocking.
- **Related symbols:** `loop`.

### `checkForError`
- **Signature:** `bool checkForError()`
- **Location:** `source/macos-static/gl_window.cpp:67-77`
- **Belongs to:** `acidcam` namespace (free function)
- **Purpose:** Drain OpenGL error queue and print discovered error codes.
- **Inputs:** None.
- **Outputs / Return value:** `true` if any errors were encountered.
- **Side effects:** Clears GL error state; writes diagnostics to stdout.
- **Preconditions:** Active GL context.
- **Postconditions:** No queued GL errors remain.
- **Error handling / failure modes:** Numeric output only.
- **Called by (best-effort):** Shader/render diagnostics.
- **Calls into (best-effort):** `glGetError`.
- **Performance notes:** Linear with number of queued errors.
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** Keep consistent with other GL error-check helpers for maintainability.
- **Related symbols:** `ShaderProgram::checkError`.
