#include "app.h"

int 
setup(void *fb0_mmap, int *fb0_fd, void *double_buf){
    if ((*fb0_fd = open(
                    FB0_PATH, 
                    O_CREAT | O_RDWR, 
                    0666
                    )) < 0){
        perror("Failed to open /dev/fb0\n");
        return -1;
    }

    if ((fb0_mmap = mmap(
                    NULL, 
                    SCREEN_HEIGHT * SCREEN_WIDTH * PIXEL_DEPTH, 
                    PROT_READ | PROT_WRITE,
                    MAP_SHARED,
                    *fb0_fd,
                    0
                    )) < 0){
        perror("Failed to map fb0 to memory\n");
        return -1;
    }

    if ((double_buf = malloc(SCREEN_HEIGHT * SCREEN_WIDTH * PIXEL_DEPTH)) < 0){
        perror("Failed to allocate double buffer\n");
        return -1;
    }

    return 0;
}

int 
shutdown(void *fb0_mmap, int fb0_fd, void *double_buf){
    int _return = 0;

    if (double_buf && free(double_buf) < 0){
        perror("Failed to free double buffer\n");
        _return = -1;
    }

    if (fb0_mmap && munmap(fb0_mmap, SCREEN_HEIGHT * SCREEN_WIDTH * PIXEL_DEPTH)) < 0){
        perror("Failed to unmap fb0\n");
        _return = -1;
    }

    if (fb0_fd && close(fb0_fd) < 0){
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
        vfprinf(stderr, format, args);
        va_end(args);
        fprintf(stderr, "\n\n");
    }

    if (shutdown(fb0_mmap, fb0_fd, double_buf) < 0){
        fprintf(stderr, "Failed to Shutdown Properly\n");
        exit(SHUTDOWN_FAILED);
    }

    fprintf("Shutdown Successful. Exiting\n");
    exit(errCode);
}

int 
main(){
    int fb0_fd;
    void *fb0_mmap;
    void *double_buf;

    if (setup(fb0_mmap, &fb0_fd, double_buf) < 0){
        exit_failure(
                fb0_mmap,
                fb0_fd,
                double_buf,
                SETUP_FAILED,
                "Failed to setup doom.\n"
                );
    }

    

    if (shutdown(fb0_mmap, fb0_fd, double_buf) < 0){
        exit_failure(
                NULL, NULL, NULL,
                SHUTDOWN_FAILED,
                "Failed to shutdown correctly.\n"
                );
    }
    
    return 0;
}
