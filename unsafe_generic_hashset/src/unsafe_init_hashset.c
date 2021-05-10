#include <stdlib.h>

#include "../export.h"
#include "../utils.h"

struct hashset *unsafe_init_hashset(size_t size, size_t (*hash)(void *, size_t))
{
    // failure on bad args
    if (!(size && hash))
    {
        return NULL;
    }

    // init hashset
    struct hashset *out = malloc(sizeof(*out));
    if (!out)
    {
        return NULL;
    }
    out->size = size;
    out->hash = hash;

    // init set
    out->set = malloc(size * sizeof(struct hash_element *));
    if (!out->set)
    {
        free(out);
        return NULL;
    }

    // init hash_element sentinels
    for (size_t i = 0; i < size; ++i)
    {
        out->set[i] = unsafe_init_hash_element();
        if (!out->set[i])
        {
            for (size_t j = 0; j < i; ++j)
            {
                free(out->set[j]);
            }
            free(out->set);
            free(out);
            return NULL;
        }
    }

    return out;
}