# Harness Doc: `source/ipc_client.cpp`

## File-level
- **File path:** `source/ipc_client.cpp`
- **Purpose of file:** Implements minimal non-Windows IPC client helpers and diagnostic error output.
- **Dependencies/includes/imports:** `ipc_client.hpp`; C stdio (`printf`, `fflush`), `errno`, C string error text.
- **Key classes/structs/types/globals/macros:** `SOCK_PATH`, `BUF_SIZE`, `sockfd`; functions `client_main`, `sendString`, `error`.
- **External resources touched:** Stdout/stderr streams; potential future Unix socket path `/tmp/testsock`.
- **Build role:** Unix-only implementation unit for client output plumbing.
- **Risks/footguns:** Currently stub-like; flushes `stdin` (non-portable/undefined behavior concerns).

## Symbols

### Function `client_main`
- **Signature:** `int client_main()`
- **Location:** `source/ipc_client.cpp:11-13`
- **Belongs to:** Global namespace.
- **Purpose:** Placeholder entry point for client-side IPC logic.
- **Inputs:** None.
- **Outputs / Return value:** Always `0` in current implementation.
- **Side effects:** None currently.
- **Preconditions:** Non-Windows compilation.
- **Postconditions:** Immediate successful return.
- **Error handling / failure modes:** None implemented.
- **Called by (best-effort):** Runtime paths that want a client mode.
- **Calls into (best-effort):** None.
- **Performance notes:** Constant-time no-op.
- **Threading notes:** Stateless as implemented.
- **Agent modification guidance:** Safe extension point for real IPC connect/send/receive behavior.
- **Related symbols:** `SOCK_PATH`, `sockfd`, `sendString`.

### Function `sendString`
- **Signature:** `void sendString(const std::string &text)`
- **Location:** `source/ipc_client.cpp:15-19`
- **Belongs to:** Global namespace.
- **Purpose:** Emits text directly to stdout and flushes standard streams.
- **Inputs:** `text` payload.
- **Outputs / Return value:** None.
- **Side effects:** Writes to stdout; flushes stdout and stdin.
- **Preconditions:** Valid C stdio streams.
- **Postconditions:** Data is pushed to output stream buffers.
- **Error handling / failure modes:** No return/error reporting.
- **Called by (best-effort):** IPC/console forwarding paths.
- **Calls into (best-effort):** `printf`, `fflush`.
- **Performance notes:** O(n) write cost on text length.
- **Threading notes:** Concurrent writes may interleave.
- **Agent modification guidance:** If converted to socket send, keep old behavior compatibility in mind.
- **Related symbols:** `error`.

### Function `error`
- **Signature:** `void error(const std::string &text, bool err_no = true)`
- **Location:** `source/ipc_client.cpp:21-24`
- **Belongs to:** Global namespace (file-local declaration + definition).
- **Purpose:** Prints an error message and optionally appends `errno` text.
- **Inputs:** `text` message; `err_no` toggle.
- **Outputs / Return value:** None.
- **Side effects:** Writes to stderr/stdout.
- **Preconditions:** `errno` meaningful when `err_no` is true.
- **Postconditions:** Human-readable diagnostics emitted.
- **Error handling / failure modes:** Diagnostic-only helper; does not throw or propagate status.
- **Called by (best-effort):** Intended IPC failure sites (none currently in this TU).
- **Calls into (best-effort):** `std::cerr`, `strerror(errno)`.
- **Performance notes:** Minimal formatting overhead.
- **Threading notes:** Logging output may interleave.
- **Agent modification guidance:** Prefer consistent stream use (stderr vs stdout) if extending.
- **Related symbols:** `errno`, `sendString`.
