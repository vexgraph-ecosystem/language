#ifndef LANGUAGE_PROJECT_BUILD_TARGET_H
#define LANGUAGE_PROJECT_BUILD_TARGET_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct BuildTarget BuildTarget;

BuildTarget *BuildTarget_3(uint64_t targetId, const char *name,
                           const char *languageId);
void BuildTarget_free(BuildTarget *self);
bool BuildTarget_addSourceFile(BuildTarget *self, uint64_t fileId);
bool BuildTarget_addDependency(BuildTarget *self, uint64_t targetId);
bool BuildTarget_addCompilerOption(BuildTarget *self, const char *option);
uint64_t BuildTarget_getId(const BuildTarget *self);
const char *BuildTarget_getName(const BuildTarget *self);
const char *BuildTarget_getLanguageId(const BuildTarget *self);
size_t BuildTarget_getSourceCount(const BuildTarget *self);
uint64_t BuildTarget_getSourceAt(const BuildTarget *self, size_t index);
size_t BuildTarget_getDependencyCount(const BuildTarget *self);
uint64_t BuildTarget_getDependencyAt(const BuildTarget *self, size_t index);
size_t BuildTarget_getCompilerOptionCount(const BuildTarget *self);
const char *BuildTarget_getCompilerOptionAt(const BuildTarget *self, size_t index);

#endif
