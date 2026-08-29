//this file is to calculate the P/A and A/P factor of a given problem.
//in this code, we can only have either A or P as the only missing variables
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
    double P;
    double i;
    double n;
    char missingVariable;

    // Prompt for missing variable
    cout << "Which variable do you want to find? (A or P): ";
    cin >> missingVariable;

    if (missingVariable == 'A') {
        cout << "Enter Present Worth (P): ";
        cin >> P;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        // At i = 0 the A/P factor divides by zero. The limit is A = P/n,
        // but this program stops rather than guess what the user meant.
        if (i == 0) {
            cout << "Error: interest rate cannot be 0 for the A/P factor." << endl;
            return 1;
        }

        // A/P factor: i(1+i)^n / ((1+i)^n - 1)
        A = P * i * pow(1 + i, n) / (pow(1 + i, n) - 1);
        cout << "Annual Worth (A) = " << A << endl;
        cout << "(at i = " << i << " (" << i * 100 << " %), n = " << n << ")" << endl;

    } else if (missingVariable == 'P') {
        cout << "Enter Annual Worth (A): ";
        cin >> A;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        if (i == 0) {
            cout << "Error: interest rate cannot be 0 for the P/A factor." << endl;
            return 1;
        }

        // P/A factor: ((1+i)^n - 1) / (i(1+i)^n)
        P = A * (pow(1 + i, n) - 1) / (i * pow(1 + i, n));
        cout << "Present Worth (P) = " << P << endl;
        cout << "(at i = " << i << " (" << i * 100 << " %), n = " << n << ")" << endl;

    } else {
        // Handle invalid input
        cout << "Invalid variable. Please enter A or P." << endl;
        return 1;
    }

    return 0;
}
