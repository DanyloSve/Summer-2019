#include <iostream>

class Point
{
private:
    int mX;
    int mY;

public:
    Point()
    {
        mX = 0;
        mY = 0;

        std::cout << this << "Constructor\n";


    }

    Point(int valueX, int valueY)
    {
        mX = valueX;
        mY = valueY;

        std::cout << this << "Constructor\n";
    }

    void setX(int x)
    {
        mX = x;
    }

    void setY(int mY)
    {
        this-> mY = mY;
    }

    int getX()
    {
        return mX;
    }

    void print()
    {
        std::cout << mX << ' ' << mY << '\n';
    }


};

int main()
{
    Point A;
    A.setY(5);
    A.print();

    Point B(5,4);
    B.print();


    return 0;
}
