/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, multi_letter_password_single_leading)
{
    Password my_password;
	int actual = my_password.count_leading_characters("abc");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, upper_and_lower_case_test)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Bbc");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, double_letter_test_with_trailing_caracter)
{
    Password my_password;
	int actual = my_password.count_leading_characters("kkck");
	ASSERT_EQ(2,actual);
}

TEST(PasswordTest, single_start_double_letter_trailing)
{
    Password my_password;
	int actual = my_password.count_leading_characters("tcktt");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, triple_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("ggg");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, leading_spaces_followed_by_single_char)
{
    Password my_password;
	int actual = my_password.count_leading_characters("    abc");
	ASSERT_EQ(4,actual);
}

TEST(PasswordTest, empty_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, null_terminator)
{
    Password my_password;
	int actual = my_password.count_leading_characters("\0");
	ASSERT_EQ(0,actual);
}