#include <QCoreApplication>
#include <iostream>
#include <array>

using namespace std;

char *getline()
{

    char ch;
    u_int size(4);
    u_int count(1);

    char *result   = new char[4];

    while(cin.get(ch) && ch != '\n' )
    {
        if(count == size - 1)
         {
           size = size * 2;

           char *temp   = new char[size];

           for(u_int i(0); i < size; i++)
               {
                 temp[i] = result[i];
               }

             temp[count - 1] = ch;

             delete[] result;

             char *result = new char[size];

             for(u_int i(0);i < size;i++)
              {
                result[i] = temp[i];
              }

            delete[] temp;
        }

        if(count < size) //this work
          {
            for(u_int i(count - 1); i < count; i++)
              {
                result[i] = ch;
              }

          }

        count++;
    }

    result[size ] = '\0';

    for(u_int i(0); i != size; i++)
      {
        cout<<result[i];
      }
    return result;
}

int main()
{

  while(true)
    {
      getline();
    }

   return 0;
}

