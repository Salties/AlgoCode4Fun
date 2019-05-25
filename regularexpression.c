#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

bool regularExpression(char *regular, char *str)
{
    char *r, *s;

    //Init
    r = regular;
    s = str;

    //Match string.
    while(!(*r == '\0' && *s == '\0'))
    {
        if(*r == '\0')
            return false;

        else if(*s == '\0')
            return false;

        else if(*r == '?' || *r == *s)
        {
            r++;
            s++;
            continue;
        }

        else if(*r == '*')
        {
            //Move to the next to match.
            while(*r == '*')
            {
                r++;
                s++;
            }

            while(*r != *s && *s != '\0')
                s++;
            continue;
        }
        //No match.
        else
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char* argv[])
{
    printf("%d\n", regularExpression(argv[1], argv[2]));
    return 0;
}
