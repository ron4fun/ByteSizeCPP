/*
Copyright(c) 2018 Mbadiwe Nnaemeka Ronald ron2tele@gmail.com

This software is provided 'as-is', without any express or implied
warranty.In no event will the author be held liable for any damages
arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions :

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software.If you use this software
in a product, an acknowledgment in the product documentation must be
specified.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.

3. This notice must not be removed or altered from any source distribution.
*/

#pragma once

#ifndef BYTESIZE_H
#define BYTESIZE_H

#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

//////////////////////
//// Exceptions
/////////////////////
class FormatException
{
public:
	FormatException(const char * text)
		: msg_(text)
	{}  // end constructor

	const char* what() const throw ()
	{
		return msg_.c_str();
	} // end function what

private:
	string msg_;

}; // end class FormatException

class ArgumentNullException
{
public:
	ArgumentNullException(const char * text)
		: msg_(text)
	{}  // end constructor

	const char* what() const throw ()
	{
		return msg_.c_str();
	} // end function what

private:
	string msg_;

}; // end class ArgumentNullException

//////////////////////
//// ByteSize Class
/////////////////////
class ByteSize
{
	//==================================================================
	//  Friend class
	//==================================================================

	friend ostream &operator<<(ostream &, const ByteSize &);

public:
	ByteSize(const double byteSize);

	inline int64_t GetBits() const
	{
		return Bits;
	}

	inline double GetBytes() const
	{
		return Bytes;
	}

	inline double GetKiloBytes() const
	{
		return KiloBytes;
	}

	inline double GetMegaBytes() const
	{
		return MegaBytes;
	}

	inline double GetGigaBytes() const
	{
		return GigaBytes;
	}

	inline double GetTeraBytes() const
	{
		return TeraBytes;
	}

	inline double GetPetaBytes() const
	{
		return PetaBytes;
	}

	static ByteSize FromBits(const int64_t value)
	{
		double dBitsInByte = BitsInByte;
		double tempDouble = double(value / dBitsInByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromBytes(const double value)
	{
		return ByteSize(value);
	}
		
	static ByteSize FromKiloBytes(const double value)
	{
		double tempDouble = double(value * BytesInKiloByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromMegaBytes(const double value)
	{
		double tempDouble = double(value * BytesInMegaByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromGigaBytes(const double value)
	{
		double tempDouble = double(value * BytesInGigaByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromTeraBytes(const double value)
	{
		double tempDouble = double(value * BytesInTeraByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromPetaBytes(const double value)
	{
		double tempDouble = double(value * BytesInPetaByte);
		return ByteSize(tempDouble);
	}

	int CompareTo(const ByteSize &bs) const
	{
		// return an integer
		if (Bits == bs.Bits) return 0;
		else if (Bits < bs.Bits) return -1;
		
		return 1;
	}

	ByteSize Add(const ByteSize &bs) const
	{
		return ByteSize(Bytes + bs.Bytes);
	}
	
	ByteSize AddBits(const int64_t value) const
	{
		return *this + FromBits(value);
	}
			
	ByteSize AddBytes(const double value) const
	{
		return *this + FromBytes(value);
	}
			
	ByteSize AddKiloBytes(const double value) const
	{
		return *this + FromKiloBytes(value);
	}
			
	ByteSize AddMegaBytes(const double value) const
	{
		return *this + FromMegaBytes(value);
	}
			
	ByteSize AddGigaBytes(const double value) const
	{
		return *this + FromGigaBytes(value);
	}
			
	ByteSize AddTeraBytes(const double value) const
	{
		return *this + FromTeraBytes(value);
	}
			
	ByteSize AddPetaBytes(const double value) const
	{
		return *this + FromPetaBytes(value);
	}
	
	ByteSize Subtract(const ByteSize &bs) const
	{
		return ByteSize(Bytes - bs.Bytes);
	}
			
	bool operator<(const ByteSize &bs) const
	{
		return Bits < bs.Bits;
	}

	bool operator<=(const ByteSize &bs) const
	{
		return Bits <= bs.Bits;
	}

	bool operator>(const ByteSize &bs) const
	{
		return Bits > bs.Bits;
	}

	bool operator>=(const ByteSize &bs) const
	{
		return Bits >= bs.Bits;
	}

	bool operator==(const ByteSize &bs) const
	{
		return Bits == bs.Bits;
	}

	bool operator!=(const ByteSize &bs) const
	{
		return Bits != bs.Bits;
	}

	ByteSize operator+(const ByteSize &bs) const
	{
		return Add(bs);
	}

	ByteSize operator+=(const ByteSize &bs)
	{
		*this = Add(bs);
		return *this;
	}

	ByteSize operator-(const ByteSize &bs) const
	{
		return Subtract(bs);
	}

	ByteSize operator-=(const ByteSize &bs)
	{
		*this = Subtract(bs);
		return *this;
	}

	ByteSize operator+()
	{
		return *this;
	}

	ByteSize operator-()
	{
		*this = ByteSize(-Bytes);
		return *this;
	}

	string ToString(string lformat = "KB") const
	{
		lformat = StripAllWhiteSpace(lformat, true);

		if (lformat.find('%') == -1 && (lformat.find('f') == -1 || lformat.find('d') == -1))
			lformat = "%.2f " + lformat;

		if (has("PB", lformat)) return output(PetaBytes, lformat);
		else if (has("TB", lformat)) return output(TeraBytes, lformat);
		else if (has("GB", lformat)) return output(GigaBytes, lformat);
		else if (has("MB", lformat)) return output(MegaBytes, lformat);
		else if (has("KB", lformat)) return output(KiloBytes, lformat);
		// Byte and Bit symbol must be case-sensitive
		else if (IndexOf(ByteSymbol, lformat, true) != -1) return output(double(Bytes), lformat);
		else if (IndexOf(BitSymbol, lformat, true) != -1) return output(double(Bits), lformat);

		ostringstream ss;
		ss.setf(ios::fixed, ios::floatfield);
		ss.precision(2);
		ss << LargestWholeNumberValue();
		ss << " " << LargestWholeNumberSymbol();
		return ss.str();
	}

	static ByteSize Parse(const string &s)
	{
		ByteSize bs(0);
		
		if (!TryParse(s, bs))
			throw FormatException("Value is not in the correct format");
			
		return bs;
	}

private:
	static string upper(const string &s)
	{
		string temp;
		temp.resize(s.size());
		for (register size_t i = 0; i < s.size(); i++)
			temp[i] = toupper(s[i]);

		return temp;
	}

	static bool has(const string &SubStr, const string &Str)
	{
		return IndexOf(SubStr, Str, false) != -1;
	}
		
	static bool Contains(const char InChar, const string &InString)
	{
		for (register size_t i = 0; i < InString.size(); i++)
		{
			if (InString[i] == InChar) return true;
		}
		
		return false;
	}

	static string StripAllWhiteSpace(const string &txt, const bool sides = false)
	{
		string temp = "";
		
		if (sides)
		{
			int index1 = 0;
			while (txt[index1] == ' ') index1++;
			
			int index2 = txt.find_last_not_of(' ');
			for (register int i = index1; i <= index2; i++)
			{
				if (txt[i] == ' ')
				{
					while (txt[i] == ' ')  i++;

					i--;
					temp += ' ';
					continue;
				}

				temp += txt[i];
			}
		}
		else
		{
			for (register size_t i = 0; i < txt.size(); i++)
			{
				if (txt[i] == ' ') continue;
				temp += txt[i];
			}
		}		
		
		return temp;
	}
		
	static int IndexOf(const string &SubStr, const string &Str, const bool caseSensitive)
	{
		// returns an integer
		if (caseSensitive) return Str.find(SubStr);

		string _Str = upper(Str);
		string _SubStr = upper(SubStr);
		return _Str.find(_SubStr);
	}
		
	static bool IsNullOrWhiteSpace(const string &InValue)
	{
		return StripAllWhiteSpace(InValue).size() == 0;
	}
		
	static double FloatingMod(const double a, const double b)
	{
		double tempDouble = (a / b);
		return a - b * int64_t(tempDouble);
	}
		
	static ByteSize GetMinValue()
	{
		return FromBits(0);
	}
	
	static ByteSize GetMaxValue()
	{
		return FromBits(Int64MaxValue);
	}

	static vector<string> Split(const string &s, const char ch = ' ')
	{
		vector<string> temp;
		string str;
		int indexf, indexl;

		indexl = s.find(ch);
		if (indexl == -1)
		{
			temp.push_back(s);
			return temp;
		}

		temp.push_back(s.substr(0, indexl));
		while (true)
		{
			indexf = s.find(ch, indexl + 1);
			if (indexf == -1)
			{
				temp.push_back(s.substr(indexl + 1, s.size() - indexl));
				break;
			}
			temp.push_back(s.substr(indexl + 1, indexf - indexl - 1));
			indexl = indexf;
		}

		return temp;
	}
	
	static size_t Count(const string &s, const char ch)
	{
		register size_t count = 0;

		for (register size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == ch) count++;
		}

		return count;
	}

	static string output(const double n, const string &formatstr)
	{
		vector<string> arr = Split(formatstr);

		if (arr.size() == 2)
		{
			int index = -1;
			string s1 = arr[0];
			bool chk = true;
			bool isDecimal = false;
			bool withDot = false;

			if (s1[s1.size() - 1] == ('f') || s1[s1.size() - 1] == ('d'))
			{
				if (index = s1.find_last_of("%.") != -1)
				{
					withDot = true;
				}
				else if (index = s1.find_last_of("%") != -1);
				else
					chk = false;
			}
			else
				chk = false;
			
			if ((index != 0 && !withDot) || (index != 1 && withDot))
				chk = false; // must begin with %.

			// check if any other symbol exist
			for (register size_t i = 0; i < s1.size(); i++)
			{
				char ch = s1[i];
				if (ch != '%' && ch != '.' && ch != 'f' && ch != 'd' && !(ch >= '0' && ch <= '9'))
					chk = false;
			}

			// makes sure there are single each
			if (Count(arr[0], '%') != 1 || !(Count(arr[0], '.') < 2) || !(Count(arr[0], 'f') == 1 || Count(arr[0], 'd') == 1))
				chk = false;	

			if (chk)
			{
				string temp;
				for (register size_t i = index + 1; i < s1.size() - 1; i++)
				{
					if (isdigit(s1[i]))
					{
						temp += arr[0][i];
					}
					else
					{
						chk = false;
						break;
					}
				}					

				if (chk)
				{
					int val = atoi(temp.c_str());
					ostringstream ss;
					isDecimal = s1[s1.size() - 1] == ('f') ? true : false;

					if (isDecimal)
					{
						ss.setf(ios::fixed, ios::floatfield);
						ss.precision(val);
					}
					else
					{
						ss << setfill('0') << setw(val);
					}

					ss << n << " " << arr[1];
					return ss.str();
				}
			}
		}
		
		throw FormatException("Value is not in the correct format");
	}

	static bool TryParse(const string &s, ByteSize &bs)
	{
		static const vector<char *> mags({ "b", "B", "KB", "kB", "kb", "MB", "mB", 
			"mb", "GB", "gB", "gb", "TB", "tB", "tb", "PB", "pB", "pb" });
		string tempS, numberPart, sizePart;
		bool found;
		size_t count, lastNumber;
		int tempInt;
		double d1;

		// Arg checking
		if (IsNullOrWhiteSpace(s))
			throw ArgumentNullException("Input String is null or whitespace");

		// Get the index of the first non - digit character
		tempS = StripAllWhiteSpace(s, true); // Protect against leading spaces
		found = false;

		// Pick first non - digit number
		count = 1;
		for (register size_t i = 0; i < tempS.size(); i++)
		{
			if (!(isdigit(tempS[i]) || tempS[i] == '.'))
			{
				found = true;
				break;
			}
				
			count += 1;
		}

		if (!found) return false;

		lastNumber = count - 1;

		if (lastNumber == 0) return false;

		// Cut the input string in half
		numberPart = StripAllWhiteSpace(tempS.substr(0, lastNumber), true);
		sizePart = StripAllWhiteSpace(tempS.substr(lastNumber));

		// Get the numeric part
		double number = atof(numberPart.c_str());
			
		// Get the magnitude part
		tempInt = -1;
		for (register size_t i = 0; i < mags.size(); i++)
		{
			if (strcmp(mags[i], sizePart.c_str()) == 0)
			{
				tempInt = i;
				break;
			}
		}

		switch (tempInt)
		{
		case -1:
			return false;

		case 0:
			d1 = 1 * 1.0;
			if (FloatingMod(number, d1) != 0) // Can't have partial bits
				return false;

			bs = FromBits(int64_t(number));
			return true;

		case 1:
			bs = FromBytes(number);
			return true;

		case 2:
		case 3:
		case 4:
			bs = FromKiloBytes(number);
			return true;

		case 5:
		case 6:
		case 7:
			bs = FromMegaBytes(number);
			return true;

		case 8:
		case 9:
		case 10:
			bs = FromGigaBytes(number);
			return true;

		case 11:
		case 12:
		case 13:
			bs = FromTeraBytes(number);
			return true;

		case 14:
		case 15:
		case 16:
			bs = FromPetaBytes(number);
			return true;
		}

		return false;
	}

private:
	string LargestWholeNumberSymbol() const
	{
		// Absolute value is used to deal with negative values
		if (abs(PetaBytes) >= 1) return PetaByteSymbol;
		else if (abs(TeraBytes) >= 1) return TeraByteSymbol;
		else if (abs(GigaBytes) >= 1) return GigaByteSymbol;
		else if (abs(MegaBytes) >= 1) return MegaByteSymbol;
		else if (abs(KiloBytes) >= 1) return KiloByteSymbol;
		else if (abs(Bytes) >= 1) return ByteSymbol;
		
		return BitSymbol;
	}
	
	double LargestWholeNumberValue() const
	{
		// Absolute value is used to deal with negative values
		if (abs(PetaBytes) >= 1) return PetaBytes;
		else if (abs(TeraBytes) >= 1) return TeraBytes;
		else if (abs(GigaBytes) >= 1) return GigaBytes;
		else if (abs(MegaBytes) >= 1) return MegaBytes;
		else if (abs(KiloBytes) >= 1) return KiloBytes;
		else if (abs(Bytes) >= 1) return Bytes;

		return double(Bits);
	}

private:
	int64_t Bits;
	double Bytes;
	double KiloBytes;
	double MegaBytes;
	double GigaBytes;
	double TeraBytes;
	double PetaBytes;

	static const int64_t Int64MaxValue = 9223372036854775807;
	static const int64_t BitsInByte = 8;
	static const int64_t BytesInKiloByte = 1024;
	static const int64_t BytesInMegaByte = 1048576;
	static const int64_t BytesInGigaByte = 1073741824;
	static const int64_t BytesInTeraByte = 1099511627776;
	static const int64_t BytesInPetaByte = 1125899906842624;

	static const char * BitSymbol;
	static const char * ByteSymbol;
	static const char * KiloByteSymbol;
	static const char * MegaByteSymbol;
	static const char * GigaByteSymbol;
	static const char * TeraByteSymbol;
	static const char * PetaByteSymbol;
};

const char * ByteSize::BitSymbol = "b";
const char * ByteSize::ByteSymbol = "B";
const char * ByteSize::KiloByteSymbol = "KB";
const char * ByteSize::MegaByteSymbol = "MB";
const char * ByteSize::GigaByteSymbol = "GB";
const char * ByteSize::TeraByteSymbol = "TB";
const char * ByteSize::PetaByteSymbol = "PB";

ByteSize::ByteSize(const double byteSize)
{
	double tempDouble = byteSize * BitsInByte;

	// Get Truncation because bits are whole units
	Bits = int64_t(tempDouble);
	Bytes = byteSize;
	KiloBytes = byteSize / BytesInKiloByte;
	MegaBytes = byteSize / BytesInMegaByte;
	GigaBytes = byteSize / BytesInGigaByte;
	TeraBytes = byteSize / BytesInTeraByte;
	PetaBytes = byteSize / BytesInPetaByte;
}

ostream &operator<<(ostream &output, const ByteSize &value)
{
	output << value.ToString();
	return output; // enables cout << a << b << c;
} // end function operator<<

#endif // !BYTESIZE_H

