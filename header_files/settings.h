#ifndef INC_TYPES_H
#define INC_TYPES_H
#include "types.h"
#endif // INC_TYPES_H

#ifndef INC_SCREEN_H
#define INC_SCREEN_H
#include "screen.h"
#endif // INC_SCREEN_H

////////////////////////////////////////
#ifndef SETTINGS_H
#define SETTINGS_H

#define HEADER_TXTS_Q       1
#define HEADER_WIDTH        SCREEN_WIDTH
#define HEADER_TXT          "[ SETTINGS ]"
#define HEADER_ALIGN        CENTER
#define HEADER_SEP          '='

#define OPTIONS_QUAN        4
#define BODY_ALIGN          LEFT
#define BODY_STYLE          ARABIC_NUM
#define BODY_DEFAULT_TOP    0

#define FOOTER_TXTS_Q       2
#define L_FOOTER_WIDTH      SCREEN_WIDTH/2
#define L_FOOTER_TXT        "type neg num to exit"
#define R_FOOTER_WIDTH      SCREEN_WIDTH/2
#define R_FOOTER_TXT        " options"
#define FOOTER_ALIGN        CENTER
#define FOOTER_SEP          ' '


item header_txt[HEADER_TXTS_Q];
struct container sett_header;

labels options[OPTIONS_QUAN];
struct body sett_body;

item footer_txt[2];
struct container sett_footer;

struct container test;


void set_opt_meter(char*);
int settings_menu();

#endif // SETTINGS_H
