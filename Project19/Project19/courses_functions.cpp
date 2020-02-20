#include <iostream>
#include "Course.h"
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;
Course::Course()
{
	strcpy_s(title, "N/A");
	units = 0;
	grade = 'Z';
};
Course::Course(char title_Entry[], int units_Entry, char grade_Entry)
{
	strcpy_s(title, title_Entry);
	units = units_Entry;
	grade = grade_Entry;

	cout << endl << "Course added!" << endl;
};
void Course::Edit_Course(char title_Entry[], int units_Entry, char grade_Entry)
{
	strcpy_s(title, title_Entry);
	units = units_Entry;
	grade = grade_Entry;
	cout << endl << "Course added!" << endl;
};
void Course::Display()
{
	
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Course title: ";
	int index = 0;
	int titlelen = strlen(title);
	while (index < titlelen)
	{
		cout << title[index];
		index++;
	}
	cout << endl << "Course units: ";
	cout << units << endl;
	cout << "Course grade: ";
	cout << grade << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
}
void Course::Display_title()
{
	cout << "Course title: ";
	int index = 0;
	int titlelen = strlen(title);
	while (index < titlelen)
	{
		cout << title[index];
		index++;
	}
}
 int Title_cmp(Course& a, Course& b)
{
	strcmp(a->title , b)
}
Course::~Course()
{

};