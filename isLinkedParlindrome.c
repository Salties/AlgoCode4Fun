#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *InitNode(int val)
{
	struct ListNode *head;
	head = malloc(sizeof(struct ListNode));
	head->val = val;
	head->next = NULL;

	return head;
}

void AddNode(struct ListNode *head, int val)
{
	struct ListNode *np;

	for (np = head; NULL != np->next; np = np->next);

	np->next = malloc(sizeof(struct ListNode));
	np->next->val = val;
	np->next->next = NULL;
	return;
}

void PrintList(struct ListNode *head)
{
	struct ListNode *np;
	for (np = head; NULL != np->next; np = np->next)
	{
		printf("%d->", np->val);
	}
	printf("%d->NULL\n", np->val);
	return;
}

bool isPalindrome(struct ListNode * head)
{
	struct ListNode *seqptr, *revptr, *prevptr, *nextptr;
	struct ListNode lapnode;
	int listlen, fhlen, shlen;
	int i;

	//Compute the length of list.
	for (listlen = 1, seqptr = head; seqptr->next != NULL;
	     listlen++, seqptr = seqptr->next);

	fhlen = listlen / 2;
	shlen = (listlen - 1) / 2;


	//Set seqptr at the (later) centre.
	seqptr = head;
	for (i = 0; i < fhlen; i++)
	{
		seqptr = seqptr->next;
	}
	//Set seqptr to lapnode to avoid overwritten by reverse.
	lapnode.val = seqptr->val;
	lapnode.next = seqptr->next;
	seqptr = &lapnode;

	//Reverse the first half of the list.
	revptr = head;
	prevptr = NULL;
	for (i = 0; i < shlen; i++)
	{
		nextptr = revptr->next;
		revptr->next = prevptr;
		prevptr = revptr;
		revptr = nextptr;
	}
	revptr->next = prevptr;

	//Compare both half.
	while (seqptr != NULL || revptr != NULL)	//Redundant condition.
	{
		if (seqptr->val != revptr->val)
			return false;
		seqptr = seqptr->next;
		revptr = revptr->next;
	}

	return true;
}

int main()
{
	struct ListNode *head;

	head = InitNode(0);
	AddNode(head, 1);
	AddNode(head, 2);
	AddNode(head, 1);
	AddNode(head, 0);
	//AddNode(head, 5);

	//PrintList(head);
	printf("%d\n", isPalindrome(head));


	return 0;
}
