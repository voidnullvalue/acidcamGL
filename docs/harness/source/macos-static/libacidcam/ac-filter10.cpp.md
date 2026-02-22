# Harness Doc: `source/macos-static/libacidcam/ac-filter10.cpp`

## File-level
- **File path:** `source/macos-static/libacidcam/ac-filter10.cpp`
- **Purpose of file:** Implements libacidcam filter/effect routines compiled into the macOS-static build.
- **Dependencies/includes/imports:** `#include"ac.h"`
- **Key classes/structs/types/globals/macros:** Namespace `ac` filters, file-scope counters/state, and OpenCV frame types.
- **External resources touched:** In-memory OpenCV frame buffers (`cv::Mat`), global filter state, and random-number helpers.
- **Build role:** One translation unit in `source/macos-static/libacidcam` filter library.
- **Risks/footguns:** High arithmetic intensity per frame, channel overflow/wrap behavior, and shared mutable state assumptions across filters.

## Functions / Methods

### `ExpandSquareSubFilter`
- **Signature:** `ExpandSquareSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:46-80`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::ExpandSquareSubFilter`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ExpandSquareBlendSubFilter`
- **Signature:** `ExpandSquareBlendSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:81-119`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::ExpandSquareBlendSubFilter`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ExpandSquareVerticalSubFilter`
- **Signature:** `ExpandSquareVerticalSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:120-154`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::ExpandSquareVerticalSubFilter`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `DarkImageMedianBlend`
- **Signature:** `DarkImageMedianBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:155-163`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `MedianBlend`, `SmoothImageAlphaBlend`, `ac::DarkImageMedianBlend`, `clone`, `setGamma`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `GammaDarken5`
- **Signature:** `GammaDarken5(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:164-168`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::GammaDarken5`, `clone`, `setGamma`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `GammaDarken10`
- **Signature:** `GammaDarken10(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:169-173`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::GammaDarken10`, `clone`, `setGamma`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SelfAlphaScaleBlend`
- **Signature:** `SelfAlphaScaleBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:174-193`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::SelfAlphaScaleBlend`, `pixelAt`, `procPos`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FadeBars`
- **Signature:** `FadeBars(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:194-210`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::FadeBars`, `pixelAt`, `procPos`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorXorAlpha`
- **Signature:** `MirrorXorAlpha(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:211-239`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::MirrorXorAlpha`, `clone`, `color_`, `pixelAt`, `procPos`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `MirrorEnergizeSubFilter`
- **Signature:** `MirrorEnergizeSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:240-248`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `DarkenImage`, `EnergizeSubFilter`, `MirrorXorAlpha`, `ac::MirrorEnergizeSubFilter`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `StrobeXor`
- **Signature:** `StrobeXor(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:249-260`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::StrobeXor`, `pix`, `pixelAt`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `IntertwinedMirror`
- **Signature:** `IntertwinedMirror(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:261-281`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::IntertwinedMirror`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlurredMirror`
- **Signature:** `BlurredMirror(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:282-308`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `DarkenImage`, `MedianBlend`, `ac::BlurredMirror`, `cv::medianBlur`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ShadeRGB`
- **Signature:** `ShadeRGB(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:309-336`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `DarkenImage`, `MedianBlend`, `ac::ShadeRGB`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `InterRGB_SubFilter`
- **Signature:** `InterRGB_SubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:337-374`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::InterRGB_SubFilter`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `InterSmoothSubFilter`
- **Signature:** `InterSmoothSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:375-407`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `Smooth`, `ac::InterSmoothSubFilter`, `clone`, `pixelAt`, `procPos`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `InterRGB_Bars_XY`
- **Signature:** `InterRGB_Bars_XY(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:408-427`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::InterRGB_Bars_XY`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `InterRGB_Bars_X`
- **Signature:** `InterRGB_Bars_X(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:428-447`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::InterRGB_Bars_X`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `InterRGB_Bars_Y`
- **Signature:** `InterRGB_Bars_Y(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:448-467`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::InterRGB_Bars_Y`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `StoredFramesAlphaBlend_SubFilter`
- **Signature:** `StoredFramesAlphaBlend_SubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:468-483`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `Smooth`, `ac::StoredFramesAlphaBlend_SubFilter`, `clone`, `procPos`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlendSubFilter`
- **Signature:** `BlendSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:484-508`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::BlendSubFilter`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlendAlphaSubFilter`
- **Signature:** `BlendAlphaSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:509-539`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::BlendAlphaSubFilter`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ReverseFrameBlend`
- **Signature:** `ReverseFrameBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:540-563`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlend`, `Reverse`, `ac::ReverseFrameBlend`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ReverseFrameBlendSwitch`
- **Signature:** `ReverseFrameBlendSwitch(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:564-591`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `MedianBlend`, `Reverse`, `ac::ReverseFrameBlendSwitch`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `DoubleRandomMirror`
- **Signature:** `DoubleRandomMirror(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:592-615`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `RandomMirror`, `ac::DoubleRandomMirror`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Blend_AlphaSubFilter`
- **Signature:** `Blend_AlphaSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:616-643`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `RandomBlendFilter`, `ac::Blend_AlphaSubFilter`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandomBlendFilter`
- **Signature:** `RandomBlendFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:644-650`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `ac::RandomBlendFilter`, `rand`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `DoubleRandomBlendFilter`
- **Signature:** `DoubleRandomBlendFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:651-674`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `RandomBlendFilter`, `ac::DoubleRandomBlendFilter`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipBlendWH`
- **Signature:** `FlipBlendWH(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:675-697`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::FlipBlendWH`, `cv::flip`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipBlendH`
- **Signature:** `FlipBlendH(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:698-720`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::FlipBlendH`, `cv::flip`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipBlendW`
- **Signature:** `FlipBlendW(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:721-743`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::FlipBlendW`, `cv::flip`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FlipBlendAll`
- **Signature:** `FlipBlendAll(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:744-777`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::FlipBlendAll`, `cv::flip`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FrameMedianBlendSubFilter`
- **Signature:** `FrameMedianBlendSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:778-806`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `CallFilter`, `MedianBlend`, `MedianBlur`, `RainbowXorBlend`, `ac::FrameMedianBlendSubFilter`, `cv::flip`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `FrameBlurSubFilter`
- **Signature:** `FrameBlurSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:807-823`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `MedianBlur`, `ac::FrameBlurSubFilter`, `clone`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageBlendSubFilter`
- **Signature:** `ImageBlendSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:824-853`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `CallFilter`, `ExactImage`, `ac::ImageBlendSubFilter`, `clone`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageBlendXorSubFilter`
- **Signature:** `ImageBlendXorSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:854-876`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `CallFilter`, `ExactImage`, `ac::ImageBlendXorSubFilter`, `clone`, `pixelAt`, `procPos`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ImageCollectionSubFilter`
- **Signature:** `ImageCollectionSubFilter(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:877-893`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `AlphaBlend`, `CallFilter`, `ExactImage`, `Smooth`, `ac::ImageCollectionSubFilter`, `clone`, `procPos`, `shiftFrames`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SelfScaleXorIncrease`
- **Signature:** `SelfScaleXorIncrease(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:894-930`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::SelfScaleXorIncrease`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Blend_RedGreenBlue`
- **Signature:** `Blend_RedGreenBlue(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:931-956`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::Blend_RedGreenBlue`, `pixelAt`, `rand`, `values`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `XorBlend_RedGreenBlue`
- **Signature:** `XorBlend_RedGreenBlue(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:957-983`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::XorBlend_RedGreenBlue`, `pixelAt`, `rand`, `values`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `BlendIncrease_RedGreenBlue`
- **Signature:** `BlendIncrease_RedGreenBlue(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:984-1016`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::BlendIncrease_RedGreenBlue`, `pixelAt`, `rand`, `values`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Blend_RedReenBlue_Dark`
- **Signature:** `Blend_RedReenBlue_Dark(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:1017-1044`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::Blend_RedReenBlue_Dark`, `pixelAt`, `rand`, `values`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `DarkModBlend`
- **Signature:** `DarkModBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:1045-1076`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::DarkModBlend`, `pixelAt`, `rand`, `values`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `PictureBuzz`
- **Signature:** `PictureBuzz(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:1077-1106`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::PictureBuzz`, `pixelAt`, `rand`, `values`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `IncDifference`
- **Signature:** `IncDifference(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:1107-1126`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::IncDifference`, `clone`, `pixelAt`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `IncDifferenceAlpha`
- **Signature:** `IncDifferenceAlpha(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-filter10.cpp:1127-1153`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `AddInvert`, `ac::IncDifferenceAlpha`, `clone`, `pixelAt`, `procPos`, `rand`, `size`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

