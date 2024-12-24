#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

double memory = 0; // Memory to store values
double ans = 0;    // Last result

// Function prototypes
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

    while (1) {
        printf("\nOptions:\n1: Evaluate Expression\n2: Store in Memory\n3: Recall Memory\n4: Clear Memory\n5: Off\n");
        printf("\nEnter your choice: ");
        fgets(choice, 3, stdin); // Read the user choice

        if (choice[0] == '5') {
            printf("CASIO\n");
            break;
        }

        if (choice[0] == '1') {
            char expression[MAX_EXPR_LEN];
            printf("Enter the mathematical expression: ");
            getchar(); // Clear the input buffer
            fgets(expression, MAX_EXPR_LEN, stdin); // Read the expression

            // Evaluate the expression
            double result = evaluateExpression(expression);
            printf("Answer: %.2lf\n", result);
        } else if (choice[0] == '2') {
            double value;
            printf("Enter the value to store in memory: ");
            scanf("%lf", &value);
            storeInMemory(value);
        } else if (choice[0] == '3') {
            recallMemory();
        } else if (choice[0] == '4') {
            clearMemory();
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

double evaluateExpression(char *expression) {
    replaceConstants(expression); // Replace pi and Ans constants
    handleFunctions(expression); // Handle mathematical functions (sin, cos, etc.)

    double operands[100];
    char operators[100];
    int opIndex = -1, oprIndex = -1;
    double a, b;

    // Process the expression character by character
    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];

        if (isspace(c)) continue;

        if (isdigit(c) || c == '.') {
            char num[50];
            int j = 0;
            while (i < strlen(expression) && (isdigit(expression[i]) || expression[i] == '.')) {
                num[j++] = expression[i++];
            }
            num[j] = '\0';
            i--; // Adjust index after reading number
            operands[++opIndex] = atof(num);
        } else if (c == '(') {
            operators[++oprIndex] = c;
        } else if (c == ')') {
            while (oprIndex >= 0 && operators[oprIndex] != '(') {
                b = operands[opIndex--];
                a = operands[opIndex--];
                char op = operators[oprIndex--];
                operands[++opIndex] = applyOperator(a, b, op);
            }
            oprIndex--; // Remove '('
        } else {
            while (oprIndex >= 0 && precedence(operators[oprIndex]) >= precedence(c)) {
                b = operands[opIndex--];
                a = operands[opIndex--];
                char op = operators[oprIndex--];
                operands[++opIndex] = applyOperator(a, b, op);
            }
            operators[++oprIndex] = c;
        }
    }

    // Process any remaining operators
    while (oprIndex >= 0) {
        b = operands[opIndex--];
        a = operands[opIndex--];
        char op = operators[oprIndex--];
        operands[++opIndex] = applyOperator(a, b, op);
    }

    ans = operands[opIndex]; // Store last result
    return operands[opIndex];
}

double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b != 0) return a / b;
            else {
                printf("Math ERROR: Division by zero\n");
                exit(1);
            }
        case '^': return pow(a, b);
        default: return 0;
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void handleFunctions(char *expression) {
    char *funcs[] = {"sin", "cos", "tan", "log", "ln", "sqrt"};
    double result;
    char *funcPos;

    for (int i = 0; i < 6; i++) {
        funcPos = strstr(expression, funcs[i]);
        while (funcPos != NULL) {
            char *openParen = strchr(funcPos, '(');
            char *closeParen = strchr(funcPos, ')');
            if (openParen && closeParen) {
                char num[20];
                strncpy(num, openParen + 1, closeParen - openParen - 1);
                num[closeParen - openParen - 1] = '\0';
                double value = atof(num);

                if (strcmp(funcs[i], "sin") == 0) result = sin(value * M_PI / 180.0);
                else if (strcmp(funcs[i], "cos") == 0) result = cos(value * M_PI / 180.0);
                else if (strcmp(funcs[i], "tan") == 0) result = tan(value * M_PI / 180.0);
                else if (strcmp(funcs[i], "log") == 0) result = log10(value);
                else if (strcmp(funcs[i], "ln") == 0) result = log(value);
                else if (strcmp(funcs[i], "sqrt") == 0) {
                    if (value < 0) {
                        printf("Math ERROR: Negative square root\n");
                        exit(1);
                    }
                    result = sqrt(value);
                }

                // Replace the function with its result
                char resultStr[50];
                sprintf(resultStr, "%.2lf", result);
                memmove(openParen, resultStr, strlen(resultStr));
                memmove(closeParen + 1, closeParen + 1, strlen(closeParen) + 1); // Shift the string
            }
            funcPos = strstr(funcPos + 1, funcs[i]); // Move to the next occurrence
        }
    }
}

void replaceConstants(char *expression) {
    // Replace pi and Ans constants
    char piStr[50];
    sprintf(piStr, "%.15lf", M_PI);
    char *pos = strstr(expression, "pi");
    if (pos) memmove(pos, piStr, strlen(piStr));

    char ansStr[50];
    sprintf(ansStr, "%.2lf", ans);
    pos = strstr(expression, "Ans");
    if (pos) memmove(pos, ansStr, strlen(ansStr));
}

void storeInMemory(double value) {
    memory = value;
    printf("Stored in memory\n");
}

void recallMemory() {
    printf("Memory value: %.2lf\n", memory);
}

void clearMemory() {
    memory = 0;
    printf("Memory cleared\n");
}
