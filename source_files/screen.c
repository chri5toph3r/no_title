#include "../header_files/screen.h"

/* TODO:
handling height in all writing functions
not yet sure how to do it, but ill try my best

handling one dimension more sure will be tricky, hope i'll be able to pull it off
*/

// aaaa problem with the variablessss
// local variables and pointers to them and they disappear and we got no text when refresh screem
// gotta find a way to transfer pure text from temp arrays or sth 

void write_menu(container *header, area *body, container *footer)
{
    setup_screen();

    // HEADER
    // printf("header\n");   //dev
    if (header->dims->height > 0)
    {
        // printf("create header\n");    // dev
        char *temp[SCREEN_HEIGHT];
        get_container(temp, header);
        update_screen(temp, header->dims->height);
        refresh_screen();
    }

    // BODY
    // printf("body\n");     // dev
    if (body->dims->height > 0)
    {
        // printf("create body\n");  // dev
        char *temp[SCREEN_HEIGHT];
        get_area(temp, body);
        int body_lines = SCREEN_HEIGHT - header->dims->height - footer->dims->height;
        update_screen(temp, body_lines);
    }
    
    // FOOTER
    // printf("footer\n");   // dev
    if (footer->dims->height > 0)
    {
        // printf("create footer\n");    // dev
        char *temp[SCREEN_HEIGHT];
        get_container(temp, footer);
        update_screen(temp, footer->dims->height);
        refresh_screen();
    }
    refresh_screen();
}

char** get_area(char **area_arr, area *area_obj)
{
    // printf("get_area\n");
    if (area_obj->dims->height <= 0) return area_arr;      // guard
    // guard for incorrect top_index value
    if ((area_obj->top_index < 0) || (area_obj->top_index > area_obj->dims->height)) area_obj->top_index = 0;

    int area_line = area_obj->dims->height;
    for (int cont_i = area_obj->top_index; (cont_i < area_obj->conts_quan) && (area_line > 0); cont_i++)
    {
        if (area_obj->conts[cont_i].dims->height <= 0) continue;      // guard

        char *cont_arr[SCREEN_HEIGHT];
        get_container(cont_arr, &(area_obj->conts[cont_i]));
        for (int cont_line = 0; (cont_line < area_obj->conts[cont_i].dims->height) && (area_line > 0); cont_line++)
        {
            char buff[SCREEN_WIDTH+1];
            get_aligned(
                buff,
                area_obj->dims->width,
                cont_arr[cont_line],
                area_obj->conts[cont_i].align
            );
            area_arr[area_line] = buff;
            area_line--;
        }
    }
    return area_arr;
}

char** get_container(char **cont_arr, container *cont_obj)
{
    // printf("\tget_cont\n");
    if (cont_obj->dims->height <= 0) return cont_arr;      // guard
    
    int curr_cont_width = cont_obj->dims->width;
    for (int item_i = 0; (item_i < cont_obj->items_quan) && (curr_cont_width > 0); item_i++)
    {
        if (cont_obj->items[item_i].dims->height <= 0) continue;      // guard
        
        char *item_arr[SCREEN_HEIGHT];
        get_item(item_arr, &(cont_obj->items[item_i]));
        // printf("itemarr0:%s\n", item_arr[0]);
        for (int item_line = 0; (item_line < cont_obj->items[item_i].dims->height) && (curr_cont_width > 0); item_line++)
        {
            cont_arr[item_line] = "";
            static char buff[SCREEN_WIDTH+1];
            curr_cont_width -= snprintf
            (
                buff, 
                curr_cont_width+1, 
                "%s%s", cont_arr[item_line], item_arr[item_line]
            );
            cont_arr[item_line] = buff;
            // printf(">>%s\n", cont_arr[item_line]);
        }
    }
    return cont_arr;
}

char** get_item(char **item_arr, item *item_obj)
{
    // printf("\t\tget_item\n");
    if (item_obj->dims->height <= 0) return item_arr;       // guard

    char *word = strtok(item_obj->content, SPLIT_STR);
    for (int line = 0; line < item_obj->dims->height; line++)
    {
        item_arr[line] = "";
        if (word != NULL)
        {
            // printf("\t\t>%s\n", word);
            // printf("\t\t:%s\n", item_arr[line]);
            static char buff[SCREEN_WIDTH+1];
            get_aligned(buff, item_obj->dims->width, word, item_obj->align);
            item_arr[line] = buff;
            // printf("\t\t>:%s\n", item_arr[line]);
		    word = strtok(NULL, SPLIT_STR);
        } else {
            get_blank_line(item_arr[line], item_obj->dims->width, item_obj->align->align_char);
        }
    }
    return item_arr;
}

// TODO: make it work however is best
char* trans_index(char *buffer, int index, index_type *style)    // TODO: look at it, it's just a dummy now
{
    if (INT_LEN(index) > 10) return "0";
    snprintf(buffer, 10, "%d. ", index);
    return buffer;
}

char* get_blank_line(char* buffer, int width, char filler)
{
    for (int i = 0; i < width; i++)
    {
        buffer[i] = filler;
    }
    buffer[width] = '\0';
    return buffer;
}

/////////////////////////////////////////////////////////
////////////////////      ARRAY      ////////////////////
/////////////////////////////////////////////////////////

int update_screen(char **update, int lines)
{
    int start_l = screen_line;
    for (screen_line = screen_line; (screen_line < SCREEN_HEIGHT) && (screen_line < (start_l + lines)); screen_line++)
    {
        screen[screen_line] = update[screen_line];
    }
    return screen_line < SCREEN_HEIGHT;
}

void refresh_screen()
{
    // cls();
    for (int line = 0; line < screen_line; line++)
    {
        printf("%s", screen[line]);
        screen[line] = '\0';
    }
    screen_line = 0;
}

int setup_screen()
{
    screen_line = 0;
    return 0;
}

/////////////////////////////////////////////////////////
//////////////////      ALIGNMENT      //////////////////
/////////////////////////////////////////////////////////

char* get_aligned(char *buffer, int width, char *text, alignment *align)
{
    // printf("/ get_aligned\n");
    switch (align->align_to)
    {
    case LEFT_TABBED:
        snprintf(buffer, width+1, "\t%s", text);        // TODO: make fun intake fill char
        break;
    case CENTER:
        center(buffer, width, text, align->align_char);
        break;
    case RIGHT:
        align_right(buffer, width, text, align->align_char);
        break;
    default:
        snprintf(buffer, width+1, text);        // TODO: make fun intake fill char
        break;
    }
    return buffer;
}

char* align_right(char *buffer, int width, char *text, char symbol)
{
    char margin[SCREEN_WIDTH+1];
    get_margin(margin, R_MARGIN_LEN(width, text), symbol);
    snprintf(buffer, width+1, "%s%s", margin, text);
    return buffer;
}

char* center(char *buffer, int width, char *text, char symbol)
{
    // printf("/ align center\n");
    char margin[SCREEN_WIDTH+1];
    get_margin(margin, C_MARGIN_LEN(width, text), symbol);
    // printf("margin[%d]:%s\n", width, margin);
    snprintf(buffer, width, "%s%s%s", margin, text, margin);

    // guard when the object can't be centered evenly, a hole creates at the end
    if (width - strlen(buffer)) snprintf(buffer, width+1, "%s%c", buffer, symbol);
    return buffer;
}

char* get_margin(char *margin, int margin_len, char symbol)
{
    if (margin_len > (SCREEN_WIDTH+1)) margin_len = SCREEN_WIDTH+1;

    for (int index=0; index<margin_len; index++)
    {
        margin[index] = symbol;
    }
    margin[margin_len] = '\0';
    return margin;
}
