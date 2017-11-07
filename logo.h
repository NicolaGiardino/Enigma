//
//

#ifndef logo_h
#define logo_h

#include <stdio.h>


// Colori per la shell Unix
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B"

// Pulisce lo schermo
#define ClearUnixScreen() printf("\033[H\033[J")

const char EnigmaLogo[] =
BLU
"\n"
" -------------------------------------------------\n"
" ███████╗███╗   ██╗██╗ ██████╗ ███╗   ███╗ █████╗\n"
" ██╔════╝████╗  ██║██║██╔════╝ ████╗ ████║██╔══██╗\n"
" █████╗  ██╔██╗ ██║██║██║  ███╗██╔████╔██║███████║\n"
" ██╔══╝  ██║╚██╗██║██║██║   ██║██║╚██╔╝██║██╔══██║\n"
" ███████╗██║ ╚████║██║╚██████╔╝██║ ╚═╝ ██║██║  ██║\n"
" ╚══════╝╚═╝  ╚═══╝╚═╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝\n"
" Copyright © 2016 Nicola di Gruttola Giardino\n"
" -------------------------------------------------\n"
RESET;

#endif /* logo_h */
