#pragma once
#include <iostream>
#include <string>
#include "Node.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

class DietList
{
public:
	DietList(ListNode* pNewHead = nullptr, ListNode* pNewTail = nullptr);


	DietList& operator= (const DietList& rhs);

	~DietList();

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
//stream overloads 
std::ostream& operator<< (std::ostream& lhs, const DietList& rhs);
std::fstream& operator<< (std::fstream& lhs, const DietList& rhs);

std::fstream& operator>> (std::fstream& lhs, DietList& rhs);