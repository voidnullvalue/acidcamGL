# Harness Doc: `source/ffmpeg_write.h`

## File-level
- **File path:** `source/ffmpeg_write.h`
- **Purpose of file:** Declares ffmpeg process helpers for writing raw frames and post-processing output media.
- **Dependencies/includes/imports:** OpenCV `cv::Mat`, C stdio handle type via `FILE`.
- **Key classes/structs/types/globals/macros:** global `ffmpeg_path`; free helper functions.
- **External resources touched:** ffmpeg executable via subprocess, filesystem media files.
- **Build role:** Interface for recording/output support code.
- **Risks/footguns:** Uses shell command strings; caller-provided paths/options must be trusted/sanitized.

## Symbols

### `open_ffmpeg`
- **Signature:** `FILE *open_ffmpeg(const char *output, const char *codec, const char *res, const char *dst_res, const char *fps, const char *crf)`
- **Location:** `source/ffmpeg_write.h:12`
- **Belongs to:** free function
- **Purpose:** Start ffmpeg process accepting raw BGR frames on stdin.

### `write_ffmpeg`
- **Signature:** `void write_ffmpeg(FILE *fptr, cv::Mat &frame)`
- **Location:** `source/ffmpeg_write.h:13`
- **Belongs to:** free function
- **Purpose:** Push one frame to ffmpeg stdin.

### `mux_audio`
- **Signature:** `void mux_audio(const char *output, const char *src, const char *final_file)`
- **Location:** `source/ffmpeg_write.h:14`
- **Belongs to:** free function
- **Purpose:** Mux video output with source audio track.

### `rotate_90`
- **Signature:** `void rotate_90(const char *output, const char *src)`
- **Location:** `source/ffmpeg_write.h:15`
- **Belongs to:** free function
- **Purpose:** Apply rotation metadata to output video.

### `close_stdout`, `list_devices`
- **Signature:** `void close_stdout()`, `void list_devices()`
- **Location:** `source/ffmpeg_write.h:16-17`
- **Belongs to:** free functions
- **Purpose:** Placeholder stdout control and Apple device listing utility.
