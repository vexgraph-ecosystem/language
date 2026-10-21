#ifndef LANGUAGE_INDEX_DEPENDENCY_GRAPH_H
#define LANGUAGE_INDEX_DEPENDENCY_GRAPH_H

#include "project/language_project.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct DependencyGraph DependencyGraph;

// The graph borrows a stable LanguageProject for its lifetime. Edges point
// from a file to files it depends on; replacing one file's edges is atomic.
DependencyGraph *DependencyGraph_1(const LanguageProject *project);
void DependencyGraph_free(DependencyGraph *self);
bool DependencyGraph_setDependencies(DependencyGraph *self, uint64_t fileId,
                                     const uint64_t *dependencyFileIds,
                                     size_t dependencyCount);
size_t DependencyGraph_getDependencyCount(const DependencyGraph *self,
                                          uint64_t fileId);
uint64_t DependencyGraph_getDependencyAt(const DependencyGraph *self,
                                         uint64_t fileId, size_t index);
size_t DependencyGraph_getDependentCount(const DependencyGraph *self,
                                         uint64_t fileId);
uint64_t DependencyGraph_getDependentAt(const DependencyGraph *self,
                                        uint64_t fileId, size_t index);
// True when candidate directly or transitively depends on changedFileId.
// A file is considered affected by itself, including in an empty graph.
bool DependencyGraph_isAffectedBy(const DependencyGraph *self,
                                  uint64_t candidateFileId,
                                  uint64_t changedFileId);
uint64_t DependencyGraph_getProjectId(const DependencyGraph *self);

#endif
