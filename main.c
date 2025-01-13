#include <stdio.h>
#include <string.h>

// -------Basic Syntax and Operations-------

void helloWorld()
{
    printf("Hello World!\n");
}

void calculator() {
    int x, y, result;
    char operation;

    printf("Insert first digit: ");
    scanf("%d", &x);

    printf("Insert second digit: ");
    scanf("%d", &y);

    getchar();

    printf("Choose operation between + - * / \n");
    scanf("%c", &operation);

    switch (operation) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            if (y != 0) {
                result = x / y;
            } else {
                printf("Error: Division by zero.\n");
                return;
            }
            break;
        default:
            printf("Unknown operation.\n");
            return;
    }

    printf("%d %c %d = %d\n", x, operation, y, result);
}

void isOdd()
{
    int x;
    char message[30];
    printf("Enter a number:");
    scanf("%d",&x);
    sprintf(message, (x % 2 == 0) ? "%d is even" : "%d is odd", x);
    printf("%s\n", message);
}

// -------Control Structures-------

void findMinMax()
{
    int arr[10] = {4,8,90,-12,-15,4,0,-35,26,10}; 
    int i, min, max, num;
    min = arr[0];
    max = arr[0];

    for(i = 1; i < 10; i++)
    {
        num = arr[i];
        if(num < min) min = num;
        if(num > max) max = num;
    }

    printf("Min: %d, max: %d",min,max);
}

void multiplicationTable()
{
    int i, num, table[11];
    printf("Multiplication table for number ");
    scanf("%d",&num);
   
    for(i = 0; i < 11; i++)
    {
        printf("%d x %d = %d\n",i,num,i*num);
    }
}

//-----Functions-----

int recursiveFactorial(int num)
{
    if(num == 1) return 1;
    return num*(recursiveFactorial(num-1));
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int isPalindrome()
{
    char word1[6], word2[6];
    int i;
    strcpy(word1,"madam");
    for(i = 0; i< 5; i++)
    {
        word2[4-i] = word1[i];
    }
    for(i = 0; i< 5; i++)
    {
        if(word1[i] != word2[i]) return 0;
    }
    return 1;
}

//-----Arrays and String-----

int main() {

   printf("%d",(int)isPalindrome());

    return 0;
}