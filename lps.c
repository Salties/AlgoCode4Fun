#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define DNM ('#') //Mancherer's form Denomitor.

int max(int x, int y)
{
    return (x > y? x: y);
}

int Expand(char *s, const int slen, int pos)
{
    int i;
    
    for(i = 0; pos - i >= 0 && pos + i < slen; i++)
    {
        if(s[pos - i] != s[pos + i])
            break;
    }

    return i - 1;
}

char* longestParlindromicString(char *s)
{
    int i;
    char *cs, *cm;
    char *ret;
    char *sMan;
    int sLen,sManLen;
    int lpsIdx, lpsManIdx;
    int lpsLen, lpsManLen, lpsManIdxLen;
    int retLen;

    //Compute the length of s.
    for(cs = s, sLen = 0; *cs != '\0'; sLen++, cs++);
    sManLen = 2 * sLen + 1;
    
    //Parse the string into Manacher's form.
    sMan = malloc(sManLen);
    for(cs = s, cm = sMan; *cs != '\0'; cs++, cm+=2)
    {
        cm[0] = DNM;
        cm[1] = *cs;
    }
    cm[0] = '#';
    cm[1] = '\0';

    //Search for most expandable length at each position.
    lpsManIdx = 0;
    lpsManLen = 0;
    for(i = 0; i < sManLen; i++)
    {
        lpsManIdxLen = Expand(sMan, sManLen, i);
        if(lpsManIdxLen > lpsManLen)
        {
            lpsManIdx = i;
            lpsManLen = lpsManIdxLen;
        }
    }
    
    //Conver index in Man's form back into normal form.
    lpsIdx = (lpsManLen - 1) / 2;
    lpsLen = lpsManLen;

    //Compute length of LPS.
    for(retLen = 0, i = lpsManIdx - lpsManLen; i < lpsManIdx + lpsManLen; i++)
    {
        if(sMan[i] != DNM)
            retLen++;
    }

    //Copy LPS from Mancherer's form.
    ret = malloc(retLen);
    for(cs = ret, i = lpsManIdx - lpsManLen; i < lpsManIdx + lpsManLen; i++)
    {
        if(sMan[i] != DNM)
        {
            *cs = sMan[i];
            cs++;
        }
    }

    //Clean up.
    free(sMan);

    return ret;
}

int main(int argc, char *argv[])
{
    char S[] = "abacaba";
    printf("%s\n", longestParlindromicString(argv[1]));
    return 0;
}
