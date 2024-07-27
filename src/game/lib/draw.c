#include "draw.h"

/// @PRIVATE ///
/// @err: None
size_t 
convert_coord_to_index(size_t x, size_t y);

/// @PRIVATE ///
/// @err: -1 if msync fails
int
draw(void *double_buf);

int
render(void *fb0_mmap, void *double_buf){
    if (memcpy(
                fb0_mmap, 
                double_buf, 
                SCREEN_SIZE
            ) < 0){
        perror("Memcpy failed writing to fb0 mmap\n");
        return -1;
    }

    if (msync(
                fb0_mmap, 
                SCREEN_SIZE,
                MS_ASYNC
            ) < 0){
        perror("Failed to schedule memory sync\n");
        return -1;
    }
    return 0;
}

int 
draw_line_x(char *double_buf, size_t x, size_t y, size_t len, size_t color){
    // validate
    if (    x < 1 
            || y < 1
            || len < 1
            || x > SCREEN_WIDTH
            || y > SCREEN_HEIGHT
            || (x + len) > SCREEN_WIDTH
            || double_buf == NULL
            || color > WHITE
       ){
        errno = EINVAL;
        return -1;
    }
    
    for (
            size_t i = convert_coord_to_index(x, y); 
            i < convert_coord_to_index(x + len, y); 
            i += PIXEL_DEPTH){
        memcpy(
            &double_buf[i], // base addr index
            &color,
            PIXEL_DEPTH
        );
    }

    if (draw(double_buf) < 0){
        perror("Failed to draw\n");
        return -1;
    }

    return 0;
}

int 
draw_line_y(char *double_buf, size_t x, size_t y, size_t len, size_t color){
    // validate
    if (    x < 1 
            || y < 1
            || len < 1
            || x > SCREEN_WIDTH
            || y > SCREEN_HEIGHT
            || (x + len) > SCREEN_WIDTH
            || double_buf == NULL
            || color > WHITE
       ){
        errno = EINVAL;
        return -1;
    }
    
    for (
            size_t i = convert_coord_to_index(x, y); 
            i < convert_coord_to_index(x, y + len); 
            i += SCREEN_WIDTH * PIXEL_DEPTH){
        memcpy(
                &double_buf[i], // base addr + index
                &color,
                PIXEL_DEPTH
                );
    }

    if (draw(double_buf) < 0){
        perror("Failed to draw\n");
        return -1;
    }

    return 0;
}

int 
clear_screen(char *double_buf){
    size_t color = BLACK;
    for (
            size_t i = 0;
            i < convert_coord_to_index(SCREEN_WIDTH, SCREEN_HEIGHT - 1);
            i += PIXEL_DEPTH){
        memcpy(
                &double_buf[i],
                &color,
                PIXEL_DEPTH
              );
    }

    if (draw(double_buf) < 0){
        perror("Failed to draw\n");
        return -1;
    }

    return 0;
}

int 
draw(void *double_buf){
    if (msync(double_buf, SCREEN_SIZE, MS_ASYNC) < 0){
        perror("Failed to Sync double_buf\n");
        return -1;
    }
    return 0;
}
    
size_t
convert_coord_to_index(size_t x, size_t y){
    // (y * WIDTH + x) * pixel_depth
    size_t index;
    index = y * SCREEN_WIDTH + x;
    index *= PIXEL_DEPTH;
    return index;
}
