# Contributions & Engineering Manifesto (language)

This project is a strictly solo development process conducted in tight pair-programming partnership with an AI coding assistant.

It serves as an architectural manifesto for **Level 3 Language Grammars and Hot-Swappable Dylibs**: grammar parsing modules, tokens, AST generation, and single-class-per-file grammar units in pure C23.

---

## 1. The AI-First Architecture Manifesto & Boilerplate Defense

This codebase strictly enforces the verbose, explicit boilerplate required across the `vexgraph` ecosystem:
- Strict prohibition of arrow syntax (`p->field` is banned; only explicit `(*p).field` is permitted).
- Single Class Per File (the Java Law: one public `typedef struct` per `.h`/`.c` pair).
- Arity-overloaded explicit constructor dispatch macros (`Class_0()`, `Class_1()`).
- Complete, symmetric getters and setters for all struct fields.
- Strict dest-last parameter ordering `(a, b, dest)`.
- Two-layer member access cap (`(*layer1).layer2` maximum).
- Exhaustive `;;OVERVIEW` blueprints mirrored at the top of every implementation file.

---

## 2. Sanity Warning for External Contributors

> [!WARNING]
> **SANITY NOTICE FOR EXTERNAL CONTRIBUTORS**
> This repository is not designed for traditional C conveniences, casual hacking, or stylistic shortcuts. It is an unapologetic, machine-verifiable manifesto of AI-augmented systems architecture.
>
> If you do not approve of this architecture or cannot find peace with this philosophy, consider leaving this repository for your own sanity.
>
> We do not accept Pull Requests, issues, or unsolicited stylistic refactors attempting to re-introduce `->`, combine multiple grammar classes into one file, or bypass explicit getters/setters. Upstream is maintained exclusively by the author and the AI agent.

---

## 3. Supreme Living Document: `../../../preferences.md` & Repo-Local Preferences

All architectural rules and style invariants are governed by the central constitution:

- **[preferences.md](https://github.com/vexgraph-dev/vexspoke/blob/main/preferences.md)** (tracked in `vexspoke`, accessible locally at `../../../preferences.md`)
- **[language-preferences.md](language-preferences.md)** (repo-local mirror binding language)

Whenever preferences or conventions evolve, `../../../preferences.md` and `language-preferences.md` are updated and committed locally in the same cycle (the Living Preferences Law / Zero Drift).
