You are continuing the documentation harness generation loop for this repository.

## Objective
Process exactly ONE harness batch and stop.

## Scope constraints (strict)
- You may modify ONLY files under `docs/harness/`.
- Do not modify application/source code or any files outside `docs/harness/`.
- Respect existing formatting/style in harness docs.

## Required behavior (Prompt 4 resume executor)
1. Initialize state if missing:
   - Ensure `docs/harness/BATCH_PLAN.md`, `docs/harness/PROGRESS_STATE.md`, and `docs/harness/INDEX.md` exist.
   - If missing, create minimally valid versions so batching can proceed.
2. Resume from current progress state:
   - Read `BATCH_PLAN.md` and `PROGRESS_STATE.md` to determine the next unprocessed batch.
3. Process exactly one batch:
   - Execute work for only the next batch ID (for example `BATCH_00X`).
   - Generate/update documentation files for the files listed in that one batch.
   - Do not start a second batch.
4. Update progress tracking:
   - Update `docs/harness/PROGRESS_STATE.md` with completed batch list, next batch, running totals, and remaining count.
   - Update the coverage/progress section in `docs/harness/INDEX.md`.
5. Stop immediately after the one batch update is complete.

## Completion behavior
- If all batches are already complete, make no unnecessary changes.
- Report completion status clearly instead of attempting another batch.

## Output requirements
At the end, print:
1. A concise human summary of what happened this run.
2. A single machine-readable final line in this exact format:
   - `HARNESS_STATUS: BATCHING_IN_PROGRESS`
   - OR `HARNESS_STATUS: BATCHING_COMPLETE`
   - OR `HARNESS_STATUS: FINALIZED`

The final line must be present exactly once.
