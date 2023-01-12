#include "../header_files/settings.h"

labels options[OPTIONS_QUAN] = {
    "GENERAL",
    "GRAPHICS",
    "SOUND",
    "LANGUAGE"
};


int settings_menu() {
    const char* header = "[ SETTINGS ]";
    const char* footer =  "created by kk13";
    index_type style = arabic_num;
    struct body sett_body = {
        OPTIONS_QUAN,
        options,
        style,
        0
    };
    
    write_menu(header, sett_body, footer);
    return 0;
}