// #define CATCH_CONFIG_MAIN
// #include "catch.hpp"

// #include <cstdio>
// #include <cstdlib>
// #include <cstring>

// //source file
// // #include "main.c"  
// #include "cpplib.h"

// TEST_CASE("function Test", "[function]") {

//     function();
//      // Redirect standard input to provide input during tests //input would be taken from input.txt
//     FILE* input_file = fopen("input.txt", "w");
//     fprintf(input_file, "1\nJohn Doe\n1\n25\nn\n"); //used to write formatted data to a file.
//     fclose(input_file);
    
//      // Redirect standard input to read from the file
//     freopen("input.txt", "r", stdin);

//     // Redirect standard output to capture printed messages
//     // freopen("output.txt", "w", stdout);  //any data written to the standard output using functions like printf or puts 
//                                         //will be sent to the specified file(output.txt) instead of being displayed on the console.

 
   

//     // Calling main function with input redirection
//     // const char* argv[] = {"out", NULL};  
//     // int argc = sizeof(argv) / sizeof(argv[0]) - 1;  // Exclude NULL
    

//     // //main function with input redirection
//     // int result = Catch::Session().run(argc, argv);

//     // // // Check the return value of the main function
//     // REQUIRE(result == 0);

//     // // // Check the output of the main function
//     // FILE* output_file = fopen("output.txt", "r");
//     // char buffer[256];
//     // fgets(buffer, sizeof(buffer), output_file);

//     // // // // Replace this assertion with the actual output you expect
//     // REQUIRE(std::strcmp(buffer, "1\nJohn Doe\n1\n25\nn\n") == 0);


//      fclose(stdin);
//     fclose(stdout);
//     // fclose(output_file);

// }


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

// source file
#include "cpplib.h"

TEST_CASE("function Test", "[function]") {

    // function();
    
    // Redirect standard input to provide input during tests //input would be taken from input.txt
    FILE* input_file = fopen("input.txt", "w");
    fprintf(input_file, "1\nJohn Doe\n1\n25\nn\n"); //used to write formatted data to a file.
    fclose(input_file);

    // Redirect standard output to capture printed messages
    // freopen("output.txt", "w", stdout);

    // Calling main function without input redirection
    const char* command = "./test < input.txt";
    int result = system(command);

    // // Check the return value of the main function
    // REQUIRE(result == 0);

    // // Check the output of the main function
    // FILE* output_file = fopen("output.txt", "r");
    // char buffer[256];
    // fgets(buffer, sizeof(buffer), output_file);

    // // Replace this assertion with the actual output you expect
    // REQUIRE(std::strcmp(buffer, "1\nJohn Doe\n1\n25\nn\n") == 0);

    // fclose(output_file);
}
