#include <stdio.h>



int main(int argc, char const *argv[])
{
    int height = 10;
    int written_lines = 0;
    int cont_index = 0;
    int conts_quan = 2;
    int conts[] = {3, 3};
    while ((written_lines < height) && (cont_index < conts_quan))
    {
        printf("cont: %d\n", cont_index);
        int cont_lines = 0;
        while ((written_lines < height) && (cont_lines < conts[cont_index]))
        {
            printf("%d\n", written_lines);
            cont_lines++;
            written_lines++;
        }
        printf(
            "printing %d lines of cont%d (line count on %d)\n",
            cont_lines, cont_index, written_lines
        );
        cont_index++;
    }
    if (written_lines < height)
    {
        for (written_lines=written_lines; written_lines<height; written_lines++)
        {
            printf("%d x\n", written_lines);
        }
    }
    printf("finally %d and index %d", written_lines, cont_index);
    return 0;
}
