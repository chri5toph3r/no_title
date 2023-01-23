#include "../header_files/screen.h"

/* TODO:
handling height in all writing functions
not yet sure how to do it, but ill try my best

handling one dimension more sure will be tricky, hope i'll be able to pull it off
*/

void write_menu(container header, area body, container footer)
{
    cls();
    // HEADER
    if (header.height > 0)
    {
        print_container(header);
        // dev
        // char header_line[SCREEN_WIDTH+1];
        // print_container(header_line, header);
        // printf("%s\n", header_line); dev
        // printf("%s", header_line);
    }

    // BODY
    if (body.height > 0)
    {
        int body_lines = SCREEN_HEIGHT - header.height - footer.height;
        print_area(body_lines, body);
    }
    
    // FOOTER
    if (footer.height > 0)
    {
        print_container(footer);
        // dev
        // char footer_line[SCREEN_WIDTH+1];
        // print_container(footer_line, footer);
        // printf("%s\n", footer_line); dev
        // printf("%s", footer_line);
    }
}

void print_area(int height, area area_obj)
{
    if (area_obj.height <= 0) return;        // guard
    // guard for incorrect top_index value
    /* ??
    the index should probably be to container, not line
    BUT, it could be to line, or there maybe should be 2 ways to define it,
    probably the best way is to just store it as a line, and then maybe calculate it,
    if sb wants to focus on some index, so by default it'd scroll to line
    */
    if ((area_obj.top_index < 0) || (area_obj.top_index > area_obj.conts_quan)) area_obj.top_index = 0;

    // int written_lines = area_obj.conts_quan - area_obj.top_index; dev
    // if (written_lines > height) written_lines = height;     // guard for keeping screen height dev
    int written_lines = 0;
    int cont_index = 0;
    while ((written_lines < height) && (cont_index < area_obj.conts_quan))
    {
        // printf("cont: %d\n", cont_index); dev
        int cont_lines = 0;
        while ((written_lines < height) && (cont_lines < area_obj.conts[cont_index].height))
        {
            // printf("%d\n", written_lines); dev
            cont_lines++;
            written_lines++;
        }
        // dev
        // printf(
        //     "printing %d lines of cont%d (line count on %d)\n",
        //     cont_lines, cont_index, written_lines
        // ); 
        print_container(area_obj.conts[cont_index]);
        cont_index++;
    }
    if (written_lines < height)
    {
        for (written_lines=written_lines; written_lines<height; written_lines++)
        {
            print_blank_line(area_obj.width);
        }
    }
    /* dev
    int line;
    if (written_lines > 0)
    {
        for (line=0; line<written_lines; line++)
        {
            print_container(area_obj.conts[line]);
            // print_container(line, area_obj);
            // printf("\n");
        }
    }
    if (written_lines < height)
    {
        for (line=written_lines; line<height; line++)
        {
            print_blank_line(area_obj.width);
            // printf("\n");
        }
    }
    */
}

// char* print_container(char *cont_str, container cont_obj)
/* ??
if could go like this:
either there is no dedicated item for index,
and print container adds it, while shortening some widths,
or
TODO:
there is dedicated item for index,
which would make program predictable,
and i think this is the way to go
*/
void print_container(container cont_obj)
{
    if (cont_obj.height <= 0) return;     // guard
    char buffer[SCREEN_WIDTH+1] = "";
    for (int item=0; item<cont_obj.items_quan; item++)
    {
        char cont_item[SCREEN_WIDTH+1];
        get_aligned
        (
            cont_item, 
            cont_obj.items[item].width, 
            cont_obj.items[item].content, 
            cont_obj.items[item].alignment, 
            cont_obj.items[item].symbol
        );
        snprintf(buffer, cont_obj.width+1, "%s%s", buffer, cont_item);
    }
    // !: not sure if a buffer could've been the same as the text, so gotta check that after cleaning
    // still tho, this will be changed when all the planned changes are done
    // get_aligned(cont_str, cont_obj.width, buffer, cont_obj.alignment, cont_obj.symbol); dev
    get_aligned(buffer, cont_obj.width, buffer, cont_obj.alignment, cont_obj.symbol);
    printf(buffer); printf("\n");
    // return cont_str; dev
}

void print_item(item item_obj, int index, index_type style) {
    if (item_obj.height <= 0) return;       // guard
    // int index = body.top_index + line;
    
    /* ??
    this probably should not be here,
    instead, seperate item for index should be created,
    maybe with custom text, so check would determine,
    or just some bool or even index to be displayed inside item struct, idk
    for now this has to do
    */
    int index_len = 0;
    if (style != NONE)
    {
        index_len = INT_LEN(index);
        char index_str[10];
        printf(trans_index(index_str, style, index+1));
    }

    char subsec_txt[SCREEN_WIDTH+1];
    // !: substract index string length!!!
    printf(get_aligned(
        subsec_txt,
        item_obj.width-index_len,
        item_obj.content,
        item_obj.alignment,
        item_obj.symbol
    ));
}

char* trans_index(char *buffer, int index, index_type style)    // TODO: look at it, it's just a dummy now
{
    if (INT_LEN(index) > 10) return "0";
    snprintf(buffer, 10, "%d. ", index);
    return buffer;
}

void print_blank_line(int width)
{
    for (int i=0; i<width; i++)
    {
        printf(BLANK_CHAR);
    }
    printf("\n");
}


char* get_aligned(char *buffer, int width, char *text, align alignment, char symbol)
{
    switch (alignment)
    {
    case LEFT_TABBED:
        snprintf(buffer, width+1, "\t%s", text);
        break;
    case CENTER:
        center(buffer, width, text, symbol);
        break;
    case RIGHT:
        align_right(buffer, width, text, symbol);
        break;
    default:
        snprintf(buffer, width+1, text);
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
    char margin[SCREEN_WIDTH+1];
    get_margin(margin, C_MARGIN_LEN(width, text), symbol);
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
