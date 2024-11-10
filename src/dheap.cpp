#include "dheap.h"
#include <iostream>
#include <vector>
#include <algorithm>

size_t DHeap::FirstChild(size_t i) const {
	size_t k = d * i + 1;
	if (k < v.size())
		return k;
	else
		return -1;
}

size_t DHeap::LastChild(size_t i) const {
	size_t first = FirstChild(i);
	return (first < v.size()) ? min(first + d - 1, v.size() - 1) : v.size();
}


size_t DHeap::MinChild(size_t i) {
	size_t first = FirstChild(i);
	if (first == -1)
		return i;
	size_t last = LastChild(i);
	size_t min = first;
	for (size_t j = first + 1; j <= last; ++j)
		if (v[j].second < v[min].second)
			min = j;
	return min;
}

size_t DHeap::Father(size_t i) const {
	if (i == 0)
		return -1;
	else
		return (i - 1) / d;
}

void DHeap::SiftDown(size_t i) {
	int key0 = v[i].first;
	int value0 = v[i].second;
	size_t c = MinChild(i);

	while (c != i && value0 > v[c].second) {
		v[i] = v[c];
		i = c;
		c = MinChild(i);
	}
	v[i] = { key0, value0 };
}

void DHeap::SiftUp(size_t i) {
	int key0 = v[i].first;
	int value0 = v[i].second;
	size_t local_father = Father(i);

	while (local_father != -1 && value0 < v[local_father].second) {
		v[i] = v[local_father];
		i = local_father;
		local_father = Father(i);
	}
	v[i] = { key0, value0 };
}

void DHeap::Insert(int key, int value) {
	v.push_back({ key, value });
	SiftUp(v.size() - 1);
}

pair<int, int> DHeap::ExtractMin() {
	if (v.size() == 0) {
		throw "In the heam not elements";
	}
	pair<int, int> min = v[0];
	v[0] = v[v.size() - 1];
	v.pop_back();
	if (!v.IsEmpty()) {
		SiftDown(0);
	}
	return min;
}

void DHeap::Display() const {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i].first << " " << v[i].second << std::endl;
	}
}

bool DHeap::isHeapPropertySatisfied() const {
	for (size_t i = 0; i < v.size(); ++i) {
		size_t first = FirstChild(i);
		if (first == -1)
			break;
		size_t last = LastChild(i);
		for (size_t j = first; j <= last; ++j) {
			if (v[i].second > v[j].second)
				return false;
		}
	}
	return true;
}

