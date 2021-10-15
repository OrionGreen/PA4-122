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

	void loadDailyPlan(fstream& fileStream, ListNode& DNode);

	void loadWeeklyPlan(fstream& fileStream, DietList& DList);

	void displayDailyPlan(ListNode DNode, DietList& DList);

	void displayWeeklyPlan(DietList& DList);

	bool storeDailyPlan(fstream& fileStream, ListNode DNode, DietList& DList);

	bool storeWeeklyPlan(fstream& fileStream, DietList& DList);

	void editGoalPlan(DietList& DList);


	void loadWeeklyPlan(fstream& fileStream, ExerList& EList);

	void displayDailyPlan(ListNode ENode, ExerList& EList);

	void displayWeeklyPlan(ExerList& EList);

	bool storeDailyPlan(fstream& fileStream, ListNode ENode, ExerList& EList);

	bool storeWeeklyPlan(fstream& fileStream, ExerList& EList);

	void editGoalPlan(ExerList& EList);
	

	int displayMenu();
private:
	//declare private variables
	DietList mDList;
	ExerList mEList;

};