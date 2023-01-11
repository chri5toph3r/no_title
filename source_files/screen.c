#include "..\header_files\screen.h"


void write_menu(const char *header, int subsec_quan, labels subsec[], index_type style, const char *footer) {
    // HEADER
    center_print(header, SCREEN_WIDTH, '=');
    printf("\n");
    
    // BODY
    int line;
    for (line=1; line<=subsec_quan; line++) {
        if (!(IS_N_FILLED(line))) { break; }
        char index_str[10];
        printf(NUMMED_SUBSEC(trans_index(style, line, index_str), subsec[line-1]));
        printf("\n");
    }
    if (IS_N_FILLED(subsec_quan)) {
        int i;
        for (line=subsec_quan; line<SCREEN_HEIGHT-NOT_BODY_LINES; line++) {
            for (i=0; i<SCREEN_WIDTH; i++) {
                printf(FILL_CHAR);
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
    
    printf(margin);
    printf(text);
    printf(margin);
    if ((SCREEN_WIDTH - strlen(text)) % 2) { printf("%c", symbol); }
}

char* trans_index(index_type style, int index, char *r_str) {
    if (INT_LEN(index) > 10) { return "0"; }
    snprintf(r_str, 10, "%d", index);
    return r_str;
}