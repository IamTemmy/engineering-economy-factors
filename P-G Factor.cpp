//This code converts an arithmetic gradient G (not including the base amount) for n years
//into a present worth at year 0. This is the arithmetic present worth.
//P/G Factor

#include <iostream>
#include <cmath>

using namespace std;

// F = Future Worth
// P = Present Worth
// A = Annual Worth
// G = Arithmetic Gradient
// i = interest rate per time period, entered as a DECIMAL (0.08 means 8%)
// n = number periods/years, months, days
// t = time/years, months, days

int main() {
    double P;
    double G;
    double i;
    double n;
    double factor;   // the P/G factor itself, so both directions share one expression
    char missingVariable;

    // Prompt for missing variable
    cout << "Which variable do you want to find? (P or G): ";
    cin >> missingVariable;

    if (missingVariable == 'P') {
        cout << "Enter Gradient (G): ";
        cin >> G;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        // The P/G factor is undefined at i = 0 because it divides by i
        if (i == 0) {
            cout << "Error: interest rate cannot be 0 for the P/G factor." << endl;
            return 1;
        }

        // P/G factor: (1/i) * [ ((1+i)^n - 1) / (i(1+i)^n) - n/(1+i)^n ]
        factor = (1 / i) * (((pow(1 + i, n) - 1) / (i * pow(1 + i, n))) - (n / pow(1 + i, n)));

        P = G * factor;
        cout << "Present Worth (P) = " << P << endl;
        cout << "(P/G factor used = " << factor
             << " at i = " << i << " (" << i * 100 << " %), n = " << n << ")" << endl;

    } else if (missingVariable == 'G') {
        cout << "Enter Present Worth (P): ";
        cin >> P;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        if (i == 0) {
            cout << "Error: interest rate cannot be 0 for the P/G factor." << endl;
            return 1;
        }

        // Same factor as above, just divided instead of multiplied.
        // Reusing one expression is what keeps the two directions consistent -
        // the earlier version of this file used a different, incorrect expression here.
        factor = (1 / i) * (((pow(1 + i, n) - 1) / (i * pow(1 + i, n))) - (n / pow(1 + i, n)));

        G = P / factor;
        cout << "Gradient (G) = " << G << endl;
        cout << "(P/G factor used = " << factor
             << " at i = " << i << " (" << i * 100 << " %), n = " << n << ")" << endl;

    } else {
        // Handle invalid input
        cout << "Invalid variable. Please enter P or G." << endl;
        return 1;
    }

    return 0;
}
