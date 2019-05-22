#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(string plaintext, string keyword);
int j;
int k;
int l = 0;

int main(int argc, string argv[])
{
    // Check to see if program was run with 1 command line argument
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        // Iterate over argv[1] to make sure all chars are chars
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
    }
    // Declare keyword as the second argument passed by the user at runtime
    string keyword = argv[1];
    // Get plaintext phrase from user
    string plaintext = get_string("plaintext: ");
    // Cipher the plaintext by the shiftvalue
    encrypt(plaintext, keyword);
}

void encrypt(string plaintext, string keyword)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            j = (l % strlen(keyword));
            k = (tolower(keyword[j]) - 97);
            printf("%i", k);
            printf("%c", (((plaintext[i] + k) - 97) % 26) + 97);
            l += 1;
        }

        else if (isupper(plaintext[i]))
        {
            j = (l % strlen(keyword));
            k = (tolower(keyword[j]) - 97);
            printf("%c", (((plaintext[i] + k) - 65) % 26) + 65);
            l += 1;
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
