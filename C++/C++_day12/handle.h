#pragma once
#include <iostream>

namespace lb
{
	class Point
	{
	private:
		int m_x;
		int m_y;
	public:
		Point() : m_x(0), m_y(0) { }
		Point(const int x, const int y) : m_x(x), m_y(y) { }
		int x() const { return m_x; }
		int y() const { return m_y; }
		Point& x(const int x) { m_x = x; return *this; }
		Point& y(const int y) { m_y = y; return *this; }
	};
	// ʹ������ʵ�ֶԶ���ļ���
	class UPoint
	{
	private:
		Point m_p;
		int m_cnt; // ���ü���
	private:
		UPoint() : m_cnt(1) { }
		UPoint(const Point & p) : m_p(p), m_cnt(1) { }
		UPoint(const int x, const int y) : m_p(x, y), m_cnt(1) { }
		UPoint(UPoint & up) : m_p(up.m_p), m_cnt(up.m_cnt) { ++m_cnt; }
		~UPoint() { --m_cnt; }
		UPoint& operator=(UPoint & up);
		int x() const { return m_p.x(); }
		int y() const { return m_p.y(); }
		int count() const { return m_cnt; }
		UPoint& x(const int x) { m_p.x(x); return *this; }
		UPoint& y(const int y) { m_p.y(y); return *this; }
		friend class PointHandle;
	};
	UPoint& UPoint::operator=(UPoint & up)
	{
		++up.m_cnt;
		--m_cnt;
		m_cnt = up.m_cnt;
		m_p = up.m_p;
		return *this;
	}
	// ʹ�þ�����ⲻ��Ҫ�Ķ�����(����������󶨵�ͬһ������)
	class PointHandle
	{
	private:
		UPoint *m_up;
		//Point *m_p; // ��ʱ�����������ָ��ǳ����ƣ��Ҳ����ж������ȫ����Ȩ���޷���ֹ�û����Point�����ʵ�ʵ�ַ
	public:
		PointHandle() : m_up(new UPoint) { }
		PointHandle(const Point & p) : m_up(new UPoint(p)) { }
		PointHandle(const int x, const int y) : m_up(new UPoint(x, y)) { }
		PointHandle(const PointHandle & ph) : m_up(ph.m_up) { ++(m_up->m_cnt); }
		~PointHandle() { if (--(m_up->m_cnt) == 0) delete m_up; }
		PointHandle& operator=(const PointHandle & ph);
		friend std::ostream& operator<<(std::ostream & os, const PointHandle & ph);
		int x() const { return m_up->x(); }
		int y() const { return m_up->y(); }
		int count() const { return m_up->count(); }

		// ָ������,�󶨵�ͬһ������ľ��ͬ���ı�
		//PointHandle& x(const int x) { m_up->m_p.x(x); return m_up->m_p; }
		//PointHandle& y(const int y) { m_up->m_p.y(y); return m_up->m_p; }
		// ֵ����,һ������ĸı䲻Ӱ���������(ʹ��дʱ����,ֻ������Ҫ��ʱ��Ž��п���)
		PointHandle& x(const int x);
		PointHandle& y(const int y);

		bool checkCount();
		void show() { std::cout << *this << std::endl; }
	};
	PointHandle& PointHandle::operator=(const PointHandle & ph)
	{
		++(ph.m_up->m_cnt);
		if (--(m_up->m_cnt) == 0)
			delete m_up;
		m_up = ph.m_up;
		return *this;
	}
	std::ostream& operator<<(std::ostream & os, const PointHandle & ph)
	{
		os << '(' << ph.x() << ',' << ph.y() << ')';
		return os;
	}
	PointHandle& PointHandle::x(const int x)
	{
		checkCount();
		m_up->x(x);
		return *this;
	}
	PointHandle& PointHandle::y(const int y)
	{
		checkCount();
		m_up->y(y);
		return *this;
	}
	bool PointHandle::checkCount()
	{
		if (m_up->m_cnt != 1)
		{
			--(m_up->m_cnt);
			m_up = new UPoint(*m_up);
		}
		return true;
	}

	// ������,������Ҫ���ü�������
	class UseCount
	{
	private:
		int *m_cnt;
	public:
		UseCount() : m_cnt(new int(1)) { }
		UseCount(const UseCount & uc) : m_cnt(uc.m_cnt) { ++(*m_cnt); }
		~UseCount() { if (--(*m_cnt) == 0) delete m_cnt; }
		int count() const { return *m_cnt; }
		bool only() const { return *m_cnt == 1; }
		bool reattach(const UseCount & uc);
		bool makeOnly();
	private:
		UseCount& operator=(const UseCount & uc) { } // ��ʵ��,��ֱֹ�Ӹ�ֵ����
	};
	bool UseCount::reattach(const UseCount & uc)
	{
		++(*uc.m_cnt);
		if (--(*m_cnt) == 0)
		{
			delete m_cnt;
			m_cnt = uc.m_cnt;
			return true;
		}
		m_cnt = uc.m_cnt;
		return false;
	}
	bool UseCount::makeOnly()
	{
		if (*m_cnt == 1)
			return false;
		--(*m_cnt);
		m_cnt = new int(1);
		return true;
	}
	class PointHandle2
	{
	private:
		Point *m_p;
		//int *m_cnt; // Ҳ����ʹ��ָ��,����������෽��
		UseCount m_uc;
	public:
		PointHandle2() : m_p(new Point){ }
		PointHandle2(const Point & p) : m_p(new Point(p)){ }
		PointHandle2(const int x, const int y) : m_p(new Point(x, y)) { }
		PointHandle2(const PointHandle2 & hp) : m_p(hp.m_p), m_uc(hp.m_uc) { }
		~PointHandle2() { if (m_uc.only()) delete m_p; }
		PointHandle2& operator=(const PointHandle2 & hp);
		friend std::ostream& operator<<(std::ostream & os, const PointHandle2 & ph);
		int x() const { return m_p->x(); }
		int y() const { return m_p->y(); }
		int count() const { return m_uc.count(); }
		PointHandle2& x(const int x);
		PointHandle2& y(const int y);
		void show() { std::cout << *this << std::endl; }
	};
	PointHandle2& PointHandle2::operator=(const PointHandle2 & hp)
	{
		if (m_uc.reattach(hp.m_uc))
			delete m_p;
		m_p = hp.m_p;
		return *this;
	}
	std::ostream& operator<<(std::ostream & os, const PointHandle2 & ph)
	{
		os << '(' << ph.x() << ',' << ph.y() << ')';
		return os;
	}
	PointHandle2& PointHandle2::x(const int x)
	{
		if (m_uc.makeOnly())
			m_p = new Point(*m_p);
		m_p->x(x);
		return *this;
	}
	PointHandle2& PointHandle2::y(const int y)
	{
		if (m_uc.makeOnly())
			m_p = new Point(*m_p);
		m_p->y(y);
		return *this;
	}
}