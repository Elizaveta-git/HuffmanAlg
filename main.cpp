#include "HuffmanAlg.h"
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	Text txt(str);
	txt.print_informarion();
	Alg Huff(txt.get_list());
	Huff.Huffman(str);
	cout << endl << "Encoded result: " << endl;
	cout << Huff.ReturnCoding() << endl;
	cout << endl << "Decoding result: " << endl;
	cout << Huff.ReturnDecoding() << endl;
	return 0;
}
