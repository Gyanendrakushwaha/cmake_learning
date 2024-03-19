#include<stdio.h>
#include<stdlib.h>
#include"cpplib.h"


#define addStudent 1
#define getStudent 2
#define getStudentList 3
#define deleteStudent   4
// #define addStudent 1
// #define getStudent 2
// #define getStudentList 3
// #define deleteStudent   4

//structure for student node
// struct node{
//     int roll_No;                   //4 bytes
//     int age;                       //4 bytes
//     char student_Name[50];         //50 bytes
//     struct node* next;             //8 bytes
// };

//function to get user input
// void get_user_input(int& roll_No,int& age,char& student_Name[50])}
//     printf("enter roll unmber");
//     scanf("%d",&roll_No);
// };

//Function to create Linked list for student data
void create_student_node(struct node** start){

struct node* new_node=(struct node *)malloc(sizeof(struct node));

if (new_node == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the student name: ");
    scanf("%s", new_node->student_Name);

    printf("Enter the roll number: ");
    scanf("%d", &new_node->roll_No);

    printf("Enter age: ");
    scanf("%d", &new_node->age);

    //getting the data in new_node
    // strcpy(new_node->student_Name, student_Name);
    // new_node->roll_No=roll_No;
    // new_node->age=age;
    new_node->next = NULL;

    // If the list is empty, set the new node as the start
    if (*start == NULL) {
        *start = new_node;
    } else {
        // Find the last node and link the new node
        struct node* temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

//Function to display Particular student
void display_particular_student(struct node* temp){
    int roll_No;
    printf("enter roll number to get the student\n");
    scanf("%d",&roll_No);

    //iterate to list and match the roll_No if got display then breaking the loop
     while (temp != NULL) {
        if(temp->roll_No==roll_No){
        printf("Name: %s, Roll Number: %d, Age: %d\n", temp->student_Name, temp->roll_No, temp->age);
        break;
        }
        temp = temp->next;
    }
}

// Function to delete a particular student based on roll number
void delete_particular_student(struct node** start){
    struct node* current = *start;
    struct node* previous = NULL;

    int roll_No;
    printf("enter roll number to delete the student\n");
    scanf("%d",&roll_No);

    while (current != NULL && current->roll_No != roll_No) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with roll number %d not found.\n", roll_No);
        return;
    }

    // If the student to be deleted is the first node
    if (previous == NULL) {
        *start = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Student with roll number %d deleted successfully.\n", roll_No);
}

// Function to display the student list
void display_student_list(struct node* temp_ptr){
    printf("\nStudent List:\n");

    while (temp_ptr != NULL) {
        printf("Name: %s, Roll Number: %d, Age: %d\n", temp_ptr->student_Name, temp_ptr->roll_No, temp_ptr->age);
        temp_ptr = temp_ptr->next;
    }
}

//function to free the whole list data when program ends
void free_student_list(struct node** start){
    struct node *current=*start;
    struct node *next;

    while(current != NULL){
        next=current->next;
        free(current);
        current=next;
    }

    free(start);
}

//function to store linkedlist data in file
void store_data_in_file(struct node *start,const char *filename){
    FILE* file = fopen(filename, "w");
    //error check
    if (file == NULL){
        printf("Error opening file for writing.\n");
        return;
    }
    struct node* current = start;
    //iterate to ll and write in the file
    while (current != NULL){
        fwrite(current, sizeof(struct node), 1, file);
        current = current->next;
    }
    fclose(file);
}

// Function to read the linked list data from a file
struct node* read_from_file(const char *filename){
    // printf("check1");
     FILE* file = fopen(filename, "rb");

     if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return NULL;
    }

     struct node* head = NULL;
     struct node* current = NULL;
    // Read each node's data from the file and create a linked list
    struct node *newNode;
    while(1){
            struct node* newNode = (struct node*)malloc(sizeof(struct node));
            size_t bytesRead = fread(newNode, sizeof(struct node), 1, file);

        if (bytesRead == 0) {
            free(newNode);  // Free the last allocated node
            break;          // End of file
        }

        newNode->next = NULL;
        if (head == NULL) {
            head = current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }

    }
    fclose(file);
    return head;  
}

void function(){
struct node* start = NULL; // Initialize the start pointer

//getting the data from data base if present
start = read_from_file("file.txt");

char choice_to_run_operation;
int operation_To_Perform;

do {
       //operation to be performed
        printf("Enter 1 for adding the name\n 2 for displaying particular student data \n 3 for displaying all students data  \n 4 for deleting \n");
        scanf("%d",&operation_To_Perform);

        switch(operation_To_Perform){
        //case for adding the student in the list
        case addStudent:  //1
            //this section is for unit testing

            create_student_node(&start);
            break;

        case getStudent:  //2
            display_particular_student(start);
            break;

        case getStudentList: //3
            display_student_list(start);
            break;

        case deleteStudent:  //4
            delete_particular_student(&start); 
            break;

        default : break;

    }
        printf("Do you want to perform operations again on student list? (y/n): ");
        scanf(" %c", &choice_to_run_operation); // Note the space before %c to consume the newline character
    }while(choice_to_run_operation == 'y' || choice_to_run_operation == 'Y');

    //storing data into file system
    store_data_in_file(start,"file.txt");

    // struct node *newNode= read_from_file("file.txt");
    display_student_list(start);

    //free the whole list data when program ends
    free_student_list(&start);
// return 0;
}