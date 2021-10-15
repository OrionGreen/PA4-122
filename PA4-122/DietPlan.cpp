#include <string>
#include "Node.hpp"
#include "DietPlan.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
//big three
DietList::DietList(ListNode* pNewHead, ListNode* pNewTail)
{
	this->mpHead = pNewHead;
	this->mpTail = pNewTail;
}


DietList& DietList::operator= (const DietList& rhs) {
	if (this != &rhs) {//self assignment?
		//this pointer - address of instance of object
		mpHead = rhs.mpHead;
		mpTail = rhs.mpTail;
	}
	return *this;
}

DietList::~DietList() {
	ListNode* pCur = mpHead;
	ListNode* pMem = mpHead;

	while (pMem->getNextPtr() != nullptr) {
		pCur = pMem->getNextPtr();
		delete pMem;
		pMem = pCur;
	}

}

//puts node at back of list
bool DietList::endList(ListNode* dayplan) {
	 //replaces makeNode()
	bool success = false;

	if (dayplan != nullptr) {

		//allocated space for a Node 
		success = true;

		//check if empty
		if (this->mpHead == nullptr) {
			//it's empty
			this->mpHead = dayplan;
			this->mpTail = dayplan;
		}
		else
		{
			//it's not empty
			this->mpTail->setNextPtr(dayplan);
			this->mpTail = dayplan;
		}

	}
	return success;
}
//allows editing of node value
bool DietList::editValue() {
	bool success = false;

	ListNode* pMem = this->mpHead;

	cout << "Which Diet Goal number for this week would you like to edit"<< endl;
	int choice = 0;
	int changedDat = 0;
	do {
		cin >> choice;
	} while (choice < 1 || choice > 7);

	if (pMem != nullptr) {
		for (int i = 0; i < choice - 1; i++) {
			pMem = pMem->getNextPtr();
		}
		cout << "Please input a number for data" << endl;
		cin >> changedDat;

		pMem->setmData(changedDat);
		success = true;
	}
	return success;
}
//getters and setters
ListNode* DietList::getmpHead() const {
	return this->mpHead;
}

ListNode* DietList::getmpTail() const {
	return this->mpTail;
}

void DietList::setmpHead(ListNode* const pNewHead) {
	this->mpHead = pNewHead;
}

void DietList::setmpTail(ListNode* const pNewTail) {
	this->mpTail = pNewTail;
}

//stream operator overloads for full lists that call operator overload for single day.
std::ostream& operator<< (std::ostream& lhs, const DietList& rhs) {
	ListNode* pMem = rhs.getmpHead();
	while (pMem != nullptr)
	{
		lhs << *pMem;
		pMem = pMem->getNextPtr();
	}
	return lhs;
}

std::fstream& operator<< (std::fstream& lhs, const DietList& rhs) {
	ListNode* pMem = rhs.getmpHead();
	while (pMem != nullptr)
	{
		lhs << *pMem;
		pMem = pMem->getNextPtr();
	}
	return lhs;
}

std::fstream& operator>> (std::fstream& lhs, DietList& rhs) {
	ListNode* pMem = new ListNode("","",0);

	while (!lhs.eof()) {
		pMem = new ListNode("", "", 0);
		lhs >> *pMem;
		rhs.endList(pMem);
	}
	return lhs;
}