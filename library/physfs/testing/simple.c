#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#if (defined __MWERKS__)
#include <SIOUX.h>
#endif

#if (defined PHYSFS_HAVE_READLINE)
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#endif

#include "include/physfs.h"

#define PHYSFS_DEPRECATED
#define TEST_VERSION_MAJOR  3
#define TEST_VERSION_MINOR  0
#define TEST_VERSION_PATCH  2

static FILE *history_file = NULL;
static PHYSFS_uint32 do_buffer_size = 0;

const int output_versions()
{
    PHYSFS_Version compiled;
    PHYSFS_Version linked;

    PHYSFS_VERSION(&compiled);
    PHYSFS_getLinkedVersion(&linked);

    return (int) compiled.major;
}

int main(int argc, char const *argv[])
{
	if (!PHYSFS_init(argv[0]))
    {
        printf("init error: %s.\n", PHYSFS_getLastError());
        exit(1);
    }

	PHYSFS_permitSymbolicLinks(1);

	char *basedir = NULL;
	char *userdir = NULL;
	basedir = PHYSFS_getBaseDir();
	userdir = PHYSFS_getUserDir();

    printf("basedir: %s\n", basedir);
    printf("userdir: %s\n", userdir);

	return 0;
}
