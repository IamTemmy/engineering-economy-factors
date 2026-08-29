//this file is to calculate the F/A and A/F factor of a given problem.
//in this code, we can only have either A or F as the only missing variables
//Generating a formula to find i and n would be complex, can be done, but in the future

#include <iostream>
#include <cmath>

using namespace std;

//F = Future Worth
//P = Present Worth
//A = Annual Worth
//i = interest rate per time period, entered as a DECIMAL (0.08 means 8%)
//n = number periods/years, months, days
//t = time/years, months, days

int main()
{
    double A;
    double F;
    double i;
    double n;
    char missingVariable;

    // Prompt for missing variable
    cout << "Which variable do you want to find? (A or F): ";
    cin >> missingVariable;

    if (missingVariable == 'A') {
        cout << "Enter Future Worth (F): ";
        cin >> F;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        // At i = 0 the A/F factor divides by zero. The limit is A = F/n,
        // but this program stops rather than guess what the user meant.
        if (i == 0) {
            cout << "Error: interest rate cannot be 0 for the A/F factor." << endl;
            return 1;
        }

        // A/F factor: i / ((1+i)^n - 1)
        A = F * i / (pow(1 + i, n) - 1);
        cout << "Annual Worth (A) = " << A << endl;
        cout << "(at i = " << i << " (" << i * 100 << " %), n = " << n << ")" << endl;

    } else if (missingVariable == 'F') {
        cout << "Enter Annual Worth (A): ";
        cin >> A;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        if (i == 0) {
            cout << "Error: interest rate cannot be 0 for the F/A factor." << endl;
            return 1;
        }

        // F/A factor: ((1+i)^n - 1) / i
        F = A * ((pow(1 + i, n) - 1) / i);
        cout << "Future Worth (F) = " << F << endl;
        cout << "(at i = " << i << " (" << i * 100 << " %), n = " << n << ")" << endl;

    } else {
        // Handle invalid input
        cout << "Invalid variable. Please enter A or F." << endl;
        return 1;
    }

    return 0;
}
