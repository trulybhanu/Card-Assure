//   C++ Program to validate Debit/Credit card number
//   Required Algorithm: Luhn's Checksum Algorithm.
//   Author: Bhanu Pratap

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Function to check if entered card number is Numeric
bool isNumericString(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main()
{
    string cardNumber, q;

    do
    {
        cout << "\n   ---------------------------------------------------------------";
        cout << "\n   ||  Debit/Credit Card Number Validator Using Luhn Algorithm  ||";
        cout << "\n   ---------------------------------------------------------------\n";

        cout << "\n   Please enter a Debit/Credit card number: ";
        cin >> cardNumber;

        if (!isNumericString(cardNumber))
        {
            cout << "\n      Card Number should be numeric only!\n";
        }

        else
        {
            int len = cardNumber.length();
            int sumOfDoubles = 0;

            // Step 1: Double every second digit, starting from the right. If it
            // results in a two digit number, add both the digits to obtain a single
            // digit number. Finally, sum all the answers to obtain 'sumOfDoubles'.

            for (int i = len - 2; i >= 0; i = i - 2)
            {
                int doubl = ((cardNumber[i] - 48) * 2);
                if (doubl > 9)
                {
                    doubl = (doubl / 10) + (doubl % 10);
                }
                sumOfDoubles += doubl;
            }

            // Step 2: Add every odd placed digit from the right to the value 'sumOfDoubles'.

            for (int i = len - 1; i >= 0; i = i - 2)
            {
                sumOfDoubles += (cardNumber[i] - 48);
            }

            // Step 3: Check if the 'sumOfDoubles' is a multiple of 10.
            // If yes, it's a valid Debit/Credit card number. Otherwise, not.

            cout << (sumOfDoubles % 10 == 0 ? "\n      Valid!" : "\n      Invalid!") << endl;
        }
        cout << "\n   ---------------------------------------------------------------\n";
        cout << "\n   Enter '1' to validate another card number, or any other key to exit: ";
        cin >> q;

    } while (q[0] == '1');

    return 0;
}