#include <iostream>

void foo(int a)
{
    std::cout << "This is integer!\n";
}

void foo(double a)
{
    std::cout << "This is double!\n";
}

void foo(char a)
{
    std::cout << "This is char!\n";
}


int main(int argc, char *argv[])
{
     int n(0);
     std::cin >> n;

     switch(n)
     {
        case 1:
     {
         int b(3);
         foo(b);
         break;

     }

     case 2:
     {
         double b(3.14);
         foo(b);
         break;
     }

     case 3:
     {
         char b('f');
         foo(b);
         break;
     }

     }

    return 0;
}
