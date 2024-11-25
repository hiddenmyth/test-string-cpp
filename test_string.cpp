#include <iostream>
#include <string>
#include <list>
#include <iomanip>

using namespace std;

/**

Problem statement  is not clear.
It should be like "If the string length is divisible by two, but not three, ..."

**/


// Flags for process type
enum CONTROL
{
    DIV_2   = 0x01,         // Flag if the length of string is divided by 2
    DIV_3   = 0x02,         // Flag if the length of string is divided by 3
    DIV_2_3 = DIV_2 | DIV_3,// Flag if the length of string is divided by 2 and 3
};

// Input string
string input_string()
{
    string s;
    cin >> s;

    return s;
}

// Calculate the control flag
int calc_control(string s)
{
    int control = 0;
    if(s.length() % 2 == 0)
        control |= DIV_2;
    if(s.length() % 3 == 0)
        control |= DIV_3;

    return control;
}

// Reverse string
void reverse_string(string& s)
{
    string rev(s.rbegin(), s.rend());

    cout << "Reversed: " << rev << endl;
}

// Add to link and double string
void process_link_double(string& input)
{
    list <char> charList(input.begin(), input.end());
    cout << "Doubled string: ";

    // Double string by printing each letters two times
    for (const char& ch : charList) {
        cout << ch << ch;
    }
    cout << endl;
}

// Calculate the tax
void calculate_tax(string& input)
{
    double value = static_cast<double>(input.length());
    double rate = 0.032;
    double res = value * (1 + rate);\

    // Tax is written in $. So it contains only 2 decimals
    cout << "Tax is $" << std::fixed << std::setprecision(2) << res << endl;
}

void manipulation(string& s)
{
    // check the length of string with the problem statement
    if(s.length() < 10 || s.length() > 15){
        cout << "Invalid length." << endl;
        return;
    }

    // calculate the control flag
    int control = calc_control(s);

    // Perfom actions
    switch(control)
    {
    case DIV_2:
        reverse_string(s);
        break;
    case DIV_3:
        process_link_double(s);
        break;
    case DIV_2_3:
        calculate_tax(s);
        break;
    default:
        cout << "Out of condition" << endl;
    }
}

void test()
{
    // Test case: Length divisible by 3 only
    string test1 = "abcdefghij"; // 10 characters
    manipulation(test1);

    // Test case: Length divisible by 3 only
    string test2 = "abcdefghi"; // 9 characters
    manipulation(test2);

    // Test case: Length divisible by both 2 and 3
    string test3 = "abcdefghijkl"; // 12 characters
    manipulation(test3);

    // Test case: Length not divisible by 2 or 3
    string test4 = "abcdefghijklm"; // 13 characters
    manipulation(test4);

    // Test case: Length is too long
    string test5 = "abcdefghijklmaaa"; // 16 characters
    manipulation(test5);

    cout << "All tests executed." << endl;
}

main()
{
//    string s = input_string();
//    manipulation(s);

    test();

    return 0;
}
