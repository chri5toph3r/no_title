#include "../header_files/main.h"


int main(int argc, char const *argv[])
{
    int cur_screen = DEF_SCREEN;
    while ((cur_screen >= 0) && (cur_screen < MENUS_QUAN)) {
        cur_screen = menus[cur_screen]();
    }
    printf("exit: %i", cur_screen);
    return 0;
}
