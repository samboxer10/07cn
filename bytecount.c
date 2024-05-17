#include <stdio.h>
#include <string.h>

char data[8];
char datawithLen[9];

void sender() {
    printf("\nSender\n-------------------------------------");

    printf("\nEnter data: ");
    scanf("%s", data);

    int len = strlen(data);
    datawithLen[0] = len + '0'; // Store the length of data as a character

    for(int i = 0; i < len; i++) {
        datawithLen[i + 1] = data[i];
    }

    datawithLen[len + 1] = '\0';
    printf("\nData to send: ");
    for(int i = 0; i <= len; i++) {
        printf("%c ", datawithLen[i]);
    }
}

void receiver(char datawithLen[]) {
    printf("\n\nReceiver\n-------------------------------------");
    int lenofDataReceived = datawithLen[0] - '0'; // Convert char back to integer
    printf("\nOriginal Data: ");
    for(int i = 1; i <= lenofDataReceived; i++) {
        printf("%c ", datawithLen[i]);
    }
    printf("\n");
}

int main() {
    sender();
    receiver(datawithLen);
    return 0;
}



#include <stdio.h>
#include <string.h>

#define MAX_DATA_SIZE 8
#define MAX_DATA_LEN (MAX_DATA_SIZE + 1)

char data[MAX_DATA_SIZE];
char datawithLen[MAX_DATA_LEN];

void sender() {
    printf("\nSender\n-------------------------------------");

    printf("\nEnter data: ");
    scanf("%s", data);

    int len = strlen(data);
    if (len > MAX_DATA_SIZE) {
        printf("\nData exceeds maximum allowed size.\n");
        return;
    }

    datawithLen[0] = len + '0'; // Store the length of data as a character

    for(int i = 0; i < len; i++) {
        datawithLen[i + 1] = data[i];
    }

    datawithLen[len + 1] = '\0';
    printf("\nData to send: ");
    for(int i = 0; i <= len; i++) {
        printf("%c ", datawithLen[i]);
    }

    // Counting number of bytes
    int numBytes = strlen(datawithLen) + 1; // +1 for null terminator
    printf("\nNumber of bytes sent: %d\n", numBytes);
}

void receiver(char datawithLen[]) {
    printf("\n\nReceiver\n-------------------------------------");
    int lenofDataReceived = datawithLen[0] - '0'; // Convert char back to integer
    printf("\nOriginal Data: ");
    for(int i = 1; i <= lenofDataReceived; i++) {
        printf("%c ", datawithLen[i]);
    }
    printf("\n");

    // Counting number of bytes
    int numBytes = strlen(datawithLen) + 1; // +1 for null terminator
    printf("\nNumber of bytes received: %d\n", numBytes);
}

int main() {
    sender();
    receiver(datawithLen);
    return 0;
}
