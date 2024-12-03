#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main32() {
    // malloc to allocate memory for an array of integers
    int* arr = (int*)malloc(5 * sizeof(int));
    if (arr == NULL) {
        perror("Failed to allocate memory using malloc");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    // Print the initial array
    printf("Array after malloc and initialization: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // calloc to allocate memory for another array
    int* arr_calloc = (int*)calloc(5, sizeof(int));
    if (arr_calloc == NULL) {
        perror("Failed to allocate memory using calloc");
        free(arr); // Free previously allocated memory
        return 1;
    }

    // Print the calloc array
    printf("Array after calloc: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr_calloc[i]);
    }
    printf("\n");

    // realloc to resize the first array
    arr = (int*)realloc(arr, 10 * sizeof(int)); // Resize to hold 10 integers
    if (arr == NULL) {
        perror("Failed to reallocate memory using realloc");
        free(arr_calloc); // Free calloc memory
        return 1;
    }

    // Initialize new elements
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1; // Assign values 6 to 10
    }

    // Print the resized array
    printf("Array after realloc: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // memcpy to copy data from one array to another
    int arr_copy[10];
    memcpy(arr_copy, arr, 10 * sizeof(int)); // Copy the contents of arr to arr_copy

    // Print the copied array
    printf("Copied array using memcpy: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr_copy[i]);
    }
    printf("\n");

    // memset to set the first 5 elements of arr_copy to 0
    memset(arr_copy, 0, 5 * sizeof(int)); // Set first 5 elements to 0

    // Print the modified copied array
    printf("Modified copied array after memset: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr_copy[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);
    free(arr_calloc);

    // time() to get the current time
    time_t current_time;
    current_time = time(NULL); // Get the current time
    if (current_time == ((time_t)-1)) {
        perror("Failed to get the current time");
        return 1;
    }
    printf("Current time in seconds since the Epoch: %ld\n", current_time);

    // localtime_s() to convert time_t to struct tm
    struct tm local_time;
    if (localtime_s(&local_time, &current_time) != 0) { // Convert to local time
        perror("Failed to convert time to local time");
        return 1;
    }
    char time_string[26];
    if (asctime_s(time_string, sizeof(time_string), &local_time) != 0) { // Convert struct tm to string
        perror("Failed to convert time to string");
        return 1;
    }
    printf("Local time: %s", time_string);

    // strftime() to format the time
    char buffer[80];
    if (strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_time) == 0) {
        perror("strftime failed");
        return 1;
    }
    printf("Formatted local time: %s\n", buffer);

    // perror() to display error messages
    FILE* file;
    if (fopen_s(&file, "non_existent_file.txt", "r") != 0) {
        perror("Error opening file");
        // The error message will be printed to stderr
    }
    else {
        fclose(file); // Close the file if it was opened successfully
    }

    return 0;
}