#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Generate();
int Picked_i(int picked);
int Picked_j(int picked);

int main() {
    char method = 'a';
    int size_width = 0, size_height = 0;
    srand(time(NULL));

//    method = getchar();
    if(method == 'a'){
        scanf("%d %d", &size_height, &size_width);
    }else if(method == 'b'){

    }else{
        return 0;
    }

    int curNonZero = (size_width * size_height);
    int curHeight = (int)(size_height/2);
    int curWidth = (int)(size_width/2);
    int map[size_height][size_width];
    for(int i = 0;i<size_height;i++){
        for(int j = 0;j<size_width;j++){
            map[i][j] = 0;
        }
    }

    while(curNonZero != 1){
        int num = Generate();
        printf("%d\n",num);
//        printf("A");
        printf("   PI:%d   PJ:%d \n",Picked_i(num), Picked_j(num));
        printf("   SH:%d   SW:%d \n",size_height,size_width);
        if(0<= (curHeight+ Picked_i(num)) && (curHeight+ Picked_i(num))<(size_height) && 0 <= (curWidth + Picked_j(num)) && (curWidth + Picked_j(num)) < (size_width)){
            int nextHeight = curHeight+ Picked_i(num);
            int nextWidth = curWidth + Picked_j(num);
//            printf("C");
            printf("  NH:%d NW:%d  \n",nextHeight,nextWidth);
            printf("  CH:%d CW:%d  \n",curHeight,curWidth);
            if(map[nextHeight][nextWidth] == 0){
                curNonZero--;
                printf("D");
                printf("%d",curNonZero);
            }
            printf("\n---------------\n");
            for(int i = 0;i<size_height;i++){
                for(int j = 0;j<size_width;j++){
                    printf("%.02d ",map[i][j]);
                }
                printf("\n");
            }
            printf("---------------\n");
            map[nextHeight][nextWidth]++;
            printf("B");
            curHeight = nextHeight;
            curWidth = nextWidth;

            }
        }




    for(int i = 0;i<size_height;i++){
        for(int j = 0;j<size_width;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}


int Picked_i(int picked) {
    switch (picked) {
        case 0:
            return 1;
            break;
        case 1:
            return 1;
            break;
        case 2:
            return 0;
            break;
        case 3:
            return -1;
            break;
        case 4:
            return -1;
            break;
        case 5:
            return -1;
            break;
        case 6:
            return 0;
            break;
        case 7:
            return 1;
            break;
    }
}

int Picked_j(int picked) {
    switch (picked) {
        case 0:
            return 0;
            break;
        case 1:
            return 1;
            break;
        case 2:
            return 1;
            break;
        case 3:
            return 1;
            break;
        case 4:
            return 0;
            break;
        case 5:
            return -1;
            break;
        case 6:
            return -1;
            break;
        case 7:
            return -1;
            break;
    }
}

int Generate(){

    return (rand()%8);
}

