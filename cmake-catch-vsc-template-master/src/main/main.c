#include<stdio.h>
#include<stdlib.h>

//library for the APIs
#include"cpplib.h"

#define addStudent 1
#define getStudent 2
#define getStudentList 3
#define deleteStudent   4

//starting with the main function
int main(){

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
}