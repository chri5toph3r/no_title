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

#define SETT_H_TXTS_Q       1
#define SETT_H_WIDTH        SCREEN_WIDTH
#define SETT_H_TXT          "[ SETTINGS ]"
#define SETT_H_ALIGN        CENTER
#define SETT_H_SEP          '='

#define SETT_B_OPT_QUAN     4
#define SETT_B_ALIGN        LEFT
#define SETT_B_STYLE        ARABIC_NUM
#define SETT_B_DEFAULT_TOP  0

#define SETT_F_TXTS_Q       2
#define SETT_LF_WIDTH       SCREEN_WIDTH/2
#define SETT_LF_TXT         "type neg num to exit"
#define SETT_RF_WIDTH       SCREEN_WIDTH/2
#define SETT_RF_TXT         " options"
#define SETT_F_ALIGN        CENTER
#define SETT_F_SEP          ' '


item header_item[SETT_H_TXTS_Q];
struct Container sett_header;

labels options[SETT_B_OPT_QUAN];
struct Body sett_body;

item footer_item[SETT_F_TXTS_Q];
struct Container sett_footer;

struct Container test;


void set_opt_meter(char*);
int _settings_menu();

#endif // SETTINGS_H
