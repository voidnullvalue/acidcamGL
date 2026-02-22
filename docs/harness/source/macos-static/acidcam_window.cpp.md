# Harness Doc: `source/macos-static/acidcam_window.cpp`

## File-level
- **File path:** `source/macos-static/acidcam_window.cpp`
- **Purpose of file:** Defines global capture/screen-capture objects for macOS-static build variant.
- **Dependencies/includes/imports:** `acidcam_window.hpp` (brings OpenCV/screenshot types).
- **Key classes/structs/types/globals/macros:** global `cv::VideoCapture cap`, `cap_second`; conditional `ScreenShot *screen_shot` under `FOR_LINUX`.
- **External resources touched:** Camera/video handles managed through OpenCV globals.
- **Build role:** Translation unit providing global storage definitions.
- **Risks/footguns:** Global mutable state and possible cross-thread access races.

## Symbols

### Global `cv::VideoCapture cap`
- **Signature:** `cv::VideoCapture cap`
- **Location:** `source/macos-static/acidcam_window.cpp:5`
- **Belongs to:** namespace `acidcam`.
- **Purpose:** Primary capture handle.
- **Inputs / Outputs / Return value:** N/A.
- **Side effects:** Runtime use opens/closes capture backend resources.
- **Preconditions:** Must be opened before frame reads.
- **Postconditions:** Represents capture state.
- **Error handling / failure modes:** Managed by users of the global.
- **Called by / Calls into (best-effort):** N/A (data symbol).
- **Performance notes:** Backend dependent.
- **Threading notes:** Shared mutable global.
- **Agent modification guidance:** Keep single definition to avoid ODR/linker errors.
- **Related symbols:** `cap_second`, `screen_shot`.

### Global `cv::VideoCapture cap_second`
- **Signature:** `cv::VideoCapture cap_second`
- **Location:** `source/macos-static/acidcam_window.cpp:5`
- **Belongs to:** namespace `acidcam`.
- **Purpose:** Secondary capture handle for dual-input paths.
- **Inputs / Outputs / Return value:** N/A.
- **Side effects:** Same class of media-resource side effects as `cap`.
- **Preconditions/Postconditions:** Same as `cap`.
- **Error handling / failure modes:** Caller-managed.
- **Called by / Calls into (best-effort):** N/A.
- **Performance notes:** Backend dependent.
- **Threading notes:** Shared mutable global.
- **Agent modification guidance:** Preserve exported symbol name.
- **Related symbols:** `cap`.

### Global `ScreenShot *screen_shot` (conditional)
- **Signature:** `ScreenShot *screen_shot = nullptr`
- **Location:** `source/macos-static/acidcam_window.cpp:8`
- **Belongs to:** namespace `acidcam` under `#ifdef FOR_LINUX`.
- **Purpose:** Optional global screen-capture helper pointer.
- **Inputs / Outputs / Return value:** N/A.
- **Side effects:** Enables lazily assigned global capture helper.
- **Preconditions:** `FOR_LINUX` build and non-null assignment before use.
- **Postconditions:** Defaults to null.
- **Error handling / failure modes:** Null dereference risk if unchecked.
- **Called by / Calls into (best-effort):** N/A.
- **Performance notes:** Pointer indirection only.
- **Threading notes:** Shared pointer state should be synchronized.
- **Agent modification guidance:** Keep compile guard aligned with platform code.
- **Related symbols:** `FOR_LINUX`.
