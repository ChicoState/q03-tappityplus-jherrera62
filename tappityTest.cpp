/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};
TEST(tappitytest, equal_length_difference)
{
	tappity mypractice("caracoles");
	mypractice.entry("caracoles");
	int dif = mypractice.length_difference();
    ASSERT_EQ(dif,0);
}
TEST(tappitytest, shorter_input_length_difference)
{
	tappity mypractice("abcdefghij");
	mypractice.entry("a");
	int dif = mypractice.length_difference();
    ASSERT_EQ(dif,9);
}
TEST(tappitytest, longer_input_length_difference)
{
	tappity mypractice("abcdefghij");
	mypractice.entry("abcdefghijklmnop");
	int dif = mypractice.length_difference();
    ASSERT_EQ(dif,6);
}
TEST(tappitytest, empty_input_length_difference)
{
	tappity mypractice("abcdefghij");
	mypractice.entry("");
	int dif = mypractice.length_difference();
    ASSERT_EQ(dif,10);
}
TEST(tappitytest, empty_reference_length_difference)
{
	tappity mypractice("");
	mypractice.entry("abcdefghij");
	int dif = mypractice.length_difference();
    ASSERT_EQ(dif,10);
}
TEST(tappitytest, perfect_score_accuracy)
{
	tappity mypractice("abcdefghij");
	mypractice.entry("abcdefghij");
	int acc = mypractice.accuracy();
    ASSERT_EQ(acc,100);
}
TEST(tappitytest, half_score_accuracy)
{
	tappity mypractice("abcdefghij");
	mypractice.entry("abcdexxxxx");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,50);
}
TEST(tappitytest, half_input_zero_score_accuracy)
{
	tappity mypractice("abcdefghij");
	mypractice.entry("xxxxx");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,0);
}
TEST(tappitytest, half_input_half_score_accuracy)
{
	tappity mypractice("abcdefghij");
	mypractice.entry("abcde");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,50);
}
TEST(tappitytest, empty_input_score_accuracy)
{
	tappity mypractice("abcdefghij");
	mypractice.entry("");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,0);
}
TEST(tappitytest, empty_reference_empty_input_score_accuracy)
{
	tappity mypractice("");
	mypractice.entry("");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,100);
}
TEST(tappitytest, empty_reference_score_accuracy)
{
	tappity mypractice("");
	mypractice.entry("abcdefghij");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,0);
}
TEST(tappitytest, space_score_accuracy)
{
	tappity mypractice(" ");
	mypractice.entry(" ");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,100);
}
TEST(tappitytest, multiple_space_score_accuracy)
{
	tappity mypractice("    ");
	mypractice.entry("    ");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,100);
}
TEST(tappitytest, half_input_space_score_accuracy)
{
	tappity mypractice("    ");
	mypractice.entry("  ");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,50);
}
TEST(tappitytest, half_input_half_space_score_accuracy)
{
	tappity mypractice("    ");
	mypractice.entry("xx  ");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,50);
}
TEST(tappitytest, newline_score_accuracy)
{
	tappity mypractice("\n");
	mypractice.entry("\n");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,100);
}
TEST(tappitytest, newline_reference_score_accuracy)
{
	tappity mypractice("\n");
	mypractice.entry("x");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,0);
}
TEST(tappitytest, second_half_of_input_matches_reference_score_accuracy)
{
	tappity mypractice("yyxx");
	mypractice.entry("xxxx");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,50);
}
TEST(tappitytest, second_half_of_input_matches_reference_plus_newline_score_accuracy)
{
	tappity mypractice("yyxx\n");
	mypractice.entry("xxxx\n");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,60);
}
TEST(tappitytest, newline_reference_x_plus_newline_input_score_accuracy)
{
	tappity mypractice("\n");
	mypractice.entry("x\n");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,0);
}
TEST(tappitytest, newline_reference_newline_plus_x_input_score_accuracy)
{
	tappity mypractice("\n");
	mypractice.entry("\nx");
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,50);
}
TEST(tappitytest, one_character_reference_matching_character_plus_more_input_score_accuracy)
{
	tappity mypractice("x");
	mypractice.entry("xy");
	mypractice.length_difference();
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,50);
}
TEST(tappitytest, one_character_input_matching_character_plus_more_reference_score_accuracy)
{
	tappity mypractice("xy");
	mypractice.entry("x");
	mypractice.length_difference();
	double acc = mypractice.accuracy();
    ASSERT_EQ(acc,50);
}
