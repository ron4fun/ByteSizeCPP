/*
Copyright(c) 2018 - 2022 Mbadiwe Nnaemeka Ronald ron2tele@gmail.com

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


// Unit of representation of byte sizes
enum ByteSizeUnit { BinaryUnit, DecimalUnit };

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
	ByteSize(const double byteSize = 0);

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
	
	inline double GetKibiBytes() const
	{
		return KibiBytes;
	}

	inline double GetMegaBytes() const
	{
		return MegaBytes;
	}

	inline double GetMebiBytes() const
	{
		return MebiBytes;
	}

	inline double GetGigaBytes() const
	{
		return GigaBytes;
	}

	inline double GetGibiBytes() const
	{
		return GibiBytes;
	}

	inline double GetTeraBytes() const
	{
		return TeraBytes;
	}

	inline double GetTebiBytes() const
	{
		return TebiBytes;
	}

	inline double GetPetaBytes() const
	{
		return PetaBytes;
	}

	inline double GetPebiBytes() const
	{
		return PebiBytes;
	}

	static ByteSize FromBits(const int64_t value)
	{
		double tempDouble = (double)value / (double)BitsInByte;
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

	static ByteSize FromKibiBytes(const double value)
	{
		double tempDouble = double(value * BytesInKibiByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromMegaBytes(const double value)
	{
		double tempDouble = double(value * BytesInMegaByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromMebiBytes(const double value)
	{
		double tempDouble = double(value * BytesInMebiByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromGigaBytes(const double value)
	{
		double tempDouble = double(value * BytesInGigaByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromGibiBytes(const double value)
	{
		double tempDouble = double(value * BytesInGibiByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromTeraBytes(const double value)
	{
		double tempDouble = double(value * BytesInTeraByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromTebiBytes(const double value)
	{
		double tempDouble = double(value * BytesInTebiByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromPetaBytes(const double value)
	{
		double tempDouble = double(value * BytesInPetaByte);
		return ByteSize(tempDouble);
	}

	static ByteSize FromPebiBytes(const double value)
	{
		double tempDouble = double(value * BytesInPebiByte);
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
			
	ByteSize AddKibiBytes(const double value) const
	{
		return *this + FromKibiBytes(value);
	}

	ByteSize AddMegaBytes(const double value) const
	{
		return *this + FromMegaBytes(value);
	}
			
	ByteSize AddMebiBytes(const double value) const
	{
		return *this + FromMebiBytes(value);
	}

	ByteSize AddGigaBytes(const double value) const
	{
		return *this + FromGigaBytes(value);
	}
			
	ByteSize AddGibiBytes(const double value) const
	{
		return *this + FromGibiBytes(value);
	}

	ByteSize AddTeraBytes(const double value) const
	{
		return *this + FromTeraBytes(value);
	}
			
	ByteSize AddTebiBytes(const double value) const
	{
		return *this + FromTebiBytes(value);
	}

	ByteSize AddPetaBytes(const double value) const
	{
		return *this + FromPetaBytes(value);
	}
	
	ByteSize AddPebiBytes(const double value) const
	{
		return *this + FromPebiBytes(value);
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

	string ToString(ByteSizeUnit unit_repr = ByteSizeUnit::BinaryUnit, int precision = 2) const
	{
		if (unit_repr == ByteSizeUnit::BinaryUnit) 
			return Output(
				LargestWholeNumberValue(true, unit_repr),
				LargestWholeNumberSymbol(true, unit_repr), 
				precision);
		else if (unit_repr == ByteSizeUnit::DecimalUnit) 
			return Output(
				LargestWholeNumberValue(true, unit_repr),
				LargestWholeNumberSymbol(true, unit_repr), 
				precision);
		else throw FormatException("Byte size unit is not in the correct format");
	}

	string ToString(string unit, int precision = 2) const
	{
		if (precision < 0) throw FormatException("Precision cannot be negative");

		unit = StripAllWhiteSpace(unit, true);

		if (unit.empty()) return Output(LargestWholeNumberValue(), LargestWholeNumberSymbol(), precision);
		if (unit.size() != 1) {
			if (EqualsIgnoreCase(unit, "PiB")) return Output(PebiBytes, "PiB", precision);
			else if (EqualsIgnoreCase(unit, "PB")) return Output(PetaBytes, "PB", precision);
			else if (EqualsIgnoreCase(unit, "TiB")) return Output(TebiBytes, "TiB", precision);
			else if (EqualsIgnoreCase(unit, "TB")) return Output(TeraBytes, "TB", precision);
			else if (EqualsIgnoreCase(unit, "GiB")) return Output(GibiBytes, "GiB", precision);
			else if (EqualsIgnoreCase(unit, "GB")) return Output(GigaBytes, "GB", precision);
			else if (EqualsIgnoreCase(unit, "MiB")) return Output(MebiBytes, "MiB", precision);
			else if (EqualsIgnoreCase(unit, "MB")) return Output(MegaBytes, "MB", precision);
			else if (EqualsIgnoreCase(unit, "KiB")) return Output(KibiBytes, "KiB", precision);
			else if (EqualsIgnoreCase(unit, "KB")) return Output(KiloBytes, "KB", precision);
		}
		else {
			// Byte and Bit symbol must be case-sensitive
			if (IndexOf(ByteSymbol, unit, true) != -1) return Output(double(Bytes), "B", precision);
			else if (IndexOf(BitSymbol, unit, true) != -1) return Output(double(Bits), "b", precision);
		}
		
		throw FormatException("Byte size unit is not in the correct format");	
	}
	
	static ByteSize Parse(const string &s)
	{
		ByteSize bs(0);
		
		if (!TryParse(s, bs))
			throw FormatException("Value is not in the correct format");
			
		return bs;
	}

	static bool TryParse(const string& s, ByteSize& bs)
	{
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
			if (i > 1 && EqualsIgnoreCase(mags[i], sizePart.c_str()))
			{
				tempInt = int(i);
				break;
			}
			else if (sizePart == mags[i]) // sensitive comparison for b and B symbols
			{
				tempInt = int(i);
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
			bs = FromKibiBytes(number);
			return true;
		case 3:
			bs = FromKiloBytes(number);
			return true;

		case 4:
			bs = FromMebiBytes(number);
			return true;
		case 5:
			bs = FromMegaBytes(number);
			return true;

		case 6:
			bs = FromGibiBytes(number);
			return true;
		case 7:
			bs = FromGigaBytes(number);
			return true;

		case 8:
			bs = FromTebiBytes(number);
			return true;
		case 9:
			bs = FromTeraBytes(number);
			return true;

		case 10:
			bs = FromPebiBytes(number);
			return true;
		case 11:
			bs = FromPetaBytes(number);
			return true;
		}

		return false;
	}

private:
	static string ToUpper(const string &s)
	{
		string temp;
		temp.resize(s.size());
		for (register size_t i = 0; i < s.size(); i++)
			temp[i] = toupper(s[i]);

		return temp;
	}
		
	static bool EqualsIgnoreCase(const string& a, const string& b) 
	{
		return _stricmp(a.c_str(), b.c_str()) == 0; // insensitive comparison
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
			size_t index1 = 0;
			while (txt[index1] == ' ') index1++;
			
			size_t index2 = txt.find_last_not_of(' ');
			for (register size_t i = index1; i <= index2; i++)
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
		if (caseSensitive) return (int)Str.find(SubStr);

		string _Str = ToUpper(Str);
		string _SubStr = ToUpper(SubStr);
		return (int)_Str.find(_SubStr);
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

	static size_t Count(const string &s, const char ch)
	{
		register size_t count = 0;

		for (register size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == ch) count++;
		}

		return count;
	}

	static string Output(const double n, const string &unit, const int precision)
	{
		ostringstream ss;
		ss.setf(ios::fixed, ios::floatfield);
		ss.precision(precision);
		ss << n;
		ss << " " << unit;
		return ss.str();		
	}

	static double ResolveDecimalPrecision(const double n, const int precision = 9)
	{
		ostringstream ss;
		ss.setf(ios::fixed, ios::floatfield);
		ss.precision(precision);
		ss << n;
		return (double)atof(ss.str().c_str());
	}

private:
	string LargestWholeNumberSymbol(bool check_repr = false, ByteSizeUnit unit_repr = ByteSizeUnit::BinaryUnit) const
	{
		if (check_repr) {
			if (unit_repr == ByteSizeUnit::BinaryUnit)
			{
				// Absolute value is used to deal with negative values
				if (abs(PebiBytes) >= 1) return PebiByteSymbol;
				else if (abs(TebiBytes) >= 1) return TebiByteSymbol;
				else if (abs(GibiBytes) >= 1) return GibiByteSymbol;
				else if (abs(MebiBytes) >= 1) return MebiByteSymbol;
				else if (abs(KibiBytes) >= 1) return KibiByteSymbol;
			} 
			else if (unit_repr == ByteSizeUnit::DecimalUnit)
			{
				// Absolute value is used to deal with negative values
				if (abs(PetaBytes) >= 1) return PetaByteSymbol;
				else if (abs(TeraBytes) >= 1) return TeraByteSymbol;
				else if (abs(GigaBytes) >= 1) return GigaByteSymbol;
				else if (abs(MegaBytes) >= 1) return MegaByteSymbol;
				else if (abs(KiloBytes) >= 1) return KiloByteSymbol;
			}
		}
		else {
			// Absolute value is used to deal with negative values
			if (abs(PebiBytes) >= 1) return PebiByteSymbol;
			else if (abs(PetaBytes) >= 1) return PetaByteSymbol;
			else if (abs(TebiBytes) >= 1) return TebiByteSymbol;
			else if (abs(TeraBytes) >= 1) return TeraByteSymbol;
			else if (abs(GibiBytes) >= 1) return GibiByteSymbol;
			else if (abs(GigaBytes) >= 1) return GigaByteSymbol;
			else if (abs(MebiBytes) >= 1) return MebiByteSymbol;
			else if (abs(MegaBytes) >= 1) return MegaByteSymbol;
			else if (abs(KibiBytes) >= 1) return KibiByteSymbol;
			else if (abs(KiloBytes) >= 1) return KiloByteSymbol;
		}

		if (abs(Bytes) >= 1) return ByteSymbol;

		return BitSymbol;
	}
	
	double LargestWholeNumberValue(bool check_repr = false, ByteSizeUnit unit_repr = ByteSizeUnit::BinaryUnit) const
	{
		if (check_repr) {
			if (unit_repr == ByteSizeUnit::BinaryUnit)
			{
				if (abs(PebiBytes) >= 1) return PebiBytes;
				else if (abs(TebiBytes) >= 1) return TebiBytes;
				else if (abs(GibiBytes) >= 1) return GibiBytes;
				else if (abs(MebiBytes) >= 1) return MebiBytes;
				else if (abs(KibiBytes) >= 1) return KibiBytes;
			}
			else if (unit_repr == ByteSizeUnit::DecimalUnit)
			{
				if (abs(PetaBytes) >= 1) return PetaBytes;
				else if (abs(TeraBytes) >= 1) return TeraBytes;
				else if (abs(GigaBytes) >= 1) return GigaBytes;
				else if (abs(MegaBytes) >= 1) return MegaBytes;
				else if (abs(KiloBytes) >= 1) return KiloBytes;
			}
		}
		else {
			// Absolute value is used to deal with negative values
			if (abs(PebiBytes) >= 1) return PebiBytes;
			else if (abs(PetaBytes) >= 1) return PetaBytes;
			else if (abs(TebiBytes) >= 1) return TebiBytes;
			else if (abs(TeraBytes) >= 1) return TeraBytes;
			else if (abs(GibiBytes) >= 1) return GibiBytes;
			else if (abs(GigaBytes) >= 1) return GigaBytes;
			else if (abs(MebiBytes) >= 1) return MebiBytes;
			else if (abs(MegaBytes) >= 1) return MegaBytes;
			else if (abs(KibiBytes) >= 1) return KibiBytes;
			else if (abs(KiloBytes) >= 1) return KiloBytes;			
		}

		if (abs(Bytes) >= 1) return Bytes;

		return double(Bits);
	}

private:
	// Binary Units
	int64_t Bits;
	double Bytes;
	double KibiBytes;
	double MebiBytes;
	double GibiBytes;
	double TebiBytes;
	double PebiBytes;

	// Decimal Units
	double KiloBytes;
	double MegaBytes;
	double GigaBytes;
	double TeraBytes;
	double PetaBytes;

	//
	static const int64_t Int64MaxValue = 9223372036854775807;
	static const int64_t BitsInByte = 8;
	static const int64_t BytesInKibiByte = 1024;
	static const int64_t BytesInMebiByte = 1048576;
	static const int64_t BytesInGibiByte = 1073741824;
	static const int64_t BytesInTebiByte = 1099511627776;
	static const int64_t BytesInPebiByte = 1125899906842624;

	static const int64_t BytesInKiloByte = 1000;
	static const int64_t BytesInMegaByte = 1000000;
	static const int64_t BytesInGigaByte = 1000000000;
	static const int64_t BytesInTeraByte = 1000000000000;
	static const int64_t BytesInPetaByte = 1000000000000000;

	// Binary Units
	static const char * BitSymbol;
	static const char * ByteSymbol;
	static const char * KibiByteSymbol;
	static const char * MebiByteSymbol;
	static const char * GibiByteSymbol;
	static const char * TebiByteSymbol;
	static const char * PebiByteSymbol;

	// Decimal Units
	static const char * KiloByteSymbol;
	static const char * MegaByteSymbol;
	static const char * GigaByteSymbol;
	static const char * TeraByteSymbol;
	static const char * PetaByteSymbol;

	static const vector<char*> mags;
};


#pragma region Binary Units

const char* ByteSize::BitSymbol = "b";
const char* ByteSize::ByteSymbol = "B";
const char* ByteSize::KibiByteSymbol = "KiB";
const char* ByteSize::MebiByteSymbol = "MiB";
const char* ByteSize::GibiByteSymbol = "GiB";
const char* ByteSize::TebiByteSymbol = "TiB";
const char* ByteSize::PebiByteSymbol = "PiB";

#pragma endregion


#pragma region Decimal Units

const char* ByteSize::KiloByteSymbol = "KB";
const char* ByteSize::MegaByteSymbol = "MB";
const char* ByteSize::GigaByteSymbol = "GB";
const char* ByteSize::TeraByteSymbol = "TB";
const char* ByteSize::PetaByteSymbol = "PB";

#pragma endregion

//
const vector<char*> ByteSize::mags = vector<char*>({ 
	"b", "B", "KiB", "KB", "MiB", "MB",
			"GiB", "GB", "TiB", "TB", "PiB", "PB"});

ByteSize::ByteSize(const double byteSize)
{
	double tempDouble = byteSize * BitsInByte;

	// Get Truncation because bits are whole units
	Bits = int64_t(tempDouble);
	Bytes = byteSize;
	KibiBytes = ResolveDecimalPrecision(byteSize / BytesInKibiByte);
	MebiBytes = ResolveDecimalPrecision(byteSize / BytesInMebiByte);
	GibiBytes = ResolveDecimalPrecision(byteSize / BytesInGibiByte);
	TebiBytes = ResolveDecimalPrecision(byteSize / BytesInTebiByte);
	PebiBytes = ResolveDecimalPrecision(byteSize / BytesInPebiByte);

	// Decimal Units
	KiloBytes = ResolveDecimalPrecision(byteSize / BytesInKiloByte);
	MegaBytes = ResolveDecimalPrecision(byteSize / BytesInMegaByte);
	GigaBytes = ResolveDecimalPrecision(byteSize / BytesInGigaByte);
	TeraBytes = ResolveDecimalPrecision(byteSize / BytesInTeraByte);
	PetaBytes = ResolveDecimalPrecision(byteSize / BytesInPetaByte);
}

ostream &operator<<(ostream &output, const ByteSize &value)
{
	output << value.ToString();
	return output; // enables cout << a << b << c;
} // end function operator<<

#endif // !BYTESIZE_H

