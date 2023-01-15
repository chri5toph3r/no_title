#ifndef TYPES_H
#define TYPES_H

typedef int (*functions)(void);
typedef const char *labels;

typedef enum {
    LEFT,
    CENTER,
    RIGHT
} align;

typedef enum {
    ARABIC_NUM,
    ROMAN_UPP_NUM,
    ROMAN_LOW_NUM,
    UPP_ALPHA,
    LOW_ALPHA
} index_type;

struct txt {
    int width;
    const char *content;
    align align;
    char sep;
};
typedef struct txt txt;

struct texts_line {
    int width;
    int texts_quan;
    txt *texts;
    align align;    // these won't be used for now, center_print() needs to be just center, so that there are strings that can be in fact centered
    char sep;       // these won't be used for now, center_print() needs to be just center, so that there are strings that can be in fact centered
};

struct body {
    int width;
    int subsec_quan;
    labels *subsec;
    int top_index;
    align alignment;
    index_type style;
};
#endif // TYPES_H
