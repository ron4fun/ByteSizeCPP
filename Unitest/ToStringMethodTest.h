#define BOOST_TEST_MODULE UNITTESTBYTESIZE

#include <boost/test/included/unit_test.hpp>
#include "../ByteSize.h"


string formatNumber(const double number, const uint32_t decimal_place)
{
	ostringstream ss;
	ss.setf(ios::fixed, ios::floatfield);
	ss.precision(decimal_place);

	ss << number;
	return ss.str();
}

BOOST_AUTO_TEST_SUITE(ToStringMethodTest)

BOOST_AUTO_TEST_CASE(ReturnsLargestMetricSuffix)
{
	double lDouble = 10.5;

	// Arrange
	ByteSize b = ByteSize::FromKiloBytes(10.5);

	// Act
	string result = b.ToString();

	// Assert
	BOOST_CHECK(formatNumber(lDouble, 2) + " KB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsDefaultNumberFormat)
{
	double lDouble = 10.5;
		
	// Arrange
	ByteSize b = ByteSize::FromKiloBytes(10.5);

	// Act
	string result = b.ToString("KB");

	// Assert
	BOOST_CHECK(formatNumber(lDouble, 2) + " KB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsProvidedNumberFormat)
{
	double lDouble = 10.1234;
	
	// Arrange
	ByteSize b = ByteSize::FromKiloBytes(10.1234);

	// Act
	string result = b.ToString("%.4f KB");

	// Assert
	BOOST_CHECK(formatNumber(lDouble, 4) + " KB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsBits)
{
	// Arrange
	ByteSize b = ByteSize::FromBits(10);

	// Act
	string result = b.ToString("%d b");

	// Assert
	BOOST_CHECK("10 b" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromBytes(10);

	// Act
	string result = b.ToString("%d B");

	// Assert
	BOOST_CHECK("10 B" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsKiloBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromKiloBytes(10);

	// Act
	string result = b.ToString("%d KB");

	// Assert
	BOOST_CHECK("10 KB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsMegaBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromMegaBytes(10);

	// Act
	string result = b.ToString("%d MB");

	// Assert
	BOOST_CHECK("10 MB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsGigaBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromGigaBytes(10);

	// Act
	string result = b.ToString("%d GB");

	// Assert
	BOOST_CHECK("10 GB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsTeraBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromTeraBytes(10);

	// Act
	string result = b.ToString("%d TB");

	// Assert
	BOOST_CHECK("10 TB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsPetaBytes)
{
	// Arrange
	ByteSize b = ByteSize::FromPetaBytes(10);

	// Act
	string result = b.ToString("%d PB");

	// Assert
	BOOST_CHECK("10 PB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsSelectedFormat)
{
	double lDouble = 10;
		
	// Arrange
	ByteSize b = ByteSize::FromTeraBytes(10);

	// Act
	string result = b.ToString("%d TB");

	// Assert
	BOOST_CHECK(formatNumber(lDouble, 0) + " TB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsLargestMetricPrefixLargerThanZero)
{
	// Arrange
	ByteSize b = ByteSize::FromMegaBytes(0.5);

	// Act
	string result = b.ToString("%d KB");

	// Assert
	BOOST_CHECK("512 KB" == result);
}

BOOST_AUTO_TEST_CASE(ReturnsLargestMetricPrefixLargerThanZeroForNegativeValues)
{
	// Arrange
	ByteSize b = ByteSize::FromMegaBytes(-0.5);

	// Act
	string result = b.ToString("%d KB");

	// Assert
	BOOST_CHECK("-512 KB" == result);
}

BOOST_AUTO_TEST_CASE(ToStringThrowsExceptionOnWrongOutputFormat)
{
	// Arrange
	ByteSize b(10000);

	BOOST_CHECK_THROW(b.ToString("%ddsjds mb"), FormatException);
}

BOOST_AUTO_TEST_SUITE_END()