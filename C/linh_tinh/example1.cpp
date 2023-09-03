#include <stdio.h>
#include <stdlib.h>

int m, t, u, f, d;
int i, j, dv;
char s[100];

void fileIn()
{
    FILE *file = fopen("Marathon copy.inp", "r");
    fscanf(file, "%d %d %d %d %d", &m, &t, &u, &f, &d);
    for (i = 0; i < t; i++)
    {
        fscanf(file, "%c",&s[i]);
    }
    fclose(file);
}

int trans(int a)
{
    if (s[a] == 'u' || s[a] == 'd') return u + d;else
    if (s[a] == 'f') return f;else return 0;
}

void xuly()
{
    int time;
    i = 0;
    dv = 0;
    while (time < m)
    time += trans(i);
    dv++;
    i++;
}

int main()
{
    fileIn();
    xuly();
    printf("Quang duong di duoc: %d", dv);
    return 0;
}