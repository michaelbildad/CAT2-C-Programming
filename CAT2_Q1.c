/*
  Name: Michael Mubia 
  Reg No: CT101/G/26492/25 
  Description: A C program for a 2d array 
*/
#include <stdio.h>

int main() {
    // Declaring and initializing the first 2x2 matrix
    int scores1[2][2] = {
        {65, 92},
        {84, 72}
    };
    
    // Declaring and initializing the second 2x2 matrix
    int scores2[2][2] = {
        {35, 70},
        {59, 67}
    };
    
    int i, j; 
    
    printf("\nPrinting the two 2x2 matrices side-by-side:\n");

    for (i = 0; i < 2; i++) {
        printf("["); 
        for (j = 0; j < 2; j++) {
            printf("%3d", scores1[i][j]); 
            if (j < 1) { 
                printf(" "); // Space between elements in the row
            }
        }
        printf("]"); 
        
        // --- Spacer between the two matrices ---
        printf(" ["); 

        // --- Print Second Matrix (scores2) ---
        for (j = 0; j < 2; j++) {
            printf("%3d", scores2[i][j]); 
            if (j < 1) { 
                printf(" ");
            }
        }
        printf("]"); 
        
        // Move to the next line for the next row
        printf("\n");
    }
    
    return 0;
}