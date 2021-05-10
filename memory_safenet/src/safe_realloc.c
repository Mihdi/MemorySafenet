#include <stdlib.h>

#include "../export.h"
#include "../utils.h"

void *safe_realloc(void *safe_ptr, size_t size)
{
    struct hashset *grbge_state = garbage_state(true, false);
    bool is_rmvd = unsafe_rmv_from_hashset(safe_ptr, grbge_state);
    if (!is_rmvd) // making sure it only works for safe_ptrs
    {
        return NULL;
    }

    void *out = realloc(safe_ptr, size);
    garbage_collect(out);
    return out;
}