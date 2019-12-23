#include "pch.h"
#include "../Proga8/calculator.h"
#include <functional>

// just for short records
auto Polish = bind(Calc::ConvertPolishStackIntoString,bind(Calc::ConvertingStringToPolishStack , std::placeholders::_1));
auto ResOf = bind(Calc::GetResult, bind(Calc::ConvertingStringToPolishStack, std::placeholders::_1));

TEST(TestingMyStack, StackMethods) {
    Stack<int> st;
    st << 1;
    st << 2;
    st << 3;
    st << 4;
    EXPECT_EQ(st.size(), 4);
    EXPECT_EQ(st.top(), 4);
    EXPECT_EQ(st[1], 2);
    EXPECT_EQ(st[2], 3);
    EXPECT_EQ(st[3], 4);
    Stack<int> expect_st1 = { 1, 2, 3, 4 };
    Stack<int> comp_st1 = { 1 ,2, 3, 4, 5 }, comp_st2 = { 1 ,2 };
    EXPECT_TRUE(st == expect_st1);
    EXPECT_TRUE(st < comp_st1);
    EXPECT_FALSE(st < comp_st2);
    int tmp;
    st >> tmp;
    st >> tmp;
    EXPECT_EQ(st.size(), 2);
    EXPECT_EQ(st.top(), 2);
    Stack<int> expect_st2 = { 1, 2 };
    EXPECT_TRUE(st == expect_st2);
    st >> tmp;
    st >> tmp;
    EXPECT_TRUE(st.empty());
}

TEST(TestingPriors, Prior2) {
    EXPECT_EQ(Calc::Prior('*'), 2);
    EXPECT_EQ(Calc::Prior('/'), 2);
}
TEST(TestingPriors, Prior1) {
    EXPECT_EQ(Calc::Prior('+'), 1);
    EXPECT_EQ(Calc::Prior('-'), 1);
}
TEST(TestingPriors, Prior0) {
    EXPECT_EQ(Calc::Prior('('), 0);
    EXPECT_EQ(Calc::Prior(')'), 0);
}

TEST(TestingIncorrectExpressions, IncorrectBrackets) {
    EXPECT_THROW(ResOf("1+2)"), std::exception);
    EXPECT_THROW(ResOf("1+2("), std::exception);
    EXPECT_THROW(ResOf("(1+2"), std::exception);
    EXPECT_THROW(ResOf(")1+2"), std::exception);
    EXPECT_THROW(ResOf(")1+(2"), std::exception);
    EXPECT_THROW(ResOf("1+(2"), std::exception);
}

TEST(TestingIncorrectExpressions, TwoOrMoreNumbersInARow) {
    EXPECT_THROW(ResOf("1 2"), std::exception);
    EXPECT_THROW(ResOf("1 2 +"), std::exception);
    EXPECT_THROW(ResOf("-2 1 2 "), std::exception);
}

TEST(TestingIncorrectExpressions, IncorrectOperations) {
    EXPECT_THROW(ResOf("*1+2"), std::exception);
    EXPECT_THROW(ResOf("1+2*5/"), std::exception);
    EXPECT_THROW(ResOf("1/+2"), std::exception);
}

TEST(TestingCorrectExpressions, TestSum) {
    EXPECT_EQ(ResOf("1"), 1);
    EXPECT_EQ(ResOf("1+2"), 3);
    EXPECT_EQ(ResOf("-1+1 *2"), 1);
    EXPECT_EQ(ResOf("(-1+2)*(2-1)"), 1);
    EXPECT_EQ(ResOf("-1 *(-5) + 2* (-2 + 4 * 7 -  8 / 5 * 10 -4) *8"), 101);
    EXPECT_FLOAT_EQ(ResOf(" ( 84  / 2 * 8 - 2)/ (4 - 3 * (-2) / 3 ) "), 55.666667);
    EXPECT_FLOAT_EQ(ResOf(" 5 + (-1 / 10 +3 ) - 2 * 2*(-3) "), 19.9);
} 

TEST(TestingCorrectExpressions, PolishTranscription) {
    EXPECT_TRUE(Polish("1+2") == "1 2 + ");
    EXPECT_TRUE(Polish("(1+2)/ (3-4)") == "1 2 + 3 4 - / ");
    EXPECT_TRUE(Polish("1 + 2 * 3") == "1 2 3 * + ");
    EXPECT_TRUE(Polish("-1 *(-5) + 2* (-2 + 4 * 7 -  8 / 5 * 10 -4) *8") == "-1 -5 * 2 -2 4 7 * + 8 5 / 10 * - 4 - * 8 * + ");
}
