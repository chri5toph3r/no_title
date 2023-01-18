#include "../header_files/screen.h"


void write_subsec_menu(struct container header, struct body body, struct container footer)
{
    cls();
    int body_lines = SCREEN_HEIGHT - (header.width > 0) - (footer.width > 0);
    // HEADER
    if (header.width > 0)
    {
        char header_line[SCREEN_WIDTH+1];
        get_container_str(header_line, header);
        printf("%s\n", header_line);
    }

    // BODY
    print_body(body_lines, body);

    // FOOTER
    if (footer.width > 0)
    {
        char footer_line[SCREEN_WIDTH+1];
        get_container_str(footer_line, footer);
        printf("%s\n", footer_line);
    }
}

void print_body(int height, struct body body)
{
    // guard for incorrect top_index value
    if ((body.top_index < 0) || (body.top_index > body.subsec_quan)) body.top_index = 0;

    int written_lines = body.subsec_quan - body.top_index;
    // guard for keeping screen height
    if (written_lines > height) written_lines = height;
    int blank_lines = height - written_lines;

    int line;
    if (written_lines > 0)
    {
        for (line=0; line<written_lines; line++)
        {
            print_subsec(line, body);
            printf("\n");
        }
    }
    if (blank_lines > 0)
    {
        for (line=0; line<blank_lines; line++)
        {
            print_blank_line(body.width);
            printf("\n");
        }
    }
}

char* get_container_str(char *cont_str, struct container cont)
{
    if (cont.width > 0)
    {
        char buffer[SCREEN_WIDTH+1] = "";
        int item;
        for (item=0; item<cont.texts_quan; item++)
        {
            char cont_item[SCREEN_WIDTH+1];
            center(cont_item, cont.texts[item].content, cont.texts[item].width, cont.texts[item].sep);
            snprintf(buffer, cont.width, "%s%s", buffer, cont_item);
        }
        center(cont_str, buffer, cont.width, cont.sep);
    }
    return cont_str;
}

void print_subsec(int line, struct body body) {
    int index = body.top_index + line;
    char index_str[10];
    printf(NUMMED_SUBSEC(
        trans_index(index_str, body.style, index+1), 
        body.subsec[index]));
}

void print_blank_line(int width)
{
    int i;
    for (i=0; i<width; i++)
    {
        printf(BLANK_CHAR);
    }
}

char* center(char *r_str, const char *text, int width, char symbol)
{
    int margin_len = MARGIN_LEN(width, text);
    char margin[SCREEN_WIDTH+1];

    int index;
    for (index=0; index<margin_len; index++)
    {
        margin[index] = symbol;
    }
    margin[margin_len] = '\0';
    snprintf(r_str, width, "%s%s%s", margin, text, margin);

    if (width - strlen(r_str)) snprintf(r_str, width+1, "%s%c", r_str, symbol);
    return r_str;
}

char* trans_index(char *r_str, index_type style, int index)
{
    if (INT_LEN(index) > 10) return "0";
    snprintf(r_str, 10, "%d", index);
    return r_str;
}

void cls()
{
    printf(CLEAR_SCREEN);
}
