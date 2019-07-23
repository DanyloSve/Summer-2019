#include <QCoreApplication>
#include <iostream>


char *getline()
{

    char ch;
    u_int buffer(4);
    u_int count(1);

    char *result   = new char[4];

    while(std::cin.get(ch) && ch != '\n' )
    {
        if(count == buffer - 1)
         {
            buffer *= 2;

            char *temp   = new char[size];

             memcpu(temp, result, buffer);

             temp[count - 1] = ch;

             delete[] result;

             char *result = new char[size];

             memcpu(result, temp, buffer);
            delete[] temp;
        }

        if(count < buffer)
          {
            for(u_int i(count - 1); i < count; i++)
              {
                result[i] = ch;
              }

          }

        count++;
    }

    result[buffer] = '\0';

    for(u_int i(0); i != buffer; i++)
      {
        std::cout<<result[i];
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

