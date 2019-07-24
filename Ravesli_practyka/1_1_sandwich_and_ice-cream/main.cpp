#include <iostream>
#include <string>

bool isSandwichWithIceCream (std :: string s)
{
    int lowerSandwichSize(0);
    int upperSandwichSize(0);
    int iceCreamSize(0);

    char lowerSandwich(s[0]);
    char upperSandwich(s[s.size() - 1]);
    char iceCream (s[s.size() / 2]);

    if (lowerSandwich != upperSandwich || lowerSandwich == iceCream || upperSandwich == iceCream )
    {
        return false;
    }

    for (int i(0); i < s.size(); i++)
    {
        if ( s[i] == lowerSandwich )
        {
            lowerSandwichSize++;
        }
        if( s[i] != lowerSandwich)
        {
            break;
        }
    }

    for (int i(s.size() - 1) ; i != 0; i--)
    {
        if ( s[i] == lowerSandwich )
        {
            upperSandwichSize++;
        }
        if( s[i] != upperSandwich)
        {
            break;
        }
    }


    if (upperSandwichSize == lowerSandwichSize)
    {
        return true;
    }

    return false;
}

int main()
{
        std::string s;

        std::cin >> s;

        std::cout << isSandwichWithIceCream(s);
        std::cout << '\n';

        return 0;
}
