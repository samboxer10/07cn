#include <stdio.h>

int main() {
    int windowsize, totalPackets, sent = 0, ack, i;

    // Input total number of packets
    printf("Enter total number of packets to be sent: ");
    scanf("%d", &totalPackets);

    // Input window size
    printf("Enter window size: ");
    scanf("%d", &windowsize);

    while (sent < totalPackets) {
        // Transmit frames within the window
        for (i = 0; i < windowsize && sent < totalPackets; i++) {
            printf("Frame %d has been transmitted.\n", sent);
            sent++;
        }

        // Acknowledgement input
        printf("\nPlease enter the last Acknowledgement received.\n");
        scanf("%d", &ack);

        // If the last acknowledged packet equals the total packets, break
        if (ack >= totalPackets) {
            printf("All packets have been acknowledged.\n");
            break;
        } else {
            // Move the sent pointer to the last acknowledged packet
            sent = ack;
        }
    }

    return 0;
}