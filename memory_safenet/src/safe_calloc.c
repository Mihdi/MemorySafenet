#include <stdlib.h>

#include "../export.h"

void *safe_calloc(size_t nmemb, size_t size)
{
    void *out = calloc(nmemb, size);
    garbage_collect(out);
    return out;
}