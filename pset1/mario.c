#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string spaces = " ";
    string block = "#";
    string gap = "  ";
    int height;
do {
    height = get_int("Please enter a height: ");
} while(height <= 0 || height > 8);

    for (int row = 0; row < height; row++)
    {

        for (int i = row; i < height - 1; i++)
        {
            printf("%s", spaces);
        }
        for (int j = 0; j < row + 1; j++)
        {
            printf("%s", block);
        }
        printf("%s", gap);

        for (int j = 0; j < row + 1; j++)
        {
            printf("%s", block);
        }
                for (int i = row; i < height - 1; i++)
        {
            printf("%s", spaces);
        }
        printf("\n");
    }
}