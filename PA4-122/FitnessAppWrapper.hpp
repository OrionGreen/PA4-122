#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "DietPlan.hpp"
#include "ExercisePlan.hpp"
#include "Node.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

class FitnessAppWrapper
{
public:
	//declare member functions
	FitnessAppWrapper();

	~FitnessAppWrapper();

	void runApp();

	void loadDailyDPlan(fstream& fileStream);

	void loadWeeklyDPlan(fstream& fileStream);

	void displayDailyDPlan(ListNode DNode);

	void displayWeeklyDPlan();

	bool storeDailyDPlan(fstream& fileStream, ListNode DNode);

	bool storeWeeklyDPlan(fstream& fileStream);

	void editGoalDPlan();


	void loadDailyEPlan(fstream& fileStream);

	void loadWeeklyEPlan(fstream& fileStream);

	void displayDailyEPlan(ListNode ENode);

	void displayWeeklyEPlan();

	bool storeDailyEPlan(fstream& fileStream, ListNode ENode);

	bool storeWeeklyEPlan(fstream& fileStream);

	void editGoalEPlan();
	

	int displayMenu();
private:
	//declare private variables
	DietList mDList;
	ExerList mEList;

};