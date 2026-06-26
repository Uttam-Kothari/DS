// Replace Lowercase Characters by Uppercase and Vice-Versa

#include <stdio.h>
#include <ctype.h>

void main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  //if any space is allowed
    // scanf("%s",str);  //if space is not allowed
    for(i = 0; str[i] != '\0'; i++) {
        if(islower(str[i])) {
            str[i] = toupper(str[i]);
        }
        else if(isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }

    printf("Converted string: %s", str);

}