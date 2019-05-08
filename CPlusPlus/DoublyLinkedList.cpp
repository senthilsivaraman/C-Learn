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
			//cout << endl << "Insert At Front Loop executed" << endl;
			node *temp = new node;
			node *temp2 = new node;
			temp -> nodeValue = value;
			
			if(isListEmpty())
			{
				temp -> prev = NULL;
				temp -> next = NULL;
				head = temp;
				tail = temp;
				//cout << "Successfully Inserted at the front of the list" << endl;
			}
			
			else
			{
				temp2 -> prev = temp;
				temp2 -> next = NULL;
				temp -> prev = NULL;
				temp -> next = head;
				head = temp;
				tail = temp2;
			}
		}
		
		
		void insertAtEnd(int value)
		{
			//cout << endl << "Insert At End Loop executed" << endl;
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
				//cout << "Successfully Inserted at the front of the list" << endl;
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
				tail = temp;
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
			//cout << endl << "Insert At  Specific Loop executed" << endl;
			node *temp = new node;
			node *temp2 = new node;
			node *temp3 = new node;
			temp -> nodeValue = value;
			
			int count1 = getcount();
			//cout << "\n" << "Total Nodes in List " << count1 << endl << endl;
			
			//Inserting At Front
			if(pos == 1)
			{
				if(isListEmpty())
				{
					temp -> prev = NULL;
					temp -> next = NULL;
					head = temp;
					tail = temp;
					//cout << "Successfully Inserted at the front of the list" << endl;
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
		
		void deleteFirst()
		{
			if(head != NULL)
			{
				node *temp = new node;
				temp = head;
				if(head -> next != NULL)
				{
					head -> next -> prev = NULL;
					head = head -> next;
					delete temp;
				}
				else
				{
					//cout << "else loop exec in delete first" << endl;
					delete temp;
					head = NULL;
					tail = NULL;
				}
				
			}
			
			else
			{
				cout << endl << "List is Empty" << endl;
			}
			
		}
		
		
		void deleteLast()
		{
			node *temp = new node;
			node *temp2 = new node;
			temp = head;
			
			
			if(head != NULL)
			{
				if(head -> next == NULL)
				{
					//cout << "If loop exec in delete Last" << endl;
					delete temp;
					head = NULL;
					tail = NULL;
				}
				else
				{
					//cout << "Else loop exec in delete Last" << endl;
					while(temp -> next != NULL)
					{
						//cout << "While loop exec";
						temp = temp -> next;
					}
					temp2 = temp -> prev;
					temp2 -> next = NULL;
					delete temp;
				}
			}
			
			else
			{
				cout << endl <<"List is already empty" << endl;
			}
		}
		
		
		void deleteNodeAt(int pos)
		{
			int count;
			count = getcount();
			
			node *temp = new node;
			node *temp2 = new node;
			node *temp3 = new node;
			temp = head;
			
			if(head == NULL)
			{
				cout << endl << "List is already empty" << endl;
			}
			
			else if(pos <= 0 || pos > count)
			{
				cout << endl << "Invalid position to delete in the list" << endl;
			}
			
			else
			{
				if(pos == 1 && count == 1)
				{
					head = NULL;
					tail = NULL;
					delete temp;
				}
				
				else if (pos == 1 && count > 1)
				{
					head = head -> next;
					delete temp;
					temp2 = head;
					temp2 -> prev = NULL;
				}
				
				else if (pos == count)
				{
					temp = head;
					for(int i = 1; i <= pos-1; i++)
					{
						temp = temp -> next;
					}
					temp2 = temp -> prev;
					temp2 -> next = NULL;
					delete temp;
				}
				
				else
				{
					temp = head;
					for(int i = 1; i <= pos-1; i++)
					{
						temp = temp -> next;
					}
					temp2 = temp -> prev;
					temp3 = temp -> next;
					temp2 -> next = temp3;
					temp3 -> prev = temp2;
					delete temp;
					
				}
			}
		}
		
		
		
		void deleteFullList()
		{
			node *temp = new node;
			
			while(head != NULL)
			{
				temp = head;
				head = head -> next;
				delete temp;
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
				cout<< "\n";
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
	
	// Insert at Front of the list
	list.insertAtFront(10);
	list.insertAtFront(20);
	list.insertAtFront(30);
	list.displayList();
		
	// Insert at the End of the list
	list.insertAtEnd(111);
	list.insertAtEnd(1151);
	list.displayList();
	
	// Insert at the Particular position
	list.insertAt(1,333);
	list.insertAt(4,666);
	list.displayList();
	
	// Deleting the First Node
	list.deleteFirst();
	list.displayList();
	
	//Deleting the Last node
	list.deleteLast();
	list.displayList();
	
	
	//Deleting the particular node
	list.deleteNodeAt(1);
	list.displayList();
	
	list.deleteNodeAt(2);
	list.displayList();
	
	return 0;
}
