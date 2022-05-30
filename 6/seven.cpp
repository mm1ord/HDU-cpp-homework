#include <iostream>
using namespace std;

template <typename T>
class DVector
{
public:
	DVector()
	{
		Size = 1000
		for (int i = 0; i < Size; ++i)
			arrays[i] = 0;
	}
	DVector(int a) :size(a)
	{
		for (int i = 0; i < Size; ++i)
			arrays[i] = 0;
	}
	DVector(int a, T temp[])
	{
		Size = a;
		for (int i = 0; i < Size; ++i)
		{
			arrays[i] = temp[i];
		}
	}
	inline DVector<T> operator + (const DVector<T> rhs);
	inline int& operator * (const DVector<T> rhs);
	friend ostream& operator << <> (ostream& out, const DVector<T>& rhs);
private:
	T arrays[1000];
	int Size;
};

template <typename T>
DVector<T> DVector<T>::operator + (const DVector<T> rhs)
{
	DVector<T> result(Size);
	for (int i = Size - 1; i >= 0; --i)
		result.arrays[i] = arrays[i] + rhs.arrays[i];
	return result;
}
template <typename T>
int& DVector<T>::operator * (const DVector<T> rhs)
{
	int sum = 0;
	for (int i = 0; i < Size; ++i)
	{
		int temp = rhs.arrays[i] * arrays[i];
		sum += temp;
	}
	return sum;
}
template <typename T>
ostream& operator << <> (ostream& out, const DVector<T>& rhs)
{
	cout << "(";
	cout << rhs.arrays[0];
	for (int i = 1; i < rhs.Size; ++i)
	{
		cout << "," << rhs.arrays[i];
	}
	cout << ")";
	return out;
}

int main()
{
	int a[6] = { 1,2,3,4,5,6 };
	int b[6] = { 3,4,5,6,7,8 };
	DVector<int> vecA(6, a), vecB(6, b), vecC(6);
	vecC = vecA + vecB;
	cout << vecA << '+' << vecB << '=' << vecC << endl;
	int iResult = vecA * vecB;
	cout << vecA << '*' << vecB << '=' << iResult << endl;
}