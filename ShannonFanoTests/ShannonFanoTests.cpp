#include "CppUnitTest.h"
#include "../ShannonFano/ShannonFanoEncoder.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ShannonFanoTests
{
	TEST_CLASS(ShannonFanoTests)
	{
	public:
		
		TEST_METHOD(MassiveRandomTest)
		{
			

			for (size_t k = 0; k < 5; k++)
			{
				for (size_t i = 0; i < 200; i++)
				{
					String randomTestString;
					//fill string

					//yeah, my strings are deep copy (omg! everything is deep copied! even lists!), so performance not so brilliant 
					for (size_t j = 0; j < i; j++)
						randomTestString += (32 + rand() % 95);

					ShannonFanoEncoder encoder(randomTestString, false);

					String encoded = encoder.Encode(randomTestString);
					String decoded = encoder.Decode(encoded);

					if (decoded != randomTestString)
						Assert::Fail();
				}
			}
		}

		TEST_METHOD(MassiveRandomTestLengthDecoding)
		{


			for (size_t k = 0; k < 5; k++)
			{
				for (size_t i = 0; i < 200; i++)
				{
					String randomTestString;

					for (size_t j = 0; j < i; j++)
						randomTestString += (32 + rand() % 95);

					ShannonFanoEncoder encoder(randomTestString, false);

					String encoded = encoder.Encode(randomTestString);

					auto iterator = encoded.CreateBitIterator();

					if (randomTestString.Length() != iterator->GetOriginalStringLength())
						Assert::Fail();

					delete iterator;
				}
			}
		}

		TEST_METHOD(MassiveRandomTestSingleAlphabet)
		{
			//create alphabet
			String alphabet;

			for (char i = 32; i < 32 + 95; i++)
			{
				alphabet += i;
			}

			ShannonFanoEncoder encoder(alphabet, false);

			for (size_t k = 0; k < 5; k++)
			{
				for (size_t i = 0; i < 500; i++)
				{
					String randomTestString;

					for (size_t j = 0; j < i; j++)
						randomTestString += (32 + rand() % 95);

					

					String encoded = encoder.Encode(randomTestString);
					String decoded = encoder.Decode(encoded);

					if (decoded != randomTestString)
						Assert::Fail();

					
				}
			}
		}

	};
}
