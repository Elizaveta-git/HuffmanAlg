#include "pch.h"
#include "CppUnitTest.h"
#include "../HuffmanAlg.h"
#include "../HuffmanAlg.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HuffmanAlgTests
{
	TEST_CLASS(HuffmanAlgTests)
	{
	public:
		
		TEST_METHOD(coding_smal)
		{
			string str = "Be happy!";
			Text txt(str);
			txt.count_length();
			txt.count_repetitions();
			Alg Huff(txt.get_list());
			Huff.build_tree();
			Huff.build_codes();
			Huff.Coding(str);
			string strCoding = Huff.ReturnCoding();
			string ResCoding = "110111111100010001010011010";
			Assert::AreEqual(strCoding, ResCoding);
		}
		TEST_METHOD(coding_mid)
		{
			string str = "When you start thinking a lot about your past, it becomes your present and you can’t see your future without it.";
			Text txt(str);
			txt.count_length();
			txt.count_repetitions();
			Alg Huff(txt.get_list());
			Huff.build_tree();
			Huff.build_codes();
			Huff.Coding(str);
			string strCoding = Huff.ReturnCoding();
			string ResCoding = "1111010011101011011000111011101110000111001000101010010000100011101111101101111011111111011011110110000101001010101110110000010111110011011100100001110111011100010000011111010111100100101010000111111000011110010110111101101101011110111110000111011101110001000001111101001011111001011011010000010101101010110001110111011100000111100101011010100011000011100101110110011101110111000100001010000110010011000100101100101001111111100011101101110010000111111001010010";
			Assert::AreEqual(strCoding, ResCoding);
		}
		TEST_METHOD(decoding)
		{
			string str = "Remember who you are.";
			Text txt(str);
			txt.count_length();
			txt.count_repetitions();
			Alg Huff(txt.get_list());
			Huff.build_tree();
			Huff.build_codes();
			Huff.Coding(str);
			Huff.Decoding();
			string strDecoding = Huff.ReturnDecoding();
			Assert::AreEqual(str, strDecoding);
		}
	};
}
