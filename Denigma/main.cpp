#include <QCoreApplication>

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

int letterChange(int lCharacterNumber, int gEncruptionLevel);
void cipher ();

std::ifstream gNotEncryptedFile;
std::ofstream gEncryptedFile;

int gEncruptionLevel (1);
int gEncryption      (1);

int gPasswordNumber1 (0);
int gPasswordNumber2 (0);
int gPasswordNumber3 (0);
int gPasswordNumber4 (0);
int gPasswordNumber5 (0);
int gPasswordNumber6 (0);

int main()
{
    std::string lPathToFile;


    while(true)
    {
        std::cout << " Set path to file : " << '\n';
        std::cout << " Example          : path / to / file / filename.txt" << '\n';
        std::cin  >> lPathToFile;


        gNotEncryptedFile.open(lPathToFile , std::ofstream::app);

        if(gNotEncryptedFile.is_open())
        {
            std::cout << "File" << ' ' << lPathToFile
                      << " is SUCCESSFULLY opened !\n";
            break;
        }
        else
        {
            std::cout << " File is NOT opened ! " << '\n'
                      << " Try one more time :  " << '\n';
        }
    }

    std::cout << "Enter Passsword\n"
              << "Example : 1 2 3 4 5 6\n";
    std::cin >> gPasswordNumber1;
    std::cin >> gPasswordNumber2;
    std::cin >> gPasswordNumber3;
    std::cin >> gPasswordNumber4;
    std::cin >> gPasswordNumber5;
    std::cin >> gPasswordNumber6;

    gEncryptedFile.open(lPathToFile);
    cipher();

    std::cout << " File is encrypted SUCCESSFULLY !!!" << '\n';

    gNotEncryptedFile.close();
    gEncryptedFile.close();

    return 0;
}

void cipher ()
{
    char lCharacter;
    int  lCharacterNumber;

    while (gNotEncryptedFile.get(lCharacter))
    {

        gEncruptionLevel = 1;
        lCharacterNumber = static_cast <int> (lCharacter);

        lCharacterNumber += gEncryption;

        lCharacterNumber = letterChange(lCharacterNumber, gEncruptionLevel);

            gEncruptionLevel = 2;
            lCharacterNumber = letterChange(lCharacterNumber, gEncruptionLevel);


            while(lCharacterNumber  > 123)
            {
                lCharacterNumber = lCharacterNumber  - 122;
            }

            lCharacter = static_cast <char> (lCharacterNumber);
            gEncryptedFile << lCharacterNumber;


    }

}


int letterChange(int lCharacterNumber, int gEncruptionLevel)
{
    switch (lCharacterNumber)
    {
    case 'a' :
        if (gEncruptionLevel == 1)
        {
            return 'g';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber2+ gPasswordNumber3 - 14;
            return lCharacterNumber;
        }
        break;

    case 'b':
        if (gEncruptionLevel == 1)
        {
            return 'v';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber6 + gPasswordNumber1 - gPasswordNumber5;
            return lCharacterNumber;
        }
        break;

    case 'c':
        if (gEncruptionLevel == 1)
        {
            return 'w';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber5 - 5 * gPasswordNumber4;
            return lCharacterNumber;
        }
        break;

    case 'd':
        if (gEncruptionLevel == 1)
        {
            return 'x';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber3 + 10 + gPasswordNumber2 * 2;
            return lCharacterNumber;
        }
        break;

    case 'e':
        if (gEncruptionLevel == 1)
        {
            return 'y';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber1 * gPasswordNumber1 / 2 - 1;
            return lCharacterNumber;
        }
        break;

    case 'f':
        if (gEncruptionLevel == 1)
        {
            return 'z';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber2 + 2;
            return lCharacterNumber;
        }
        break;

    case 'g':
        if (gEncruptionLevel == 1)
        {
            return 'u';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber1;
            return lCharacterNumber;
        }
        break;

    case 'h':
        if (gEncruptionLevel == 1)
        {
            return 'p';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber2 % 3 ;
            return lCharacterNumber;
        }
        break;

    case 'i':
        if (gEncruptionLevel == 1)
        {
            return 'q';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber2 + 3;
            return lCharacterNumber;
        }
        break;

    case 'j':
        if (gEncruptionLevel == 1)
        {
            return 'r';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + pow(gPasswordNumber4, 2) + 4;
            return lCharacterNumber;
        }
        break;

    case 'k':
        if (gEncruptionLevel == 1)
        {
            return 's';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber3 + gPasswordNumber5 +gPasswordNumber6 + 8;
            return lCharacterNumber;
        }
        break;

    case 'l':
        if (gEncruptionLevel == 1)
        {
            return 't';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + 6* gPasswordNumber3 - gPasswordNumber1 - 7;
            return lCharacterNumber;
        }
        break;

    case 'm':
        if (gEncruptionLevel == 1)
        {
            return 'o';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber5 * gPasswordNumber4 - gPasswordNumber1 * 12 - 4;
            return lCharacterNumber;
        }
        break;

    case 'n':
        if (gEncruptionLevel == 1)
        {
            return 'h';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + pow(gPasswordNumber1, gPasswordNumber6) -
                    gPasswordNumber5 * gPasswordNumber3 * gPasswordNumber4 * gPasswordNumber2;
            return lCharacterNumber;
        }
        break;

    case 'o':
        if (gEncruptionLevel == 1)
        {
            return 'n';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber2 - 3 * gPasswordNumber3;
            return lCharacterNumber;
        }
        break;

    case 'p':
        if (gEncruptionLevel == 1)
        {
            return 'm';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber2 - 2 * gPasswordNumber6
                    + gPasswordNumber2 / 2;
            return lCharacterNumber;
        }
        break;

    case 'q':
        if (gEncruptionLevel == 1)
        {
            return 'l';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber1 * gPasswordNumber1 - 9 +
                    gPasswordNumber4;
            return lCharacterNumber;
        }
        break;

    case 'r':
        if (gEncruptionLevel == 1)
        {
            return 'k';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber1 + 3;
            return lCharacterNumber;
        }
        break;

    case 's':
        if (gEncruptionLevel == 1)
        {
            return 'j';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber3 - 3
                    + gPasswordNumber2 *gPasswordNumber5 % gPasswordNumber1;
            return lCharacterNumber;
        }
        break;

    case 't':
        if (gEncruptionLevel == 1)
        {
            return 'i';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber3;
            return lCharacterNumber;
        }
        break;

    case 'u':
        if (gEncruptionLevel == 1)
        {
            return 'f';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber2 + 7;
            return lCharacterNumber;
        }
        break;

     case 'v':
        if (gEncruptionLevel == 1)
        {
            return 'e';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber5 * gPasswordNumber1 / gPasswordNumber6;
            return lCharacterNumber;
        }
        break;

    case 'w':
        if (gEncruptionLevel == 1)
        {
            return 'd';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber1 - 11
                    + pow( abs(gPasswordNumber4 - gPasswordNumber2), abs( gPasswordNumber3 - gPasswordNumber3) );
            return lCharacterNumber;
        }
        break;

    case 'x':
        if (gEncruptionLevel == 1)
        {
            return 'c';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber5 - 5 * pow(2, gPasswordNumber6);
            return lCharacterNumber;
        }
        break;

    case 'y':
        if (gEncruptionLevel == 1)
        {
            return 'b';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + 3 * gPasswordNumber4 - 88;
            return lCharacterNumber;
        }
        break;

    case 'z':
        if (gEncruptionLevel == 1)
        {
            return 'a';
        }
        else if (gEncruptionLevel == 2)
        {
            gEncryption += lCharacterNumber + gPasswordNumber5 + 5*gPasswordNumber2 - 121;
            return lCharacterNumber;
        }
        break;
    }

    return lCharacterNumber;

}
