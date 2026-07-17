#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char name[50];
    struct Song *prev;
    struct Song *next;
};

struct Song *FIRST = NULL;
struct Song *LAST = NULL;
struct Song *CURRENT = NULL;

void addSong()
{
    struct Song *NEWNODE;

    NEWNODE = (struct Song *)malloc(sizeof(struct Song));

    printf("Enter Song Name: ");
    scanf(" %[^\n]", NEWNODE->name);

    NEWNODE->next = NULL;
    NEWNODE->prev = NULL;

    if (FIRST == NULL)
    {
        FIRST = LAST = NEWNODE;
    }
    else
    {
        LAST->next = NEWNODE;
        NEWNODE->prev = LAST;
        LAST = NEWNODE;
    }

    if (CURRENT == NULL)
        CURRENT = FIRST;

    printf("Song Added Successfully.\n");
}

void displayPlaylist()
{
    struct Song *TEMP;

    if (FIRST == NULL)
    {
        printf("Playlist is Empty.\n");
        return;
    }

    TEMP = FIRST;

    printf("\n------ Playlist ------\n");

    while (TEMP != NULL)
    {
        printf("%s\n", TEMP->name);
        TEMP = TEMP->next;
    }
}

void playFirst()
{
    if (FIRST == NULL)
    {
        printf("Playlist is Empty.\n");
        return;
    }

    CURRENT = FIRST;
    printf("Now Playing: %s\n", CURRENT->name);
}

void playNext()
{
    if (CURRENT == NULL)
    {
        printf("Playlist is Empty.\n");
        return;
    }

    if (CURRENT->next == NULL)
    {
        printf("Last Song Reached.\n");
    }
    else
    {
        CURRENT = CURRENT->next;
        printf("Now Playing: %s\n", CURRENT->name);
    }
}

void playPrevious()
{
    if (CURRENT == NULL)
    {
        printf("Playlist is Empty.\n");
        return;
    }

    if (CURRENT->prev == NULL)
    {
        printf("Already at First Song.\n");
    }
    else
    {
        CURRENT = CURRENT->prev;
        printf("Now Playing: %s\n", CURRENT->name);
    }
}

void deleteSong()
{
    char song[50];
    struct Song *TEMP;

    if (FIRST == NULL)
    {
        printf("Playlist is Empty.\n");
        return;
    }

    printf("Enter Song Name to Delete: ");
    scanf(" %[^\n]", song);

    TEMP = FIRST;

    while (TEMP != NULL)
    {
        if (strcmp(TEMP->name, song) == 0)
        {
            if (TEMP == FIRST)
            {
                FIRST = FIRST->next;
                if (FIRST != NULL)
                    FIRST->prev = NULL;
            }
            else
            {
                TEMP->prev->next = TEMP->next;
            }

            if (TEMP == LAST)
            {
                LAST = TEMP->prev;
                if (LAST != NULL)
                    LAST->next = NULL;
            }
            else if (TEMP->next != NULL)
            {
                TEMP->next->prev = TEMP->prev;
            }

            if (CURRENT == TEMP)
                CURRENT = FIRST;

            free(TEMP);

            printf("Song Deleted Successfully.\n");
            return;
        }

        TEMP = TEMP->next;
    }

    printf("Song Not Found.\n");
}

void currentSong()
{
    if (CURRENT == NULL)
    {
        printf("No Song Playing.\n");
    }
    else
    {
        printf("Current Song: %s\n", CURRENT->name);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== MUSIC PLAYER =====\n");
        printf("1. Add Song\n");
        printf("2. Display Playlist\n");
        printf("3. Play First Song\n");
        printf("4. Play Next Song\n");
        printf("5. Play Previous Song\n");
        printf("6. Delete Song\n");
        printf("7. Current Song\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addSong();
            break;

        case 2:
            displayPlaylist();
            break;

        case 3:
            playFirst();
            break;

        case 4:
            playNext();
            break;

        case 5:
            playPrevious();
            break;

        case 6:
            deleteSong();
            break;

        case 7:
            currentSong();
            break;

        case 8:
            printf("Thank You!\n");
            exit(0);

        default:
            printf("Invalid Choice.\n");
        }
    }

    return 0;
}