#include "vector.h"
#include "pair.h"
#include <gtest.h>

TEST(Vector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(vector<int> v(3));
}

TEST(Vector, cant_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(vector<int> v(-3));
}

TEST(Vector, can_create_copied_vector)
{
	vector<int> v(3);

	ASSERT_NO_THROW(vector<int> v1(v));
}

TEST(Vector, can_get_size)
{
	vector<int> v(3);

	EXPECT_EQ(3, v.size());
}

TEST(Vector, can_get_element)
{
	vector<int> v(3);

	ASSERT_NO_THROW(v[0]);
}

TEST(Vector, can_set_element)
{
	vector<int> v(3);

	ASSERT_NO_THROW(v[0] = 1);
}

TEST(Vector, can_assign_vector)
{
	vector<int> v(3);
	vector<int> v1(3);

	ASSERT_NO_THROW(v = v1);
}

TEST(Vector, can_push_back_element)
{
	vector<int> v(3);

	ASSERT_NO_THROW(v.push_back(1));
}

TEST(Vector, can_pop_back_element)
{
	vector<int> v(3);

	ASSERT_NO_THROW(v.pop_back());
}

TEST(Vector, can_get_back_element)
{
	vector<int> v(3);

	ASSERT_NO_THROW(v.back());
}

TEST(Vector, can_check_if_vector_is_empty)
{
	vector<int> v(3);

	ASSERT_NO_THROW(v.IsEmpty());
}

