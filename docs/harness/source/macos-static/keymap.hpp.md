# Harness Doc: `source/macos-static/keymap.hpp`

## File-level
- **File path:** `source/macos-static/keymap.hpp`
- **Purpose of file:** Declares keyboard shortcut mapping utility used to map key presses to filter/shader indices.
- **Dependencies/includes/imports:** `<iostream>`, `<fstream>`, `<unordered_map>`, `<string>`.
- **Key classes/structs/types/globals/macros:** `acidcam::KeyMap`, internal `keys` map (`int -> pair<int,int>`).
- **External resources touched:** Keymap file data (via implementation load).
- **Build role:** Input configuration interface for macOS static runtime.
- **Risks/footguns:** Character key normalization uses `toupper`; locale/unsigned-char caveats apply.

## Functions / Methods

### `KeyMap::load`
- **Signature:** `void load(const std::string &name)`
- **Location:** `source/macos-static/keymap.hpp:13`
- **Belongs to:** `acidcam::KeyMap`
- **Purpose:** Declare loading of key bindings from file.
- **Inputs:** Path to keymap file.
- **Outputs / Return value:** None.
- **Side effects:** Populates internal map in implementation.
- **Preconditions:** Readable mapping file.
- **Postconditions:** Parsed shortcuts available via `checkKey`.
- **Error handling / failure modes:** Implementation logs on open failure.
- **Called by (best-effort):** Startup configuration routines.
- **Calls into (best-effort):** File parsing in `keymap.cpp`.
- **Performance notes:** Linear with file line count.
- **Threading notes:** Mutating map requires external synchronization.
- **Agent modification guidance:** Preserve file format compatibility unless migration path exists.
- **Related symbols:** `setKey`, `checkKey`.

### `KeyMap::setKey`
- **Signature:** `void setKey(int k, int s, int i)`
- **Location:** `source/macos-static/keymap.hpp:14`
- **Belongs to:** `acidcam::KeyMap`
- **Purpose:** Declare insertion/update of one key binding.
- **Inputs:** Key code, shader/filter indices (`s`, `i`).
- **Outputs / Return value:** None.
- **Side effects:** Updates internal hash map.
- **Preconditions:** Key code should map meaningfully to expected keyboard input.
- **Postconditions:** Binding stored/overwritten for normalized key.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** `load`, manual binding customization paths.
- **Calls into (best-effort):** `unordered_map` operations in implementation.
- **Performance notes:** Average O(1).
- **Threading notes:** Non-thread-safe mutation.
- **Agent modification guidance:** Keep normalization rules (`toupper`) consistent with `checkKey`.
- **Related symbols:** `keys`, `checkKey`.

### `KeyMap::checkKey`
- **Signature:** `bool checkKey(int key, int &s, int &i)`
- **Location:** `source/macos-static/keymap.hpp:15`
- **Belongs to:** `acidcam::KeyMap`
- **Purpose:** Declare lookup of mapped action values for a key.
- **Inputs:** Key code and output references for mapped values.
- **Outputs / Return value:** `true` if found; outputs populated when true.
- **Side effects:** Writes to output references.
- **Preconditions:** Caller provides writable references.
- **Postconditions:** On success, `s`/`i` contain mapped pair.
- **Error handling / failure modes:** False return indicates missing mapping.
- **Called by (best-effort):** Keyboard input handlers.
- **Calls into (best-effort):** `unordered_map::find` in implementation.
- **Performance notes:** Average O(1).
- **Threading notes:** Safe for reads only if no concurrent writes.
- **Agent modification guidance:** Preserve bool+out-params contract unless all callsites are migrated.
- **Related symbols:** `setKey`, `load`.
