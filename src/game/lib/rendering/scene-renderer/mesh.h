#include "../draw.h"

/** @INFO: 
 *      z is the direction into the screen.
 *      x, and y are normal
 */

enum fill_opts{
    SOLIDH,
    WIREFRAME,
    DOTTED
};

/// @Summary:
///     draws a 3d box of the given dimentions
///     to the buffer
/// @param: double_buf - the buffer
/// @param: x, y, z - the 3d coords
/// @param: size - x,y,z sizes of the box
/// @param: rotation - the x,y,z axis rotation
/// @param: color - the color to draw 
/// @param: fill - the fill to draw from fill_opts
int
draw_mesh_box(
        void *double_buf,
        vector_3 pos,
        vector_3 size,
        vector_3 rotation,
        size_t color,
        size_t fill
        );

/// @Summary:
///     draws a 3d box of the given dimentions
///     to the buffer
/// @param: double_buf - the buffer
/// @param: x, y, z - the 3d coords
/// @param: radius_x, y, z - the x_y_z shape of the bubble
/// @param: rotation - the x,y,z axis rotation
/// @param: color - the color to draw 
/// @param: fill - the fill to draw from fill_opts
int
draw_mesh_bubble(
void *double_buf,
        vector_3 pos,
        vector_3 size,
        vector_3 rotation,
        size_t color,
        size_t fill
        );

/// @Summary:
///     draws a 3d plane at the given co-ords
///     to the buffer
/// @param: double_buf - the buffer
/// @param: x, y, z - the 3d coords
/// @param: size - the x_y size
/// @param: rotation - the x,y,z axis rotation
/// @param: color - the color to draw 
/// @param: fill - the fill to draw from fill_opts
int 
draw_mesh_plane(
        void *double_buf,
        vector_3 pos,
        vector_2 size,
        vector_3 rotation,
        size_t color,
        size_t fill
        );

