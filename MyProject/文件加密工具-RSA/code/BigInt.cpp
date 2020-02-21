#include "BigInt.h"
#include <cctype>
#include <iostream>

namespace lb
{
	BigInt::BigInt(long long num)
	{
		int flag = 0;
		if (num < 0) // ��¼num�Ƿ�Ϊ����
			flag = 1;
		while (num)
		{
			m_data.insert(0, 1, '0' + num % 10); // �ӵ�λ��ʼ��������
			num /= 10;
		}
		if (flag)
			m_data.insert(0, 1, '-'); // �����Ų��뵽���ֵĿ�ͷ
	}

	BigInt::BigInt(const std::string & data)
	{
		std::string str = data;
		m_data = dealData(str); // ��������ַ�������Ϊ���õĴ���
	}

	const std::string& BigInt::dealData(std::string& data)
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
		if (flag) // ��Ϊ����ʱ�������Ų��뵽���ֵĿ�ͷ
			data.insert(0, 1, '-');
		return data;
	}

	const std::string BigInt::add(std::string data1, std::string data2)
	{
		// �Կ�ʼ�����Ž��д���
		if (data1[0] == '+')
			data1.erase(0, 1);
		if (data2[0] == '+')
			data2.erase(0, 1);

		// ���и��ŵ�������д�����ӷ�Ϊ����
		if (data1[0] == '-')
			return sub(data2, data1.substr(1));
		else if (data2[0] == '-')
			return sub(data1, data2.substr(1));

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

	const std::string BigInt::sub(std::string data1, std::string data2)
	{
		// �Կ�ʼ�����Ž��д���
		if (data1[0] == '+')
			data1.erase(0, 1);
		if (data2[0] == '+')
			data2.erase(0, 1);

		// ���и��ŵ�������д���
		if (data2[0] == '-') // data2Ϊ����ʱ�������Ϊ�ӷ���ͬʱȥ��data2�ĸ���
			return add(data1, data2.substr(1));
		else if (data1[0] == '-') // data1Ϊ����ʱ���Ḻ�š�ȥ��data1�ĸ��ź��ڲ�����data1+data2
		{
			std::string res = add(data1.substr(1), data2);
			res.insert(0, 1, '-');
			return res;
		}
		if (data1.size() < data2.size() // data1С��data2ʱ���Ḻ�ţ��ڲ�����data2-data1
			|| data1.size() == data2.size() && data1[0] < data2[0])
		{
			std::string res = sub(data2, data1);
			res.insert(0, 1, '-');
			return res;
		}

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

	const std::string BigInt::mul(std::string data1, std::string data2)
	{
		// �Կ�ʼ�����Ž��д���
		if (data1[0] == '+')
			data1.erase(0, 1);
		if (data2[0] == '+')
			data2.erase(0, 1);

		// ���и��ŵ�������д���
		if (data1[0] == '-' && data2[0] == '-') // ����������ˣ�����Ϊ��
		{
			data1.erase(0);
			data2.erase(0);
		}
		else if (data1[0] == '-') // �����ˣ����Ϊ����
		{
			std::string res = mul(data1.substr(1), data2);
			res.insert(0, 1, '-');
			return res;
		}
		else if (data2[0] == '-') // �����ˣ����Ϊ����
		{
			std::string res = mul(data1, data2.substr(1));
			res.insert(0, 1, '-');
			return res;
		}

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

	const std::string BigInt::dev(std::string data1, std::string data2)
	{
		return "";
	}

	BigInt BigInt::operator+(const BigInt & data)
	{
		return add(m_data, data.m_data);
	}

	BigInt BigInt::operator-(const BigInt & data)
	{
		return sub(m_data, data.m_data);
	}

	BigInt BigInt::operator*(const BigInt & data)
	{
		return mul(m_data, data.m_data);
	}

	BigInt BigInt::operator/(const BigInt & data)
	{
		return dev(m_data, data.m_data);
	}

	BigInt BigInt::operator+(const std::string & data)
	{
		return add(m_data, data);
	}

	BigInt BigInt::operator-(const std::string & data)
	{
		return sub(m_data, data);
	}

	BigInt BigInt::operator*(const std::string & data)
	{
		return mul(m_data, data);
	}

	BigInt BigInt::operator/(const std::string & data)
	{
		return dev(m_data, data);
	}

	BigInt BigInt::operator-() // ȡ�����������
	{
		BigInt res(m_data); // ��������

		if (res.m_data[0] == '-') // ɾȥ����
			res.m_data.erase(0, 1);
		else if (res.m_data[0] == '+') // �����Ÿ�Ϊ����
			res.m_data[0] = '-';
		else // �����Ų��뵽���ֵĿ�ͷ
			res.m_data.insert(0, 1, '-');
		
		return res;
	}

	std::ostream& operator<<(std::ostream & os, const BigInt & data) // ������������
	{
		os << data.m_data;
		return os;
	}

	std::istream& operator>>(std::istream & is, BigInt & data) // �������������
	{
		is >> data.m_data;
		data.dealData(data.m_data);
		return is;
	}
}