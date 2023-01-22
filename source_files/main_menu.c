#include "../header_files/main_menu.h"


item title_item = {
    MM_T_WIDTH,
    MM_T_HEIGHT,
    MM_T_TXT,
    MM_T_ALIGN, 
    MM_T_SEP
};
container mm_title = {
    SCREEN_WIDTH,
    MM_T_HEIGHT,
    MM_T_TXTS_Q,
    &title_item,
    MM_T_ALIGN,
    MM_T_SEP
};

item mm_texts[MM_B_OPT_QUAN] = {
    {
        SCREEN_WIDTH,
        MM_B_C_HEIGHT,
        "SINGLE",
        MM_B_ALIGN,
        MM_B_SEP
    },
    {
        SCREEN_WIDTH,
        MM_B_C_HEIGHT,
        "MULTI",
        MM_B_ALIGN,
        MM_B_SEP
    },
    {
        SCREEN_WIDTH,
        MM_B_C_HEIGHT,
        "SETTINGS",
        MM_B_ALIGN,
        MM_B_SEP
    },
};
container mm_options[MM_B_OPT_QUAN] = {
    {
        SCREEN_WIDTH,
        MM_B_C_HEIGHT,
        MM_B_C_TXT_QUAN,
        &(mm_texts[0]),
        MM_B_ALIGN,
        MM_B_SEP
    },
    {
        SCREEN_WIDTH,
        MM_B_C_HEIGHT,
        MM_B_C_TXT_QUAN,
        &(mm_texts[1]),
        MM_B_ALIGN,
        MM_B_SEP
    },
    {
        SCREEN_WIDTH,
        MM_B_C_HEIGHT,
        MM_B_C_TXT_QUAN,
        &(mm_texts[2]),
        MM_B_ALIGN,
        MM_B_SEP
    },
};
area mm_body = {
    SCREEN_WIDTH,
    MM_B_HEIGHT,
    MM_B_OPT_QUAN,
    MM_B_DEFAULT_TOP,
    mm_options,
    MM_B_ALIGN,
    MM_B_SEP,
    MM_B_STYLE
};


int _main_menu()
{
    mm_footer.height = 0;
    write_menu(mm_title, mm_body, mm_footer);

    scanf("%i", &mm_body.top_index);
    if (mm_body.top_index < 1) return -mm_body.top_index;
    mm_body.top_index --;

    return 0;
}