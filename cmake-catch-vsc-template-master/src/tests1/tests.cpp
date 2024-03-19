#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include"cpplib.h"
#include <iostream>

TEST_CASE("LinkedList Operations", "[LinkedList]") {
   
    SECTION("Insertion and Search") {

      // Initialize the head pointer with some nodes
      struct  node *head = NULL;
        create_student_node(&head,1,23,"gyanendra");
        create_student_node(&head,2,23,"yash");
        create_student_node(&head,3,23,"lavina");
        create_student_node(&head,4,23,"sakshi");
        create_student_node(&head,5,23,"ravi");
        create_student_node(&head,6,23,"hitakshi");
        create_student_node(&head,7,23,"ishika");
        create_student_node(&head,8,23,"ajit");
        create_student_node(&head,9,23,"piyush");

        REQUIRE(strcmp(display_particular_student(head,1), "gyanendra") == 0);
        REQUIRE(strcmp(display_particular_student(head,2), "yash") == 0);
        REQUIRE(strcmp(display_particular_student(head,3), "lavina") == 0);
        REQUIRE(strcmp(display_particular_student(head,4), "sakshi") == 0);
        REQUIRE(strcmp(display_particular_student(head,5), "ravi") == 0);
        REQUIRE(strcmp(display_particular_student(head,6), "hitakshi") == 0);
        REQUIRE(strcmp(display_particular_student(head,7), "ishika") == 0);
        REQUIRE(strcmp(display_particular_student(head,8), "ajit") == 0);
        REQUIRE(strcmp(display_particular_student(head,9), "piyush") == 0);
        
    }

    SECTION("Insertion and delete") {

      // Initialize the head pointer with some nodes
      struct  node *head = NULL;
        create_student_node(&head,1,23,"gyanendra");
        create_student_node(&head,2,23,"yash");
        create_student_node(&head,3,23,"lavina");
        create_student_node(&head,4,23,"sakshi");
        create_student_node(&head,5,23,"ravi");
        create_student_node(&head,6,23,"hitakshi");
        create_student_node(&head,7,23,"ishika");
        create_student_node(&head,8,23,"ajit");
        create_student_node(&head,9,23,"piyush");

        delete_particular_student(&head,1);
        delete_particular_student(&head,6);
        REQUIRE(strcmp(display_particular_student(head,1), "gyanendra") == -1); //this is deleted
        REQUIRE(strcmp(display_particular_student(head,2), "yash") == 0);
        REQUIRE(strcmp(display_particular_student(head,3), "lavina") == 0);
        REQUIRE(strcmp(display_particular_student(head,4), "sakshi") == 0);
        REQUIRE(strcmp(display_particular_student(head,5), "ravi") == 0);
        REQUIRE(strcmp(display_particular_student(head,6), "hitakshi") == -1);  //this is deleted
        REQUIRE(strcmp(display_particular_student(head,7), "ishika") == 0);
        REQUIRE(strcmp(display_particular_student(head,8), "ajit") == 0);
        REQUIRE(strcmp(display_particular_student(head,9), "piyush") == 0);
    }


    SECTION("Empty List") {
        struct  node *head = NULL;
        REQUIRE(strcmp(display_particular_student(head,1), "gyanendra") == -1); //no element
        REQUIRE(strcmp(display_particular_student(head,2), "yash") == -1);      //no element
        REQUIRE(strcmp(display_particular_student(head,3), "lavina") == -1);    //no element
    }
}