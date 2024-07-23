#include "app.h"

int 
setup(void **fb0_mmap, int *fb0_fd, void **double_buf){
    if ((*fb0_fd = open(
                    FB_PATH, 
                    O_CREAT | O_RDWR, 
                    0666
                    )) < 0){
        perror("Failed to open /dev/fb0\n");
        return -1;
    }

    if ((*fb0_mmap = mmap(
                    NULL, 
                    SCREEN_SIZE,
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED,
                    *fb0_fd,
                    0
                    )) < 0){
        perror("Failed to map fb0 to memory\n");
        return -1;
    }

    if ((*double_buf = mmap(
                    NULL,
                    SCREEN_SIZE,
                    PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS,
                    -1, 0
                    )) < 0){
        perror("Failed to map double buf");
        return -1;
    }

    return 0;
}

int 
shutdown(void *fb0_mmap, int fb0_fd, void *double_buf){
    int _return = 0;

    if (fb0_mmap && munmap(
                    double_buf, 
                    SCREEN_SIZE
                    ) < 0){
        perror("Failed to unmap double_buf\n");
        _return = -1;
    }

    if (fb0_mmap && munmap(
                    fb0_mmap, 
                    SCREEN_SIZE
                    ) < 0){
        perror("Failed to unmap fb0\n");
        _return = -1;
    }

    if (fb0_fd >= 0 && close(fb0_fd) < 0){
        perror("Failed to close fb0\n");
        _return = -1;
    }

    return _return;
}


void 
exit_success(void *fb0_mmap, int fb0_fd, void *double_buf){
    if (shutdown(fb0_mmap, fb0_fd, double_buf) < 0){
        fprintf(stderr, "Failed to Shutdown Properly\n");
        exit(SHUTDOWN_FAILED);
    }
    printf("Shutdown Successful. Exiting\n");
    exit(0);
}

void 
exit_failure(
        void *fb0_mmap, 
        int fb0_fd, 
        void *double_buf, 
        int errCode, 
        char *format, 
        ...
        ){
    if (format != NULL){
        fprintf(stderr, "Error: \n");
        va_list args;
        va_start(args, format);
        vfprintf(stderr, format, args);
        va_end(args);
        fprintf(stderr, "\n\n");
    }

    if (shutdown(fb0_mmap, fb0_fd, double_buf) < 0){
        fprintf(stderr, "Failed to Shutdown Properly\n");
        exit(SHUTDOWN_FAILED);
    }

    printf("Shutdown Successful. Exiting\n");
    exit(errCode);
}

int 
main(){
    int fb0_fd;
    void *fb0_mmap;
    void *double_buf;

    struct game_state state;

    if (setup(&fb0_mmap, &fb0_fd, &double_buf) < 0){
        exit_failure(
                fb0_mmap,
                fb0_fd,
                double_buf,
                SETUP_FAILED,
                "Failed to setup doom.\n"
                );
    }

    state.is_active = TRUE;

    // Game loop:
    while (state.is_active){
        draw_line_x(double_buf, 1000, 1000, 100, 0xFFFFFFFF);                 
        draw_line_y(double_buf, 1000, 1000, 100, 0xFFFFFFFF);
        draw_line_x(double_buf, 1000, 1100, 100, 0xFFFFFFFF);
        draw_line_y(double_buf, 1100, 1000, 100, 0xFFFFFFFF);
        render(fb0_mmap, double_buf);
    }

    if (shutdown(fb0_mmap, fb0_fd, double_buf) < 0){
        exit_failure(
                NULL, -1, NULL,
                SHUTDOWN_FAILED,
                "Failed to shutdown correctly.\n"
                );
    }
    
    return 0;
}
