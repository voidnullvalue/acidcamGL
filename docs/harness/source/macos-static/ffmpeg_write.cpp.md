# Harness Doc: `source/macos-static/ffmpeg_write.cpp`

## File-level
- **File path:** `source/macos-static/ffmpeg_write.cpp`
- **Purpose of file:** Implements ffmpeg subprocess piping helpers for recording raw OpenCV frames and post-processing media.
- **Dependencies/includes/imports:** `ffmpeg_write.h`, platform headers (`mach-o/dyld.h`, `unistd.h`), `ipc_client.hpp`, iostream/sstream/fstream.
- **Key classes/structs/types/globals/macros:** Globals `ffmpeg_path`, `buffer`, `file`, `stdout_save`; functions `open_ffmpeg`, `list_devices`, `write_ffmpeg`, `close_stdout`, `mux_audio`, `rotate_90`.
- **External resources touched:** Launches `ffmpeg` process via `popen/_popen`; writes frame bytes to ffmpeg stdin; prints command logs.
- **Build role:** Runtime media output implementation for macOS-static build variant.
- **Risks/footguns:** Shell command composition with quoted args; limited error propagation; `close_stdout()` currently empty.

## Symbols

### Function `open_ffmpeg`
- **Signature:** `FILE *open_ffmpeg(const char *output, const char *codec, const char *res, const char *dst_res, const char *fps, const char *crf)`
- **Location:** `source/macos-static/ffmpeg_write.cpp:30-115`
- **Belongs to:** Global namespace.
- **Purpose:** Builds ffmpeg encode command and opens writable pipe to process stdin.
- **Inputs:** Output file path, codec, source/destination resolutions, frame rate, quality value.
- **Outputs / Return value:** `FILE*` pipe handle or `0` on failure.
- **Side effects:** May rewrite global `ffmpeg_path` on Apple; prints full command; spawns ffmpeg subprocess.
- **Preconditions:** ffmpeg executable available; arguments are valid for selected codec.
- **Postconditions:** Caller can stream raw BGR frames into returned pipe.
- **Error handling / failure modes:** Logs to `stderr` and returns null when process open fails.
- **Called by (best-effort):** Video capture/recording workflow.
- **Calls into (best-effort):** `_NSGetExecutablePath`, `dirname`, `popen/_popen`.
- **Performance notes:** One-time process launch; command string assembly linear in argument size.
- **Threading notes:** Mutates global `ffmpeg_path`; coordinate if called concurrently.
- **Agent modification guidance:** Keep codec-option mapping table aligned with ffmpeg CLI changes.
- **Related symbols:** `write_ffmpeg`, `mux_audio`, `rotate_90`.

### Function `list_devices`
- **Signature:** `void list_devices()`
- **Location:** `source/macos-static/ffmpeg_write.cpp:119-134`
- **Belongs to:** Global namespace.
- **Purpose:** On Apple builds, queries ffmpeg avfoundation input device list.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Executes ffmpeg command and prints stdout lines; exits process on popen failure.
- **Preconditions:** Apple platform and ffmpeg present.
- **Postconditions:** Device listing emitted to console.
- **Error handling / failure modes:** Prints error and calls `exit(0)` if pipe open fails.
- **Called by (best-effort):** Audio/video source configuration UI.
- **Calls into (best-effort):** `popen`, `fgets`, `pclose`.
- **Performance notes:** O(output size) stream read.
- **Threading notes:** Console output not synchronized.
- **Agent modification guidance:** Consider non-terminating error handling if hardening.
- **Related symbols:** `ffmpeg_path`.

### Function `write_ffmpeg`
- **Signature:** `void write_ffmpeg(FILE *fptr, cv::Mat &frame)`
- **Location:** `source/macos-static/ffmpeg_write.cpp:136-138`
- **Belongs to:** Global namespace.
- **Purpose:** Streams one OpenCV frame's raw bytes into ffmpeg pipe.
- **Inputs:** Open pipe handle and frame matrix.
- **Outputs / Return value:** None.
- **Side effects:** Writes binary bytes to child process stdin.
- **Preconditions:** `fptr` valid, frame contiguous/compatible with expected pixel format.
- **Postconditions:** Frame bytes appended to ffmpeg input stream.
- **Error handling / failure modes:** No write-result validation.
- **Called by (best-effort):** Recording loop per frame.
- **Calls into (best-effort):** `fwrite`.
- **Performance notes:** O(frame byte size) per call.
- **Threading notes:** Shared `FILE*` writes must be serialized.
- **Agent modification guidance:** Add error checks/flush logic if reliability improvements are needed.
- **Related symbols:** `open_ffmpeg`.

### Function `close_stdout`
- **Signature:** `void close_stdout()`
- **Location:** `source/macos-static/ffmpeg_write.cpp:140-142`
- **Belongs to:** Global namespace.
- **Purpose:** Placeholder for historical stdout redirection cleanup.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** None in current implementation.
- **Preconditions/Postconditions:** N/A.
- **Error handling / failure modes:** N/A.
- **Called by (best-effort):** Potential cleanup call sites.
- **Calls into (best-effort):** None.
- **Performance notes:** No-op.
- **Threading notes:** No state changes.
- **Agent modification guidance:** Safe spot for implementing descriptor restoration.
- **Related symbols:** `stdout_save` global.

### Function `mux_audio`
- **Signature:** `void mux_audio(const char *output, const char *src, const char *final_file)`
- **Location:** `source/macos-static/ffmpeg_write.cpp:144-162`
- **Belongs to:** Global namespace.
- **Purpose:** Runs ffmpeg to combine captured video and external audio into final output.
- **Inputs:** Video source, audio source, target output path.
- **Outputs / Return value:** None.
- **Side effects:** Spawns ffmpeg subprocess and logs command string.
- **Preconditions:** Input files exist and ffmpeg is available.
- **Postconditions:** Mux command executed; produced file expected at `final_file`.
- **Error handling / failure modes:** Logs error and returns if process open fails.
- **Called by (best-effort):** Post-recording finalize flow.
- **Calls into (best-effort):** `popen/_popen`, `pclose/_pclose`.
- **Performance notes:** External process cost dominated by ffmpeg work.
- **Threading notes:** Uses shared global path; otherwise local state.
- **Agent modification guidance:** Keep optional-audio map (`-map 1:a:0?`) behavior unless requirements change.
- **Related symbols:** `open_ffmpeg`, `rotate_90`.

### Function `rotate_90`
- **Signature:** `void rotate_90(const char *output, const char *src)`
- **Location:** `source/macos-static/ffmpeg_write.cpp:164-183`
- **Belongs to:** Global namespace.
- **Purpose:** Invokes ffmpeg metadata update to mark output rotated 90 degrees.
- **Inputs:** Source file and destination file path.
- **Outputs / Return value:** None.
- **Side effects:** Spawns ffmpeg command; writes console output.
- **Preconditions:** Input media exists; ffmpeg supports metadata edit path.
- **Postconditions:** Destination file written with rotation metadata.
- **Error handling / failure modes:** Logs and returns on popen failure.
- **Called by (best-effort):** Post-process orientation adjustment path.
- **Calls into (best-effort):** `popen/_popen`, `pclose/_pclose`.
- **Performance notes:** External command time proportional to media/container operations.
- **Threading notes:** Independent call but global path shared.
- **Agent modification guidance:** Keep quoting around paths to avoid shell breakage.
- **Related symbols:** `mux_audio`.
