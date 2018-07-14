#ByteSizeCPP#

**`ByteSizeCPP`** is a C++11 library that handles how byte sizes are represented and an easy to use interface to convert to other forms of representation.

**Tested Enviroments:**
     
    Visual Studio 2015.

Example
---------

    #include "ByteSize.h"
	#include <iostream>

	using namespace std;

    int main()
    {
        ByteSize b1 = ByteSize::FromBits(1200);
		ByteSize b2 = ByteSize::FromBytes(1200)

		ByteSize b3 = b1 + b2;
		
		b3.AddMegaBytes(10.04);

		b4 = ByteSize::Parse("13.5MB")

        bool check = b3.CompareTo(b4);
        
		cout << b3.ToString("%d mb") << " " << b3.ToString("%.5f GB") << endl;

        return 0;
    }

 **Unit Tests:**

To run the unit tests, you should have [boost library](http://www.boost.org/) installed in your workstation.
    
License
----------
    Copyright (c) 2018 Mbadiwe Nnaemeka Ronald ron2tele@gmail.com

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
   