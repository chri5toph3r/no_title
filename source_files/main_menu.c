#include "../header_files/main_menu.h"

item title_item[MM_T_TXTS_Q] = {{
    MM_T_WIDTH,
    MM_T_TXT,
    MM_T_ALIGN, 
    MM_T_SEP
}};
struct Container mm_title = {
    SCREEN_WIDTH,
    MM_T_TXTS_Q,
    title_item,
    MM_T_ALIGN,
    MM_T_SEP
};

labels mm_options[MM_B_OPT_QUAN] = {
    "SINGLE",
    "MULTI",
    "SETTINGS"
};
struct Body mm_body = {
    SCREEN_WIDTH,
    MM_B_OPT_QUAN,
    mm_options,
    MM_B_DEFAULT_TOP,
    MM_B_ALIGN,
    MM_B_SEP,
    MM_B_STYLE
};


int _main_menu()
{
    write_menu(mm_title, mm_body);

    scanf("%i", &mm_body.top_index);
    if (mm_body.top_index < 1) return -mm_body.top_index;
    mm_body.top_index --;

    return 0;
}