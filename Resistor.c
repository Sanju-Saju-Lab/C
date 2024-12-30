#include <stdio.h>
#include <string.h>
#include <math.h>

#define COLOR_CODE_COUNT 10
#define MULTIPLIER_COUNT 8
#define TOLERANCE_COUNT 4

// Arrays for color codes, values, multipliers, and tolerance values
const char *COLOR_CODES[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
const int COLOR_VALUES[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

const char *MULTIPLIERS[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "gold", "silver"};
const float MULTIPLIER_VALUES[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 1, 0.1};

const char *TOLERANCES[] = {"brown", "red", "gold", "silver"};
const char *TOLERANCE_VALUES[] = {"±1%", "±2%", "±5%", "±10%"};

// Function to calculate resistance based on color bands
void calculateResistance() {
    char band1[20], band2[20], multiplier[20], tolerance[20];

    // Display available color bands for user input
    printf("\nAvailable colors for 1st and 2nd band:\n");
    for (int i = 0; i < COLOR_CODE_COUNT; i++) {
        printf("%s ", COLOR_CODES[i]);
    }
    printf("\nEnter the 1st color: ");
    scanf("%s", band1);
    printf("Enter the 2nd color: ");
    scanf("%s", band2);

    // Display available multiplier colors
    printf("\nAvailable multiplier colors:\n");
    for (int i = 0; i < MULTIPLIER_COUNT; i++) {
        printf("%s ", MULTIPLIERS[i]);
    }
    printf("\nEnter the multiplier color: ");
    scanf("%s", multiplier);

    // Display available tolerance colors
    printf("\nAvailable tolerance colors:\n");
    for (int i = 0; i < TOLERANCE_COUNT; i++) {
        printf("%s ", TOLERANCES[i]);
    }
    printf("\nEnter the tolerance color: ");
    scanf("%s", tolerance);

    // Find the corresponding index for each input color
    int band1Index = -1, band2Index = -1, multiplierIndex = -1, toleranceIndex = -1;

    for (int i = 0; i < COLOR_CODE_COUNT; i++) {
        if (strcmp(band1, COLOR_CODES[i]) == 0) {
            band1Index = i;
        }
        if (strcmp(band2, COLOR_CODES[i]) == 0) {
            band2Index = i;
        }
    }

    for (int i = 0; i < MULTIPLIER_COUNT; i++) {
        if (strcmp(multiplier, MULTIPLIERS[i]) == 0) {
            multiplierIndex = i;
        }
    }

    for (int i = 0; i < TOLERANCE_COUNT; i++) {
        if (strcmp(tolerance, TOLERANCES[i]) == 0) {
            toleranceIndex = i;
        }
    }

    // If all inputs are valid, calculate resistance
    if (band1Index != -1 && band2Index != -1 && multiplierIndex != -1) {
        int resistance = (COLOR_VALUES[band1Index] * 10 + COLOR_VALUES[band2Index]) * MULTIPLIER_VALUES[multiplierIndex];
        printf("\nResistance: %d Ω %s\n", resistance, TOLERANCE_VALUES[toleranceIndex]);
    } else {
        printf("\nInvalid color code entered. Please try again.\n");
    }
}

// Function to suggest color bands based on the resistance value
void suggestColor() {
    float resistance;
    char tolerance[20];
    printf("\nEnter the resistance value in Ω: ");
    scanf("%f", &resistance);
    printf("Enter the tolerance (1%, 2%, 5%, or 10%): ");
    scanf("%s", tolerance);

    // Loop through possible color bands to match the resistance
    for (int band1 = 0; band1 < COLOR_CODE_COUNT; band1++) {
        for (int band2 = 0; band2 < COLOR_CODE_COUNT; band2++) {
            for (int multiplier = 0; multiplier < MULTIPLIER_COUNT; multiplier++) {
                float calculatedResistance = (COLOR_VALUES[band1] * 10 + COLOR_VALUES[band2]) * MULTIPLIER_VALUES[multiplier];
                if (fabs(calculatedResistance - resistance) < 0.001) {
                    int toleranceIndex = -1;
                    for (int i = 0; i < TOLERANCE_COUNT; i++) {
                        if (strcmp(tolerance, TOLERANCES[i]) == 0) {
                            toleranceIndex = i;
                            break;
                        }
                    }
                    if (toleranceIndex != -1) {
                        printf("\nColor Bands: %s, %s, %s, %s\n", COLOR_CODES[band1], COLOR_CODES[band2], MULTIPLIERS[multiplier], TOLERANCE_VALUES[toleranceIndex]);
                        return;
                    } else {
                        printf("\nInvalid tolerance value entered.\n");
                        return;
                    }
                }
            }
        }
    }
    printf("\nNo matching color code found.\n");
}

int main() {
    int choice;
    while (1) {
        // Display menu for user interaction
        printf("\nChoose an option:\n");
        printf("1. Calculate resistance from color bands.\n");
        printf("2. Suggest color bands from resistance.\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute the corresponding function based on user choice
        switch (choice) {
            case 1:
                calculateResistance();  // Call function to calculate resistance
                break;
            case 2:
                suggestColor();  // Call function to suggest color bands
                break;
            case 3:
                printf("\nExiting the program. Goodbye!\n");  // Exit the program
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");  // Handle invalid input
        }
    }
}
