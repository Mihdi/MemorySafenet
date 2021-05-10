#include <stdlib.h>

#include "../utils.h"

struct hash_element *init_hash_element(void)
{
    struct hash_element *out = safe_calloc(1, sizeof(struct hash_element));
    if (!out)
    {
        return NULL;
    }

    out->prev = out;
    out->next = out;

    return out;
}