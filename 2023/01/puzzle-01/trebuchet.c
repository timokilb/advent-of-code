#include <stdio.h>
#include <ctype.h>

#define MAXLINE_LENGTH 256 // maximum number of characters per line

int linetocalibrationvalue(char s[]);
int digitstoint(char a, char b);

int main(int argc, char *argv[])
{

    FILE *filepointer;

    if (argc > 1)
    {
        filepointer = fopen(argv[1], "r");
        if (filepointer == NULL)
        {
            printf("No file named %s found.\n", argv[1]);
            return 1;
        }
        else
        {
            int result = 0;
            char line[256];
            while (fgets(line, sizeof(line), filepointer))
            {
                result += linetocalibrationvalue(line);
            }

            fclose(filepointer);
            printf("Code: %d\n", result);
            return 0;
        }
    }
    else
    {
        printf("No filename specified\n");
    }

    return 0;
}

int linetocalibrationvalue(char s[])
{
    char digits[MAXLINE_LENGTH];
    int i = 0;
    int l = 0;
    while (s[i] != '\0')
    {
        if (isdigit(s[i]))
        {
            digits[l] = s[i];
            ++l;
        }
        ++i;
    }

    if (l == 0)
    {
        return 0;
    }
    else if (l == 1)
    {
        return digitstoint(digits[0], digits[0]);
    }
    else
    {
        return digitstoint(digits[0], digits[l - 1]);
    }
}

int digitstoint(char a, char b)
{
    return (a - '0') * 10 + b - '0';
}