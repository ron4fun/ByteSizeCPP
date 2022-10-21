#define BOOST_TEST_MODULE UNITTESTBYTESIZE

#include <boost/test/included/unit_test.hpp>
#include "../ByteSize.h"


BOOST_AUTO_TEST_SUITE(ParsingMethodsTest)

BOOST_AUTO_TEST_CASE(Parse)
{
	string val = "1020KB";
	ByteSize expected = ByteSize::FromKiloBytes(1020);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseDecimalMB)
{
	string val = "100.5MB";
	ByteSize expected = ByteSize::FromMegaBytes(100.5);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseThrowsExceptionOnBadValue)
{
	string val = "Unexpected Value";

	BOOST_CHECK_THROW(ByteSize::Parse(val), FormatException);
}

BOOST_AUTO_TEST_CASE(ParseThrowsExceptionOnMissingMagnitude)
{
	string val = "1000";

	BOOST_CHECK_THROW(ByteSize::Parse(val), FormatException);
}

BOOST_AUTO_TEST_CASE(ParseThrowsExceptionOnMissingValue)
{
	string val = "KB";

	BOOST_CHECK_THROW(ByteSize::Parse(val), FormatException);
}

BOOST_AUTO_TEST_CASE(ParseWorksWithLotsOfSpaces)
{
	string val = " 100 KB ";
	ByteSize expected = ByteSize::FromKiloBytes(100);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParsePartialBits)
{
	string val = "10.5b";

	BOOST_CHECK_THROW(ByteSize::Parse(val), FormatException);
}

BOOST_AUTO_TEST_CASE(ParseBits)
{
	string val = "1b";
	ByteSize expected = ByteSize::FromBits(1);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseBytes)
{
	string val = "1B";
	ByteSize expected = ByteSize::FromBytes(1);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseKiB)
{
	string val = "1020KiB";
	ByteSize expected = ByteSize::FromKibiBytes(1020);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseKB)
{
	string val = "1020KB";
	ByteSize expected = ByteSize::FromKiloBytes(1020);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseMiB)
{
	string val = "1000MiB";
	ByteSize expected = ByteSize::FromMebiBytes(1000);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseMB)
{
	string val = "1000MB";
	ByteSize expected = ByteSize::FromMegaBytes(1000);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseGiB)
{
	string val = "805GiB";
	ByteSize expected = ByteSize::FromGibiBytes(805);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseGB)
{
	string val = "805GB";
	ByteSize expected = ByteSize::FromGigaBytes(805);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseTiB)
{
	string val = "100TiB";
	ByteSize expected = ByteSize::FromTebiBytes(100);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParseTB)
{
	string val = "100TB";
	ByteSize expected = ByteSize::FromTeraBytes(100);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParsePiB)
{
	string val = "100PiB";
	ByteSize expected = ByteSize::FromPebiBytes(100);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_CASE(ParsePB)
{
	string val = "100PB";
	ByteSize expected = ByteSize::FromPetaBytes(100);
	ByteSize result = ByteSize::Parse(val);

	BOOST_CHECK(expected == result);
}

BOOST_AUTO_TEST_SUITE_END()