# Harness Doc: `source/macos-static/autofilter.hpp`

## File-level
- **File path:** `source/macos-static/autofilter.hpp`
- **Purpose of file:** Header-only autoplay filter playlist parser/iterator for shader+filter frame scheduling.
- **Dependencies/includes/imports:** STL streams/strings/files/vectors/algorithms/chrono/random/cstdlib.
- **Key classes/structs/types/globals/macros:** `acidcam::AutoFilterIndex`, `acidcam::AutoFilter`, stream operator overload.
- **External resources touched:** Reads playlist text files; writes diagnostics to stdout/stderr.
- **Build role:** Utility component used by runtime filter sequencing.
- **Risks/footguns:** `increment/current/next` assume non-empty playlist; `while(!eof())` parsing pattern can be brittle.

## Symbols

### Type `AutoFilterIndex`
- **Signature:** `class AutoFilterIndex`
- **Location:** `source/macos-static/autofilter.hpp:16-43`
- **Belongs to:** `acidcam` namespace.
- **Purpose:** Stores one shader/filter entry and per-entry frame counters.
- **Inputs:** Constructed from shader/filter/count values.
- **Outputs / Return value:** N/A.
- **Side effects:** Holds mutable frame index state.
- **Preconditions:** `frame_count` should be positive for valid playback.
- **Postconditions:** Entry can be iterated/logged.
- **Error handling / failure modes:** No internal validation in constructors.
- **Called by (best-effort):** `AutoFilter::parseLine`, playback traversal.
- **Calls into (best-effort):** STL move/copy operations.
- **Performance notes:** Small object; cheap copy/move.
- **Threading notes:** Not synchronized.
- **Agent modification guidance:** Keep POD-like simplicity and copy/move semantics aligned.
- **Related symbols:** `AutoFilter`, `operator<<`.

### Operator `operator<<`
- **Signature:** `inline std::ostream &operator<<(std::ostream &out, const AutoFilterIndex &i)`
- **Location:** `source/macos-static/autofilter.hpp:45-48`
- **Belongs to:** `acidcam` namespace helper.
- **Purpose:** Formats index entries for logs.
- **Inputs:** Output stream and index entry.
- **Outputs / Return value:** Same stream reference.
- **Side effects:** Writes human-readable descriptor text.
- **Preconditions:** Stream valid.
- **Postconditions:** Log line appended.
- **Error handling / failure modes:** Standard stream failbit behavior.
- **Called by (best-effort):** `AutoFilter::printFilters`.
- **Calls into (best-effort):** stream insertion operators.
- **Performance notes:** O(length of fields).
- **Threading notes:** Output may interleave across threads.
- **Agent modification guidance:** Preserve stable log format if downstream parsers depend on it.
- **Related symbols:** `AutoFilterIndex`.

### Type `AutoFilter`
- **Signature:** `class AutoFilter`
- **Location:** `source/macos-static/autofilter.hpp:50-172`
- **Belongs to:** `acidcam` namespace.
- **Purpose:** Manages ordered/shuffled playback of filter script entries.
- **Inputs:** Loaded from file lines `shader:filter:count`.
- **Outputs / Return value:** Iteration status and current entries.
- **Side effects:** Mutates internal vector/index; prints diagnostics.
- **Preconditions:** Playlist should be loaded before iteration methods.
- **Postconditions:** Stateful progress through configured sequence.
- **Error handling / failure modes:** Parsing errors logged and skipped; no exceptions.
- **Called by (best-effort):** Main processing loop controlling dynamic filters.
- **Calls into (best-effort):** file I/O, RNG shuffle, parser helper.
- **Performance notes:** Mostly O(1) iteration; shuffle O(n).
- **Threading notes:** Mutable non-thread-safe state.
- **Agent modification guidance:** Add bounds checks before index access if hardening.
- **Related symbols:** `parseLine`, `playback`, `current_index`.

### Methods summary (`AutoFilter`)
- **Signature:** `AutoFilter()`, `clear()`, `printFilters()`, `size() const`, `increment()`, `current() const`, `next(AutoFilterIndex&)`, `next()`, `shuffle(bool)`, `shuffle()`, `loadFile(const std::string&)`, `parseLine(int,const std::string&)`.
- **Location:** `source/macos-static/autofilter.hpp:53-171`
- **Belongs to:** `AutoFilter`.
- **Purpose:** Construct/reset state, inspect size, iterate entries, optional randomization, parse/load playlist files.
- **Inputs:** Optional output reference, boolean toggle, filename, line text.
- **Outputs / Return value:** Booleans for iteration/load success; current entry copies; no return for mutators.
- **Side effects:** Alters `playback`, `current_index`, `shuffle_on`; emits console diagnostics.
- **Preconditions:** Iteration requires `playback.size() > 0`.
- **Postconditions:** Cursor advances/resets and entries may be shuffled.
- **Error handling / failure modes:** Missing delimiters/non-positive counts are rejected with stderr logs; failed file open returns `false`.
- **Called by (best-effort):** Auto-filter runtime controller.
- **Calls into (best-effort):** `std::getline`, `std::shuffle`, `atoi`, stream output.
- **Performance notes:** File load O(lines); parse O(line length); next/increment O(1).
- **Threading notes:** All methods unsynchronized.
- **Agent modification guidance:** Keep parsing format backward-compatible (`shader:filter:count`).
- **Related symbols:** `AutoFilterIndex`, `operator<<`.
