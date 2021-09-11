#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc != 2) // 2 strings needed to run program
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26) //checks if the key has 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

for (int i = 0, len = strlen(argv[1]); i < len; i++) // checks if the key only has alphabetic
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }

             for (int j = i + 1; j < len; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j])) //checks if the key has dultipate characters
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("Plaintext: "); //gets plaintext

    int length = strlen(plaintext);

    char text[length]; //Array that contains all characters in plaintext

    printf("ciphertext: ");


    for (int i = 0; i < length; i++) // initilizes counter for use in the code below
    {
        int character = plaintext[i]; //convert plaintext character to integer value

        if (isupper(plaintext[i]))
        {
            text[i] = toupper(argv[1][character - 65]); // Use integer values to determine the text for uppercase letters
            printf("%c", text[i]);
        }

        if (islower(plaintext[i]))
        {
            text[i] = tolower(argv[1][character - 97]); // Use integer values to determine the text for lowercase letters
            printf("%c", text[i]);
        }

        if (!isalpha(plaintext[i])) //character such as punctuatio remain the same
        {
            text[i] = plaintext[i]; //character in plaintext is equal to the enchyered text
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}
