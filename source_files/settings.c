#include "../header_files/settings.h"


item header_item[SETT_H_TXTS_Q] = {{
    SETT_H_WIDTH,
    SETT_H_TXT,
    SETT_H_ALIGN, 
    SETT_H_SEP
}};
struct Container sett_header = {
    SCREEN_WIDTH,
    SETT_H_TXTS_Q,
    header_item,
    SETT_H_ALIGN,
    SETT_H_SEP
};

labels sett_options[SETT_B_OPT_QUAN] = {
    "GENERAL",
    "GRAPHICS",
    "SOUND",
    "LANGUAGE"
};
struct Body sett_body = {
    SCREEN_WIDTH,
    SETT_B_OPT_QUAN,
    sett_options,
    SETT_B_DEFAULT_TOP,
    SETT_B_ALIGN,
    SETT_B_SEP,
    SETT_B_STYLE
};

item footer_item[2] = {
    {
        SETT_LF_WIDTH,
        SETT_LF_TXT,
        SETT_F_ALIGN, 
        SETT_F_SEP
    },
    {
        SETT_RF_WIDTH,
        SETT_RF_TXT,
        SETT_F_ALIGN, 
        SETT_F_SEP
    }
};
struct Container sett_footer = {
    SCREEN_WIDTH,
    SETT_F_TXTS_Q,
    footer_item,
    SETT_F_ALIGN,
    SETT_F_SEP
};

void set_opt_meter(char *buffer)
{
    snprintf(buffer, SETT_RF_WIDTH, "%i%s", SETT_B_OPT_QUAN, SETT_RF_TXT);
    sett_footer.texts[1].content = buffer;
}

int _settings_menu()
{
    char buffer[SETT_RF_WIDTH];
    set_opt_meter(buffer);
    write_subsec_menu(sett_header, sett_body, sett_footer);
    
    scanf("%i", &sett_body.top_index);
    if (sett_body.top_index < 1) return -sett_body.top_index;
    sett_body.top_index --;

    return 1;
}
