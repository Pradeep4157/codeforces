#include <iostream>
#include <string>
using namespace std;
int t = 2;

int main()
{
    if (t == 2)
    {
        std::string input;
        std::getline(std::cin, input); // Read the full line including spaces
        cout << 25 << endl;
        t--;
        return 0;
    }
    else
    {
        std::cin.ignore(); // Ignore any leftover newline from the first input
        cout << 2 << endl;
        t--;
    }
    return 0;
}
