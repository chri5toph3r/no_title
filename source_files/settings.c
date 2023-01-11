#include "..\header_files\settings.h"

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
    write_menu(header, OPTIONS_QUAN, options, style, footer);
    return 1;
}