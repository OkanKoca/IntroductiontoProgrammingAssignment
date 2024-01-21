
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

struct student {
    vector<string> name = { "Nana", "Clive", "Frederick", "Scott", "Carmen", "Gwendoline", "Terry", "Harold", "Josie", "Mathew", "Enid", "Lisa", "Sylvia", "Sandy", "Dan", "Coral", "Virginia", "Holly", "Brian", "Lindsay", "Barrie", "Cecilia", "Loretta", "Lauren", "Sam", "Ross", "Jim", "Salma", "Belinda", "Jimmy", "Karina", "Laurie", "Leanne", "Glynis", "Walter", "Kirsty", "Iqbal", "Ravi", "Maria", "Ronald" };
    vector<string> surname = { "Barrett", "Cantu", "Wong", "Butler", "Dougherty", "Torres", "Black", "Logan", "Mcmillan", "Oconnor", "Benson", "Mclean", "Hanna", "Stewart", "David", "Rivers", "Wilkins", "Madden", "Webster", "Kaufman", "Hayden", "Kelley", "Bernard", "Keller", "Ewing", "Dalton", "Frazier", "Gilbert", "Schaefer", "Pollard", "Aguilar", "Reeves", "Martin", "Oconnell", "Hernandez", "Grant", "Banks", "Riggs", "Cline", "Hubbard" };
    vector<int> midtermExamGrade = {};
    vector<int> firstHomeworkGrade = {};
    vector<int> secondHomeworkGrade = {};
    vector<int> firstShortExamGrade = {};
    vector<int> secondShortExamGrade = {};
    vector<int> finalExamGrade = {};
    vector<double> passingGrade = {};
    vector<string> letterGrade = { "AA", "BA", "BB", "CB", "CC", "DC", "DD", "FD", "FF" };
    vector<string> letterGradeResult = {};
}student;

int main()
{

    float highestGrade = 0.0;
    float lowestGrade = 100.0;
    int cntrAA = 0, cntrBA = 0, cntrBB = 0, cntrCB = 0, cntrCC = 0, cntrDC = 0, cntrDD = 0, cntrFD = 0, cntrFF = 0;
    int totalGrade = 0;
    double averageGrade = 0;
    int studentNumber;
    int prcntgMidtermExam;
    int prcntgFirstHomework;
    int prcntgSecondHomework;
    int prcntgFirstShortExam;
    int prcntgSecondShortExam;
    int prcntgFinalExam;
    vector<float>standardDeviation = {};

    srand(time(0));

    cout << "Please enter number of students: ";
    cin >> studentNumber;
    system("CLS");

    //this loop runs until total amount of percentages is 100. 
    do {

        cout << "Enter the weight of midterm exam: ";
        cin >> prcntgMidtermExam;
        cout << "Enter the weight of first homework: ";
        cin >> prcntgFirstHomework;
        cout << "Enter the weight of second homework: ";
        cin >> prcntgSecondHomework;
        cout << "Enter the weight of first short exam: ";
        cin >> prcntgFirstShortExam;
        cout << "Enter the weight of second short exam: ";
        cin >> prcntgSecondShortExam;
        cout << "Enter the weight of final exam: ";
        cin >> prcntgFinalExam;
        //if total weight is not 100 prints a message and the loop iterates.
        if (prcntgMidtermExam + prcntgFirstHomework + prcntgSecondHomework + prcntgFirstShortExam + prcntgSecondShortExam + prcntgFinalExam != 100)
            cout << "Invalid values. (Total of weights must be 100)" << endl;
        system("pause");
        system("CLS");

    } while (prcntgMidtermExam + prcntgFirstHomework + prcntgSecondHomework + prcntgFirstShortExam + prcntgSecondShortExam + prcntgFinalExam != 100);

    cout << setw(12) << "Name" << setw(12) << "Surname" << setw(12) << "Homework" << setw(12) << "Homework" << setw(12) << "Short Exam" << setw(12) << "Short Exam" << setw(12) << "Exam" << setw(12) << "Final" << setw(15) << "Passing Grade" << endl;
    cout << setw(12) << "-----" << setw(12) << "--------" << setw(12) << "-----" << setw(12) << "------" << setw(12) << "-----" << setw(12) << "-----" << setw(12) << "-------" << setw(12) << "-------" << setw(15) << "-------- " << endl;

    int studentNumberLeft = studentNumber;

    // this loop provides to create random grades between 80 and 100 for %20 of students.
    for (int i = 1; i <= ceil(studentNumber * 2 / 10); i++) {
        student.midtermExamGrade.push_back(rand() % 21 + 80);
        student.firstHomeworkGrade.push_back(rand() % 21 + 80);
        student.secondHomeworkGrade.push_back(rand() % 21 + 80);
        student.firstShortExamGrade.push_back(rand() % 21 + 80);
        student.secondShortExamGrade.push_back(rand() % 21 + 80);
        student.finalExamGrade.push_back(rand() % 21 + 80);
    }

    studentNumberLeft = studentNumberLeft - int(studentNumber * 2 / 10);

    // this loop provides to create random grades between 50 and 80 for %50 of students.
    for (int i = 1; i <= ceil(studentNumber * 5 / 10); i++) {
        student.midtermExamGrade.push_back(rand() % 31 + 50);
        student.firstHomeworkGrade.push_back(rand() % 31 + 50);
        student.secondHomeworkGrade.push_back(rand() % 31 + 50);
        student.firstShortExamGrade.push_back(rand() % 31 + 50);
        student.secondShortExamGrade.push_back(rand() % 31 + 50);
        student.finalExamGrade.push_back(rand() % 31 + 50);
    }

    studentNumberLeft = studentNumberLeft - int(studentNumber * 5 / 10);

    // this loop provides to create random grades between 0 and 50 for %30 of students.
    for (int i = 1; i <= studentNumberLeft; i++) {
        student.midtermExamGrade.push_back(rand() % 51);
        student.firstHomeworkGrade.push_back(rand() % 51);
        student.secondHomeworkGrade.push_back(rand() % 51);
        student.firstShortExamGrade.push_back(rand() % 51);
        student.secondShortExamGrade.push_back(rand() % 51);
        student.finalExamGrade.push_back(rand() % 51);
    }
    student.passingGrade.resize(studentNumber);

    //this loop calculates passing grades according to entered weights.
    for (int i = 0; i < studentNumber; i++) {
        student.passingGrade[i] = (student.midtermExamGrade[i] * prcntgMidtermExam +
            student.firstHomeworkGrade[i] * prcntgFirstHomework +
            student.secondHomeworkGrade[i] * prcntgSecondHomework +
            student.firstShortExamGrade[i] * prcntgFirstShortExam +
            student.secondShortExamGrade[i] * prcntgSecondShortExam +
            student.finalExamGrade[i] * prcntgFinalExam) / 100.0;

    }

    student.letterGradeResult.resize(studentNumber);

    /*
    This loop checks passing grades and if it is between(89.99, 100] AA counter increases one.
    If it is between [85, 90) BA counter increases one.
    If it is between [80, 85) BB counter increases one.
    If it is between [75, 80) CB counter increases one.
    If it is between [65, 75) CC counter increases one.
    If it is between [58, 65) DC counter increases one.
    If it is between [50, 58) DD counter increases one.
    If it is between [40, 50) FD counter increases one.
    if it is less than 40 FF counter increases one.
    */
    for (int i = 0; i < studentNumber; i++) {
        if (student.passingGrade[i] <= 100 && student.passingGrade[i] > 89.99) {
            cntrAA++;
            student.letterGradeResult[i] = "AA";
        }
        else if (student.passingGrade[i] < 90 && student.passingGrade[i] >= 85) {
            cntrBA++;
            student.letterGradeResult[i] = "BA";
        }
        else if (student.passingGrade[i] < 85 && student.passingGrade[i] >= 80) {
            cntrBB++;
            student.letterGradeResult[i] = "BB";
        }
        else if (student.passingGrade[i] < 80 && student.passingGrade[i] >= 75) {
            cntrCB++;
            student.letterGradeResult[i] = "CB";
        }
        else if (student.passingGrade[i] < 75 && student.passingGrade[i] >= 65) {
            cntrCC++;
            student.letterGradeResult[i] = "CC";
        }
        else if (student.passingGrade[i] < 65 && student.passingGrade[i] >= 58) {
            cntrDC++;
            student.letterGradeResult[i] = "DC";
        }
        else if (student.passingGrade[i] < 58 && student.passingGrade[i] >= 50) {
            cntrDD++;
            student.letterGradeResult[i] = "DD";
        }
        else if (student.passingGrade[i] < 50 && student.passingGrade[i] >= 40) {
            cntrFD++;
            student.letterGradeResult[i] = "FD";
        }
        else {
            cntrFF++;
            student.letterGradeResult[i] = "FF";
        }
    }
  
    //this loop compares passing grades to find highest grade between students.
    for (int i = 0; i < studentNumber; i++) {
        if (student.passingGrade[i] > highestGrade)
            highestGrade = student.passingGrade[i];
    }
    //this loop compares passing grades to find lowest grade between students.
    for (int i = 0; i < studentNumber; i++) {
        if (student.passingGrade[i] < lowestGrade)
            lowestGrade = student.passingGrade[i];
    }

    standardDeviation.resize(studentNumber);
    totalGrade = (accumulate(student.midtermExamGrade.begin(), student.midtermExamGrade.end(), 0) * prcntgMidtermExam +
        accumulate(student.firstHomeworkGrade.begin(), student.firstHomeworkGrade.end(), 0) * prcntgFirstHomework +
        accumulate(student.secondHomeworkGrade.begin(), student.secondHomeworkGrade.end(), 0) * prcntgSecondHomework +
        accumulate(student.firstShortExamGrade.begin(), student.firstShortExamGrade.end(), 0) * prcntgFirstShortExam +
        accumulate(student.secondShortExamGrade.begin(), student.secondShortExamGrade.end(), 0) * prcntgSecondShortExam +
        accumulate(student.finalExamGrade.begin(), student.finalExamGrade.end(), 0) * prcntgFinalExam) / 100.0;
    averageGrade = totalGrade / (double)studentNumber;

    //this loop calculate squares of the differences betwwen student grades and average grade to use it in standard deviation calculation.
    for (int i = 0; i < studentNumber; i++) {
        standardDeviation[i] = (student.passingGrade[i] - averageGrade) * (student.passingGrade[i] - averageGrade);
    }

    float standardDeviationResult = sqrt(accumulate(standardDeviation.begin(), standardDeviation.end(), 0) / (float)studentNumber - 1);

    // this loop prints random generated grades.
    for (int i = 0; i < studentNumber; i++) {
        cout << i + 1 << setw(12) << student.name[rand() % 40] << " " << setw(12) << student.surname[rand() % 40] << setw(12) << student.firstHomeworkGrade[i]
            << setw(12) << student.secondHomeworkGrade[i] << setw(12) << student.firstShortExamGrade[i] << setw(12) << student.secondShortExamGrade[i] << setw(12)
            << student.midtermExamGrade[i] << setw(12) << student.finalExamGrade[i] << setw(15) << student.passingGrade[i] << setw(5) << student.letterGradeResult[i] << setw(5) << endl
            << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    system("pause");
    system("CLS");

    cout << "Average grade: " << averageGrade << endl;
    cout << "Highest grade: " << highestGrade << endl;
    cout << "Lowest grade: " << lowestGrade << endl;
    cout << "Standard Deviation: " << standardDeviationResult << endl;
    cout << "Amount of AA grades: " << cntrAA << endl;
    cout << "Amount of BA grades: " << cntrBA << endl;
    cout << "Amount of BB grades: " << cntrBB << endl;
    cout << "Amount of CB grades: " << cntrCB << endl;
    cout << "Amount of CC grades: " << cntrCC << endl;
    cout << "Amount of DC grades: " << cntrDC << endl;
    cout << "Amount of DD grades: " << cntrDD << endl;
    cout << "Amount of FD grades: " << cntrFD << endl;
    cout << "Amount of FF grades: " << cntrFF << endl;
    cout << "Percentage of AA grades: %" << ((float)cntrAA / studentNumber) * 100 << endl;
    cout << "Percentage of BA grades: %" << ((float)cntrBA / studentNumber) * 100 << endl;
    cout << "Percentage of BB grades: %" << ((float)cntrBB / studentNumber) * 100 << endl;
    cout << "Percentage of CB grades: %" << ((float)cntrCB / studentNumber) * 100 << endl;
    cout << "Percentage of CC grades: %" << ((float)cntrCC / studentNumber) * 100 << endl;
    cout << "Percentage of DC grades: %" << ((float)cntrDC / studentNumber) * 100 << endl;
    cout << "Percentage of DD grades: %" << ((float)cntrDD / studentNumber) * 100 << endl;
    cout << "Percentage of FD grades: %" << ((float)cntrFD / studentNumber) * 100 << endl;
    cout << "Percentage of FF grades: %" << ((float)cntrFF / studentNumber) * 100 << endl;

    system("pause");
    system("CLS");

    cout << "AA: ";
    //this loop prints "*" until it is equal to amount of AA grades.
    for (int i = 0; i < cntrAA; i++)
        cout << "*";
    cout << endl;
    cout << "BA: ";
    //this loop prints "*" until it is equal to amount of BA grades.
    for (int i = 0; i < cntrBA; i++)
        cout << "*";
    cout << endl;
    cout << "BB: ";
    //this loop prints "*" until it is equal to amount of BB grades.
    for (int i = 0; i < cntrBB; i++)
        cout << "*";
    cout << endl;
    cout << "CB: ";
    //this loop prints "*" until it is equal to amount of CB grades.
    for (int i = 0; i < cntrCB; i++)
        cout << "*";
    cout << endl;
    cout << "CC: ";
    //this loop prints "*" until it is equal to amount of CC grades.
    for (int i = 0; i < cntrCC; i++)
        cout << "*";
    cout << endl;
    cout << "DC: ";
    //this loop prints "*" until it is equal to amount of DC grades.
    for (int i = 0; i < cntrDC; i++)
        cout << "*";
    cout << endl;
    cout << "DD: ";
    //this loop prints "*" until it is equal to amount of DD grades.
    for (int i = 0; i < cntrDD; i++)
        cout << "*";
    cout << endl;
    cout << "FD: ";
    //this loop prints "*" until it is equal to amount of FD grades.
    for (int i = 0; i < cntrFD; i++)
        cout << "*";
    cout << endl;
    cout << "FF: ";
    //this loop prints "*" until it is equal to amount of FF grades.
    for (int i = 0; i < cntrFF; i++)
        cout << "*";
    cout << endl;






}
