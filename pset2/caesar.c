#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(string phrase, int key);

int main(int argc, string argv[])
{
    // Check to see if program was run with 1 command line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Iterate over argv[1] to make sure all chars are ints
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 0;
            }
        }
        // Take the key, convert to int
        int key = atoi(argv[1]);
        // Get phrase from user
        string plaintext = get_string("plaintext: ");
        encrypt(plaintext, key);
    }
}
// Loop through the phrase provided and increment each alphabetical char by the key. Keep case the same as provided.
void encrypt(string plaintext, int key)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // If not a letter, print the character
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        // Wrap from Z to A
        else if (isupper(plaintext[i]))
        {
            int letter = plaintext[i];
            letter = letter - 65;
            letter = letter + key;
            letter = letter % 26;
            letter = letter + 65;
            printf("%c", letter);
        }
        // Wrap from z to a
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i];
            letter = letter - 97;
            letter = letter + key;
            letter = letter % 26;
            letter = letter + 97;
            printf("%c", letter);
        }
    }
    printf("\n");
}