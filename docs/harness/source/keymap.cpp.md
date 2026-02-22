# Harness Doc: `source/keymap.cpp`

## File-level
- **File path:** `source/keymap.cpp`
- **Purpose of file:** Implements keymap file parsing, insertion, and runtime lookup.
- **Dependencies/includes/imports:** `keymap.hpp`, stringstream, cstdlib/cctype helpers.
- **Key classes/structs/types/globals/macros:** `acidcam::KeyMap`; external hook `acidcam::updateError()`.
- **External resources touched:** Reads mapping file from filesystem.
- **Build role:** Core implementation for keyboard shortcut configuration.
- **Risks/footguns:** Uses `while(!file.eof())` pattern; malformed lines silently ignored beyond parse defaults.

## Symbols

### Function `acidcam::updateError` (extern declaration)
- **Signature:** `extern void updateError();`
- **Location:** `source/keymap.cpp:8`
- **Belongs to:** Namespace `acidcam`.
- **Purpose:** External error-state notifier invoked on keymap file-open failure.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Defined elsewhere; likely updates global error UI/state.
- **Preconditions:** Linked symbol must exist.
- **Postconditions:** Error state updated when called.
- **Error handling / failure modes:** Linker failure if symbol missing.
- **Called by (best-effort):** `KeyMap::load`.
- **Calls into (best-effort):** Definition outside this file.
- **Performance notes:** Expected constant-time hook.
- **Threading notes:** Depends on implementation.
- **Agent modification guidance:** Keep declaration synced with definition signature.
- **Related symbols:** `KeyMap::load`.

### Method `KeyMap::load`
- **Signature:** `void KeyMap::load(const std::string &name)`
- **Location:** `source/keymap.cpp:10-33`
- **Belongs to:** `acidcam::KeyMap`.
- **Purpose:** Loads key bindings from text file lines of the form `<char> <filt> <shade>`.
- **Inputs:** `name` file path.
- **Outputs / Return value:** None.
- **Side effects:** Reads file, logs status/error messages, inserts bindings into `keys`.
- **Preconditions:** Path is accessible and formatted as expected.
- **Postconditions:** Map updated with uppercase keys from valid parsed lines.
- **Error handling / failure modes:** On open failure, logs message and invokes `acidcam::updateError`; parsing failures simply skip insertion.
- **Called by (best-effort):** Startup/config reload flows.
- **Calls into (best-effort):** `std::fstream::open`, `std::getline`, `std::istringstream`, `toupper`, `setKey`, `acidcam::updateError`.
- **Performance notes:** O(lines) with per-line tokenization.
- **Threading notes:** Not synchronized; should not race with reads/writes to `keys`.
- **Agent modification guidance:** Preserve file format and uppercase normalization to avoid user config breakage.
- **Related symbols:** `KeyMap::setKey`, `keys`.

### Method `KeyMap::setKey`
- **Signature:** `void KeyMap::setKey(int k, int s, int i)`
- **Location:** `source/keymap.cpp:35-37`
- **Belongs to:** `acidcam::KeyMap`.
- **Purpose:** Inserts or replaces a key binding in the internal hash map.
- **Inputs:** Key code `k`; mapped values `s` and `i`.
- **Outputs / Return value:** None.
- **Side effects:** Mutates `keys`.
- **Preconditions:** `k` should map correctly through `toupper`.
- **Postconditions:** `keys[toupper(k)]` equals `(s, i)`.
- **Error handling / failure modes:** None explicit.
- **Called by (best-effort):** `KeyMap::load`; manual key-binding updates.
- **Calls into (best-effort):** `toupper`, `unordered_map::operator[]`.
- **Performance notes:** Amortized O(1).
- **Threading notes:** Mutation not thread-safe without external locking.
- **Agent modification guidance:** Keep mapping pair ordering stable (`first=s`, `second=i`).
- **Related symbols:** `KeyMap::checkKey`.

### Method `KeyMap::checkKey`
- **Signature:** `bool KeyMap::checkKey(int key, int &s, int &i)`
- **Location:** `source/keymap.cpp:39-46`
- **Belongs to:** `acidcam::KeyMap`.
- **Purpose:** Looks up normalized key and returns associated mapping values.
- **Inputs:** Incoming key code; output refs `s`, `i`.
- **Outputs / Return value:** `true` if key exists and outputs are written.
- **Side effects:** Writes `s` and `i` on success.
- **Preconditions:** Caller supplies valid references.
- **Postconditions:** On hit, outputs reflect stored pair; on miss, outputs unchanged.
- **Error handling / failure modes:** Miss path returns `false`.
- **Called by (best-effort):** Keyboard event dispatch logic.
- **Calls into (best-effort):** `toupper`, `unordered_map::find`.
- **Performance notes:** Average O(1) lookup.
- **Threading notes:** Safe for read-only concurrent usage if map is immutable.
- **Agent modification guidance:** Maintain boolean return semantics used by callers for branch control.
- **Related symbols:** `keys`, `setKey`.
