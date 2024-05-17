#include <stdio.h>

void Calculatetime(float Tt, float Tp, int n, int *lost_packets) {
    float time = 0;
    int last_received_packet = 0;
    int lost_count = 0;
    float RTT = 2 * Tp;

    for (int i = 0; i < n; i++) {
        if (lost_packets[i]) {
            printf("Sending packet %d\n", i + 1);
            printf("Packet %d lost, retransmitting...\n", i + 1);
            time += (3 * RTT + Tt);
            printf("P%d resent at %.2f ms\n", i + 1, time);
            time += Tp;
            printf("Received P%d at %.2f ms\n", i + 1, time);
            time += Tt + Tp;
            printf("Received Ack%d at %.2f ms\n\n", i + 1, time);
            lost_count++;
        } else {
            time += Tp + Tt;
            printf("Received P%d at %.2f ms\n", i + 1, time);
            time += Tt + Tp;
            printf("Received Ack%d at %.2f ms\n\n", i + 1, time);
            last_received_packet = i + 1;
        }
    }

    float total_time = time;
    printf("Total time required is %.2f ms\n", total_time);
}

int main() {
    int n;
    float Tt, Tp;

    printf("Enter the number of packets: ");
    scanf("%d", &n);

    printf("Enter the transmission time per packet (in ms): ");
    scanf("%f", &Tt);

    printf("Enter the propagation time (in ms): ");
    scanf("%f", &Tp);

    int lost_packets[n];
    printf("Enter the packet numbers to be lost (separated by space, 1-indexed): ");
    for (int i = 0; i < n; i++) {
        lost_packets[i] = 0;
    }

    int packet_num;
    char ch;
    while (scanf("%d%c", &packet_num, &ch) == 2) {
        if (packet_num > 0 && packet_num <= n) {
            lost_packets[packet_num - 1] = 1;
        }
        if (ch == '\n') {
            break;
        }
    }

    Calculatetime(Tt, Tp, n, lost_packets);
    return 0;
}
