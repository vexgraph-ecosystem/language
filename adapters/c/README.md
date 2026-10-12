# C language adapter (planned)

This directory is reserved for the C-family adapter. The common model currently
has source ranges, lexical token records, symbols, and references in sibling
subsystems. No C lexer, parser, project scanner, preprocessor, or semantic
resolver is implemented here yet.

The adapter should map C declarations and uses into the shared model, retaining
macro expansion and conditional-compilation provenance where available. It must
not claim complete references when preprocessing configuration is unknown.
