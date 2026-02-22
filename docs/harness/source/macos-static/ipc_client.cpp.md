# Harness Doc: `source/macos-static/ipc_client.cpp`

## File-level
- **File path:** `source/macos-static/ipc_client.cpp`
- **Purpose of file:** Provides minimal non-Windows IPC client stubs and error/output helpers.
- **Dependencies/includes/imports:** `ipc_client.hpp` (when `_WIN32` is not defined).
- **Key classes/structs/types/globals/macros:** `SOCK_PATH`, `BUF_SIZE`, `sockfd`, `client_main`, `sendString`, `error`.
- **External resources touched:** stdout/stderr streams; POSIX errno string APIs.
- **Build role:** IPC client implementation for macOS/static build target.
- **Risks/footguns:** `fflush(stdin)` is undefined behavior in standard C; socket globals currently unused.

## Functions / Methods

### `client_main`
- **Signature:** `int client_main()`
- **Location:** `source/macos-static/ipc_client.cpp:11-13`
- **Belongs to:** Global namespace (`#ifndef _WIN32`)
- **Purpose:** Stub entrypoint for IPC client execution.
- **Inputs:** None.
- **Outputs / Return value:** Always returns `0`.
- **Side effects:** None.
- **Preconditions:** Non-Windows compilation.
- **Postconditions:** Immediate successful return.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** CLI startup path if IPC mode invoked.
- **Calls into (best-effort):** None.
- **Performance notes:** Constant-time no-op.
- **Threading notes:** Thread-safe due to no state changes.
- **Agent modification guidance:** If implementing full IPC, preserve signature and return-code conventions.
- **Related symbols:** `sendString`, `sockfd`.

### `sendString`
- **Signature:** `void sendString(const std::string &text)`
- **Location:** `source/macos-static/ipc_client.cpp:15-19`
- **Belongs to:** Global namespace (`#ifndef _WIN32`)
- **Purpose:** Emit text to stdout and flush streams.
- **Inputs:** `text` message.
- **Outputs / Return value:** None.
- **Side effects:** Writes to stdout; flushes stdout and stdin.
- **Preconditions:** stdout available.
- **Postconditions:** Message sent to standard output stream.
- **Error handling / failure modes:** No explicit write/flush result checking.
- **Called by (best-effort):** IPC or command output paths.
- **Calls into (best-effort):** `printf`, `fflush`.
- **Performance notes:** O(message length).
- **Threading notes:** Concurrent writes may interleave.
- **Agent modification guidance:** Consider removing `fflush(stdin)` for standards compliance.
- **Related symbols:** `error`.

### `error`
- **Signature:** `void error(const std::string &text, bool err_no = true)`
- **Location:** `source/macos-static/ipc_client.cpp:21-24`
- **Belongs to:** Global namespace (internal helper)
- **Purpose:** Print formatted error message and optional `errno` text.
- **Inputs:** Message text; flag controlling errno print.
- **Outputs / Return value:** None.
- **Side effects:** Writes to stderr/stdout.
- **Preconditions:** I/O streams available.
- **Postconditions:** Error diagnostics emitted.
- **Error handling / failure modes:** No propagation beyond logging.
- **Called by (best-effort):** Future/partial IPC operations in this TU.
- **Calls into (best-effort):** `strerror(errno)`.
- **Performance notes:** O(message length).
- **Threading notes:** Shared stream output not synchronized.
- **Agent modification guidance:** Keep helper local or namespace-scope if expanding IPC logic.
- **Related symbols:** `client_main`, `sendString`.
