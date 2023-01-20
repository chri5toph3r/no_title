#ifndef TYPES_H
#define TYPES_H

typedef int (*functions)(void);
typedef char *labels; // [-]

typedef enum
{
    LEFT_TABBED,
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
    // [+] int height;
    char *content;
    align alignment;
    char sep;
};
typedef struct Item item;

 // TODO: rename to line 
 // TODO: make it a type
struct Container
{
    int width;
    // [+] int height;
    int texts_quan;     // TODO: to int items_quan
    item *texts;        // TODO: to item *items
    align alignment;
    char sep;
};

// TODO: rename to container 
// TODO: make it a type
struct Body
{
    int width;
    // [+] int height;
    int subsec_quan;    // TODO: to int lines_quan
    labels *subsec;     // TODO: to line *lines
    int top_index;
    align alignment;
    char sep;
    index_type style;
};

#endif // TYPES_H
