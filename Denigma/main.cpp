#include <QCoreApplication>

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

void encryption ();
void decryption ();

int smallLetterChange(int lCharacterNumber, int lEncryptionLevel);
int bigLetterChange  (int lCharacterNumber, int lEncryptionLevel);

std::fstream gNotEncryptedFile;

std::fstream gEncryptedFile;

std::fstream gDecryptedFile;

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

    while (true)
    {
        int choise;
        std::cout << " Input :\n "
                  << "1 to encrypt file\n"
                  << "2 to decrypt file\n";
        std::cin >> choise;

        if (choise == 1)
        {
                std::ofstream gEncryptedFile;

                std::cout<<"Encryption:\n";
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


            std::cout << "Enter Passsword\n"
                      << "Example : 1 2 3 4 5 6\n";

            std::cin >> gPasswordNumber1;
            std::cin >> gPasswordNumber2;
            std::cin >> gPasswordNumber3;
            std::cin >> gPasswordNumber4;
            std::cin >> gPasswordNumber5;
            std::cin >> gPasswordNumber6;

            gEncryptedFile.open("EncryptedFile.txt");

            encryption();

            std::cout << " File is encrypted SUCCESSFULLY !!!" << '\n';

            gNotEncryptedFile.close();
            gEncryptedFile.close();

        }

        if(choise == 2)
        {
                std::ofstream gNotEncryptedFile;

                std::cout << "Decryption\n";
                std::cout << " Set path to file : " << '\n';
                std::cout << " Example          : path / to / file / filename.txt" << '\n';
                std::cin  >> lPathToFile;

                gEncryptedFile.open(lPathToFile , std::ofstream::app);

                if(gEncryptedFile.is_open())
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

            gDecryptedFile.open("DecryptedFile.txt");

            decryption();

            std::cout << " File is dencrypted SUCCESSFULLY !!!" << '\n';

            gDecryptedFile.close();
            gEncryptedFile.close();
    }
    return 0;
}

void encryption ()
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
                        lCharacterNumber = lCharacterNumber  - 26;
                  }

                while(lCharacterNumber  < 96)
                  {
                        lCharacterNumber = lCharacterNumber  + 26;
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
                    lCharacterNumber = lCharacterNumber  - 26;
              }
            while(lCharacterNumber  < 65)
              {
                    lCharacterNumber = lCharacterNumber  + 26;
              }

            lCharacter = static_cast <char> (lCharacterNumber);
        }

        gEncryptedFile << lCharacterNumber;
    }
}

void decryption ()
{
    char lCharacter;
    int lCharacterNumber;

    while (gEncryptedFile.get(lCharacter))
    {

        int lEncryptionLevel  = 2;
        lCharacterNumber = static_cast <int> (lCharacter);

        if ((lCharacterNumber > 96) || (lCharacterNumber < 123))
        {
                lCharacterNumber -= gSmallLetterEncryption;
                lCharacterNumber = smallLetterChange(lCharacterNumber, lEncryptionLevel);

                while(lCharacterNumber  > 123)
                  {
                        lCharacterNumber = lCharacterNumber  - 26;
                  }

                while(lCharacterNumber  < 96)
                  {
                        lCharacterNumber = lCharacterNumber  + 26;
                  }

                lEncryptionLevel = 3;
                lCharacterNumber = smallLetterChange(lCharacterNumber, lEncryptionLevel);
          }


        if ((lCharacterNumber > 65) || (lCharacterNumber < 90))
        {

            lCharacterNumber -= gBigLetterEncryption;

            lCharacterNumber = bigLetterChange(lCharacterNumber, lEncryptionLevel);

            while(lCharacterNumber  > 91)
              {
                    lCharacterNumber = lCharacterNumber  - 90;
              }

            lEncryptionLevel = 3;
            lCharacterNumber = bigLetterChange(lCharacterNumber, lEncryptionLevel);
        }

        lCharacter = static_cast <char> (lCharacterNumber);
        gDecryptedFile << lCharacterNumber;
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
            gSmallLetterEncryption +=   gPasswordNumber2 + gPasswordNumber3 - 14;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'z';
        }
        break;

    case 'b':
        if (lEncryptionLevel == 1)
        {
            return 'v';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=  gPasswordNumber6 + gPasswordNumber1 - gPasswordNumber5;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'y';
        }
        break;

    case 'c':
        if (lEncryptionLevel == 1)
        {
            return 'w';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber5 - 5 * gPasswordNumber4;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'x';
        }
        break;

    case 'd':
        if (lEncryptionLevel == 1)
        {
            return 'x';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=  gPasswordNumber3 + 10 + gPasswordNumber2 * 2;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'w';
        }
        break;

    case 'e':
        if (lEncryptionLevel == 1)
        {
            return 'y';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=  gPasswordNumber1 * gPasswordNumber1 / 2 - 1;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'v';
        }
        break;

    case 'f':
        if (lEncryptionLevel == 1)
        {
            return 'z';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=  gPasswordNumber2 + 2;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'u';
        }
        break;

    case 'g':
        if (lEncryptionLevel == 1)
        {
            return 'u';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=  gPasswordNumber1;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'a';
        }
        break;

    case 'h':
        if (lEncryptionLevel == 1)
        {
            return 'p';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber2 % 3 ;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'n';
        }
        break;

    case 'i':
        if (lEncryptionLevel == 1)
        {
            return 'q';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=  gPasswordNumber2 + 3;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 't';
        }
        break;

    case 'j':
        if (lEncryptionLevel == 1)
        {
            return 'r';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=  pow(gPasswordNumber4, 2) + 4;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 's';
        }
        break;

    case 'k':
        if (lEncryptionLevel == 1)
        {
            return 's';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=   gPasswordNumber3 + gPasswordNumber5 +gPasswordNumber6 + 8;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'r';
        }
        break;

    case 'l':
        if (lEncryptionLevel == 1)
        {
            return 't';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption +=  6* gPasswordNumber3 - gPasswordNumber1 - 7;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'q';
        }
        break;

    case 'm':
        if (lEncryptionLevel == 1)
        {
            return 'o';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber5 * gPasswordNumber4 - gPasswordNumber1 * 12 - 4;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'p';
        }
        break;

    case 'n':
        if (lEncryptionLevel == 1)
        {
            return 'h';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += pow(gPasswordNumber1, gPasswordNumber6) -
                    gPasswordNumber5 * gPasswordNumber3 * gPasswordNumber4 * gPasswordNumber2;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'o';
        }
        break;

    case 'o':
        if (lEncryptionLevel == 1)
        {
            return 'n';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber2 - 3 * gPasswordNumber3;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'm';
        }
        break;

    case 'p':
        if (lEncryptionLevel == 1)
        {
            return 'm';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber2 - 2 * gPasswordNumber6
                    + gPasswordNumber2 / 2;
            break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'h';
        }
        break;

    case 'q':
        if (lEncryptionLevel == 1)
        {
            return 'l';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber1 * gPasswordNumber1 - 9 +
                    gPasswordNumber4;
             break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'i';
        }
        break;

    case 'r':
        if (lEncryptionLevel == 1)
        {
            return 'k';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber1 + 3;
             break;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'j';
        }
        break;

    case 's':
        if (lEncryptionLevel == 1)
        {
            return 'j';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber3 - 3
                    + gPasswordNumber2 *gPasswordNumber5 % gPasswordNumber1;
             ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'k';
        }
        break;

    case 't':
        if (lEncryptionLevel == 1)
        {
            return 'i';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber3;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'l';
        }
        break;

    case 'u':
        if (lEncryptionLevel == 1)
        {
            return 'f';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber2 + 7;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'g';
        }
        break;

     case 'v':
        if (lEncryptionLevel == 1)
        {
            return 'e';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber5 * gPasswordNumber1 / gPasswordNumber6;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'b';
        }
        break;

    case 'w':
        if (lEncryptionLevel == 1)
        {
            return 'd';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber1 - 11
                    + pow( abs(gPasswordNumber4 - gPasswordNumber2), abs( gPasswordNumber3 - gPasswordNumber3 + 1) );
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'c';
        }
        break;

    case 'x':
        if (lEncryptionLevel == 1)
        {
            return 'c';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber5 - 5 * pow(2, gPasswordNumber6);
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'd';
        }
        break;

    case 'y':
        if (lEncryptionLevel == 1)
        {
            return 'b';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += 3 * gPasswordNumber4 - 88;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'e';
        }
        break;

    case 'z':
        if (lEncryptionLevel == 1)
        {
            return 'a';
        }
        else if (lEncryptionLevel == 2)
        {
            gSmallLetterEncryption += gPasswordNumber5 + 5*gPasswordNumber2 - 121;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'f';
        }
        break;
    }

    return lCharacterNumber;
}

int bigLetterChange(int lCharacterNumber, int lEncryptionLevel)
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
            gBigLetterEncryption += gPasswordNumber1 / gPasswordNumber5 - 14;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'K';
        }
        break;

    case 'B':
        if (lEncryptionLevel == 1)
        {
            return 'O';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber2 + 2 * gPasswordNumber3 - gPasswordNumber4 - 33;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'C';
        }
        break;

    case 'C':
        if (lEncryptionLevel == 1)
        {
            return 'B';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber2 - 3 * gPasswordNumber3;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'P';
        }
        break;

    case 'D':
        if (lEncryptionLevel == 1)
        {
            return 'S';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber1 + 2 * gPasswordNumber2  - 41;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'V';
        }
        break;

    case 'E':
        if (lEncryptionLevel == 1)
        {
            return 'V';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber5 * gPasswordNumber3  - 15;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'W';
        }
        break;

    case 'F':
        if (lEncryptionLevel == 1)
        {
            return 'R';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber2 + 2;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'Z';
        }
        break;

    case 'G':
        if (lEncryptionLevel == 1)
        {
            return 'K';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 3 * gPasswordNumber3;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'I';
        }
        break;

    case 'H':
        if (lEncryptionLevel == 1)
        {
            return 'L';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 4 * gPasswordNumber5 % 3 ;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'X';
        }
        break;

    case 'I':
        if (lEncryptionLevel == 1)
        {
            return 'G';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber2 + 11;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'A';
        }
        break;

    case 'J':
        if (lEncryptionLevel == 1)
        {
            return 'T';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += pow(gPasswordNumber4, 3) + 34;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'O';
        }
        break;

    case 'K':
        if (lEncryptionLevel == 1)
        {
            return 'A';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber2 + gPasswordNumber6 - 18;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'G';
        }
        break;

    case 'L':
        if (lEncryptionLevel == 1)
        {
            return 'X';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 6* gPasswordNumber3 - 5 * gPasswordNumber1 - 7;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'H';
        }
        break;

    case 'M':
        if (lEncryptionLevel == 1)
        {
            return 'Z';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 3 * gPasswordNumber3 - gPasswordNumber6  - 14;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'Q';
        }
        break;

    case 'N':
        if (lEncryptionLevel == 1)
        {
            return 'U';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 3 * gPasswordNumber4 * gPasswordNumber2 - 21;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'R';
        }
        break;

    case 'O':
        if (lEncryptionLevel == 1)
        {
            return 'J';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber2 - 3 * gPasswordNumber3;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'B';
        }
        break;

    case 'P':
        if (lEncryptionLevel == 1)
        {
            return 'C';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber2 - 4 * gPasswordNumber5
                    + gPasswordNumber3;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'Y';
        }
        break;

    case 'Q':
        if (lEncryptionLevel == 1)
        {
            return 'M';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber3 * gPasswordNumber2 - 9;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'Q';
        }
        break;

    case 'R':
        if (lEncryptionLevel == 1)
        {
            return 'N';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 4 * gPasswordNumber2 - 34;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'F';
        }
        break;

    case 'S':
        if (lEncryptionLevel == 1)
        {
            return 'Y';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber4 - 6
                    + gPasswordNumber3 *gPasswordNumber5 % gPasswordNumber1;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'D';
        }
        break;

    case 'T':
        if (lEncryptionLevel == 1)
        {
            return 'W';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber5 + 33;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'J';
        }
        break;

    case 'U':
        if (lEncryptionLevel == 1)
        {
            return 'Q';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 2 * gPasswordNumber6 - 17;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'N';
        }
        break;

     case 'V':
        if (lEncryptionLevel == 1)
        {
            return 'D';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 3 * gPasswordNumber2 * gPasswordNumber3 % gPasswordNumber6;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'E';
        }
        break;

    case 'W':
        if (lEncryptionLevel == 1)
        {
            return 'E';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += gPasswordNumber1 - 11 + gPasswordNumber5 * 2;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'T';
        }
        break;

    case 'X':
        if (lEncryptionLevel == 1)
        {
            return 'H';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 10 * gPasswordNumber5 - 9 * gPasswordNumber3 ;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'L';
        }
        break;

    case 'Y':
        if (lEncryptionLevel == 1)
        {
            return 'P';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += -2 * gPasswordNumber2 + 65;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'S';
        }
        break;

    case 'Z':
        if (lEncryptionLevel == 1)
        {
            return 'F';
        }
        else if (lEncryptionLevel == 2)
        {
            gBigLetterEncryption += 3 * gPasswordNumber4 - 2 * gPasswordNumber1 - 89;
            break ;
        }
        else if (lEncryptionLevel == 3)
        {
            return 'M';
        }
        break;
    }
    return lCharacterNumber;
}

