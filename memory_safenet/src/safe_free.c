#include "../export.h"
#include "../utils.h"

void safe_free(void *safe_ptr)
{
    if (!safe_ptr)
        return;

    // if safe pointer, removes it from garbage state, else do nothing
    if (!unsafe_rmv_from_hashset(safe_ptr, garbage_state(true, false)))
    {
        return;
    }

    free(safe_ptr);
}
