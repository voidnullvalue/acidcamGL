# Harness Doc: `source/macos-static/libacidcam/ac-basic.cpp`

## File-level
- **File path:** `source/macos-static/libacidcam/ac-basic.cpp`
- **Purpose of file:** Implements libacidcam filter/effect routines compiled into the macOS-static build.
- **Dependencies/includes/imports:** `#include"ac.h"`, `#include"fractal.h"`
- **Key classes/structs/types/globals/macros:** Namespace `ac` filters, file-scope counters/state, and OpenCV frame types.
- **External resources touched:** In-memory OpenCV frame buffers (`cv::Mat`), global filter state, and random-number helpers.
- **Build role:** One translation unit in `source/macos-static/libacidcam` filter library.
- **Risks/footguns:** High arithmetic intensity per frame, channel overflow/wrap behavior, and shared mutable state assumptions across filters.

## Functions / Methods

### `SelfAlphaBlend`
- **Signature:** `SelfAlphaBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:48-80`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::SelfAlphaBlend`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `SelfScale`
- **Signature:** `SelfScale(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:81-122`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::SelfScale`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `StrobeEffect`
- **Signature:** `StrobeEffect(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:123-178`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::StrobeEffect`, `invert`, `pixelAt`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Blend3`
- **Signature:** `Blend3(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:179-206`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::Blend3`, `invert`, `pixelAt`, `rand`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `NegParadox`
- **Signature:** `NegParadox(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:207-240`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::NegParadox`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `ThoughtMode`
- **Signature:** `ThoughtMode(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:241-273`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::ThoughtMode`, `invert`, `pixelAt`, `rand`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Pass2Blend`
- **Signature:** `Pass2Blend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:274-290`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::Pass2Blend`, `empty`, `pixelAt`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `RandTriBlend`
- **Signature:** `RandTriBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:291-344`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::RandTriBlend`, `invert`, `pixelAt`, `rand`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Blank`
- **Signature:** `Blank(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:345-378`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::Blank`, `invert`, `negative`, `pixelAt`, `positive`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Tri`
- **Signature:** `Tri(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:379-411`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::Tri`, `invert`, `negative`, `pixelAt`, `positive`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Distort`
- **Signature:** `Distort(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:412-441`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::Distort`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `CDraw`
- **Signature:** `CDraw(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:442-471`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::CDraw`, `cos`, `invert`, `pixel`, `pixelAt`, `resetAlpha`, `sin`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `Type`
- **Signature:** `Type(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:472-495`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::Type`, `invert`, `pixelAt`, `rand`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `NewOne`
- **Signature:** `NewOne(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:496-536`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::NewOne`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `blendFractal`
- **Signature:** `blendFractal(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:537-542`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::blendFractal`, `frac::DrawFractal`, `frac::FractalLogic`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `blendFractalMood`
- **Signature:** `blendFractalMood(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:543-564`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::blendFractalMood`, `frac::DrawFractal`, `frac::FractalLogic`, `pixelAt`, `rand`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `GetFX`
- **Signature:** `GetFX(cv::Mat & frame,int x,int nw)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:565-569`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::GetFX`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `GetFY`
- **Signature:** `GetFY(cv::Mat & frame,int y,int nh)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:570-575`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::GetFY`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `blendWithImage`
- **Signature:** `blendWithImage(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:576-613`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `GetFX`, `GetFY`, `ac::blendWithImage`, `invert`, `pixelAt`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `cossinMultiply`
- **Signature:** `cossinMultiply(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:614-634`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::cossinMultiply`, `cos`, `invert`, `pixelAt`, `resetAlpha`, `sin`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `colorAccumulate1`
- **Signature:** `colorAccumulate1(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:635-655`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::colorAccumulate1`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `colorAccumulate2`
- **Signature:** `colorAccumulate2(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:656-677`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::colorAccumulate2`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `colorAccumulate3`
- **Signature:** `colorAccumulate3(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:678-698`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::colorAccumulate3`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `filter8`
- **Signature:** `filter8(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:699-725`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::filter8`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `filter3`
- **Signature:** `filter3(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:726-755`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::filter3`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `rainbowBlend`
- **Signature:** `rainbowBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:756-803`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::rainbowBlend`, `invert`, `pixelAt`, `rand`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `randBlend`
- **Signature:** `randBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:804-821`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::randBlend`, `invert`, `pixelAt`, `rand`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `newBlend`
- **Signature:** `newBlend(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:822-854`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::newBlend`, `invert`, `pixelAt`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

### `pixelScale`
- **Signature:** `pixelScale(cv::Mat & frame)`
- **Location:** `source/macos-static/libacidcam/ac-basic.cpp:855-889`
- **Belongs to:** `ac`
- **Purpose:** Executes one filter stage or helper operation on image data/state (best-effort summary).
- **Inputs:** Parameters in signature (typically frame refs, scalar controls, and optional subfilter objects).
- **Outputs / Return value:** Per signature; most routines mutate frame data in place.
- **Side effects:** Updates pixel buffers and may change static/global counters, matrices, or collection buffers.
- **Preconditions:** Expected valid frame dimensions/type and initialized filter/global resources from libacidcam runtime.
- **Postconditions:** Effect computations applied to addressed frame/state regions.
- **Error handling / failure modes:** Mostly boundary checks and clamped math; little explicit error propagation.
- **Called by (best-effort):** Central filter dispatch / frame-processing pipeline in `ac`.
- **Calls into (best-effort):** `ac::pixelScale`, `invert`, `pixelAt`, `resetAlpha`, `swapColors`
- **Performance notes:** Usually O(width*height) per call; some routines include extra buffer traversals/subfilter calls.
- **Threading notes:** Not inherently thread-safe when shared file/global state is touched concurrently.
- **Agent modification guidance:** Keep in-place semantics and neighbor-index guards intact; verify visual output regressions after math changes.
- **Related symbols:** `ac::CallFilter`, `ac::UseMultipleThreads`, neighboring `ac-filter*.cpp` effects.

