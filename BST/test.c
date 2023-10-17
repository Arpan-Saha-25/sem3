#include<stdio.h>


int main(int argc, char const *argv[])
{
    // int a = 1,b = 2;
    // (a>b) ? (b=a) : (a = b);
    // printf("%d %d",a,b);

    // int array[5] = {1,2,3,4,5};
    // a = array[array[array[1]]];
    // printf("\n%d " ,a);


    // short arr[4][4] = {0,0};
    // printf(" // %d " , sizeof(short));
    // printf(" >> %u" , &(arr[0][0]));
    // printf(" >> %u" , &(arr[1][3]));
    #define break continue
    for(int i = 0;i<10;i++){
        if(i % 2 == 0) break;
        printf("%d ",i+1);
    }

    int a = 3;
    // printf("%d%d%d",a++,a++,++a);
    printf("%d ",a++);
    printf("%d ",a++);
    printf("%d ",++a);

    a = 3;
    printf(" %d%d%d",a++,a++,++a);
                    //  5  4  5



    return 0;
}

