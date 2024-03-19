
#include <iostream>
using namespace std;

class A
{
public:
    int a = 10;

    friend istream &operator>>(istream &os, A &obj);
};

istream &operator>>(istream &os, A &obj)
{
    os >> obj.a;
    return os;
}

// Function to calculate and print Pascal's Triangle
void generatePascalsTriangle(int numRows)
{
    for (int i = 0; i < numRows; i++)
    {
        int number = 1; // First element in each row
        for (int j = 0; j < numRows - i; j++)
        {
            cout << "  "; // Add spaces for formatting
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "   " << number;             // Print the number
            number = number * (i - j) / (j + 1); // Calculate the next number
        }
        cout << endl; // Move to the next row
    }
}

int main()
{
    A obj;
    cin >> obj;
    string a = "a";
    cout << obj.a;
    return 0;
}

