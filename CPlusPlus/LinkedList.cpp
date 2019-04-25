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
			node *temp = head;
			node *newnod = new node;
			newnod-> nodeValue = value;
			newnod-> next = NULL;
			temp = head;
			
			int count = 0;
			while(temp -> next != NULL)
			{
				count++;
				temp = temp -> next;
			}
			count = count + 1;
			cout << "Linked List Count : " << count << endl;
			
			if(head == NULL)
			{
				cout << "Linked List is empty" << endl;
			}
			else if (pos <1)
			{
				cout << endl << "Invalid position" << endl;
			}
			else if((count+2) >= pos)
			{
				node *prev = new node;
				node *curnt = new node;
				
				curnt = head;
				
				for(int i = 0; i < pos-1 ; i++)
				{
					prev = curnt;
					curnt = curnt -> next;
				}
				cout << endl <<"Value at " << prev << "is  - - - " << prev -> nodeValue << endl;
				cout << endl <<"Value at " << curnt << "is  - - - " << curnt -> nodeValue << endl;
				
				newnod->next = curnt;
				prev->next = newnod;
				
			}
			
			else
			{
				cout << "Linked list have only " << count << " Position. So, impossible to insert value "<< value << " at position " << pos;
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
	obj.insertNode(20);
	obj.displayList();
	
	cout << "\n\n" <<  "Insert at End" << endl;
	obj.insertAtEnd(20);
	obj.displayList();
	
	cout << "\n\n" <<  "Insert at Position" << endl;
	obj.insertAt(5, 212);
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
	cout << endl;
	
	
	return 0;
   
}
