#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <direct.h>  // For _getcwd() on Windows
#include <string>
using namespace std;

// Course structure
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

// Function to load course data from file
void loadCourses(map<string, Course>& courses, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Unable to open file at " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseTitle, prerequisite;
        vector<string> prerequisites;

        getline(ss, courseNumber, ',');
        getline(ss, courseTitle, ',');
        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }

        courses[courseNumber] = { courseNumber, courseTitle, prerequisites };
    }
    file.close();
    cout << "Data successfully loaded!" << endl;
}

// Function to print course list in alphanumeric order
void printCourseList(const map<string, Course>& courses) {
    cout << "Here is a sample schedule:" << endl;
    for (const auto& entry : courses) {
        cout << entry.second.courseNumber << ", " << entry.second.courseTitle << endl;
    }
}

// Function to print course details
void printCourseDetails(const map<string, Course>& courses, string courseNumber) {
    transform(courseNumber.begin(), courseNumber.end(), courseNumber.begin(), ::toupper);
    auto it = courses.find(courseNumber);
    if (it != courses.end()) {
        cout << it->second.courseNumber << ", " << it->second.courseTitle << endl;
        if (!it->second.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (size_t i = 0; i < it->second.prerequisites.size(); ++i) {
                cout << it->second.prerequisites[i];
                if (i < it->second.prerequisites.size() - 1) cout << ", ";
            }
            cout << endl;
        }
        else {
            cout << "Prerequisites: None" << endl;
        }
    }
    else {
        cout << "Course not found." << endl;
    }
}

// Main menu function
void displayMenu() {
    cout << "\nWelcome to the course planner." << endl;
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
}

int main() {
    map<string, Course> courses;
    string filename = "\\\\apporto.com\\dfs\\SNHU\\Users\\gonzaloramosr_snhu\\Documents\\CS 300 Final Project\\FinaProject\\Debug\\CS 300 ABCU_Advising_Program_Input.csv";

    char currentPath[FILENAME_MAX];
    if (_getcwd(currentPath, sizeof(currentPath))) {
        cout << "Current Working Directory: " << currentPath << endl;
    }

    int choice;
    while (true) {
        displayMenu();
        cout << "What would you like to do? ";
        cin >> choice;

        if (choice == 1) {
            loadCourses(courses, filename);
        }
        else if (choice == 2) {
            printCourseList(courses);
        }
        else if (choice == 3) {
            string courseNumber;
            cout << "What course do you want to know about? ";
            cin >> courseNumber;
            printCourseDetails(courses, courseNumber);
        }
        else if (choice == 9) {
            cout << "Thank you for using the course planner!" << endl;
            break;
        }
        else {
            cout << choice << " is not a valid option." << endl;
        }
    }
    return 0;
}
