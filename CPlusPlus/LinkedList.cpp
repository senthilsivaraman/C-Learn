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
				temp ->next = NULL;
				tail = temp;
			}
		}
		
		
		void searchValue(int value)
		{
			node *temp;
			temp = head;
			
			while(temp != NULL)
			{
				if(temp -> nodeValue == value)
				{
					cout << "The value " << temp -> nodeValue << " found at linkedlist " << temp << endl;
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
	cout << endl << endl <<  "Insert at End" << endl;
	obj.insertAtEnd(20);
	obj.displayList();
	cout << "\n\n" << "Searching a Value" << endl;
	obj.searchValue(20);
	cout<<endl;
	return 0;
    //Insert(Beginning, End, before or after a key), Delete, Display
}
