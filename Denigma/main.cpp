#include <QCoreApplication>

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

int smallLetterChange(int lCharacterNumber, int lEncryptionLevel);
int bigLetterChange  (int lCharacterNumber, int lEncryptionLevel);
void cipher ();

std::ifstream gNotEncryptedFile;
std::ofstream gEncryptedFile;

int gSmallLetterEncryption (1);
int gBigLetterEncryption   (5);

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

    gEncryptedFile.open("EncryptedFile.txt");

    cipher();

    std::cout << " File is encrypted SUCCESSFULLY !!!" << '\n';

    gNotEncryptedFile.close();
    gEncryptedFile.close();

    return 0;
}

void cipher ()
{
    char lCharacter;
    int lCharacterNumber;


    while (gNotEncryptedFile.get(lCharacter))
    {

        int lEncryptionLevel  = 1;
        lCharacterNumber = static_cast <int> (lCharacter);

        if ((lCharacterNumber > 96) || (lCharacterNumber < 123))
        {

                lCharacterNumber = smallLetterChange(lCharacterNumber, lEncryptionLevel);

                lEncryptionLevel = 2;

                lCharacterNumber += gSmallLetterEncryption;

                lCharacterNumber = smallLetterChange(lCharacterNumber, lEncryptionLevel);

                while(lCharacterNumber  > 123)
                  {
                        lCharacterNumber = lCharacterNumber  - 122;
                  }

                lCharacter = static_cast <char> (lCharacterNumber);

          }


        if ((lCharacterNumber > 65) || (lCharacterNumber < 90))
        {
            lCharacterNumber = bigLetterChange(lCharacterNumber, lEncryptionLevel);

            lEncryptionLevel = 2;

            lCharacterNumber += gBigLetterEncryption;

            lCharacterNumber = bigLetterChange(lCharacterNumber, lEncryptionLevel);

            while(lCharacterNumber  > 91)
              {
                    lCharacterNumber = lCharacterNumber  - 90;
              }

            lCharacter = static_cast <char> (lCharacterNumber);
        }

        gEncryptedFile << lCharacterNumber;


    }
}

int smallLetterChange(int lCharacterNumber, int lEncryptionLevel)
{
    switch (lCharacterNumber)
    {
    case 'a' :
        if (lEncryptionLevel == 1)
        {
            return 'g';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber2 + gPasswordNumber3 - 14;
            return lCharacterNumber;
        }
        break;

    case 'b':
        if (lEncryptionLevel == 1)
        {
            return 'v';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber6 + gPasswordNumber1 - gPasswordNumber5;
            return lCharacterNumber;
        }
        break;

    case 'c':
        if (lEncryptionLevel == 1)
        {
            return 'w';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber5 - 5 * gPasswordNumber4;
            return lCharacterNumber;
        }
        break;

    case 'd':
        if (lEncryptionLevel == 1)
        {
            return 'x';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber3 + 10 + gPasswordNumber2 * 2;
            return lCharacterNumber;
        }
        break;

    case 'e':
        if (lEncryptionLevel == 1)
        {
            return 'y';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber1 * gPasswordNumber1 / 2 - 1;
            return lCharacterNumber;
        }
        break;

    case 'f':
        if (lEncryptionLevel == 1)
        {
            return 'z';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber2 + 2;
            return lCharacterNumber;
        }
        break;

    case 'g':
        if (lEncryptionLevel == 1)
        {
            return 'u';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber1;
            return lCharacterNumber;
        }
        break;

    case 'h':
        if (lEncryptionLevel == 1)
        {
            return 'p';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber2 % 3 ;
            return lCharacterNumber;
        }
        break;

    case 'i':
        if (lEncryptionLevel == 1)
        {
            return 'q';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber2 + 3;
            return lCharacterNumber;
        }
        break;

    case 'j':
        if (lEncryptionLevel == 1)
        {
            return 'r';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + pow(gPasswordNumber4, 2) + 4;
            return lCharacterNumber;
        }
        break;

    case 'k':
        if (lEncryptionLevel == 1)
        {
            return 's';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber3 + gPasswordNumber5 +gPasswordNumber6 + 8;
            return lCharacterNumber;
        }
        break;

    case 'l':
        if (lEncryptionLevel == 1)
        {
            return 't';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + 6* gPasswordNumber3 - gPasswordNumber1 - 7;
            return lCharacterNumber;
        }
        break;

    case 'm':
        if (lEncryptionLevel == 1)
        {
            return 'o';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber5 * gPasswordNumber4 - gPasswordNumber1 * 12 - 4;
            return lCharacterNumber;
        }
        break;

    case 'n':
        if (lEncryptionLevel == 1)
        {
            return 'h';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + pow(gPasswordNumber1, gPasswordNumber6) -
                    gPasswordNumber5 * gPasswordNumber3 * gPasswordNumber4 * gPasswordNumber2;
            return lCharacterNumber;
        }
        break;

    case 'o':
        if (lEncryptionLevel == 1)
        {
            return 'n';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber2 - 3 * gPasswordNumber3;
            return lCharacterNumber;
        }
        break;

    case 'p':
        if (lEncryptionLevel == 1)
        {
            return 'm';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber2 - 2 * gPasswordNumber6
                    + gPasswordNumber2 / 2;
            return lCharacterNumber;
        }
        break;

    case 'q':
        if (lEncryptionLevel == 1)
        {
            return 'l';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber1 * gPasswordNumber1 - 9 +
                    gPasswordNumber4;
            return lCharacterNumber;
        }
        break;

    case 'r':
        if (lEncryptionLevel == 1)
        {
            return 'k';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber1 + 3;
            return lCharacterNumber;
        }
        break;

    case 's':
        if (lEncryptionLevel == 1)
        {
            return 'j';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber3 - 3
                    + gPasswordNumber2 *gPasswordNumber5 % gPasswordNumber1;
            return lCharacterNumber;
        }
        break;

    case 't':
        if (lEncryptionLevel == 1)
        {
            return 'i';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber3;
            return lCharacterNumber;
        }
        break;

    case 'u':
        if (lEncryptionLevel == 1)
        {
            return 'f';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber2 + 7;
            return lCharacterNumber;
        }
        break;

     case 'v':
        if (lEncryptionLevel == 1)
        {
            return 'e';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber5 * gPasswordNumber1 / gPasswordNumber6;
            return lCharacterNumber;
        }
        break;

    case 'w':
        if (lEncryptionLevel == 1)
        {
            return 'd';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber1 - 11
                    + pow( abs(gPasswordNumber4 - gPasswordNumber2), abs( gPasswordNumber3 - gPasswordNumber3) );
            return lCharacterNumber;
        }
        break;

    case 'x':
        if (lEncryptionLevel == 1)
        {
            return 'c';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber5 - 5 * pow(2, gPasswordNumber6);
            return lCharacterNumber;
        }
        break;

    case 'y':
        if (lEncryptionLevel == 1)
        {
            return 'b';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + 3 * gPasswordNumber4 - 88;
            return lCharacterNumber;
        }
        break;

    case 'z':
        if (lEncryptionLevel == 1)
        {
            return 'a';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += lCharacterNumber + gPasswordNumber5 + 5*gPasswordNumber2 - 121;
            return lCharacterNumber;
        }
        break;
    }

    return lCharacterNumber;
}

int BigLetterChange(int lCharacterNumber, int lEncryptionLevel)
{
    switch (lCharacterNumber)
    {
    case 'A' :
        if (lEncryptionLevel == 1)
        {
            return 'I';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber1 + gPasswordNumber5 - 14;
            return lCharacterNumber;
        }
        break;

    case 'B':
        if (lEncryptionLevel == 1)
        {
            return 'O';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber2 + 2 * gPasswordNumber3 - gPasswordNumber4 - 33;
            return lCharacterNumber;
        }
        break;

    case 'C':
        if (lEncryptionLevel == 1)
        {
            return 'B';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber2 - 3 * gPasswordNumber3;
            return lCharacterNumber;
        }
        break;

    case 'D':
        if (lEncryptionLevel == 1)
        {
            return 'S';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber1 + 2 * gPasswordNumber2  - 41;
            return lCharacterNumber;
        }
        break;

    case 'E':
        if (lEncryptionLevel == 1)
        {
            return 'V';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber5 * gPasswordNumber3  - 15;
            return lCharacterNumber;
        }
        break;

    case 'F':
        if (lEncryptionLevel == 1)
        {
            return 'R';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber2 + 2;
            return lCharacterNumber;
        }
        break;

    case 'G':
        if (lEncryptionLevel == 1)
        {
            return 'K';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 3 * gPasswordNumber3;
            return lCharacterNumber;
        }
        break;

    case 'H':
        if (lEncryptionLevel == 1)
        {
            return 'L';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 4 * gPasswordNumber5 % 3 ;
            return lCharacterNumber;
        }
        break;

    case 'I':
        if (lEncryptionLevel == 1)
        {
            return 'G';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber2 + 11;
            return lCharacterNumber;
        }
        break;

    case 'J':
        if (lEncryptionLevel == 1)
        {
            return 'T';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + pow(gPasswordNumber4, 3) + 34;
            return lCharacterNumber;
        }
        break;

    case 'K':
        if (lEncryptionLevel == 1)
        {
            return 'A';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber2 + gPasswordNumber6 - 18;
            return lCharacterNumber;
        }
        break;

    case 'L':
        if (lEncryptionLevel == 1)
        {
            return 'X';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 6* gPasswordNumber3 - 5 * gPasswordNumber1 - 7;
            return lCharacterNumber;
        }
        break;

    case 'M':
        if (lEncryptionLevel == 1)
        {
            return 'Z';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 3 * gPasswordNumber3 - gPasswordNumber6  - 14;
            return lCharacterNumber;
        }
        break;

    case 'N':
        if (lEncryptionLevel == 1)
        {
            return 'U';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber +  3 * gPasswordNumber4 * gPasswordNumber2 - 21;
            return lCharacterNumber;
        }
        break;

    case 'O':
        if (lEncryptionLevel == 1)
        {
            return 'J';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber2 - 3 * gPasswordNumber3;
            return lCharacterNumber;
        }
        break;

    case 'P':
        if (lEncryptionLevel == 1)
        {
            return 'C';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber2 - 4 * gPasswordNumber5
                    + gPasswordNumber3;
            return lCharacterNumber;
        }
        break;

    case 'Q':
        if (lEncryptionLevel == 1)
        {
            return 'M';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber3 * gPasswordNumber2 - 9;
            return lCharacterNumber;
        }
        break;

    case 'R':
        if (lEncryptionLevel == 1)
        {
            return 'N';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 4 * gPasswordNumber2 - 34;
            return lCharacterNumber;
        }
        break;

    case 'S':
        if (lEncryptionLevel == 1)
        {
            return 'Y';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber4 - 6
                    + gPasswordNumber3 *gPasswordNumber5 % gPasswordNumber1;
            return lCharacterNumber;
        }
        break;

    case 'T':
        if (lEncryptionLevel == 1)
        {
            return 'W';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber5 + 33;
            return lCharacterNumber;
        }
        break;

    case 'U':
        if (lEncryptionLevel == 1)
        {
            return 'Q';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 2 * gPasswordNumber6 - 17;
            return lCharacterNumber;
        }
        break;

     case 'V':
        if (lEncryptionLevel == 1)
        {
            return 'D';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 3 * gPasswordNumber2 * gPasswordNumber3 % gPasswordNumber6;
            return lCharacterNumber;
        }
        break;

    case 'W':
        if (lEncryptionLevel == 1)
        {
            return 'E';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + gPasswordNumber1 - 11 + gPasswordNumber5 * 2;
            return lCharacterNumber;
        }
        break;

    case 'X':
        if (lEncryptionLevel == 1)
        {
            return 'H';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 10 * gPasswordNumber5 - 9 * gPasswordNumber3 ;
            return lCharacterNumber;
        }
        break;

    case 'Y':
        if (lEncryptionLevel == 1)
        {
            return 'P';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber - 2 * gPasswordNumber2 + 65;
            return lCharacterNumber;
        }
        break;

    case 'Z':
        if (lEncryptionLevel == 1)
        {
            return 'F';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += lCharacterNumber + 3 * gPasswordNumber4 - 2 * gPasswordNumber1 - 89;
            return lCharacterNumber;
        }
        break;
    }

    return lCharacterNumber;
}

