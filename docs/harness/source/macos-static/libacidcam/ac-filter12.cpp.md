# Harness Doc: `source/macos-static/libacidcam/ac-filter12.cpp`

## File-level
- **File path:** `source/macos-static/libacidcam/ac-filter12.cpp`
- **Purpose of file:** Implements libacidcam filter/effect routines compiled into the macOS-static build.
- **Dependencies/includes/imports:** `#include "ac.h"`
- **Key classes/structs/types/globals/macros:** Namespace `ac` filters, file-scope counters/state, and OpenCV frame types.
- **External resources touched:** In-memory OpenCV frame buffers (`cv::Mat`), global filter state, and random-number helpers.
- **Build role:** One translation unit in `source/macos-static/libacidcam` filter library.
- **Risks/footguns:** High arithmetic intensity per frame, channel overflow/wrap behavior, and shared mutable state assumptions across filters.

## Functions / Methods

### `BlendReverseSubFilter`
- **Signature:** `BlendReverseSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:46-99`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `Reverse`, `ac::BlendReverseSubFilter`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorBitwiseXor`
- **Signature:** `MirrorBitwiseXor(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:100-120`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `DarkenFilter`, `FlipBlendAll`, `MedianBlend`, `MirrorXorAll`, `ac::MirrorBitwiseXor`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SmoothBlendReverseSubFilter`
- **Signature:** `SmoothBlendReverseSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:121-137`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `BlendReverseSubFilter`, `CallFilter`, `Smooth`, `ac::SmoothBlendReverseSubFilter`, `clone`, `procPos`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomIncrease`
- **Signature:** `RandomIncrease(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:138-153`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::RandomIncrease`, `pixelAt`, `rand`, `size_reset`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MedianBlend16`
- **Signature:** `MedianBlend16(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:154-183`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `MedianBlur`, `ac::MedianBlend16`, `invert`, `pixelAt`, `procPos`, `rand`, `shiftFrames`, `size`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MedianBlendBufferSubFilter`
- **Signature:** `MedianBlendBufferSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:184-223`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `CallFilter`, `MedianBlur`, `ac::MedianBlendBufferSubFilter`, `clone`, `invert`, `pixelAt`, `procPos`, `shiftFrames`, `size`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BGRBlend`
- **Signature:** `BGRBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:224-247`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlur`, `ac::BGRBlend`, `pixelAt`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RGBBlend`
- **Signature:** `RGBBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:248-273`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlur`, `ac::RGBBlend`, `clone`, `pixelAt`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RGBBlendSubFilter`
- **Signature:** `RGBBlendSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:274-304`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `MedianBlur`, `ac::RGBBlendSubFilter`, `clone`, `pixelAt`, `shiftFrames`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `DivideAndIncH`
- **Signature:** `DivideAndIncH(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:305-329`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::DivideAndIncH`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `DivideAndIncW`
- **Signature:** `DivideAndIncW(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:330-354`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::DivideAndIncW`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `XorOppositeSubFilter`
- **Signature:** `XorOppositeSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:355-375`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::XorOppositeSubFilter`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlendSmoothSubFilter`
- **Signature:** `BlendSmoothSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:376-386`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `Smooth`, `ac::BlendSmoothSubFilter`, `clone`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlurSmooth`
- **Signature:** `BlurSmooth(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:387-396`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlur`, `Smooth`, `ac::BlurSmooth`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlurSmoothMedian`
- **Signature:** `BlurSmoothMedian(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:397-402`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `BlurSmooth`, `MedianBlend`, `ac::BlurSmoothMedian`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlurSmoothSubFilter`
- **Signature:** `BlurSmoothSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:403-416`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `MedianBlur`, `Smooth`, `ac::BlurSmoothSubFilter`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlurFlip`
- **Signature:** `BlurFlip(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:417-430`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `FlipBlendAll`, `MedianBlend`, `MedianBlur`, `XorAlpha`, `ac::BlurFlip`, `clone`, `rand`, `setGamma`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlurFlipSubFilter`
- **Signature:** `BlurFlipSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:431-453`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `FlipBlendAll`, `MedianBlend`, `MedianBlur`, `XorAlpha`, `ac::BlurFlipSubFilter`, `clone`, `procPos`, `rand`, `setGamma`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlurMirrorGamma`
- **Signature:** `BlurMirrorGamma(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:454-476`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `FlipBlendWH`, `MedianBlend`, `MedianBlur`, `MirrorXorAll`, `ac::BlurMirrorGamma`, `clone`, `procPos`, `rand`, `setGamma`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MedianBlendDark`
- **Signature:** `MedianBlendDark(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:477-509`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlur`, `ac::MedianBlendDark`, `clone`, `invert`, `pixelAt`, `procPos`, `rand`, `setGamma`, `shiftFrames`, `size`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MedianBlendSubFilterEx`
- **Signature:** `MedianBlendSubFilterEx(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:510-545`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlur`, `ac::MedianBlendSubFilterEx`, `clone`, `invert`, `pixelAt`, `shiftFrames`, `size`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `EnergyMirrorDark`
- **Signature:** `EnergyMirrorDark(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:546-552`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `BlendWithSource`, `MedianBlendDark`, `MirrorXorAll`, `ac::EnergyMirrorDark`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `AlphaBlendMirror`
- **Signature:** `AlphaBlendMirror(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:553-567`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `AlphaXorBlend`, `ac::AlphaBlendMirror`, `clone`, `cv::flip`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `AlphaBlendXorImage`
- **Signature:** `AlphaBlendXorImage(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:568-593`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MedianBlur`, `ac::AlphaBlendXorImage`, `ac_resize`, `pixelAt`, `procPos`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ShiftFrameSmoothSubFilter`
- **Signature:** `ShiftFrameSmoothSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:594-604`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `Smooth`, `ac::ShiftFrameSmoothSubFilter`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ShiftFrameStaticXorSubFilter`
- **Signature:** `ShiftFrameStaticXorSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:605-621`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ScalarAverage`, `StaticXor`, `ac::ShiftFrameStaticXorSubFilter`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `IncreaseDecreaseGamma`
- **Signature:** `IncreaseDecreaseGamma(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:622-640`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::IncreaseDecreaseGamma`, `clone`, `setGamma`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `GammaIncDecIncrease`
- **Signature:** `GammaIncDecIncrease(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:641-664`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::GammaIncDecIncrease`, `clone`, `setGamma`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomSubFilter2`
- **Signature:** `RandomSubFilter2(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:665-682`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::RandomSubFilter2`, `begin`, `count`, `end`, `size`, `std::chrono::system_clock::now`, `std::default_random_engine`, `std::shuffle`, `time_since_epoch`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `TwistedVision`
- **Signature:** `TwistedVision(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:683-725`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::TwistedVision`, `pixelAt`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `TwistedMirror`
- **Signature:** `TwistedMirror(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:726-735`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `FlipBlendAll`, `MedianBlend`, `MirrorXorAll`, `TwistedVision`, `ac::TwistedMirror`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SelfScaleSortBlend`
- **Signature:** `SelfScaleSortBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:736-743`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `SelfScale`, `StrobeSort`, `ac::SelfScaleSortBlend`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlashMedianBlend`
- **Signature:** `FlashMedianBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:744-759`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MedianBlend`, `ac::FlashMedianBlend`, `clone`, `color`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlendWithFrameSubFilter`
- **Signature:** `BlendWithFrameSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:760-768`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `ac::BlendWithFrameSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `AlphaBlendWithFrameSubFilter`
- **Signature:** `AlphaBlendWithFrameSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:769-781`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `ac::AlphaBlendWithFrameSubFilter`, `clone`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `AlphaXorBlendWithFrameSubFilter`
- **Signature:** `AlphaXorBlendWithFrameSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:782-794`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaXorBlend`, `CallFilter`, `ac::AlphaXorBlendWithFrameSubFilter`, `clone`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `XorBlendSubFilter`
- **Signature:** `XorBlendSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:795-804`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `Xor`, `ac::XorBlendSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipAlphaBlend`
- **Signature:** `FlipAlphaBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:805-821`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `ac::FlipAlphaBlend`, `clone`, `cv::flip`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomFlipFilter`
- **Signature:** `RandomFlipFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:822-830`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::RandomFlipFilter`, `clone`, `flip`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorMedian`
- **Signature:** `MirrorMedian(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:831-856`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlend`, `ac::MirrorMedian`, `clone`, `cv::flip`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipMatrixCollection`
- **Signature:** `FlipMatrixCollection(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:857-870`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `MedianBlend`, `Smooth`, `ac::FlipMatrixCollection`, `clone`, `cv::flip`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorMatrixCollection`
- **Signature:** `MirrorMatrixCollection(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:871-897`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `Smooth`, `ac::MirrorMatrixCollection`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorMatrixSource`
- **Signature:** `MirrorMatrixSource(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:898-905`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `BlendWithSource`, `BlurFlip`, `MedianBlend`, `MirrorMatrixCollection`, `ac::MirrorMatrixSource`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SelfScaleByFrame`
- **Signature:** `SelfScaleByFrame(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:906-922`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `SelfAlphaScale`, `ac::SelfScaleByFrame`, `clone`, `pixelAt`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SmoothMedianRotateSubFilter`
- **Signature:** `SmoothMedianRotateSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:923-938`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `MedianBlend`, `Smooth`, `ac::SmoothMedianRotateSubFilter`, `clone`, `cv::flip`, `rand`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SmoothCollectionAlphaBlend`
- **Signature:** `SmoothCollectionAlphaBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:939-950`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `BlendWithSource`, `MedianBlur`, `Smooth`, `Xor`, `ac::SmoothCollectionAlphaBlend`, `clone`, `rainbowBlend`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `XorSubFilter`
- **Signature:** `XorSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:951-958`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `Xor`, `ac::XorSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `XorAlphaSubFilter`
- **Signature:** `XorAlphaSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:959-978`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::XorAlphaSubFilter`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlurXorAlphaSubFilter`
- **Signature:** `BlurXorAlphaSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:979-995`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlur`, `Xor`, `ac::BlurXorAlphaSubFilter`, `clone`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageXorFrame`
- **Signature:** `ImageXorFrame(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:996-1006`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `Xor`, `ac::ImageXorFrame`, `ac_resize`, `clone`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageXorFunction`
- **Signature:** `ImageXorFunction(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:1007-1015`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `Xor`, `ac::ImageXorFunction`, `ac_resize`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageXorAlphaBlend`
- **Signature:** `ImageXorAlphaBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:1016-1030`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `Xor`, `ac::ImageXorAlphaBlend`, `ac_resize`, `clone`, `procPos`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageAlphaXorMedianSubFilter`
- **Signature:** `ImageAlphaXorMedianSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:1031-1046`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlend`, `Xor`, `ac::ImageAlphaXorMedianSubFilter`, `ac_resize`, `clone`, `procPos`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageSmoothAlphaXorSubFilter`
- **Signature:** `ImageSmoothAlphaXorSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:1047-1060`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `Smooth`, `Xor`, `ac::ImageSmoothAlphaXorSubFilter`, `ac_resize`, `clone`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageXorMirrorFilter`
- **Signature:** `ImageXorMirrorFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:1061-1086`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::ImageXorMirrorFilter`, `ac_resize`, `clone`, `pixelAt`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageXorSubFilter`
- **Signature:** `ImageXorSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter12.cpp:1087-1115`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `CallFilter`, `ac::ImageXorSubFilter`, `ac_resize`, `clone`, `pixelAt`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

