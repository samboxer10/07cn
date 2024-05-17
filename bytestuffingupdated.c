#include <stdio.h>
#include <string.h>

char data[100];     // to store data entered by user
char prepData[400]; // to store data to be transmitted from sender to receiver

char flag[8] = {'0', '1', '1', '1', '1', '1', '1', '0'};
char esc[5] = {'1', '1', '0', '1', '1'};

int i = 0; // for tracking each bit of data
int j = 0; // for keeping track of prepData

// Function to check if data contains flag at position i
int isFlag(char data[], int i) {
    for (int k = 0; k < 8; k++) {
        if (data[i + k] != flag[k]) {
            return 0;
        }
    }
    return 1;
}

// Function to check if data contains esc at position i
int isEsc(char data[], int i) {
    for (int k = 0; k < 5; k++) {
        if (data[i + k] != esc[k]) {
            return 0;
        }
    }
    return 1;
}

void sender() {
    // Take data from user
    printf("Enter the data: ");
    scanf("%s", data);

    i = 0;
    j = 0;

    // Append flag at the beginning of prepData
    for (int k = 0; k < 8; k++) {
        prepData[j++] = flag[k];
    }

    // Prepare data to transmit from user's data
    while (i < strlen(data)) {
        // If there is flag in the data append esc and then flag to prepData
        if (isFlag(data, i)) {
            // Append esc
            for (int k = 0; k < 5; k++) {
                prepData[j++] = esc[k];
            }
            // Append flag
            for (int k = 0; k < 8; k++) {
                prepData[j++] = flag[k];
            }
            i += 8;
        }
        // If there is esc in the data append esc and esc to prepData
        else if (isEsc(data, i)) {
            // Append esc
            for (int k = 0; k < 5; k++) {
                prepData[j++] = esc[k];
            }
            // Append esc again
            for (int k = 0; k < 5; k++) {
                prepData[j++] = esc[k];
            }
            i += 5;
        }
        // Otherwise, just copy the data
        else {
            prepData[j++] = data[i++];
        }
    }

    // Append flag at the end of prepData
    for (int k = 0; k < 8; k++) {
        prepData[j++] = flag[k];
    }

    prepData[j] = '\0';

    printf("\nEntered Data: %s", data);
    printf("\nPrepared Data: %s", prepData);
}

int main() {
    sender();
    return 0;
}
