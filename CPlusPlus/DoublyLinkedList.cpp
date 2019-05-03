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
			cout << endl << "Insert At Front Loop executed" << endl;
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
			cout << endl << "Insert At End Loop executed" << endl;
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
		
		int getcount()
		{
			//cout << endl << "Get Count Loop executed" << endl;
			node *temp = new node;
			temp = head;
			int count2 = 0;
			
			while(temp != NULL)
			{
				//cout << "Inside While Loop";
				count2++;
				temp = temp -> next;
			}
			//cout <<endl << "Check" << endl;
			return count2;
		}
		
		
		void insertAt(int pos, int value)
		{
			cout << endl << "Insert At  Specific Loop executed" << endl;
			node *temp = new node;
			node *temp2 = new node;
			node *temp3 = new node;
			temp -> nodeValue = value;
			
			int count1 = getcount();
			cout << "\n" << "Total Nodes in List " << count1 << endl << endl;
			
			//Inserting At Front
			if(pos == 1)
			{
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
			
			//Inserting At End
			else if (pos == count1 + 1)
			{
				temp2 = head;
				while(temp2 -> next != NULL)
				{
					temp2 = temp2 -> next;
				}
				
				temp2 -> next = temp;
				temp -> next = NULL;
				temp -> prev = temp2;
				tail = temp2;
			}
			
			//Position between front and Last
			else if (pos > 0 && pos <= count1+1)
			{
				temp2 = head;
				for(int i = 1; i < pos-1 ; i++)
				{
					temp2 = temp2 -> next;
				}
				
				//cout << endl << temp -> nodeValue << endl;
				
				temp3 = temp2 -> next;
				//cout << endl << temp3 -> nodeValue << endl;
				temp2 -> next = temp;
				temp -> prev = temp2;
				temp -> next = temp3;
				temp3 -> prev = temp;
			}
			
			else
			{
				cout << endl << "Invalid Position to insert in the Linked list" << endl;
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
	list.insertAt(2, 111);
	list.displayList();
	
	return 0;
}
