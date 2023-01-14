#include "../header_files/screen.h"


void write_menu(const char *header, struct body menu, const char *footer) {
    printf(CLEAR_SCREEN);
    // HEADER
    center_print(header, SCREEN_WIDTH, '=');
    printf("\n");

    if ((menu.top_index < 0) || (menu.top_index > menu.subsec_quan)) {
        menu.top_index = 0;
    }

    // BODY
    int written_lines = menu.subsec_quan - menu.top_index;
    int blank_lines = BODY_LINES - written_lines;

    int line;
    if (written_lines > 0) {
        for (line=0; line<written_lines; line++) {
            int index = menu.top_index + line;
            char index_str[10];
            printf(NUMMED_SUBSEC(
                trans_index(menu.style, index+1, index_str), 
                menu.subsec[index]));
            printf("\n");
        }
    }
    if (blank_lines > 0) {
        int i;
        for (line=0; line<blank_lines; line++) {
            for (i=0; i<SCREEN_WIDTH; i++) {
                printf(BLANK_CHAR);
            }
            printf("\n");
        }
    }

    // FOOTER
    center_print(footer, SCREEN_WIDTH/2, ' ');
    printf("\n");
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