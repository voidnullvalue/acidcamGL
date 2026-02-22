# Harness Doc: `source/ipc_client.hpp`

## File-level
- **File path:** `source/ipc_client.hpp`
- **Purpose of file:** Declares non-Windows IPC client helper API and a small `std::cout` redirection utility.
- **Dependencies/includes/imports:** I/O streams, Unix socket headers, string/stringstream support (guarded by `#ifndef _WIN32`).
- **Key classes/structs/types/globals/macros:** `CoutRedirect`; extern `CoutRedirect *redirect`; `sendString`, `client_main` declarations.
- **External resources touched:** Unix domain sockets (through included system headers, call sites in implementation).
- **Build role:** Public declaration header for Linux/Unix IPC client helpers.
- **Risks/footguns:** API excluded on Windows; `CoutRedirect` globally mutates `std::cout` buffer while alive.

## Symbols

### Function `sendString`
- **Signature:** `void sendString(const std::string &text)`
- **Location:** `source/ipc_client.hpp:14`
- **Belongs to:** Global namespace.
- **Purpose:** Declares text transport/output function used by IPC client paths.
- **Inputs:** `text` payload.
- **Outputs / Return value:** None.
- **Side effects:** Writes text in implementation.
- **Preconditions:** Non-Windows build path.
- **Postconditions:** Payload emitted by implementation routine.
- **Error handling / failure modes:** Delegated to implementation.
- **Called by (best-effort):** IPC-facing call sites.
- **Calls into (best-effort):** Implementation in `ipc_client.cpp`.
- **Performance notes:** Linear in payload size.
- **Threading notes:** Underlying stream writes may interleave across threads.
- **Agent modification guidance:** Keep declaration in sync with implementation signature.
- **Related symbols:** `client_main`.

### Function `client_main`
- **Signature:** `int client_main()`
- **Location:** `source/ipc_client.hpp:15`
- **Belongs to:** Global namespace.
- **Purpose:** Declares IPC client entry-point wrapper.
- **Inputs:** None.
- **Outputs / Return value:** Status code.
- **Side effects:** Implementation-defined startup/IPC actions.
- **Preconditions:** Non-Windows build path.
- **Postconditions:** Returns process/status code from IPC logic.
- **Error handling / failure modes:** Implementation-specific.
- **Called by (best-effort):** Main/runtime dispatch code.
- **Calls into (best-effort):** Implementation in `ipc_client.cpp`.
- **Performance notes:** Minimal in current implementation.
- **Threading notes:** No intrinsic synchronization.
- **Agent modification guidance:** Maintain ABI for callers.
- **Related symbols:** `sendString`.

### Class `CoutRedirect`
- **Signature:** `class CoutRedirect`
- **Location:** `source/ipc_client.hpp:17-37`
- **Belongs to:** Global namespace.
- **Purpose:** Temporarily redirects `std::cout` into an internal string buffer for capture.
- **Inputs:** Constructor takes no args; methods use internal state.
- **Outputs / Return value:** `getString()` returns captured output and clears buffer.
- **Side effects:** Constructor swaps `std::cout` streambuf; destructor restores original streambuf.
- **Preconditions:** `std::cout` must be valid and streambuf swapping must be acceptable in process context.
- **Postconditions:** After destruction, `std::cout` points back to original buffer.
- **Error handling / failure modes:** No explicit handling; misuse can lead to surprising logging behavior.
- **Called by (best-effort):** Logging capture paths.
- **Calls into (best-effort):** `std::cout.rdbuf`, `std::stringstream` APIs.
- **Performance notes:** Buffer copies on `getString`; overhead proportional to captured output.
- **Threading notes:** Not thread-safe globally because it mutates shared `std::cout` state.
- **Agent modification guidance:** Preserve RAII restore behavior in destructor.
- **Related symbols:** `redirect`.

### Method `CoutRedirect::CoutRedirect`
- **Signature:** `CoutRedirect()`
- **Location:** `source/ipc_client.hpp:20-22`
- **Belongs to:** `CoutRedirect`.
- **Purpose:** Captures original `std::cout` streambuf and redirects output to internal buffer.
- **Inputs:** None.
- **Outputs / Return value:** N/A (constructor).
- **Side effects:** Global `std::cout` redirection.
- **Preconditions:** Object lifetime should enclose redirection window.
- **Postconditions:** `old` stores previous streambuf.
- **Error handling / failure modes:** None explicit.
- **Called by / Calls into (best-effort):** Object construction / `std::cout.rdbuf`.
- **Performance notes:** Constant-time pointer swap.
- **Threading notes:** Process-global effect.
- **Agent modification guidance:** Do not remove restore path dependency.
- **Related symbols:** `~CoutRedirect`.

### Method `CoutRedirect::getString`
- **Signature:** `std::string getString()`
- **Location:** `source/ipc_client.hpp:24-28`
- **Belongs to:** `CoutRedirect`.
- **Purpose:** Returns buffered text and resets the capture buffer.
- **Inputs:** None.
- **Outputs / Return value:** Captured string contents.
- **Side effects:** Clears internal stringstream content.
- **Preconditions:** Object is alive.
- **Postconditions:** Internal buffer emptied.
- **Error handling / failure modes:** None explicit.
- **Called by / Calls into (best-effort):** Callers polling capture / `stringstream::str`.
- **Performance notes:** Copies buffered string.
- **Threading notes:** No locking around buffer operations.
- **Agent modification guidance:** Preserve clear-after-read behavior.
- **Related symbols:** `buffer` field.

### Method `CoutRedirect::~CoutRedirect`
- **Signature:** `~CoutRedirect()`
- **Location:** `source/ipc_client.hpp:30-32`
- **Belongs to:** `CoutRedirect`.
- **Purpose:** Restores the original `std::cout` stream buffer.
- **Inputs:** None.
- **Outputs / Return value:** N/A.
- **Side effects:** Reverts global output routing.
- **Preconditions:** `old` contains a previously captured buffer pointer.
- **Postconditions:** `std::cout` no longer redirected to internal buffer.
- **Error handling / failure modes:** None explicit.
- **Called by / Calls into (best-effort):** Object teardown / `std::cout.rdbuf`.
- **Performance notes:** Constant-time pointer swap.
- **Threading notes:** Process-global effect; coordination required in multi-threaded logs.
- **Agent modification guidance:** Keep destructor non-throwing and restoration intact.
- **Related symbols:** Constructor.
