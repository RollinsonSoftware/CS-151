#include <iostream>

using namespace std;

double lastValue(ListNode *ptr);
ListNode * removeFirst(ListNode *ptr);
ListNode * listConcat(ListNode *list1, ListNode *list2);

int main(int argc, char** argv) 
{
	system("pause");
	return 0;
}
/*
Question number 11:
Write a function
  double lastValue(ListNode *ptr)  
that returns the value stored in the last node of a nonempty list passed 
to it as parameter. The function should print an error message and terminate 
the program if the list passed to it is empty.
*/
double lastValue(ListNode *ptr)
{
	if(!ptr)
	{
		cout << "Error";
		exit(1);
	}
	
	if(ptr->next == NULL)
	{
		return ptr->value;
	}
	else
	{
		return lastValue(ptr->next);
	}
}
/*
Question number 12:
Write a function
  ListNode * removeFirst(ListNode *ptr)  
that is passed a linked list as parameter and returns the tail of the list: 
That is, it removes the first node and returns what is left. The function 
should deallocate the storage of the removed node. The function returns null 
in ptr if the list passed to it is empty.
*/
ListNode * removeFirst(ListNode *ptr)
{
	if(!head)
	{
		return;
	}
	if(!head->value == number)
	{
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
	else
	{
		nodePtr = head;
		while(nodePtr! = NULL && nodePtr->value != number)
		{
			previousNodePtr = nodePtr;
			nodePtr = nodePtr->next;
		}
		if(nodePtr)
		{
			previousNodePtr->next = nodePtr->next;
			delete nodePtr;
		}
	}
}
/*
Question number 13:
Write a function

 ListNode * listConcat(ListNode *list1, ListNode *list2) 

that concatenates the items in list2 to the end of list1 and returns the resulting list.
For each of the following program fragments, predict what the output will be.
*/
ListNode * listConcat(ListNode *list1, ListNode *list2)
{
	if(list1 == NULL)
	{
		return list2;
	}
	
	ListNode *ptr = list1;
	
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = list2;
	return list1;
}
