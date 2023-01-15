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

#define HEADER_LENGTH       13
#define HEADER_TXT          "[ SETTINGS ]"
#define HEADER_ALIGN        CENTER
#define HEADER_SEP          '='

#define OPTIONS_QUAN        4
#define BODY_ALIGN          LEFT
#define BODY_STYLE          ARABIC_NUM
#define BODY_DEFAULT_TOP    0

#define FOOTER_TXT          "type neg num to exit"


txt header_txt[];
struct texts_line sett_header;

labels options[OPTIONS_QUAN];
struct body sett_body;

txt footer_txt;
struct texts_line sett_footer;


int settings_menu();

#endif // SETTINGS_H
