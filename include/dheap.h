#include "vector.h"
#include "pair.h"
class DHeap {
private:
	vector<pair<int,int>> v;
	size_t d;

	size_t FirstChild(size_t i) const;
	size_t LastChild(size_t i) const;
	size_t MinChild(size_t i);
	size_t Father(size_t i) const;
	void SiftDown(size_t i);
	void SiftUp(size_t i);

public:
	DHeap(size_t _d) : d(_d) {}
	bool isHeapPropertySatisfied() const;
	void Insert(int vertex, int weight);
	pair<int,int> ExtractMin();
	bool isEmpty() const { return v.IsEmpty(); }
	void Display() const;
};