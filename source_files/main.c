#include "../header_files/main.h"


functions menus[MENUS_QUAN] = {
    &_main_menu//,
    // &_settings_menu
};


int main(int argc, char const *argv[])
{
    // cls();
    printf("main\n");
    int cur_screen = DEFAULT_SCREEN;
    while ((cur_screen >= 0) && (cur_screen < MENUS_QUAN))
    {
        cur_screen = menus[cur_screen]();
    }
    printf("exit: %i", cur_screen);
    return 0;
}
