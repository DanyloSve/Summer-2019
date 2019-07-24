#include <QCoreApplication>

#include <iostream>
#include <string>

bool isSandwichWithIceCream (std :: string s)
{
    bool sandwich (false);
    bool iceCream (false);
    int check(0);

    for (int i(0); i < s.size(); i++)
    {
       if (s[i] == s[0])
       {
           if (!sandwich)
           {
               check++;
               sandwich = true;
           }
           continue;
       }

       if (s[i] != s[0])
       {
           if (!iceCream)
           {
               iceCream = true;
               sandwich = false;

               check++;
           }
       }

    }

    if ( sandwich  && iceCream  && check == 3)
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
