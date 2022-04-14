#include <iostream>
#include "ShannonFanoEncoder.h"


void TestShannon(String toEncode, bool verbose = false)
{
	//define default eng alphabet
	String alphabetEng = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz,./()!? :;'\"1234567890-=+_<>}{[]\\|~`@#$%^&*’";

	//create all needed info for encoding/decoding
	ShannonFanoEncoder encoder(alphabetEng, verbose);

	cout << "-----------------Encoding with default eng alphabet-----------------" << endl;

	//just do the work
	cout << "String to encode:\n" << toEncode << endl;
	String encodedString = encoder.Encode(toEncode);
	cout << "Encoded string:\n" << encodedString << endl;
	String decodedString = encoder.Decode(encodedString);
	cout << "Decoded string:\n" << decodedString << endl;

	cout << "\n\n\n";
	//we can create info manually, but do we really need it?
	auto customOperationInfo = ShannonFanoEncoder::CreateOperationInfo(toEncode, verbose);

	cout << "-----------------Encoding with alphabet from input-----------------" << endl;

	//just do the work with static calls
	cout << "String to encode:\n" << toEncode << endl;
	String encodedString2 = ShannonFanoEncoder::Encode(toEncode, customOperationInfo, verbose);
	cout << "Encoded string:\n" << encodedString2 << endl;
	String decodedString2 = ShannonFanoEncoder::Decode(encodedString2, customOperationInfo, verbose);
	cout << "Decoded string:\n" << decodedString2 << endl;



	delete customOperationInfo;
}

int main()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out, 0x0 | 0x70);
	SetConsoleOutputCP(1251);
	system("CLS");
	//It's okay if small (string with big alphabet)'s size is bigger than reference size!
	//The thing is... I use first 8 bytes of encoded string to store initial character count 
	//(because program output without validating character count will be close to undefined (because we have only 2 bit values (that is pitiful)))

	// ? char stands for non-printable char values

	//And like always, no forgotten heap objects

	//variant 2

	TestShannon("All the world’s a stage, and all the men and women merely players. @William Shakespeare");
	TestShannon("Eighty percent of success is showing up. @Woody Allen");
	TestShannon("Genius is one percent inspiration and ninety-nine percent perspiration. @Thomas Edison");


	cout << "\nNow enter your string:\n";

	char inputBuffer[512];
	cin.get(inputBuffer, 512);

	TestShannon(inputBuffer, true);
}
