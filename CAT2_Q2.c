/*
  Name: Michael Mubia 
  Reg No: CT101/G/26492/25 
  Description: A C program that prints gross pay, taxes and net pay. 
*/
#include <stdio.h>

// Define constants for the fixed values
#define STANDARD_HOURS 40.0
#define OVERTIME_RATE 1.5
#define TAX_BRACKET_1_LIMIT 600.0
#define TAX_RATE_1 0.15 // 15%
#define TAX_RATE_2 0.20 // 20%

int main() {
    // Variable declarations
    double hours_worked = 0.0;
    double hourly_wage = 0.0;
    double gross_pay = 0.0;
    double taxes = 0.0;
    double net_pay = 0.0;
    double regular_pay = 0.0;
    double overtime_pay = 0.0;

    // --- 1. Get User Input ---
    printf("--- Payroll Calculator ---\n");
    printf("Enter total hours worked this week: ");
    scanf("%lf", &hours_worked);

    printf("Enter the hourly wage ($): ");
    scanf("%lf", &hourly_wage);

    // --- 2. Calculate Gross Pay (Handling Overtime) ---

    if (hours_worked > STANDARD_HOURS) {
        // Calculate overtime hours and pay
        double overtime_hours = hours_worked - STANDARD_HOURS;
        
        regular_pay = STANDARD_HOURS * hourly_wage;
        overtime_pay = overtime_hours * hourly_wage * OVERTIME_RATE;
        
        gross_pay = regular_pay + overtime_pay;
        
        printf("\n(Calculated %.2f hours of overtime at %.2fx pay rate)\n", 
               overtime_hours, OVERTIME_RATE);
               
    } else {
        // No overtime
        gross_pay = hours_worked * hourly_wage;
    }
    
    // --- 3. Calculate Taxes ---
    
    if (gross_pay <= TAX_BRACKET_1_LIMIT) {
        // Tax is 15% of the entire gross pay
        taxes = gross_pay * TAX_RATE_1;
        
    } else {
        // Calculate tax for the first $600
        double tax_1 = TAX_BRACKET_1_LIMIT * TAX_RATE_1;
        
        // Calculate the remaining amount subject to the 20% tax
        double remaining_income = gross_pay - TAX_BRACKET_1_LIMIT;
        double tax_2 = remaining_income * TAX_RATE_2;
        
        // Total taxes
        taxes = tax_1 + tax_2;
    }
    
    // --- 4. Calculate Net Pay ---
    net_pay = gross_pay - taxes;

    // --- 5. Print Results (Formatted to two decimal places) ---
    printf("\n--- RESULTS ---\n");
    printf("Gross Pay:  $%.2f\n", gross_pay);
    printf("Taxes Paid: $%.2f\n", taxes);
    printf("Net Pay:    $%.2f\n", net_pay);
    printf("---------------\n");

    return 0;
}