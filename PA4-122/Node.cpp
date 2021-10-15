#include "Node.hpp"
//big three
ListNode::ListNode(string newDate, string newName, int newData) {
	this->mData = newData;
	this->mDate = newDate;
	this->mName = newName;
	this->mpNext = nullptr;
}



ListNode& ListNode::operator= (const ListNode& rhs) {

	if (this != &rhs) {//self assignment?
		//this pointer - address of instance of object
		mpNext = rhs.mpNext;
		mDate = rhs.mDate;
		mName = rhs.mName;
		mData = rhs.mData;
	}

	return *this;
}

ListNode::~ListNode() {
}

//setters
void ListNode::setNextPtr(ListNode* const pNewNext) {
	this->mpNext = pNewNext;
}

void ListNode::setmName(string const newName) {
	this->mName = newName;
}

void ListNode::setmDate(string const newDate) {
	this->mDate = newDate;
}

void ListNode::setmData(int const newData) {
	this->mData = newData;
}

//getters
ListNode* ListNode::getNextPtr() const {
	return this->mpNext;
}

string ListNode::getmDate() const{
	return this->mDate;
}

string ListNode::getmName() const{
	return this->mName;
}

int ListNode::getmData() const{
	return this->mData;
}
//operator overloading
std::ostream& operator<< (std::ostream& lhs, const ListNode& rhs) { 
	lhs <<"Plan Name: " << rhs.getmName() << endl << "Goal: " << rhs.getmData() << endl << "Date: " << rhs.getmDate() << endl;
	return lhs;
}

std::fstream& operator<< (std::fstream& lhs, const ListNode& rhs) {
	lhs << rhs.getmName() << endl << rhs.getmData() << endl << rhs.getmDate() << endl << endl;
	return lhs;
}

std::fstream& operator>> (std::fstream& lhs, ListNode& rhs) {
	char data[100] = "";
	lhs.getline(data, 100);
	rhs.setmName(data);
	int num = 0;
	lhs >> num;
	rhs.setmData(num);
	lhs.getline(data, 100);
	lhs.getline(data, 100);
	rhs.setmDate(data);
	lhs.getline(data, 100);
	return lhs;
}
