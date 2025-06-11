#include <iostream>
#include <iomanip>
#include<string>
using namespace std;
void printHeader() {
    cout << "\n=========================================\n";
    cout << "        STUDENT CGPA CALCULATOR\n";
    cout << "=========================================\n";
}

void printFooter() {
    cout << "-----------------------------------------\n";
    cout << "        Thank you for using the tool!\n";
    cout << "-----------------------------------------\n";
}
string grade(float point){
    if (point >= 9.0)
        return "A+";
    else if (point >= 8.0)
        return "A";
    else if (point >= 7.0)
        return "B+";
    else if (point >= 6.0)
        return "B";
    else if (point >= 5.0)
        return "C";
    else if (point >= 4.0)
        return "D";
    else
        return "F";
}

int main() {
    const int MAX = 20;
    int n;
    float credits[MAX], grades[MAX];
    float totalGradePoints = 0, totalCredits = 0;

    printHeader();

    cout << "Enter number of subjects (max " << MAX << "): ";
    cin >> n;
    while (n <= 0 || n > MAX) {
        cout << "Invalid number! Please enter between 1 and " << MAX << ": ";
        cin >> n;
    }

    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Subject " << i + 1 << " ---\n";
        cout << "Enter credit hours: ";
        cin >> credits[i];
        cout << "Enter grade point (e.g., 9.0): ";
        cin >> grades[i];

        totalGradePoints += credits[i] * grades[i];
        totalCredits += credits[i];
    }
    float cgpa = totalGradePoints / totalCredits;
    cout << "\n=========================================\n";
    cout << "            RESULT SUMMARY\n";
    cout << "=========================================\n";
    cout << fixed << setprecision(2);
    cout << "Total Credits    : " << totalCredits << endl;
    cout << "Total Grade Pts  : " << totalGradePoints << endl;
    cout << "Your CGPA        : " << cgpa << endl;
    cout << "Your grade       : " << grade(cgpa)<<endl;
    cout << "=========================================\n";

    printFooter();
    return 0;
}
