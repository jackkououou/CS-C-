#pragma once

#ifndef courses_functions

#define courses_functions

class Course
{
private:
	char title[10];
	char grade;
	int units;

public:
	Course();
	Course(char title[], int units, char grade);
	void Edit_Course(char title[], int units, char grade);
	void Display();
	void Display_title();
	int Title_cmp();
	~Course();
};


#endif courses_functions.cpp

