#define BOOST_TEST_MODULE UNITTESTBYTESIZE

#include <boost/test/included/unit_test.hpp>
#include "../ByteSize.h"
#include <iomanip>

// Exactly thesame function used by ByteSize objects internally to
// resolve decimal precision error that may occur.
double ResolveDecimalPrecision(const double n, const int precision = 9)
{
	double integer_part, decimal_part;

	ostringstream ss;
	ss.setf(ios::fixed, ios::floatfield);
	ss.precision(precision);

	decimal_part = modf(n, &integer_part);
	if (decimal_part == 0) ss << (int)n;
	else ss << n;

	return (double)atof(ss.str().c_str());
}


BOOST_AUTO_TEST_SUITE(CreatingMethodsTest)

double val = 1.5;
double d0 = 1.5;

BOOST_AUTO_TEST_CASE(Constructor)
{
	// Arrange
	double byteSize = 1125899906842624;

	// Act
	ByteSize result = ByteSize(byteSize);

	double d0 = byteSize * 8;
	double d1 = byteSize / 1024;
	double d2 = byteSize / 1024 / 1024;
	double d3 = byteSize / 1024 / 1024 / 1024;
	double d4 = byteSize / 1024 / 1024 / 1024 / 1024;

	// Assert
	BOOST_CHECK(d0 == result.GetBits());
	BOOST_CHECK(byteSize == result.GetBytes());
	BOOST_CHECK(d1 == result.GetKibiBytes());
	BOOST_CHECK(d2 == result.GetMebiBytes());
	BOOST_CHECK(d3 == result.GetGibiBytes());
	BOOST_CHECK(d4 == result.GetTebiBytes());
	BOOST_CHECK(double(1) == result.GetPebiBytes());

	double d5 = byteSize / 1000;
	double d6 = ResolveDecimalPrecision(byteSize / 1000 / 1000);
	double d7 = ResolveDecimalPrecision(byteSize / 1000 / 1000 / 1000);
	double d8 = ResolveDecimalPrecision(byteSize / 1000 / 1000 / 1000 / 1000);
	double d9 = ResolveDecimalPrecision(byteSize / 1000 / 1000 / 1000 / 1000 / 1000);

	BOOST_CHECK(d5 == result.GetKiloBytes());
	BOOST_CHECK(d6 == result.GetMegaBytes());
	BOOST_CHECK(d7 == result.GetGigaBytes());
	BOOST_CHECK(d8 == result.GetTeraBytes());
	BOOST_CHECK(d9 == result.GetPetaBytes());
}

BOOST_AUTO_TEST_CASE(FromBitsMethod)
{
	// Arrange
    int64_t val = 8;

	// Act
	ByteSize result = ByteSize::FromBits(val);

	// Assert
	BOOST_CHECK(8 == result.GetBits());
	BOOST_CHECK(1 == result.GetBytes());
}

BOOST_AUTO_TEST_CASE(FromBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromBytes(val);

	// Assert
	BOOST_CHECK(12 == result.GetBits());
	BOOST_CHECK(d0 == result.GetBytes());
}

BOOST_AUTO_TEST_CASE(FromKibiBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromKibiBytes(val);

	// Assert
	BOOST_CHECK(1536 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetKibiBytes());
}

BOOST_AUTO_TEST_CASE(FromKiloBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromKiloBytes(val);

	// Assert
	BOOST_CHECK(1500 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetKiloBytes());
}

BOOST_AUTO_TEST_CASE(FromMebiBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromMebiBytes(val);

	// Assert
	BOOST_CHECK(1572864 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetMebiBytes());
}

BOOST_AUTO_TEST_CASE(FromMegaBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromMegaBytes(val);

	// Assert
	BOOST_CHECK(1500000 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetMegaBytes());
}

BOOST_AUTO_TEST_CASE(FromGibiBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromGibiBytes(val);

	// Assert
	BOOST_CHECK(1610612736 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetGibiBytes());
}

BOOST_AUTO_TEST_CASE(FromGigaBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromGigaBytes(val);

	// Assert
	BOOST_CHECK(1500000000 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetGigaBytes());
}

BOOST_AUTO_TEST_CASE(FromTebiBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromTebiBytes(val);

	// Assert
	BOOST_CHECK(1649267441664 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetTebiBytes());
}

BOOST_AUTO_TEST_CASE(FromTeraBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromTeraBytes(val);

	// Assert
	BOOST_CHECK(1500000000000 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetTeraBytes());
}

BOOST_AUTO_TEST_CASE(FromPebiBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromPebiBytes(val);

	// Assert
	BOOST_CHECK(1688849860263936 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetPebiBytes());
}

BOOST_AUTO_TEST_CASE(FromPetaBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromPetaBytes(val);

	// Assert
	BOOST_CHECK(1500000000000000 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetPetaBytes());
}

BOOST_AUTO_TEST_SUITE_END()