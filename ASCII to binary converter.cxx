#include <stdio.h>
#include <string.h>
#include <math.h>
void binary(int num)
{
    int i = 0, array[8];
    for (; num != 1 && num != 0; i++)
    {
        array[i] = num % 2;
        num /= 2;
    }
    array[i] = (num == 0) ? array[i] = 0 : array[i] = 1;
    while (i < 7)
    {
        array[++i] = 0;
    }
    for (int j = 7; j >= 0; j--)
    {
        printf("%d", array[j]);
    }
}

void ASCII(char bi[9])
{
    int val = 0, power, num;
    for (int i = 1; i < 9; i++)
    {
        power = pow(2, 8 - i);
        num = (bi[i - 1] == '1') ? 1 : 0;
        val += power * num;
    }
    printf("%c", (char)val);
}
int main()
{
    printf("This program can convert any character/string into binary and vice-vorsa\n");
    printf("This program works on 8 bits, as a character can store 1 byte (8 bits)\n");
    printf("Type binary for converting string into binary\n");
    printf("Type ASCII for converting binary into string\n");
again:
    char ask[7];
    char string[1000];
    printf("Enter type:");
    gets(ask);
    if (strcmp(ask, "binary") == 0 || strcmp(ask, "Binary") == 0)
    {
        for (;;)
        {
            printf("Enter string:");
            gets(string);
            for (int i = 0; i < strlen(string); i++)
            {
                binary((int)string[i]);
                printf(" ");
            }
            printf("\n");
        }
    }
    else if (strcmp(ask, "ASCII") == 0 || strcmp(ask, "ascii") == 0)
    {
        printf("Note- Every Binary character must be of 8 bits\n");
        for (;;)
        {
            printf("Enter Binary form:");
            gets(string);
            // Bunch of code for removing spaces
            int j = 0, i = 0;
            char bina[strlen(string)];
            for (; i < strlen(string); i++)
            {
                if (string[i] == '0' || string[i] == '1')
                {
                    bina[j++] = string[i];
                }
            }
            bina[j] = '\0';
            //Bunch of code for retriving 8 bit binary
            if (strlen(bina) != 0 && strlen(bina) % 8 == 0)
            {
                char array[9];
                int j = 0;
                for (int i = 0; i < strlen(string); i++)
                {
                    if (i != 0 && i % 8 == 0)
                    {
                        j = 0;
                        ASCII(array);
                    }
                    array[j++] = bina[i];
                }
            }
            else
                printf("Given binary form is incorrect\nPlease give every binary in 8 bits\nEx- If you want to give 1110 then you need to enter 00001110\n");
            printf("\n");
        }
    }
    else
        printf("Please enter Binary or ASCII only\n");
    goto again;
}