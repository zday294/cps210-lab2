//mergesort
#include "ArrayIter.h"
#include "Compare.h"
#include <string>

template <class T>
class Mergesort {

public:
	static void print(char* caption, ArrayIter<T> begin, ArrayIter<T> end) {
		// Make copies of all iterators whose next method will be called
		Iter<T> pos = begin.copy();
		printf("%s: \n", caption);
		for (; !pos.isEqualTo(end); pos.next()) {
			printf(" %d", pos.get());
		}
		printf("\n");
	}


	static void swap(ArrayIter<T> a, ArrayIter<T> b) {
		T c = a.get();
		a.set(b.get());
		b.set(c);
	}

	static ArrayIter<T> append(ArrayIter<T> resultHold, ArrayIter<T> begin, ArrayIter<T> end) {
		ArrayIter<T> pos = begin.copy();
		ArrayIter<T> result = resultHold.copy();

		for (; !pos.isEqualTo(end); result.next(), pos.next()) {
			result.set(pos.get());
		}
		return result;
	}

	static void merge(ArrayIter<T> begin1, ArrayIter<T> end1, ArrayIter<T> begin2, ArrayIter<T> end2, ArrayIter<T> result, ArrayIter<T> beginHold, Compare<T> cmp)
	{
		// Make copies of all iterators whose next method will be called
		ArrayIter<T> pos = beginHold.copy();
		ArrayIter<T> iter1 = begin1.copy();
		ArrayIter<T> iter2 = begin2.copy();

		// Debugging information
		print("merging\n");
		print("list 1", iter1, end1);
		print("list 2", iter2, end2);

		while (!iter1.isEqualTo(end1) && !iter2.isEqualTo(end2))
		{
			if (cmp.precedes(iter2.get(), iter1.get()))
			{
				// the iter2's value is used next
				pos.set(iter2.get());
				pos.next();
				iter2.next();
			}
			else
			{
				// the iter1's value is used next
				pos.set(iter1.get());
				pos.next();
				iter1.next();
			}
		}

		pos = append(pos, iter1, end1);
		pos = append(pos, iter2, end2);
		ArrayIter<T> resultEnd = append(result, beginHold, pos); // used for debugging
		print("merged list", result, resultEnd);
	};

	static void sort(ArrayIter<T> begin, ArrayIter<T> end, ArrayIter<T> hold, Compare<T> cmp) {
		// Make copies of all iterators whose next method will be called
		ArrayIter<T> pos = begin.copy();
		ArrayIter<T> mid = begin.copy();

		print("Inside sort\n");

		int size;
		// count the items in the list and find the middle of the list
		for (size = 0; !pos.isEqualTo(end); pos.next(), ++size) {
			print(" %d", pos.get());
			if (0 == size % 2) { mid.next(); } // increment mid every other time
		}
		print("; Found middle; size=%d\n", size);

		if (size <= 2) {
			if (2 == size && cmp.precedes(mid.get(), begin.get())) {
				swap(begin, mid);
			}
			return;
		}

		sort(begin, mid, hold, cmp);
		sort(mid, end, hold, cmp);
		merge(begin, mid, mid, end, begin, hold, cmp);
	};
};
