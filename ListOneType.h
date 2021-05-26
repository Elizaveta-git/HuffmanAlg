#include <iostream>

using namespace std;

template <class type>
class ListOneType
{
private:
	class Node
	{
	public:
		Node* Next;//pointer to the next element in the list
		type data;//element value

		Node(type data = type(), Node* Next = NULL)//creating element
		{
			this->data = data;
			this->Next = Next;
		}
	};
	int Size;//list size
	Node* head;//pointer to the head of the list
public:
	ListOneType()
	{
		Size = 0;//list size
		head = NULL;//zeroing head element
	}
	~ListOneType()
	{
		clear();
	}
	ListOneType(ListOneType <type>& other)
	{
		this->head = NULL;
		this->Size = 0;
		for (int i = 0; i < other.Size; i++)
			this->push_back(other.at(i));
	}
	ListOneType <type>& operator=(ListOneType <type>& right)
	{
		if (this == &right)
			return *this;
		this->clear();
		for (int i = 0; i < right.Size; i++)
		{
			this->push_back(right.at(i));
		}
		return *this;
	}
	type at(size_t index)//getting an element by index
	{
		Node* current = this->head;//go to the beginning of the list
		for (int i = 0; i < index; i++)//find the element by index
		{
			current = current->Next;
		}
		return current->data;//return the value of the element
	}
	int atDataNode(size_t index)//getting an element by index
	{

			Node* current = this->head;//go to the beginning of the list
			for (int i = 0; i < index; i++)//find the element by index
			{
				current = current->Next;
			}
			return current->data->freq;//return the value of the element
	}
	char atSymbNode(size_t index)//getting an element by index
	{

		Node* current = this->head;//go to the beginning of the list
		for (int i = 0; i < index; i++)//find the element by index
		{
			current = current->Next;
		}
		return current->data->symb;//return the value of the element
	}
	string atCodeNode(size_t index)//getting an element by index
	{

		Node* current = this->head;//go to the beginning of the list
		for (int i = 0; i < index; i++)//find the element by index
		{
			current = current->Next;
		}
		return current->data->code;//return the value of the element
	}
	void push_front(type data)//insert element at the beginning of the list
	{
		head = new Node(data, head);
		Size++;//increasing list size
	}
	void push_back(type data)//insert element in the end of the list
	{
		if (isEmpty() != 0)//insert first element if list is empty
		{
			head = new Node(data);//element creation
		}
		else//insert element in the end of the list
		{
			Node* current = head;//creation a new element
			while (current->Next != NULL)//while the next element exists, move throuth the list to the end
			{
				current = current->Next;
			}
			current->Next = new Node(data);//creating the last element
		}
		Size++;//increasing list size
	}
	void pop_back()//remove an element in the end of the list
	{
			Node* previous = this->head;//set the previous element
			for (int i = 0; i < Size - 2; i++)//find the penultimate element
			{
				previous = previous->Next;
			}
			Node* Del = previous->Next;//remember the element in the end
			previous->Next = NULL;//set the end of the list
			delete Del;////remove element in the end
			Size--;//reduce list size
	}
	bool isEmpty()//checking the list for emptiness
	{
		if (head == NULL) return true;
		else return false;
	}
	void clear()//clear list
	{
		while (Size)
		{
			pop_front();
		}
	}
	void pop_front()//remove an element from the beginning of the list
	{
		if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else
		{
			Node* current = head;//remember the first element
			head = head->Next;//make the second element first
			delete current;//delete first element
			Size--;//reduce list size
		}
	}
	void print_to_console()//output the list to the console
	{
		Node* current = this->head;//go to the beginning of the list
		while (current != NULL)//while new element exist
		{
			cout << current->data << " ";//display the value of the element
			current = current->Next;//move on to the next element
		}
	}
	void print_to_consoleNode()//output the list to the console
	{
		Node* current = this->head;//go to the beginning of the list
		while (current != NULL)//while new element exist
		{
			cout << current->data->freq << " ";//display the value of the element
			current = current->Next;//move on to the next element
		}
	}
	void print_tree(Node* curr, int h)
	{
		if (curr)
		{
			print_tree(curr->left, h + 3);
			for (int i = 0; i < h; i++)
			{
				cout << "   ";
			}
			cout << curr->data->symb << "(" << curr->data->frec << "):" << endl;
			print_tree(curr->right, h + 3);
		}
	}
	size_t get_size()//getting list size
	{
		return Size;
	}
	void swap(size_t index1, size_t index2)//swap two elements in the list
	{
		Node* current1 = this->head;//go to the beginning of the list
		for (int i = 0; i < index1; i++)//find the first element by index
		{
			current1 = current1->Next;
		}
		Node* current2 = this->head;//go to the beginning of the list
		for (int i = 0; i < index2; i++)//find the second element by index
		{
			current2 = current2->Next;
		}
		Node* temp = new Node();//creating a new variable
		temp->data = current1->data;//remember the first element
		current1->data = current2->data;//write the value of the second element to the value of the first element
		current2->data = temp->data;//write the value of the first element to the value of the second element
	}
	void insert(type data, size_t index)//insert element into the list by index
	{
		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node* previous = this->head;//set the previous element
			for (int i = 0; i < index - 1; i++)//find the previous element
			{
				previous = previous->Next;
			}
			Node* current = new Node(data, previous->Next);//element creation by index
			previous->Next = current;
			Size++;//increasing list size
		}
	}
	void BogoSort()
	{
		Node* current = this->head;
		for (int j = 0; j < get_size(); j++)
		{
			bool flag = true;
			for (int i = 0; i < get_size() - (j + 1); i++)
			{
				if (at(i) < at(i + 1))//if the first elemens is greater than the second, then swap them
				{
					flag = false;
					swap(i, i + 1);
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
	void BogoSortNode()
	{
		Node* current = this->head;
		for (int j = 0; j < get_size(); j++)
		{
			bool flag = true;
			for (int i = 0; i < get_size() - (j + 1); i++)
			{
				if (atDataNode(i) < atDataNode(i + 1))//if the first elemens is greater than the second, then swap them
				{
					flag = false;
					swap(i, i + 1);
				}
			}
			if (flag)
			{
				break;
			}
		}
	}
	type ReturnHead()
	{
		return head->data;
	}
	type ReturnTail()
	{
		Node* current = this->head;//go to the beginning of the list
		for (int i = 0; i < Size-1; i++)//find the element by end
		{
			current = current->Next;
		}
		return current->data;//return the value of the element
	}
};