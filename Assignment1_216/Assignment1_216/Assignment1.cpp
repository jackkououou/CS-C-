j//Program Name: Assignment 1
//Programmer: Tigran Marashlian
//Date: 3/1/2020
#include <iostream>
#include <conio.h>
using namespace std;
class Course
{
private:
	char title[10];
	int numOfUnits;
	char grade;
public:
	Course();
	int add(Course *coursePtrs[10]);
	void edit(Course *coursePtrs[10], int count);
	void sort(Course *coursePtrs[], int count);
	void bin_search(Course *coursePtrs[], char *searchCourse, int count);
	void swapPtrs(Course** pointer1, Course** pointer2);
	void display(Course *coursePtrs[10], int count) const;
	void display_GPA(Course *coursePtrs[10], int count);
	double points(char grade);
	void delete_course(Course *coursePtrs[10], int count);
	//void delete(Course *coursePtrs[10], int count);
	~Course();
};

int main()
{
	Course *coursePtrs[10];
	char courseSearch[10] = { NULL };
	char answer;
	int menuAnswer, count;
	do
	{
		cout << "Select one of the following actions." << endl;
		cout << "1. Add New Course" << endl << "2. Edit an existing course" << endl << "3. Display a course" <<
			endl << "4. List all courses" << endl << "5. Display GPA" << endl << "6. Delete all courses" << endl << "7. Quit" << endl;
		cin >> menuAnswer;

		if (menuAnswer == 1)
		{
			count = coursePtrs[10]->add(coursePtrs);
		}

		if (menuAnswer == 2)
		{
			coursePtrs[10]->edit(coursePtrs, count);
		}

		if (menuAnswer == 3)
		{
			coursePtrs[10]->sort(coursePtrs, count);
			cout << "Enter a course to search for." << endl;
			cin.ignore();
			cin.getline(courseSearch, sizeof(courseSearch), '\n');
			coursePtrs[10]->bin_search(coursePtrs, courseSearch, count);
		}

		if (menuAnswer == 4)
		{
			coursePtrs[10]->sort(coursePtrs, count);
			coursePtrs[10]->display(coursePtrs, count);
		}

		if (menuAnswer == 5)
		{
			coursePtrs[10]->display_GPA(coursePtrs, count);
		}

		if (menuAnswer == 6)
		{
			coursePtrs[10]->delete_course(coursePtrs, count);
		}

		if (menuAnswer == 7)
		{

		}

		cout << "Show menu again? (Y/N)" << endl;
		cin >> answer;
	} while (answer == 'Y' || answer == 'y');


	cout << "Press any key to continue." << endl;
	_getch();
	return 0;
}

Course::Course()
{
	Course *coursePtrs[10] = { NULL };
}

int Course::add(Course *coursePtrs[10])
{
	int count = 0;
	char reply;
	for (int i = 0; i < 10; i++)
	{
		coursePtrs[i] = new Course;
		cout << "Enter course title." << endl;
		cin.ignore();
		cin.getline(coursePtrs[i]->title, sizeof(coursePtrs[i]->title), '\n');
		cout << "Enter units." << endl;
		cin >> coursePtrs[i]->numOfUnits;
		cout << "Enter grade." << endl;
		cin >> coursePtrs[i]->grade;
		count++;
		cout << "Enter another course? (y/n)" << endl;
		cin >> reply;
		if (reply == 'n' || reply == 'N')
			break;
	}
	return count;
}

void Course::edit(Course *coursePtrs[10], int count)
{
	int editAnswer;
	cout << "Select the course to edit." << endl;
	for (int i = 0; i < count; i++)
		cout << i + 1 << "." << coursePtrs[i]->title << endl;
	cin >> editAnswer;

	cout << "Editing " << coursePtrs[editAnswer - 1]->title << ", " << coursePtrs[editAnswer - 1]->numOfUnits << " units, grade: " << coursePtrs[editAnswer - 1]->grade << endl;
	cout << "Enter course name." << endl;
	cin.ignore();
	cin.getline(coursePtrs[editAnswer - 1]->title, sizeof(coursePtrs[editAnswer - 1]->title), '\n');
	cout << "Enter units." << endl;
	cin >> coursePtrs[editAnswer - 1]->numOfUnits;
	cout << "Enter grade." << endl;
	cin >> coursePtrs[editAnswer - 1]->grade;
	cout << "Course modified." << endl;

}

void Course::sort(Course *coursePtrs[], int count)
{
	bool swapped;
	do
	{
		swapped = false;
		for (int i = 0; i < count - 1; i++)
		{
			if (strcmp(coursePtrs[i]->title, coursePtrs[i + 1]->title) > 0)
			{
				swapPtrs(&coursePtrs[i], &coursePtrs[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);

}

void Course::swapPtrs(Course** pointer1, Course** pointer2)
{
	Course* tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}

void Course::bin_search(Course *coursePtrs[], char *searchCourse, int count)
{
	int mid;
	int index = -1;
	int first = 0, last = count - 1;
	bool found = false;

	while (!found && first <= last)
	{
		mid = (first + last) / 2;
		if (searchCourse == coursePtrs[mid]->title)
		{
			found = true;
			index = mid;
		}
		else if (searchCourse > coursePtrs[mid]->title)
			first = mid + 1;
		else
			last = mid - 1;
	}
	if (index == -1)
		cout << "Course not found." << endl;
	else
		cout << coursePtrs[mid]->title << ", " << coursePtrs[mid]->numOfUnits << ", " << coursePtrs[mid]->grade << endl;

}

void Course::display(Course *coursePtrs[10], int count) const
{
	for (int i = 0; i < count; i++)
	{
		cout << coursePtrs[i]->title << ", " << coursePtrs[i]->numOfUnits << ", " << coursePtrs[i]->grade << endl;
	}
}

void Course::display_GPA(Course *coursePtrs[10], int count)
{
	double GPA;
	double pointSum = 0;
	double unitSum = 0;

	for (int i = 0; i < count; i++)
	{
		pointSum += (coursePtrs[i]->numOfUnits) * (points(coursePtrs[i]->grade));
		unitSum += coursePtrs[i]->numOfUnits;
	}
	GPA = pointSum / unitSum;
	cout << "GPA = " << GPA << endl;
}

double Course::points(char grade)
{
	if (grade == 'A')
		return 4.0;
	if (grade == 'B')
		return 3.0;
	if (grade == 'C')
		return 2.0;
	if (grade == 'D')
		return 1.0;
	if (grade == 'F')
		return 0.0;
}

void Course::delete_course(Course *coursePtrs[10], int count)
{
	for (int i = 0; i < count; i++)
	{
		delete coursePtrs[i];
		coursePtrs[i] = { NULL };
	}
}

Course::~Course()
{

}