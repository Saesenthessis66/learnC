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

void matrixMultiplication()
{
    int ** matrix;
    int ** matrix2;
    int ** matrix3;
    int rows = 5, columns = 5, i,j,k, sum=0;
    matrix = malloc( rows * sizeof(int *));
    matrix2 = malloc( rows * sizeof(int *));
    matrix3 = malloc( rows * sizeof(int *));

    for(i = 0; i < rows; i++)
    {
        matrix[i] = malloc( columns * sizeof(int));
        matrix2[i] = malloc( columns * sizeof(int));
        matrix3[i] = malloc( columns * sizeof(int));
    }

    for(i = 0; i < rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            matrix[i][j] = i+j+5;
            matrix2[i][j] = 2* i *j;
        }
    }

    for(i = 0; i < rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            sum = 0;
            for(k = 0; k < rows; k++)
            {
                sum += matrix[i][k] * matrix2[k][j];
            }
            matrix3[i][j] = sum;
        }
    }

    printf("Matrix 1: \t\t\t\t Matrix 2: \t\t\t\t Matrix 3:\n ");

    for(i = 0; i < rows;i++)
    {
        for(j=0;j<columns;j++)
        {
            printf("%d \t %d \t %d \t",matrix[i][j],matrix2[i][j],matrix3[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < rows; i++)
    {
       free(matrix[i]);
       free(matrix2[i]);
       free(matrix3[i]);
    }
    free(matrix);
    free(matrix2);
    free(matrix3);
}

//-----threading-----

#include <pthread.h>
#include <unistd.h>
int num = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;  

void* count1(void* args)
{
    int i = 0;
    
    pthread_mutex_lock(&mutex);  
    while (num < 5) {  
        pthread_cond_wait(&cond, &mutex);  
    }
    pthread_mutex_unlock(&mutex);  
    
    for (i = 0; i < 10; i++) {
        printf("Hello from count1. %d\n", i);
        num++;
        sleep(1);
    }
    return NULL;
}

void* count(void* args)
{
    int i = 0;
    for (i = 0; i < 10; i++) {
        printf("Hello from count. %d\n", i);
        num++;
        
        if (num == 5) {
            pthread_mutex_lock(&mutex);
            pthread_cond_signal(&cond);  
            pthread_mutex_unlock(&mutex);
        }

        sleep(1);
    }
    return NULL;
}

void threads()
{
    pthread_t thread_id, dt;
    
    pthread_create(&thread_id, NULL, count, NULL);
    
    pthread_create(&dt, NULL, count1, NULL);

    pthread_join(thread_id, NULL);
    pthread_detach(dt);
    
    int i = 0;
    for (i = 0; i < 10; i++) {
        printf("Hello from main function. %d\n", i);
        sleep(1);
    }

    pthread_exit(NULL);
}

struct threadData
{
   int* array;
   int size;
};


void* calculateSum(void* args)
{
    struct threadData* data = (struct threadData*)args;
    int i;
    int *ret = malloc(sizeof(int));
    *ret = 0;
    for(i = 0; i < data->size; i++)
    {
        *ret += data->array[i];
    }

    return ret;
}

#define array_size 100
#define thread_amount 4

void calculateThreadSum()
{
    int sum = 0;

    int* array = malloc(sizeof(int) * array_size), i;
    int* originalArray = array;
    for(i = 0; i < array_size; i++)
    {
        array[i] = 2 * i;
    }

    pthread_t t[thread_amount];
    struct threadData d[thread_amount];

    for(i = 0; i<thread_amount;i++)
    {
        d[i].size = array_size/thread_amount;
        d[i].array = array + i * d[i].size;

        if(pthread_create(&t[i], NULL, calculateSum,&d[i]) != 0) 
        {
            perror("Failed to create thread");
            free(array);
            return;
        }
    }

    for ( i = 0; i < thread_amount; i++) {
        int* partialSum;
        if (pthread_join(t[i], (void**)&partialSum) != 0) {
            perror("Failed to join thread");
            free(array);
            return;
        }
        sum += *partialSum;
        free(partialSum);
    }

    printf("Sum of given array equals: %d",sum);
    free(originalArray);
}

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

pthread_cond_t cond_full = PTHREAD_COND_INITIALIZER;  
pthread_cond_t cond_empty = PTHREAD_COND_INITIALIZER;

int* buffer;
int amount = 0;      
int buffer_size;     
int stop = 0;        

void* consume(void* args) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (amount == 0 && !stop) {
            pthread_cond_wait(&cond_full, &mutex);
        }
        if (stop) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        printf("Consuming value: %d\n", buffer[amount - 1]);
        amount--;

        pthread_cond_signal(&cond_empty);

        pthread_mutex_unlock(&mutex);
        sleep(1);  
    }
    return NULL;
}

void* produce(void* args) {
    while (1) {
        pthread_mutex_lock(&mutex);

        while (amount == buffer_size && !stop) {
            pthread_cond_wait(&cond_empty, &mutex);
        }
        if (stop) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        int item = rand() % 100;  
        buffer[amount] = item;
        printf("Producing value: %d\n", item);
        amount++;

        pthread_cond_signal(&cond_full);

        pthread_mutex_unlock(&mutex);
        sleep(1);  
    }
    return NULL;
}

void producerConsumer() {
    int producers, consumers, i;

    printf("Insert number of producers: ");
    scanf("%d", &producers);
    printf("Insert number of consumers: ");
    scanf("%d", &consumers);
    printf("Insert size of buffer: ");
    scanf("%d", &buffer_size);

    buffer = malloc(buffer_size * sizeof(int));
    pthread_t* prod_threads = malloc(sizeof(pthread_t) * producers);
    pthread_t* cons_threads = malloc(sizeof(pthread_t) * consumers);

    srand(time(NULL));  


    for (i = 0; i < producers; i++) {
        if (pthread_create(&prod_threads[i], NULL, produce, NULL) != 0) {
            perror("Failed to create producer thread");
            free(buffer);
            free(prod_threads);
            free(cons_threads);
            return;
        }
    }

    for (i = 0; i < consumers; i++) {
        if (pthread_create(&cons_threads[i], NULL, consume, NULL) != 0) {
            perror("Failed to create consumer thread");
            free(buffer);
            free(prod_threads);
            free(cons_threads);
            return;
        }
    }

    sleep(10);
    stop = 1;  

    pthread_mutex_lock(&mutex);
    pthread_cond_broadcast(&cond_full);
    pthread_cond_broadcast(&cond_empty);
    pthread_mutex_unlock(&mutex);

    for (i = 0; i < producers; i++) {
        pthread_join(prod_threads[i], NULL);
    }
    for (i = 0; i < consumers; i++) {
        pthread_join(cons_threads[i], NULL);
    }

    free(buffer);
    free(prod_threads);
    free(cons_threads);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_full);
    pthread_cond_destroy(&cond_empty);

    printf("Producer-consumer simulation finished.\n");
}

//-----Algorithms and Data Structures-----

struct node
{
    int data;
    struct node* next;
    struct node* previous;
};

struct linkedList
{
    int size;
    struct node* head;
};

void push_back(struct linkedList* list, int value)
{
    if(list->head == NULL)
    {
        struct node* node = malloc(sizeof(struct node));
        node->data = value;
        node->next = NULL;
        node->previous = NULL;
        list->head = node;
        list->size = 1;
    }
    else
    {
        struct node* node = list->head;
        while(node->next != NULL)
        {
            node = node->next;
        } 
        struct node* element =  malloc(sizeof(struct node));
        element->data = value;
        element->next = NULL;
        element->previous = node;
        node->next = element;
        list->size++;
    }
}

void pop_back(struct linkedList* list) {
    if (list->size == 0) {
        printf("Cannot pop from an empty list!\n");
        return;
    }
    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
    } else {
        struct node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->previous->next = NULL;
        free(current);
    }
    list->size--;
}

void printList(struct linkedList* list)
{
    if(list->size == 0) 
    {
        printf("List is empty.");
        return;
    }
    struct node* node = list->head;
    int i = 0;
    printf("Element: %d value: %d\n",i,node->data);
    while(node->next != NULL)
    {
        node = node->next;
        i++;
        printf("Element: %d value: %d\n",i,node->data);
    } 
}

void push_front(struct linkedList* list, int value)
{
    if(list->head == NULL)
    {
        struct node* node = malloc(sizeof(struct node));
        node->data = value;
        node->next = NULL;
        node->previous = NULL;
        list->head = node;
        list->size = 1;
    }
    else
    {
        struct node* newHead = malloc(sizeof(struct node));
        struct node* node = list->head;
        newHead->data =  value;
        newHead->next = node;
        node->previous = newHead;
        list->head = newHead;
        list->size++;
    }
}

void pop_front(struct linkedList* list)
{
    if (list->head == NULL)
    {
        printf("Empty list cannot be front popped!\n");
        return;
    }

    if (list->size == 1)
    {
        free(list->head);
        list->head = NULL;
        list->size = 0;  
        return;
    }

    struct node* oldHead = list->head;         
    list->head = list->head->next;            
    list->head->previous = NULL;             
    free(oldHead);                           
    list->size--;                             
}

struct node* find(struct linkedList* list, int value)
{
    struct node* head = list->head;
    while(head->next != NULL)
    {
        if(head->data == value) return head;
        head = head->next;
    }
    if(head->data == value) return head;
    printf("Value not found!");
    return NULL;
}

void linkedListDelete(struct linkedList* list, int value)
{
    struct node* head = list->head;

    while (head != NULL)  
    {
        if (head->data == value) 
        {
            struct node* nodeToDelete = head;
            if (head == list->head)  
            {
                list->head = head->next;  
                if (list->head != NULL)   
                    list->head->previous = NULL;
            }
            else 
            {
                head->previous->next = head->next; 
                if (head->next != NULL) 
                    head->next->previous = head->previous; 
            }

            free(nodeToDelete); 
            list->size--;       
            return;            
        }
        head = head->next;
    }

    printf("Value not found!\n");
}

void reverse_print(struct linkedList* list)
{
    if (list->head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }

    struct node* current = list->head;
    int i = list->size - 1;  

    while (current->next != NULL)
    {
        current = current->next;
    }

    while (current != NULL)
    {
        printf("Element: %d, Value: %d\n", i, current->data);
        i--;
        current = current->previous;
    }
}

void clear(struct linkedList* list)
{
    if (list->head == NULL) 
    {
        return;
    }

    struct node* current = list->head;
    struct node* nextNode;

    while (current != NULL) 
    {
        nextNode = current->next;
        free(current);           
        current = nextNode;       
    }

    list->head = NULL; 
    list->size = 0;    
}

void linkedListTest()
{
    struct linkedList list = {0, NULL};

    push_back(&list,5);
    push_back(&list,4);
    push_back(&list,3);

    printList(&list);
    printf("\n");

    pop_back(&list);
    printList(&list);
    printf("\n");

    push_front(&list,3);
    printList(&list);
    printf("\n");

    pop_front(&list);
    printList(&list);
    printf("\n");

    struct node* val = find(&list,4);
    printf("Address of value: %p\n",val);
    val->data = 10;
    printList(&list);
    printf("\n");

    printList(&list);
    printf("\n");
    linkedListDelete(&list,5);
    printList(&list);
    printf("\n");

    push_back(&list,5);
    push_back(&list,4);
    push_back(&list,3);

    printList(&list);
    printf("\n");

    reverse_print(&list);
    printf("\n");

    clear(&list);
    printList(&list);
    printf("\n");
}

struct Queue {
    int* array;
    int capacity;
    int front;
    int rear;
    int size;
};

void initQueue(struct Queue* q, int cap)
{
    q->capacity = cap;
    q->array = malloc(sizeof(int) * cap);
    q->size = 0;
    q->front = 0;
    q->rear = -1; 
}

void enqueue(struct Queue* q, int val)
{
    if (q->size == q->capacity)
    {
        printf("Queue overflow! Cannot enqueue %d\n", val);
        return;
    }
    
    q->rear = (q->rear + 1) % q->capacity; 
    q->array[q->rear] = val;
    q->size++;

    printf("Enqueued: %d\n", val);
}

int dequeue(struct Queue* q)
{
    if (q->size == 0)
    {
        printf("Queue underflow! Cannot dequeue\n");
        return -1;
    }

    int val = q->array[q->front]; 
    q->front = (q->front + 1) % q->capacity; 
    q->size--;

    return val;
}

void printQueue(struct Queue* q)
{
    if (q->size == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++)
    {
        int index = (q->front + i) % q->capacity;
        printf("%d ", q->array[index]);
    }
    printf("\n");
}

void freeQueue(struct Queue* q)
{
    free(q->array);
}

void testQueue()
{
    struct Queue q;
    initQueue(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printQueue(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); 
    enqueue(&q, 70); 

    printQueue(&q);

    freeQueue(&q);
}

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value)
{
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = value;
    node->right = NULL;
    node->left = NULL;

    return node;
}

struct TreeNode* insert(struct TreeNode* root, int value) 
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->val)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->val)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

struct TreeNode* findMin(struct TreeNode* root)
{
    struct TreeNode* node = root;
    if(root == NULL)
    {
        printf("BST is empty.");
        return NULL;
    }
    if(root->left == NULL)
    {
        return root;
    }
    findMin(root->left);
}

struct TreeNode* findMax(struct TreeNode* root)
{
    struct TreeNode* node = root;
    if(root == NULL)
    {
        printf("BST is empty.");
        return NULL;
    }
    if(root->right == NULL)
    {
        return root;
    }
    findMin(root->right);
}

struct TreeNode* delete(struct TreeNode* root, int value) {

    if (root == NULL)
    {
        printf("Tree is empty or value is not in tree.\n");
        return root;
    }

    int val = root->val;
    if(val > value)
    {
        root->left = delete(root->left,value);
    }
    else if(val < value)
    {
       root->right = delete(root->right,value);
    }
    else 
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if(root->left == NULL)
        {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* successor = findMin(root->right);
        root->val = successor->val;
        root->right = delete(root->right, successor->val);
    }
    return root;
}

struct TreeNode* search(struct TreeNode* root, int value)
{
    if(root == NULL)
    {
        printf("Value %d not found.",value);
        return NULL;
    }
    int val = root->val;
    if(val > value)
    {
        search(root->left,val);
    }
    else if(val < value)
    {
       search(root->right,val);
    }
    else 
    {
        return root;
    }
}

void inOrderTraversal(struct TreeNode* root)
{
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->val);
    inOrderTraversal(root->right);
}

void preOrderTraversal(struct TreeNode* root)
{
    if(root == NULL) return;
    printf("%d ",root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct TreeNode* root)
{
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ",root->val);
}

void destroyTree(struct TreeNode* root)
{
    if(root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

void BST()
{
    struct TreeNode* root = NULL;

    printf("Inserting values: 50, 30, 70, 20, 40, 60, 80\n");
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("\nInOrder Traversal (Should be sorted): ");
    inOrderTraversal(root);
    printf("\n");

    printf("\nPreOrder Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("\nPostOrder Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("\nFinding min: ");
    struct TreeNode* minNode = findMin(root);
    if (minNode) printf("%d\n", minNode->val);

    printf("Finding max: ");
    struct TreeNode* maxNode = findMax(root);
    if (maxNode) printf("%d\n", maxNode->val);

    printf("\nSearching for 40: ");
    struct TreeNode* found = search(root, 40);
    if (found) printf("Found %d\n", found->val);
    else printf("Not found\n");

    root = delete(root, 20);
    printf("InOrder Traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    root = delete(root, 30);
    printf("InOrder Traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    root = delete(root, 50);
    printf("InOrder Traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    destroyTree(root);
    root = NULL;
    printf("Tree destroyed.\n");
}

int main() {

    BST();

    return 0;
}