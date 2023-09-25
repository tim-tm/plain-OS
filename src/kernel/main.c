#include "../include/stdio.h"

void kernel_main(void) 
{
    k_print_clear();
    k_set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    kputs("Welcome to plain-OS!");
}
