template <typename T>
class Compare
{
public:
	virtual bool precedes(T a, T b) 
	{
		if (a < b) 
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
};