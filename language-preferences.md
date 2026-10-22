# language — Repo-Local Living Preferences
> Repo-local preferences governed by the Living Documentation Law; the supreme workspace constitution is published at workspace gist/PREFERENCES.md.

## 0. Constitution Link (supreme)
- [preferences.md](https://gist.github.com/vex-graph/4132a6c45cb6d3797c3e8eff2e94035a) — real, Git-ignored workspace file at `../../gist/PREFERENCES.md`, not tracked in Vexspoke or symlinked.
- All universal laws in `../../gist/PREFERENCES.md` are mandatory and binding across the ecosystem.
- This document codifies **exclusive** preferences for `language` (R3 Language Grammars). Grammar/AST semantics stay R3; borrow R2 Vexspoke computation/behavior or Relational Engine memory/storage/native C search contracts. Implemented: callback lexical coordinator and explicit C23 adapter; immutable revisioned document snapshots; validated snapshot-bound token stream; caller-fed project/build-target model and dependency graph; versioned project symbol/reference index. Planned: filesystem discovery, parsing/AST, semantic resolution, automatic invalidation, compiler services and LSP transport. No default allocator replacement or schema migration is implied.

## 1. Repo-Local Law Index (Binding Matrix)

Universal laws are inherited from the canonical `../../gist/PREFERENCES.md` Index; this table indexes the additional laws specific to this repository.

| Law Title | Scope | Enforcement |
| :--- | :--- | :--- |
| **Hot-Swappable Grammar Module Law** | R3 Language Grammars | Mandatory for `language` |
| **Single-Class-Per-File Grammar Law** | R3 Language Grammars | Mandatory for `language` |

## 2. Exclusive Repo-Local Laws (FULL PROSE RESTATEMENT)

### Hot-Swappable Grammar Module Law

#### Definition:
Grammars are independent dynamically loadable modules exporting standard parser vtables and token iterators, swappable at runtime without restarting the language server.

#### The Why:
Enable rapid BNF grammar and AST-builder iteration without recompiling clients.

#### The Rule:
1. **Seam Interface:** Every grammar dylib exports `Grammar_init`, `Grammar_parse`, and `Grammar_destroy` symbols.
2. **Stateless AST:** Parsers output relational AST nodes into caller-provided memory pools.

---

### Single-Class-Per-File Grammar Law

#### Definition:
Grammar rules, lexers, AST node builders, and token definitions each occupy a dedicated `.h`/`.c` pair named for the class in lowercase.

#### The Why:
Sharing a translation unit across token types and rule matchers makes grammar logic unmaintainable.

#### The Rule:
1. **One Class:** Each grammar file pair has exactly one public struct.

---

## 3. Repo-Local Extensions (managed, per the Conflict Triage Law)

;;INTENTION("R3 Grammar Subsystem: hot-swappable dylibs for language parsing; single-class-per-file grammar modules.")

---

## 4. Readiness Cross-Reference (Living Documentation Law)

- Feature readiness matrix: [language](https://gist.github.com/vex-graph/6943f92acb931b25dad1073c46da6ce7#file-language-md).
- Open blockers and deferred decisions: [ecosystem blockers Gist](https://gist.github.com/vex-graph/e921fa188eebbd0c68c4e59646109887).
