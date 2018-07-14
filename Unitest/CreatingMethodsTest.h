#define BOOST_TEST_MODULE UNITTESTBYTESIZE

#include <boost/test/included/unit_test.hpp>
#include "../ByteSize.h"


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
	BOOST_CHECK(d1 == result.GetKiloBytes());
	BOOST_CHECK(d2 == result.GetMegaBytes());
	BOOST_CHECK(d3 == result.GetGigaBytes());
	BOOST_CHECK(d4 == result.GetTeraBytes());
	BOOST_CHECK(double(1) == result.GetPetaBytes());
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

BOOST_AUTO_TEST_CASE(FromKiloBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromKiloBytes(val);

	// Assert
	BOOST_CHECK(1536 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetKiloBytes());
}

BOOST_AUTO_TEST_CASE(FromMegaBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromMegaBytes(val);

	// Assert
	BOOST_CHECK(1572864 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetMegaBytes());
}

BOOST_AUTO_TEST_CASE(FromGigaBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromGigaBytes(val);

	// Assert
	BOOST_CHECK(1610612736 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetGigaBytes());
}

BOOST_AUTO_TEST_CASE(FromTeraBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromTeraBytes(val);

	// Assert
	BOOST_CHECK(1649267441664 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetTeraBytes());
}

BOOST_AUTO_TEST_CASE(FromPetaBytesMethod)
{
	// Act
	ByteSize result = ByteSize::FromPetaBytes(val);

	// Assert
	BOOST_CHECK(1688849860263936 == result.GetBytes());
	BOOST_CHECK(d0 == result.GetPetaBytes());
}

BOOST_AUTO_TEST_SUITE_END()