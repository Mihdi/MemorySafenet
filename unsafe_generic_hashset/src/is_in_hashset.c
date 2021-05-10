#include "../export.h"

bool is_in_hashset(void *sought, struct hashset *hs)
{
    size_t pos = hs->hash(sought, hs->size);

    for (struct hash_element *p = hs->set[pos]->next; p != hs->set[pos];
         p = p->next)
    {
        if (sought == p->val)
        {
            return true;
        }
    }
    return false;
}