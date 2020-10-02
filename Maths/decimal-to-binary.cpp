#include <iostream>

int main()
{
    int bin[32], n, i;

    std::cout << "Enter a decimal integer:" << std::endl;
    std::cin >> n;

    for (i = 0; n > 0; i++)
    {
        bin[i] = n % 2;
        n /= 2;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        std::cout << bin[j];
    }

    return 0;
}