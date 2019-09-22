#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*Definition for singly-linked list.*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



/*
 *
 * Vector �ļ���
 *
 */
 
vector<int> twoSum(vector<int>& nums, int target);		// 1. ����֮��
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);	// 4. Ѱ�����������������λ��

/*
 *
 * String �ļ���
 *
 */
 
int lengthOfLongestSubstring(string s);					// 3. ���ظ��ַ�����Ӵ�
string longestPalindrome(string s);						// 5. ������Ӵ�
string convert(string s, int numRows);					// 6. Z ���α任

/*
 *
 * LinkList �ļ���
 *
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);	// 2. �������