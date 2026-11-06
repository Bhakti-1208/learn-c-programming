# Workspace Guidance

- Keep the course documentation-first and beginner-friendly while preserving technical accuracy.
- Put each new C topic in its own file under `guides/`; update `GUIDE_INDEX.md` when adding or renaming a guide.
- Each guide should include a plain-language explanation, a useful analogy, a small complete C example, a **Behind the scenes** section for core behavior, and practice prompts with hints.
- Use standard C (target C17 unless a guide says otherwise), portable standard-library examples, and compiler commands that enable warnings.
- Explain important hazards such as bounds, object lifetime, input validation, and undefined behavior without presenting unsafe code as a recommended pattern.
- Keep README.md as the study playbook and navigation, not a substitute for the individual guides.
