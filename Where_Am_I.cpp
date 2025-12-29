#include <iostream>
#include <iomanip> // For setting precision

int main()
{
    double latitude = 36.104600;
    double longitude = -115.172608;

    // Output with 6 decimal places
    std::cout << std::fixed << std::setprecision(6);
    std::cout << latitude << std::endl;
    std::cout << longitude << std::endl;

    return 0;
}
