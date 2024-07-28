#include "mesh.h"

int
draw_mesh_box(
        void *double_buf,
        size_t x,
        size_t y,
        size_t z,
        size_t height,
        size_t width,
        size_t depth,
        size_t color,
        size_t fill
        ){
    // validate
    if (x < 1
        || (x + width) > SCREEN_WIDTH
        || y < 1
        || (y + height) > SCREEN_HEIGHT
        || z < 1
        || (z + depth) > MAX_Z
        || color > WHITE
       ){
        errno = EINVAL;
        return -1;
    }
    return -1;
}

int
draw_mesh_bubble(
        void *double_buf,
        size_t x,
        size_t y,
        size_t z,
        size_t radius_x,
        size_t radius_y,
        size_t radius_z,
        size_t color,
        size_t fill
        ){
    // validate
    if (x < 1
        || (x + radius_x) > SCREEN_WIDTH
        || y < 1
        || (y + radius_y) > SCREEN_HEIGHT
        || z < 1
        || (z + radius_z) > MAX_Z
        || color > WHITE
       ){
        errno = EINVAL;
        return -1;
    }
    return -1;
}

