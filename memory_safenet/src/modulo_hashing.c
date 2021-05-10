#include <stddef.h>

#include "../utils.h"

size_t modulo_hashing(void *p, size_t sz)
{
    unsigned char *uc_p = p;
    unsigned char *uc_nll = NULL;

    return (uc_p - uc_nll) % sz;
}