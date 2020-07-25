#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/* The Function is declared initially to ensure there's an explicit declaration */
void cipherText(int key, string plaintext);

int main(int argc, string argv[])
{
    /* Exception Check #1 - To check if exactly 2 arguments have been supplied in the command line */
    /* If yes, then the loop further widens and the length of the key argument is checked next */
    if (argc == 2)
    {
        int length = strlen(argv[1]);
        int counter = 0;
        string k = argv[1];
        for (int x = 0; x < length; x++)
        {
            /* Exception Check #2 - To check if the key has any non-integer characters and if so, then increment a counter so that if the counter is not 0, then we'll know that the key isn't valid */
            if (!isdigit(k[x]))
            {
                counter++;
            }
        }
        /* Final Exception Check - To ensure that encryption happens only if the key is a valid key */
        if (counter == 0)
        {
            /* Only if the key is valid, the key is converted to an integer */
            /* Otherwise, a return code of 1 is presented indicating deviation from the normal program flow */
            /* If it is a valid key, calls the encryption function passing key and the plaintext as the arguments */
            int key = atoi(k);
            if (key > 0)
            {
                string plaintext = get_string("plaintext: ");
                cipherText(key, plaintext);
                printf("\n");
                return 0;   
            }
            else
            {
                printf("Invalid key\n");
                return 1;
            }
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}

/* Function to encrypt the plaintext using the key and plaintext as arguments */

void cipherText(int key, string plaintext)
{
    int ptlength = strlen(plaintext);
    int cipherc;
    printf("ciphertext: ");
    /* If the key is greater than 26, it is reduced to a number within 26 by performing a modulus division against 26 */
    for (int x = 0; x < ptlength; x++)
    {
        /* A for loop to iterate over the characters in the Plain text string to check and manipulate upper case string, lower case string and non-alphabetic strings appropriately */
        if (isupper(plaintext[x]))
        {
            cipherc = plaintext[x] + (key % 26);

            /* If the cipher constant exceeds the last character constant's value, we subtract it with the last char constant's value and then push it from the first character constant's value
            so as to wrap the alphabets in a circular fashion */
            /* Example, if the plaintext character is z, if we add 5 to it, the result would be a non-alphabetic character according to the ASCII table */
            /* Hence, we subtract the value of (z's Integer value (90) + the key(5)) {95} with the last alphabet's integer value (90) yielding 5 (95-90), 
            since 5 is an alphabetic ascii character, to enter the alphabets again, we add the first alphabet's integer value(a = 65) -1, to the result, thus the answer becomes e */
            /* The same is repeated as per the casing of letters */

            if (cipherc > 90)
            {
                cipherc = (cipherc - 90) + 64;
            }
            printf("%c", toupper(cipherc));
        }
        else if (islower(plaintext[x]))
        {
            cipherc = plaintext[x] + (key % 26);
            if (cipherc > 122)
            {
                cipherc = (cipherc - 122) + 96;
            }
            printf("%c", tolower(cipherc));
        }
        else
        {
            printf("%c", plaintext[x]);
        }
    }
}
