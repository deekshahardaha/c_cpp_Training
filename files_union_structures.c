#include <stdio.h>
#include <stdlib.h>
#include<string.h>


// Structures are used to group related data together, allowing access to all members simultaneously.
// Unions are used to save memory by allowing different data types to share the same memory
union Data {
    int i;
    float f;
    char c;
};

struct Student {
    int id;
    char name[50];
    float grade;
};


struct Date {
    unsigned int day : 5;  // 5 bits for day (0-31)
    unsigned int month : 4; // 4 bits for month (0-15)
    unsigned int year : 7;  // 7 bits for year (0-127)
};


struct Padded {
    char a;      // 1 byte
    int b;       // 4 bytes (needs padding)
    char c;      // 1 byte
};

struct Unpadded {
    char a;      // 1 byte
    char c;      // 1 byte
    int b;       // 4 bytes
};

/*
#pragma pack: Allows to control the alignment of structure members, 
reducing padding and potentially saving memory. 
Setting Packing: The #pragma pack(push, 1) directive sets the alignment to 1 byte, meaning no padding will be added between members of the structure.

Defining a Packed Structure: The struct Packed is defined with a char, an int, and another char. With 1-byte packing, the total size will be 6 bytes (1 + 4 + 1).

Restoring Packing: The #pragma pack(pop) directive restores the previous packing alignment.

Size Calculation: The sizeof operator is used to determine the size of the packed structure, which will be smaller than the default alignment.
*/
#pragma pack(push, 1) // Set alignment to 1 byte

struct Packed {
    char a;      // 1 byte
    int b;       // 4 bytes
    char c;      // 1 byte
};

#pragma pack(pop) // Restore previous alignment



int main() {
    FILE *file;
    int num;

    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        fprintf(file, "%d\n", i * i);
    }

    fclose(file);

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &num) != EOF) {
        printf("%d\n", num);
    }

    fclose(file);

    /* 
    "r"	Read mode(file must exist).
    "w"	Write mode(truncates existing file or creates new).
    "a"	Append mode(creates new file if it doesn't exist).
    "r+" Read and write mode(file must exist).
    "w+" Write and read mode(truncates existing file or creates new).
    "a+" Append and read mode(creates new file if it doesn't exist).
    */


    union Data data;

    data.i = 10;
    printf("data.i: %d\n", data.i);

    data.f = 3.14159;
    printf("data.f: %f\n", data.f);

    data.c = 'A';
    printf("data.c: %c\n", data.c);

    printf("data.i: %d\n", data.i);


    struct Student student1;

    // Assign values to the members
    student1.id = 1;
    strcpy(student1.name, "Alice");
    student1.grade = 85.5;
    printf("Student ID: %d\n", student1.id);
    printf("Student Name: %s\n", student1.name);
    printf("Student Grade: %.2f\n", student1.grade);


    struct Date today;

    today.day = 15;   // Valid day
    today.month = 8;  // Valid month
    today.year = 21;  // Valid year

    printf("Date: %d/%d/%d\n", today.day, today.month, today.year);


    printf("Size of Padded structure: %zu bytes\n", sizeof(struct Padded));
    printf("Size of Unpadded structure: %zu bytes\n", sizeof(struct Unpadded));
    

    printf("Size of Packed structure: %zu bytes\n", sizeof(struct Packed));

    return 0;
}