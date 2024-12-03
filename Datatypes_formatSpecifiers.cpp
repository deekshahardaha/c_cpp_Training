// use #include<> for including the files in the configured path."
// use #include"" for including the files in the local path."
#include <stdio.h>
#include <math.h>
#include<stdlib.h>


int p=10;
int main8()
{
    int h=p;

    // Variables
    // int a; // Integer variable(4 byte)
    // scanf("%d", &a);
    // printf("Integer: %d\n", a);

    // float b; // Float variable(4 byte)
    // scanf("%f", &b);
    // printf("Float: %.2f\n", b);

    // double g; // Double variable(8 byte)
    // scanf("%lf", &g);
    // printf("Double: %.3lf\n", g);

    // char c; // Character variable(1 byte)
    // scanf("%c", &c);
    // printf("Character: %c\n", c);

    // short d; // Short integer variable(2 byte)
    // scanf("%hd", &d);
    // printf("Short Integer: %hd\n", d);

    // long l; // Long integer variable(4 byte)
    // scanf("%ld", &l);
    // printf("Long Integer: %ld\n", l);

    // unsigned int uint; // Unsigned integer variable(2 byte)
    // scanf("%u", &uint);
    // printf("Unsigned Integer: %u\n", uint);

    // const int temp = 100;
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

    // printf("Unsigned Integer: %u\n", uint);
    // printf("Octal: %o\n", uint);
    // // printf("Pointer: %p\n", pointer);

    // double val = 123456.789;
    // printf("Scientific Notation: %e\n", val); // 1.234568e+005
    // printf("General Format: %g\n", val);      // 123457

    // // Variations of Format Specifiers
    // int num = 42;
    // printf("%5d\n", num);  // Output: "   42"   5 is total length
    // printf("%-5d\n", num); // Output: "42   "   left justification
    // printf("%05d\n", num); // Output: "00042"  zero padding
    // // +: Forces the output of a sign (+ or -).
    // printf("%+d\n", num); // Output: "+42"

    // printf("%07.2f\n", b); // Output: "003.14"

    // float pi = 3.14159;
    // printf("%.2f\n", pi); // Output: "3.14"  for precision

    // printf("This is a backslash: \\\n");
    // printf("It's a sunny day.\n");
    // printf("He said, \"Hello!\"\n");
    // printf("Hello\nWorld!\n");
    // printf("Column1\tColumn2\n");      // tabspace
    // printf("Hellokshjdfiu\rWorld!\n"); // moves cursor to the beginning of line
    // printf("Hello\bWorld!\n");         // backslash
    // printf("Hello\fWorld!\n");         // Advances to the next page (usually used with forms)(may not have visible effect in all environments).
    // printf("Hello\vWorld!\n"); // vertical tab
    // // Demonstrating the null character
    // char str[] = "Hello\0World";
    // printf("String with null character: %s\n", str); // Only prints "Hello"
    // // Question mark escape sequence
    // printf("Is this a question\?\n");


    //Arith +, -, *, %, /,

    //Shift <<, >>

    int s=9;

    // printf("%d\n",s>>2);

    //Comparison/equality  >, <, ==

    // Logical && || ! ^

    

    //Bitwise & | ~
    // printf("%d\n",s & 6);
    // printf("%d\n",~s);
    // sizeof
    // printf("%d\n",sizeof(s));
    // ++, --
    // int k = 6;
    // k = ++7; error


    // int l = ++k;
    // printf("%d",l);

    // if else operator Not operator, control flow statements

    // Ternary operator ?:

    // Address of &, *, ->
    // int a;
    // int x = 1;

    // if (x)
    // {
    //  a = 10;
    // }
    // else
    // {
    //  a = 20;
    // }

    // a = x ? 10 : 20;

    // //comma operator
    // int a = 1, b = 2, c = 20;
    // c = (a += 1, b += 2, 25); // while assigning the values the last one will get assighned to the variable.
    // a->2
    // b->4
    // c->25
    // Shorthand +=, -=, ....
    // []

    //:: it is not used in c but get introduced in c++.

    // +/-

    //int a = 10;
    //int b = 2;
    //int c = 3;
    ////int k = (a / b) * c;
    //if (b!=0 && a/b + c)
    //{
    //  std::cout << "output is "<< std::endl;
    //}
    //else
    //  //b is zero not a valid scenartio
  
    // int a = 8;
    // int b = ++a;
    // int c = a++;
    // printf("%d %d %d\n",a,b,c); //a ->10, b ->9, c->9

    // printf("%d\n",a+++a-++b*c--);


    // MATHEMATICAL FUNCTIONS
    // int num =6;
    // double root = sqrt(num); 
    // printf("%lf\n",root);
    // double result = pow(num, -3);
    // printf("%lf\n",result);
    // double res = pow(num, 3);
    // printf("%lf\n",res);

    // double angle = 45.0; // in degrees
    // double radians = angle * (3.1415 / 180.0); // convert to radians
    // double sineValue = sin(radians);
    // printf("%lf\n",radians);
    // printf("%lf\n",sineValue);

    // int x = 4;
    // double result = exp(x); // e^2
    // printf("Exponential of %d is %lf\n", x, result);

    // double ln = log(x); // ln(x)
    // double logval = log10(x); // log(x)
    // printf("Natural logarithm of %d is %lf\n", x, ln);
    // printf("logarithm of %d is %lf\n", x, logval);


    double x = -5.5;
    double absoluteValue = fabs(x); // Absolute for floats
    int y = -47;
    // stdlib is required for abs.
    printf("%d\n",abs(y)); // for integers
    printf("Absolute value of %lf is %lf\n", x, absoluteValue);
    return 0;
}
