//Convert Seconds to HH:MM:SS

#include <stdio.h>

void main() {
    int sec, h, m, s;

    printf("Enter seconds: ");
    scanf("%d", &sec);

    h = sec / 3600;
    m = (sec % 3600) / 60;
    s = sec % 60;

    printf("%02d:%02d:%02d", h, m, s);

}