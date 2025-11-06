/*
  Name: Michael Mubia 
  Reg No: CT101/G/26492/25 
  Description: A C program for a file . 
*/
#include <stdio.h>
#include <stdlib.h> 

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define NUM_INTEGERS 10

void createInputFile() {
    FILE *file_ptr;
    int number;

    // Open the file in write mode ("w"). "w" creates the file if it doesn't exist, 
    // or overwrites it if it does.
    file_ptr = fopen(INPUT_FILE, "w");

    // Error Handling (4)
    if (file_ptr == NULL) {
        perror("Error opening input.txt for writing");
        return;
    }

    printf("Please enter %d integers:\n", NUM_INTEGERS);
    
    for (int i = 0; i < NUM_INTEGERS; i++) {
        printf("Enter integer #%d: ", i + 1);
        
        // Read integer from user
        if (scanf("%d", &number) != 1) {
            printf("Invalid input. Skipping remaining inputs.\n");
            break; 
        }
        
        // Write integer to file, followed by a newline for separation
        fprintf(file_ptr, "%d\n", number);
    }

    // Close the file
    fclose(file_ptr);
    printf("Successfully wrote integers to %s.\n", INPUT_FILE);
}

// ----------------------------------------------------------------------
// 2. Function to read from input.txt, calculate sum/average, and write to output.txt
// ----------------------------------------------------------------------
void processAndSave() {
    FILE *input_ptr, *output_ptr;
    int number, count = 0;
    long long sum = 0;
    double average = 0.0;

    // Open input file for reading ("r")
    input_ptr = fopen(INPUT_FILE, "r");
    // Error Handling (4)
    if (input_ptr == NULL) {
        perror("Error opening input.txt for reading");
        return;
    }

    // Open output file for writing ("w")
    output_ptr = fopen(OUTPUT_FILE, "w");
    // Error Handling (4)
    if (output_ptr == NULL) {
        perror("Error opening output.txt for writing");
        fclose(input_ptr); // Close input file before returning
        return;
    }

    printf("\n--- Task 2: Processing Data ---\n");
    
    // Read integers from the input file until the end of file (EOF) is reached
    while (fscanf(input_ptr, "%d", &number) == 1) {
        sum += number;
        count++;
    }

    if (count > 0) {
        average = (double)sum / count;
    }

    // Write results to output.txt in a formatted manner
    fprintf(output_ptr, "--- Analysis of %d Integers from %s ---\n", count, INPUT_FILE);
    fprintf(output_ptr, "Total Sum: %lld\n", sum);
    fprintf(output_ptr, "Average: %.2f\n", average);
    fprintf(output_ptr, "------------------------------------------------\n");
    
    // Close files
    fclose(input_ptr);
    fclose(output_ptr);
    printf("Calculations complete. Results saved to %s.\n", OUTPUT_FILE);
}

// ----------------------------------------------------------------------
// 3. Function to read and display the contents of both files
// ----------------------------------------------------------------------
void displayFileContents(const char *filename) {
    FILE *file_ptr;
    int character;

    file_ptr = fopen(filename, "r");
    
    // Error Handling (4)
    if (file_ptr == NULL) {
        perror("Error opening file for display");
        return;
    }

    printf("Contents of %s:\n", filename);
    printf("--------------------------------\n");
    
    // Read character by character until the end of file (EOF)
    while ((character = fgetc(file_ptr)) != EOF) {
        putchar(character);
    }
    
    printf("--------------------------------\n");
    
    fclose(file_ptr);
}

void displayFiles() {
    printf("\n--- Task 3: Displaying File Contents ---\n");
    displayFileContents(INPUT_FILE);
    displayFileContents(OUTPUT_FILE);
}

// ----------------------------------------------------------------------
// Main Function to execute the tasks
// ----------------------------------------------------------------------
int main() {
    // 1. Create and populate input file
    createInputFile();
    
    // 2. Process data and save results to output file
    processAndSave();
    
    // 3. Display the contents of both files
    displayFiles();
    
    return 0;
}