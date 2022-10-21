ByteSizeCPP [![License](http://img.shields.io/badge/license-MIT-green.svg)](https://github.com/ron4fun/ByteSizeCPP/blob/master/LICENSE)
====

**`ByteSizeCPP`** is a C++11 library that handles how byte sizes are represented while adopting the `International Electrotechnical Commission` ([IEC](https://en.wikipedia.org/wiki/Byte)) proposed standard (kibi, mebi, gibi etc.) and also providing an easy to use interface for conversion from one form of representation to the other.

### **The `ToString` Function**

There are two functions that can help you convert ByteSize objects to string:
	
	> ToString(ByteSizeUnit unit_repr = BinaryUnit, int precision = 2)
	> ToString(string unit, int precision = 2)
	
Both functions throw the `FormatException` if the `precision` is a negetive value. Also, if the input string `unit` is incorrectly 
formatted. 

	
	Where:
		ByteSizeUnit representation is an enum { BinaryUnit, DecimalUnit }
		also,
		precision > 0, returns a decimal value 
		precision == 0, returns a non decimal value
		precision < 0, throws the `FormatException`


### **The `Parse` and `TryParse` Function**
	
These are two static functions for parsing of input string to ByteSize objects:

	> ByteSize Parse(string s);
	
Throws the `FormatException` if input string is incorrectly formatted.

	> bool TryParse(string s, ByteSize &bs)
	  
Returns false if input string is incorrectly formatted and true 
if good and stores the newly created ByteSize object in `bs`, 
which is passed by reference to the function.


### **All The Acceptable Input String Unit Formats**
 
	
Here are all the acceptable input string `unit` formats:

	"b" => Bit
	"B" => Byte 
	"KiB" => KibiByte 
	"KB" => KiloByte
	"MiB" => MebiByte 
	"MB" => MegaByte
	"GiB" => GibiByte 
	"GB" => GigaByte
	"TiB" => TebiByte
	"TB" => TeraByte
	"PiB" => PebiByte 
	"PB" => PetaByte
	"EiB" => ExbiByte
	"EB" => ExaByte
	
All symbols between parenthesis are good. Also, be careful about the 
	  case-sentivity when it comes to `b` and `B`.


Example
---------

```c++
#include "ByteSize.h"
#include <iostream>

using namespace std;

int main()
{
  ByteSize b1 = ByteSize::FromBits(1200);
  ByteSize b2 = ByteSize::FromBytes(1200);

  ByteSize b3 = b1 + b2;

  ByteSize b4 = b3.AddMebiBytes(10.04);

  ByteSize b5 = ByteSize::Parse("13.5MiB");

  int check = b4.CompareTo(b5); // -1

  cout << b4.ToString("mb", 0) << endl; // 11 MB
  cout << b5.ToString("GB", 5) << endl; // 0.01416 GB

  return 0;
}
```

**Tested Enviroments:**
     
    Visual Studio 2019.


 **Unit Tests:**

To run the unit tests, you should have [boost library](http://www.boost.org/) installed in your workstation. 
You can also follow this [guide](https://tomkoos.github.io/cpp/boost-vs.html) to help install `boost` library properly on your computer.
 
License
----------
    Copyright (c) 2018 - 2022 Mbadiwe Nnaemeka Ronald ron2tele@gmail.com

    This software is provided 'as-is', without any express or implied
    warranty. In no event will the author be held liable for any damages
    arising from the use of this software.
    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:
    
    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation must be
    specified.
    
    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.
    
    3. This notice may not be removed or altered from any source distribution.
        
     
#### Tip Jar
* :dollar: **Bitcoin**: `1Mcci95WffSJnV6PsYG7KD1af1gDfUvLe6`


Conclusion
--------------------------------------------------

   Special thanks to [Xor-el](https://github.com/xor-el) for making this library available in the first place.
   
