// Anagram Game Using Array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void sortString(char str[])
{
    int i, j;
    char temp;

    int len = strlen(str);

    for (i = 0; i < len - 1; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void main()
{
    int n, i, randomIndex;
    char words[20][50];
    char userWord[50];
    char temp1[50], temp2[50];

    printf("Enter number of words: ");
    scanf("%d", &n);

    printf("Enter %d words:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", words[i]);
    }

    srand(time(NULL));
    randomIndex = rand() % n;

    printf("\nWord Selected: %s\n", words[randomIndex]);
    printf("Enter its anagram: ");
    scanf("%s", userWord);

    strcpy(temp1, words[randomIndex]);
    strcpy(temp2, userWord);

    if (strlen(temp1) == strlen(temp2))
    {
        sortString(temp1);
        sortString(temp2);

        if (strcmp(temp1, temp2) == 0)
        {
            printf("Correct! %s is an anagram of %s\n", userWord, words[randomIndex]);
        }
        else
        {
            printf("Incorrect! %s is not an anagram of %s\n", userWord, words[randomIndex]);
        }
    }
    else
    {
        printf("Incorrect! %s is not an anagram of %s\n", userWord, words[randomIndex]);
    }
}

// **Example:**

// Enter number of words: 3
// LISTEN
// APPLE
// EARTH

// Word Selected: LISTEN
// Enter its anagram: SILENT
