#pragma once
#include <iostream>

using namespace std;

template <class type1, class type2>
class List
{
private:

	class Node
	{
	public:
		Node* Next;//pointer to the next element in the list
		type1 data;//element value
		type2 val;

		Node(type1 data = type1(), type2 val = type2(),  Node* Next = NULL)//creating element
		{
			this->data = data;
			this->Next = Next;
			this->val = val;
		}
	};
	int Size;//list size
	Node* head;//pointer to the head of the list
public:
	List()
	{
		Size = 0;//list size
		head = NULL;//zeroing head element
	}
	~List()
	{
		clear();
	}
	type2 at_type2(size_t index)//getting an element by index
	{
	/*if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else if (isEmpty() != 1 && index >= Size)
		{
			throw out_of_range("Index is greater than list size");
		}
		else
		{*/
			Node* current = this->head;//go to the beginning of the list
			for (int i = 0; i < index; i++)//find the element by index
			{
				current = current->Next;
			}
			return current->val;//return the value of the element
		//}
	}
	type1 at_type1(size_t index)//getting an element by index
	{
		Node* current = this->head;//go to the beginning of the list
		for (int i = 0; i < index; i++)//find the element by index
		{
			current = current->Next;
		}
		return current->data;//return the value of the element
	}
	
	void push_back(type1 data, type2 val)//insert element in the end of the list
	{
		if (isEmpty() != 0)//insert first element if list is empty
		{
			head = new Node(data, val);//element creation
		}
		else//insert element in the end of the list
		{
			Node* current = head;//creation a new element
			while (current->Next != NULL)//while the next element exists, move throuth the list to the end
			{
				current = current->Next;
			}
			current->Next = new Node(data, val);//creating the last element
		}
		Size++;//increasing list size
	}
	void push_front(type1 data, type2 val)//insert element at the beginning of the list
	{
		head = new Node(data, val, head);
		Size++;//increasing list size
	}
	void insert(type1 data, type2 val, size_t index)//insert element into the list by index
	{
		if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else if (index >= Size)
		{
			throw out_of_range("Index is greater than list size");
		}
		else if (index == 0)
		{
			push_front(data, val);
		}
		else
		{
			Node* previous = this->head;//set the previous element
			for (int i = 0; i < index - 1; i++)//find the previous element
			{
				previous = previous->Next;
			}
			Node* current = new Node(data, val, previous->Next);//element creation by index
			previous->Next = current;
			Size++;//increasing list size
		}
	}
	void remove(size_t index)//remove element by index
	{
		if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else if (index >= Size)
		{
			throw out_of_range("Index is greater than list size");
		}
		else if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node* previous = this->head;//set the previous element
			for (int i = 0; i < index - 1; i++)//find the previous element
			{
				previous = previous->Next;
			}
			Node* Del = previous->Next;//remember the element by index
			previous->Next = Del->Next;//redirect the connection
			delete Del;//remove element by index
			Size--;//reduce list size
		}
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
	void pop_back()//remove an element in the end of the list
	{
		if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else
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
	}
	void set(type1 data, type2 val, size_t index)//set new element value by index
	{
		if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else if (index >= Size)
		{
			throw out_of_range("Index is greater than list size");
		}
		else
		{
			Node* current = this->head;//go to the beginning of the list
			for (int i = 0; i < index; i++)//find the element by index
			{
				current = current->Next;
			}
			current->data = data;//set new value
			current->val = val;
		}
	}
	void swap_type1(size_t index1, size_t index2)//swap two elements in the list
	{
		/*if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else if (index1 >= Size || index2 >= Size)
		{
			throw out_of_range("Index is greater than list size");
		}
		else if (index1 == index2)
		{
			throw out_of_range("Iindexes are equal");
		}
		else
		{*/
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
		//}

	}
	void swap_type2(size_t index1, size_t index2)//swap two elements in the list
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
		temp->val = current1->val;//remember the first element
		current1->val = current2->val;//write the value of the second element to the value of the first element
		current2->val = temp->val;//write the value of the first element to the value of the second element
	}
	size_t get_size()//getting list size
	{
		return Size;
	}
	void print_to_console()//output the list to the console
	{
		Node* current = this->head;//go to the beginning of the list
		while (current != NULL)//while new element exist
		{
			cout << current->data << "(" << current->val << ")  " << endl;//display the value of the element
			current = current->Next;//move on to the next element
		}
	}
	void CountVal(type1 data)
	{
		if (isEmpty() == 1)
		{
			throw out_of_range("The list is empty");
		}
		else
		{
			Node* current = this->head;//go to the beginning of the list
			bool find=false;
			for (int i = 0; i < get_size() && find == false; i++)//find the element by index
			{
				if (current->data == data)
				{
					current->val++;
					find =true;
				}
				else 
					current = current->Next;
			}
		}
	}
	bool found(type1 data)
	{
		if (isEmpty() == 1)
		{
			return false;
		}
		else
		{
			Node* current = this->head;//go to the beginning of the list
			for (int i = 0; i < get_size(); i++)//find the element by index
			{
				if (current->data == data)
				{
					return true;
				}
				else
					current = current->Next;
			}	
		}
		return false;
	}
	size_t get_index(type2 val)
	{
		int i;
		Node* current = this->head;
		for (int i = 0; i < get_size(); i++)//find the element by index
		{
			if (current->val == val)
			{
				return i;
			}
			else
				current = current->Next;
		}	
		
	}
	void BogoSort()
	{
		Node* current=this->head;
		for (int j = 0; j < get_size(); j++)
		{
			bool flag=true;
			for (int i = 0; i < get_size() - (j+1); i++)
			{
				if (at_type2(i) < at_type2(i+1))//if the first elemens is greater than the second, then swap them
				{
					flag = false;
					swap_type1(i,i+1);
					swap_type2(i,i+1);
				}
			}
			if (flag) 
			{
				break;
			}
		}
	}
};
