# language — R3 grammar & LSP driver provider

**Role:** R3 Driver — syntax backends for the ecosystem (used by `semicolon`).
**Status:** stub (LICENSE only; contract defined, no grammars yet).

## What it is
`language` owns the `Language` contract (`Lang_tokenize/parse/highlight/...`).
Each grammar ships as a hot-swappable dylib loaded through `hotcwap` R1 —
adding a language never rebuilds the IDE, it drops in a module.

## Depends on (Vertical Integration Law allowlist)
`vexspoke` only (`+ graphvex` for GPU-backed highlighting). Never engines,
never `darling`/`api-haven` headers.

## Layout
- Grammars (future): one directory per language, each building its own dylib.
- Tests: umbrella `tests/` has no `language/` partition yet; until then keep
  seam tests in-repo under `tests/` (never inside source dirs, per the Test
  Segregation Law).

## Laws that govern work here
- Constitution: `../../preferences.md` (umbrella symlink → `ecosystem/vexspoke/preferences.md`).
- Commits land in THIS repo root, one cohesive unit each; never push unless asked.
- One public class per `.h`/`.c` pair, `(*ptr).field` (never `->`), dest-last
  params, `-Wall -Wextra -Werror`.
