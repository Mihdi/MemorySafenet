#include "../export.h"
#include "../utils.h"

bool garbage_collect(void *to_be_added)
{
    return unsafe_add2hashset(to_be_added, garbage_state(true, false));
}