#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_STACK_SIZE 1024

//Definition for a binary tree node.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* InitNode(int val)
{
    struct TreeNode *newnode = NULL;
    
    newnode = malloc(sizeof(struct TreeNode));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

typedef struct 
{
    int *vals;
    int count;
} Stack;

Stack* InitStack(int maxsize)
{
    Stack *s;

    s = malloc(sizeof(Stack));
    s->vals = malloc(sizeof(int) * maxsize);
    s->count = 0;
    return s;
}

void FreeStack(Stack* s)
{
    free(s->vals);
    free(s);
    return;
}

void Push(Stack *s, int val)
{
    s->vals[s->count] = val;
    s->count++;
    return;
}

void PrintStack(Stack *s)
{
    int i;
    for(i = 0; i< s->count; i++)
        printf("%d ", s->vals[i]);
    printf("\n");
    return;
}

int CountNodes(struct TreeNode* root)
{
    int nleft = 0, nright = 0;
    
    if(root == NULL)
        return 0;
    
    if(root->left != NULL)
        nleft = CountNodes(root->left);
    
    if(root->right != NULL)
        nright = CountNodes(root->right);
    
    return nleft + 1 + nright;
}

void StackInorderTraverse(struct TreeNode *root, Stack* st)
{
    if(root == NULL)
        return;

    if(root->left != NULL)
    {
        StackInorderTraverse(root->left, st);
    }

    Push(st, root->val);

    if(root->right != NULL)
    {
        StackInorderTraverse(root->right, st);
    }

    return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int i;
    int* trvoutput;
    Stack *trvstack;

    //Init a stack.
    trvstack = InitStack(MAX_STACK_SIZE);

    //Do inorder traverse using stack.
    //StackInorderTraverse(root, trvstack);
    StackPreorderTraverse(root, trvstack);

    trvoutput = malloc(sizeof(int) * trvstack->count);

    //Copy stack into output.
    for(i = 0; i < trvstack->count; i++)
    {
        trvoutput[i] = trvstack->vals[i];
    }
    *returnSize = trvstack->count;

    FreeStack(trvstack);

    return trvoutput;
}

int main()
{
    int i;
    int outsize, *outval;
    struct TreeNode *n10, *n5, *n15, *n6, *n20, *n31;


    n10 = InitNode(10);
    n5 = InitNode(5);
    n15 = InitNode(15);
    n6 = InitNode(6);
    n20 = InitNode(20);
    n31 = InitNode(31);
    n10->left = n5;
    n10->right = n15;
    n15->left = n6;
    n15->right = n20;
    n20->right = n31;

    outval = inorderTraversal(n10, &outsize);

    for(i = 0; i < outsize; i++)
    {
        printf("%d ", outval[i]);
    }
    printf("\n");

    return 0;
}
