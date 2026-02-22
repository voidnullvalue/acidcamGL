# Harness Doc: `source/macos-static/fractal.h`

## File-level
- **File path:** `source/macos-static/fractal.h`
- **Purpose of file:** Declares fractal rendering control parameters and draw/logic entry points.
- **Dependencies/includes/imports:** OpenCV (`cv::Mat`), `<complex>`, `<string>`.
- **Key classes/structs/types/globals/macros:** Namespace `frac`; extern params (`paramA`, `paramB`, radius/zoom fields, color fields, `max_iter`); `FractalLogic`, `DrawFractal`.
- **External resources touched:** Intended to mutate image frames (`cv::Mat`) and global fractal state.
- **Build role:** Shared interface for fractal effect implementation and callers.
- **Risks/footguns:** Heavy global mutable state in namespace; requires careful sequencing when used from multiple threads.

## Symbols

### Namespace globals (`frac`)
- **Signature:** `extern double paramA, paramB; extern float radius; extern float zoom_x, zoom_y, zoom_w, zoom_h; extern long max_iter; extern double red_color, green_color, blue_color;`
- **Location:** `source/macos-static/fractal.h:53-57`
- **Belongs to:** `frac` namespace.
- **Purpose:** Runtime parameters controlling fractal geometry, iteration depth, and color scaling.
- **Inputs:** Set by UI/config/logic code.
- **Outputs / Return value:** Read by fractal computation routines.
- **Side effects:** Changing values alters future generated imagery.
- **Preconditions:** Variables defined in corresponding implementation unit.
- **Postconditions:** New parameter state persists globally.
- **Error handling / failure modes:** No range validation at declaration level.
- **Called by (best-effort):** Fractal UI sliders/config loaders.
- **Calls into (best-effort):** N/A.
- **Performance notes:** Global scalar reads/writes are cheap.
- **Threading notes:** Unsynchronized shared mutable state.
- **Agent modification guidance:** Prefer grouping into config struct if refactoring for thread safety.
- **Related symbols:** `FractalLogic`, `DrawFractal`.

### Function `FractalLogic`
- **Signature:** `void FractalLogic();`
- **Location:** `source/macos-static/fractal.h:58`
- **Belongs to:** `frac` namespace.
- **Purpose:** Updates or computes fractal internal state prior to drawing.
- **Inputs:** Implicitly uses global fractal parameters.
- **Outputs / Return value:** None.
- **Side effects:** Expected to mutate global/runtime fractal state.
- **Preconditions:** Global parameters initialized.
- **Postconditions:** State prepared for rendering pass.
- **Error handling / failure modes:** Not specified in header.
- **Called by (best-effort):** Animation/update loop.
- **Calls into (best-effort):** Implementation-specific numeric routines.
- **Performance notes:** Complexity depends on iteration strategy.
- **Threading notes:** Not thread-safe with shared globals.
- **Agent modification guidance:** Document deterministic behavior if logic evolves.
- **Related symbols:** `DrawFractal`, `max_iter`.

### Function `DrawFractal`
- **Signature:** `void DrawFractal(cv::Mat &frame, bool neg=false);`
- **Location:** `source/macos-static/fractal.h:59`
- **Belongs to:** `frac` namespace.
- **Purpose:** Renders fractal output into supplied image frame.
- **Inputs:** Destination `cv::Mat` and optional negative-color toggle.
- **Outputs / Return value:** None; frame modified in-place.
- **Side effects:** Writes pixel data to `frame`.
- **Preconditions:** Frame allocated and writable; global params configured.
- **Postconditions:** Frame contains fractal visualization.
- **Error handling / failure modes:** No declaration-level failure reporting.
- **Called by (best-effort):** Effect/filter render pipeline.
- **Calls into (best-effort):** Fractal computation routines, OpenCV matrix access.
- **Performance notes:** Typically O(width*height*iteration_depth).
- **Threading notes:** Avoid concurrent calls sharing global state unless synchronized.
- **Agent modification guidance:** Keep explicit in-place mutation semantics.
- **Related symbols:** `FractalLogic`, namespace globals.
