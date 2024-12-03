#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main66() {
    // 1. Using fgets() to read a string
    char str1[100];
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);

    // Remove newline character from fgets
    str1[strcspn(str1, "\n")] = 0;

    // 2. Using puts() to print the string
    puts("You entered:");
    puts(str1);

    // 3. Using putchar() to print each character
    printf("Characters in the string:\n");
    for (int i = 0; i < strlen(str1); i++) {
        putchar(str1[i]);
    }
    putchar('\n');

    // 4. Using strlen() to get the length of the string
    printf("Length of the string: %zu\n", strlen(str1));

    // 5. Using strcmp() to compare two strings
    char str2[] = "Hello";
    int cmpResult = strcmp(str1, str2);
    if (cmpResult < 0) {
        printf("'%s' is less than '%s'\n", str1, str2);
    }
    else if (cmpResult > 0) {
        printf("'%s' is greater than '%s'\n", str1, str2);
    }
    else {
        printf("'%s' is equal to '%s'\n", str1, str2);
    }

    // 6. Using strcat_s() to concatenate strings
    char str3[200] = "Greetings, ";
    strcat_s(str3, sizeof(str3), str1);
    printf("Concatenated string: %s\n", str3);

    // 7. Using strcpy_s() to copy a string
    char str4[100];
    strcpy_s(str4, sizeof(str4), str1);
    printf("Copied string: %s\n", str4);

    // 8. Using strchr() to find a character in the string
    char* ptr = strchr(str1, 'o');
    if (ptr) {
        printf("First occurrence of 'o' is at index: %d\n", ptr - str1 + 1);
    }
    else {
        printf("'o' not found in the string.\n");
    }

    // 9. Using _stricmp() for case-insensitive comparison
    char str5[] = "hello";
    if (_stricmp(str1, str5) == 0) {
        printf("'%s' is equal to '%s' (case-insensitive)\n", str1, str5);
    }

    // 10. Using strtok_s() to tokenize the string
    printf("Tokenizing the string:\n");
    char str6[] = "Hello, World! Welcome to C.";
    char* context; // Context for strtok_s
    char* token = strtok_s(str6, " ,.!?", &context); // tokenize by space, comma, period, and exclamation
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok_s(NULL, " ,.!?", &context); // Continue tokenizing
    }

    // 11. Using character functions
    printf("Character analysis:\n");
    for (int i = 0; i < strlen(str1); i++) {
        char ch = str1[i];
        printf("Character: %c, ", ch);
        printf("Lowercase: %c, ", tolower(ch));
        printf("Uppercase: %c, ", toupper(ch));
        printf("Is alpha: %d, ", isalpha(ch));
        printf("Is alnum: %d, ", isalnum(ch));
        printf("Is digit: %d, ", isdigit(ch));
        printf("Is space: %d\n", isspace(ch));
    }

    const char* num_str = "3567";
    int num = atoi(num_str);
    printf("The integer value is: %d\n", num);

    char str1_num[20];
    // Using _itoa_s instead of _itoa
    if (_itoa_s(num, str1_num, sizeof(str1_num), 10) == 0) { // Convert integer to string in base 10
        printf("The string value is: %s\n", str1_num);
    }
    else {
        printf("Error converting the integer to string.\n");
    }

    double num2 = 123.456;
    char str2_num[20];
    sprintf_s(str2_num, sizeof(str2_num), "%.2f", num2); // Convert float to string with 2 decimal places
    printf("The string value is: %s\n", str2_num);

    const char* str_input = "123 456";
    int a, b;
    if (sscanf_s(str_input, "%d %d", &a, &b) == 2) {
        printf("a: %d, b: %d\n", a, b); // Output: a: 123, b: 456
    }
    else {
        printf("Failed to parse the input string.\n");
    }

    printf("Exiting the program.\n");
    exit(0); // Exit with status code 0 (success)

    printf("Aborting the program.\n");
    abort(); // This will terminate the program immediately

    return 0;
}