# File Map (High-Level Harness)

This pass captures **repo-level structure only** (no per-file API/function docs yet).

## Top-Level Areas

- `source/` — core C++ application sources for `acidcamGL`, platform variants, bundled headers, and plugin SDK/examples. Primary runtime code appears to live in `source/main.cpp`, `source/acidcam_window.*`, and `source/gl_window.*`.
- `filters/` — large GLSL shader library (`*.glsl`) and `index.txt`-driven shader selection list.
- `plugin/` and `source/plugin/` — dynamic filter/plugin ecosystem:
  - `plugin/` (repo root): index/readme and likely installed plugin artifacts list.
  - `source/plugin/`: many plugin subprojects, each with a `Makefile`, likely building shared objects loaded at runtime.
- `autofilter/`, `playlist/`, `shortcut/`, `custom/` — runtime data/config inputs (automation sequences, playlists, key maps, custom filter recipes).
- `launcher.gui/` — Qt launcher application (`acidcamGL_launcher`) with its own CMake project.
- `midi-cfg/` — MIDI config utility and Qt project files for controller mapping generation.
- `tools/` — small support binaries (camera info, RtAudio device listing).
- `scripts/` — dependency/bootstrap scripts for macOS/Ubuntu and helper build scripts.
- `docs/harness/` — this harness documentation set.
- `source/macos-static/`, `source/macos/`, `source/acidcamGL-Visual.Studio/`, `deb/` — platform packaging/build support (macOS static app workflow, Visual Studio tree, Debian package layout).

## Probable Vendor / Third-Party / Generated Content

> Marked as **probable** where ownership is not explicitly stated.

- `source/include/glad/` + `source/src/glad.c` — GLAD OpenGL loader (probable generated third-party).
- `source/glm/` and `source/acidcamGL-Visual.Studio/glm/` — GLM math library copy (probable vendored third-party).
- `source/macos-static/Syphon.framework/` — third-party framework bundle (probable vendored binary/framework artifact).
- `launcher.gui/build/` — CMake-generated build output (generated artifacts; not source-of-truth docs).

## Asset / Shader / Runtime Data Directories

- `filters/` — shader corpus used by runtime shader loader; `README.md` indicates `index.txt` controls load order.
- `autofilter/` (`*.af`) — scripted auto-filter sequences loaded via `-A` option.
- `playlist/` (`*.key`, `playlist-example.txt`) — filter sequencing/playlist files loaded via runtime playlist options.
- `shortcut/` (`*.key`) — keyboard shortcut mapping inputs.
- `custom/` + `custom/index.txt` — custom filter chain definitions consumed by `loadCustom` path.
- `plugin/` + `source/plugin/*` — runtime extension filters loaded from shared libraries via plugin loader (`dlopen` path in core code).
- `screens/`, `manual/`, `launcher.gui/images/` — documentation/UI media assets, not core processing pipeline.

## Scope Notes for Next Passes

- Per-file harness generation should prioritize:
  1. `source/` core runtime files.
  2. `launcher.gui/` and `midi-cfg/` tooling apps.
  3. `source/plugin/*` families (very large volume; batch needed).
- `filters/*.glsl` likely require a separate shader-oriented doc strategy due to volume.
