#include "dheap.h"
#include <gtest.h>

TEST(dHeap, can_create_dheap)
{
	ASSERT_NO_THROW(DHeap dheap(3));
}

TEST(dHeap, can_insert_element)
{
	DHeap dheap(3);
	ASSERT_NO_THROW(dheap.Insert(1, 2));
}

TEST(dHeap, can_extract_min_element)
{
	DHeap dheap(3);
	dheap.Insert(1, 2);
	ASSERT_NO_THROW(dheap.ExtractMin());
}

TEST(dHeap, can_check_heap_property)
{
	DHeap dheap(3);
	dheap.Insert(1, 2);
	EXPECT_EQ(dheap.isHeapPropertySatisfied(), true);
}

TEST(DHeapTest, InsertMultipleElements) {
	DHeap heap(2);  // Binary heap
	heap.Insert(100, 100);
	heap.Insert(50, 50);
	heap.Insert(200, 200);
	heap.Insert(10, 10);

	EXPECT_TRUE(heap.isHeapPropertySatisfied());
	EXPECT_EQ(heap.ExtractMin().second, 10);
	EXPECT_EQ(heap.ExtractMin().second, 50);
}

TEST(DHeapTest, InsertMultipleElements2) {
	DHeap heap(3);  // Ternary heap
	heap.Insert(100, 100);
	heap.Insert(50, 50);
	heap.Insert(200, 200);
	heap.Insert(10, 10);

	EXPECT_TRUE(heap.isHeapPropertySatisfied());
	EXPECT_EQ(heap.ExtractMin().second, 10);
	EXPECT_EQ(heap.ExtractMin().second, 50);
}

TEST(DHeapTest, InsertAndHeapPropertyFor15Heap) {
	DHeap heap(15);
	heap.Insert(100, 100);
	heap.Insert(50, 50);
	heap.Insert(200, 200);
	heap.Insert(10, 10);
	heap.Insert(5, 5);
	heap.Insert(300, 300);
	EXPECT_TRUE(heap.isHeapPropertySatisfied());
	EXPECT_EQ(heap.ExtractMin().second, 5);
	EXPECT_EQ(heap.ExtractMin().second, 10);
	EXPECT_TRUE(heap.isHeapPropertySatisfied());
}

TEST(DHeapTest, ExtractMinFor15Heap) {
	DHeap heap(15);

	heap.Insert(100, 100);
	heap.Insert(50, 50);
	heap.Insert(200, 200);
	heap.Insert(10, 10);
	heap.Insert(5, 5);
	heap.Insert(300, 300);
	heap.Insert(15, 15);
	heap.Insert(30, 30);
	EXPECT_EQ(heap.ExtractMin().second, 5);
	EXPECT_EQ(heap.ExtractMin().second, 10);
	EXPECT_EQ(heap.ExtractMin().second, 15);
	EXPECT_EQ(heap.ExtractMin().second, 30);
	EXPECT_EQ(heap.ExtractMin().second, 50);
	EXPECT_EQ(heap.ExtractMin().second, 100);
}

TEST(DHeapTest, ExtractMinFromEmpty15Heap) {
	DHeap heap(15);
	EXPECT_THROW(heap.ExtractMin(), const char*);
}

TEST(DHeapTest, InsertAndExtractMultipleElements) {
	DHeap heap(15);
	heap.Insert(50, 50);
	heap.Insert(30, 30);
	heap.Insert(100, 100);
	heap.Insert(10, 10);
	heap.Insert(5, 5);
	heap.Insert(300, 300);
	heap.Insert(200, 200);
	heap.Insert(20, 20);
	EXPECT_TRUE(heap.isHeapPropertySatisfied());
	EXPECT_EQ(heap.ExtractMin().second, 5);
	EXPECT_EQ(heap.ExtractMin().second, 10);
	EXPECT_EQ(heap.ExtractMin().second, 20);
	EXPECT_EQ(heap.ExtractMin().second, 30);
	EXPECT_EQ(heap.ExtractMin().second, 50);
	EXPECT_EQ(heap.ExtractMin().second, 100);
	EXPECT_EQ(heap.ExtractMin().second, 200);
	EXPECT_EQ(heap.ExtractMin().second, 300);
	EXPECT_THROW(heap.ExtractMin(), const char*);
}
