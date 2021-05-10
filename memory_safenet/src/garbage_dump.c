#include "../export.h"
#include "../utils.h"

void garbage_dump(bool are_you_sure)
{
    if (!are_you_sure)
        return;

    // this should be the only time ever where garbage_state(false, true) is
    // invoked
    struct hashset *grbg_state = garbage_state(false, true);
    if (!grbg_state)
    {
        return;
    }

    if (grbg_state->set)
    {
        for (size_t i = 0; i < grbg_state->size; ++i)
        {
            if (grbg_state->set[i])
            {
                for (struct hash_element *p = grbg_state->set[i]->next;
                     p != grbg_state->set[i];)
                {
                    struct hash_element *next = p->next;
                    free(p->val);
                    free(p);
                    p = next;
                }
                free(grbg_state->set[i]);
            }
        }
        free(grbg_state->set);
    }
    free(grbg_state);
}