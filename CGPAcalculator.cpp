#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;


struct Course {
    string name;
    int credits;
    double grade; 
};

int main() {
    int numCourses;
    vector<Course> courses;

    
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    
    for (int i = 0; i < numCourses; i++) {
        Course course;
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin.ignore(); 
        getline(cin, course.name);
        cout << "Credits (e.g., 3, 4): ";
        cin >> course.credits;
        cout << "Grade Points (e.g., 4.0 for A, 3.0 for B): ";
        cin >> course.grade;

        courses.push_back(course);
    }

    
    double totalCredits = 0, totalGradePoints = 0;
    for (const auto& course : courses) {
        totalCredits += course.credits;
        totalGradePoints += course.credits * course.grade;
    }
    double CGPA = totalGradePoints / totalCredits;

    
    cout << "\n\n----- CGPA Report -----\n";
    cout << setw(20) << left << "Course Name"
         << setw(10) << "Credits"
         << setw(10) << "Grade\n";
    for (const auto& course : courses) {
        cout << setw(20) << left << course.name
             << setw(10) << course.credits
             << setw(10) << course.grade << endl;
    }
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nCumulative Grade Point Average (CGPA): " << fixed << setprecision(2) << CGPA << endl;

    return 0;
}
