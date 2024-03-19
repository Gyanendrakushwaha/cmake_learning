#include<stdio.h>
#include<stdlib.h>
#include"cpplib.h"
#include <cstring>

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

//Function to create Linked list for student data

void create_student_node(struct node** start,int roll_No,int age,const char student_Name[50]){
struct node* new_node=(struct node *)malloc(sizeof(struct node));

if (new_node == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed.\n");
        return;
    }

    //getting the data in new_node
    strcpy(new_node->student_Name, student_Name);
    new_node->roll_No=roll_No;
    new_node->age=age;
    new_node->next = NULL;

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
const char* display_particular_student(struct node* temp,int roll_No){

    //iterate to list and match the roll_No if got display then breaking the loop
     while (temp != NULL) {
        if(temp->roll_No==roll_No){
        return temp->student_Name;
        }
        temp = temp->next;
    }
    // Return a default value or handle the case when the student is not found
    return "Student not found";
}

// Function to delete a particular student based on roll number
void delete_particular_student(struct node** start,int roll_No){
    struct node* current = *start;
    struct node* previous = NULL;

    while (current != NULL && current->roll_No != roll_No){
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
void store_data_in_file(struct node *start,char *filename){
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
struct node* read_from_file(char *filename){
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