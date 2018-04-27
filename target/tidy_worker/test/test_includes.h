#ifndef TEST_INCLUDES_H
#define TEST_INCLUDES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tidy_html.h"
#include "eterm_vec.h"

#define TEST_LOG fprintf(stdout, "[LOG]\t%s()\n", __func__);
#define TEST_ERROR fprintf(stderr, "[ERROR]\t%s()\n\t%s:%d\n", __func__, __FILE__, __LINE__);

#endif