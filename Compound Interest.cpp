//This code calculates the compound amount and solves for any one missing variable.
//Note on naming: C here is the COMPOUND AMOUNT, i.e. principal plus accumulated
//interest, P(1+i)^n. The interest earned on its own is C - P.

#include <iostream>
#include <cmath>

using namespace std;

// P = Principal
// i = interest rate per time period, entered as a DECIMAL (0.08 means 8%)
// n = number periods/years, months, days
// C = Compound amount (principal + interest)

int main() {
    double C;
    double P;
    double i;
    double n;
    char missingVariable;

    // Prompt for missing variable
    cout << "Which variable do you want to find? (C, P, i or n): ";
    cin >> missingVariable;

    if (missingVariable == 'C') {
        cout << "Enter Principal (P): ";
        cin >> P;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        // Calculate C using the formula
        C = P * pow(1 + i, n);
        cout << "Compound amount (C) = " << C << endl;
        cout << "Interest earned (C - P) = " << C - P << endl;

    } else if (missingVariable == 'P') {
        cout << "Enter Compound amount (C): ";
        cin >> C;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        // Rearrange formula to solve for P
        P = C / pow(1 + i, n);
        cout << "Principal (P) = " << P << endl;

    } else if (missingVariable == 'i') {
        cout << "Enter Compound amount (C): ";
        cin >> C;
        cout << "Enter Principal (P): ";
        cin >> P;
        cout << "Enter number of periods (n): ";
        cin >> n;

        if (n == 0) {
            cout << "Error: number of periods cannot be 0 when solving for i." << endl;
            return 1;
        }
        if (P == 0 || C / P <= 0) {
            cout << "Error: C and P must be nonzero and have the same sign." << endl;
            return 1;
        }

        // Solve for i
        i = pow(C / P, 1.0 / n) - 1;
        cout << "Interest rate (i) = " << i << " (" << i * 100 << " %)" << endl;

    } else if (missingVariable == 'n') {
        cout << "Enter Compound amount (C): ";
        cin >> C;
        cout << "Enter Principal (P): ";
        cin >> P;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;

        // log(1+i) is 0 when i = 0, which would divide by zero below
        if (i == 0) {
            cout << "Error: interest rate cannot be 0 when solving for n." << endl;
            return 1;
        }
        if (P == 0 || C / P <= 0) {
            cout << "Error: C and P must be nonzero and have the same sign." << endl;
            return 1;
        }

        // Solve for n using logarithms
        n = log(C / P) / log(1 + i);
        cout << "Number of periods (n) = " << n << endl;

    } else {
        // Handle invalid input
        cout << "Invalid variable. Please enter C, P, i, or n." << endl;
        return 1;
    }

    return 0;
}
