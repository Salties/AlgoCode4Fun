#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_DIGIT 20


bool isPalindrome(int x){
    int digits[MAX_DIGIT] = {0};
    int i,j;
    
    if(x < 0)
        return false;
    
    if(x == 0)
        return true;
    
    //Conver x into array of digits.
    for(i = 0; x != 0; i++)
    {
        digits[i] = x % 10;
        x /= 10;
    }
    i--;
    
    //Test Palindrome.
    for(j = 0; i >= j; j++, i--)
    {
        if(digits[i] != digits[j])
            return false;
    }
    
    return true;
}

int main(int argc, char* argv[])
{
    printf("%d\n", isPalindrome(atoi(argv[1])));
    return 0;
}
