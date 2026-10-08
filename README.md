# language — R3 grammar & LSP driver provider

## CLion: CMake is IDE metadata only

Open this repository root as a CMake project. `CMakeLists.txt` is an IDE-only
blueprint entry: there are no production sources or C23 source targets yet,
so there is nothing to provide semantic diagnostics or inlay hints for.
No fake declarations, dependency downloads, linking or application runner are
wired into it. IDE appearance is user-verified.

Future builds belong to [b](https://github.com/vex-graph/b). No runnable grammar
target or standalone runtime build is claimed by this metadata entry.

## Current State

**Role:** R3 driver — syntax backends for the ecosystem (used by `semicolon`).

**Implemented and proven:** nothing. This is a **source-free blueprint**: the
repository holds only `README.md`, `CONTRIBUTING.md`, `LICENSE`,
`language-preferences.md`, `.gitignore` and an IDE-only `LANGUAGES NONE`
`CMakeLists.txt`. There is no `src/`, header, grammar dylib or test.

**Specified only:** the `Language` contract (`Lang_tokenize/parse/highlight/…`),
the hot-swappable grammar-module ABI, the tokenizer, relational AST, highlighter,
scope resolver, formatter, LSP bridge and the ~30 grammars.

**Platforms proven:** none (no build, no binary).

## What it is
`language` owns the `Language` contract (`Lang_tokenize/parse/highlight/...`).
Each grammar ships as a hot-swappable dylib loaded through `hotcwap` R1 —
adding a language never rebuilds the IDE, it drops in a module.

## Depends on (Vertical Integration Law allowlist)
R3 may borrow either R2 public contract: Vexspoke CPU computation/behavior or
Relational Engine memory/storage, stable rows, variable bindings and native C
search over Rust-owned spans (`+ graphvex` for GPU-backed highlighting). Never
R1/R4/R5 or `api-haven` headers. This blueprint has no implemented engine
integration. Migration is staged; Vexspoke's existing memory/container ABI and
default allocator remain. R1 owns lifetimes/residency; no C/Rust atomic-layout
compatibility or automatic schema migration is assumed. GPU dispatch stays R3.

## Layout
- Grammars (future): one directory per language, each building its own dylib.
- Tests: the shared `../../../tests` repo will host a `tests/language/` partition
  (mirrored per unit, the Test Tree Mirror Law); no test file lives inside this
  repo's source directories (the Test Segregation Law).

## Laws that govern work here
- Constitution: the [canonical preferences.md Gist](https://gist.github.com/vex-graph/4132a6c45cb6d3797c3e8eff2e94035a); one real, Git-ignored workspace-root `../../../preferences.md`, not a Vexspoke file or symlink.
- Commits land in THIS repo root, one cohesive unit each; never push unless asked.
- One public class per `.h`/`.c` pair, `(*ptr).field` (never `->`), dest-last
  params, `-Wall -Wextra -Werror`.

## Scope and Limitations

**Scope (intended):** R3 language support — per-grammar hot-swappable dylibs and
the tokenizer/AST/highlighter/LSP surface consumed by `semicolon`.

**Deliberately not covered:** no engine integration today; it never includes
R1/R4/R5 or `api-haven` headers; the allocator and IO remain R2 (Relational Engine).

**Known limits and gaps:** zero implementation — every contract above is
specification only, with no platform proven and no `tests/language/` partition.
Interface spellings disagree across the repo's own docs (`Lang_*` vs `Grammar_*`
vs a `LangDriver` vtable); no source exists to arbitrate, so none is canonical.
