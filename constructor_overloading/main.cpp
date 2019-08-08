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
  }

  Point(int x, int y)
  {
      mX = x;
      mY = y;
  }

  void print()
  {
      std::cout << mX << ' ' << mY << '\n';
  }
};

int main()
{
    Point A;
    A.print();

    Point B(5,4);
    B.print();

    return 0;
}
