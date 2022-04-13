#pragma once

#include <iostream>
using namespace std;

class String
{
private:
	size_t length;
	char* value;

	void RewriteArray(String& from)
	{
		if (this->value != nullptr)
			delete[] this->value;

		char* copy = new char[from.length + 1];
		for (size_t i = 0; i < from.length; i++)
			copy[i] = from.value[i];

		copy[from.length] = '\0';
		this->length = from.length;
		this->value = copy;
	}
public:
	size_t Length()
	{
		return length;
	}

	//Low-level functions

	char* GetArrayCopy()
	{
		char* val = new char[length + 1];
		for (size_t i = 0; i < length; i++)
			val[i] = value[i];
		val[length] = '\0';

		return val;
	}
	char* GetArrayPointer()
	{
		return value;
	}

	//CONSTRUCTORS
	//copy constructor
	String(const String& other)
	{
		char* copy = new char[other.length + 1];
		for (size_t i = 0; i < other.length; i++)
			copy[i] = other.value[i];
		copy[other.length] = '\0';

		length = other.length;
		value = copy;
	}
	String()
	{
		length = 0;
		value = new char[1];
		value[0] = '\0';
	}
	String(const char* value)
	{
		length = 0;
		while (value[length] != '\0')
			length++;

		char* copy = new char[length];
		for (size_t i = 0; i < length; i++)
			copy[i] = value[i];

		this->value = copy;
	}
	String(const char value)
	{
		length = 1;
		char* copy = new char[2];
		copy[0] = value;
		copy[1] = '\0';

		this->value = copy;
	}

	~String()
	{
		if (value != nullptr)
			delete[] value;
	}

	//Operator overloads
	bool operator==(String& toCompare)
	{
		return Equals(toCompare);
	}
	String operator=(const String& other)
	{
		if (this != &other)
		{
			length = other.length;
			char* copy = new char[length + 1];
			for (size_t i = 0; i < length; i++)
				copy[i] = other.value[i];
			copy[length] = '\0';

			delete[] value;
			this->value = copy;
		}
		return *this;
	}
	String operator+(const char* other)
	{
		String returnVal = *this;
		returnVal.Concat(other);
		return returnVal;
	}
	String operator+(String other)
	{
		String returnVal = *this;
		returnVal.Concat(other);
		return returnVal;
	}
	String operator+=(String other)
	{
		Concat(other);
		return *this;
	}
	String operator+=(const char* other)
	{
		Concat(other);
		return *this;
	}
	String operator+=(char other)
	{
		Concat(other);
		return *this;
	}
	char operator[] (size_t index)
	{
		return value[index];
	}
	friend ostream& operator<<(ostream& stream, const String& string)
	{
		//stream << "\"";
		for (size_t i = 0; i < string.length; i++)
		{
			if (string.value[i] < 32 || string.value[i] > 127)
				stream << '?';
			else
				stream << string.value[i];
		}
		//stream << "\"";
		return stream;
	}
	//concatenation functions
	void Concat(const char* toAdd)
	{
		size_t addLen = 0;
		while (toAdd[addLen] != '\0')
			addLen++;

		char* newVal = new char[length + addLen + 1];

		for (size_t i = 0; i < length; i++)
			newVal[i] = value[i];
		for (size_t i = 0; i < addLen; i++)
			newVal[i + length] = toAdd[i];

		newVal[length + addLen] = '\0';

		delete[] value;
		value = newVal;
		length = length + addLen;
	}
	void Concat(char toAdd)
	{
		char* newVal = new char[length + 2];

		for (size_t i = 0; i < length; i++)
			newVal[i] = value[i];
		newVal[length] = toAdd;
		newVal[length + 1] = '\0';

		length++;
		if (value != nullptr)
			delete[] value;
		value = newVal;
	}
	void Concat(String& toAdd)
	{
		size_t addLen = toAdd.length;
		char* newVal = new char[length + addLen + 1];

		for (size_t i = 0; i < length; i++)
			newVal[i] = value[i];
		for (size_t i = 0; i < addLen; i++)
			newVal[i + length] = toAdd.value[i];

		newVal[length + addLen] = '\0';

		delete[] value;
		value = newVal;
		length = length + addLen;
	}

	//... another useless comment
	bool Equals(const char* toCompare)
	{
		if (strlen(toCompare) != length)
			return false;

		for (size_t i = 0; i < length; i++)
			if (value[i] != toCompare[i])
				return false;

		return true;
	}
	bool Equals(String toCompare)
	{
		if (toCompare.length != length)
			return false;
		for (size_t i = 0; i < length; i++)
			if (value[i] != toCompare[i])
				return false;

		return true;
	}

	bool Contains(char toCompare)
	{
		for (size_t i = 0; i < length; i++)
			if (value[i] == toCompare)
				return true;

		return false;
	}
	bool Contains(String toCompare)
	{
		if (toCompare.length > length)
			return false;

		for (size_t i = 0; i < length; i++)
		{
			if (value[i] == toCompare[0])
			{
				bool areDifferent = false;
				//first symbol is equal, check the rest
				for (size_t j = 1; j < toCompare.length; j++)
				{
					if (value[i + j] != toCompare[j])
					{
						areDifferent = true;
						break;
					}
				}
				if (!areDifferent)
					return true;
			}
		}
		return false;
	}


	//Lazy concat implementation
	String Substring(size_t startIndex, size_t endIndex)
	{
		String result;
		for (size_t i = startIndex; i < endIndex; i++)
			result += value[i];
		return result;
	}
	String Substring(size_t startIndex)
	{
		String result;
		for (size_t i = startIndex; i < length; i++)
			result += value[i];
		return result;
	}

	//replaces first entry of oldValue to newValue
	void ReplaceFirst(String oldValue, String newValue)
	{
		if (Contains(oldValue))
		{
			//find start index
			size_t startIndex = -1;
			for (size_t i = 0; i < length; i++)
			{
				if (value[i] == oldValue[0])
				{
					bool areDifferent = false;
					//first symbol is equal, check the rest
					for (size_t j = 1; j < oldValue.length; j++)
					{
						if (oldValue[j] != value[i + j])
						{
							areDifferent = true;
							break;
						}
					}
					if (!areDifferent)
					{
						startIndex = i;
						break;
					}
				}
			}

			//split string into 2 pieces between oldValue
			String first = Substring(0, startIndex);
			String second = Substring(startIndex + oldValue.length);

			first += newValue + second;

			RewriteArray(first);
		}
	}
	//replaces all occurences of oldValue with newValue
	void ReplaceAll(String oldValue, String newValue)
	{
		while (Contains(oldValue))
			ReplaceFirst(oldValue, newValue);
	}



	//static functions
	static List<String> LazySplitv2(String& source, char separator)
	{
		List<String> result;
		size_t newStringCount = 1, length = source.length;
		char* value = source.value;

		for (size_t i = 0; i < length; i++)
			if (value[i] == separator)
				newStringCount++;

		size_t* markers = new size_t[newStringCount];
		markers[newStringCount - 1] = length;

		//setup markers
		size_t counter = 0;
		for (size_t i = 0; i < length; i++)
		{
			if (value[i] == separator)
			{
				markers[counter] = i;
				counter++;
			}
		}

		size_t markerIndex = -1;
		size_t lastMarkerIndex = -1;
		for (size_t i = 0; i < newStringCount; i++)
		{
			markerIndex++;
			String segment;
			for (size_t j = lastMarkerIndex + 1; j < length; j++)
			{
				if (j > length - 1)
					break;

				if (j < markers[markerIndex])
					segment += (value[j]);
				else
					break;
			}
			if (segment.length > 0)
				result.Add(segment);

			lastMarkerIndex = markers[markerIndex];
		}

		delete[] markers;
		return result;
	}
	static String FromDouble(double value)
	{
		char c[50];
		sprintf_s(c, "%f", value);
		String toReturn(c);
		return toReturn;
	}

	//bit add-on


	class StringBitIterator
	{
	private:
		size_t currentBitPos = 0;
		String* str;
	public:
		bool Next()
		{
			return (str->value[(currentBitPos / 8)] >> (currentBitPos++ % 8)) & 1;
		};
		bool HasNext()
		{
			return currentBitPos < str->length * 8;
		};


		StringBitIterator(String* str)
		{
			this->str = str;
		}
	};
	StringBitIterator* CreateBitIterator()
	{
		return new StringBitIterator(this);
	}

	void WriteBits(List<bool> bits)
	{
		delete value;

		size_t charCount = bits.GetSize() / 8;
		if (bits.GetSize() % 8 != 0)
			charCount++;

		length = charCount;
		value = new char[length + 1];


		for (size_t i = 0; i < length; i++)
			value[i] = 0;

		value[length] = '\0';

		//now we somehow smash these bits across chars
		for (size_t c = 0; c < length; c++)
		{
			size_t offset = c * 8;
			for (size_t bit = 0; bit < 8; bit++)
			{
				if (offset + bit > bits.GetSize() - 1)
					break;
				if (bits[offset + bit])
					value[c] |= 1 << bit;
				else
					value[c] &= ~(1 << bit);
			}
		}

	}
};