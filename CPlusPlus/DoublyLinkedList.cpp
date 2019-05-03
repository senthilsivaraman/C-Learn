#include <iostream>

using namespace std;

struct node
{
	int nodeValue;
	node *next;
	node *prev;
};

class doubleLinkedList
{
	private:
		node *head;
		node *tail;
	
	public:
		
		doubleLinkedList()
		{
			head = NULL;
			tail = NULL;
		}
		
		bool isListEmpty()
		{
			if(head == NULL)
				return true;
			else
				return false;
		}
		
		
		void insertAtFront(int value)
		{
			//cout << "Loop Executed";
			node *temp = new node;
			node *temp2 = new node;
			temp -> nodeValue = value;
			
			if(isListEmpty())
			{
				temp -> prev = NULL;
				temp -> next = NULL;
				head = temp;
				tail = temp;
				cout << "Successfully Inserted at the front of the list" << endl;
			}
			
			else
			{
				temp2 -> prev = temp;
				temp -> prev = NULL;
				temp -> next = head;
				head = temp;
			}
		}
		
		
		void insertAtEnd(int value)
		{
			//cout << "Insert at End Loop Executed";
			node *temp = new node;
			node *temp2 = new node;
			temp2 = head;
			//temp = NULL;
			temp -> nodeValue = value;
			
			if(isListEmpty())
			{
				temp -> prev = NULL;
				temp -> next = NULL;
				head = temp;
				tail = temp;
				cout << "Successfully Inserted at the front of the list" << endl;
			}	
			else
			{
				while(temp2 -> next != NULL)
				{
					temp2 = temp2 -> next;
				}
				
				temp2 -> next = temp;
				temp -> next = NULL;
				temp -> prev = temp2;
				tail = temp2;
				//cout << endl << "Value" << temp2 -> nodeValue << endl;
				
			}
		}
		
		
		void displayList()
		{
			node *temp = new node;
			temp = head;
			if(head == NULL)
			{
				cout << "List is Empty" << endl;
			}
			else
			{
				while(temp != NULL)
				{
					//cout << "Loop Executed";
					cout << temp -> nodeValue << "\t";
					temp = temp -> next;
				}
			}
			cout << endl;
		}
	
	
};

int main()
{
	doubleLinkedList list;
	
	cout << "Inserting at the Front of the List" << endl;
	list.insertAtFront(10);
	list.displayList();
	list.insertAtFront(100);
	list.insertAtFront(200);
	list.insertAtFront(300);
	list.insertAtEnd(500);
	list.displayList();
}
