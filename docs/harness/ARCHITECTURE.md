# Architecture (High-Level Harness)

This document is a **best-effort architectural map** based on build files and top-level runtime flow.
Where uncertain, notes are marked as probable.

## Scope

- Focuses on subsystem boundaries and startup/frame flow.
- Does **not** enumerate every class/function yet.

## Major Subsystems

- **Application Bootstrap / CLI (`source/main.cpp`)**
  - Parses extensive CLI options (input source, shader path, recording, playlists, stereo, plugin path, etc.).
  - Initializes GLFW + app window callbacks.
  - Configures capture source (camera/file/image), output writer (OpenCV or ffmpeg pipe), optional MIDI and optional RtAudio reactivity.

- **Windowing + Render Loop (`source/gl_window.*`)**
  - Thin base window abstraction over GLFW/GLAD.
  - `create(...)` initializes context and calls virtual `init()`.
  - `loop()` drives frame updates by repeatedly calling virtual `update(time)`.

- **Frame Processing / Effects Orchestrator (`source/acidcam_window.*`)**
  - Central runtime state machine (filter index, shader index, playlists, snapshots, blend/state controls).
  - Manages shader loading, custom filter scripts, plugin execution, recording output interactions, and per-frame OpenGL texture updates.
  - Appears to be the core bridge between OpenCV frame data and OpenGL shader presentation.

- **Shader System (`filters/` + shader loader in core window)**
  - Large GLSL inventory loaded from `index.txt` + shader path.
  - Runtime supports shader cycling/lists and optional curated shader list files.

- **Filter Library Integration (`acidcam` external lib)**
  - Build files require `acidcam` via `pkg-config`; runtime references `ac::...` APIs (filter list, initialization, memory/thread tuning).
  - Indicates major CPU-side image effect logic lives in external dependency, with this repo acting as GL/UI/runtime host.

- **Plugin Runtime (`source/plugin-program.*` + `source/plugin/*`)**
  - Uses dynamic library loading (`dlopen`/`dlsym("filter")`) on non-Windows.
  - Plugin directory tree suggests many optional/custom filter modules built independently.

- **Input/Output Subsystems**
  - **Video/camera input** via OpenCV `VideoCapture` and optional screen capture modes (platform-conditional).
  - **Video output** via OpenCV `VideoWriter` or ffmpeg subprocess pipe.
  - **Audio** probable dual role:
    - RtAudio for reactive amplitude control (`REACTIVE_ENABLED`).
    - ffmpeg post-mux of original source audio when writing encoded output.

- **Control / UX Surfaces**
  - Keyboard control with optional external keymap files.
  - Playlist/autofilter automation.
  - Separate Qt launcher app (`launcher.gui/`) and separate MIDI mapping tool (`midi-cfg/`).

- **Platform Integration (probable split paths)**
  - CMake primary build for cross-platform desktop.
  - Legacy/alternate Makefiles for Linux/macOS variants, MIDI-enabled builds, and plugin builds.
  - Mac static/Syphon and Windows Visual Studio support directories indicate platform-specific packaging tracks.

## Probable Startup and Frame Call Flow

1. **Process launch** -> parse CLI/env (`main`).
2. Initialize optional subsystems (MIDI config, audio reactivity, IPC redirection as configured).
3. Initialize GLFW and create `AcidCam_Window` via `glWindow::create(...)`.
4. `AcidCam_Window::init()` sets GL objects/state and default effect runtime state.
5. Load runtime resources:
   - custom filter definitions,
   - plugin libraries,
   - shader index and shader programs,
   - playlists/autofilter/keymaps.
6. Configure capture source (camera/video/image/screen) and optional recording pipeline.
7. Enter `main_window.loop()` -> inherited GLFW loop:
   - on each frame: call `AcidCam_Window::update(time)`.
   - update path likely captures/advances input frame, applies acidcam/filter/plugin logic, applies GLSL shader stage, overlays text/debug, presents frame, and optionally writes to output.
8. On exit: release writer/capture/audio/MIDI/plugin-adjacent resources, optional audio mux, terminate GLFW.

## Uncertainty / Needs Verification

- Exact ordering of CPU-side acidcam filter pass vs GPU shader pass per frame (probable: CPU effects then shader render).
- Exact plugin ABI/build artifact naming on each platform (Linux dynamic loading is explicit; Windows path likely different).
- Screen-capture and Syphon/Spout feature coverage by platform and compile flags.
