#ifndef LANGUAGE_DOCUMENT_SOURCE_RANGE_H
#define LANGUAGE_DOCUMENT_SOURCE_RANGE_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// SourceRange is a document-relative half-open byte span. It carries no text
// pointer and does not convert offsets to UTF-8 scalars, lines, or LSP columns.
typedef struct SourceRange {
    uint32_t documentId; // owner-assigned document identity; zero is unbound
    uint64_t startByte;  // inclusive byte offset into one immutable snapshot
    uint64_t endByte;    // exclusive byte offset; ordered by isValid
} SourceRange;

// Construct the zero value, an empty range for one document, or a complete
// half-open range. The complete constructor stores values without validation.
SourceRange SourceRange_0(void);
SourceRange SourceRange_1(uint32_t documentId);
SourceRange SourceRange_3(uint32_t documentId, uint64_t startByte, uint64_t endByte);
// Dispatch the supported arities: SourceRange(), SourceRange(documentId), or
// SourceRange(documentId, startByte, endByte). Other arities are compile errors.
#define SourceRange(...) SOURCE_RANGE_SELECT(_, ##__VA_ARGS__, SourceRange_3, SourceRange_invalid_arity, SourceRange_1, SourceRange_0)(__VA_ARGS__)
#define SOURCE_RANGE_SELECT(_0, _1, _2, _3, NAME, ...) NAME
// Return the all-zero identity. Validity requires nonzero documentId and
// startByte <= endByte; setters do not maintain this cross-field invariant.
SourceRange SourceRange_zero(void);
bool SourceRange_isValid(const SourceRange *self);
// Symmetric field accessors. Null getters return zero; null setters do nothing.
uint32_t SourceRange_getDocumentId(const SourceRange *self);
void SourceRange_setDocumentId(SourceRange *self, uint32_t value);
uint64_t SourceRange_getStartByte(const SourceRange *self);
void SourceRange_setStartByte(SourceRange *self, uint64_t value);
uint64_t SourceRange_getEndByte(const SourceRange *self);
void SourceRange_setEndByte(SourceRange *self, uint64_t value);

#endif
