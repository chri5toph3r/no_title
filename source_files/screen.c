#include "../header_files/screen.h"


void write_menu(struct container header, struct body body, struct container footer) {
    cls();
    int body_lines = SCREEN_HEIGHT - (header.width > 0) - (footer.width > 0);
    // HEADER
    if (header.width > 0) {
        char header_line[SCREEN_WIDTH+1];
        printf(center(header_line, header.texts[0].content, header.texts[0].width, header.texts[0].sep));
        // center_print(header.texts[0].content, header.texts[0].width, header.texts[0].sep);
        printf("\n");
    }

    // BODY
    if ((body.top_index < 0) || (body.top_index > body.subsec_quan)) {
        body.top_index = 0;
    }
    int written_lines = body.subsec_quan - body.top_index;
    if (written_lines > body_lines) written_lines = body_lines;
    int blank_lines = body_lines - written_lines;

    int line;
    if (written_lines > 0) {
        for (line=0; line<written_lines; line++) {
            print_subsec(line, body);
            printf("\n");
        }
    }
    if (blank_lines > 0) {
        for (line=0; line<blank_lines; line++) {
            print_blank_line(body.width);
            printf("\n");
        }
    }

    // FOOTER
    if (footer.width > 0) {
        char footer_line[SCREEN_WIDTH+1] = "";
        int i_txt;
        for (i_txt=0; i_txt<footer.texts_quan; i_txt++) {
            char footer_item[SCREEN_WIDTH+1];
            center(footer_item, footer.texts[i_txt].content, footer.texts[i_txt].width, footer.texts[i_txt].sep);
            snprintf(footer_line, footer.width, "%s%s", footer_line, footer_item);
        }
        char temp[SCREEN_WIDTH+1];
        printf(center(temp, footer_line, footer.width, footer.sep));
        printf("\n");
    }
}

// void print_texts_line(struct container line) {}

// void print_body(struct body body) {}

void print_subsec(int line, struct body body) {
    int index = body.top_index + line;
    char index_str[10];
    printf(NUMMED_SUBSEC(
        trans_index(index_str, body.style, index+1), 
        body.subsec[index]));
}

void print_blank_line(int width) {
    int i;
    for (i=0; i<width; i++) {
        printf(BLANK_CHAR);
    }
}

char* center(char* r_str, const char *text, int width, char symbol) {
    int margin_len = MARGIN_LEN(width, text);
    char margin[SCREEN_WIDTH+1];

    int index;
    for (index=0; index<margin_len; index++) {
        margin[index] = symbol;
    }
    margin[margin_len] = '\0';
    snprintf(r_str, width, "%s%s%s", margin, text, margin);

    if (width - strlen(r_str)) { 
        snprintf(r_str, width+1, "%s%c", r_str, symbol);
    }
    return r_str;
}

char* trans_index(char *r_str, index_type style, int index) {
    if (INT_LEN(index) > 10) { return "0"; }
    snprintf(r_str, 10, "%d", index);
    return r_str;
}

void cls() {
    printf(CLEAR_SCREEN);
}
