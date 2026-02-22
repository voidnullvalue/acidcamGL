# Harness Automation Loop (One Batch Per Run)

This document explains the GitHub Actions automation loop for harness generation.

## What it does

The workflow `.github/workflows/harness-batch-loop.yml` runs Codex in non-interactive mode and processes **exactly one batch** per run using prompt logic in `.github/codex-prompts/harness_resume_batch.md`.

Each run:
1. Resumes harness state from existing docs.
2. Processes one next batch only.
3. Updates `docs/harness/PROGRESS_STATE.md` and coverage information in `docs/harness/INDEX.md`.
4. Commits only harness-related doc changes.
5. Opens a PR for review.

If no changes are made (for example, all batches are complete), it exits successfully without opening a PR.

## Required secrets

- `OPENAI_API_KEY` (required): API key used by `openai/codex-action`.
- `GITHUB_TOKEN` (automatic): used to push branch and create PR.

## Manual run

1. Go to **Actions** in GitHub.
2. Select **Harness Batch Loop**.
3. Click **Run workflow**.
4. Wait for job completion.

## Expected loop

Repeat this cycle until complete:

1. Run workflow.
2. Workflow creates a docs-only PR for one batch.
3. Review PR content.
4. Merge PR manually.
5. Run workflow again.

This keeps changes small and reviewable.

## Completion detection

The loop considers batching complete when progress state indicates completion, such as:
- `ALL BATCHES COMPLETE`, or
- `Remaining batches: **0**`, or
- `Next batch ID: **None**`

When complete:
- The workflow logs completion and does not open a new PR.

## Safety guardrails

- Workflow permissions are minimal: `contents: write`, `pull-requests: write`.
- A validation step fails the run if any changed files are outside:
  - `docs/harness/**`
  - `.github/codex-prompts/**`
- No auto-merge is enabled by default.
- Optional schedule trigger is present but commented out.

## Finalization pass after all batches

After batching completes, run a final manual Codex/doc pass focused on final polish:
- verify aggregate counts,
- ensure `INDEX.md` reflects full coverage,
- normalize wording/formatting,
- confirm progress state is final.

Keep this as a separate, explicit run/PR so finalization is isolated from per-batch updates.
