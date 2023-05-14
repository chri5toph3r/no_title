#include "../header_files/main_menu.h"

dimensions mm_title_dims = {
    .height = MM_T_HEIGHT,
    .width = MM_T_WIDTH
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


dimensions mm_texts_dims = {
    .height = 1,
    .width= MM_B_WIDTH
};

alignment mm_texts_align = {
    .align_to = MM_B_ALIGN,
    .align_char = MM_B_FILL
};

item mm_texts[MM_B_C_QUAN] = {
    {
        .dims = &mm_texts_dims,
        .content = "OPT 0",
        .align = &mm_texts_align
    },
    {
        .dims = &mm_texts_dims,
        .content = "OPT 1",
        .align = &mm_texts_align
    },
    {
        .dims = &mm_texts_dims,
        .content = "OPT 2",
        .align = &mm_texts_align
    }
};

container mm_options[MM_B_C_QUAN] = {
    {
        .dims = &mm_texts_dims,
        .items_quan = MM_B_C_TXT_QUAN,
        .items = &(mm_texts)[0],
        .align = &mm_texts_align
    },
    {
        .dims = &mm_texts_dims,
        .items_quan = MM_B_C_TXT_QUAN,
        .items = &(mm_texts)[1],
        .align = &mm_texts_align
    },
    {
        .dims = &mm_texts_dims,
        .items_quan = MM_B_C_TXT_QUAN,
        .items = &(mm_texts)[2],
        .align = &mm_texts_align
    }
};

dimensions mm_body_dims = {
    .height = MM_B_HEIGHT,
    .width = MM_B_WIDTH
};

alignment mm_body_align = {
    MM_B_ALIGN,
    MM_B_FILL
};

dimensions zero_height = {
    .height = 0
};

area mm_body = {
    .dims = &mm_body_dims,
    .conts_quan = MM_B_C_QUAN,
    .top_index = MM_B_DEFAULT_TOP,
    .conts = mm_options,
    .align = &mm_body_align,
    .style = NONE
};

item footer_item = {
    .dims = &mm_title_dims,
    .content = "ST00PKA",
    .align = &mm_title_align
};

container mm_footer = {
    .dims = &mm_title_dims,
    .items_quan = MM_T_TXTS_Q,
    .items = &footer_item,
    .align = &mm_title_align
};

int _main_menu()
{
    write_menu(&mm_title, &mm_body, &mm_footer);

    printf("> ");
    scanf("%i", &(mm_body.top_index));
    if (mm_body.top_index < 1) return -mm_body.top_index;
    mm_body.top_index --;

    return 0;
}