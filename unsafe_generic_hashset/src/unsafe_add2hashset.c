#include <stdlib.h>

#include "../export.h"
#include "../utils.h"

bool unsafe_add2hashset(void *to_be_added, struct hashset *hs)
{
    if (!to_be_added)
    {
        return NULL;
    }

    size_t pos = hs->hash(to_be_added, hs->size);

    for (struct hash_element *p = hs->set[pos]->next; p != hs->set[pos];
         p = p->next)
    {
        if (p->val == to_be_added)
        {
            return false;
        }
    }

    struct hash_element *new = unsafe_init_hash_element();
    if (!new)
    {
        return false;
    }

    new->val = to_be_added;

    new->prev = hs->set[pos]->prev; // new's prev = old prev
    hs->set[pos]->prev->next = new; // old prev's next is new
    hs->set[pos]->prev = new; // new is prev
    new->next = hs->set[pos]; // new's next is sentinel

    return true;
}
