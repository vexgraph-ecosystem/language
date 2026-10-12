# Unified diff adapter

The initial adapter classifies a unified Git patch one line at a time into shared
`TokenKind` values: file header, metadata, hunk, addition, removal, and context.
It preserves the caller's `inHunk` state and output token on invalid input, and
reports rejected lines through `THROW`.

This is structural patch highlighting only. Added and removed source text is not
lexed by the embedded programming-language adapter yet. Combined diffs, binary
payload interpretation, word-level change ranges, line-number mapping, and
consumer/UI color integration are not implemented. See the owner at
`../../../../tests/language/adapters/diff/diff_adapter_test.c`.
