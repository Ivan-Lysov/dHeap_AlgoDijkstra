#include "pair.h"
#include <gtest.h>
#include <iostream>
#include <string>
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(pair, testMakePair) {
	pair<int, int> p;
	EXPECT_EQ(p.first, 0);
	EXPECT_EQ(p.second, 0);
}

TEST(pair, testGetFirstSecond) {
	pair<int, int> p(1, 2);
	EXPECT_EQ(p.first, 1);
	EXPECT_EQ(p.second, 2);
}

TEST(pair, testGetMinFirstSecond) {
	pair<int, int> p(1, 2);
	EXPECT_EQ(min(p.first, p.second), 1);
}

TEST(pair, testGetMaxFirstSecond) {
	pair<int, int> p(10, 5);
	EXPECT_EQ(max(p.first, p.second), 10);
}

TEST(pair, testEqualPair) {
	pair<int, int> p(1, 2);
	pair<int, int> p1(3, 4);
	p = p1;
	EXPECT_EQ(p.first, 3);
	EXPECT_EQ(p.second, 4);
}

TEST(pair, DefaultConstructor) {
	pair<int, double> p;
	EXPECT_EQ(p.first, 0);
	EXPECT_EQ(p.second, 0.0);
}

TEST(pair, ParameterizedConstructor) {
	pair<int, std::string> p(5, "str");
	EXPECT_EQ(p.first, 5);
	EXPECT_EQ(p.second, "str");
}

TEST(pair, DifferentDataTypes) {
	pair<char, float> p('A', 3.14f);
	EXPECT_EQ(p.first, 'A');
	EXPECT_FLOAT_EQ(p.second, 3.14f);
}

TEST(pair, CopyConstructor) {
	pair<int, int> p(1, 2);
	pair<int, int> p1(p);
	EXPECT_EQ(p1.first, 1);
	EXPECT_EQ(p1.second, 2);
}

TEST(PairTest, AssignmentOperator) {
	pair<int, int> p1(10, 20);
	pair<int, int> p2 = p1;
	EXPECT_EQ(p2.first, 10);
	EXPECT_EQ(p2.second, 20);

	pair<std::string, double> p3("test", 2.71);
	pair<std::string, double> p4;
	p4 = p3;
	EXPECT_EQ(p4.first, "test");
	EXPECT_EQ(p4.second, 2.71);
}

TEST(PairTest, MinMaxFunctions) {
	EXPECT_EQ(min(10, 20), 10);
	EXPECT_EQ(max(10, 20), 20);
	EXPECT_EQ(min(3.5, 2.1), 2.1);
	EXPECT_EQ(max(3.5, 2.1), 3.5);
}

TEST(PairTest, SwapFunction) {
	pair<int, int> p1(10, 20);
	pair<int, int> p2(30, 40);
	std::swap(p1, p2);
	EXPECT_EQ(p1.first, 30);
	EXPECT_EQ(p1.second, 40);
	EXPECT_EQ(p2.first, 10);
	EXPECT_EQ(p2.second, 20);
}