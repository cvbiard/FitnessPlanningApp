#include "header.hpp"

//Diet plan prototype functions
DietPlan::DietPlan()
{
	//Initialize member variables
	goalCalories = 0;
	name = "testName";
	date = "00/00/0000";
	pNext = nullptr;
	pPrev = nullptr;

}
DietPlan::~DietPlan()
{

}
DietPlan::DietPlan(const DietPlan &source)
{
	//Copy data from source
	goalCalories = source.goalCalories;
	name = source.name;
	date = source.date;

}
int DietPlan::getGoal()
{
	return goalCalories;
}
string DietPlan::getName()
{
	return name;
}
string DietPlan::getDate()
{
	return date;
}
DietPlan* DietPlan::getNext()
{
	return pNext;
}
DietPlan* DietPlan::getPrev()
{
	return pPrev;
}
void DietPlan::setGoal(int newGoal)
{
	goalCalories = newGoal;
}
void DietPlan::setName(string newName)
{
	name = newName;
}
void DietPlan::setDate(string newDate)
{
	date = newDate;
}
void DietPlan::setNext(DietPlan* next)
{
	pNext = next;
}
void DietPlan::setPrev(DietPlan* prev)
{
	pPrev = prev;
}

//Excercise plan prototype functions
ExcercisePlan::ExcercisePlan()
{
	//Initialize member variables
	goalSteps = 0;
	name = "defaultName";
	date = "00/00/0000";

	pNext = NULL;
	pPrev = NULL;
}
ExcercisePlan::~ExcercisePlan()
{

}
ExcercisePlan::ExcercisePlan(const ExcercisePlan& source)
{
	goalSteps = source.goalSteps;
	name = source.name;
	date = source.date;
}
int ExcercisePlan::getSteps()
{
	return goalSteps;
}
string ExcercisePlan::getName()
{
	return name;
}
string ExcercisePlan::getDate()
{
	return date;
}
ExcercisePlan* ExcercisePlan::getNext()
{
	return pNext;
}
ExcercisePlan* ExcercisePlan::getPrev()
{
	return pPrev;
}
void ExcercisePlan::setSteps(int newSteps)
{
	goalSteps = newSteps;
}
void ExcercisePlan::setName(string newName)
{
	name = newName;
}
void ExcercisePlan::setDate(string newDate)
{
	date = newDate;
}
void ExcercisePlan::setNext(ExcercisePlan* next)
{
	pNext = next;
}
void ExcercisePlan::setPrev(ExcercisePlan* prev)
{
	pPrev = prev;
}

//App wrapper prototype functions
FitnessAppWrapper::FitnessAppWrapper()
{
	//Initialize member variables
	dietHead = nullptr;
	excerciseHead = nullptr;
}
FitnessAppWrapper::~FitnessAppWrapper()
{
	delete dietHead;
	delete excerciseHead;
}
DietPlan* FitnessAppWrapper::getDietHead()
{
	return dietHead;
}
ExcercisePlan* FitnessAppWrapper::getExcerciseHead()
{
	return excerciseHead;
}
bool FitnessAppWrapper::isDietEmpty()
{
	if (dietHead == NULL)
	{
		return true;
	}

	return false;
}
bool FitnessAppWrapper::isExcerciseEmpty()
{
	if (excerciseHead == NULL)
	{
		return true;
	}

	return false;
}
bool FitnessAppWrapper::instertDietFront(DietPlan* newPlan)
{
	

		if (dietHead != nullptr)
		{
			dietHead->setPrev(newPlan);
		}

		newPlan->setNext(dietHead);
		dietHead = newPlan;

		return true;


}
bool FitnessAppWrapper::insertExcerciseFront(ExcercisePlan* newPlan)
{

	if (excerciseHead != nullptr)
	{
		excerciseHead->setPrev(newPlan);
	}

	newPlan->setNext(excerciseHead);
	excerciseHead = newPlan;

	return true;
}
void FitnessAppWrapper::printDietPlan()
{
	DietPlan* tempNode = dietHead;

	while (tempNode != nullptr)
	{
		std::cout << tempNode->getName() << endl << tempNode->getGoal() << endl << tempNode->getDate() << endl;
		
		tempNode = tempNode->getNext();

	}
}
void FitnessAppWrapper::printExcercisePlan()
{
	ExcercisePlan* tempNode = excerciseHead;

	while (tempNode != nullptr)
	{
		std::cout << tempNode->getSteps() << endl << tempNode->getName() << endl << tempNode->getDate() << endl;

		tempNode = tempNode->getNext();

	}
}
void FitnessAppWrapper::runApp()
{
	displayMenu();
}
//Manages interfacing with the user
void FitnessAppWrapper::displayMenu()
{
	int exit = 0;
	int result = 0;
	fstream dietPlans;
	fstream excercisePlans;

	dietPlans.open("dietPlans.txt", ios::in | ios::out);
	excercisePlans.open("excercisePlans.txt", ios::in | ios::out);
	while (exit != 1)
	{
		cout << "What would you like to do?" << endl << "1. Load weekly diet plan from file" << endl << "2. Load weekly excercise plan from file" << endl << "3. Write weekly diet plan to file" << endl << "4. Write weekly excercise plan to file" << endl << "5. Display weekly diet plan" << endl << "6. Display weekly excercise plan" << endl << "7. Edit daily diet plan" << endl << "8. Edit daily excercise plan" << endl << "9. Exit" << endl;
		cin >> result;

		switch (result)
		{
		case 1:
			this->loadWeeklyDietPlan(dietPlans);
			break;
		case 2:
			this->loadWeeklyExcercisePlan(excercisePlans);
			break;
		case 3:
			this->storeWeeklyDietPlan(dietPlans);
			break;
		case 4:
			this->storeWeeklyExcercisePlan(excercisePlans);
			break;
		case 5:
			this->printDietPlan();
			break;
		case 6:
			this->printExcercisePlan();
			break;
		case 7:
			this->editDailyDietPlan();
			break;
		case 8:
			this->editDailyExcercisePlan();
			break;
		case 9:
			this->storeWeeklyDietPlan(dietPlans);
			this->storeWeeklyExcercisePlan(excercisePlans);
			dietPlans.close();
			excercisePlans.close();
			exit = 1;
			break;
		}
	}
}
void FitnessAppWrapper::loadDailyDietPlan(fstream& fileStream)
{
	int goal = 0;
	string name;
	string date;
	DietPlan* newPlan = new DietPlan;
	fileStream >> *newPlan;

	this->instertDietFront(newPlan);
	
}
void FitnessAppWrapper::loadWeeklyDietPlan(fstream& fileStream)
{
	for (int i = 0; i < 7; i++)
	{
		this->loadDailyDietPlan(fileStream);
	}
}
void FitnessAppWrapper::loadDailyExcercisePlan(fstream& fileStream)
{
	int goal = 0;
	string name = "";
	string date = "";
	ExcercisePlan* newPlan = new ExcercisePlan;
	fileStream >> *newPlan;

	this->insertExcerciseFront(newPlan);


}
void FitnessAppWrapper::loadWeeklyExcercisePlan(fstream& fileStream)
{
	for (int i = 0; i < 7; i++)
	{
		this->loadDailyExcercisePlan(fileStream);
	}
}
void FitnessAppWrapper::storeWeeklyDietPlan(fstream& fileStream)
{
	DietPlan* tempPlan = dietHead;
	while (tempPlan != nullptr)
	{
		fileStream << tempPlan->getName() << endl << tempPlan->getGoal() << endl << tempPlan->getDate() << endl << endl;
		tempPlan = tempPlan->getNext();
	}
}
void FitnessAppWrapper::storeWeeklyExcercisePlan(fstream& fileStream)
{
	ExcercisePlan* tempPlan = excerciseHead;
	while (tempPlan != nullptr)
	{
		fileStream << tempPlan->getName() << endl << tempPlan->getSteps() << endl << tempPlan->getDate() << endl << endl;
		tempPlan = tempPlan->getNext();
	}
}
void FitnessAppWrapper::editDailyDietPlan()
{
	string result;
	int choice;
	string newString;
	int newVal;
	this->printDietPlan();

	cout << "Which day would you like to edit?" << endl;

	cin >> result;

	DietPlan* tempPlan = dietHead;
	while (tempPlan != nullptr)
	{
		//Compare the desired plan name to the current plan name
		if (result.compare(tempPlan->getName()) == 0)
		{
			cout << "What would you like to edit?" << endl << "1. Name" << endl << "2. Goal" << endl << "3. Date" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter a new name." << endl;
				cin >> newString;
				tempPlan->setName(newString);
				break;
			case 2:
				cout << "Enter a new goal." << endl;
				cin >> newVal;
				tempPlan->setGoal(newVal);
				break;
			case 3:
				cout << "Enter a new date." << endl;
				cin >> newString;
				tempPlan->setDate(newString);
				break;
			}
		}
		tempPlan = tempPlan->getNext();
	}
}
void FitnessAppWrapper::editDailyExcercisePlan()
{
	string result;
	int choice;
	string newString;
	int newVal;
	this->printExcercisePlan();

	cout << "Which day would you like to edit?" << endl;

	cin >> result;

	ExcercisePlan* tempPlan = excerciseHead;
	while (tempPlan != nullptr)
	{
		//Compare the desired plan name to the current plan name
		if (result.compare(tempPlan->getName()) == 0)
		{
			cout << "What would you like to edit?" << endl << "1. Name" << endl << "2. Goal" << endl << "3. Date" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter a new name." << endl;
				cin >> newString;
				tempPlan->setName(newString);
				break;
			case 2:
				cout << "Enter a new goal." << endl;
				cin >> newVal;
				tempPlan->setSteps(newVal);
				break;
			case 3:
				cout << "Enter a new date." << endl;
				cin >> newString;
				tempPlan->setDate(newString);
				break;
			}
		}
		tempPlan = tempPlan->getNext();
	}
}
fstream& operator >> (fstream& in, DietPlan &plan)
{
	int result = 0;
	string str;
	string date;
	in >> str >> result >> date;
	plan.setGoal(result);
	plan.setDate(date);
	plan.setName(str);
	cout << plan.getGoal() << endl << plan.getDate() << endl << plan.getName() << endl;;
	return in;
}
fstream& operator >> (fstream& in, ExcercisePlan& plan)
{
	int result = 0;
	string str;
	string date;
	in >> str >> result >> date;
	plan.setSteps(result);
	plan.setDate(date);
	plan.setName(str);
	cout << plan.getSteps() << endl << plan.getDate() << endl << plan.getName() << endl;;
	return in;
}