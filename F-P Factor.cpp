//this file is to calculate the F/P factor of a given problem, it can also calculate the P/F factor since it requires the
//same formula

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
    double F;
    double P;
    double i;
    double n;
    char missingVariable;

    // Prompt for missing variable
    cout << "Which variable do you want to find? (F, P, i, or n): ";
    cin >> missingVariable;

    if (missingVariable == 'F') {
        cout << "Enter Present Worth (P): ";
        cin >> P;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        // F/P factor: (1+i)^n. This one is fine at i = 0, it just returns P.
        F = P * pow(1 + i, n);
        cout << "Future Worth (F) = " << F << endl;

    } else if (missingVariable == 'P') {
        cout << "Enter Future Worth (F): ";
        cin >> F;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        // P/F factor: 1 / (1+i)^n
        P = F / pow(1 + i, n);
        cout << "Present Worth (P) = " << P << endl;

    } else if (missingVariable == 'i') {
        cout << "Enter Future Worth (F): ";
        cin >> F;
        cout << "Enter Present Worth (P): ";
        cin >> P;
        cout << "Enter number of periods (n): ";
        cin >> n;

        if (n == 0) {
            cout << "Error: number of periods cannot be 0 when solving for i." << endl;
            return 1;
        }
        if (P == 0 || F / P <= 0) {
            cout << "Error: F and P must be nonzero and have the same sign." << endl;
            return 1;
        }

        // Solve (1+i)^n = F/P for i. 1.0/n keeps this in floating point.
        i = pow(F / P, 1.0 / n) - 1;
        cout << "Interest rate (i) = " << i << " (" << i * 100 << " %)" << endl;

    } else if (missingVariable == 'n') {
        cout << "Enter Future Worth (F): ";
        cin >> F;
        cout << "Enter Present Worth (P): ";
        cin >> P;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;

        // log(1+i) is 0 when i = 0, which would divide by zero below
        if (i == 0) {
            cout << "Error: interest rate cannot be 0 when solving for n." << endl;
            return 1;
        }
        if (P == 0 || F / P <= 0) {
            cout << "Error: F and P must be nonzero and have the same sign." << endl;
            return 1;
        }

        // Solve (1+i)^n = F/P for n using logarithms
        n = log(F / P) / log(1 + i);
        cout << "Number of periods (n) = " << n << endl;

    } else {
        // Handle invalid input
        cout << "Invalid variable. Please enter F, P, i, or n." << endl;
        return 1;
    }

    return 0;
}
