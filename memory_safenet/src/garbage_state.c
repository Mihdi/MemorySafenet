#include <stddef.h>

#include "../utils.h"

struct hashset *garbage_state(bool protect, bool reset)
{
    static struct hashset *state = NULL;

    // when no current state, create one
    if (state == NULL)
    {
        state = unsafe_init_hashset(GARBAGE_HASHSET_SIZE, modulo_hashing);
    }

    // return value is always the state before any possible reset
    struct hashset *out = state;

    // if no protection was asked and reset was demanded, reset the state
    if (!protect && reset)
    {
        state = NULL;
    }

    return out;
}