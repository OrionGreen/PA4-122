#include"FitnessAppWrapper.hpp"
//nothing in constructor or destructor because everything is callled and taken out of scope within the run function so no need for any data to start or end with.
FitnessAppWrapper::FitnessAppWrapper() {
}

FitnessAppWrapper::~FitnessAppWrapper() {
}
//runs the app
//I chose to have each time the file is open in a different form to close and open to make sure you can swap between functions correctly
void FitnessAppWrapper::runApp() {
	int choice = 0;
	fstream dietFile;
	fstream exerFile;
	DietList dList;
	ExerList eList;

	while (choice != 10) {
		choice = displayMenu();

		if (choice == 1) {
			if (!dietFile.is_open()) {
				dietFile.open("dietPlans.txt", std::ios::in);
			}
			loadWeeklyPlan(dietFile, dList);
			dietFile.close();
			system("cls");
		}

		if (choice == 2) {
			if (!exerFile.is_open()) {
				exerFile.open("exercisePlans.txt", std::ios::in);
			}
			loadWeeklyPlan(exerFile, eList);
			exerFile.close();
			system("cls");
		}

		if (choice == 3) {
			if (!dietFile.is_open()) {
				dietFile.open("dietPlans.txt", std::ios::out);
			}
			storeWeeklyPlan(dietFile, dList);
			dietFile.close();
			system("cls");
		}

		if (choice == 4) {
			if (!exerFile.is_open()) {
				exerFile.open("exercisePlans.txt", std::ios::out);
			}
			storeWeeklyPlan(exerFile, eList);
			exerFile.close();
			system("cls");
		}

		if (choice == 5) {
			displayWeeklyPlan(dList);

		}

		if (choice == 6) {
			displayWeeklyPlan(eList);

		}

		if (choice == 7) {
			editGoalPlan(dList);
			system("cls");
		}

		if (choice == 8) {
			editGoalPlan(eList);
			system("cls");
		}

		if (choice == 9) {
			if (!exerFile.is_open()) {
				exerFile.open("exercisePlans.txt", std::ios::out);
			}
			if (!dietFile.is_open()) {
				dietFile.open("dietPlans.txt", std::ios::out);
			}
			storeWeeklyPlan(dietFile, dList);
			storeWeeklyPlan(exerFile, eList);
			dietFile.close();
			exerFile.close();
			system("cls");
			choice = 10;
		}

		
		}
}
//overloaded stream operation there is no reason for loadDaily plan because I have an overloaded stream operator for the list that basically does the same thing.
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ListNode& DNode) {
	fileStream >> DNode;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietList& DList) {
	ListNode* pMem = new ListNode("", "", 0);
	mDList.setmpHead(pMem);
	mDList.setmpTail(pMem);

	while (!fileStream.eof()) {
		loadDailyPlan(fileStream, *(pMem));
		mDList.endList(pMem);
		pMem = new ListNode("", "", 0);
	}
	delete pMem;

}
//overloaded stream operation, there is really no need for display daily plan because I can just use the overloaded list stream operator but I did it in the "correct way" just to show that I can do it with calling the daily function
void FitnessAppWrapper::displayDailyPlan(ListNode DNode, DietList& DList) {
	cout << DNode;
}

void FitnessAppWrapper::displayWeeklyPlan(DietList& DList) {
	ListNode* pMem = mDList.getmpHead();

	while (pMem != nullptr) {
		displayDailyPlan(*(pMem), mDList);
		pMem = pMem->getNextPtr();
	}
}
//storing plans I can of course just do this with stream operator again on the full list but this is more proper. Or at least what the PA calls for.
bool FitnessAppWrapper::storeDailyPlan(fstream& fileStream, ListNode DNode, DietList& DList) {
	bool success = false;
	if (fileStream.is_open()) {
		fileStream << DNode;
		success = true;
	}
	return success;
}

bool FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, DietList& DList) {
	ListNode* pMem = mDList.getmpHead();
	bool success = false;
	if (fileStream.is_open()) {
		while (pMem != nullptr) {
			storeDailyPlan(fileStream, *(pMem), mDList);
			pMem = pMem->getNextPtr();
		}
	}
	return success;
}
//edits goal and displays the editted list
void FitnessAppWrapper::editGoalPlan(DietList& DList) {
	mDList.editValue();
	displayWeeklyPlan(mDList);
	Sleep(4000);
}



//same funtions as the other but for the exercise list

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExerList& EList) {
	ListNode* pMem = new ListNode("", "", 0);
	mEList.setmpHead(pMem);
	mEList.setmpTail(pMem);

	while (!fileStream.eof()) {
		loadDailyPlan(fileStream, *(pMem));
		mEList.endList(pMem);
		pMem = new ListNode("", "", 0);
	}
	delete pMem;
}

void FitnessAppWrapper::displayDailyPlan(ListNode ENode, ExerList& EList) {
	cout << ENode;
}

void FitnessAppWrapper::displayWeeklyPlan(ExerList& EList) {
	ListNode* pMem = mEList.getmpHead();

	while (pMem != nullptr) {
		displayDailyPlan(*(pMem), mEList);
		pMem = pMem->getNextPtr();
	}
}

bool FitnessAppWrapper::storeDailyPlan(fstream& fileStream, ListNode ENode, ExerList& EList) {
	bool success = false;
	if (fileStream.is_open()) {
		fileStream << ENode;
		success = true;
	}
	return success;
}

bool FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, ExerList& EList) {
	ListNode* pMem = mEList.getmpHead();
	bool success = false;
	if (fileStream.is_open()) {
		while (pMem != nullptr) {
			storeDailyPlan(fileStream, *(pMem), mEList);
			pMem = pMem->getNextPtr();
		}
	}
	return success;
}

void FitnessAppWrapper::editGoalPlan(ExerList& EList) {
	mEList.editValue();
	displayWeeklyPlan(mEList);
	Sleep(4000);
}

//display menu and then choose what they want to do.
int FitnessAppWrapper::displayMenu() {
	int choice = 0;
	cout << "What would you like to do?" << endl;
	cout << "1.Load weekly diet plan from file." << endl;
	cout << "2.Load weekly exercise plan from file." << endl;
	cout << "3.Store weekly diet plan to file." << endl;
	cout << "4.Store weekly exercise plan to file." << endl;
	cout << "5.Display weekly diet plan to screen." << endl;
	cout << "6.Display weekly exercise plan to screen." << endl;
	cout << "7.Edit daily diet plan." << endl;
	cout << "8.Edit daily exercise plan." << endl;
	cout << "9.Exit." << endl;

	do {
		cin >> choice;
	} while (choice < 1 || choice > 9);

	return choice;
}