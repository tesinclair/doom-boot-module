#ifndef _DOOM_APP_H
#define _DOOM_APP_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>

#include "lib/scenes.h"

#define FB_PATH "/dev/fb0"

// Standard stuff
#define TRUE 1
#define FALSE 0

// Errors
enum {
    SETUP_FAILED = 10,
    SHUTDOWN_FAILED,
    NO_MEMORY,
};

struct game_state{
    int is_active;
};

int
setup(void **fb_mmap, int *fb0_fd, void **double_buf);

int
shutdown(void *fb0_mmap, int fb0_fd, void *double_buf);

void
exit_success(void *fb0_mmap, int fb0_fd, void *double_buf);

void
exit_failure(
        void *fb0_mmap,
        int fb0_fd,
        void *double_buf,
        int errCode,
        char *format,
        ...
        );

#endif // _DOOM_APP_H
