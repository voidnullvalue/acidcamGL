# Harness Doc: `source/acidcam_window.cpp`

## File-level
- **File path:** `source/acidcam_window.cpp`
- **Purpose of file:** Defines global capture/screen-capture objects declared for shared runtime use.
- **Dependencies/includes/imports:** `acidcam_window.hpp`; OpenCV types via included header.
- **Key classes/structs/types/globals/macros:** global `cv::VideoCapture cap`, `cv::VideoCapture cap_second`; conditional global `ScreenShot *screen_shot` behind `FOR_LINUX`.
- **External resources touched:** Camera/video device handles through OpenCV globals.
- **Build role:** Translation unit that provides storage for globals referenced from other runtime code.
- **Risks/footguns:** Global mutable state; lifetime and synchronization are managed elsewhere.

## Symbols

### Global `cv::VideoCapture cap`
- **Signature:** `cv::VideoCapture cap`
- **Location:** `source/acidcam_window.cpp:5`
- **Belongs to:** namespace `acidcam` (global variable)
- **Purpose:** Primary capture device/input handle shared by runtime.
- **Inputs:** N/A
- **Outputs / Return value:** N/A
- **Side effects:** Opens/closes OS/media resources when used.
- **Preconditions:** Must be initialized/opened before frame reads.
- **Postconditions:** State reflects capture backend open/closed state.
- **Error handling / failure modes:** Failures are handled by call sites; this file only defines storage.
- **Called by (best-effort):** N/A (data symbol)
- **Calls into (best-effort):** N/A
- **Performance notes:** Backend-dependent I/O costs.
- **Threading notes:** Not inherently thread-safe for concurrent mutation.
- **Agent modification guidance:** Keep as single definition; avoid duplicate-definition ODR issues.
- **Related symbols:** `cap_second`, `screen_shot`.

### Global `cv::VideoCapture cap_second`
- **Signature:** `cv::VideoCapture cap_second`
- **Location:** `source/acidcam_window.cpp:5`
- **Belongs to:** namespace `acidcam` (global variable)
- **Purpose:** Secondary capture handle (e.g., stereo/dual-source paths).
- **Inputs / Outputs / Side effects:** Same behavior class as `cap`.
- **Preconditions/Postconditions:** Same as `cap`.
- **Error handling / failure modes:** Delegated to call sites.
- **Called by / Calls into:** N/A
- **Performance notes:** Backend-dependent I/O costs.
- **Threading notes:** Shared mutable state.
- **Agent modification guidance:** Preserve single-definition semantics.
- **Related symbols:** `cap`.

### Global `ScreenShot *screen_shot` (conditional)
- **Signature:** `ScreenShot *screen_shot = nullptr`
- **Location:** `source/acidcam_window.cpp:8` (`#ifdef FOR_LINUX`)
- **Belongs to:** namespace `acidcam` (global pointer)
- **Purpose:** Stores Linux screen-capture helper instance pointer.
- **Inputs:** N/A
- **Outputs / Return value:** N/A
- **Side effects:** Enables deferred allocation and global access pattern.
- **Preconditions:** Compiled with `FOR_LINUX`; pointer must be assigned before dereference.
- **Postconditions:** Remains null unless initialized by runtime code.
- **Error handling / failure modes:** Null dereference risk if unchecked.
- **Called by / Calls into:** N/A
- **Performance notes:** Pointer indirection only.
- **Threading notes:** Shared pointer state; synchronize if accessed cross-thread.
- **Agent modification guidance:** Keep compile guards aligned with platform code.
- **Related symbols:** `FOR_LINUX`.
