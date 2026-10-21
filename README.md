# language — R3 grammar & LSP driver provider

Future builds belong to [b](https://github.com/vex-graph/b). No runnable grammar
target exists yet.

## Current State

**Role:** R3 driver — syntax backends for the ecosystem (used by `semicolon`).

**Implemented:** initial value-object scaffolding exists for source ranges,
tokens, symbols and references (`document/source_range.*`, `token/token.*`,
`semantic/symbol.*`, `semantic/reference.*`). A small unified-diff adapter
classifies patch lines for structural highlighting. The value records are
borrowed/value-only; the adapter does not lex changed source text. Neither slice
provides programming-language parsing, symbol resolution, project indexing, or
LSP services.

The first styling/analysis value layer now also exists: `BoundedText` provides
returned, truncation-flagged projections; `TextStyle` carries inherited colors,
bold/italic/dim/reverse/blink/hidden attributes and independently colored
underline/squiggle/strike decorations; `StyleKeyRegistry` joins shared style
keys and language-prefixed adapter keys through one bounded fallback; and
`SyntaxRole`, `SyntaxSpan`, and `Diagnostic` provide language-neutral outputs
for adapters and hosts. The C corpus at
`../../tests/language/adapters/c/corpus.c` records the intended cases (`*` as
multiply/dereference/declarator, macro object/function/generic claims,
`;;` claims versus empty statements, and documentation comments), but no C
lexer or parser consumes it yet.

**Still a blueprint:** no grammar adapter, document store, syntax tree, semantic
resolver, project index, LSP transport or hot-swappable grammar dylib exists.
No runnable repository build target is registered yet.

**Verification performed:** on Apple Silicon macOS, eleven owner tests compile
with GNU C23 and `-Wall -Wextra -Werror`, both normally and with ASan/UBSan.
This is scoped object/diff-classifier evidence only, not platform/runtime
integration proof.

**Platforms proven for language services:** none. The diff classifier is a local
offline parsing helper only, not a complete language service.

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
- `document`: shared source byte-range value (`SourceRange`).
- `token`: shared lexical token kind/range value (`Token`).
- `semantic`: shared symbol identity/kinds (`Symbol`) and use-site
  relationship (`Reference`). Function, class, variable, macro, label and type
  aliases are currently `SymbolKind` variants, not separate classes; global
  declarations use the global scope identity chosen by a future index.
- `adapters/<language>/`: language-specific frontends. `adapters/diff` contains
  the unified-diff line classifier; `adapters/c` remains a reservation only.
- `../../tests/language`: mirrored owner tests and `run.py`; checklist evidence is
  being recorded separately for these Language tests.

## Laws that govern work here
- Constitution: the [canonical preferences.md Gist](https://gist.github.com/vex-graph/4132a6c45cb6d3797c3e8eff2e94035a); one real, Git-ignored workspace `../../gist/PREFERENCES.md`, not a Vexspoke file or symlink.
- Commits land in THIS repo root, one cohesive unit each; never push unless asked.
- One public class per `.h`/`.c` pair, `(*ptr).field` (never `->`), dest-last
  params, `-Wall -Wextra -Werror`.

## Scope and Limitations

**Scope (intended):** R3 language support — per-grammar hot-swappable dylibs and
the tokenizer/AST/highlighter/LSP surface consumed by `semicolon`.

**Deliberately not covered:** no engine integration today; it never includes
R1/R4/R5 or `api-haven` headers; the allocator and IO remain R2 (Relational Engine).

**Known limits and gaps:** owner tests are strict C23 local tests, not yet an
umbrella build target. Diff support only classifies unified Git patch line roles;
there is no changed-code lexer integration, full patch model, C syntax parser,
claim verifier, macro expansion engine, color-theme persistence, inlay-hint
producer, project-wide usages, LSP transport,
consumer integration, or non-macOS platform proof. Earlier blueprint docs still
disagree on the grammar-module ABI (`Lang_*` vs `Grammar_*` vs `LangDriver`);
these objects do not settle that dispute.
