# Harness Doc: `source/autofilter.hpp`

## File-level
- **File path:** `source/autofilter.hpp`
- **Purpose of file:** Header-only playback list for automatic shader/filter switching based on frame counts.
- **Dependencies/includes/imports:** STL containers/algorithms, `<fstream>`, `<random>`, `<chrono>`.
- **Key classes/structs/types/globals/macros:** `AutoFilterIndex`, `AutoFilter`, stream operator overload.
- **External resources touched:** Reads autofilter files from disk; logs to stdout/stderr.
- **Build role:** Runtime scheduling helper for filter/shader automation.
- **Risks/footguns:** Many methods index `playback[current_index]` without empty-check; caller must ensure non-empty list.

## Symbols

### `AutoFilterIndex` constructors and assignment operators
- **Signature:** value/move/copy ctor + copy/move assignment.
- **Location:** `source/autofilter.hpp:19-40`
- **Belongs to:** `AutoFilterIndex`
- **Purpose:** Store one automation step (`shader`, `filter`, `frame_count`, `frame_index`).
- **Inputs:** symbol names and frame counts, or source instance.
- **Outputs:** initialized/assigned struct.
- **Side effects:** move operations transfer string storage.
- **Preconditions:** `frame_count` should be positive for valid playback semantics.
- **Postconditions:** members copied/moved.
- **Error handling:** none.
- **Called by:** parser/load path.
- **Calls into:** STL move/copy ops.
- **Performance notes:** inexpensive except string allocations.
- **Threading notes:** plain data type.
- **Agent modification guidance:** keep POD-like semantics; avoid adding hidden runtime dependencies.
- **Related symbols:** `AutoFilter::parseLine`.

### `operator<<(std::ostream&, const AutoFilterIndex&)`
- **Signature:** inline stream operator
- **Location:** `source/autofilter.hpp:44-47`
- **Belongs to:** namespace `acidcam`
- **Purpose:** Human-readable debug print for one index entry.
- **Inputs:** output stream and index object.
- **Outputs:** stream reference.
- **Side effects:** writes formatted text.
- **Preconditions:** valid stream.
- **Postconditions:** stream appended.
- **Error handling:** stream-state based.
- **Called by:** `AutoFilter::printFilters`.
- **Calls into:** ostream insertion ops.
- **Performance notes:** small I/O formatting cost.
- **Threading notes:** stream synchronization depends on caller.
- **Agent modification guidance:** keep output stable if external tooling parses logs.
- **Related symbols:** `printFilters`.

### `AutoFilter::clear`
- **Signature:** `void clear()`
- **Location:** `source/autofilter.hpp:55-61`
- **Belongs to:** `AutoFilter`
- **Purpose:** Clear loaded playback entries and reset index.
- **Inputs/Outputs:** none.
- **Side effects:** mutates internal vector/index.
- **Preconditions:** none.
- **Postconditions:** `playback` empty and `current_index=0` if previously non-empty.
- **Error handling:** none.
- **Called by:** reset/reload flow.
- **Calls into:** vector erase.
- **Performance notes:** O(n).
- **Threading notes:** not synchronized.
- **Agent modification guidance:** `clear()` could simplify to `playback.clear()` in future cleanup.
- **Related symbols:** `loadFile`.

### `printFilters`, `size`, `increment`, `current`, `next(AutoFilterIndex&)`, `next()`, `shuffle(bool)`, `shuffle()`
- **Signature:** Playback iteration/control helpers.
- **Location:** `source/autofilter.hpp:64-117`
- **Belongs to:** `AutoFilter`
- **Purpose:** Provide iteration and optional shuffle behavior over loaded entries.
- **Inputs:** optional output ref or shuffle flag.
- **Outputs / Return value:** booleans indicate wraparound/progression; `current()` returns current entry copy.
- **Side effects:** mutates `current_index`, `frame_index`, and vector order (`shuffle()`).
- **Preconditions:** `playback` must be non-empty before `increment/current/next` to avoid out-of-bounds.
- **Postconditions:** index/frame counters advanced or reset.
- **Error handling / failure modes:** no explicit guard for empty playback.
- **Called by:** runtime auto-filter scheduler.
- **Calls into:** STL output and `std::shuffle`.
- **Performance notes:** O(1) except shuffle O(n).
- **Threading notes:** mutable shared state; external synchronization needed.
- **Agent modification guidance:** if adding safety checks, preserve current wrap semantics.
- **Related symbols:** `parseLine`, `loadFile`.

### `AutoFilter::loadFile`
- **Signature:** `bool loadFile(const std::string &filename)`
- **Location:** `source/autofilter.hpp:120-138`
- **Belongs to:** `AutoFilter`
- **Purpose:** Parse autofilter script file and populate playback entries.
- **Inputs:** file path.
- **Outputs:** `true` if file opened (even with parse errors), else `false`.
- **Side effects:** appends parsed entries, resets `current_index`, logs load summary.
- **Preconditions:** readable file in expected `shader:filter:count` format per line.
- **Postconditions:** playback may contain zero or more valid entries.
- **Error handling / failure modes:** returns false on open failure; malformed lines reported by `parseLine` and skipped.
- **Called by:** command-line/runtime autofilter load path.
- **Calls into:** fstream operations, `parseLine`.
- **Performance notes:** linear in file lines.
- **Threading notes:** file I/O + mutable state; not synchronized.
- **Agent modification guidance:** this method does not clear existing entries before load; callers should call `clear()` when needed.
- **Related symbols:** `parseLine`.

### `AutoFilter::parseLine` (private)
- **Signature:** `void parseLine(int line_index, const std::string &line)`
- **Location:** `source/autofilter.hpp:144-166`
- **Belongs to:** `AutoFilter`
- **Purpose:** Parse one line into `AutoFilterIndex` and append to playback.
- **Inputs:** source line number + text.
- **Outputs:** none.
- **Side effects:** appends to `playback` or logs parse error.
- **Preconditions:** line contains two `:` separators and positive integer count.
- **Postconditions:** valid parsed entries pushed.
- **Error handling:** logs specific parse failures; ignores invalid lines.
- **Called by:** `loadFile`.
- **Calls into:** string parsing and `atoi`.
- **Performance notes:** linear in line length.
- **Threading notes:** not synchronized.
- **Agent modification guidance:** uses `atoi` (no strict validation); uncertain parsing edge cases should be documented if changed.
- **Related symbols:** `AutoFilterIndex`.
