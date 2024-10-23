#include <stdio.h>

int main() {
    // Variables
    int a;                  // Integer variable(4 byte)
    scanf("%d", &a);
    printf("Integer: %d\n", a);                       


    float b;                  // Float variable(4 byte)
    scanf("%f", &b);
    printf("Float: %.2f\n", b); 


    double g;                // Double variable(8 byte)
    scanf("%lf", &g); 
    printf("Double: %.3lf\n", g); 


    char c;                    // Character variable(1 byte)
    scanf("%c", &c); 
    printf("Character: %c\n", c);


    short d;                  // Short integer variable(2 byte)
    scanf("%hd", &d); 
    printf("Short Integer: %hd\n", d);


    long l;                    // Long integer variable(4 byte)
    scanf("%ld", &l); 
    printf("Long Integer: %ld\n", l);


    unsigned int uint;     // Unsigned integer variable(2 byte)
    scanf("%u", &uint); 
    printf("Unsigned Integer: %u\n", uint);         

    const int temp = 100;
    // temp=10; this line will show error as constants can not be changed.
    
    /* 
    %d: integers.
    %f: floating-point numbers.
    %c: characters.
    %s: strings.
    %u: unsigned integers.
    %i: signed integer (same in printf , but with scanf recognises the decimal , octal, hexadecimal using prefix(none, 0,0x) respectively. 
    %x: hexadecimal representation of integers.
    %o: octal representation of integers.
    %p: pointers.
    %e: scientific notation (floating-point)into power of 2.
    %g: both floating-point and scientific notation.
    */

    printf("Unsigned Integer: %u\n", uint );
    printf("Octal: %o\n", uint);
    // printf("Pointer: %p\n", pointer);

    double val =123456.789;
    printf("Scientific Notation: %e\n", val); //1.234568e+005
    printf("General Format: %g\n", val); //123457


    // Variations of Format Specifiers
    int num = 42;
    printf("%5d\n", num); // Output: "   42"   5 is total length
    printf("%-5d\n", num); // Output: "42   "   left justification
    printf("%05d\n", num); // Output: "00042"  zero padding
    // +: Forces the output of a sign (+ or -).
    printf("%+d\n", num); // Output: "+42"

    printf("%07.2f\n", b); // Output: "003.14"

    float pi = 3.14159;
    printf("%.2f\n", pi); // Output: "3.14"  for precision

    printf("This is a backslash: \\\n");
    printf("It's a sunny day.\n");
    printf("He said, \"Hello!\"\n");
    printf("Hello\nWorld!\n");
    printf("Column1\tColumn2\n"); //tabspace
    printf("Hellokshjdfiu\rWorld!\n");  //moves cursor to the beginning of line
    printf("Hello\bWorld!\n"); //backslash
    printf("Hello\fWorld!\n"); //Advances to the next page (may not have visible effect in all environments).
    printf("Hello\vWorld!\n");
    // Demonstrating the null character
    char str[] = "Hello\0World";
    printf("String with null character: %s\n", str); // Only prints "Hello"
    // Question mark escape sequence
    printf("Is this a question\?\n");

    return 0;
}
