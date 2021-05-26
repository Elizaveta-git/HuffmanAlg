#include "HuffmanAlg.h"
using namespace std;

Text::Text(string line)
{
	str = line;
	strLength = 0;
}

size_t Text::count_length()//counting the number of characters
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		strLength++;
	}
	return strLength;
}

void Text::count_repetitions()
{
	for (int i = 0; i < strLength; i++)
	{
		char c = str[i];
		if (lst.found(c) == false)
		{
			lst.push_back(c, 1);
		}
		else
		{
			lst.CountVal(c);
		}
	}
}

void Text::print_informarion()
{
	cout << "Text size: " << count_length() << endl;
	cout << endl << "Frequency table:" << endl;
	count_repetitions();
	lst.print_to_console();
}

List<char, int>* Text::get_list()
{
	List<char, int>* curr = new List<char, int>;
	for (int i = 0; i < lst.get_size(); i++)
	{
		curr->push_back(lst.at_type1(i), lst.at_type2(i));
	}
	return curr;
}

Text::~Text()
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i]=0;
	}
}


Alg::Alg(List<char, int>* lst)
{
	list = *lst;
}

Alg::~Alg()
{
	list.clear();
}

void Alg::build_tree()
{
	list.BogoSort();//sorting the elements
	CreateListNode();//fill in lists of pointers
	node* NodeTail = listNodeFirst.ReturnTail();
	node* NodePenult = NULL;
	int Tail = NodeTail->freq;
	NodeTail->data = "0";
	listNodeFirst.pop_back();
	while(listNodeFirst.get_size()!=0)
	{
		NodePenult= listNodeFirst.ReturnTail();
		int Penult = NodePenult->freq;
		NodePenult->data = "1";
		listNodeFirst.pop_back();
		node* root = new node(Tail+Penult, '~',"", NodeTail, NodePenult);//create new element
		NodeTail->parent = root;
		NodePenult->parent = root;
		listNodeFirst.push_back(root);
		listNodeFirst.BogoSortNode();//sorting the elements
		head = root;
		NodeTail = listNodeFirst.ReturnTail();
		Tail = NodeTail->freq;
		if (listNodeFirst.get_size() > 1)//for the last items
		{
			NodeTail->data = "0";
		}
		else
		{
			NodeTail->data = "1";
		}
		listNodeFirst.pop_back();
	}

}

void Alg::build_codes()
{
	node* Tail = NULL;
	node* TailTemp = NULL;
	cout << endl << "Code table:" << endl;
	while (listNodeSecond.get_size() != 0)
	{
		Tail = listNodeSecond.ReturnTail();
		TailTemp= listNodeSecond.ReturnTail();
		string str, strTemp;
		int count;
		while (TailTemp->parent != NULL)//while element has parent
		{
			strTemp += TailTemp->data;
			TailTemp = TailTemp->parent;
		}
		count = strSize(strTemp)-1;
		for (int i = 0; i < strSize(strTemp); i++)//write codes in line
		{
			char data = strTemp[count];
			str += data;
			count--;
		}
		Tail->code = str;
		cout << Tail->symb << "(" << Tail->code << ")" << endl;
		listNodeSymb.push_back(Tail);
		listNodeSecond.pop_back();
	}
}

void Alg::CreateListNode()
{
	for (int i = 0; i < list.get_size(); i++)
	{
		node* curr = new node(list.at_type2(i), list.at_type1(i));
		listNodeFirst.push_back(curr);
		listNodeSecond.push_back(curr);
	}
}
                                                                   
void Alg::Huffman(string str)
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
	build_tree();                                                                                                                                                                                              
	build_codes();
	Coding(str);                                                                        
	Decoding();
	CountMemory(str);
}

void Alg::Coding(string str)
{
	for (int i = 0; i < strSize(str); i++)
	{
		for (int j = 0; j < listNodeSymb.get_size(); j++)
		{
			if (str[i] == listNodeSymb.atSymbNode(j))
			{
				strCoding = strCoding + listNodeSymb.atCodeNode(j);
			}
		}
	}
}

void Alg::Decoding()
{
	node* curr = head;
	for (int i = 0; i < strSize(strCoding); i++)
	{
		if (strCoding[i] == '0' && curr->symb == '~')
		{
			curr = curr->left;
		}
		else if (strCoding[i] == '1' && curr->symb == '~')
		{
			curr = curr->right;
		}
		else
		{
			strDecoding += curr->symb;
			curr = head;
			i--;
		}
	}
	strDecoding += curr->symb;
}

string Alg::ReturnCoding()
{
	return strCoding;
}

string Alg::ReturnDecoding()
{
	return strDecoding;
}

void Alg::CountMemory(string str)
{
	int MemoryBefore = strSize(str) * 8;
	int MemoryAfter = strSize(strCoding);
	cout << endl << "Memory size before encoding: " << MemoryBefore << endl;
	cout << "Memory size after encoding: " << MemoryAfter << endl;
	float coefficient=(MemoryBefore*1000.0)/(MemoryAfter*1000.0);
	cout << "Compression ratio: " << coefficient << endl;
}

size_t Alg::strSize(string str)
{
	size_t strSize = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		strSize++;
	}
	return strSize;
}
