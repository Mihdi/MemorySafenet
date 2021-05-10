#include <stdlib.h>

#include "../export.h"

void unsafe_free_hashset(struct hashset *hs)
{
    if (!hs)
    {
        return;
    }

    if (hs->set)
    {
        for (size_t i = 0; i < hs->size; ++i)
        {
            if (hs->set[i])
            {
                for (struct hash_element *p = hs->set[i]->next;
                     p != hs->set[i];)
                {
                    struct hash_element *next = p->next;
                    free(p);
                    p = next;
                }
                free(hs->set[i]);
            }
        }
        free(hs->set);
    }
    free(hs);
}