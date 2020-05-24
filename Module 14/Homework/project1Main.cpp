#include <iostream>

using namespace std;

class LinkedList
{
	protected:
		struct ListNode
		{
			double value;
			ListNode *next;
			ListNode(double value = NULL, ListNode *next = NULL)
			{
				this->value = value;
				this->next = next;
			}
		};
		ListNode *head;
	public:
		void add(double number);
		bool isMember(double x);
		LinkedList(const LinkedList &);
		void print();
		void remove(double x);
		void insert(double x, int pos);
		
		LinkedList()
		{
			head = NULL;
		}
};
//Copy constructor.
LinkedList::LinkedList(const LinkedList& otherList)
{
	head = NULL;
	
	ListNode *newNode; // A new node
	ListNode *nodePtr; // To traverse in other list
	ListNode *tempPtr; // To traverse in developing list
	
	//check if the other list is empty.
	if(!otherList.head)
	{
		return;
	}
	
	nodePtr = otherList.head;
	head = new ListNode();
	head->value = nodePtr->value;
	head->next = NULL;
	nodePtr = nodePtr->next;
	tempPtr = head;
	
	while(nodePtr != NULL)
	{
		newNode = new ListNode;
		newNode->value = nodePtr->value;
		newNode->next = NULL;
		
		tempPtr->next = newNode;
		tempPtr = newNode;
		nodePtr = nodePtr->next;
	}
}
