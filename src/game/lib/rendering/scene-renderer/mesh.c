#include "mesh.h"

int
draw_mesh_box(
        void *double_buf,
        vector_3 pos,
        vector_3 size,
        vector_3 rotation,
        size_t color,
        size_t fill
        ){
    // validate
    if (!double_buf
        || pos.x < 1
        || (pos.x + size.x) > SCREEN_WIDTH
        || pos.y < 1
        || (pos.y + size.y) > SCREEN_HEIGHT
        || pos.z < 1
        || (pos.z + size.z) > MAX_Z
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
        vector_3 pos,
        vector_3 size,
        vector_3 rotation,
        size_t color,
        size_t fill
        ){
    // validate
    if (!double_buf
        || pos.x < 1
        || (pos.x + size.x) > SCREEN_WIDTH
        || pos.y < 1
        || (pos.y + size.y) > SCREEN_HEIGHT
        || pos.z < 1
        || (pos.z + size.z) > MAX_Z
        || color > WHITE
       ){
        errno = EINVAL;
        return -1;
    }
    return -1;
}

int 
draw_mesh_plane(
        void *double_buf,
        vector_3 pos,
        vector_2 size,
        vector_3 rotation,
        size_t color,
        size_t fill
        ){
    // validate
    if (!double_buf
        || pos.x < 1
        || (pos.x + size.x) > SCREEN_WIDTH
        || pos.y < 1
        || (pos.y + size.y) > SCREEN_HEIGHT
        || pos.z > MAX_Z
        || color > WHITE
       ){
        errno = EINVAL;
        return -1;
    }
 
    if (fill == WIREFRAME){
        
    } 
    elif (fill == SOLID){
        return -1;
    }
}

