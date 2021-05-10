#include <stdlib.h>

#include "../export.h"

void *safe_malloc(size_t size)
{
    void *out = malloc(size);
    garbage_collect(out);
    return out;
}