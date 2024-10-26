#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int convert(int x,int y); int neighbours(bool* data,int pos);
int main() {
    bool grid[100]; bool buffer[100]; char input[2]; for (int i=0;i<100;i++) { grid[i]=0; buffer[i]=0; }
    while (true) {
        printf(" A B C D E F G H\n");
        for (int i=10;i<89;i++) {
            switch (i%10) {
                case 9:
                    printf("\e[0m\n");
                    break;
                case 0:
                    printf("%d",7-((i/10)-1));
                    break;
                default:
                    printf("\e[48;5;%dm  ",15-grid[i]*15);
            } 
        }
        printf("\e[0m\n(XY/ST/RT)?:"); scanf("%s",input); char in=(input[0]%32==19)+2*(input[0]%32==18);
        switch(in) {
            case 0:
                grid[convert((input[0]-1)%8,input[1]%8)]=1-grid[convert((input[0]-1)%8,input[1]%8)]; break;
            case 1:
                for (int i=11;i<89;i++) {
                    if (i%10==9 || i%10==0) { continue; }
                    switch (neighbours(grid,i)) {
                        case 2:
                            buffer[i]=grid[i]; break;
                        case 3:
                            buffer[i]=1; break;
                        default:
                            buffer[i]=0; break;
                    } } 
                for (int i=11;i<89;i++) { grid[i]=buffer[i]; } break;
            case 2:
                for (int i=11;i<89;i++) { grid[i]=0; } break;
        }
        system("clear");
    }
    return 0;
}
int convert(int x,int y) { return 10*(8-y)+x+1; }
int neighbours(bool* data,int pos) {
    int offset[8]={11,10,9,1}; int n=0;
    for (int i=0;i<4;i++) { n=n+data[pos+offset[i]]+data[pos-offset[i]]; } return n; }
