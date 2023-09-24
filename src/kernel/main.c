#include "../header/print.h"

void kernel_main(void) 
{
    print_clear();
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("Welcome to plain-OS!");
}
