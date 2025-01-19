#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

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

int sumOfArray()
{
    int i, sum = 0;
    int arr[5] = {7,9,4,6,1};

    for(i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    return sum;
}

void reverseArray()
{
    int i;
    const int size = 5;
    int arr[5] = {7,9,4,6,1};
    int revArr[size];

    for(i = 0; i < size; i++)
    {
        revArr[size-i - 1] = arr[i];
    }

    for(i = 0; i < size; i++)
    {
        printf("arr[%d]: %d\ninv arr[%d]: %d \n",i,arr[i],i,revArr[i]);
    }
}

void stringManipulation()
{
    char string[6] = "Herlo";
    char string2[6] = "world";

    // Concatenate strings

    int newSize = strlen(string) + strlen(string2) + 2;
    char newString[newSize];

    int i;
    for (i = 0; i < strlen(string); i++) {
        newString[i] = string[i];
    }

    newString[i] = ' ';

    int j = 0;
    while (string2[j] != '\0') {
        newString[i + 1 + j] = string2[j];
        j++;
    }

    newString[i + 1 + j] = '\0';

    printf("String 1: %s\nString 2: %s\nConcatenated string: %s\n", string, string2,newString);

    // Reverse string
    
    char reversedString[strlen(newString) + 1];
    reversedString[strlen(newString)] = '\0';
    for(i = 0; i <= strlen(newString); i++)
    {
        reversedString[i] =  newString[strlen(newString) - i -1];
    }
    printf("Reversed string: %s\n",reversedString);

    // Find substrings

    char sub[3] = "rl";

    for(i = 0; i <= strlen(newString) - strlen(sub); i++)
    {
        if(newString[i] == sub[0] && newString[i+1] == sub[1]) printf("Found substring on index %d\n",i);  
    }
}

//-----Pointers-----

void pointersArithmetic()
{
    int array[5] = {5,3,7,1,9};
    int * arr;

    arr = array;

    int i;
    for(i = 0; i<5;i++)
    {
        printf("Memory address: %p, value: %d\n",(void *)arr, *arr);
        arr ++;
    }

    printf("Number of elements in array: %d",arr-array);
}

void swapByPointer()
{
    int a = 10;
    int b = 20;
    int temp;

    printf("value of a: %d, value of b: %d\n", a, b);

    int *pa = &a;
    int *pb = &b;
    temp = *pa;
    *pa = *pb;
    *pb = temp;

    printf("after swap. value of a: %d, value of b: %d\n", a, b);
}

void dynamicAlloc()
{
    int* arr = malloc(sizeof(int) * 5);
    int i;
    int* ptr = arr;
    for(i = 0; i < 5; i++)
    {
        *ptr = i*2;
        ptr++;
    }
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
    int* newArr = realloc(arr, sizeof(int) * 6);
    if (newArr == NULL) {
    printf("Realloc failed!\n");
    free(arr);
    return;
    }
    arr = newArr;
        printf("After realloc:\n");
    arr[5] = 10;
    for(i = 0; i < 6; i++)
    {
        printf("%d\n", arr[i]);
    }
}

//-----Dynamic Memory Allocation-----

struct Student
{
    int age;
    float grade;
    char name[50];
};

struct Student createStudent()
{
    struct Student s;

    printf("\nInsert student name: ");
    scanf("%s",&s.name);
    printf("\nInsert student age: ");
    scanf("%d",&s.age);
    printf("\nInsert student grade: ");
    scanf("%f",&s.grade);

    return s;
}

void studentManage()
{
    int i,size = 2;
    struct Student* students = malloc(size * sizeof(struct Student));
    for(i = 0; i< size; i++)
    {  
        printf("\nStudent %d: ",i+1);
        struct Student s = createStudent();
        students[i] = s;
    }

    for(i = 0; i< size; i++)
    {  
        printf("\nStudent %d - Name: %s, Age: %d, Grade: %.2f\n",
        i+1,students[i].name, students[i].age, students[i].grade);
    }

    free(students);
}


struct Stack {
    int* data;  
    int size;   
};


void push(struct Stack* s, int x) {
    
    s->size++;
   
    int* temp = realloc(s->data, s->size * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed during push.\n");
        return;
    }
    s->data = temp;
    s->data[s->size - 1] = x;
}

void pop(struct Stack* s) {
    if (s->size > 0) {
        s->size--;
        if (s->size > 0) {
            int* temp = realloc(s->data, s->size * sizeof(int));
            if (temp == NULL) {
                printf("Memory allocation failed during pop.\n");
                return;
            }
            s->data = temp;
        } else {

            free(s->data);
            s->data = NULL;
        }
    } else {
        printf("Stack underflow: no elements to pop.\n");
    }
}

void printStack(struct Stack* s) {
    if (s->size == 0) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i < s->size; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void stackTest() {
    
    struct Stack s;
    s.size = 0;
    s.data = NULL;

    push(&s, 1);
    push(&s, 5);
    push(&s, 10);
    printStack(&s);

    pop(&s);
    printStack(&s);

    pop(&s);
    pop(&s);
    printStack(&s);

    free(s.data);
}

//-----File I/O-----

void fileIO() {
    char text[50];
    printf("Insert text: ");
    scanf("%49s", text); 

    FILE* ptr = fopen("./Hello.txt", "w+");
    if (ptr == NULL) {
        perror("Error occurred while creating the file");
        return;
    }

    if (fputs(text, ptr) == EOF) {
        perror("Error writing to file");
        fclose(ptr);
        return;
    }

    rewind(ptr);

    char string[50] = {0};
    if (fgets(string, sizeof(string), ptr) == NULL) {
        perror("Error reading from file");
        fclose(ptr);
        return;
    }

    printf("Text from file: %s\n", string);

    fclose(ptr);
}

void countInFile() {
    FILE* ptr = fopen("./Hello.txt", "r");
    if (ptr == NULL) {
        perror("Error opening file");
        return;
    }

    int characters = 0, lines = 0, words = 0;
    char c;
    int inWord = 0; 

    while ((c = fgetc(ptr)) != EOF) {
        characters++;

        if (c == '\n') {
            lines++;
        }

        if (isspace(c)) {
            if (inWord) {
                words++;
                inWord = 0; // End of a word
            }
        } else {
            inWord = 1; // Inside a word
        }
    }

    if (characters > 0 && c != '\n') {
        lines++;
    }

    if (inWord) {
        words++;
    }

    printf("Characters: %d, Lines: %d, Words: %d\n", characters, lines, words);

    fclose(ptr);
}

#define BUF_SIZE 65536

void copyFile() {
    FILE* src = fopen("./Hello.txt", "r");
    if (src == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE* dest = fopen("./Hello_Copy.txt", "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buf[BUF_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buf, 1, BUF_SIZE, src)) > 0) {
        if (fwrite(buf, 1, bytesRead, dest) != bytesRead) {
            perror("Error writing to destination file");
            fclose(src);
            fclose(dest);
            return;
        }
    }
    if (ferror(src)) {
        perror("Error reading from source file");
    }

    fclose(src);
    fclose(dest);
}

//-----Structures and Enums-----

enum Day
{
    MONDAY = 0,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

void enumTest()
{
    int i = 0;
    while(i<7)
    {
        switch (i)
        {
        case MONDAY:
            printf("Monday value is: %d\n",i);
            break;
        case THURSDAY:
            printf("Thursday value is: %d\n",i);
            break;
        default:
            break;
        }

        i++;
    }
}

struct Book
{
   char title [50];
   char author[50];
   float price;
};

struct Person
{
    struct Book* books;
    char name[50];
};

void structTest()
{
    struct Book book, book2;
    strcpy(book.author,"Pawel P");
    strcpy(book.title,"Mongolian wars");
    book.price = 19.99;
    printf("Book: %s, Author: %s, price: %.2f",book.title,book.author,book.price);
    strcpy(book2.author,"Jay Z");
    strcpy(book2.title,"Amimir technology");
    book2.price = 29.99;

    struct Person person;
    strcpy(person.name,"Jacob");
    person.books = malloc(2*sizeof(struct Book));
    person.books[0] = book;
    person.books[1] = book2;

    printf("\n\nName: %s, books: %s, %s",person.name,person.books[0].title,person.books[1].title);

    free(person.books);
    person.books = NULL;
}

//-----Dynamic Arrays-----

int main() {

    

    return 0;
}