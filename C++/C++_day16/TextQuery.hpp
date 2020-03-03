#ifndef _TEXTQUERY_HPP_
#define _TEXTQUERY_HPP_

#include <set>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

namespace lb
{
	class QueryResult
	{
		friend std::ostream& print(std::ostream &os, const QueryResult &result);

	private:
		using LineNo = std::vector<std::string>::size_type;

		std::string m_word; // ��ѯ�ĵ���
		std::shared_ptr<std::set<LineNo>> m_lines; // ���ֵ��к�
		std::shared_ptr<std::vector<std::string>> m_file; // Ҫ��ѯ���ļ�

	public:
		QueryResult(std::string word, std::shared_ptr<std::set<LineNo>> lines
			, std::shared_ptr<std::vector<std::string>> file)
			: m_word(word)
			, m_file(file)
			, m_lines(lines)
		{ }
	};

	class TextQuery
	{
	private:
		using LineNo = std::vector<std::string>::size_type;

		std::shared_ptr<std::vector<std::string>> m_file; // ������ļ�
		std::map<std::string, std::shared_ptr<std::set<LineNo>>> m_wordMap; // ÿ�����ʵ��������кŵ�ӳ��

	public:
		TextQuery(std::ifstream &fin) : m_file(new std::vector<std::string>)
		{
			LineNo lineNo;
			std::string line, word;

			while (getline(fin, line)) // ��ȡÿ�е��ı�
			{
				m_file->push_back(line); // ����ȡ���ı�����
				lineNo = m_file->size() - 1; // ��ȡ��ǰ�еı��
				std::istringstream text(line);

				while (text >> word) // ��ȡÿ���еĵ���
				{
					if (!m_wordMap[word]) // ��shared_ptr<set<LineNo>>�ǿ�ָ��
						m_wordMap[word].reset(new std::set<LineNo>); // ����һ��set<LineNo>
					m_wordMap[word]->insert(lineNo); // ���б�Ų���set
				}
			}
		}

		QueryResult query(const std::string &word) const
		{
			static std::shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>); // �Ҳ���ʱ�ķ���
			auto loc = m_wordMap.find(word); // ʹ��find�����Ƿ���word����

			if (loc == m_wordMap.end()) // ����Ҳ���������nodata
				return QueryResult(word, nodata, m_file);
			else// �ҵ��˷���loc->second
				return QueryResult(word, loc->second, m_file);
		}
	};

	std::ostream& print(std::ostream &os, const QueryResult &result)
	{
		os << result.m_word << " ������ " << result.m_lines->size() << " ��: " << std::endl;
		for (auto num : *result.m_lines)
			os << "(line " << num + 1 << ") " << *(result.m_file->begin() + num) << std::endl;
		return os;
	}
}
#endif /* _TEXTQUERY_HPP_ */