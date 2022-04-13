#pragma once

#include "List.h"
#include "String.h"
#include "RBTree.h"

//using namespace std;
class ShannonFanoEncoder
{
private:
	Map<char, String>* operationMap;

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
					(*results).Replace((*results)[i] + '0', i);
				else
					(*results).Replace((*results)[i] + '1', i);
			}

			//do it recursively until 1 or 0 characters left
			FillResultsListRecursive(leftIndex, middleIndex, probability, results);
			FillResultsListRecursive(middleIndex + 1, rightIndex, probability, results);
		}



	}

public:
	~ShannonFanoEncoder()
	{
		delete operationMap;
	}
	ShannonFanoEncoder(String alphabet)
	{
		operationMap = CreateOperationMap(alphabet);
	}
	Map<char, String>* GetOperationMapPointer()
	{
		return operationMap;
	}
	String Encode(String input)
	{
		return Encode(input, operationMap);
	}
	String Decode(String input)
	{
		return Decode(input, operationMap);
	}


	//some copies for static calls
	static String Encode(String input, Map<char, String>* operationMap)
	{
		cout << endl << "---------input string size: " << input.Length() * 8 << " bits" << endl;
		String output = "";

		//just iterate through all chars and get corresponding representation for each of them
		List<bool> bits;
		for (size_t i = 0; i < input.Length(); i++)
		{
			String bitCode = operationMap->Find(input[i]);
			for (size_t j = 0; j < bitCode.Length(); j++)
			{
				if (bitCode[j] == '1')
					bits.Add(true);
				else
					bits.Add(false);
			}
		}
		output.WriteBits(bits);
		cout << endl << "---------output string size: " << output.Length() * 8 << " bits" << endl;
		return output;
	}
	static String Decode(String input, Map<char, String>* operationMap)
	{
		cout << endl << "---------input string size: " << input.Length() * 8 << " bits" << endl;
		//1. split string by separator
		//List<String> parts = String::LazySplitv2(input, ' ');

		String output;
		String accumulator;

		//now find letter for each 
		//since operationMap has no objects with the same values...
		//it is going to work
		auto iterator = input.CreateBitIterator();
		while (iterator->HasNext())
		{
			int bit = iterator->Next();
			if (bit == 1)
				accumulator += '1';
			else
				accumulator += '0';

			//very bad solution...
			if (operationMap->ContainsValue(accumulator))
			{
				output += operationMap->FindFirstKeyByValue(accumulator);
				accumulator = "";
			}

		}
		delete iterator;
		cout << endl << "---------output string size: " << output.Length() * 8 << " bits" << endl;
		return output;


	}
	static Map<char, String>* CreateOperationMap(String alphabetInput)
	{
		//create alphabet
		List <char> alphabet;
		List<String> results;
		List <float> probability;
		List <int> count;

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

		//now count probabilities
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

		cout << "\nAlphabet:\n";
		alphabet.PrintToConsole();
		cout << "\nCounts:\n";
		count.PrintToConsole();
		cout << "\nProbabilities:\n";
		probability.PrintToConsole();



		for (size_t i = 0; i < alphabet.GetSize(); i++)
			results.Add("");



		int leftIndex = 0;
		int rightIndex = alphabet.GetSize() - 1;
		FillResultsListRecursive(leftIndex, rightIndex, &probability, &results);

		//thats all folks

		cout << "\nAlphabet codes:\n";
		results.PrintToConsole();


		Map<char, String>* operationMap = new Map<char, String>();
		//build table
		for (size_t i = 0; i < alphabet.GetSize(); i++)
			operationMap->Insert(alphabet[i], results[i]);

		operationMap->Print();

		return operationMap;
	}
};