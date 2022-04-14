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

					//yeah, my strings are deep copy (omg! everything is deep copied! even lists!), so performance no so brilliant 
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
	};
}
