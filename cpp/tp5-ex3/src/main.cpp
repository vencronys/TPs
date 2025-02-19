#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

enum LEVEL {
    FIRST_YEAR = 1,
    SECOND_YEAR,
    THIRD_YEAR,
    FOURTH_YEAR,
    FIFTH_YEAR,
};

enum SPECIALITY {
    CP = 1,
    GI,
    IG,
    GSI,
};

struct Student {
    static int ID_COUNTER;
    int id;
    string name;
    string familyName;
    string address;
    LEVEL level;
    SPECIALITY speciality;
};

void CopyStudentsArray(Student *, Student *, const int &);
void FillStudent(Student &);
void AddStudent(Student *&, int &);
int SearchStudentById(Student *, const int &, const int &);
int SearchStudentByName(Student *, const int &, const string &);
int SearchStudentByFamilyName(Student *, const int &, const string &);
int SearchStudentByAddress(Student *, const int &, const string &);
int SearchStudentByLevel(Student *, const int &, const LEVEL &);
int SearchStudentBySpeciality(Student *, const int &, const SPECIALITY &);
int SearchStudent(Student *, const int &);
void ModifyStudent(Student *, const int &);
void DeleteStudent(Student *&, int &);
void DisplayStudent(const Student &);
void DisplayStudentWithSearch(Student *, const int &);
void DisplayStudents(Student *, const int &);

int Student::ID_COUNTER = 0;

int main() {
    Student *students = nullptr;
    int size = 0;
    char choice;
    do {
        cout << "1. Add Student\n"
             << "2. Modify Student\n"
             << "3. Delete Student\n"
             << "4. Display Student\n"
             << "5. Display Students\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                AddStudent(students, size);
                break;
            case '2':
                ModifyStudent(students, size);
                break;
            case '3':
                DeleteStudent(students, size);
                break;
            case '4':
                DisplayStudentWithSearch(students, size);
                break;
            case '5':
                DisplayStudents(students, size);
                break;
            case '6':
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != '6');
    return 0;
}

void CopyStudentsArray(Student *dest, Student *src, const int &size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void FillStudent(Student &student) {
    int temp;
    cout << "Enter data for the student:\n";
    student.id = ++Student::ID_COUNTER;
    cout << "Name: ";
    cin >> student.name;
    cout << "Family Name: ";
    cin >> student.familyName;
    cout << "Address: ";
    cin >> student.address;
    cout << "Level:\n"
         << "1. First Year\n"
         << "2. Second Year\n"
         << "3. Third Year\n"
         << "4. Fourth Year\n"
         << "5. Fifth Year\n"
         << "Enter Level: ";
    cin >> temp;
    student.level = static_cast<LEVEL>(temp);
    cout << "Speciality:\n"
         << "1. CP\n"
         << "2. GI\n"
         << "3. IG\n"
         << "4. GSI\n"
         << "Enter Speciality: ";
    cin >> temp;
    student.speciality = static_cast<SPECIALITY>(temp);
}

void AddStudent(Student *&students, int &size) {
    Student *temp = new Student[size + 1];
    if (students != nullptr) {
        CopyStudentsArray(temp, students, size);
        delete[] students;
    }
    FillStudent(temp[size]);
    students = temp;
    size++;
}


int SearchStudentById(Student *students, const int &size, const int &id) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

int SearchStudentByName(Student *students, const int &size, const string &name) {
    for (int i = 0; i < size; i++) {
        if (students[i].name == name) {
            return i;
        }
    }
    return -1;
}

int SearchStudentByFamilyName(Student *students, const int &size, const string &familyName) {
    for (int i = 0; i < size; i++) {
        if (students[i].familyName == familyName) {
            return i;
        }
    }
    return -1;
}

int SearchStudentByAddress(Student *students, const int &size, const string &address) {
    for (int i = 0; i < size; i++) {
        if (students[i].address == address) {
            return i;
        }
    }
    return -1;
}

int SearchStudentByLevel(Student *students, const int &size, const LEVEL &level) {
    for (int i = 0; i < size; i++) {
        if (students[i].level == level) {
            return i;
        }
    }
    return -1;
}

int SearchStudentBySpeciality(Student *students, const int &size, const SPECIALITY &speciality) {
    for (int i = 0; i < size; i++) {
        if (students[i].speciality == speciality) {
            return i;
        }
    }
    return -1;
}

int SearchStudent(Student *students, const int &size) {
    char choice;
    cout << "Search by:\n"
         << "1. ID\n"
         << "2. Name\n"
         << "3. Family Name\n"
         << "4. Address\n"
         << "5. Level\n"
         << "6. Speciality\n"
         << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case '1': {
            int id;
            cout << "Enter ID: ";
            cin >> id;
            return SearchStudentById(students, size, id);
        }
        case '2': {
            string name;
            cout << "Enter Name: ";
            cin >> name;
            return SearchStudentByName(students, size, name);
        }
        case '3': {
            string familyName;
            cout << "Enter Family Name: ";
            cin >> familyName;
            return SearchStudentByFamilyName(students, size, familyName);
        }
        case '4': {
            string address;
            cout << "Enter Address: ";
            cin >> address;
            return SearchStudentByAddress(students, size, address);
        }
        case '5': {
            int level;
            cout << "Enter Level:\n"
                 << "1. First Year\n"
                 << "2. Second Year\n"
                 << "3. Third Year\n"
                 << "4. Fourth Year\n"
                 << "5. Fifth Year\n"
                 << "Enter Level: ";
            cin >> level;
            return SearchStudentByLevel(students, size, static_cast<LEVEL>(level));
        }
        case '6': {
            int speciality;
            cout << "Enter Speciality:\n"
                 << "1. CP\n"
                 << "2. GI\n"
                 << "3. IG\n"
                 << "Enter Speciality: ";
            cin >> speciality;
            return SearchStudentBySpeciality(students, size, static_cast<SPECIALITY>(speciality));
        }
        default:
            return -1;
    }
}

void ModifyStudent(Student *students, const int &size) {
    int index = SearchStudent(students, size);
    if (index == -1) {
        cout << "Student not found!" << endl;
        return;
    }
    FillStudent(students[index]);
}

void DeleteStudent(Student *&students, int &size) { // Pass by reference
    if (size == 0) return;
    Student *temp = new Student[size - 1];
    int index = SearchStudent(students, size);
    if (index == -1) {
        cout << "Student not found!" << endl;
        delete[] temp;
        return;
    }
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) temp[j++] = students[i];
    }
    delete[] students;
    students = temp;
    size--;
}


void DisplayStudent(const Student &student) {
    cout << "Student ID: " << student.id << endl;
    cout << "Name: " << student.name << endl;
    cout << "Family Name: " << student.familyName << endl;
    cout << "Address: " << student.address << endl;
    cout << "Level: ";
    switch (student.level) {
        case FIRST_YEAR:
            cout << "First Year" << endl;
            break;
        case SECOND_YEAR:
            cout << "Second Year" << endl;
            break;
        case THIRD_YEAR:
            cout << "Third Year" << endl;
            break;
        case FOURTH_YEAR:
            cout << "Fourth Year" << endl;
            break;
        case FIFTH_YEAR:
            cout << "Fifth Year" << endl;
            break;
    }
    cout << "Speciality: ";
    switch (student.speciality) {
        case CP:
            cout << "CP" << endl;
            break;
        case GI:
            cout << "GI" << endl;
            break;
        case IG:
            cout << "IG" << endl;
            break;
        case GSI:
            cout << "GSI" << endl;
            break;
    }
}

void DisplayStudentWithSearch(Student *students, const int &size) {
    int studentIndex = SearchStudent(students, size);
    if (studentIndex == -1) {
        cout << "Student not found!" << endl;
        return;
    }
    DisplayStudent(students[studentIndex]);
}

void DisplayStudents(Student *students, const int &size) {
    if (size == 0) {
        cout << "No students to display!" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << endl;
        DisplayStudent(students[i]);
    }
}
