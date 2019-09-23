//ArrayIter
#include <vector>


template <typename T>
class ArrayIter
{
private:
	std::vector<T> theList;
	int index;

public:
	ArrayIter<T>()
	{
		theList = std::vector<T>();
		index = 0;
	};

	ArrayIter<T>(std::vector<T> _theList)
	{
		theList = _theList;
		index = 0;
	}

	ArrayIter<T>(std::vector<T> _theList, int _index)
	{
		theList = _theList;
		index = _index;
	}

	void next() { ++index; }
	T get() { return theList[index]; }
	void set(T value) { theList[index] = value; }
	ArrayIter<T> copy() { return new ArrayIter<T>(this, index); }

	bool isEqualTo(ArrayIter<T> other)
	{
		type_info ofOther = typeid(other);
		if (std::is_base_of< ArrayIter<T>, ofOther >)
		{
			ArrayIter<T> _other = new ArrayIter<T>(other);
			//System.out.println("The indices are " + index + " and " + _other.index);
			return (theList == _other.theList && index == _other.index);
		}
		else { return false; }
	}
}