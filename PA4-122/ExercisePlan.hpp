#pragma once
#include <iostream>
#include <string>
#include "Node.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

class ExerList
{
public:
	ExerList(ListNode* pNewHead = nullptr, ListNode* pNewTail = nullptr);

	ExerList& operator= (const ExerList& rhs);

	~ExerList();

	bool endList(ListNode* dayplan);
	bool editValue();

	//getters
	ListNode* getmpHead() const;
	ListNode* getmpTail() const;

	//setters 
	void setmpHead(ListNode* const pNewHead);
	void setmpTail(ListNode* const pNewTail);

private:
	ListNode* mpHead;
	ListNode* mpTail;
};

//overloaded stream operators allow for printing entire list
std::ostream& operator<< (std::ostream& lhs, const ExerList& rhs);
std::fstream& operator<< (std::fstream& lhs, const ExerList& rhs);

std::fstream& operator>> (std::fstream& lhs, ExerList& rhs);