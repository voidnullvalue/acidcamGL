# Harness Doc: `source/keymap.hpp`

## File-level
- **File path:** `source/keymap.hpp`
- **Purpose of file:** Declares keyboard shortcut mapping container used to map key presses to filter/shader indexes.
- **Dependencies/includes/imports:** STL I/O, file streams, unordered map, strings.
- **Key classes/structs/types/globals/macros:** `acidcam::KeyMap`; `keys` map storing `key -> (s, i)` pair.
- **External resources touched:** None directly in header.
- **Build role:** Interface declaration for keymap loading and lookup logic.
- **Risks/footguns:** Case normalization via `toupper`; locale-dependent behavior.

## Symbols

### Class `acidcam::KeyMap`
- **Signature:** `class KeyMap`
- **Location:** `source/keymap.hpp:11-19`
- **Belongs to:** Namespace `acidcam`.
- **Purpose:** Owns shortcut mapping from keyboard key to two integer routing values.
- **Inputs:** File path for loading; key/value tuples for insertion and lookup.
- **Outputs / Return value:** Lookup success boolean and output references.
- **Side effects:** Mutates in-memory map.
- **Preconditions:** Keys expected as ASCII-like values for uppercase normalization.
- **Postconditions:** Map reflects loaded/inserted key bindings.
- **Error handling / failure modes:** Error handling mostly deferred to implementation.
- **Called by (best-effort):** Input/event handling code.
- **Calls into (best-effort):** `load`, `setKey`, `checkKey` implementations.
- **Performance notes:** Average O(1) map insert/lookup.
- **Threading notes:** Not thread-safe for concurrent mutation.
- **Agent modification guidance:** Preserve `checkKey` out-parameter semantics for existing callers.
- **Related symbols:** `keys`.

### Method `KeyMap::load`
- **Signature:** `void load(const std::string &name)`
- **Location:** `source/keymap.hpp:13`
- **Belongs to:** `acidcam::KeyMap`.
- **Purpose:** Declares file-based keymap loader.
- **Inputs:** Config filename/path.
- **Outputs / Return value:** None.
- **Side effects:** Populates mapping table in implementation.
- **Preconditions:** Readable keymap file.
- **Postconditions:** Key bindings imported when parse succeeds.
- **Error handling / failure modes:** Implementation emits error and triggers update hook.
- **Called by / Calls into (best-effort):** Runtime config loading / implementation in `keymap.cpp`.
- **Performance notes:** Linear in number of lines.
- **Threading notes:** Mutating method.
- **Agent modification guidance:** Keep plain-text format compatibility.
- **Related symbols:** `setKey`.

### Method `KeyMap::setKey`
- **Signature:** `void setKey(int k, int s, int i)`
- **Location:** `source/keymap.hpp:14`
- **Belongs to:** `acidcam::KeyMap`.
- **Purpose:** Declares key-binding insertion/update helper.
- **Inputs:** Key `k`, mapped values `s` and `i`.
- **Outputs / Return value:** None.
- **Side effects:** Writes into `keys` map.
- **Preconditions:** Key value representable for `toupper` normalization.
- **Postconditions:** Existing entry replaced or new one inserted.
- **Error handling / failure modes:** None explicit.
- **Called by / Calls into (best-effort):** `load`; implementation in `keymap.cpp`.
- **Performance notes:** Average O(1).
- **Threading notes:** Not synchronized.
- **Agent modification guidance:** Preserve uppercase normalization behavior.
- **Related symbols:** `checkKey`.

### Method `KeyMap::checkKey`
- **Signature:** `bool checkKey(int key, int &s, int &i)`
- **Location:** `source/keymap.hpp:15`
- **Belongs to:** `acidcam::KeyMap`.
- **Purpose:** Declares lookup routine returning mapped values for a pressed key.
- **Inputs:** Input key; output refs `s` and `i`.
- **Outputs / Return value:** `true` when key exists; fills `s`/`i`.
- **Side effects:** None besides output parameters.
- **Preconditions:** Caller provides valid refs.
- **Postconditions:** On success, outputs populated from stored pair.
- **Error handling / failure modes:** Returns `false` for missing key.
- **Called by / Calls into (best-effort):** Input event dispatch.
- **Performance notes:** Average O(1).
- **Threading notes:** Safe for concurrent reads only if map not mutating.
- **Agent modification guidance:** Avoid changing return/out-param contract.
- **Related symbols:** `keys`.
