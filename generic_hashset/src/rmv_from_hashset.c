#include <stdlib.h>

#include "../export.h"

bool rmv_from_hashset(void *to_be_rmvd, struct hashset *hs)
{
    size_t pos = hs->hash(to_be_rmvd, hs->size);

    for (struct hash_element *p = hs->set[pos]->next; p != hs->set[pos];
         p = p->next)
    {
        if (to_be_rmvd == p->val)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;

            safe_free(p);
            return true;
        }
    }
    return false;
}