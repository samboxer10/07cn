#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080  // Specify the port here
#define MAX_DATA_SIZE 1024  // Maximum size of data in the packet

typedef struct packet {
    char data[MAX_DATA_SIZE];
} Packet;

typedef struct frame {
    int frame_kind; // ACK:0, SEQ:1 FIN:2
    int sq_no;
    int ack;
    Packet packet;
} Frame;

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    int frame_id = 0;
    Frame frame_send;
    Frame frame_recv;
    int ack_recv = 1;

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Configure server address
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);  // Specify the port here
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Get number of packets to send from user
    int num_packets;
    printf("Enter the number of packets to send: ");
    scanf("%d", &num_packets);

    // Get size of data packet from user
    int packet_size;
    printf("Enter the size of data packet (max %d bytes): ", MAX_DATA_SIZE);
    scanf("%d", &packet_size);
    
    if (packet_size > MAX_DATA_SIZE || packet_size <= 0) {
        printf("Invalid packet size. Please enter a value between 1 and %d.\n", MAX_DATA_SIZE);
        return 1;
    }

    for (int i = 0; i < num_packets; i++) {
        if (ack_recv == 1) {
            frame_send.sq_no = frame_id;
            frame_send.frame_kind = 1;
            frame_send.ack = 0;

            printf("Enter Data: ");
            scanf("%s", frame_send.packet.data);

            // Ensure the data does not exceed the specified packet size
            frame_send.packet.data[packet_size - 1] = '\0'; // Null-terminate if necessary

            sendto(sockfd, &frame_send, sizeof(Frame), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
            printf("Frame Sent\n");
        }

        addr_size = sizeof(serverAddr);
        int f_recv_size = recvfrom(sockfd, &frame_recv, sizeof(frame_recv), 0, (struct sockaddr*)&serverAddr, &addr_size);

        if (f_recv_size > 0 && frame_recv.sq_no == 0 && frame_recv.ack == frame_id + 1) {
            printf("Ack Received\n");
            ack_recv = 1;
        } else {
            printf("Ack Not Received\n");
            ack_recv = 0;
        }

        frame_id++;
    }

    // Close socket
    close(sockfd);
    return 0;
}
