#include "draw.h"

/** @INFO: 
 *      z is the direction into the screen.
 *      x, and y are normal
 */

enum fill_opts{
    FILL,
    LINE_MESH
};

/// @Summary:
///     draws a 3d box of the given dimentions
///     to the buffer
/// @param: double_buf - the buffer
/// @param: x, y, z - the 3d coords
/// @param: height, width, depth - the sizes
/// @param: color - the color to draw 
/// @param: fill - the fill to draw from fill_opts
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
        );

/// @Summary:
///     draws a 3d box of the given dimentions
///     to the buffer
/// @param: double_buf - the buffer
/// @param: x, y, z - the 3d coords
/// @param: radius_x, y, z - the x_y_z shape of the bubble
/// @param: color - the color to draw 
/// @param: fill - the fill to draw from fill_opts
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
        );

