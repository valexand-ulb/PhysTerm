//
// Created by alex on 6/01/24.
//

#include <unistd.h>
#include <sys/ioctl.h>

#include "utilities.h"
#include "../constant.h"

void utilities::setSize(int* w, int* h) {
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    *w = window.ws_col - BORDER_W;
    *h = window.ws_row - BORDER_H;
    if (*w <= 0 || *h <= 0) {
        *w = DEFAULT_WIDTH;
        *h = DEFAULT_HEIGHT;
    }
}
