# Harness Doc: `source/macos-static/ffmpeg_write.h`

## File-level
- **File path:** `source/macos-static/ffmpeg_write.h`
- **Purpose of file:** Declares ffmpeg writer helper API and shared executable path variable.
- **Dependencies/includes/imports:** iostream, string, cstdlib, OpenCV, sstream.
- **Key classes/structs/types/globals/macros:** `ffmpeg_path` extern; ffmpeg helper function declarations.
- **External resources touched:** Declared API interacts with ffmpeg subprocesses and media files.
- **Build role:** Public header for recording/muxing helpers used by multiple translation units.
- **Risks/footguns:** Uses raw `FILE*`; callers must manage subprocess/pipe lifetimes carefully.

## Symbols

### Global variable declaration `ffmpeg_path`
- **Signature:** `extern std::string ffmpeg_path;`
- **Location:** `source/macos-static/ffmpeg_write.h:11`
- **Belongs to:** Global namespace.
- **Purpose:** Shares resolved ffmpeg executable path.
- **Inputs:** Set by implementation.
- **Outputs / Return value:** Read by helper functions/callers.
- **Side effects:** Runtime command location decisions.
- **Preconditions:** Defined in exactly one implementation unit.
- **Postconditions:** Commands use this binary path.
- **Error handling / failure modes:** Invalid path causes subprocess launch failures.
- **Called by / Calls into (best-effort):** Used by `open_ffmpeg`, `list_devices`, mux/rotate helpers.
- **Performance notes:** Constant-size string access.
- **Threading notes:** Mutable global; synchronize writes.
- **Agent modification guidance:** Keep declaration in sync with definition.
- **Related symbols:** `open_ffmpeg`.

### Function declarations
- **Signature:** `open_ffmpeg(...)`, `write_ffmpeg(FILE*, cv::Mat&)`, `mux_audio(...)`, `rotate_90(...)`, `close_stdout()`, `list_devices()`.
- **Location:** `source/macos-static/ffmpeg_write.h:13-18`
- **Belongs to:** Global namespace.
- **Purpose:** Exposes ffmpeg launch, frame write, mux, rotation, and utility actions.
- **Inputs:** Media paths/options and raw frame buffers.
- **Outputs / Return value:** Pipe handle for `open_ffmpeg`; otherwise side-effecting void APIs.
- **Side effects:** Subprocess launch and stream/file modifications (implemented in `.cpp`).
- **Preconditions:** ffmpeg availability and valid arguments.
- **Postconditions:** Encoded/muxed output media produced best-effort.
- **Error handling / failure modes:** Implementation currently logs errors with limited status reporting.
- **Called by (best-effort):** Recording workflow in application runtime.
- **Calls into (best-effort):** Implementations invoke stdio/process APIs and ffmpeg.
- **Performance notes:** Dominated by external ffmpeg process execution.
- **Threading notes:** `FILE*` and shared globals need caller-side serialization.
- **Agent modification guidance:** Keep declarations and implementation signatures strictly aligned.
- **Related symbols:** `ffmpeg_path`, implementation in `ffmpeg_write.cpp`.
