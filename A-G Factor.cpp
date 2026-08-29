//This code calculates the equivalent uniform annual series A for an Arithmetic Gradient G
//A/G Factor

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
    double A;
    double G;
    double i;
    double n;
    double factor;   // the A/G factor itself, so both directions share one expression
    char missingVariable;

    // Prompt for missing variable
    cout << "Which variable do you want to find? (A or G): ";
    cin >> missingVariable;

    if (missingVariable == 'A') {
        cout << "Enter Gradient (G): ";
        cin >> G;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        // The A/G factor divides by i and by ((1+i)^n - 1), both zero at i = 0
        if (i == 0) {
            cout << "Error: interest rate cannot be 0 for the A/G factor." << endl;
            return 1;
        }

        // A/G factor: 1/i - n/((1+i)^n - 1)
        factor = (1 / i) - (n / (pow(1 + i, n) - 1));

        A = G * factor;
        cout << "Annual Worth (A) = " << A << endl;
        cout << "(A/G factor used = " << factor
             << " at i = " << i << " (" << i * 100 << " %), n = " << n << ")" << endl;

    } else if (missingVariable == 'G') {
        // This prompt previously asked for Present Worth (P) by mistake - it wants A
        cout << "Enter Annual Worth (A): ";
        cin >> A;
        cout << "Enter interest rate (i) as a decimal, e.g. 0.08 for 8%: ";
        cin >> i;
        cout << "Enter number of periods (n): ";
        cin >> n;

        if (i == 0) {
            cout << "Error: interest rate cannot be 0 for the A/G factor." << endl;
            return 1;
        }

        factor = (1 / i) - (n / (pow(1 + i, n) - 1));

        G = A / factor;
        cout << "Gradient (G) = " << G << endl;
        cout << "(A/G factor used = " << factor
             << " at i = " << i << " (" << i * 100 << " %), n = " << n << ")" << endl;

    } else {
        // Handle invalid input
        cout << "Invalid variable. Please enter A or G." << endl;
        return 1;
    }

    return 0;
}
