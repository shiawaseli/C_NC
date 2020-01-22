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
		void show() { std::cout << '(' << x() << ',' << y() << ')' << std::endl; }
	};
	PointHandle& PointHandle::operator=(const PointHandle & ph)
	{
		++(ph.m_up->m_cnt);
		if (--(m_up->m_cnt) == 0)
			delete m_up;
		m_up = ph.m_up;
		return *this;
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
}