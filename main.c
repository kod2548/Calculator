#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char equation[100];
    char operators[100];
    float number[100];
    int n = 0, o = 0;

    printf("Enter Your Equation: ");
    scanf("%s", equation);

    if (strspn(equation, "0123456789.+-*/%") != strlen(equation))
    {
        printf("Error: Invalid character\n");
        return 0;
    }

    printf("Your Equation: %s\n", equation);
    char *p = equation;
    number[n] = strtof(p, &p);
    n++;

    while (*p)
    {
        operators[o] = *p;
        o++;
        p++;
        number[n] = strtof(p, &p);
        n++;
    }

    for (int i = 0; i < o; i++) // คูณ (*) หาร (/) หารลงตัว (%)
    {
        if (operators[i] == '*' || operators[i] == '/' || operators[i] == '%')
        {
            float result;
            if (operators[i] == '*')
                result = number[i] * number[i + 1];
            else if (operators[i] == '/')
                result = number[i] / number[i + 1];
            else
                result = (int)number[i] % (int)number[i + 1];

            number[i] = result;
            for (int j = i + 1; j < n - 1; j++)
                number[j] = number[j + 1];
            for (int j = i; j < o - 1; j++)
                operators[j] = operators[j + 1];

            n--;
            o--;
            i--;
        }
    }

    float answer = number[0];
    for (int i = 0; i < o; i++)
    {
        if (operators[i] == '+')
            answer += number[i + 1];
        else
            answer -= number[i + 1];
    }

    printf("Result = %.2f\n", answer);

    return 0;
}