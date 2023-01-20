#include "../header_files/screen.h"


void write_menu(struct Container header, struct Body body)
{
    cls();
    // TITLE
    char temp_cont[SCREEN_WIDTH+1];
    // to fun: print_title()
    get_cont_str(temp_cont, header);
    printf("\n%s\n\n", temp_cont);
    
    // BODY
    print_body(SCREEN_HEIGHT - 3, body);
}

void write_subsec_menu(struct Container header, struct Body body, struct Container footer)
{
    cls();
    // HEADER
    if (header.width > 0)
    {
        char header_line[SCREEN_WIDTH+1];
        get_cont_str(header_line, header);
        printf("%s\n", header_line);
    }

    // BODY
    int body_lines = SCREEN_HEIGHT - (header.width > 0) - (footer.width > 0);
    print_body(body_lines, body);

    // FOOTER
    if (footer.width > 0)
    {
        char footer_line[SCREEN_WIDTH+1];
        get_cont_str(footer_line, footer);
        printf("%s\n", footer_line);
    }
}

char* get_cont_str(char *cont_str, struct Container cont)
{
    if (cont.width > 0)
    {
        char buffer[SCREEN_WIDTH+1] = "";
        for (int item=0; item<cont.texts_quan; item++)
        {
            char cont_item[SCREEN_WIDTH+1];
            get_aligned
            (
                cont_item, 
                cont.texts[item].width, 
                cont.texts[item].content, 
                cont.texts[item].alignment, 
                cont.texts[item].sep
            );
            snprintf(buffer, cont.width, "%s%s", buffer, cont_item);
        }
        get_aligned(cont_str, cont.width, buffer, cont.alignment, cont.sep);
    }
    return cont_str;
}

void print_body(int height, struct Body body)
{
    // guard for incorrect top_index value
    if ((body.top_index < 0) || (body.top_index > body.subsec_quan)) body.top_index = 0;

    int written_lines = body.subsec_quan - body.top_index;
    // guard for keeping screen height
    if (written_lines > height) written_lines = height;

    int line;
    if (written_lines > 0)
    {
        for (line=0; line<written_lines; line++)
        {
            print_subsec(line, body);
            printf("\n");
        }
    }
    if (written_lines < height)
    {
        for (line=written_lines; line<height; line++)
        {
            print_blank_line(body.width);
            printf("\n");
        }
    }
}

void print_subsec(int line, struct Body body) {
    int index = body.top_index + line;
    char index_str[10];
    char subsec_txt[SCREEN_WIDTH+1];
    printf(trans_index(index_str, body.style, index+1));
    // !: substract index string length!!!
    printf(get_aligned(subsec_txt, body.width-3, body.subsec[index], body.alignment, body.sep));
}

char* trans_index(char *buffer, index_type style, int index)
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
}

char* get_aligned(char *buffer, int width, char *text, align alignment, char symbol)
{
    switch (alignment)
    {
    case LEFT_TABBED:
        snprintf(buffer, width+1, "\t%s", text);
        break;
    case CENTER:
        center(buffer, text, width, symbol);
        break;
    case RIGHT:
        align_right(buffer, text, width, symbol);
        break;
    default:
        snprintf(buffer, width+1, text);
        break;
    }
    return buffer;
}

char* align_right(char *buffer, char *text, int width, char symbol)
{
    char margin[SCREEN_WIDTH+1];
    get_margin(R_MARGIN_LEN(width, text), margin, symbol);
    snprintf(buffer, width+1, "%s%s", margin, text);
    return buffer;
}

char* center(char *buffer, char *text, int width, char symbol)
{
    char margin[SCREEN_WIDTH+1];
    get_margin(C_MARGIN_LEN(width, text), margin, symbol);
    snprintf(buffer, width, "%s%s%s", margin, text, margin);

    // guard when the object can't be centered evenly, a hole creates at the end
    if (width - strlen(buffer)) snprintf(buffer, width+1, "%s%c", buffer, symbol);
    return buffer;
}

char* get_margin(int margin_len, char *margin, char symbol)
{
    if (margin_len > (SCREEN_WIDTH+1)) margin_len = SCREEN_WIDTH+1;

    for (int index=0; index<margin_len; index++)
    {
        margin[index] = symbol;
    }
    margin[margin_len] = '\0';
    return margin;
}
