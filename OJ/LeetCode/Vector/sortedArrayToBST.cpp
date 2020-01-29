#include "Leetcode.h"

/*
 *
 *	108. ����������ת��Ϊ����������
 *
 *  	ִ����ʱ:		24 ms, ������ C++ �ύ�л�����58.27%���û�
 *  	�ڴ�����:		26.1 MB, ������ C++ �ύ�л�����7.22%���û�
 *
 */
TreeNode* sortedArrayToBST(vector<int>& nums)
{
	TreeNode *root = nullptr;
	if (nums.size() <= 0)
		return root;
	if (nums.size() == 1)
		root = new TreeNode(nums[0]);
	root = new TreeNode(nums[nums.size() / 2]);
	vector<int> tmp1(nums.begin(), nums.begin() + nums.size() / 2);
	root->left = sortedArrayToBST(tmp1);
	vector<int> tmp2(nums.begin() + nums.size() / 2 + 1, nums.end());
	root->right = sortedArrayToBST(tmp2);
	return root;
}