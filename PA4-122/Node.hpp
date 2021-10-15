#pragma once
#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class ListNode
{
public:
	ListNode(string newDate, string newName, int newCalories = 0);

	ListNode & operator= (const ListNode& copy);

	~ListNode();

	
	//setters
	void setNextPtr(ListNode* const pNewNext);
	void setmName(string const newName);
	void setmDate(string const newDate);
	void setmData(int const newData);

	//getters
	ListNode* getNextPtr() const;
	string getmDate() const;
	string getmName() const;
	int getmData() const;

private:
	string mDate;
	string mName;
	int mData;
	ListNode* mpNext;
};
//stream operator overloads
std::ostream& operator<< (std::ostream& lhs, const ListNode& rhs);
std::fstream& operator<< (std::fstream& lhs, const ListNode& rhs);
std::fstream& operator>> (std::fstream& lhs, ListNode& rhs);