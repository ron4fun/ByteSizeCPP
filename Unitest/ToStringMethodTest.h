#define BOOST_TEST_MODULE UNITTESTBYTESIZE

#include <boost/test/included/unit_test.hpp>
#include "../ByteSize.h"
#include <iomanip>

// Exactly thesame function used by ByteSize objects internally to
// resolve decimal precision error that may occur.
string ResolveOutput(const double n, const string &unit, const int decimal_place = 2)
{
	ostringstream ss;
	ss.setf(ios::fixed, ios::floatfield);
	ss.precision(decimal_place);
	ss << n;
	ss << " " << unit;
	return ss.str();
}

BOOST_AUTO_TEST_SUITE(ToStringMethodTest)

BOOST_AUTO_TEST_CASE(ReturnsLargestMetricSuffix)
{
	double lDouble = 10.5;

	// Arrange
	ByteSize b = ByteSize::FromKibiBytes(10.5);

	// Act
	string result = b.ToString();

	// Assert
	BOOST_CHECK(ResolveOutput(lDouble, "KiB") == result);
}

BOOST_AUTO_TEST_CASE(ReturnsDefaultNumberFormat)
{
	double lDouble = 10.5;
		
	// Arrange
	ByteSize b = ByteSize::FromKibiBytes(10.5);

	// Act
	string result = b.ToString("KiB");

	// Assert
	BOOST_CHECK(ResolveOutput(lDouble, "KiB") == result);
}

BOOST_AUTO_TEST_CASE(ReturnsProvidedNumberFormat)
{
	double lDouble = 10.1234;
	
	// Arrange
	ByteSize b = ByteSize::FromKibiBytes(10.1234);

	// Act
	string result = b.ToString("KiB", 4);

	// Assert
	BOOST_CHECK(ResolveOutput(lDouble, "KiB", 4) == result);
}

BOOST_AUTO_TEST_CASE(ReturnsBits)
{
	// Arrange
	ByteSize b = ByteSize::FromBits(10);

	// Act
	string result = b.ToString("b", 0);

	// Assert
	BOOST_CHECK("10 b" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromBytes(10);

	// Act
	string result = b.ToString("B", 0);

	// Assert
	BOOST_CHECK("10 B" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsKibiBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromKibiBytes(10);

	// Act
	string result = b.ToString("KiB", 0);

	// Assert
	BOOST_CHECK("10 KiB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsKiloBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromKiloBytes(10);

	// Act
	string result = b.ToString("KB", 0);

	// Assert
	BOOST_CHECK("10 KB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsMebiBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromMebiBytes(10);

	// Act
	string result = b.ToString("MiB", 0);

	// Assert
	BOOST_CHECK("10 MiB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsMegaBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromMegaBytes(10);

	// Act
	string result = b.ToString("MB", 0);

	// Assert
	BOOST_CHECK("10 MB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsGibiBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromGibiBytes(10);

	// Act
	string result = b.ToString("GiB", 0);

	// Assert
	BOOST_CHECK("10 GiB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsGigaBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromGigaBytes(10);

	// Act
	string result = b.ToString("GB", 0);

	// Assert
	BOOST_CHECK("10 GB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsTebiBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromTebiBytes(10);

	// Act
	string result = b.ToString("TiB", 0);

	// Assert
	BOOST_CHECK("10 TiB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsTeraBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromTeraBytes(10);

	// Act
	string result = b.ToString("TB", 0);

	// Assert
	BOOST_CHECK("10 TB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsPebiBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromPebiBytes(10);

	// Act
	string result = b.ToString("PiB", 0);

	// Assert
	BOOST_CHECK("10 PiB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsPetaBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromPetaBytes(10);

	// Act
	string result = b.ToString("PB", 0);

	// Assert
	BOOST_CHECK("10 PB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsSelectedFormat)
{
	double lDouble = 10;
		
	// Arrange
	ByteSize b = ByteSize::FromTeraBytes(10);

	// Act
	string result = b.ToString("TB", 0);

	// Assert
	BOOST_CHECK(ResolveOutput(lDouble, "TB", 0) == result);
}

BOOST_AUTO_TEST_CASE(ReturnsLargestMetricPrefixLargerThanZero)
{
	// Arrange
	ByteSize b = ByteSize::FromMebiBytes(0.5);

	// Act
	string result = b.ToString("KiB", 0);

	// Assert
	BOOST_CHECK("512 KiB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsLargestMetricPrefixLargerThanZeroForNegativeValues)
{
	// Arrange
	ByteSize b = ByteSize::FromMebiBytes(-0.5);

	// Act
	string result = b.ToString("KiB", 0);

	// Assert
	BOOST_CHECK("-512 KiB" == result);
}

BOOST_AUTO_TEST_CASE(ToStringThrowsExceptionOnWrongOutputFormat)
{
	// Arrange
	ByteSize b(10000);

	BOOST_CHECK_THROW(b.ToString("sjds mb"), FormatException);
}

BOOST_AUTO_TEST_CASE(ToStringThrowsExceptionOnNegitivePlaceNumber)
{
	// Arrange
	ByteSize b(1024);

	BOOST_CHECK_THROW(b.ToString("KB", -1), FormatException);
}

BOOST_AUTO_TEST_SUITE_END()