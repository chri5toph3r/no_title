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

#define OPTIONS_QUAN    4
#define MENU_HEADER     "[ SETTINGS ]"
#define MENU_FOOTER     "type 0 to exit"

labels options[OPTIONS_QUAN];
struct body sett_body;

int settings_menu();

#endif // SETTINGS_H
