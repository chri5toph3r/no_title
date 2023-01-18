#include "../header_files/settings.h"


item header_txt[HEADER_TXTS_Q] = {{
    HEADER_WIDTH,
    HEADER_TXT,
    HEADER_ALIGN, 
    HEADER_SEP
}};
struct container sett_header = {
    SCREEN_WIDTH,
    HEADER_TXTS_Q,
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

item footer_txt[2] = {
    {
        L_FOOTER_WIDTH,
        L_FOOTER_TXT,
        FOOTER_ALIGN, 
        FOOTER_SEP
    },
    {
        R_FOOTER_WIDTH,
        R_FOOTER_TXT,
        FOOTER_ALIGN, 
        FOOTER_SEP
    }
};
struct container sett_footer = {
    SCREEN_WIDTH,
    FOOTER_TXTS_Q,
    footer_txt,
    FOOTER_ALIGN,
    FOOTER_SEP
};

void set_opt_meter(char *buffer)
{
    snprintf(buffer, R_FOOTER_WIDTH, "%i%s", OPTIONS_QUAN, R_FOOTER_TXT);
    sett_footer.texts[1].content = buffer;
}

int settings_menu()
{
    char buffer[R_FOOTER_WIDTH];
    set_opt_meter(buffer);
    write_subsec_menu(sett_header, sett_body, sett_footer);
    
    scanf("%i", &sett_body.top_index);
    if (sett_body.top_index < 1) return -sett_body.top_index;
    sett_body.top_index --;

    return 0;
}
