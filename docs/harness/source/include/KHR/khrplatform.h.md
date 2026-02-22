# Harness Doc: `source/include/KHR/khrplatform.h`

## File-level
- **File path:** `source/include/KHR/khrplatform.h`
- **Purpose of file:** Provides Khronos platform ABI typedefs, calling-convention macros, feature flags, and a boolean enum used by GL/EGL/OpenCL headers.
- **Dependencies/includes/imports:** Conditional compiler/platform macros; `<stdint.h>` or `<inttypes.h>` on most targets.
- **Key classes/structs/types/globals/macros:** `KHRONOS_APICALL`, `KHRONOS_APIENTRY`, `KHRONOS_APIATTRIBUTES`; integer typedef family (`khronos_int32_t`, etc.); `khronos_boolean_enum_t`.
- **External resources touched:** None (header-only type/macro declarations).
- **Build role:** Third-party compatibility header consumed by graphics API headers.
- **Risks/footguns:** Platform-specific ABI mismatches if edited; should track upstream Khronos definitions.

## Symbols

### Enum `khronos_boolean_enum_t`
- **Signature:** `typedef enum { KHRONOS_FALSE = 0, KHRONOS_TRUE = 1, KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM } khronos_boolean_enum_t`
- **Location:** `source/include/KHR/khrplatform.h:305-309`
- **Belongs to:** Global type namespace (C typedef enum).
- **Purpose:** Defines a 32-bit-safe enum-backed boolean type for Khronos APIs that represent booleans as enums.
- **Inputs:** N/A
- **Outputs / Return value:** N/A
- **Side effects:** None.
- **Preconditions:** Consumers include this header before using Khronos boolean enum types.
- **Postconditions:** Boolean constants are available with fixed, cross-platform values.
- **Error handling / failure modes:** None in this declaration.
- **Called by (best-effort):** N/A (type declaration).
- **Calls into (best-effort):** N/A.
- **Performance notes:** Compile-time only.
- **Threading notes:** N/A.
- **Agent modification guidance:** Treat as vendored upstream; avoid local edits unless syncing with Khronos release.
- **Related symbols:** `KHRONOS_MAX_ENUM`, `KHRONOS_FALSE`, `KHRONOS_TRUE`.

## Function/Method Inventory
- No functions or methods are defined in this header; it is macro/type-focused.
