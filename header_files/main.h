#ifndef INC_STR_H
#define INC_STR_H
#include <string.h>
#endif // INC_STR_H

////////////////////////////////////////
#ifndef INC_MEMOP_H
#define INC_MEMOP_H
#include "memop.h"
#endif // INC_MEMOP_H

#ifndef INC_TYPES_H
#define INC_TYPES_H
#include "types.h"
#endif // INC_TYPES_H

#ifndef INC_SCREEN_H
#define INC_SCREEN_H
#include "screen.h"
#endif // INC_SCREEN_H

#ifndef INC_SETTINGS_H
#define INC_SETTINGS_H
#include "settings.h"
#endif // INC_SETTINGS_H
////////////////////////////////////////
#define DEF_SCREEN      0

////////////////////////////////////////
#ifndef MAIN_H
#define MAIN_H

#define MENUS_QUAN      1
functions menus[1] = {
    &settings_menu
};

int main(int, char const*[]);

#endif // MAIN_H
