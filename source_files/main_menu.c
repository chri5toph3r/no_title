#include "../header_files/main_menu.h"

dimensions mm_title_dims = {
    .width = MM_T_WIDTH,
    .height = MM_T_HEIGHT
};

alignment mm_title_align = {
    .align_to = MM_T_ALIGN,
    .align_char = MM_T_FILL
};

item title_item = {
    .dims = &mm_title_dims,
    .content = MM_T_TXT,
    .align = &mm_title_align
};

container mm_title = {
    .dims = &mm_title_dims,
    .items_quan = MM_T_TXTS_Q,
    .items = &title_item,
    .align = &mm_title_align
};

dimensions zero_height = {
    .height = 0
};

area mm_body = {
    .dims = &zero_height
};

container mm_footer = {
    .dims = &zero_height
};

int _main_menu()
{
    write_menu(&mm_title, &mm_body, &mm_footer);

    scanf("%i", &(mm_body.top_index));
    if (mm_body.top_index < 1) return -mm_body.top_index;
    mm_body.top_index --;

    return 0;
}