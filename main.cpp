#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;


// function prototypes

void table(string courses[], string grades[], int credits[], int courseCount);

float calculation(string courses[], string grades[], int credits[],float weightedPoints[], int choice, int courseCount,int totalCredits, float totalWeightedPoints);

string convertToUppercase(string grade);


int main()
{
    int courseCount;
    int choice;
    int totalCredits = 0;
    float totalWeightedPoints = 0;
    float gpa = 0;


    cout << "AA - BA - BB - CB - CC - DC - DD - FD - FF " << "[1]" << endl;
    cout << "A - A(-) - B+ - B - B(-) - C+ - C - C(-) - D+ - D - D(-) " << "[2]" << endl;

    cout << "Select the grading system you use: ";
    cin >> choice;


    while(choice != 1 && choice != 2) {
        cout << "Please make a valid selection: ";
        cin >> choice;
    }


    cout << "Enter the number of courses you have taken: ";
    cin >> courseCount;

    while(courseCount <= 0)
    {
        cout << "Please enter a valid course number:";
        cin >> courseCount;

    }


    string courses[courseCount];
    int credits[courseCount];
    string grades[courseCount];
    float weightedPoints[courseCount];


    gpa = calculation(courses, grades, credits, weightedPoints,choice, courseCount, totalCredits,totalWeightedPoints);


    table(courses, grades, credits, courseCount);


    cout << "Gpa:" << gpa << endl;


    return 0;
}


// table function

void table(string courses[], string grades[],int credits[], int courseCount)
{
    cout << endl;

    // left aligns the output to the left
    // setw sets a specific amount of space for the output

    cout << left << setw(10) << "Courses" << setw(15) << "Credits" << setw(15) << "Letter Grade" << endl;


    for(int l = 0; l < courseCount; l++)
    {
        // substr gets characters 0-3 of the string

        cout << left << setw(10) << courses[l].substr(0, 3) << setw(15) << credits[l] << setw(15) << grades[l] << endl;
    }
}


// calculation function

float calculation(string courses[], string grades[], int credits[],float weightedPoints[], int choice, int courseCount,int totalCredits, float totalWeightedPoints)
{

    if(choice == 1)
    {
        for(int i = 0; i < courseCount; i++)
        {
            cout << i + 1 << ". Enter the name of your course: ";
            cin >> courses[i];


            cout << i + 1 << ". Enter the number of credits for your course: ";
            cin >> credits[i];

            while(credits[i] <= 0)
            {
                cout << "Please enter a valid number of credits: ";
                cin >> credits[i];

            }


            cout << i + 1 << ". Enter the letter grade you received for the course: ";
            cin >> grades[i];


            // converts lowercase letters to uppercase
        grades[i] = convertToUppercase(grades[i]);


    while(grades[i] != "AA" && grades[i] != "BA" && grades[i] != "BB" && grades[i] != "CB" && grades[i] != "CC" && grades[i] != "DC" && grades[i] != "DD" && grades[i] != "FD" && grades[i] != "FF")
    {
    cout << "Please enter a valid letter grade: ";
    cin >> grades[i];
    grades[i] = convertToUppercase(grades[i]);

    }   


            if(grades[i] == "AA"){
                weightedPoints[i] = 4 * credits[i];
            }

            else if(grades[i] == "BA")
            {
                weightedPoints[i] = 3.5 * credits[i];
            }

            else if(grades[i] == "BB")
            {
                weightedPoints[i] = 3 * credits[i];
            }

            else if(grades[i] == "CB")
            {
                weightedPoints[i] = 2.5 * credits[i];
            }

            else if(grades[i] == "CC")
            {
                weightedPoints[i] = 2 * credits[i];
            }

            else if(grades[i] == "DC")
            {
                weightedPoints[i] = 1.5 * credits[i];
            }

            else if(grades[i] == "DD"){
                weightedPoints[i] = 1 * credits[i];
            }

            else if(grades[i] == "FD")
            {
                weightedPoints[i] = 0.5 * credits[i];
            }

            else if(grades[i] == "FF")
            {
                weightedPoints[i] = 0;
            }

        }


        for(int j = 0; j < courseCount; j++)
        {
            totalCredits = totalCredits + credits[j];
        }


        for(int k = 0; k < courseCount; k++)
        {
            totalWeightedPoints = totalWeightedPoints + weightedPoints[k];
        }
    }


    else if(choice == 2)
    {
        for(int i = 0; i < courseCount; i++)
        {
            cout << i + 1 << ". Enter the name of your course: ";
            cin >> courses[i];


            cout << i + 1 << ". Enter the number of credits for your course: ";
            cin >> credits[i];


            cout << i + 1 << ". Enter the letter grade you received for the course: ";
            cin >> grades[i];


            // converts lowercase letters to uppercase
            grades[i] = convertToUppercase(grades[i]);

            while(grades[i] != "A" && grades[i] != "A-" && grades[i] != "B+" && grades[i] != "B" && grades[i] != "B-" && grades[i] != "C+" && grades[i] != "C" && grades[i] != "C-" && grades[i] != "D+" && grades[i] != "D" && grades[i] != "D-" && grades[i] != "F")
            {
                cout << "Please enter a valid letter grade: ";
                cin >> grades[i];
                grades[i] = convertToUppercase(grades[i]); 
            }




            if(grades[i] == "A")
            {
                weightedPoints[i] = 4 * credits[i];

            }

            else if(grades[i] == "A-"){
                weightedPoints[i] = 3.7 * credits[i];

            }

            else if(grades[i] == "B+")
            {
                weightedPoints[i] = 3.3 * credits[i];

            }

            else if(grades[i] == "B")
            {
                weightedPoints[i] = 3 * credits[i];

            }

            else if(grades[i] == "B-"){
                weightedPoints[i] = 2.7 * credits[i];

            }

            else if(grades[i] == "C+")
            {
                weightedPoints[i] = 2.5 * credits[i];


            }

            else if(grades[i] == "C")
            {
                weightedPoints[i] = 2 * credits[i];

            }

            else if(grades[i] == "C-")
            {
                weightedPoints[i] = 1.7 * credits[i];

            }

            else if(grades[i] == "D+")
            {
                weightedPoints[i] = 1.3 * credits[i];

            }

            else if(grades[i] == "D")
            {
                weightedPoints[i] = 1 * credits[i];

            }

            else if(grades[i] == "D-")
            {
                weightedPoints[i] = 0.7 * credits[i];


            }

            else if(grades[i] == "F")
            {
                weightedPoints[i] = 0;

            }

        }


        for(int j = 0; j < courseCount; j++)
        {
            totalCredits = totalCredits + credits[j];
        }


        for(int k = 0; k < courseCount; k++)
        {
            totalWeightedPoints = totalWeightedPoints + weightedPoints[k];

        }
    }

    return totalWeightedPoints / totalCredits;
}

// this function converts lowercase letters to uppercase to prevent errors
string convertToUppercase(string grade)
{
    for(int i = 0; i < grade.length(); i++)
    {
        grade[i] = toupper(grade[i]);
        
    }

    return grade;

}