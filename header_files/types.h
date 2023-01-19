#ifndef TYPES_H
#define TYPES_H

typedef int (*functions)(void);
typedef char *labels;

typedef enum
{
    LEFT,
    CENTER,
    RIGHT
} align;

typedef enum
{
    NONE,
    ARABIC_NUM,
    ROMAN_UPP_NUM,
    ROMAN_LOW_NUM,
    UPP_ALPHA,
    LOW_ALPHA
} index_type;

struct Item
{
    int width;
    char *content;
    align align;
    char sep;
};
typedef struct Item item;

struct Container
{
    int width;
    int texts_quan;
    item *texts;
    align align;
    char sep;
};

struct Body
{
    int width;
    int subsec_quan;
    labels *subsec;
    int top_index;
    align alignment;
    index_type style;
};

#endif // TYPES_H
