#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int min(int x, int y)
{
	return (x < y ? x : y);
}

int max(int x, int y)
{
	return (x > y ? x : y);
}

int area(int *height, int heightSize, int start, int end)
{
	return (end - start) * min(height[start], height[end]);
}

int maxArea(int *height, int heightSize)
{
    int i, j;
    int maxarea = 0;
    
    i = 0;
    j = 1;
    for(i = 0; i < j; i++)
    {
        for(j = 1; j < heightSize; j++)
        {
            maxarea = max(maxarea, area(height, heightSize, i, j));
        }
    }

	return maxarea;
}

int hist[] = {
	1, 8, 6, 2, 5,
	4, 8, 3, 7
};

int main()
{
	printf("%d\n", maxArea(hist, sizeof(hist) / sizeof(int)));
	return 0;
}
