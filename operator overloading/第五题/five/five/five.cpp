#include<bits/stdc++.h>
using namespace std;

class BigInteger {
public:
	BigInteger(long long num = 0);
	BigInteger(const std::string& numStr);
	BigInteger operator + (const BigInteger& rhs) const;
	BigInteger operator - (const BigInteger& rhs) const;
	BigInteger operator * (const BigInteger& rhs) const;
	BigInteger operator / (const BigInteger& rhs) const;
	BigInteger operator % (const BigInteger& rhs) const;
	bool operator > (const BigInteger& rhs) const;
	bool operator < (const BigInteger& rhs) const;
	bool operator >= (const BigInteger& rhs) const;
	bool operator <= (const BigInteger& rhs) const;
	bool operator != (const BigInteger& rhs) const;
	bool operator == (const BigInteger& rhs) const;
private:
	// 该函数假设 lhs >= rhs    
	static BigInteger sub(const BigInteger& lhs, const BigInteger& rhs);

	// 利用长除法进行除法运算    
	static BigInteger divide(BigInteger& lhs, const BigInteger& rhs);

	// 去掉最高位的0    
	static void removeHighestZero(BigInteger& num);

	// 格式化各数位，使其符合进制    
	static void formatBits(BigInteger& num);
private:
	//采用BASE进制记录任意大小的非负整数
	// BASE为10的指数，因乘法运算具体实现的限制，BASE的值不要超过10^4  
	static const int BASE = 10000;
	static const int WIDTH = 4;
	//BASE进制各位数，从低位到高位对应数组从左到右
	std::vector<int> m_bits;

	friend std::ostream& operator<<(ostream& out, const BigInteger& num);
	friend std::istream& operator>>(istream& in, BigInteger& num);
};

BigInteger::BigInteger(long long num)
{
	*this = num;
}
BigInteger::BigInteger(const string& numStr)
{
	*this = numStr;
}
BigInteger BigInteger::operator + (const BigInteger& rhs) const
{
	BigInteger result;
	result.m_bits.clear();

	for (int i = 0, carry = 0; ; i++)
	{
		if (i >= m_bits.size() && i >= rhs.m_bits.size() && carry == 0)
			break;
		int num = carry;
		if (i < m_bits.size())
			num += m_bits[i];
		if (i < rhs.m_bits.size())
			num += rhs.m_bits[i];
		result.m_bits.push_back(num % BASE);
		carry = num / BASE;
	}
	return result;
}
BigInteger BigInteger::operator - (const BigInteger& rhs) const
{
	// lhs > rhs， 则结果为 lhs - rhs；否则结果为 rhs - lhs    
	if (*this > rhs)
		return sub(*this, rhs);
	else
		return sub(rhs, *this);
}
// 乘法运算
BigInteger BigInteger::operator * (const BigInteger& rhs) const
{
	BigInteger result;
	result.m_bits.clear();
	result.m_bits.resize(m_bits.size() + rhs.m_bits.size(), 0);

	for (size_t i = 0; i < m_bits.size(); i++)
	{
		for (size_t j = 0; j < rhs.m_bits.size(); j++)
		{
			// 由于int的精度限制，两者的乘积不能溢出，所以BASE的值不要超过10^4            
			int num = m_bits[i] * rhs.m_bits[j];
			result.m_bits[i + j] += num;
		}
	}

	formatBits(result);
	removeHighestZero(result);
	return result;
}
BigInteger BigInteger::operator / (const BigInteger& rhs) const
{
	if (rhs == 0)
		throw "Divisor cannot be 0!";

	BigInteger temp = *this;
	return divide(temp, rhs);
}
BigInteger BigInteger::operator % (const BigInteger& rhs) const
{
	if (rhs == 0)
		throw "Divisor cannot be 0!";

	BigInteger result = *this;
	divide(result, rhs);
	return result;
}
bool BigInteger::operator > (const BigInteger& rhs) const
{
	// 如果数位不相等    
	if (m_bits.size() != rhs.m_bits.size())
		return m_bits.size() > rhs.m_bits.size();

	// 数位相等则逐位进行比较    
	for (int i = m_bits.size() - 1; i >= 0; i--)
	{
		if (m_bits[i] != rhs.m_bits[i])
			return m_bits[i] > rhs.m_bits[i];
	}

	return false;
}
bool BigInteger::operator >= (const BigInteger& rhs) const
{
	return (*this > rhs || *this == rhs);
}

bool BigInteger::operator < (const BigInteger& rhs) const
{
	return !(*this >= rhs);
}

bool BigInteger::operator <= (const BigInteger& rhs) const
{
	return !(*this > rhs);
}

bool BigInteger::operator == (const BigInteger& rhs) const
{
	return m_bits == rhs.m_bits;
}

bool BigInteger::operator != (const BigInteger& rhs) const
{
	return m_bits != rhs.m_bits;
}
// 该函数假设 lhs >= rhsBigInteger
BigInteger BigInteger::sub(const BigInteger& lhs, const BigInteger& rhs)
{
	BigInteger result;
	result.m_bits.clear();

	for (int i = 0, carry = 0; ; i++)
	{
		if (i >= lhs.m_bits.size() && i >= rhs.m_bits.size() && carry == 0)
			break;
		int num = carry;
		if (i < lhs.m_bits.size())
			num += lhs.m_bits[i];
		if (i < rhs.m_bits.size())
			num -= rhs.m_bits[i];
		num += BASE;
		result.m_bits.push_back(num % BASE);
		carry = num / BASE - 1;
	}

	removeHighestZero(result);
	return result;
}

// 进行除法运算，同时求得余数
BigInteger BigInteger::divide(BigInteger& lhs, const BigInteger& rhs)
{
	if (lhs < rhs)
		return 0;

	BigInteger result;
	// 商的最大位数    
	int maxSize = lhs.m_bits.size() - rhs.m_bits.size();

	// 从最高位到最低位逐位求商的各位数值    
	BigInteger multiple, product;
	while (lhs >= rhs)
	{
		multiple.m_bits.clear();
		multiple.m_bits.resize(maxSize + 1, 0);
		multiple.m_bits[maxSize] = 1;
		product = rhs * multiple;

		while (lhs >= product)
		{
			lhs = lhs - product;
			result = result + multiple;
		}
		maxSize--;
	}
	return result;
}

// 去掉最高位的0
void BigInteger::removeHighestZero(BigInteger& num)
{
	while (num.m_bits.size() > 1 && num.m_bits.back() == 0)
		num.m_bits.pop_back();
}

// 格式化各数位，使其符合进制
void BigInteger::formatBits(BigInteger& num)
{
	int carry = 0;
	for (size_t i = 0; i < num.m_bits.size(); i++)
	{
		int temp = num.m_bits[i] + carry;
		num.m_bits[i] = temp % BASE;
		carry = temp / BASE;
	}

	while (carry != 0)
	{
		num.m_bits.push_back(carry % BASE);
		carry /= BASE;
	}
}

ostream& operator << (ostream& out, const BigInteger& num)
{
	static string format = "%0" + to_string(BigInteger::WIDTH) + "d";
	out << num.m_bits.back();
	for (int i = num.m_bits.size() - 2; i >= 0; i--)
	{
		char buf[20];
		sprintf(buf, format.c_str(), num.m_bits[i]);
		out << buf;
	}
	return out;
}

istream& operator >> (istream& in, BigInteger& num)
{
	string str;
	if (!(in >> str))
		return in;
	num = str;
	return in;
}



int main()
{
	BigInteger num1, num2;
	char instruction;
	while (1)
	{
		cout << "Enter q to exit and other to start" << endl;
		cin >> instruction;
		if (instruction == 'q')
			break;
		cout << "please input num1:" << endl;
		cin >> num1;
		cout << "please input num2:" << endl;
		cin >> num2;
		cout << "the result of (num1 + num2) is:" << endl;
		cout << num1 + num2 << endl;
		cout << "the result of (num1 - num2):" << endl;
		cout << num1 - num2 << endl;
		cout << "the result of (num1 * num2):" << endl;
		cout << num1 * num2 << endl;
		cout << "the result of (num1 / num2):" << endl;
		cout << num1 / num2 << endl;
		cout << "the result of (num1 % num2):" << endl;
		cout << num1 % num2 << endl;
		cout << endl;
	}

}





