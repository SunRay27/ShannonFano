#pragma once

#include "List.h"
#include "String.h"
#include "RBTree.h"
#include "ShannonFanoTree.h"

//using namespace std;
class ShannonFanoEncoder
{
	class ShannonFanoInfo
	{
		SFTree<char>* decodeTree;
		Map<char, String>* encodeTree;

	public:
		~ShannonFanoInfo()
		{
			delete decodeTree;
			delete encodeTree;
		}
		ShannonFanoInfo(SFTree<char>* decodeTree, Map<char, String>* encodeTree)
		{
			this->decodeTree = decodeTree;
			this->encodeTree = encodeTree;
		}

		SFTNode<char>* GetDecodeTreeRoot()
		{
			return decodeTree->GetRoot();
		}

		String GetCharEncodedRepresentation(char charToEncode)
		{
			return encodeTree->Find(charToEncode);
		}
	};

private:
	//Map<char, String>* operationMap;
	ShannonFanoInfo* info;
	bool verbose = false;
	static void FillResultsListRecursive(int leftIndex, int rightIndex, List<float>* probability, List<String>* results)
	{
		if (leftIndex < rightIndex)
		{
			float leftHalfProbability = 0;

			for (size_t i = leftIndex; i < rightIndex; i++)
				leftHalfProbability += (*probability)[i];



			//split symbols in half
			int middleIndex = rightIndex;
			float rightHalfProbability = (*probability)[rightIndex];



			while (leftHalfProbability >= rightHalfProbability)
			{
				middleIndex--;

				float nextCharProbability = (*probability)[middleIndex];

				leftHalfProbability -= nextCharProbability;
				rightHalfProbability += nextCharProbability;
			}

			//now we have middleIndex


			//add 0 to first half, 1 to second half prefix
			for (size_t i = leftIndex; i <= rightIndex; i++)
			{
				if (i <= middleIndex)
				{
					(*results).Replace((*results)[i] + '0', i);
				}
				else
				{
					(*results).Replace((*results)[i] + '1', i);
				}
			}

			//do it recursively until 1 or 0 characters left
			FillResultsListRecursive(leftIndex, middleIndex, probability, results);
			FillResultsListRecursive(middleIndex + 1, rightIndex, probability, results);
		}



	}

public:
	~ShannonFanoEncoder()
	{
		delete info;
	}
	ShannonFanoEncoder(String alphabet, bool verbose = false)
	{
		info = CreateOperationInfo(alphabet, verbose);
	}

	String Encode(String input)
	{
		return Encode(input, info, verbose);
	}
	String Decode(String input)
	{
		return Decode(input, info, verbose);
	}


	//main logic is inside static functions
	static String Encode(String input, ShannonFanoInfo* info, bool verbose = false)
	{
		String output;


		List<bool> bits;
		for (size_t i = 0; i < input.Length(); i++)
		{
			//get string binary code representation for this character
			String bitCode = info->GetCharEncodedRepresentation(input[i]);

			//add those bits to list
			for (size_t j = 0; j < bitCode.Length(); j++)
				bits.Add(bitCode[j] == '1' ? true : false);
		}
		//compose string out of these bits
		output.WriteBits(bits);

		if (verbose)
		{
			float compressionRatio = 1 - (float)output.Length() / input.Length();
			cout << endl << "Encoding results: " << input.Length() * 8 << " bits -> " << output.Length() * 8 << " bits"
				<< "\nCompression ratio: " << compressionRatio * 100 << "%" << endl;

			return output;
		}
	}

	static String Decode(String input, ShannonFanoInfo* info, bool verbose = false)
	{
		String output;

		SFTNode<char>* searchNode = info->GetDecodeTreeRoot();
		auto iterator = input.CreateBitIterator();

		//iterate through string bits
		while (iterator->HasNext())
		{
			bool bit = iterator->Next();
			if (bit == true)
			{
				//move right in decodeTree
				if (searchNode->GetRight() != nullptr)
				{
					searchNode = searchNode->GetRight();
				}
				else
				{
					//that means that we already trying to move along sftree for next character
					//so add current character
					output += searchNode->GetKey();

					//and move to desired position in tree
					searchNode = info->GetDecodeTreeRoot()->GetRight();
				}
			}
			else // the same for left direction
			{
				// move left in decodeTree
				if (searchNode->GetLeft() != nullptr)
				{
					searchNode = searchNode->GetLeft();
				}
				else
				{

					output += searchNode->GetKey();
					searchNode = info->GetDecodeTreeRoot()->GetLeft();
				}
			}
		}
		delete iterator;

		if (verbose)
		{
			float compressionRatio = 1 - (float)output.Length() / input.Length();
			cout << endl << "Decoding results: " << input.Length() * 8 << " bits -> " << output.Length() * 8 << " bits"
				<< "\nCompression ratio: " << compressionRatio * 100 << "%" << endl;
		}

		return output;
	}

	static ShannonFanoInfo* CreateOperationInfo(String alphabetInput, bool verbose = false)
	{
		//create alphabet
		List <char> alphabet;
		List<String> results;
		List <float> probability;
		List <int> count;

		//fill alphabet, count and probability lists 
		for (int i = 0; i < alphabetInput.Length(); i++)
		{
			int index = alphabet.IndexOf(alphabetInput[i]);
			if (index == -1)
			{
				probability.Add(0);
				count.Add(1);
				alphabet.Add(alphabetInput[i]);
			}
			else
			{
				count.Replace(count[index] + 1, index);
			}
		}

		//now update probabilities
		for (int i = 0; i < alphabet.GetSize(); i++)
			probability.Replace((float)count[i] / alphabetInput.Length(), i);


		//now superBubbleSort everything by descending
		int n = probability.GetSize();
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - i - 1; j++)
				if (probability[j] < probability[j + 1])
				{
					alphabet.Swap(j, j + 1);
					count.Swap(j, j + 1);
					probability.Swap(j, j + 1);
				}

		if (verbose)
		{
			cout << "\nAlphabet:\n";
			alphabet.PrintToConsole();
			cout << "\nCounts:\n";
			count.PrintToConsole();
			cout << "\nProbabilities:\n";
			probability.PrintToConsole();
		}


		//prepare results list
		for (size_t i = 0; i < alphabet.GetSize(); i++)
			results.Add("");


		//fill results list
		int leftIndex = 0;
		int rightIndex = alphabet.GetSize() - 1;
		FillResultsListRecursive(leftIndex, rightIndex, &probability, &results);

		//thats all folks
		if (verbose)
		{
			cout << "\nAlphabet codes:\n";
			results.PrintToConsole();
		}
		//build encode tree
		Map<char, String>* encodeTree = new Map<char, String>();
		for (size_t i = 0; i < results.GetSize(); i++)
			encodeTree->Insert(alphabet[i], results[i]);
		if (verbose)
		{
			cout << "\n------------------Encode tree------------------\n";
			encodeTree->Print();
		}


		//build decode tree?
		SFTree<char>* decodeTree = new SFTree<char>(new SFTNode<char>(0));

		for (size_t i = 0; i < alphabet.GetSize(); i++)
		{
			String bitSeq = results[i];
			char targetChar = alphabet[i];
			SFTNode<char>* searchNode = decodeTree->GetRoot();
			//String accumulator;
			for (size_t j = 0; j < bitSeq.Length(); j++)
			{
				//accumulator += bitSeq[j];
				if (bitSeq[j] == '0')
				{
					//move left
					if (searchNode->GetLeft() != nullptr)
					{
						searchNode = searchNode->GetLeft();
					}
					else
					{
						if (j != bitSeq.Length() - 1)
							searchNode->SetLeft(new SFTNode<char>(0));
						//operationMap->Insert(accumulator, 0);
						else
							searchNode->SetLeft(new SFTNode< char>(targetChar));
						//operationMap->Insert(accumulator, targetChar);
						searchNode = searchNode->GetLeft();
					}
				}
				else
				{
					//move right
					if (searchNode->GetRight() != nullptr)
					{
						searchNode = searchNode->GetRight();
					}
					else
					{
						if (j != bitSeq.Length() - 1)
							searchNode->SetRight(new SFTNode<char>(0));
						//operationMap->Insert(accumulator, 0);
						else
							//operationMap->Insert(accumulator, targetChar);
							searchNode->SetRight(new SFTNode< char>(targetChar));
						searchNode = searchNode->GetRight();
					}
				}
				//decodeTree->Print();
			}


		}

		if (verbose)
		{
			cout << "\n------------------Decode tree------------------\n";
			decodeTree->Print();
		}


		return new ShannonFanoInfo(decodeTree, encodeTree);
	}
};