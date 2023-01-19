#include "../header_files/screen.h"


void write_menu(struct Container header, struct Body body)
{
    cls();
    // TITLE
    char temp_cont[SCREEN_WIDTH+1];
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
            center(cont_item, cont.texts[item].content, cont.texts[item].width, cont.texts[item].sep);
            snprintf(buffer, cont.width, "%s%s", buffer, cont_item);
        }
        center(cont_str, buffer, cont.width, cont.sep);
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
    //get_aligned_str(subsec_txt...)
    center(subsec_txt, body.subsec[index], body.width, ' ');
    printf
    (
        NUMMED_SUBSEC,
        trans_index(index_str, body.style, index+1),
        subsec_txt
        //body.subsec[index]
    );
}

void print_blank_line(int width)
{
    for (int i=0; i<width; i++)
    {
        printf(BLANK_CHAR);
    }
}

// char* get_aligned_str()
// char* align_right()

char* center(char *r_str, const char *text, int width, char symbol)
{
    int margin_len = MARGIN_LEN(width, text);
    if (margin_len > SCREEN_WIDTH) margin_len = SCREEN_WIDTH;
    char margin[SCREEN_WIDTH+1];

    for (int index=0; index<margin_len; index++)
    {
        margin[index] = symbol;
    }
    margin[margin_len] = '\0';
    snprintf(r_str, width, "%s%s%s", margin, text, margin);

    // when the object can't be centered evenly, a hole creates at the end
    if (width - strlen(r_str)) snprintf(r_str, width+1, "%s%c", r_str, symbol);
    return r_str;
}

char* trans_index(char *r_str, index_type style, int index)
{
    if (INT_LEN(index) > 10) return "0";
    snprintf(r_str, 10, "%d", index);
    return r_str;
}
