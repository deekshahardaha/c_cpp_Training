#include <stdarg.h>
#include <iostream>

using namespace std;

// typedef is a keyword in C that allows you to create a new name (alias) for an existing type. 
// This can make your code more readable and easier to manage, especially when dealing with complex data types like structures or pointers.
// Define a new type for a pointer to an integer
typedef int* IntPtr;

// Macros are defined using the #define preprocessor directive. 
// Allows to create symbolic constants or inline functions. Macros are replaced by their definitions during the preprocessing stage before compilation.
#define PI 3.14159
#define SQUARE(x) ((x) * (x))

int sum(int count,...){
    int sss=0;
    va_list args;
    va_start(args,count);
    for(int i=0;i<count;i++){
        sss+=va_arg(args,int);
    }
    va_end(args);
    return sss;
}

int main75(){
    int s;
    s=sum(3,99,45,2);
    cout<<s<<endl;

    int a = 10;
    IntPtr p = &a; // Using the typedef alias

    printf("Value of a: %d\n", *p); 

    printf("Value of PI: %f\n", PI);

    int num = 5;
    printf("Square of %d: %d\n", num, SQUARE(num));
    return 0;
}