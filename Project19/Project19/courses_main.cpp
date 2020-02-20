#include <iostream>
#include "Course.h"
#include "sorting.h"
#include <conio.h>
#include <array>
#include <string>


using namespace std;

void add(Course * course[]);
void edit(Course * course[], int index_choice);
void sort(Course * courses[], int cour_made);
void display_all(Course *courses[], int cour_made)
{
	
	
	for (int i = 0; i < cour_made; i++)
	{
		courses[i]->Display();
	}
};
int main()
{
	Course * courses[10] = { NULL };
	int choice = NULL, cour_made = 0;
	

	do
	{
		cout << endl
			<< "1. Add new course" << endl
			<< "2. Edit an existing course" << endl
			<< "3. Display a course" << endl
			<< "4. List all courses" << endl
			<< "5. Display GPA" << endl
			<< "6. Delete all courses" << endl
			<< "7. Quit" << endl
			<< "Enter a choice: ";
		cin >> choice;

		switch (choice)
		{
			case 1:
				add(courses);
				cour_made++;
				break;
			case 2:
				int edit_choice;
				for (int i = 0; i < cour_made; i++)
				{
					
					cout << endl << 1 + i << ". ";
					courses[i]->Display_title();
				}
				cout << "Which course would you like to edit: ";
				cin >> edit_choice;
				edit(courses, edit_choice);
				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			default:
				cout << endl <<"Please enter a valid option ( 1 - 7)";
		}
		

	} while (choice != 7);


	_getch(); 
	return 0;
}


void edit(Course * course[], int index_choice)
{
	char temp_title[10], temp_grade;
	int temp_unit;
	cin.ignore();
	cout << endl << "Enter new coure name: ";
	cin.getline(temp_title, 10, '\n');
	cout << "Enter a new grade: ";
	cin >> temp_grade;
	cout << "Enter new units: ";
	cin >> temp_unit;
	course[index_choice - 1]->Edit_Course(temp_title, temp_unit, temp_grade);
}


void add(Course * course[])
{
	int empty_index = 0, units, index;
	char title[10], grade;
	bool empty_space = false;
	for (index = 0; index < 10; index++)
	{
		if (course[index] == NULL)
		{
			empty_index = index;
			empty_space = true;
			break;
		}
	}
	if (empty_space)
	{
		cin.ignore();
		cout << endl << "Enter course title (10 char or less): ";
		cin.getline(title, 10, '\n');


		cout << endl << "Enter units for course: ";
		cin >> units;

		cout << endl << "Enter grade for course: ";
		cin >> grade;

		course[index] = new Course(title, units, grade);
		
	}
};
void sort(Course * courses[], int cour_made)
{
	int temppnt;
	int n = cour_made / sizeof(courses), i , j;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			
		}
	}
}