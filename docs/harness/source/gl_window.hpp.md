# Harness Doc: `source/gl_window.hpp`

## File-level
- **File path:** `source/gl_window.hpp`
- **Purpose of file:** Declares base GLFW window abstraction used by acidcam runtime windows.
- **Dependencies/includes/imports:** `glad`, `GLFW`, STL.
- **Key classes/structs/types/globals/macros:** class `glWindow`; free functions `checkForError`, `updateError` (extern).
- **External resources touched:** OS window and OpenGL context.
- **Build role:** Base interface consumed by concrete window classes.
- **Risks/footguns:** Virtual destructor not declared; object lifetime likely managed non-polymorphically.

## Symbols

### `glWindow::create`
- **Signature:** `int create(bool record, bool full, bool resize, std::string name, int w, int h, int monitor)`
- **Location:** `source/gl_window.hpp:11`
- **Belongs to:** `acidcam::glWindow`
- **Purpose:** Create GLFW window/context and initialize derived runtime state.
- **Inputs:** mode flags, title, geometry, monitor index.
- **Outputs:** success/fail status (`1`/`0`).
- **Side effects:** allocates GLFW window; sets context current.
- **Preconditions:** GLFW initialized; monitor index expected valid.
- **Postconditions:** window/context ready, `init()` called on success.
- **Error handling / failure modes:** failure path logs and returns 0.
- **Called by:** app startup path.
- **Calls into:** GLFW/GLAD; `init()`.
- **Performance notes:** setup-time only.
- **Threading notes:** should run on main/UI thread.
- **Agent modification guidance:** preserve call to virtual `init()` after context creation.
- **Related symbols:** `loop`, `quit`, `update`.

### `glWindow::init` / `glWindow::update`
- **Signature:** `virtual void init() = 0;` / `virtual void update(double timeval) = 0;`
- **Location:** `source/gl_window.hpp:12-13`
- **Belongs to:** abstract interface methods.
- **Purpose:** Hooks for derived class startup and per-frame logic.
- **Inputs/Outputs:** implementation-defined.
- **Side effects:** implementation-defined.
- **Preconditions:** called with valid GL context.
- **Postconditions:** runtime state/frame rendered.
- **Error handling:** implementation-defined.
- **Called by:** `create` / `loop`.
- **Calls into:** derived implementations.
- **Performance notes:** frame-time critical for `update`.
- **Threading notes:** same thread as render loop.
- **Agent modification guidance:** avoid heavy blocking work in `update`.
- **Related symbols:** `loop`.

### `glWindow::loop`, `glWindow::win`, `glWindow::quit`, `checkForError`, `updateError`
- **Signature:** declared at `source/gl_window.hpp:14-24`.
- **Location:** see `source/gl_window.cpp` for definitions except `updateError` (external).
- **Purpose:** frame loop control and GL error utilities.
