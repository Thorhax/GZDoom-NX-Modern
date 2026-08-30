#pragma once

#include <switch.h>

#define BASEDIR "gzdoom"
#define RELATIVE_TMPDIR "temp"
#define TMPDIR BASEDIR "/" RELATIVE_TMPDIR

#ifndef VERSION
# ifdef GIT_DESCRIPTION
#  define VERSION GIT_DESCRIPTION
# else
#  define VERSION "nx4.7.1-1"
# endif
#endif
