#pragma once
#include<iostream>

enum
{
	BLANK, // ��Ч
	SPADE, // ����
	HEART, // ����
	DIAMOND, // ����
	CLUB, // ÷��
	JOKER, // ��С��
	A = 1,
	J = 11,
	Q = 12,
	K = 13,
};

class Poker
{
private:
	int m_point;
	char m_suit;
public:
	Poker(char point = BLANK, char suit = BLANK);
	~Poker();
	void SetPoker(char point = BLANK, char suit = BLANK);
	bool IsValid() { return m_point != BLANK && m_suit != BLANK; }
	int GetPoint() { return m_point; }
	bool operator>(const Poker& p)const;
	bool operator<(const Poker& p)const;
	bool operator==(const Poker& p)const;
	friend std::ostream& operator<<(std::ostream& os, const Poker& p);
};

