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

	while (choice != 10) {
		choice = displayMenu();

		if (choice == 1) {
			if (!dietFile.is_open()) {
				dietFile.open("dietPlans.txt", std::ios::in);
			}
			loadWeeklyDPlan(dietFile);
			dietFile.close();
			system("cls");
		}

		if (choice == 2) {
			if (!exerFile.is_open()) {
				exerFile.open("exercisePlans.txt", std::ios::in);
			}
			loadWeeklyEPlan(exerFile);
			exerFile.close();
			system("cls");
		}

		if (choice == 3) {
			if (!dietFile.is_open()) {
				dietFile.open("dietPlans.txt", std::ios::out);
			}
			storeWeeklyDPlan(dietFile);
			dietFile.close();
			system("cls");
		}

		if (choice == 4) {
			if (!exerFile.is_open()) {
				exerFile.open("exercisePlans.txt", std::ios::out);
			}
			storeWeeklyEPlan(exerFile);
			exerFile.close();
			system("cls");
		}

		if (choice == 5) {
			displayWeeklyDPlan();

		}

		if (choice == 6) {
			displayWeeklyEPlan();

		}

		if (choice == 7) {
			editGoalDPlan();
			system("cls");
		}

		if (choice == 8) {
			editGoalEPlan();
			system("cls");
		}

		if (choice == 9) {
			if (!exerFile.is_open()) {
				exerFile.open("exercisePlans.txt", std::ios::out);
			}
			if (!dietFile.is_open()) {
				dietFile.open("dietPlans.txt", std::ios::out);
			}
			storeWeeklyDPlan(dietFile);
			storeWeeklyEPlan(exerFile);
			dietFile.close();
			exerFile.close();
			system("cls");
			choice = 10;
		}

		
		}
}
//overloaded stream operation there is no reason for loadDaily plan because I have an overloaded stream operator for the list that basically does the same thing.
void FitnessAppWrapper::loadDailyDPlan(fstream& fileStream) {
	fileStream >> mDList;
}

void FitnessAppWrapper::loadWeeklyDPlan(fstream& fileStream) {
	fileStream >> mDList;

}
//overloaded stream operation, there is really no need for display daily plan because I can just use the overloaded list stream operator but I did it in the "correct way" just to show that I can do it with calling the daily function
void FitnessAppWrapper::displayDailyDPlan(ListNode DNode) {
	cout << DNode;
}

void FitnessAppWrapper::displayWeeklyDPlan() {
	ListNode* pMem = mDList.getmpHead();

	while (pMem != nullptr) {
		displayDailyDPlan(*(pMem));
		pMem = pMem->getNextPtr();
	}
}
//storing plans I can of course just do this with stream operator again on the full list but this is more proper. Or at least what the PA calls for.
bool FitnessAppWrapper::storeDailyDPlan(fstream& fileStream, ListNode DNode) {
	bool success = false;
	if (fileStream.is_open()) {
		fileStream << DNode;
		success = true;
	}
	return success;
}

bool FitnessAppWrapper::storeWeeklyDPlan(fstream& fileStream) {
	ListNode* pMem = mDList.getmpHead();
	bool success = false;
	if (fileStream.is_open()) {
		while (pMem != nullptr) {
			storeDailyDPlan(fileStream, *(pMem));
			pMem = pMem->getNextPtr();
		}
	}
	return success;
}
//edits goal and displays the editted list
void FitnessAppWrapper::editGoalDPlan() {
	mDList.editValue();
	displayWeeklyDPlan();
	Sleep(4000);
}



//same funtions as the other but for the exercise list
void FitnessAppWrapper::loadDailyEPlan(fstream& fileStream) {
	fileStream >> mEList;
}

void FitnessAppWrapper::loadWeeklyEPlan(fstream& fileStream) {
	fileStream >> mEList;

}

void FitnessAppWrapper::displayDailyEPlan(ListNode ENode) {
	cout << ENode;
}

void FitnessAppWrapper::displayWeeklyEPlan() {
	ListNode* pMem = mEList.getmpHead();

	while (pMem != nullptr) {
		displayDailyEPlan(*(pMem));
		pMem = pMem->getNextPtr();
	}
}

bool FitnessAppWrapper::storeDailyEPlan(fstream& fileStream, ListNode ENode) {
	bool success = false;
	if (fileStream.is_open()) {
		fileStream << ENode;
		success = true;
	}
	return success;
}

bool FitnessAppWrapper::storeWeeklyEPlan(fstream& fileStream) {
	ListNode* pMem = mEList.getmpHead();
	bool success = false;
	if (fileStream.is_open()) {
		while (pMem != nullptr) {
			storeDailyEPlan(fileStream, *(pMem));
			pMem = pMem->getNextPtr();
		}
	}
	return success;
}

void FitnessAppWrapper::editGoalEPlan() {
	mEList.editValue();
	displayWeeklyEPlan();
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