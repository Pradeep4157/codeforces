#include <iostream>
#include <vector>
using namespace std;

// Function to count number of odd and even divisors
pair<int, int> countDivisors(int n)
{
    int odd = 0, even = 0;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int div1 = i;
            int div2 = n / i;

            if (div1 % 2 == 0)
                even++;
            else
                odd++;

            // Avoid double counting if div1 == div2
            if (div1 != div2)
            {
                if (div2 % 2 == 0)
                    even++;
                else
                    odd++;
            }
        }
    }
    return {odd, even};
}

void findInterestingNumbers(int limit)
{
    for (int num = 2; num <= limit; ++num)
    {
        pair<int, int> result = countDivisors(num);
        int odd = result.first;
        int even = result.second;
        if (even >= 1 && odd > even)
        {
            cout << num << " → Odd: " << odd << ", Even: " << even << '\n';
        }
    }
}

int main()
{
    int limit = 100000;
    findInterestingNumbers(limit);
    return 0;
}