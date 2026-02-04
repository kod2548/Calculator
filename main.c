#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char equation[100];
    char operators[100];
    float number[100];
    int n = 0, o = 0;

    printf("Enter Your Equation: "); // รับสมการจากผู้ใช้
    scanf("%s", equation);           // รับสมการเป็นสตริง

    if (strspn(equation, "0123456789.+-*/%") != strlen(equation)) // ตรวจสอบตัวอักษรที่ไม่ถูกต้อง
    {
        printf("Error: Invalid character\n"); // แจ้งข้อผิดพลาด
        return 0;                             // ออกจากโปรแกรม
    }

    printf("Your Equation: %s\n", equation); // แสดงสมการที่ผู้ใช้ป้อน

    char *p = equation;        // ตัวชี้ไปยังตำแหน่งปัจจุบันในสมการ
    number[n] = strtof(p, &p); // แปลงสตริงเป็นตัวเลข
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
            if (operators[i] == '*') // คูณ
            {
                result = number[i] * number[i + 1];
            }
            else if (operators[i] == '/') // หาร
            {
                result = number[i] / number[i + 1];
            }
            else
            {
                result = (int)number[i] % (int)number[i + 1]; // หารลงตัว (%)
            }

            number[i] = result;

            for (int j = i + 1; j < n - 1; j++)
            {
                number[j] = number[j + 1];
            }

            for (int j = i; j < o - 1; j++)
            {
                operators[j] = operators[j + 1];
            }

            n--; // ออก loop
            o--;
            i--;
        }
    }

    float answer = number[0];
    for (int i = 0; i < o; i++)
    {
        if (operators[i] == '+')
        {
            answer += number[i + 1];
        }
        else
        {
            answer -= number[i + 1];
        }
    }

    printf("Result = %.2f\n", answer); // แตกกิ่ง V1 TESTING

    return 0;
}
// test case: 10+20*3-5/5%2
// hellow world tset branching

// หิวววววววว
// กินไรดีวันนี้
// กินกะเพราะม่ะ

// TESTTTT BRO

// fdjshjhijshfjodhslkjfhksj

// แตกกิ่งing