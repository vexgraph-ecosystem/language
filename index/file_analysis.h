#ifndef LANGUAGE_INDEX_FILE_ANALYSIS_H
#define LANGUAGE_INDEX_FILE_ANALYSIS_H

#include "semantic/reference.h"
#include "semantic/symbol.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct FileAnalysis FileAnalysis;

FileAnalysis *FileAnalysis_4(uint64_t fileId, uint32_t documentId,
                             uint64_t documentRevision,
                             uint64_t compilationContextId);
void FileAnalysis_free(FileAnalysis *self);
bool FileAnalysis_addSymbol(FileAnalysis *self, Symbol symbol);
bool FileAnalysis_addReference(FileAnalysis *self, Reference reference);
uint64_t FileAnalysis_getFileId(const FileAnalysis *self);
uint32_t FileAnalysis_getDocumentId(const FileAnalysis *self);
uint64_t FileAnalysis_getDocumentRevision(const FileAnalysis *self);
uint64_t FileAnalysis_getCompilationContextId(const FileAnalysis *self);
size_t FileAnalysis_getSymbolCount(const FileAnalysis *self);
Symbol FileAnalysis_getSymbolAt(const FileAnalysis *self, size_t index);
size_t FileAnalysis_getReferenceCount(const FileAnalysis *self);
Reference FileAnalysis_getReferenceAt(const FileAnalysis *self, size_t index);

#endif
