#ifndef LANGUAGE_LANG_LANGUAGE_ADAPTER_H
#define LANGUAGE_LANG_LANGUAGE_ADAPTER_H

#include "analysis/syntax_span.h"
#include "lang/language_lex_result.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* A language adapter is selected by an explicit language id, never by suffix
 * alone: the same .c/.h file may be compiled under different language modes. */
typedef struct LanguageAdapter {
    const char *languageId;
    void *(*open)(uint32_t documentId, const char *source, size_t length);
    LanguageLexResult (*next)(void *session);
    void (*close)(void *session);
} LanguageAdapter;

bool LanguageAdapter_isValid(const LanguageAdapter *self);
const char *LanguageAdapter_getLanguageId(const LanguageAdapter *self);
void *LanguageAdapter_open(const LanguageAdapter *self, uint32_t documentId,
                           const char *source, size_t length);
LanguageLexResult LanguageAdapter_next(const LanguageAdapter *self, void *session);
void LanguageAdapter_close(const LanguageAdapter *self, void *session);

#endif
