# language — Repo-Local Living Preferences
> Repo-local preferences governed by the Living Documentation Law.
> Universal Supreme Constitution: preferences.md (vexspoke).

## 0. Constitution Link (supreme)
- [preferences.md](https://github.com/vexgraph-ecosystem/vexspoke/blob/main/preferences.md) (canonical, vexspoke) — accessible locally at ../../preferences.md
- All universal laws in `../../../preferences.md` are mandatory and binding across the ecosystem.
- This document codifies **exclusive** preferences that apply uniquely to `language` (R3 Language Grammars).

## 1. Repo-Local Law Index (Binding Matrix)

Universal laws are inherited from the canonical `../../../preferences.md` Index; this table indexes the additional laws specific to this repository.

| Law Title | Scope | Enforcement |
| :--- | :--- | :--- |
| **Hot-Swappable Grammar Module Law** | R3 Language Grammars | Mandatory for `language` |
| **Single-Class-Per-File Grammar Law** | R3 Language Grammars | Mandatory for `language` |

## 2. Exclusive Repo-Local Laws (FULL PROSE RESTATEMENT)

### Hot-Swappable Grammar Module Law

#### Definition:
Language grammars are compiled as independent, dynamically loadable modules exporting standard parser vtables and token iterators. Grammars can be updated or swapped at runtime without restarting the language server.

#### The Why:
Language development requires rapid iteration on BNF grammars and AST builders without recompiling client environments.

#### The Rule:
1. **Seam Interface:** Every grammar dylib exports standard `Grammar_init`, `Grammar_parse`, and `Grammar_destroy` symbols.
2. **Stateless AST:** Parsers output relational AST nodes into caller-provided memory pools.

---

### Single-Class-Per-File Grammar Law

#### Definition:
Grammar rules, lexers, AST node builders, and token definitions each reside in their own dedicated `.h`/`.c` file pair matching the class name in lowercase.

#### The Why:
Grammar parsing logic easily becomes unmaintainable when multiple token types and rule matchers share a single translation unit.

#### The Rule:
1. **One Class:** Exactly one public struct per grammar file pair.

---

## 3. Repo-Local Extensions (managed, per the Conflict Triage Law)

;;INTENTION("R3 Grammar Subsystem: hot-swappable dylibs for language parsing; single-class-per-file grammar modules.")

---

## 4. Readiness Cross-Reference (Living Documentation Law)

- Feature readiness matrix tracked in [`../../_repositories/.ecosystem/language.md`](../../_repositories/.ecosystem/language.md) (rendered as `[[language]]` wiki page).
