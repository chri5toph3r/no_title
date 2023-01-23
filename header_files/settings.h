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

// HEADER
#define SETT_H_WIDTH        SCREEN_WIDTH
#define SETT_H_HEIGHT       1
#define SETT_H_TXTS_Q       1
#define SETT_H_TXT          "[ SETTINGS ]"
#define SETT_H_ALIGN        CENTER
#define SETT_H_SEP          '='

// BODY
#define SETT_B_HEIGHT       4
#define SETT_B_C_HEIGHT     1
#define SETT_B_OPT_QUAN     4
#define SETT_B_C_OPT_QUAN   1
#define SETT_B_DEFAULT_TOP  0
#define SETT_B_ALIGN        LEFT_TABBED
#define SETT_B_C_ALIGN      LEFT
#define SETT_B_SEP          ' '
#define SETT_B_STYLE        ARABIC_NUM

// FOOTER
#define SETT_F_TXTS_Q       2
#define SETT_F_HEIGHT       1

#define SETT_LF_WIDTH       SCREEN_WIDTH*2/3
#define SETT_LF_TXT         "type neg num to exit"

#define SETT_RF_WIDTH       SCREEN_WIDTH/3
#define SETT_RF_TXT         " options"

#define SETT_F_ALIGN        CENTER
#define SETT_F_SEP          ' '


item header_item;
container sett_header;

item sett_texts[SETT_B_OPT_QUAN];
container sett_options[SETT_B_OPT_QUAN];
area sett_body;

item footer_items[SETT_F_TXTS_Q];
container sett_footer;


void set_opt_meter(char*);
int _settings_menu();

#endif // SETTINGS_H
