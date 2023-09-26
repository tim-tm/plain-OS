#include "../include/stdio.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

typedef struct _Char {
    uint8_t character;
    uint8_t color;
} Char;

Char* buffer = (Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

static void clear_row(size_t row) {
    Char empty = {
        ' ',
        color
    };

    for (size_t col = 0; col < NUM_COLS; ++col) {
        buffer[col + NUM_COLS * row] = empty; 
    }
}

static void print_newline() {
    col = 0;
    if (row < NUM_ROWS - 1) {
        ++row;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; ++row) {
        for (size_t col = 0; col < NUM_COLS; ++col) {
            Char c = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = c;
        }
    }
    clear_row(NUM_COLS-1);
}

void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; ++i) {
        clear_row(i);
    }
}

void putchar(char c) {
    if (c == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (Char) {
        (uint8_t) c,
        color
    };
    ++col;
}

void puts(char* str) {
    for (size_t i = 0; 1; ++i) {
        char c = (uint8_t) str[i];

        if (c == '\0') {
            return;
        }
        putchar(c);
    }
}

void set_print_color(uint8_t fore, uint8_t back) {
    color = fore + (back << 4);
}

