#include <cctype>
#include <cstring>
#include <iostream>
#include <limits>
#include <strings.h>

using std::cin;
using std::cout;
using std::endl;

struct Student {
    char name[20];
    char familyName[20];
    int age;
    int CIN;
};

struct Date {
    int day;
    char month[10];
    int year;
};

void FillStudent(Student &);
void DisplayStudent(const Student &);
bool CompareStudent(const Student &, const Student &);
void UpdateStudent(Student &);
void InitStudents(Student *, const int &);
void DisplayStudents(const Student *, const int &);
int GetAverageAge(Student *, const int &);
void FillDate(Date &);
void DisplayDate(const Date &);
int GetMonthNumber(const char *);
int CompareDate(const Date &, const Date &);

int main() {
    /*Student student1, student2;*/
    /*cout << "Student 1:" << endl;*/
    /*FillStudent(student1);*/
    /*DisplayStudent(student1);*/
    /*cout << "Student 2:" << endl;*/
    /*FillStudent(student2);*/
    /*DisplayStudent(student2);*/
    /*cout << "Are the two students equal? "*/
    /*    << (CompareStudent(student1, student2) ? "Yes" : "No") << endl;*/
    /*cout << "Updating student 1:" << endl;*/
    /*UpdateStudent(student1);*/
    /*DisplayStudent(student1);*/
    /*Student *students = new Student[3];*/
    /*InitStudents(students, 3);*/
    /*DisplayStudents(students, 3);*/
    /*cout << "Average age: " << GetAverageAge(students, 3) << endl;*/


    Date date1, date2;
    FillDate(date1);
    FillDate(date2);
    DisplayDate(date1);
    DisplayDate(date2);
    if (CompareDate(date1, date2) == 0) {
        cout << "The two dates are equal" << endl;
    } else if (CompareDate(date1, date2) == 1) {
        cout << "Date 1 is greater than date 2" << endl;
    } else {
        cout << "Date 1 is smaller than date 2" << endl;
    }
    return 0;
}

void FillStudent(Student &student) {
    cout << "Enter the student's name: ";
    cin.getline(student.name, 20);
    cout << "Enter the student's family name: ";
    cin.getline(student.familyName, 20);
    cout << "Enter the student's age: ";
    cin >> student.age;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter the student's CIN: ";
    cin >> student.CIN;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void DisplayStudent(const Student &student) {
    cout << "Name: " << student.name << endl;
    cout << "Family Name: " << student.familyName << endl;
    cout << "Age: " << student.age << endl;
    cout << "CIN: " << student.CIN << endl;
}

bool CompareStudent(const Student &student1, const Student &student2) {
    return (strcmp(student1.name, student2.name) == 0 &&
    strcmp(student1.familyName, student2.familyName) == 0 &&
    student1.age == student2.age && student1.CIN == student2.CIN);
}

void UpdateStudent(Student &student) { FillStudent(student); }

void InitStudents(Student *students, const int &size) {
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        FillStudent(students[i]);
    }
}

void DisplayStudents(const Student *students, const int &size) {
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        DisplayStudent(students[i]);
    }
}

int GetAverageAge(Student *students, const int &size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += students[i].age;
    }
    return sum / size;
}

void FillDate(Date &date) {
    cout << "Enter the day: ";
    cin >> date.day;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do {
        cout << "Enter the month: ";
        cin.getline(date.month, 10);
    } while (GetMonthNumber(date.month) == -1);
    cout << "Enter the year: ";
    cin >> date.year;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void DisplayDate(const Date &date) {
    cout << "Day: " << date.day << endl;
    cout << "Month: " << date.month << endl;
    cout << "Year: " << date.year << endl;
}

int GetMonthNumber(const char *month) {
    const char *MONTHS[] = {"January",   "February", "March",    "April",
                            "May",       "June",     "July",     "August",
                            "September", "October",  "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(month, MONTHS[i]) == 0) {
            return i + 1;
        }
    }
    return -1;
}

int CompareDate(const Date &date1, const Date &date2) {
    if (date1.year == date2.year && GetMonthNumber(date1.month) == GetMonthNumber(date2.month) && date1.day == date2.day) {
        return 0;
    }
    if (date1.year > date2.year) {
        return 1;
    } else return -1;
    if (GetMonthNumber(date1.month) > GetMonthNumber(date2.month)) {
        return 1;
    } else return -1;
    if (date1.day > date2.day) {
        return 1;
    } else return -1;
}
