#include <stdio.h>

void Calculatetime(float Tt,float Tp,int n){
    float time = 0;
    for(int i = 0; i < n; i++){
        time += Tp+Tt;
        printf("received P%d at %.2f ms\n",i+1,time);
        time += Tt+Tp;
        printf("received Ack%d at %.2f ms\n\n",i+2,time);
    }
    printf("Total time required is %.2f ms",n*2*(Tt+Tp));
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

    Calculatetime(Tt,Tp,n);
    return 0;
}
