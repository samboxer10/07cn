#include <stdio.h>

#define MAX_PACKET_SIZE 1500
#define MAX_WINDOW_SIZE 5

int calculateMaxPackets(int transmissionTime, int propagationTime) {
    return (transmissionTime + propagationTime) / transmissionTime;
}

int calculateSequenceNumberBits(int maxPackets) {
    int bits = 0;
    while ((1 << bits) < maxPackets)
        bits++;
    return bits;
}

int calculateSenderWindow(int maxWindowSize, int maxPackets) {
    return (maxWindowSize < maxPackets) ? maxWindowSize : maxPackets;
}

float calculateEfficiency(int transmissionTime, int propagationTime, int maxPackets, int windowSize) {
    return (float)windowSize / ((float)transmissionTime / (transmissionTime + propagationTime));
}
int main() {
    int transmissionTime, propagationTime;
    printf("Enter transmission time (in milliseconds): ");
    scanf("%d", &transmissionTime);
    printf("Enter propagation time (in milliseconds): ");
    scanf("%d", &propagationTime);
    int maxPackets = calculateMaxPackets(transmissionTime, propagationTime);
    printf("Maximum packets to transmit: %d\n", maxPackets);
    int sequenceNumberBits = calculateSequenceNumberBits(maxPackets);
    printf("Number of bits in the sequence number: %d\n", sequenceNumberBits);
    int windowSize = calculateSenderWindow(MAX_WINDOW_SIZE, maxPackets);
    printf("Sender window size: %d\n", windowSize);
    float efficiency = calculateEfficiency(transmissionTime, propagationTime, maxPackets, windowSize);
    printf("Efficiency of the algorithm: %.2f\n", efficiency);
    return 0;
}
