#include <err.h>

#include "../export.h"
#include "../utils.h"

void safe_errx(int eval, char *out_msg)
{
    garbage_dump(true);
    if (eval == EXIT_FAILURE)
        eval = 2;
    errx(eval, "%s", out_msg);
}
