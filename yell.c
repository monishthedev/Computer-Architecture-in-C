#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
   
    if (argc == 2) {
        char *val = argv[1];
        if (argv[1][0] != '\0') {
            for (int i = 0; val[i] != '\0'; i++)//as long as val isn't a null byte
            {
                printf("%c", toupper(val[i]));
            }
            printf("%c%c%c", '!', '!', '\n');
            }
    }
    else{
    return 0;
    }
}


