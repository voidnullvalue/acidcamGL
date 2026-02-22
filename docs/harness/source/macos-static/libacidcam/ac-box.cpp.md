# Harness Doc: `source/macos-static/libacidcam/ac-box.cpp`

## File-level
- **File path:** `source/macos-static/libacidcam/ac-box.cpp`
- **Purpose of file:** Implements libacidcam filter/effect routines compiled into the macOS-static build.
- **Dependencies/includes/imports:** `#include"ac.h"`
- **Key classes/structs/types/globals/macros:** Namespace `ac` filters, file-scope counters/state, and OpenCV frame types.
- **External resources touched:** In-memory OpenCV frame buffers (`cv::Mat`), global filter state, and random-number helpers.
- **Build role:** One translation unit in `source/macos-static/libacidcam` filter library.
- **Risks/footguns:** High arithmetic intensity per frame, channel overflow/wrap behavior, and shared mutable state assumptions across filters.

## Functions / Methods

### `initBox`
- **Signature:** `initBox(int width,int height)`
- **Location:** `source/macos-static/libacidcam/ac-box.cpp:49-60`
- **Belongs to:** `ac::Box`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::Box::initBox`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `drawBox`
- **Signature:** `drawBox(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-box.cpp:61-81`
- **Belongs to:** `ac::Box`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `CallFilter`, `ac::Box::drawBox`, `create`, `cv::Size`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `sizeBox`
- **Signature:** `sizeBox()`
- **Location:** `source/macos-static/libacidcam/ac-box.cpp:82-103`
- **Belongs to:** `ac::Box`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::Box::sizeBox`, `initBox`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

