#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); 

    while (t--)
    {
        string line;
        getline(cin, line); 

        stringstream ss(line);
        string word;

        while (ss >> word)
        {
            cout << word[0]; 
        }
        cout << endl; 
    }

    return 0;
}
