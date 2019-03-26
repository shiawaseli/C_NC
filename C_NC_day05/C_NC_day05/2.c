#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int find(int *a, int target, int left, int right)
{
	int mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (a[mid] < target)
		{
			left = mid + 1;
		}
		else if (a[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main2()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a) / sizeof(a[0]);
	int target, output;

	printf("��������Ҫ���ҵ�ֵ:>");
	scanf("%d", &target);
	output = find(a, target, 0, n-1);
	if (output != -1) {
		printf("Ŀ�������±�Ϊ��%d\n", output);
	}
	else
	{
		printf("Ŀ��ֵ�����ڣ�\n");
	}

	system("pause");
	return 0;
}