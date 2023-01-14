#include "../header_files/settings.h"

labels options[OPTIONS_QUAN] = {
    "GENERAL",
    "GRAPHICS",
    "SOUND",
    "LANGUAGE"
};

struct body sett_body = {
    OPTIONS_QUAN,
    options,
    arabic_num,
    0,
};


int settings_menu() {
    write_menu(MENU_HEADER, sett_body, MENU_FOOTER);
    
    scanf("%i", &sett_body.top_index);
    sett_body.top_index --;

    return 0;
}