#include "BigInt.h"
#include <cctype>
#include <ctime>
#include <utility>
#include <iostream>
#include <random>

namespace lb
{
	BigInt::BigInt(long long num)
	{
		int flag = 0;
		if (num < 0) // ��¼num�Ƿ�Ϊ����
		{
			num /= -1;
			flag = 1;
		}
		while (num)
		{
			m_data.insert(0, 1, '0' + num % 10); // �ӵ�λ��ʼ��������
			num /= 10;
		}
		if (flag && m_data.size() > 0)
			m_data.insert(0, 1, '-'); // �����Ų��뵽���ֵĿ�ͷ
		else if (m_data.size() == 0) // ��û�ж�������ʱ��Ĭ��Ϊ0
			m_data = "0";
	}

	BigInt::BigInt(const char* data)
		: BigInt(std::string(data))
	{ }

	BigInt::BigInt(const std::string & data)
		: m_data(data)
	{
		dealData(m_data); // ��������ַ�������Ϊ���õĴ���
	}

	BigInt BigInt::getRandom(size_t n)
	{
		std::mt19937 rng;
		rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> dist(0, BigInt("1") << BigInt(n));
		return dist(rng);
	}

	std::string& BigInt::dealData(std::string& data)
	{
		int start = 0, end = 0, flag = 0;
		while (data[start] == '+' || data[start] == '-' 
			|| data[start] == '0') // ����+-0��ͷʱ�����ӹ���Щ��Ϣ
		{
			if (data[start] == '-') // ������ڸ��ţ���Ƕ�ȡ��һ������
				flag = 1;
			++start;
		}
		end = start; // ���׸����ֿ�ʼ���ͳ�����������ֳ��ֵĸ���
		while (end < data.size() && isdigit(data[end]))
			++end;
		data = data.substr(start, end - start); // ��ȡ����������
		if (flag && data.size() > 0) // ��Ϊ����ʱ�������Ų��뵽���ֵĿ�ͷ
			data.insert(0, 1, '-');
		else if (data.size() == 0) // ��û�ж�������ʱ��Ĭ��Ϊ0
			data = "0";
		return data;
	}
	// ��Ȼ�����������
	std::string BigInt::add(std::string data1, std::string data2)
	{
		if (data1.size() < data2.size()) // ����ʹ����data�Ĵ�Сһ��
			data1.insert(0, data2.size() - data1.size(), '0');
		else
			data2.insert(0, data1.size() - data2.size(), '0');
		int step = 0;
		std::string res(data1.size(), '0');

		for (int i = static_cast<int>(data1.size()) - 1; i >= 0; --i) // �ӵ�λ���λ���м���
		{
			res[i] = (data1[i] - '0') + (data2[i] - '0') + step; // ������ӵ���ʱֵ���Ǹ�����
			step = res[i] / 10; // ���½�λ��Ϣ
			res[i] = res[i] % 10 + '0'; // ���µ�ǰλ�Ľ�����Ǹ��ַ�
		}
		if (step) // ������ܴ��ڵ�δ����Ľ�λ
			res.insert(0, "1");

		return res;
	}
	// ��Ȼ�Ǵ�����С��
	std::string BigInt::sub(std::string data1, std::string data2)
	{
		int i;
		std::string res(data1.size(), '0');
		data2.insert(0, data1.size() - data2.size(), '0'); // ����ʹ����data�Ĵ�Сһ��

		for (i = static_cast<int>(data1.size()) - 1; i >= 0; --i) // �ӵ�λ���λ���м���
		{
			if (data1[i] < data2[i]) // �ж��Ƿ���Ҫ��λ����
			{
				data1[i] += 10; // ��λ
				--data1[i - 1];
			}
			res[i] = data1[i] - data2[i] + '0'; // ���浱ǰλ�Ľ��
		}
		for (i = 0; i <= res.size() && res[i] == '0'; ++i) // ͳ�����������ͷ���ܴ��ڵ�0�ĸ���
			continue;

		return res.substr(i); // ���ؿ�ͷ����0�Ľ��
	}
	// ��Ȼ�����������
	std::string BigInt::mul(std::string data1, std::string data2)
	{
		int i, j;
		std::string res("0");

		for (i = static_cast<int>(data1.size()) - 1; i >= 0; --i) // ʹ��data1�е�ÿһλ��data2
		{
			int step = 0, curData = data1[i] - '0'; // ��λ��Ϣ��������data2�ĵ�ǰֵ
			std::string temp(data2.size(), '0'); // ����ÿһ����˵���ʱ���

			for (j = static_cast<int>(data2.size()) - 1; j >= 0; --j) // �ӵ�λ���λ���м���
			{
				step += (data2[j] - '0') * curData; // ������˵���ʱֵ���Ǹ�����
				temp[j] = step % 10 + '0'; // ����ǰλ�Ľ�����浽��ʱ�����
				step /= 10; // ���½�λ��Ϣ
			}
			if (step) // ������ܴ��ڵ�δ����Ľ�λ
				temp.insert(0, 1, '0' + step);
			temp.append(data1.size() - 1 - i, '0'); // Ϊ��ʱ��������β��0
			res = add(res, temp);
		}
		for (i = 0; i <= res.size() && res[i] == '0'; ++i) // ͳ�����������ͷ���ܴ��ڵ�0�ĸ���
			continue;

		return res.substr(i); // ���ؿ�ͷ����0�Ľ��
	}
	// ��Ȼ�����������
	std::pair<std::string, std::string> BigInt::dev(std::string data1, std::string data2)
	{
		if (less(data1, data2))
			return make_pair("0", data1);

		std::string ret1, ret2(data1);
		int i, diffNum = data1.size() - data2.size();
		data2.append(diffNum, '0');
		for (i = 0; i <= diffNum; ++i)
		{
			char ch = '0';
			while (less(data2, ret2) || equal(data2, ret2))
			{
				ret2 = sub(ret2, data2);
				++ch;
			}
			ret1.append(1, ch);
			data2.pop_back();
		}
		for (i = 0; i <= ret1.size() && ret1[i] == '0'; ++i) // ͳ�����������ͷ���ܴ��ڵ�0�ĸ���
			continue;

		return make_pair(ret1.substr(i), ret2); // ���ؿ�ͷ����0�Ľ��
	}
	// ��Ȼ��������Ǹ���������
	std::string BigInt::pow(std::string data, std::string n)
	{
		if (n == "0")
			return "1";
		if (n == "1")
			return data;
		if (BigInt(n) % BigInt(2) == "0")
			return pow(mul(data, data), dev(n, "2").first);
		return mul(pow(mul(data, data), dev(n, "2").first), data);
	}
	BigInt BigInt::pow(BigInt n)
	{
		if (n < "0")
			throw "��֧���󸺴�����";
		int flag = 0;
		if (m_data[0] == '-' && n % BigInt(2) == BigInt(1))
			flag = 1;
		std::string res = pow(m_data, n.m_data);
		if (flag)
			res.insert(0, 1, '-');
		return res;
	}

	// �ж�BigInt��С��ϵ��˽�к���
	bool BigInt::less(const std::string & data1, const std::string & data2)
	{
		if (data1[0] == '-' && data2[0] == '-')
			return data1 > data2;
		if (data1[0] == '-')
			return true;
		if (data2[0] == '-')
			return false;
		return data1.size() < data2.size() || data1.size() == data2.size() && data1 < data2;
	}
	bool BigInt::equal(const std::string & data1, const std::string & data2)
	{
		return data1 == data2;
	}

	// ȡ�����������
	BigInt BigInt::operator-()
	{
		BigInt res(m_data); // ��������

		if (m_data == "0")
			return res;
		if (res.m_data[0] == '-') // ɾȥ����
			res.m_data.erase(0, 1);
		else if (res.m_data[0] == '+') // �����Ÿ�Ϊ����
			res.m_data[0] = '-';
		else // �����Ų��뵽���ֵĿ�ͷ
			res.m_data.insert(0, 1, '-');

		return res;
	}
	BigInt BigInt::operator++()
	{
		return *this += 1;
	}
	BigInt BigInt::operator++(int)
	{
		BigInt res(*this);
		*this += 1;
		return res;
	}
	BigInt BigInt::operator--()
	{
		return *this -= 1;
	}
	BigInt BigInt::operator--(int)
	{
		BigInt res(*this);
		*this -= 1;
		return res;
	}
	BigInt::operator long long()
	{
		if (BigInt(LLONG_MAX) < *this)
			return BigInt(LLONG_MAX);
		if (BigInt(LLONG_MIN) > *this)
			return BigInt(LLONG_MIN);

		int i = 0, flag = 0;
		long long res = 0;
		if (m_data[i] == '-')
		{
			++i;
			flag = 1;
		}
		for (; i < m_data.size(); ++i)
			res = res * 10 + m_data[i] - '0';
		if (flag)
			res *= -1;
		return res;
	}
	BigInt::operator std::string()
	{
		return m_data;
	}

	// BigInt��BigInt�ļ�,��,��,��,ģ,����,��������
	BigInt BigInt::operator+(BigInt data)
	{
		// �������������ʱ���Ḻ�ţ����������ļӷ�����
		if (m_data[0] == '-' && data.m_data[0] == '-')
		{
			std::string ret = add(m_data.substr(1), data.m_data.substr(1));
			ret.insert(0, "-");
			return ret;
		}

		// ����һ������ʱ��ת��Ϊ��������
		if (m_data[0] == '-')
			return data - m_data.substr(1);
		if (data.m_data[0] == '-')
			return *this - data.m_data.substr(1);

		// �����������������ļӷ�
		return BigInt(add(m_data, data.m_data));
	}
	BigInt BigInt::operator-(BigInt data)
	{
		// data1,data2��Ϊ����ʱ����Ϊ����data2-data1
		// ���ﲻֱ�ӵ���sub��Ҫ���ж�data2-data1�Ƿ�С��������
		if (m_data[0] == '-' && data.m_data[0] == '-')
			return BigInt(data.m_data.substr(1)) - BigInt(m_data.substr(1));
		
		// data2Ϊ����ʱ��ȥ��data2�ĸ��ź󣬼�����ӷ�
		if (data.m_data[0] == '-')
			return add(m_data, data.m_data.substr(1));

		// data1Ϊ����ʱ���Ḻ�š�ȥ��data1�ĸ��ź��ڲ�����data1+data2
		if (m_data[0] == '-')
		{
			BigInt res = add(m_data.substr(1), data.m_data);
			return -res;
		}

		// data1С��data2ʱ���Ḻ�ţ��ڲ�����data2-data1
		if (m_data.size() == data.m_data.size() && m_data[0] < data.m_data[0]
			|| m_data.size() < data.m_data.size())
		{
			BigInt res = sub(data.m_data, m_data);
			return -res;
		}

		// data1����data2ʱ����������data1-data2
		return sub(m_data, data.m_data);
	}
	BigInt BigInt::operator*(BigInt data)
	{
		// ����������ˣ�����Ϊ��
		if (m_data[0] == '-' && data.m_data[0] == '-')
			return mul(m_data.substr(1), data.m_data.substr(1));

		// �����ˣ����Ϊ����
		if (m_data[0] == '-')
		{
			BigInt res = mul(m_data.substr(1), data.m_data);
			return -res;
		}
		if (data.m_data[0] == '-')
		{
			BigInt res = mul(m_data, data.m_data.substr(1));
			return -res;
		}

		// �����������������ĳ˷�
		return mul(m_data, data.m_data);
	}
	BigInt BigInt::operator/(BigInt data)
	{
		// �жϳ����Ƿ�Ϊ0
		if (data.m_data == "" || data.m_data == "0")
			throw "error C2124: ������������ģ";

		// �����������������Ϊ��
		if (m_data[0] == '-' && data.m_data[0] == '-')
			return dev(m_data.substr(1), data.m_data.substr(1)).first;

		// �����������Ϊ����
		if (m_data[0] == '-')
		{
			BigInt res = dev(m_data.substr(1), data.m_data).first;
			return -res;
		}
		if (data.m_data[0] == '-')
		{
			BigInt res = dev(m_data, data.m_data.substr(1)).first;
			return -res;
		}
		// �����������ڳ���ʱ����������data1/data2
		return dev(m_data, data.m_data).first;
	}
	BigInt BigInt::operator%(BigInt data)
	{
		// �жϳ����Ƿ�Ϊ0
		if (data.m_data == "" || data.m_data == "0")
			throw "error C2124: ������������ģ";

		// �����������������Ϊ��
		if (m_data[0] == '-' && data.m_data[0] == '-')
			return dev(m_data.substr(1), data.m_data.substr(1)).second;

		// �����������Ϊ����
		if (m_data[0] == '-')
		{
			BigInt res = dev(m_data.substr(1), data.m_data).second;
			return -res;
		}
		if (data.m_data[0] == '-')
		{
			BigInt res = dev(m_data, data.m_data.substr(1)).second;
			return -res;
		}

		// �����������ڳ���ʱ����������data1%data2
		return dev(m_data, data.m_data).second;
	}
	BigInt BigInt::operator<<(BigInt data)
	{
		// ���Ƹ����α�ʾ���������ֵ��
		if (data < "0")
			return *this >> -data;
		return *this * pow("2", data.m_data);

	}
	BigInt BigInt::operator>>(BigInt data)
	{
		// ���Ƹ����α�ʾ���������ֵ��
		if (data < "0")
			return *this << -data;
		return *this / pow("2", data.m_data);
	}
	BigInt BigInt::operator+=(BigInt data)
	{
		*this = *this + data;
		return *this;
	}
	BigInt BigInt::operator-=(BigInt data)
	{
		*this = *this - data;
		return *this;
	}
	BigInt BigInt::operator*=(BigInt data)
	{
		*this = *this * data;
		return *this;
	}
	BigInt BigInt::operator/=(BigInt data)
	{
		*this = *this / data;
		return *this;
	}
	BigInt BigInt::operator%=(BigInt data)
	{
		*this = *this % data;
		return *this;
	}
	BigInt BigInt::operator<<=(BigInt data)
	{
		*this = *this << data;
		return *this;
	}
	BigInt BigInt::operator>>=(BigInt data)
	{
		*this = *this >> data;
		return *this;
	}

	// string������BigInt�ļ�,��,��,��,ģ,����,��������
	BigInt operator+(std::string data1, BigInt data2)
	{
		return BigInt(data1) + data2;
	}
	BigInt operator-(std::string data1, BigInt data2)
	{
		return BigInt(data1) - data2;
	}
	BigInt operator*(std::string data1, BigInt data2)
	{
		return BigInt(data1) * data2;
	}
	BigInt operator/(std::string data1, BigInt data2)
	{
		return BigInt(data1) / data2;
	}
	BigInt operator%(std::string data1, BigInt data2)
	{
		return BigInt(data1) % data2;
	}
	BigInt operator<<(std::string data1, BigInt data2)
	{
		return BigInt(data1) << data2;
	}
	BigInt operator>>(std::string data1, BigInt data2)
	{
		return BigInt(data1) >> data2;
	}

	// ������BigInt�ļ�,��,��,��,ģ,����,��������
	BigInt operator+(long long data1, BigInt data2)
	{
		return BigInt(data1) + data2;
	}
	BigInt operator-(long long data1, BigInt data2)
	{
		return BigInt(data1) - data2;
	}
	BigInt operator*(long long data1, BigInt data2)
	{
		return BigInt(data1) * data2;
	}
	BigInt operator/(long long data1, BigInt data2)
	{
		return BigInt(data1) / data2;
	}
	BigInt operator%(long long data1, BigInt data2)
	{
		return BigInt(data1) % data2;
	}
	BigInt operator<<(long long data1, BigInt data2)
	{
		return BigInt(data1) << data2;
	}
	BigInt operator>>(long long data1, BigInt data2)
	{
		return BigInt(data1) >> data2;
	}

	// ��ϵ���������
	bool BigInt::operator<(const BigInt & data)
	{
		return less(m_data, data.m_data);
	}
	bool BigInt::operator<=(const BigInt & data)
	{
		return less(m_data, data.m_data) || equal(m_data, data.m_data);
	}
	bool BigInt::operator>(const BigInt & data)
	{
		return less(data.m_data, m_data);
	}
	bool BigInt::operator>=(const BigInt & data)
	{
		return less(data.m_data, m_data) || equal(m_data, data.m_data);
	}
	bool BigInt::operator==(const BigInt & data)
	{
		return equal(m_data, data.m_data);
	}
	bool BigInt::operator!=(const BigInt & data)
	{
		return !equal(m_data, data.m_data);
	}

	bool operator<(long long data1, const BigInt & data2)
	{
		return BigInt(data1) < data2;
	}
	bool operator<=(long long data1, const BigInt & data2)
	{
		return BigInt(data1) <= data2;
	}
	bool operator>(long long data1, const BigInt & data2)
	{
		return BigInt(data1) < data2;
	}
	bool operator>=(long long data1, const BigInt & data2)
	{
		return BigInt(data1) >= data2;
	}
	bool operator==(long long data1, const BigInt & data2)
	{
		return BigInt(data1) == data2;
	}
	bool operator!=(long long data1, const BigInt & data2)
	{
		return BigInt(data1) != data2;
	}

	// ������������
	std::ostream& operator<<(std::ostream & os, const BigInt & data)
	{
		os << data.m_data;
		return os;
	}
	// �������������
	std::istream& operator>>(std::istream & is, BigInt & data) 
	{
		is >> data.m_data;
		data.dealData(data.m_data);
		return is;
	}
}