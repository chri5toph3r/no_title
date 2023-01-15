#include "../header_files/settings.h"


txt header_txt[] = {{
    HEADER_LENGTH,
    HEADER_TXT,
    HEADER_ALIGN, 
    HEADER_SEP
}};
struct texts_line sett_header = {
    SCREEN_WIDTH,
    1,
    header_txt,
    HEADER_ALIGN,
    HEADER_SEP
};

labels options[OPTIONS_QUAN] = {
    "GENERAL",
    "GRAPHICS",
    "SOUND",
    "LANGUAGE"
};
struct body sett_body = {
    SCREEN_WIDTH,
    OPTIONS_QUAN,
    options,
    BODY_DEFAULT_TOP,
    BODY_ALIGN,
    BODY_STYLE
};

txt footer_txt[] = {
    {
        L_FOOTER_LENGTH,
        L_FOOTER_TXT,
        FOOTER_ALIGN, 
        FOOTER_SEP
    },
    {
        R_FOOTER_LENGTH,
        L_FOOTER_TXT,
        FOOTER_ALIGN, 
        FOOTER_SEP
    }
};
struct texts_line sett_footer = {
    SCREEN_WIDTH,
    1,
    footer_txt,
    FOOTER_ALIGN,
    FOOTER_SEP
};


int settings_menu() {
    write_menu(HEADER_TXT, sett_body, L_FOOTER_TXT);
    
    scanf("%i", &sett_body.top_index);
    if (sett_body.top_index < 1) return -sett_body.top_index;
    sett_body.top_index --;

    return 0;
}