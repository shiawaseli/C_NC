#include "Nowcoder.h"

/*
 *
 *		��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
 *
 *  	����ʱ�䣺3ms
 *		ռ���ڴ棺620k	
 *
 */
class AddClass
{
private:
	int m_sum;
public:
	AddClass(int n = 1)
		: m_sum(n)
	{
		if (n > 1)
			m_sum += AddClass(n - 1).show();
	}
	int show()
	{
		return m_sum;
	}
};
int Sum_Solution(int n)
{
	return AddClass(n).show();
}