#ifndef _MAILCLASS_HPP_
#define _MAILCLASS_HPP_

#include <set>
#include <string>
#include <iostream>

namespace lb
{
	class Folder;

	class Message
	{
		friend class Folder;
		// ��������message
		friend void swap(Message &msg1, Message &msg2);

	private:
		// ��Ϣ�ı�
		std::string m_contents;
		// ��¼��Ϣ�����ڵ�Ŀ¼
		std::set<Folder*> m_folders;

	private:
		// ʹ��ǰmessage����ָ��folder��λ����Ϣ
		void addFldr(Folder *fldr);
		// ʹ��ǰmessageɾ��ָ��folder��λ����Ϣ
		void remFldr(Folder *fldr);
		// ʹ���б����о�message��Ϣ��folder��ӵ�ǰmessage��λ����Ϣ
		void addToFolders();
		// ʹ���б����е�ǰmessage��Ϣ��folderɾ����ǰmessage��λ����Ϣ
		void removeFromFolders();
		// �ƶ���ʱmessage��folder��Ϣ
		void moveFolders(Message *msg);

	public:
		// m_folders��ʽ��ʼ��Ϊ��
		explicit Message(const std::string &contents = "")
			: m_contents(contents) { }
		// �������캯����������message��Ϣ������ӵ����е�folder��
		Message(const Message &msg)
			: m_contents(msg.m_contents), m_folders(msg.m_folders)
		{
			addToFolders();
		}
		// �ƶ����캯����������ʱ��message��Ϣ�ƶ�����ǰ��message��
		Message(Message &&msg)
			: m_contents(std::move(msg.m_contents))
		{
			moveFolders(&msg);
		}
		// ��������������Ҫ���ٵ�message������folder��ɾ��
		~Message() { removeFromFolders(); }

		// ɾ��ԭ��folder����ľ�message��Ϣ���������һ����message��Ϣ
		Message& operator=(const Message &msg);
		// ɾ��ԭ��folder����ľ�message��Ϣ���ƶ���ȡһ����message��Ϣ
		Message& operator=(Message &&msg);
		// ��message���浽ָ����folder��
		void save(Folder &fldr);
		// ��message��ָ����folderɾ��
		void remove(Folder &fldr);
		// �����ǰmessage����Ϣ
		void print() const;
	};
	void swap(Message &msg1, Message &msg2)
	{
		// ���������ñ�����ѡ������ʵ�swap�����н���
		using std::swap;
		// �Ƚ�����Ŀ¼��message�ľ�λ����Ϣɾ��
		msg1.removeFromFolders();
		msg2.removeFromFolders();
		// ʹ������ʵ�swap���н���
		swap(msg1.m_contents, msg2.m_contents);
		swap(msg1.m_folders, msg2.m_folders);
		// ʹ����Ŀ¼���±���message����λ����Ϣ
		msg1.addToFolders();
		msg2.addToFolders();
	}

	class Folder
	{
		friend class Message;
		// ��������folder
		friend void swap(Folder &fldr1, Folder &fldr2);

	private:
		// ��¼Ŀ¼�б������Ϣ
		std::set<Message*> m_msg;
		
	private:
		// ʹ��ǰfolder����ָ��message��λ����Ϣ
		void addMsg(Message *msg);
		// ʹ��ǰfolderɾ��ָ��message��λ����Ϣ
		void remMsg(Message *msg);
		// ʹ��Ŀ¼������message��ӵ�ǰfolder��λ����Ϣ
		void addToMessages();
		// ʹ��ǰĿ¼������messageɾ����ǰfolder��λ����Ϣ
		void removeFromMessages();
		// �ƶ���ʱfolder�е�message��Ϣ
		void moveMessage(Folder *fldr);

	public:
		// m_msg��ʽ��ʼ��Ϊ��
		explicit Folder() { }
		// �������캯����������folder��Ϣ��ӵ����������message��
		Folder(const Folder &fldr)
			: m_msg(fldr.m_msg)
		{
			addToMessages();
		}
		Folder(Folder &&fldr)
		{
			moveMessage(&fldr);
		}
		// ��������������Ҫ���ٵĵ�ǰfolder�����б����message��ɾ��
		~Folder()
		{
			removeFromMessages();
		}

		// ɾ����Ŀ¼������message�����ľ�folder��Ϣ��Ϊ��message���������folder��Ϣ
		Folder& operator=(const Folder &fldr);
		// ɾ����Ŀ¼������message�����ľ�folder��Ϣ���ƶ���ȡ��ʱmessage��folder��Ϣ
		Folder& operator=(Folder &&fldr);
		// ��ָ��message���浽��ǰfolder��
		void save(Message &msg);
		// ��ָ��message�ӵ�ǰfolderɾ��
		void remove(Message &msg);
		// ���������folder��message����Ϣ
		void print(const std::string &fldrname = "") const;
	};
	void swap(Folder &fldr1, Folder &fldr2)
	{
		// ���������ñ�����ѡ������ʵ�swap�����н���
		using std::swap;
		// �Ƚ�Ŀ¼������message����ľ�floderλ����Ϣɾ��
		fldr1.removeFromMessages();
		fldr2.removeFromMessages();
		// ʹ������ʵ�swap���н���
		swap(fldr1.m_msg, fldr2.m_msg);
		// ʹĿ¼������message���±���floder����λ����Ϣ
		fldr1.addToMessages();
		fldr2.addToMessages();
	}

	Message& Message::operator=(const Message &msg)
	{
		removeFromFolders();
		m_contents = msg.m_contents;
		m_folders = msg.m_folders;
		addToFolders();
		return *this;
	}
	Message& Message::operator=(Message &&msg)
	{
		if (this != &msg)
		{
			removeFromFolders();
			m_contents = std::move(msg.m_contents);
			moveFolders(&msg);
		}
		return *this;
	}
	/*
	// ͬʱʵ�ֿ������ƶ����壬����ֵʱ�����õ�msg������ֵʱ�ƶ��õ�msg��
	// Ȼ��msg��*this������ɸ�ֵ
	// ע�⣺�Լ����Լ���ֵʱҲ����п�����������Դ�˷�
	// 		��һ����ֵʱ������������ƶ�����
	Message& Message::operator=(Message msg)
	{
		// ֱ�ӵ����Լ���swap
		swap(*this, msg);
		return *this;
	}
	*/
	inline void Message::save(Folder &fldr)
	{
		addFldr(&fldr);
		fldr.addMsg(this);
	}
	inline void Message::remove(Folder &fldr)
	{
		remFldr(&fldr);
		fldr.remMsg(this);
	}
	inline void Message::print() const
	{
		std::cout << "message: " << m_contents << ";";
	}
	inline void Message::addFldr(Folder *fldr)
	{
		m_folders.insert(fldr);
	}
	inline void Message::remFldr(Folder *fldr)
	{
		m_folders.erase(fldr);
	}
	void Message::addToFolders()
	{
		for (auto f : m_folders)
			f->addMsg(this);
	}
	void Message::removeFromFolders()
	{
		for (auto f : m_folders)
			f->remMsg(this);
	}
	void Message::moveFolders(Message *msg)
	{
		msg->removeFromFolders();
		m_folders = std::move(msg->m_folders);
		addToFolders();
		msg->m_folders.clear(); // ��֤����set���޺���
	}

	Folder& Folder::operator=(const Folder &fldr)
	{
		removeFromMessages();
		m_msg = fldr.m_msg;
		addToMessages();
		return *this;
	}
	Folder& Folder::operator=(Folder &&fldr)
	{
		if (this != &fldr)
			moveMessage(&fldr);
		return *this;
	}
	inline void Folder::save(Message &msg)
	{
		addMsg(&msg);
		msg.addFldr(this);
	}
	inline void Folder::remove(Message &msg)
	{
		remMsg(&msg);
		msg.remFldr(this);
	}
	void Folder::print(const std::string &fldrname) const
	{
		std::cout << fldrname << "Ŀ¼:";
		for (auto m : m_msg)
		{
			std::cout << " ";
			m->print();
		}
		std::cout << std::endl;
	}
	inline void Folder::addMsg(Message *msg)
	{
		m_msg.insert(msg);
	}
	inline void Folder::remMsg(Message *msg)
	{
		m_msg.erase(msg);
	}
	void Folder::addToMessages()
	{
		for (auto m : m_msg)
			m->addFldr(this);
	}
	void Folder::removeFromMessages()
	{
		for (auto m : m_msg)
			m->remFldr(this);
	}
	void Folder::moveMessage(Folder *fldr)
	{
		fldr->removeFromMessages();
		m_msg = std::move(fldr->m_msg);
		addToMessages();
	}
}

#endif /* _MAILCLASS_HPP_ */