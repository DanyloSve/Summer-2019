#include <iostream>

class MyClass
{
private:
    int *mData;
public:
    MyClass(int size)
    {
        mData = new int [size];

        for (int i(0); i < size; i++)
        {
            mData[i] = i;
        }
        std::cout << "Object : " << mData << " Constructor!\n";
    }

    ~MyClass()  //Деструктори є лише без параметрів! Д - р видаляє...
    {
        delete [] mData; //видаляється динамічна пам'ять
        std::cout <<"Object : " << mData << " Destuctor!\n";
    }
};

void foo()
{
    std::cout << "Foo start\n";
    MyClass A(1);;
    std::cout << "Foo end\n";
} //тут об'єкт А видалиться

int main()
{
    foo();
    MyClass B(2);

    return 0;
} //тут об'єкт B видалиться
