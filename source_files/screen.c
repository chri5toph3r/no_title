#include "../header_files/screen.h"


void write_menu(const char *header, struct body body, const char *footer) {
    cls();
    int body_lines = SCREEN_HEIGHT - (header != NULL) - (footer != NULL);
    // HEADER
    if (header != NULL) {
        center_print(header, SCREEN_WIDTH, '=');
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
    if (footer != NULL) {
        center_print(footer, SCREEN_WIDTH/2, ' ');
        // char right_footer[SCREEN_WIDTH/2];
        // snprintf(right_footer, SCREEN_WIDTH/2, "%i options", body.subsec_quan);
        // center_print(right_footer, SCREEN_WIDTH/2, ' ');
        printf("\n");
    }
}

void print_subsec(int line, struct body body) {
    int index = body.top_index + line;
    char index_str[10];
    printf(NUMMED_SUBSEC(
        trans_index(body.style, index+1, index_str), 
        body.subsec[index]));
}

void print_blank_line(int width) {
    int i;
    for (i=0; i<width; i++) {
        printf(BLANK_CHAR);
    }
}

void center_print(const char *text, int width, char symbol) {
    int margin_len = MARGIN_LEN(width, text);
    char margin[SCREEN_WIDTH+1];

    int index;
    for (index=0; index<margin_len; index++) {
        margin[index] = symbol;
    }
    margin[margin_len] = '\0';
    
    printf("%s", margin);
    printf("%s", text);
    printf("%s", margin);
    if ((SCREEN_WIDTH - strlen(text)) % 2) { printf("%c", symbol); }
}

char* trans_index(index_type style, int index, char *r_str) {
    if (INT_LEN(index) > 10) { return "0"; }
    snprintf(r_str, 10, "%d", index);
    return r_str;
}

void cls() {
    printf(CLEAR_SCREEN);
}