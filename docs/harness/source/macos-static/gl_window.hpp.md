# Harness Doc: `source/macos-static/gl_window.hpp`

## File-level
- **File path:** `source/macos-static/gl_window.hpp`
- **Purpose of file:** Declares abstract OpenGL window lifecycle interface used by runtime render loops.
- **Dependencies/includes/imports:** `<iostream>`, `<string>`, `glad/glad.h`, `<GLFW/glfw3.h>`.
- **Key classes/structs/types/globals/macros:** `acidcam::glWindow`, free function `checkForError`, external `updateError` declaration.
- **External resources touched:** GLFW windows/monitors and OpenGL context state (in implementation).
- **Build role:** Base class contract for macOS static windowed rendering.
- **Risks/footguns:** `window` raw pointer lifecycle managed manually; no virtual destructor declared.

## Functions / Methods

### `glWindow::create`
- **Signature:** `int create(bool record, bool full, bool resize, std::string name, int w, int h, int monitor)`
- **Location:** `source/macos-static/gl_window.hpp:12`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Declare window/context creation entrypoint.
- **Inputs:** Recording/fullscreen/resize flags, title, dimensions, monitor index.
- **Outputs / Return value:** Success code.
- **Side effects:** Creates GLFW window and GL context in implementation.
- **Preconditions:** GLFW initialized by caller.
- **Postconditions:** Window and context become available on success.
- **Error handling / failure modes:** Returns failure code if creation fails.
- **Called by (best-effort):** App initialization paths.
- **Calls into (best-effort):** GLFW/GLAD setup in implementation.
- **Performance notes:** One-time setup.
- **Threading notes:** Should be called on main/UI thread for GLFW portability.
- **Agent modification guidance:** Keep parameter semantics stable for CLI/UI integration.
- **Related symbols:** `loop`, `init`, `update`.

### `glWindow::init`
- **Signature:** `virtual void init() = 0`
- **Location:** `source/macos-static/gl_window.hpp:13`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Abstract callback for subclass GL resource initialization.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Defined by subclass.
- **Preconditions:** Window/context created.
- **Postconditions:** Subclass-specific setup complete.
- **Error handling / failure modes:** Subclass responsibility.
- **Called by (best-effort):** `create`.
- **Calls into (best-effort):** Subclass implementations.
- **Performance notes:** Setup-time, app-defined.
- **Threading notes:** Runs on same thread as `create`.
- **Agent modification guidance:** Preserve pure-virtual contract.
- **Related symbols:** `update`, `loop`.

### `glWindow::update`
- **Signature:** `virtual void update(double timeval) = 0`
- **Location:** `source/macos-static/gl_window.hpp:14`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Abstract per-frame update/render callback.
- **Inputs:** Current time value.
- **Outputs / Return value:** None.
- **Side effects:** Defined by subclass.
- **Preconditions:** Active GL context during loop.
- **Postconditions:** Frame state may advance.
- **Error handling / failure modes:** Subclass responsibility.
- **Called by (best-effort):** `loop`.
- **Calls into (best-effort):** Subclass implementations.
- **Performance notes:** Called every frame.
- **Threading notes:** Same thread as event/render loop.
- **Agent modification guidance:** Keep timing contract intact.
- **Related symbols:** `loop`.

### `glWindow::loop`
- **Signature:** `void loop()`
- **Location:** `source/macos-static/gl_window.hpp:15`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Declare main render/event loop.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Polls events, swaps buffers, destroys window on exit.
- **Preconditions:** Window created successfully.
- **Postconditions:** Loop exits and window is destroyed.
- **Error handling / failure modes:** Depends on implementation and GLFW state.
- **Called by (best-effort):** Main runtime control flow.
- **Calls into (best-effort):** `update`, GLFW APIs.
- **Performance notes:** Frame-rate dependent loop.
- **Threading notes:** Should stay on thread owning GLFW context.
- **Agent modification guidance:** Maintain exit conditions and cleanup behavior.
- **Related symbols:** `quit`, `update`.

### `glWindow::win`
- **Signature:** `GLFWwindow *win() const`
- **Location:** `source/macos-static/gl_window.hpp:16`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Access raw GLFW window pointer.
- **Inputs:** None.
- **Outputs / Return value:** `GLFWwindow*`.
- **Side effects:** None.
- **Preconditions:** Window may be null before creation/after destruction.
- **Postconditions:** Caller can inspect/use pointer.
- **Error handling / failure modes:** Caller must null-check as needed.
- **Called by (best-effort):** Input/event integration code.
- **Calls into (best-effort):** None.
- **Performance notes:** O(1).
- **Threading notes:** Pointer use must follow GLFW thread rules.
- **Agent modification guidance:** Preserve simple accessor behavior.
- **Related symbols:** `create`, `loop`.

### `glWindow::quit`
- **Signature:** `void quit()`
- **Location:** `source/macos-static/gl_window.hpp:17`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Declare loop-stop request API.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Sets active flag false in implementation.
- **Preconditions:** Object initialized.
- **Postconditions:** Loop exits next iteration.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** UI callbacks/shutdown logic.
- **Calls into (best-effort):** Internal state mutation.
- **Performance notes:** O(1).
- **Threading notes:** Cross-thread invocation would need synchronization.
- **Agent modification guidance:** Keep as lightweight cooperative-stop signal.
- **Related symbols:** `loop`, `active`.

### `checkForError`
- **Signature:** `bool checkForError()`
- **Location:** `source/macos-static/gl_window.hpp:25`
- **Belongs to:** `acidcam` namespace (free function)
- **Purpose:** Declare GL error-drain helper.
- **Inputs:** None.
- **Outputs / Return value:** Whether errors were present.
- **Side effects:** Consumes GL errors in implementation.
- **Preconditions:** Valid GL context.
- **Postconditions:** GL error queue drained.
- **Error handling / failure modes:** Numeric diagnostics only.
- **Called by (best-effort):** Rendering/shader diagnostics paths.
- **Calls into (best-effort):** `glGetError` in implementation.
- **Performance notes:** Linear in queued errors.
- **Threading notes:** GL context-thread affinity.
- **Agent modification guidance:** Keep behavior aligned with `ShaderProgram::checkError`.
- **Related symbols:** `updateError`.

### `updateError`
- **Signature:** `extern void updateError()`
- **Location:** `source/macos-static/gl_window.hpp:26`
- **Belongs to:** `acidcam` namespace (external symbol)
- **Purpose:** Declare external error-state update hook used across modules.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Defined elsewhere.
- **Preconditions:** Linked symbol provided by another TU.
- **Postconditions:** Global error state may change.
- **Error handling / failure modes:** Link-time failure if not defined.
- **Called by (best-effort):** File-loading/initialization failures in related modules.
- **Calls into (best-effort):** External implementation.
- **Performance notes:** Depends on external implementation.
- **Threading notes:** Depends on external implementation.
- **Agent modification guidance:** Keep declaration in sync with actual definition.
- **Related symbols:** `checkForError`.
