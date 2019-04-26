#include<iostream>

using namespace std;

struct node
{
    int nodeValue;
    node *next;
};

class linkedList
{
    private:
        node *head;
        node *tail;
    
    public:
        linkedList()
        {
            head = NULL;
            tail = NULL;
        }
		
		int getCount(struct node *head)
		{
			if(head == NULL)
				return 0;
			return 1 + getCount(head -> next);
		}
		
		void insertNode(int newValue)
		{
			node *temp = new node;
			temp -> nodeValue = newValue;
			
			if(head == NULL)
			{
				temp -> next = NULL;
				head = temp;
				tail = temp;
			}
			else
			{
				temp -> next = head;
				head = temp;
			}
		}
		
		void insertAtEnd(int value)
		{
			node *temp = new node;
			temp -> nodeValue = value;
			if(head == NULL)
			{
				temp -> next = NULL;
				head = temp;
				tail = temp;
			}
			else
			{
				node *last = head;
				while(last->next != NULL)
				{
					last = last -> next; 
				}
				last -> next = temp;
				temp -> next = NULL;
				tail = temp;
			}
		}
		
		
		void insertAt(int pos, int value)
		{
			
			if(head != NULL)
			{
				node *temp = head;
				node *newnod = new node;
				newnod -> nodeValue = value;
				newnod -> next = NULL;
				temp = head;
			
				int count = 0;
			
				while(temp -> next != NULL)
				{
					count++;
					temp = temp -> next;
				}
				count = count + 1;
				cout << "Linked List Count : " << count << endl;
				
				if (pos <1)
				{
					cout << endl << "Invalid position" << endl;
				}
				
				else if((count+1) >= pos)
				{
					node *prev = new node;
					node *curnt = new node;
					
					curnt = head;
					
					for(int i = 0; i < pos-1 ; i++)
					{
						prev = curnt;
						curnt = curnt -> next;
					}
					//cout << endl <<"Value at " << prev << "is  - - - " << prev -> nodeValue << endl;
					//cout << endl <<"Value at " << curnt << "is  - - - " << curnt -> nodeValue << endl;
					
					newnod -> next = curnt;
					prev -> next = newnod;
					
				}
			
				else
				{
					cout << "Linked list have only " << count << " Position. So, impossible to insert value "<< value << " at position " << pos;
				}
			}
			
			else
			{
				cout << endl << "List is empty - so use insert function instead insertAt" << endl; 
			}

		}
		
		
		bool searchValue(int value)
		{
			node *temp;
			temp = head;
			
			while(temp != NULL)
			{
				if(temp -> nodeValue == value)
				{
					return true;
				}
				temp = temp -> next;
			}
		}
		
		
		
		void deleteFront()
		{
			if(head == NULL)
			{
				cout << "Linked list is already empty" << endl;
			}
			else
			{
				node *temp =new node;
				temp = head;
				head = head -> next;
				delete temp;
			}
		}
		
		
		void deleteEnd()
		{
			if(head == NULL)
			{
				cout << "Linked list is already empty" << endl;
			}
			else if(head -> next == NULL)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				node *temp = new node;
				temp = head;
				while(temp -> next -> next != NULL)
				{
					temp = temp -> next;
				}
				delete (temp -> next);
				temp -> next = NULL;
				
			}
		}
		
		
		void deletePos(int position)
		{
			node *temp = new node;
			node *temp2 = new node;
			node *curnt;
			temp = head;
			temp2 = head;
			
			int b = getCount(head);
			//cout << "Linked List Count using recursion : " << b << endl;
			
			if(position <= b && position > 0)
			{
				if(position == 1)
				{
					head = head -> next;
					delete temp;
				}
				
				else if (position == 2)
				{
					temp = head;
					temp2 = head -> next;
					temp -> next = temp2 -> next;
					delete temp2;
				}
				else
				{
					for(int i = 1; i < position - 1 ; i++)
					{
						temp = temp -> next;
						temp2 = temp -> next;
						
					}
					temp -> next = temp2 -> next;
					delete temp2;
					//cout << endl << endl <<  "Delete At position " <<  position << " : " << temp -> nodeValue << endl;
					//cout << endl << endl <<  "Next Pointer " <<  position << " : " << temp2 -> nodeValue << endl;
					
					//curnt = temp2 -> next;
				}
			}
			
			else
			{
				cout << endl << "Invalid position to delete" << endl;
			}
			
			
		}
		
		
		void displayList()
		{
			node *temp;
			temp = head;
			while (temp != NULL)
			{
				cout << temp -> nodeValue << "\t";
				temp = temp -> next;
			}
		}
};



int main()
{
    linkedList obj;
	cout << "Insert at front" << endl;
    obj.insertNode(5);
	obj.insertNode(10);
	obj.insertNode(15);
	obj.insertNode(25);
	obj.insertNode(35);
	obj.insertNode(40);
	obj.displayList();
	
	cout << "\n\n" <<  "Insert at End" << endl;
	obj.insertAtEnd(20);
	obj.displayList();
	
	cout << "\n\n" <<  "Insert at Position" << endl;
	obj.insertAt(2, 212);
	cout << endl;
	obj.displayList();
	
	cout << "\n\n" << "Searching a Value" << endl;
	int n = 20;
	bool a = obj.searchValue(n);
	if(a == true)
	{
		cout << "Value " << n << " is found in the Linked List " << endl;
	}
	else
	{
		cout << "Value " << n << " is not found at Linked List" << endl;
	}
	
	cout << endl << endl << "Delete at Front" << endl;
	obj.deleteFront();
	obj.displayList();
	cout << endl << endl << "Delete at End" << endl;
	obj.deleteEnd();
	obj.displayList();
	cout << endl << endl << "Delete at Position" << endl;
	obj.deletePos(4);
	obj.displayList();
	
	
	return 0;
   
}
