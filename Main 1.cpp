#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter ID Name Marks: ";
    cin >> s.id >> s.name >> s.marks;
    students.push_back(s);
}

void displayStudents() {
    for (auto s : students) {
        cout << s.id << " " << s.name << " " << s.marks << endl;
    }
}

void saveToFile() {
    ofstream file("data.txt");
    for (auto s : students) {
        file << s.id << " " << s.name << " " << s.marks << endl;
    }
    file.close();
}

void loadFromFile() {
    ifstream file("data.txt");
    Student s;
    while (file >> s.id >> s.name >> s.marks) {
        students.push_back(s);
    }
    file.close();
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << s.id << " " << s.name << " " << s.marks << endl;
            return;
        }
    }
    cout << "Not found\n";
}

void sortStudents() {
    for (int i = 0; i < students.size(); i++) {
        for (int j = i + 1; j < students.size(); j++) {
            if (students[i].marks < students[j].marks) {
                swap(students[i], students[j]);
            }
        }
    }
    cout << "Sorted by marks (descending)\n";
}
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted\n";
            return;
        }
    }
    cout << "Student not found\n";
}
void findTopper() {
    if (students.empty()) {
        cout << "No data\n";
        return;
    }

    Student top = students[0];
    for (auto s : students) {
        if (s.marks > top.marks) {
            top = s;
        }
    }

    cout << "Topper: " << top.id << " " << top.name << " " << top.marks << endl;
}
void averageMarks() {
    if (students.empty()) {
        cout << "No data\n";
        return;
    }

    float sum = 0;
    for (auto s : students) {
        sum += s.marks;
    }

    cout << "Average Marks: " << sum / students.size() << endl;
}
int main() {
    loadFromFile();

    int choice;
    while (true) {
        cout << "\n1.Add 2.Display 3.Save 4.Search 5.Sort 6.Exit\n";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) displayStudents();
        else if (choice == 3) saveToFile();
        else if (choice == 4) searchStudent();
        else if (choice == 5) sortStudents();
        else break;
    }
}
