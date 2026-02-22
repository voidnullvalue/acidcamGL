# Harness Doc: `source/ffmpeg_write.cpp`

## File-level
- **File path:** `source/ffmpeg_write.cpp`
- **Purpose of file:** Implements ffmpeg command construction and process piping for video encoding and post-processing.
- **Dependencies/includes/imports:** `ffmpeg_write.h`, `ipc_client.hpp`, platform headers (`mach-o/dyld.h`, `unistd.h`, etc.).
- **Key classes/structs/types/globals/macros:** globals `ffmpeg_path`, `buffer`, `file`, `stdout_save`.
- **External resources touched:** ffmpeg executable, subprocess stdio pipes, filesystem video/audio files.
- **Build role:** Recording/output backend utility.
- **Risks/footguns:** shell command composition with string interpolation; error handling mostly via console messages.

## Functions

### `open_ffmpeg`
- **Signature:** `FILE *open_ffmpeg(const char *output, const char *codec, const char *res, const char *dst_res, const char *fps, const char *crf)`
- **Location:** `source/ffmpeg_write.cpp:28-108`
- **Belongs to:** free function
- **Purpose:** Build ffmpeg command for raw-frame stdin ingest and launch encoder process.
- **Inputs:** output file, codec, source/destination resolution, frame rate, quality/CRF parameter.
- **Outputs / Return value:** writable process handle (`FILE*`) or `0` on failure.
- **Side effects:** may update global `ffmpeg_path` (Apple path logic); starts child process via `popen/_popen`; logs full command.
- **Preconditions:** ffmpeg binary accessible; parameters valid for selected codec.
- **Postconditions:** returned pipe ready for `write_ffmpeg` when successful.
- **Error handling / failure modes:** returns 0 if process launch fails; codec-specific options may still fail at runtime in ffmpeg.
- **Called by (best-effort):** recording pipeline setup.
- **Calls into (best-effort):** `popen/_popen`, platform path APIs.
- **Performance notes:** startup-only cost; subprocess encoding cost dominates runtime.
- **Threading notes:** global `ffmpeg_path` mutation is unsynchronized.
- **Agent modification guidance:** maintain codec option table carefully; regressions here break hardware encode paths.
- **Related symbols:** `write_ffmpeg`, `mux_audio`, `rotate_90`.

### `list_devices`
- **Signature:** `void list_devices()`
- **Location:** `source/ffmpeg_write.cpp:112-127`
- **Belongs to:** free function
- **Purpose:** On Apple, invoke ffmpeg avfoundation device-list command and print output.
- **Inputs:** none.
- **Outputs:** none.
- **Side effects:** starts read pipe process, prints to stdout, may `exit(0)` on failure.
- **Preconditions:** Apple build/runtime; ffmpeg present.
- **Postconditions:** device lines printed.
- **Error handling / failure modes:** if pipe fails, prints error and exits process.
- **Called by:** diagnostics/UI path (best-effort).
- **Calls into:** `popen`, `fgets`, `pclose`.
- **Performance notes:** one-off diagnostic.
- **Threading notes:** process I/O; avoid concurrent stdout interleaving.
- **Agent modification guidance:** note platform guard (`#ifdef __APPLE__`).
- **Related symbols:** global `ffmpeg_path`.

### `write_ffmpeg`
- **Signature:** `void write_ffmpeg(FILE *fptr, cv::Mat &frame)`
- **Location:** `source/ffmpeg_write.cpp:129-131`
- **Belongs to:** free function
- **Purpose:** Write raw frame bytes to ffmpeg stdin stream.
- **Inputs:** opened ffmpeg stream and OpenCV frame.
- **Outputs:** none.
- **Side effects:** writes binary data to pipe.
- **Preconditions:** `fptr` valid/open; frame contiguous format expected by ffmpeg command (`bgr24`).
- **Postconditions:** frame bytes enqueued for encoding.
- **Error handling:** return value from `fwrite` ignored.
- **Called by:** per-frame recording loop.
- **Calls into:** `fwrite`.
- **Performance notes:** frame-size linear I/O.
- **Threading notes:** serial writes required per process stream.
- **Agent modification guidance:** adding write-result checks would improve robustness.
- **Related symbols:** `open_ffmpeg`.

### `close_stdout`
- **Signature:** `void close_stdout()`
- **Location:** `source/ffmpeg_write.cpp:133-135`
- **Belongs to:** free function
- **Purpose:** Currently no-op placeholder.
- **Inputs/Outputs/Side effects:** none.
- **Preconditions/Postconditions:** none.
- **Error handling:** none.
- **Called by:** unknown.
- **Calls into:** none.
- **Performance notes:** trivial.
- **Threading notes:** trivial.
- **Agent modification guidance:** safe hook for future output redirection logic.
- **Related symbols:** `stdout_save` global (currently unused in visible snippet).

### `mux_audio`
- **Signature:** `void mux_audio(const char *output, const char *src, const char *final_file)`
- **Location:** `source/ffmpeg_write.cpp:137-155`
- **Belongs to:** free function
- **Purpose:** Run ffmpeg command to combine encoded video and source audio stream.
- **Inputs:** intermediate output video, source media, destination file.
- **Outputs:** none.
- **Side effects:** launches ffmpeg process; writes destination file.
- **Preconditions:** input files exist.
- **Postconditions:** final muxed file attempted.
- **Error handling / failure modes:** logs and returns on popen failure; command-level failures not parsed.
- **Called by:** post-record finalization path.
- **Calls into:** `popen/_popen`, `pclose/_pclose`.
- **Performance notes:** potentially expensive external process.
- **Threading notes:** subprocess invocation is process-wide side effect.
- **Agent modification guidance:** keep `-map 1:a:0?` optional audio behavior intact.
- **Related symbols:** `open_ffmpeg`, `rotate_90`.

### `rotate_90`
- **Signature:** `void rotate_90(const char *output, const char *src)`
- **Location:** `source/ffmpeg_write.cpp:157-176`
- **Belongs to:** free function
- **Purpose:** Write output with rotation metadata set to 90 degrees.
- **Inputs:** source output, destination file path.
- **Outputs:** none.
- **Side effects:** subprocess call and destination file write.
- **Preconditions:** input file accessible.
- **Postconditions:** transformed file attempted.
- **Error handling:** same pattern as `mux_audio`.
- **Called by:** post-processing flow (best-effort).
- **Calls into:** `popen/_popen`, `pclose/_pclose`.
- **Performance notes:** external process bound.
- **Threading notes:** subprocess side effects.
- **Agent modification guidance:** metadata-only rotation may not rewrite frames; behavior depends on player support.
- **Related symbols:** `mux_audio`.
