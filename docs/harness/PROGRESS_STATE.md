# Harness Progress State

- Total batches: **84**
- Completed batches: **1** (`BATCH_001`)
- Next batch ID: **BATCH_002**
- Total files documented (running): **8**
- Total functions/methods documented (running, best-effort): **42**

## Batch processed this run
- Batch ID: `BATCH_001`
- Files processed:
  - `source/acidcam_window.cpp`
  - `source/autofilter.hpp`
  - `source/ffmpeg_write.cpp`
  - `source/ffmpeg_write.h`
  - `source/gl_shader.cpp`
  - `source/gl_shader.hpp`
  - `source/gl_window.cpp`
  - `source/gl_window.hpp`
- Notes: Batch size kept at 8 (small/safe default for GL-heavy codebase).

## Skipped / deferred files
- Deferred low-priority trees (997 files):
  - `vendor/`, `third_party/`, `external/`, `build/`, `dist/`, `generated/`
  - `source/acidcamGL-Visual.Studio/`, `source/glm/`, `source/macos/include/`, `source/macos-static/Syphon.framework/`
- Reason: third-party/generated/platform-bundled trees are currently marked low-priority for harness coverage.

## Remaining work
- Remaining batches: **83**
- Remaining active files (best-effort): **547**
