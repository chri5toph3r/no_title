#ifndef TYPES_H
#define TYPES_H

#define SPLIT_STR       "\n"

typedef int (*functions)(void);

typedef enum
{
    LEFT,
    LEFT_TABBED,
    CENTER,
    RIGHT
} alignments;

typedef enum
{
    NONE,
    ARABIC_NUM,
    ROMAN_UPP_NUM,
    ROMAN_LOW_NUM,
    UPP_ALPHA,
    LOW_ALPHA
} index_type;

struct Dimensions
{
    int height;
    int width;
};
// width, height
typedef struct Dimensions dimensions;

struct Alignment
{
    alignments align_to;
    char align_char;
};
// align, char
typedef struct Alignment alignment;


struct Item
{
    dimensions *dims;
    char *content;
    alignment *align;
};
// .*dims, *content, *align
typedef struct Item item;

struct Container
{
    dimensions *dims;
    int items_quan;
    item *items;
    alignment *align;
};
// .*dims, items_q, *items, *align
typedef struct Container container;

struct Area
{
    dimensions *dims;
    int conts_quan;
    int top_index;
    container *conts;
    alignment *align;
    index_type style;
};
// .*dims, conts_q, top_i, *conts, *align, style
typedef struct Area area;

#endif // TYPES_H
