#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

double memory = 0; // Memory to store values
double ans = 0;    // Last result

// Function prototypes for each part of the calculator's operations
double evaluateExpression(char *expression);
double applyOperator(double a, double b, char op);
int precedence(char op);
void handleFunctions(char *expression);
void replaceConstants(char *expression);
void storeInMemory(double value);
void recallMemory();
void clearMemory();

int main() {
    char choice[3];

    // Main loop for the program where the user can choose different options
    while (1) {
        printf("\nOptions:\n1: Evaluate Expression\n2: Store in Memory\n3: Recall Memory\n4: Clear Memory\n5: Off\n");
        printf("\nEnter your choice: ");
        fgets(choice, 3, stdin); // Read the user choice

        // Option to turn off the calculator
        if (choice[0] == '5') {
            printf("CASIO\n");
            break; // Exit the program
        }

        // Option to evaluate a mathematical expression
        if (choice[0] == '1') {
            char expression[MAX_EXPR_LEN];
            printf("Enter the mathematical expression: ");
            getchar(); // Clear the input buffer
            fgets(expression, MAX_EXPR_LEN, stdin); // Read the expression

            // Evaluate the expression and print the result
            double result = evaluateExpression(expression);
            printf("Answer: %.2lf\n", result);
        } else if (choice[0] == '2') {
            double value;
            printf("Enter the value to store in memory: ");
            scanf("%lf", &value);
            storeInMemory(value); // Store value in memory
        } else if (choice[0] == '3') {
            recallMemory(); // Recall the stored memory value
        } else if (choice[0] == '4') {
            clearMemory(); // Clear the memory
        } else {
            printf("Invalid choice. Please try again.\n"); // Handle invalid input
        }
    }

    return 0;
}

// Function to evaluate the given mathematical expression
double evaluateExpression(char *expression) {
    replaceConstants(expression); // Replace 'pi' and 'Ans' constants with their values
    handleFunctions(expression); // Handle functions like sin, cos, etc.

    double operands[100]; // Array to hold numbers
    char operators[100];  // Array to hold operators
    int opIndex = -1, oprIndex = -1;
    double a, b;

    // Process the expression character by character
    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];

        // Skip spaces in the expression
        if (isspace(c)) continue;

        // If the character is a number or decimal point, process it
        if (isdigit(c) || c == '.') {
            char num[50];
            int j = 0;
            while (i < strlen(expression) && (isdigit(expression[i]) || expression[i] == '.')) {
                num[j++] = expression[i++];
            }
            num[j] = '\0';
            i--; // Adjust index after reading number
            operands[++opIndex] = atof(num); // Convert string to double and store
        } else if (c == '(') {
            operators[++oprIndex] = c; // Push opening parenthesis to operators stack
        } else if (c == ')') {
            // Evaluate the expression inside the parentheses
            while (oprIndex >= 0 && operators[oprIndex] != '(') {
                b = operands[opIndex--];
                a = operands[opIndex--];
                char op = operators[oprIndex--];
                operands[++opIndex] = applyOperator(a, b, op); // Apply the operator
            }
            oprIndex--; // Remove '(' from the stack
        } else {
            // Process the operators based on precedence
            while (oprIndex >= 0 && precedence(operators[oprIndex]) >= precedence(c)) {
                b = operands[opIndex--];
                a = operands[opIndex--];
                char op = operators[oprIndex--];
                operands[++opIndex] = applyOperator(a, b, op); // Apply the operator
            }
            operators[++oprIndex] = c; // Push the operator to the stack
        }
    }

    // Evaluate any remaining operators
    while (oprIndex >= 0) {
        b = operands[opIndex--];
        a = operands[opIndex--];
        char op = operators[oprIndex--];
        operands[++opIndex] = applyOperator(a, b, op); // Apply the remaining operators
    }

    ans = operands[opIndex]; // Store the last result
    return operands[opIndex]; // Return the result of the expression
}

// Function to apply the operator on two operands
double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b; // Handle division by zero
            else {
                printf("Math ERROR: Division by zero\n");
                exit(1); // Exit on error
            }
        case '^': return pow(a, b); // Handle exponentiation
        default: return 0; // Default case for unsupported operators
    }
}

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1; // Lower precedence
    if (op == '*' || op == '/') return 2; // Higher precedence
    if (op == '^') return 3; // Highest precedence
    return 0; // Default case
}

// Function to handle mathematical functions like sin, cos, log, etc.
void handleFunctions(char *expression) {
    char *funcs[] = {"sin", "cos", "tan", "log", "ln", "sqrt"};
    double result;
    char *funcPos;

    // Loop through each function and replace it with its result
    for (int i = 0; i < 6; i++) {
        funcPos = strstr(expression, funcs[i]);
        while (funcPos != NULL) {
            char *openParen = strchr(funcPos, '(');
            char *closeParen = strchr(funcPos, ')');
            if (openParen && closeParen) {
                char num[20];
                strncpy(num, openParen + 1, closeParen - openParen - 1); // Extract argument inside parentheses
                num[closeParen - openParen - 1] = '\0';
                double value = atof(num); // Convert to double

                // Calculate the result based on the function
                if (strcmp(funcs[i], "sin") == 0) result = sin(value * M_PI / 180.0);
                else if (strcmp(funcs[i], "cos") == 0) result = cos(value * M_PI / 180.0);
                else if (strcmp(funcs[i], "tan") == 0) result = tan(value * M_PI / 180.0);
                else if (strcmp(funcs[i], "log") == 0) result = log10(value);
                else if (strcmp(funcs[i], "ln") == 0) result = log(value);
                else if (strcmp(funcs[i], "sqrt") == 0) {
                    if (value < 0) {
                        printf("Math ERROR: Negative square root\n");
                        exit(1); // Exit on error
                    }
                    result = sqrt(value);
                }

                // Replace the function in the expression with its result
                char resultStr[50];
                sprintf(resultStr, "%.2lf", result);
                memmove(openParen, resultStr, strlen(resultStr)); // Replace with result
                memmove(closeParen + 1, closeParen + 1, strlen(closeParen) + 1); // Shift the string
            }
            funcPos = strstr(funcPos + 1, funcs[i]); // Move to the next occurrence
        }
    }
}

// Function to replace constants like 'pi' and 'Ans' in the expression
void replaceConstants(char *expression) {
    char piStr[50];
    sprintf(piStr, "%.15lf", M_PI); // Convert pi to a string
    char *pos = strstr(expression, "pi");
    if (pos) memmove(pos, piStr, strlen(piStr)); // Replace 'pi'

    char ansStr[50];
    sprintf(ansStr, "%.2lf", ans); // Convert the last result to a string
    pos = strstr(expression, "Ans");
    if (pos) memmove(pos, ansStr, strlen(ansStr)); // Replace 'Ans'
}

// Function to store a value in memory
void storeInMemory(double value) {
    memory = value;
    printf("Stored in memory\n");
}

// Function to recall the stored value from memory
void recallMemory() {
    printf("Memory value: %.2lf\n", memory);
}

// Function to clear the memory
void clearMemory() {
    memory = 0;
    printf("Memory cleared\n");
}
