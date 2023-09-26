#include "../include/stdio.h"
#include "../include/string.h"

void kernel_main(void) 
{
    print_clear();
    set_print_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    puts("Welcome to plain-OS!\n");
}
