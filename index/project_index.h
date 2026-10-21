#ifndef LANGUAGE_INDEX_PROJECT_INDEX_H
#define LANGUAGE_INDEX_PROJECT_INDEX_H

#include "index/file_analysis.h"
#include "project/language_project.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct ProjectIndex ProjectIndex;

ProjectIndex *ProjectIndex_1(const LanguageProject *project);
void ProjectIndex_free(ProjectIndex *self);
bool ProjectIndex_publish(ProjectIndex *self, const FileAnalysis *analysis);
const FileAnalysis *ProjectIndex_findAnalysis(const ProjectIndex *self, uint64_t fileId,
                                             uint64_t compilationContextId);
size_t ProjectIndex_getAnalysisCount(const ProjectIndex *self);
size_t ProjectIndex_getDeclarationCount(const ProjectIndex *self, uint64_t symbolId,
                                        uint64_t compilationContextId);
Symbol ProjectIndex_getDeclarationAt(const ProjectIndex *self, uint64_t symbolId,
                                     uint64_t compilationContextId, size_t index);
size_t ProjectIndex_getReferenceCount(const ProjectIndex *self, uint64_t symbolId,
                                      uint64_t compilationContextId);
Reference ProjectIndex_getReferenceAt(const ProjectIndex *self, uint64_t symbolId,
                                      uint64_t compilationContextId, size_t index);
uint64_t ProjectIndex_getProjectId(const ProjectIndex *self);

#endif
