#ifndef TYPES_H
#define TYPES_H

typedef int (*functions)(void);

typedef enum
{
    LEFT,
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
    int height;
    char *content;
    align alignment;
    char symbol;
};
typedef struct Item item;

struct Container
{
    int width;
    int height;
    int items_quan;
    item *items;
    align alignment;
    char symbol;
};
typedef struct Container container;

struct Area
{
    int width;
    int height;
    int conts_quan;
    int top_index;
    container *conts;
    align alignment;
    char symbol;
    index_type style;
};
typedef struct Area area;

#endif // TYPES_H
