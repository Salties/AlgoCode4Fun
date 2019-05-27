#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>


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

int max(int x, int y)
{
	return (x > y ? x : y);
}

int min(int x, int y)
{
	return (x < y ? x : y);
}

int GetMaxBst(struct TreeNode *root)
{
	int maxval, lmax, rmax;

	if (root->left == NULL && root->right == NULL)
	{
		return root->val;
	}

    maxval = root->val;
	if (root->left != NULL)
	{
		lmax = GetMaxBst(root->left);
		maxval = max(lmax, maxval);
	}

	if (root->right != NULL)
	{
		rmax = GetMaxBst(root->right);
		maxval = max(rmax, maxval);
	}

	return maxval;
}

int GetMinBst(struct TreeNode *root)
{
	int minval, lmin, rmin;

	if (root->left == NULL && root->right == NULL)
	{
		return root->val;
	}

    minval = root->val;
	if (root->left != NULL)
	{
		lmin = GetMinBst(root->left);
		minval = min(lmin, minval);
	} 

	if (root->right != NULL)
	{
		rmin = GetMinBst(root->right);
		minval = min(rmin, minval);
	} 

	return minval;
}

bool isValidBST(struct TreeNode * root)
{
    int lmax, rmin;
	//Recursion exit.
	if (root == NULL)
	{
		return true;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}

	if (root->left != NULL)
	{
        lmax = GetMaxBst(root->left);
		if (root->val <= lmax)
		{
			return false;
		}
		if (!isValidBST(root->left))
		{
			return false;
		}
	}

	if (root->right != NULL)
	{
        rmin = GetMinBst(root->right);
		if (root->val >= rmin)
		{
			return false;
		}
		if (!isValidBST(root->right))
		{
			return false;
		}
	}

	return true;
}

int main()
{
    int out;

    struct TreeNode *n10, *n5, *n15, *n6, *n20;

    n10 = InitNode(10);
    n5 = InitNode(5);
    n15 = InitNode(15);
    n6 = InitNode(6);
    n20 = InitNode(20);
    n10->left = n5;
    n10->right = n15;
    n15->left = n6;
    n15->right = n20;

    out = isValidBST(n10);

    printf("%d\n", out);

    return 0;
}
