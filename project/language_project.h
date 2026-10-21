#ifndef LANGUAGE_PROJECT_LANGUAGE_PROJECT_H
#define LANGUAGE_PROJECT_LANGUAGE_PROJECT_H

#include "project/project_file.h"
#include "project/build_target.h"
#include "project/project_configuration.h"
#include <stddef.h>
#include <stdint.h>

typedef struct LanguageProject LanguageProject;

LanguageProject *LanguageProject_2(uint64_t projectId, const char *rootPath);
void LanguageProject_free(LanguageProject *self);
const ProjectFile *LanguageProject_addFile(LanguageProject *self,
                                           const char *relativePath,
                                           ProjectFileKind kind,
                                           const char *languageId);
const ProjectFile *LanguageProject_findFile(const LanguageProject *self,
                                             const char *relativePath);
const ProjectFile *LanguageProject_findFileById(const LanguageProject *self,
                                                 uint64_t fileId);
const ProjectFile *LanguageProject_getFileAt(const LanguageProject *self, size_t index);
BuildTarget *LanguageProject_addTarget(LanguageProject *self, const char *name,
                                       const char *languageId);
BuildTarget *LanguageProject_findTarget(const LanguageProject *self, const char *name);
bool LanguageProject_addSourceToTarget(LanguageProject *self, uint64_t targetId,
                                       uint64_t fileId);
bool LanguageProject_addTargetDependency(LanguageProject *self, uint64_t targetId,
                                         uint64_t dependencyId);
BuildTarget *LanguageProject_getTargetAt(const LanguageProject *self, size_t index);
ProjectConfiguration *LanguageProject_getConfiguration(LanguageProject *self);
uint64_t LanguageProject_getId(const LanguageProject *self);
const char *LanguageProject_getRootPath(const LanguageProject *self);
size_t LanguageProject_getFileCount(const LanguageProject *self);
size_t LanguageProject_getTargetCount(const LanguageProject *self);

#endif
