# Harness Doc: `source/macos-static/keymap.cpp`

## File-level
- **File path:** `source/macos-static/keymap.cpp`
- **Purpose of file:** Implements file-backed key binding load/store/lookup logic.
- **Dependencies/includes/imports:** `keymap.hpp`, `<sstream>`, `<cstdlib>`, `<cctype>`.
- **Key classes/structs/types/globals/macros:** `acidcam::KeyMap`; external `acidcam::updateError` declaration.
- **External resources touched:** Keymap text file and console output.
- **Build role:** Input shortcut parser/lookup implementation for macOS static runtime.
- **Risks/footguns:** `while(!file.eof())` idiom can be error-prone; open failure does not short-circuit parsing loop.

## Functions / Methods

### `KeyMap::load`
- **Signature:** `void KeyMap::load(const std::string &name)`
- **Location:** `source/macos-static/keymap.cpp:10-33`
- **Belongs to:** `acidcam::KeyMap`
- **Purpose:** Parse keymap file lines into in-memory shortcut map.
- **Inputs:** File path.
- **Outputs / Return value:** None.
- **Side effects:** Reads file, writes to `keys`, logs configured shortcuts, may call global error updater.
- **Preconditions:** File exists and uses expected line format (`<char> <int> <int>`).
- **Postconditions:** Valid entries inserted into map with uppercase key normalization.
- **Error handling / failure modes:** Logs open error and calls `acidcam::updateError()`; continues execution.
- **Called by (best-effort):** Startup configuration/load path.
- **Calls into (best-effort):** `std::fstream`, `std::getline`, `std::istringstream`, `toupper`, `setKey`, `acidcam::updateError`.
- **Performance notes:** O(number of lines).
- **Threading notes:** Mutates internal map; not thread-safe with concurrent reads/writes.
- **Agent modification guidance:** Prefer `while(std::getline(...))` if modernizing parser robustness.
- **Related symbols:** `setKey`, `checkKey`.

### `KeyMap::setKey`
- **Signature:** `void KeyMap::setKey(int k, int s, int i)`
- **Location:** `source/macos-static/keymap.cpp:35-37`
- **Belongs to:** `acidcam::KeyMap`
- **Purpose:** Store a normalized key binding pair.
- **Inputs:** Key code and mapped values (`s`, `i`).
- **Outputs / Return value:** None.
- **Side effects:** Inserts/updates `keys` entry.
- **Preconditions:** None beyond valid map state.
- **Postconditions:** `keys[toupper(k)] == {s, i}`.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** `load`, potential manual configuration.
- **Calls into (best-effort):** `unordered_map::operator[]`, `std::pair` ctor.
- **Performance notes:** Average O(1).
- **Threading notes:** Unsynchronized mutation.
- **Agent modification guidance:** Keep normalization logic consistent with lookup.
- **Related symbols:** `checkKey`.

### `KeyMap::checkKey`
- **Signature:** `bool KeyMap::checkKey(int key, int &s, int &i)`
- **Location:** `source/macos-static/keymap.cpp:39-46`
- **Belongs to:** `acidcam::KeyMap`
- **Purpose:** Lookup mapping for given key and return associated values.
- **Inputs:** Key code and output references.
- **Outputs / Return value:** `true` when mapping exists.
- **Side effects:** Writes to `s` and `i` on success.
- **Preconditions:** Caller passes valid references.
- **Postconditions:** Outputs populated iff return is true.
- **Error handling / failure modes:** False return for missing key.
- **Called by (best-effort):** Keyboard event handling code.
- **Calls into (best-effort):** `unordered_map::find`, `toupper`.
- **Performance notes:** Average O(1).
- **Threading notes:** Safe for read-only access only when no concurrent writers.
- **Agent modification guidance:** Preserve lookup contract for input handlers.
- **Related symbols:** `setKey`, `keys`.
