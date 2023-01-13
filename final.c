#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

void encryption(char text[100], char key[100], int keylength);
void decryption(char text[100], char key[100], int keylength);


int main(void)

{

    printf("           \\\\      //  ||   ======   ||====  ||\\\\   ||  ||====   ||===|   ||====    \n");
    printf("            \\\\    //   ||   ||       ||      || \\\\  ||  ||       ||===|   ||       \n");
    printf("             \\\\  //    ||   ||  -|   ||==    ||  \\\\ ||  ||==     ||\\\\     ||==     \n");
    printf("              \\\\//     ||   ||__-|   ||====  ||   \\\\||  ||====   || \\\\    ||====    \n");

    //Taking key value
    int i, keylength, keyrepeat;
    char key[100];
    char text[100];
    //while(x = 1)
    //{

    printf("\n\n                    Enter key: ");
    gets(key);
    keylength = strlen(key);

    printf("\n                    Enter text: ");
    gets(text);

    // asking for encrypt

    char check;
    printf("\n\n                    Enter 1 for encrption\n\n                    Enter 2 for decryption\n\n                     ==> ");
    scanf("%c", &check);

    //counting letters
    int len = strlen(text);

    if (check == '1')
    {
        encryption(text, key, keylength);
    }
    else if (check == '2')
    {
        decryption(text, key, keylength);
    }

    else
    {
        printf("\n\n                    Error!!! PLEASE ENTER CORRECT KEY");
    }

    printf("\n\n                    THANK YOU FOR USING VIGENERE CIPHER!!!");

    getch();
}

void decryption(char text[100], char key[100], int keylength)
{
    int keyrepeat, i, len = strlen(text);
    printf("\n\n                    Decrypted text:  ");
    for (i = 0, keyrepeat = 0; i < len; i++)
    {
        //keyrepeat used to iterate through the given key
        char c = text[i];
        int d = text[i];
        //for alphabetic characters
        if (isalpha(c))
        { //for uppercase letters

            if (keyrepeat >= keylength) //this condition repeats the loop if keyrepeat is greater or equal than the given key
            {
                keyrepeat = 0;
            }
            if (isupper(c))
            {
                char m = 'A';
                printf("%c", (((c - m) - (toupper(key[keyrepeat]) - 'A')) + 26) % 26 + m);
            }
            //for lowerrcase letters
            if (islower(c))
            {
                char m = 'a';
                printf("%c", (((c - m) - (toupper(key[keyrepeat]) - 'A')) + 26) % 26 + m);
                //printf("(%d)", toupper(key[keyrepeat]) - 'A');
            }

            keyrepeat++;
        }
        //for numbers
        if (isdigit(c))
        {
            printf("%d", (c - 48));
        }
        //for no alpha numeric characters
        if (!isalnum(c))
        {
            printf("%c", c);
        }
    }
}
void encryption(char text[100], char key[100], int keylength)
{

    int keyrepeat, i, len = strlen(text);
    printf("\n\n                    Encrypted text: ");

    for (i = 0, keyrepeat = 0; i < len; i++)
    {
        //keyrepeat used to iterate through the given key
        char c = text[i];
        int d = text[i];
        //for alphabetic characters
        if (isalpha(c))
        { //for uppercase letters

            if (keyrepeat >= keylength) //this condition repeats the loop if keyrepeat is greater or equal than the given key
            {
                keyrepeat = 0;
            }
            if (isupper(c))
            {
                char m = 'A';
                printf("%c", (c - m + toupper(key[keyrepeat]) - 'A') % 26 + m);
            }
            //for lowerrcase letters
            if (islower(c))
            {
                char m = 'a';
                printf("%c", (c - m + toupper(key[keyrepeat]) - 'A') % 26 + m);
                // printf("%d", keyrepeat);
            }

            keyrepeat++;
        }
        //for numbers
        if (isdigit(c))
        {
            printf("%d", (c - 48));
        }
        //for no alpha numeric characters
        if (!isalnum(c))
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
