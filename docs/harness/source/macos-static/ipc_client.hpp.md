# Harness Doc: `source/macos-static/ipc_client.hpp`

## File-level
- **File path:** `source/macos-static/ipc_client.hpp`
- **Purpose of file:** Declares lightweight IPC client entrypoints and `std::cout` redirection helper for non-Windows builds.
- **Dependencies/includes/imports:** POSIX socket headers (`sys/socket.h`, `sys/un.h`, `unistd.h`), `<cstring>`, `<errno.h>`, `<string>`, `<sstream>`, `<iostream>`.
- **Key classes/structs/types/globals/macros:** `CoutRedirect`, `sendString`, `client_main`, global `redirect` pointer.
- **External resources touched:** stdout stream buffer and Unix-domain socket stack (implementation-dependent).
- **Build role:** IPC helper declarations for macOS/static CLI integration.
- **Risks/footguns:** Entire API excluded on `_WIN32`; `CoutRedirect` uses global streambuf replacement with no locking.

## Functions / Methods

### `sendString`
- **Signature:** `void sendString(const std::string &text)`
- **Location:** `source/macos-static/ipc_client.hpp:14`
- **Belongs to:** Global namespace (`#ifndef _WIN32` gated)
- **Purpose:** Declare API to send or emit text via IPC path.
- **Inputs:** Message text.
- **Outputs / Return value:** None.
- **Side effects:** Implementation writes output/IPC channel.
- **Preconditions:** Non-Windows build.
- **Postconditions:** Message emitted according to implementation behavior.
- **Error handling / failure modes:** Implementation-defined.
- **Called by (best-effort):** Client command dispatch routines.
- **Calls into (best-effort):** Defined in `ipc_client.cpp`.
- **Performance notes:** O(message length).
- **Threading notes:** Shared stdout/socket writes require coordination.
- **Agent modification guidance:** Keep cross-platform guard intact.
- **Related symbols:** `client_main`.

### `client_main`
- **Signature:** `int client_main()`
- **Location:** `source/macos-static/ipc_client.hpp:15`
- **Belongs to:** Global namespace (`#ifndef _WIN32` gated)
- **Purpose:** Declare IPC client entrypoint.
- **Inputs:** None.
- **Outputs / Return value:** Process/status code.
- **Side effects:** Implementation-defined.
- **Preconditions:** Non-Windows build.
- **Postconditions:** Client run completes.
- **Error handling / failure modes:** Implementation-defined.
- **Called by (best-effort):** Program startup path when IPC mode enabled.
- **Calls into (best-effort):** Defined in `ipc_client.cpp`.
- **Performance notes:** Depends on implementation.
- **Threading notes:** Depends on implementation.
- **Agent modification guidance:** Keep stable callable signature for existing integration points.
- **Related symbols:** `sendString`.

### `CoutRedirect::CoutRedirect`
- **Signature:** `CoutRedirect()`
- **Location:** `source/macos-static/ipc_client.hpp:20-22`
- **Belongs to:** `CoutRedirect`
- **Purpose:** Redirect `std::cout` to internal stringstream buffer.
- **Inputs:** None.
- **Outputs / Return value:** Constructed redirect object.
- **Side effects:** Replaces `std::cout` streambuf pointer.
- **Preconditions:** Caller accepts global stdout capture impact.
- **Postconditions:** Subsequent `std::cout` writes captured into `buffer`.
- **Error handling / failure modes:** No explicit handling.
- **Called by (best-effort):** Code needing temporary stdout capture.
- **Calls into (best-effort):** `std::cout.rdbuf`.
- **Performance notes:** Redirect setup is O(1).
- **Threading notes:** Not thread-safe against concurrent `std::cout` writers.
- **Agent modification guidance:** Avoid nested redirect instances unless state handling is added.
- **Related symbols:** `~CoutRedirect`, `getString`.

### `CoutRedirect::getString`
- **Signature:** `std::string getString()`
- **Location:** `source/macos-static/ipc_client.hpp:24-28`
- **Belongs to:** `CoutRedirect`
- **Purpose:** Retrieve and clear currently captured stdout content.
- **Inputs:** None.
- **Outputs / Return value:** Captured string data.
- **Side effects:** Clears internal `buffer`.
- **Preconditions:** Object constructed and capturing active.
- **Postconditions:** Buffer reset to empty string.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** IPC polling/forwarding code.
- **Calls into (best-effort):** `stringstream::str` getter/setter.
- **Performance notes:** O(captured bytes) due to string copy.
- **Threading notes:** No internal synchronization.
- **Agent modification guidance:** Keep clear-after-read semantics unless callers are updated.
- **Related symbols:** `buffer` member.

### `CoutRedirect::~CoutRedirect`
- **Signature:** `~CoutRedirect()`
- **Location:** `source/macos-static/ipc_client.hpp:30-32`
- **Belongs to:** `CoutRedirect`
- **Purpose:** Restore original `std::cout` stream buffer.
- **Inputs:** None.
- **Outputs / Return value:** None.
- **Side effects:** Reverts global cout redirection.
- **Preconditions:** Constructor captured `old` streambuf.
- **Postconditions:** `std::cout` writes route to original destination.
- **Error handling / failure modes:** None.
- **Called by (best-effort):** Object destruction/RAII scope exit.
- **Calls into (best-effort):** `std::cout.rdbuf`.
- **Performance notes:** O(1).
- **Threading notes:** Global stream mutation not synchronized.
- **Agent modification guidance:** Keep destructor non-throwing and restoration-focused.
- **Related symbols:** `CoutRedirect()`.

### `redirect`
- **Signature:** `extern CoutRedirect *redirect`
- **Location:** `source/macos-static/ipc_client.hpp:39`
- **Belongs to:** Global namespace.
- **Purpose:** Declare shared pointer to redirection helper.
- **Inputs:** N/A.
- **Outputs / Return value:** N/A.
- **Side effects:** Implementation may manage global capture state.
- **Preconditions:** Definition provided elsewhere if used.
- **Postconditions:** Global access point for redirect instance.
- **Error handling / failure modes:** Link-time failure if missing definition and referenced.
- **Called by (best-effort):** IPC output relay logic.
- **Calls into (best-effort):** N/A.
- **Performance notes:** N/A.
- **Threading notes:** Global mutable pointer requires synchronization.
- **Agent modification guidance:** Prefer ownership-safe wrappers if modernizing.
- **Related symbols:** `CoutRedirect`.
