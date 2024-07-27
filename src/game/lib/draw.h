#ifndef _DOOM_LIBDRAW_H
#define _DOOM_LIBDRAW_H

#define SCREEN_HEIGHT (size_t) 1995
#define SCREEN_WIDTH (size_t) 3200
#define PIXEL_DEPTH (size_t) 4

#define SCREEN_SIZE SCREEN_HEIGHT * \
    SCREEN_WIDTH * \
    PIXEL_DEPTH

#define WHITE (size_t) 0xFFFFFFFF
#define BLACK (size_t) 0xFF000000
#define BLUE (size_t) 0xFF0000FF

#include <sys/mman.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

/// @param fb0_mmap - the base address of the
///                   memory map to write to
/// @param double_buf - The second buffer to
///                     write to the memory map
///                     from
/// @return int, error status (0/-1)
/// @summary - writes the current state of the
///            second buffer to fb0_mmap, then
///            schedules a memory sync
int
render(void *fb0_mmap, void *double_buf);

/// @param double_buf - The buffer to draw to
/// @param x - the start x coord
/// @param y - the start y coord
/// @param len - the number of pixels to draw
/// @param color - the color (rgba) to draw; must be dword (4bytes)
/// @return int, error status (0/-1)
/// @summary - draws a straight line (LtR on x axis)
///            onto double_buf of length len,
///            starting at (x, y)
int 
draw_line_x(char *double_buf, size_t x, size_t y, size_t len, size_t color);

/// @param double_buf - The buffer to draw to
/// @param x - the start x coord
/// @param y - the start y coord
/// @param len - the number of pixels to draw
/// @param color - the color (rgba) to draw; must be dword (4bytes)
/// @return int, error status (0/-1)
/// @summary - draws a straight line (TtB on y axis)
///            onto double_buf of length len,
///            starting at (x, y)
int 
draw_line_y(char *double_buf, size_t x, size_t y, size_t len, size_t color);


/// @param double_buf - The buffer to clear
/// @return int, error status (0/-1)
/// @summary - draw black to every pixel on buf
int
clear_screen(char *double_buf);

#endif // _DOOM_LIBDRAW_H
