#define BOOST_TEST_MODULE UNITTESTBYTESIZE

#include <boost/test/included/unit_test.hpp>
#include "../ByteSize.h"


BOOST_AUTO_TEST_SUITE(ArithmeticMethodsTest)

int d2 = 2;
int i16 = 16;

BOOST_AUTO_TEST_CASE(AddMethod)
{
	ByteSize size1 = ByteSize::FromBytes(1);
	ByteSize result = size1.Add(size1);

	BOOST_CHECK(d2 == result.GetBytes());
	BOOST_CHECK(i16 == result.GetBits());
}

BOOST_AUTO_TEST_CASE(AddBitsMethod)
{
	ByteSize size = ByteSize::FromBytes(1).AddBits(8);

	BOOST_CHECK(d2 == size.GetBytes());
	BOOST_CHECK(i16 == size.GetBits());
}

BOOST_AUTO_TEST_CASE(AddBytesMethod)
{
	ByteSize size = ByteSize::FromBytes(1).AddBytes(1);

	BOOST_CHECK(d2 == size.GetBytes());
	BOOST_CHECK(i16 == size.GetBits());
}

BOOST_AUTO_TEST_CASE(AddKibiBytesMethod)
{
	double d1 = 4 * 1024;
	double d2 = 4;
	ByteSize size = ByteSize::FromKibiBytes(2).AddKibiBytes(2);
	
	BOOST_CHECK(int64_t(4 * 1024 * 8) == size.GetBits());
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKibiBytes());
}

BOOST_AUTO_TEST_CASE(AddKiloBytesMethod)
{
	double d1 = 4 * 1000;
	double d2 = 4;
	ByteSize size = ByteSize::FromKiloBytes(2).AddKiloBytes(2);

	BOOST_CHECK(int64_t(4 * 1000 * 8) == size.GetBits());
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKiloBytes());
}

BOOST_AUTO_TEST_CASE(AddMebiBytesMethod)
{
	double d1 = 4 * 1024 * 1024;
	double	d2 = 4 * 1024;
	double d3 = 4;
	ByteSize size = ByteSize::FromMebiBytes(2).AddMebiBytes(2);

	BOOST_CHECK(int64_t(4 * 1024 * 1024 * 8) == size.GetBits());
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKibiBytes());
	BOOST_CHECK(d3 == size.GetMebiBytes());
}

BOOST_AUTO_TEST_CASE(AddMegaBytesMethod)
{
	double d1 = 4 * 1000 * 1000;
	double	d2 = 4 * 1000;
	double d3 = 4;
	ByteSize size = ByteSize::FromMegaBytes(2).AddMegaBytes(2);

	BOOST_CHECK(int64_t(4 * 1000 * 1000 * 8) == size.GetBits());
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKiloBytes());
	BOOST_CHECK(d3 == size.GetMegaBytes());
}

BOOST_AUTO_TEST_CASE(AddGibiBytesMethod)
{
	double d0 = 4.0 * 1024 * 1024 * 1024 * 8;
	double d1 = 4.0 * 1024 * 1024 * 1024;
	double d2 = 4.0 * 1024 * 1024;
	double d3 = 4.0 * 1024;
	double d4 = 4.0;
	ByteSize size = ByteSize::FromGibiBytes(2).AddGibiBytes(2);

	BOOST_CHECK(d0 == double(size.GetBits()));
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKibiBytes());
	BOOST_CHECK(d3 == size.GetMebiBytes());
	BOOST_CHECK(d4 == size.GetGibiBytes());
}

BOOST_AUTO_TEST_CASE(AddGigaBytesMethod)
{
	double d0 = 4.0 * 1000 * 1000 * 1000 * 8;
	double d1 = 4.0 * 1000 * 1000 * 1000;
	double d2 = 4.0 * 1000 * 1000;
	double d3 = 4.0 * 1000;
	double d4 = 4.0;
	ByteSize size = ByteSize::FromGigaBytes(2).AddGigaBytes(2);

	BOOST_CHECK(d0 == double(size.GetBits()));
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKiloBytes());
	BOOST_CHECK(d3 == size.GetMegaBytes());
	BOOST_CHECK(d4 == size.GetGigaBytes());
}

BOOST_AUTO_TEST_CASE(AddTebiBytesMethod)
{
	double d0 = 4.0 * 1024 * 1024 * 1024 * 1024 * 8;
	double d1 = 4.0 * 1024 * 1024 * 1024 * 1024;
	double d2 = 4.0 * 1024 * 1024 * 1024;
	double d3 = 4.0 * 1024 * 1024;
	double d4 = 4.0 * 1024;
	double d5 = 4.0;
	ByteSize size = ByteSize::FromTebiBytes(2).AddTebiBytes(2);

	BOOST_CHECK(d0 == double(size.GetBits()));
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKibiBytes());
	BOOST_CHECK(d3 == size.GetMebiBytes());
	BOOST_CHECK(d4 == size.GetGibiBytes());
	BOOST_CHECK(d5 == size.GetTebiBytes());
}

BOOST_AUTO_TEST_CASE(AddTeraBytesMethod)
{
	double d0 = 4.0 * 1000 * 1000 * 1000 * 1000 * 8;
	double d1 = 4.0 * 1000 * 1000 * 1000 * 1000;
	double d2 = 4.0 * 1000 * 1000 * 1000;
	double d3 = 4.0 * 1000 * 1000;
	double d4 = 4.0 * 1000;
	double d5 = 4.0;
	ByteSize size = ByteSize::FromTeraBytes(2).AddTeraBytes(2);

	BOOST_CHECK(d0 == double(size.GetBits()));
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKiloBytes());
	BOOST_CHECK(d3 == size.GetMegaBytes());
	BOOST_CHECK(d4 == size.GetGigaBytes());
	BOOST_CHECK(d5 == size.GetTeraBytes());
}

BOOST_AUTO_TEST_CASE(AddPebiBytesMethod)
{
	double d0 = 4.0 * 1024 * 1024 * 1024 * 1024 * 1024 * 8;
	double d1 = 4.0 * 1024 * 1024 * 1024 * 1024 * 1024;
	double d2 = 4.0 * 1024 * 1024 * 1024 * 1024;
	double d3 = 4.0 * 1024 * 1024 * 1024;
	double d4 = 4.0 * 1024 * 1024;
	double d5 = 4.0 * 1024;
	double d6 = 4.0;

	ByteSize size = ByteSize::FromPebiBytes(2).AddPebiBytes(2);

	BOOST_CHECK(d0 == double(size.GetBits()));
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKibiBytes());
	BOOST_CHECK(d3 == size.GetMebiBytes());
	BOOST_CHECK(d4 == size.GetGibiBytes());
	BOOST_CHECK(d5 == size.GetTebiBytes());
	BOOST_CHECK(d6 == size.GetPebiBytes());
}

BOOST_AUTO_TEST_CASE(AddPetaBytesMethod)
{
	double d0 = 4.0 * 1000 * 1000 * 1000 * 1000 * 1000 * 8;
	double d1 = 4.0 * 1000 * 1000 * 1000 * 1000 * 1000;
	double d2 = 4.0 * 1000 * 1000 * 1000 * 1000;
	double d3 = 4.0 * 1000 * 1000 * 1000;
	double d4 = 4.0 * 1000 * 1000;
	double d5 = 4.0 * 1000;
	double d6 = 4.0;

	ByteSize size = ByteSize::FromPetaBytes(2).AddPetaBytes(2);

	BOOST_CHECK(d0 == double(size.GetBits()));
	BOOST_CHECK(d1 == size.GetBytes());
	BOOST_CHECK(d2 == size.GetKiloBytes());
	BOOST_CHECK(d3 == size.GetMegaBytes());
	BOOST_CHECK(d4 == size.GetGigaBytes());
	BOOST_CHECK(d5 == size.GetTeraBytes());
	BOOST_CHECK(d6 == size.GetPetaBytes());
}

BOOST_AUTO_TEST_CASE(SubtractMethod)
{
	ByteSize size = ByteSize::FromBytes(4).Subtract(ByteSize::FromBytes(2));

	BOOST_CHECK(int64_t(16) == size.GetBits());
	BOOST_CHECK(double(2) == size.GetBytes());
}

BOOST_AUTO_TEST_CASE(MinusOperator)
{
	ByteSize size = ByteSize::FromBytes(2);
	size = -size;

	BOOST_CHECK(int64_t(-16) == size.GetBits());
	BOOST_CHECK(double(-2) == size.GetBytes());
}

BOOST_AUTO_TEST_SUITE_END()