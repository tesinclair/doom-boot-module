#ifndef _DOOM_APP_H
#define _DOOM_APP_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/mman.h>
#include <fcntl.h>

// Screen Info
#define SCREEN_HEIGHT 2160
#define SCREEN_WIDTH 3200
#define PIXEL_DEPTH 4

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

#endif // _DOOM_APP_H
