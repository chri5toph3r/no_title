#ifndef INC_TYPES_H
#define INC_TYPES_H
#include "types.h"
#endif // INC_TYPES_H

#ifndef INC_SCREEN_H
#define INC_SCREEN_H
#include "screen.h"
#endif // INC_SCREEN_H

////////////////////////////////////////
#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#define MM_T_TXTS_Q         1
#define MM_T_WIDTH          SCREEN_WIDTH
#define MM_T_TXT            "'THE MENU MANAGER'"
#define MM_T_ALIGN          CENTER
#define MM_T_SEP            '.'

#define MM_B_OPT_QUAN       3
#define MM_B_DEFAULT_TOP    0
#define MM_B_ALIGN          CENTER
#define MM_B_SEP            '.'
#define MM_B_STYLE          NONE


item title_item[MM_T_TXTS_Q];
struct Container mm_title;

labels mm_options[MM_B_OPT_QUAN];
struct Body mm_body;


int _main_menu();

#endif // MAIN_MENU_H