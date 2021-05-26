#pragma once
#include "List.h"
#include "ListOneType.h"
#include <iostream>

class Text
{
private:
	string str;
	size_t strLength;
	List<char, int> lst;
public:
	
	Text(string);
	size_t count_length();
	void count_repetitions();
	void print_informarion();
	List<char, int>* get_list();
	~Text();
};
class Alg
{
private:
	class node
	{
	public:
		int freq;
		char symb;
		string data;
		string code="";
		node* left;
		node* right;
		node* parent;
		node* next;
		node(int freq, char symb='~', string code="", node* left=NULL, node* right=NULL, node* parent=NULL)
		{
			this->freq = freq;
			this->symb = symb;
			this->code += code;
			this->left = left;
			this->right = right;
			this->parent = parent;
		}
	};
	
public:
	
	Alg(List<char, int>*);
	~Alg();
	void build_tree();
	void build_codes();
	void CreateListNode();
	void Huffman(string);
	void Coding(string);
	void Decoding();
	string ReturnCoding();
	string ReturnDecoding();
	void CountMemory(string);
	size_t strSize(string);
	List<char, int> list;
	ListOneType<int> data;
	string strCoding, strDecoding;
	node* head;
	ListOneType<node*> listNodeFirst;
	ListOneType<node*> listNodeSecond;
	ListOneType<node*> listNodeSymb;
};