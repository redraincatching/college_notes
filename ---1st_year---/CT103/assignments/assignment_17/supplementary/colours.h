/*
c colour codes
8 ansi colours
\033 is the escape sequence
[0____ is the colour code itself
*/

void console_black() {
    printf("\033[0;30m");
}

void console_red() {
    printf("\033[0;31m");
}

void console_green() {
    printf("\033[0;32m");
}

void console_yellow() {
    printf("\033[0;33m");
}

void console_blue() {
    printf("\033[0;34m");
}

void console_purple() {
    printf("\033[0;35m");
}

void console_cyan() {
    printf("\033[0;36m");
}

void console_white() {
    printf("\033[0;37m");
}

void console_reset() {
    printf("\033[0m");
}
