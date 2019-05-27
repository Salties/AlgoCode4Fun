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
    j = heightSize - 1;
    
    while(i < j - 1)
    {
        //Record the current area.
        maxarea = max(maxarea, area(height, heightSize, i, j));
        
        //Move the boundary.
        if(height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
        
    }

	return maxarea;
}

#if 0
int hist[] = {
	1, 8, 6, 2, 5,
	4, 8, 3, 7
};
#endif

int hist[] = {1,2,4,3};

int main()
{
	printf("%d\n", maxArea(hist, sizeof(hist) / sizeof(int)));
	return 0;
}
