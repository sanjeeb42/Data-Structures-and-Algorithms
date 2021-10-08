#include <stdio.h>
#include <string.h>

int checkvalidemail(char s[], int n)
{
    char special_array[] = {'!', '#', '$', '%', '^', '&', '*', '+', '-', '/', '?', '_', '`', '{', '|', '.'};

    int len = (strlen(special_array)) - 1;

    for (int j = 0; j < len; j++)
    {
        if (s[0] == special_array[j] || s[n - 1] == special_array[j])
        {

            return -1;
        }
    }
    int i = 1;
    int domain = 0;

    for (i = 1; i < n; i++)
    {
        if (s[i] == '@')
        {

            domain = i;
            break;
        }
        else if (s[i] == '.' || s[i] == '!' || s[i] == '!' || s[i] == '#' || s[i] == '$' || s[i] == '&' || s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '=' || s[i] == '?' || s[i] == '^' || s[i] == '_' || s[i] == '`' || s[i] == '{' || s[i] == '|')
        {
            {
                int indx1 = 1, indx2 = 0;

                for (int j = 0; j < len; j++)
                {
                    if (s[i + 1] == special_array[j])
                    {
                        indx2 = 1;
                        break;
                    }
                }
                if (indx1 == indx2)
                {

                    return -1;
                }
            }
        }
    }
    if (domain == (n - 1))
    {

        return -1;
    }
    int valid = 0;
    for (i + 1; i < n; i++)
    {
        if (s[i] == '\0')
        {
            return 1;
        }
        else if (s[i] == '!' || s[i] == '!' || s[i] == '#' || s[i] == '$' || s[i] == '&' || s[i] == '*' || s[i] == '-' || s[i] == '/' || s[i] == '=' || s[i] == '?' || s[i] == '^' || s[i] == '+' || s[i] == '`' || s[i] == '{' || s[i] == '|')
        {
            return -1;
        }
        else if (s[i] == '.' && i != n - 1)
        {
            if (s[i + 1] != '!' && s[i + 1] != '!' && s[i + 1] != '#' && s[i + 1] != '$' && s[i + 1] != '&' && s[i + 1] != '*' && s[i + 1] != '-' && s[i + 1] != '/' && s[i + 1] != '=' && s[i + 1] != '?' && s[i + 1] != '^' && s[i + 1] != '+' && s[i + 1] != '`' && s[i + 1] != '{' && s[i + 1] != '|')
            {
                valid = 1;
            }
        }
    }
    return valid;
}

int main()
{
    char s[100];
    scanf("%s", s); // No need to use itterators in case of strings
    // printf("%s", s); // breaks when it encounnters a " "
    int len = strlen(s);
    // printf("%d", len);
    // printf("\n");
    int result = checkvalidemail(s, len);
    // printf("THe value returned is %d \n", result);
    if (result == 1)
    {
        printf("Valid email id");
    }
    else
    {
        printf("Invalid Email id");
    }
    return 0;
}
