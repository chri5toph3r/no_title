#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void changer(char *buff)
{
    sprintf(buff, "bb");
}

int main(int argc, char const *argv[])
{
    char *arr[10];
    char buff[10];
    changer(buff);
    arr[0] = buff;
    printf("%s\n%s", buff, arr[0]);
    // printer(screen, 2);
}
