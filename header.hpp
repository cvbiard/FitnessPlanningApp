#pragma once

#include <iostream>
#include <fstream>
#include <string>

//Declare namespaces
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::string;
using namespace std;

//Node for the diet plan list
class DietPlan
{
public:

	//Constructor
	DietPlan();

	//Destructor
	~DietPlan();

	//Copy constructor
	DietPlan(const DietPlan& source);

	//Getters
	int getGoal();
	string getName();
	string getDate();

	DietPlan* getNext();
	DietPlan* getPrev();

	//Setters
	void setGoal(int newGoal);
	void setName(string newName);
	void setDate(string newName);

	void setNext(DietPlan* next);
	void setPrev(DietPlan* prev);


 private:

	int goalCalories;
	string name;
	string date;

	DietPlan* pNext;
	DietPlan* pPrev;
};

//Node for the excercise plan list
class ExcercisePlan
{
public:

	//Constructor
	ExcercisePlan();

	//Destructor
	~ExcercisePlan();

	//Copy Constructor
	ExcercisePlan(const ExcercisePlan& source);

	//Getters
	int getSteps();
	string getName();
	string getDate();

	ExcercisePlan* getNext();
	ExcercisePlan* getPrev();


	//Setters
	void setSteps(int newSteps);
	void setName(string newName);
	void setDate(string newName);

	void setNext(ExcercisePlan* next);
	void setPrev(ExcercisePlan* prev);

private:

	int goalSteps;
	string name;
	string date;

	ExcercisePlan* pNext;
	ExcercisePlan* pPrev;
};

//The list class, contains linked nodes for both diet and exercise plans
class FitnessAppWrapper
{
public:

	//Constructor
	FitnessAppWrapper();

	//Destructor
	~FitnessAppWrapper();


	//Getters
	DietPlan* getDietHead();
	ExcercisePlan* getExcerciseHead();

	//Check empty
	bool isDietEmpty();
	bool isExcerciseEmpty();

	//Insert node
	bool instertDietFront(DietPlan* newPlan);
	bool insertExcerciseFront(ExcercisePlan* newPlan);


	//Print
	void printDietPlan();
	void printExcercisePlan();

	//Wrapper functions
	void runApp();
	void displayMenu();

	//Load daily plans from file
	void loadDailyDietPlan(fstream& fileStream);
	void loadDailyExcercisePlan(fstream& fileStream);

	//Load weekly plans from file
	void loadWeeklyDietPlan(fstream& fileStream);
	void loadWeeklyExcercisePlan(fstream& fileStream);

	//Store weekly plans in file
	void storeWeeklyDietPlan(fstream& fileStream);
	void storeWeeklyExcercisePlan(fstream& fileStream);

	//Edit daily plans in list
	void editDailyDietPlan();
	void editDailyExcercisePlan();
	
private:

	DietPlan* dietHead;
	ExcercisePlan* excerciseHead;

};

//Stream insertion operator overload
fstream& operator >> (fstream& in, DietPlan& plan);
fstream& operator >> (fstream& in, ExcercisePlan& plan);