#pragma once
#include <iostream>
using namespace std;

namespace lb {
	enum Color { RED, BLACK };
	const char *color[2] = { "RED", "BLACK" };

	template <class T>
	class RBTreeNode
	{
	private:
		T m_data;
		RBTreeNode* m_left;
		RBTreeNode* m_right;
		RBTreeNode* m_parent;
		Color m_color;
	public:
		RBTreeNode(const T& val = T(), Color color = RED) : 
			m_data(val),
			m_left(nullptr),
			m_right(nullptr),
			m_parent(nullptr),
			m_color(RED)
		{}

		template <class T>
		friend class RBTree;
	};

	template <class T>
	class RBTree
	{
	private:
		RBTreeNode<T>* m_head;

		bool updateHead() // ����ͷ���͸��ڵ����Ϣ
		{
			RBTreeNode<T> *root = getRoot();
			root->m_color = BLACK;
			m_head->m_left = leftMost();
			m_head->m_right = rightMost();
			return true;
		}

		bool rRound(RBTreeNode<T> *pre) // �������������������ڵ㽫���Ϊ��������ߵĽڵ�
		{
			RBTreeNode<T> *grand = pre->m_parent;
			RBTreeNode<T> *grandparent = grand->m_parent;

			pre->m_parent = grandparent;
			if (grandparent == m_head)
				m_head->m_parent = pre;
			else if (grandparent->m_left == grand)
				grandparent->m_left = pre;
			else
				grandparent->m_right = pre;

			if (pre->m_right)
				pre->m_right->m_parent = grand;
			grand->m_left = pre->m_right;

			pre->m_right = grand;
			grand->m_parent = pre;
			return true;
		}

		bool lRound(RBTreeNode<T> *pre) // �������������������ڵ㽫���Ϊ��������ߵĽڵ�
		{
			RBTreeNode<T> *grand = pre->m_parent;
			RBTreeNode<T> *grandparent = grand->m_parent;

			pre->m_parent = grandparent;
			if (grandparent == m_head)
				m_head->m_parent = pre;
			else if (grandparent->m_left == grand)
				grandparent->m_left = pre;
			else
				grandparent->m_right = pre;

			if (pre->m_left)
				pre->m_left->m_parent = grand;
			grand->m_right = pre->m_left;

			pre->m_left = grand;
			grand->m_parent = pre;
			return true;
		}

		bool lRound_forlr(RBTreeNode<T> *pre) // ר����������������ʱд������������ڵ���Һ��ӽ����Ϊ��������ߵĽڵ�
		{
			RBTreeNode<T> *cur = pre->m_right;
			RBTreeNode<T> *grand = pre->m_parent;

			cur->m_parent = grand;
			if (grand == m_head)
				m_head->m_parent = cur;
			else if (grand->m_left == pre)
				grand->m_left = cur;
			else
				grand->m_right = cur;

			if (cur->m_left)
				cur->m_left->m_parent = pre;
			pre->m_right = cur->m_left;

			cur->m_left = pre;
			pre->m_parent = cur;
			return true;
		}

		void subShow(RBTreeNode<T> *cur) // ǰ��ݹ���������
		{
			if (cur)
			{
				cout << cur->m_data << " " << color[cur->m_color] << "|||";
				subShow(cur->m_left);
				subShow(cur->m_right);
			}
		}

	public:
		RBTree()
		{
			m_head = new RBTreeNode<T>(0, BLACK);
			m_head->m_color = BLACK;
		}

		RBTreeNode<T>* getRoot() // ��ø��ڵ�
		{
			return m_head->m_parent;
		}

		RBTreeNode<T>* leftMost() // �����Сֵ�Ľڵ�
		{
			RBTreeNode<T> *cur;
			for (cur = getRoot(); cur->m_left; cur = cur->m_left);
			return cur;
		}

		RBTreeNode<T>* rightMost() // ������ֵ�Ľڵ�
		{
			RBTreeNode<T> *cur;
			for (cur = getRoot(); cur->m_right; cur = cur->m_right);
			return cur;
		}

		bool insert(const T& val) // ��������뺯��
		{
			RBTreeNode<T> *root = getRoot();

			if (root == nullptr) // �����Ϊ��ʱ
			{
				RBTreeNode<T> *cur = new RBTreeNode<T>(val);
				m_head->m_parent = cur;
				cur->m_parent = m_head;
			}
			else
			{
				RBTreeNode<T> *pre = nullptr;
				RBTreeNode<T> *cur = root;

				while (cur)
				{
					if (cur->m_data == val)
						return false;
					pre = cur;
					if (cur->m_data > val)
						cur = cur->m_left;
					else
						cur = cur->m_right;
				}
				cur = new RBTreeNode<T>(val);
				if (pre->m_data > val)
					pre->m_left = cur;
				else
					pre->m_right = cur;
				cur->m_parent = pre;
				// ���������
			checkAgain:
				if (pre->m_color == RED) // ���ڵ�Ϊ��ɫʱ�����е���
				{
					RBTreeNode<T> *grand = pre->m_parent;
					RBTreeNode<T> *uncle = (grand->m_left == pre) ? grand->m_right : grand->m_left;

					if (grand->m_left == pre)
					{
						uncle = grand->m_right;
						if (uncle && uncle->m_color == RED) // �˾˽ڵ�Ϊ��ɫʱ�����л�ɫ����
						{
							uncle->m_color = BLACK;
							pre->m_color = BLACK;
							grand->m_color = RED;
							cur = grand;
							pre = cur->m_parent;
							grand = pre->m_parent;
							uncle = (grand->m_left == pre) ? grand->m_right : grand->m_left;
							goto checkAgain;
						}
						else // �˾˽ڵ�Ϊ��ɫʱ��������ת����
						{
							if (pre->m_right == cur) // �й������ʱ����������
							{
								lRound(cur);
								RBTreeNode<T> *tmp = pre;
								pre = cur;
								cur = tmp;
							}
							rRound(pre); // ������ɽڵ�λ�õ���
							pre->m_color = BLACK;
							grand->m_color = RED;
						}
					}
					else
					{
						uncle = grand->m_left;
						if (uncle && uncle->m_color == RED) // �˾˽ڵ�Ϊ��ɫʱ�����л�ɫ����
						{
							uncle->m_color = BLACK;
							pre->m_color = BLACK;
							grand->m_color = RED;
							cur = grand;
							pre = cur->m_parent;
							grand = pre->m_parent;
							uncle = (grand->m_left == pre) ? grand->m_right : grand->m_left;
							goto checkAgain;
						}
						else // �˾˽ڵ�Ϊ��ɫʱ��������ת����
						{
							if (pre->m_left == cur) // �й������ʱ����������
							{
								rRound(cur);
								RBTreeNode<T> *tmp = pre;
								pre = cur;
								cur = tmp;
							}
							lRound(pre); // ������ɽڵ�λ�õ���
							pre->m_color = BLACK;
							grand->m_color = RED;
						}
					}
				}
			}

			updateHead();
			return true;
		}

		void show()
		{
			RBTreeNode<T> *root = getRoot();
			subShow(root);
		}
	};
}
