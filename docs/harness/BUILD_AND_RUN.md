# Build and Run (High-Level Harness)

Inferred from project build scripts and top-level build configuration.

## Build Systems Present

- **Primary:** CMake (root `CMakeLists.txt`) for `acidcamGL` executable.
- **Secondary:** GNU Make variants in `source/`:
  - `Makefile.linux` (Linux build)
  - `Makefile.midi.linux` (Linux + MIDI/Reactive)
  - `Makefile.midi` (macOS-style MIDI/Reactive build)
- **Additional projects:**
  - `launcher.gui/CMakeLists.txt` (Qt launcher)
  - `midi-cfg/Makefile` (+ Qt `.pro` files)
  - many per-plugin Makefiles in `source/plugin/*`.

## Core Dependency Signals (from build files)

### Required for main CMake build

- C++11 compiler
- `pkg-config`
- OpenGL (`find_package(OpenGL)`)
- Threads
- `opencv4` (pkg-config)
- `glfw3` (pkg-config)
- `acidcam` library (pkg-config; external dependency)
- GLAD source included in-tree (`source/src/glad.c`)

### Optional/toggled in CMake

- `ENABLE_MIDI` (default ON) -> requires `rtmidi`
- `ENABLE_REACTIVE` (default ON) -> requires `rtaudio`

> Practical note: default CMake options require both RtMidi and RtAudio unless explicitly disabled.

### Other visible runtime/tool dependencies

- ffmpeg executable path/runtime use for encoding/mux path.
- Qt5/Qt6 + Threads for launcher GUI.
- X11 linkage in Linux Makefile path for desktop capture-oriented variant.

## Platform Assumptions (inferred)

- **Linux:**
  - CMake and legacy Makefile paths available.
  - Some capture paths likely assume Xorg/X11 (not Wayland) in legacy Makefile flow.
- **macOS:**
  - CMake supported; additional static build path under `source/macos-static`.
  - Syphon-related files indicate optional macOS visual routing integration.
- **Windows:**
  - Visual Studio support directories exist; root CMake has Windows linker/static flags and `NO_SCREEN_GRAB` define.
  - Plugin dynamic loading code shown is non-Windows specific, so Windows plugin handling may differ (needs verification).

## Probable Build Paths

### Path A: Root CMake (recommended modern path)

```bash
mkdir -p build
cd build
cmake ..
cmake --build . -j
```

Optional feature toggles if MIDI/audio libs are missing:

```bash
cmake .. -DENABLE_MIDI=OFF -DENABLE_REACTIVE=OFF
```

Install target exists:

```bash
cmake --install .
```

### Path B: Legacy Linux Makefile (source/)

```bash
cd source
make -f Makefile.linux
sudo make -f Makefile.linux install
```

MIDI/reactive variant:

```bash
make -f Makefile.midi.linux
sudo make -f Makefile.midi.linux install
```

### Path C: Launcher GUI

```bash
cd launcher.gui
mkdir -p build
cd build
cmake ..
cmake --build . -j
```

Produces launcher target installed as `launcher` binary.

## Probable Runtime Invocation Notes

- Main app runtime expects shader directory path either via:
  - `SHADER_PATH` env var, or
  - CLI path option (`-p`).
- Common runtime modes visible in CLI/help and README:
  - camera capture (`-d`),
  - input file (`-i`),
  - screen mode (`-G`),
  - playlist/autofilter/custom/plugin loading via dedicated flags.
- MIDI runtime expects `AC_MIDI` env path on non-Windows builds when MIDI enabled.

## Needs Verification in later pass

- Exact binary names across each build path and platform package layout.
- Which scripts are current vs historical (`scripts/build_project.sh` references upstream clone workflow).
- End-to-end plugin install/load locations by OS.
