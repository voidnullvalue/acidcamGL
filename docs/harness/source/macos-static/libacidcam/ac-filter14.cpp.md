# Harness Doc: `source/macos-static/libacidcam/ac-filter14.cpp`

## File-level
- **File path:** `source/macos-static/libacidcam/ac-filter14.cpp`
- **Purpose of file:** Implements libacidcam filter/effect routines compiled into the macOS-static build.
- **Dependencies/includes/imports:** `#include "ac.h"`
- **Key classes/structs/types/globals/macros:** Namespace `ac` filters, file-scope counters/state, and OpenCV frame types.
- **External resources touched:** In-memory OpenCV frame buffers (`cv::Mat`), global filter state, and random-number helpers.
- **Build role:** One translation unit in `source/macos-static/libacidcam` filter library.
- **Risks/footguns:** High arithmetic intensity per frame, channel overflow/wrap behavior, and shared mutable state assumptions across filters.

## Functions / Methods

### `MirrorAlphaBlend`
- **Signature:** `MirrorAlphaBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:47-58`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `BlendWithSource`, `DarkenFilter`, `MirrorBitwiseXor`, `MirrorXorAll`, `ac::MirrorAlphaBlend`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageSmoothMedianBlend`
- **Signature:** `ImageSmoothMedianBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:59-71`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `DarkenFilter`, `MedianBlend`, `SmoothSubFilter32`, `ac::ImageSmoothMedianBlend`, `getFilterByName`, `popSubFilter`, `pushSubFilter`, `rainbowBlend`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageSmoothMedianSubFilter`
- **Signature:** `ImageSmoothMedianSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:72-87`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `DarkenFilter`, `MedianBlend`, `SmoothSubFilter32`, `ac::ImageSmoothMedianSubFilter`, `clone`, `getFilterByName`, `popSubFilter`, `pushSubFilter`, `rainbowBlend`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageAlphaXorMedianBlend`
- **Signature:** `ImageAlphaXorMedianBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:88-102`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaXorBlend`, `ImageSmoothMedianBlend`, `SmoothImageAlphaBlend`, `ac::ImageAlphaXorMedianBlend`, `ac_resize`, `clone`, `procPos`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionBlend`
- **Signature:** `MatrixCollectionBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:103-115`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlur`, `ShuffleAlpha`, `Smooth`, `ac::MatrixCollectionBlend`, `clone`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionSubFilter`
- **Signature:** `MatrixCollectionSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:116-129`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `Smooth`, `ac::MatrixCollectionSubFilter`, `clone`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionImageSubFilter`
- **Signature:** `MatrixCollectionImageSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:130-144`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlend`, `Smooth`, `ac::MatrixCollectionImageSubFilter`, `ac_resize`, `clone`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionBlurAlpha`
- **Signature:** `MatrixCollectionBlurAlpha(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:145-168`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlend`, `Smooth`, `ac::MatrixCollectionBlurAlpha`, `clone`, `pixelAt`, `procPos`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionXor`
- **Signature:** `MatrixCollectionXor(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:169-190`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::MatrixCollectionXor`, `pixelAt`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionXor32`
- **Signature:** `MatrixCollectionXor32(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:191-212`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::MatrixCollectionXor32`, `pixelAt`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionRandomColorMap`
- **Signature:** `MatrixCollectionRandomColorMap(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:213-236`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `RandomColorMap`, `ac::MatrixCollectionRandomColorMap`, `clone`, `pixelAt`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionDarkXor`
- **Signature:** `MatrixCollectionDarkXor(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:237-259`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::MatrixCollectionDarkXor`, `pixelAt`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixCollectionRGB`
- **Signature:** `MatrixCollectionRGB(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:260-297`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AllBlue`, `AllGreen`, `AllRed`, `ac::MatrixCollectionRGB`, `clone`, `pixelAt`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `TrailsSubFilter`
- **Signature:** `TrailsSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:298-320`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `MatrixCollectionXor`, `ac::TrailsSubFilter`, `clone`, `colorBounds`, `hv`, `lv`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `TrailsSubFilter32`
- **Signature:** `TrailsSubFilter32(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:321-342`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `MatrixCollectionXor32`, `ac::TrailsSubFilter32`, `clone`, `colorBounds`, `hv`, `lv`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `CompareWithSubFilter`
- **Signature:** `CompareWithSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:343-363`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::CompareWithSubFilter`, `clone`, `colorBounds`, `hv`, `lv`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MedianTrails`
- **Signature:** `MedianTrails(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:364-373`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MedianBlend`, `TrailsSubFilter`, `ac::MedianTrails`, `clone`, `getFilterByName`, `popSubFilter`, `pushSubFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SmoothMedianBlend`
- **Signature:** `SmoothMedianBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:374-381`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlend`, `SmoothSubFilter`, `ac::SmoothMedianBlend`, `getFilterByName`, `popSubFilter`, `pushSubFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorTransition`
- **Signature:** `ColorTransition(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:382-415`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::ColorTransition`, `pixelAt`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorTransitionMedian`
- **Signature:** `ColorTransitionMedian(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:416-421`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ColorTransition`, `MedianBlend`, `ac::ColorTransitionMedian`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorTransitionRandom`
- **Signature:** `ColorTransitionRandom(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:422-455`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::ColorTransitionRandom`, `pixelAt`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorTransitionRandomMedian`
- **Signature:** `ColorTransitionRandomMedian(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:456-461`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ColorTransitionRandom`, `MedianBlend`, `ac::ColorTransitionRandomMedian`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorTransitionSubFilter`
- **Signature:** `ColorTransitionSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:462-473`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `ColorTransitionRandomMedian`, `MedianBlend`, `ac::ColorTransitionSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorTransitionImageSubFilter`
- **Signature:** `ColorTransitionImageSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:474-484`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `ac::ColorTransitionImageSubFilter`, `ac_resize`, `clone`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `CurtainSubFilter`
- **Signature:** `CurtainSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:485-530`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::CurtainSubFilter`, `clone`, `pixelAt`, `procPos`, `testSize`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomTrails`
- **Signature:** `RandomTrails(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:531-537`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `TrailsSubFilter`, `ac::RandomTrails`, `getFilterByName`, `popSubFilter`, `pushSubFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomTrailsSubFilter`
- **Signature:** `RandomTrailsSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:538-549`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `TrailsSubFilter`, `ac::RandomTrailsSubFilter`, `clone`, `getFilterByName`, `popSubFilter`, `pushSubFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `CosSinMedianBlend`
- **Signature:** `CosSinMedianBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:550-557`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlend`, `SmoothSubFilter`, `ac::CosSinMedianBlend`, `getFilterByName`, `popSubFilter`, `pushSubFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `TrailsRGB`
- **Signature:** `TrailsRGB(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:558-577`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MatrixTrailsXorRandom`, `StrobeXor`, `ac::TrailsRGB`, `clone`, `colorBounds`, `hv`, `lv`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MatrixTrailsXorRandom`
- **Signature:** `MatrixTrailsXorRandom(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:578-606`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::MatrixTrailsXorRandom`, `pixelAt`, `rand`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `CosSinMultiplyCollectionXor`
- **Signature:** `CosSinMultiplyCollectionXor(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:607-615`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MatrixCollectionXor`, `MedianBlend`, `ac::CosSinMultiplyCollectionXor`, `clone`, `cossinMultiply`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Filter8_Blend`
- **Signature:** `Filter8_Blend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:616-625`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MedianBlend`, `Smooth`, `ac::Filter8_Blend`, `clone`, `filter8`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Filter8_SubFilter`
- **Signature:** `Filter8_SubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:626-636`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlend`, `ac::Filter8_SubFilter`, `clone`, `filter8`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomSmoothAlphaMedian`
- **Signature:** `RandomSmoothAlphaMedian(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:637-646`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MedianBlend`, `Smooth`, `ac::RandomSmoothAlphaMedian`, `clone`, `randomFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomAlphaBlendFilter`
- **Signature:** `RandomAlphaBlendFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:647-660`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MedianBlend`, `Smooth`, `ac::RandomAlphaBlendFilter`, `clone`, `randomFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomMirrorBitwiseXor`
- **Signature:** `RandomMirrorBitwiseXor(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:661-671`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MedianBlend`, `MirrorBitwiseXor`, `Smooth`, `ac::RandomMirrorBitwiseXor`, `clone`, `randomFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SquareDivideSubFilter`
- **Signature:** `SquareDivideSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:672-699`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `ac::SquareDivideSubFilter`, `ac_resize`, `clone`, `copyMat`, `cv::Size`, `randomFilter`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SquareSubFilter`
- **Signature:** `SquareSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:700-722`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::SquareSubFilter`, `ac_resize`, `copyMat`, `cv::Size`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SquareSubFilter8`
- **Signature:** `SquareSubFilter8(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:723-746`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::SquareSubFilter8`, `ac_resize`, `copyMat`, `cv::Size`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorExpand`
- **Signature:** `ColorExpand(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:747-797`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::ColorExpand`, `pixelAt`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorExpandSubFilter`
- **Signature:** `ColorExpandSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:798-823`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ColorExpand`, `ac::ColorExpandSubFilter`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RotateImage`
- **Signature:** `RotateImage(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:824-837`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::RotateImage`, `ac_resize`, `clone`, `cv::flip`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RotateBlendImage`
- **Signature:** `RotateBlendImage(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:838-844`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `RotateImage`, `ac::RotateBlendImage`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RotateImageSubFilter`
- **Signature:** `RotateImageSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:845-855`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `RotateBlendImage`, `ac::RotateImageSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RotateAlphaBlendImage`
- **Signature:** `RotateAlphaBlendImage(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:856-867`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `RotateImage`, `ac::RotateAlphaBlendImage`, `clone`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipShuffle`
- **Signature:** `FlipShuffle(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:868-881`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::FlipShuffle`, `begin`, `clone`, `count`, `cv::flip`, `end`, `size`, `std::chrono::system_clock::now`, `std::default_random_engine`, `std::shuffle`, `time_since_epoch`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipRandom`
- **Signature:** `FlipRandom(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:882-889`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::FlipRandom`, `clone`, `cv::flip`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipOrder`
- **Signature:** `FlipOrder(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:890-899`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::FlipOrder`, `clone`, `cv::flip`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipStrobeSubFilter`
- **Signature:** `FlipStrobeSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:900-915`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `FlipOrder`, `Negate`, `ac::FlipStrobeSubFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorBlendFrame`
- **Signature:** `MirrorBlendFrame(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:916-922`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `ac::MirrorBlendFrame`, `clone`, `cv::flip`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorBlendVertical`
- **Signature:** `MirrorBlendVertical(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:923-929`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `ac::MirrorBlendVertical`, `clone`, `cv::flip`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorVerticalAndHorizontal`
- **Signature:** `MirrorVerticalAndHorizontal(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:930-937`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MirrorBlendFrame`, `MirrorBlendVertical`, `ac::MirrorVerticalAndHorizontal`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlendFor360`
- **Signature:** `BlendFor360(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:938-974`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::BlendFor360`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorSidesMedian`
- **Signature:** `MirrorSidesMedian(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:975-981`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlend`, `MirrorVerticalAndHorizontal`, `MirrorXorAll`, `ac::MirrorSidesMedian`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorSidesSubFilter`
- **Signature:** `MirrorSidesSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:982-993`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlend`, `MirrorVerticalAndHorizontal`, `MirrorXorAll`, `ac::MirrorSidesSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MedianFrameAlphaBlendSubFilter`
- **Signature:** `MedianFrameAlphaBlendSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:994-1003`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlend`, `ac::MedianFrameAlphaBlendSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MedianSubFilter`
- **Signature:** `MedianSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:1004-1020`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlend`, `Smooth`, `ac::MedianSubFilter`, `clone`, `randomFilter`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorXorScale`
- **Signature:** `ColorXorScale(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:1021-1050`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::ColorXorScale`, `pixelAt`, `procPos`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ColorXorScaleSubFilter`
- **Signature:** `ColorXorScaleSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter14.cpp:1051-1059`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `ColorXorScale`, `ac::ColorXorScaleSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

