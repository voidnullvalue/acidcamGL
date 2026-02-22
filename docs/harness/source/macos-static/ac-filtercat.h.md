# Harness Doc: `source/macos-static/ac-filtercat.h`

## File-level
- **File path:** `source/macos-static/ac-filtercat.h`
- **Purpose of file:** Declares filter-category lists, map metadata container, and initialization/sort entry points for macOS-static build.
- **Dependencies/includes/imports:** STL `vector`, `string`, `unordered_map`; random engine declaration.
- **Key classes/structs/types/globals/macros:** `ac::FilterItem`; extern filter category vectors/arrays; `filter_menu_map`; `SortFilters`, `init_filter_menu_map`.
- **External resources touched:** None directly (declarations only).
- **Build role:** Shared declaration header for filter catalog/grouping infrastructure.
- **Risks/footguns:** Many extern globals imply global mutable shared state across translation units.

## Symbols

### Class `ac::FilterItem`
- **Signature:** `class FilterItem`
- **Location:** `source/macos-static/ac-filtercat.h:51-63`
- **Belongs to:** Namespace `ac`.
- **Purpose:** Stores a pointer to a filter-name vector plus menu label metadata for category mapping.
- **Inputs:** Constructor accepts vector reference and menu name.
- **Outputs / Return value:** Copy/assignment preserve pointer/name fields.
- **Side effects:** Pointer aliasing to externally owned vector.
- **Preconditions:** Referenced vectors must outlive `FilterItem` instances.
- **Postconditions:** `menu_list` and `menu_name` initialized/copied.
- **Error handling / failure modes:** Dangling pointer risk if source vector lifetime ends.
- **Called by (best-effort):** Filter catalog setup logic.
- **Calls into (best-effort):** STL copy/assignment operations.
- **Performance notes:** Lightweight copies (pointer + string).
- **Threading notes:** Shared mutable vectors require synchronization in concurrent contexts.
- **Agent modification guidance:** Prefer explicit ownership comments if extending to avoid lifetime bugs.
- **Related symbols:** `filter_menu_map`, `init_filter_menu_map`.

### Method `FilterItem::FilterItem()`
- **Signature:** `FilterItem() = default`
- **Location:** `source/macos-static/ac-filtercat.h:53`
- **Belongs to:** `ac::FilterItem`.
- **Purpose:** Default-constructs item fields.
- **Inputs/Outputs / Return value:** N/A.
- **Side effects:** None.
- **Preconditions:** None.
- **Postconditions:** Members default-initialized.
- **Error handling / failure modes:** None explicit.
- **Called by / Calls into (best-effort):** STL/container construction.
- **Performance notes:** Constant-time.
- **Threading notes:** N/A.
- **Agent modification guidance:** Keep trivial if used in containers.
- **Related symbols:** Parameterized constructor.

### Method `FilterItem::FilterItem(std::vector<std::string> &, std::string)`
- **Signature:** `FilterItem(std::vector<std::string> &v, std::string name)`
- **Location:** `source/macos-static/ac-filtercat.h:56`
- **Belongs to:** `ac::FilterItem`.
- **Purpose:** Binds item to an external menu list and captures menu label.
- **Inputs:** Vector reference `v`, menu name `name`.
- **Outputs / Return value:** N/A.
- **Side effects:** Stores pointer alias to caller-owned vector.
- **Preconditions:** `v` lifetime exceeds this object's usage.
- **Postconditions:** `menu_list` points to `v`, `menu_name` copied/moved from parameter.
- **Error handling / failure modes:** Potential dangling pointer if lifetime contract violated.
- **Called by / Calls into (best-effort):** Filter map initialization.
- **Performance notes:** O(name length) for string copy.
- **Threading notes:** Pointer target may be shared.
- **Agent modification guidance:** Consider const-correctness or smart pointers only with broad refactor.
- **Related symbols:** copy constructor, assignment operator.

### Method `FilterItem::FilterItem(const FilterItem &)`
- **Signature:** `FilterItem(const FilterItem &f)`
- **Location:** `source/macos-static/ac-filtercat.h:57`
- **Belongs to:** `ac::FilterItem`.
- **Purpose:** Copies pointer and menu-name metadata.
- **Inputs:** Source object `f`.
- **Outputs / Return value:** N/A.
- **Side effects:** New instance aliases same `menu_list` pointer.
- **Preconditions:** Source points to valid vector.
- **Postconditions:** Shallow pointer copy semantics preserved.
- **Error handling / failure modes:** Same aliasing lifetime risks.
- **Called by / Calls into (best-effort):** Container copies.
- **Performance notes:** O(name length).
- **Threading notes:** Shared pointee access concerns.
- **Agent modification guidance:** Be aware this is intentionally shallow copy behavior.
- **Related symbols:** assignment operator.

### Method `FilterItem::operator=`
- **Signature:** `FilterItem &operator=(const FilterItem &f)`
- **Location:** `source/macos-static/ac-filtercat.h:58-62`
- **Belongs to:** `ac::FilterItem`.
- **Purpose:** Assigns pointer/name fields from another item.
- **Inputs:** Source `f`.
- **Outputs / Return value:** Reference to `*this`.
- **Side effects:** Overwrites existing metadata.
- **Preconditions:** Source remains valid for pointer alias semantics.
- **Postconditions:** Destination mirrors source fields.
- **Error handling / failure modes:** No self-assignment guards needed for current fields.
- **Called by / Calls into (best-effort):** Container assignment operations.
- **Performance notes:** O(name length).
- **Threading notes:** Unsynchronized shared state.
- **Agent modification guidance:** Keep return `*this` for assignment chaining.
- **Related symbols:** copy constructor.

### Function `ac::SortFilters`
- **Signature:** `void SortFilters()`
- **Location:** `source/macos-static/ac-filtercat.h:85`
- **Belongs to:** Namespace `ac`.
- **Purpose:** Declared sorter for filter collections.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Expected to reorder global vectors/map.
- **Preconditions:** Filter lists initialized.
- **Postconditions:** Sorted ordering applied.
- **Error handling / failure modes:** Implementation-defined.
- **Called by / Calls into (best-effort):** Filter bootstrap code.
- **Performance notes:** Likely O(n log n) depending on implementation.
- **Threading notes:** Mutating global containers.
- **Agent modification guidance:** Keep deterministic ordering for UI consistency.
- **Related symbols:** `init_filter_menu_map`.

### Function `ac::init_filter_menu_map`
- **Signature:** `void init_filter_menu_map()`
- **Location:** `source/macos-static/ac-filtercat.h:86`
- **Belongs to:** Namespace `ac`.
- **Purpose:** Declared initializer for menu-name to filter-category mapping.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Expected population of `filter_menu_map` and related vectors.
- **Preconditions:** Globals available.
- **Postconditions:** Filter menu map ready for lookup/use.
- **Error handling / failure modes:** Implementation-defined.
- **Called by / Calls into (best-effort):** Startup/configuration paths.
- **Performance notes:** Linear to number of categories/filters.
- **Threading notes:** Should run before concurrent reads.
- **Agent modification guidance:** Preserve key naming to avoid UI/config breakage.
- **Related symbols:** `filter_menu_map`, `FilterItem`.
