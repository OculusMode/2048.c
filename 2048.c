#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*
Created by: Prashant aka pd, Balu and JayThakkar(jaggo) AKA tick tack trio(we can discuss the name later)
shubharab on 10 59 a.m. 30th August,2018 (Ariye ki bDay.!)
*/

void dummyToUnderStandPointer(int *ip, int *m , int *n){
    printf("%p %p %p", ip, m, n);
    printf("%d %d %d", *ip, *m, *n);
}

void part(){printf("---------------------\n");}
void makeZeroArray(int *a, int m , int n){
    // *a contains ref of array[0][0] means ref of array[0][1] will be ref+1 means ref(array[i][j] = ref(array[0][0]) + (i*m) + j)
    int i,j;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
          *( a + (i*m) + j) = 0;
        }
    }
}

void printData(int *a, int m, int n){
    // *a contains ref of array[0][0] means ref of array[0][1] will be ref+1 means ref(array[i][j] = ref(array[0][0]) + (i*m) + j)
    int i,j;
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
          if(*( a + (i*m) + j) == 0)
              printf("- ");
            else
                printf("%d ", *( a + (i*m) + j)); // a + i*m + j = array[i][j]'s pointer
        }
        printf("\n");
    }
}

void up(int *a, int m, int n){
    /*
    if ele = 0 || ele = nichenuEle
        ele = ele + nichenuEle
        nichenuEle = 0
    */
    int i,j;
    for(int i=0;i<m-1;i++){ //there is no need to make actions for last row(think about it)
      for(int j=0;j<n;j++){ 
            printf("%d-%d-%d-%d ",i,j,*( a + (i*m) + j), *( a + ((i+1)*m) + j));
            if(*( a + (i*m) + j) == 0 || *( a + (i*m) + j) == *( a + ((i+1)*m) + j)){ //if ele = 0 || ele = nichenuEle
            // if(*( a + (i*m) + j) == *( a + ((i+1)*m) + j)){ //ele = nichenuEle
                *( a + (i*m) + j) = *( a + (i*m) + j) + *( a + ((i+1)*m) + j); //ele = ele + nichenuEle
                *( a + ((i+1)*m) + j) = 0; //nichenuEle = 0
            }
        }
        printf("\n");
    }
}

void all(int *a, int m, int n, int choice){
    int i,j,k;
    //lets simply create array so code becomes simpler
    int array[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            array[i][j] = *(a + (i*m) + j);
    }
    int iStart = 0, iEnd = m, jStart = 0, jEnd = n, iIncr = 1, jIncr = 1;
    switch(choice){
        case 0:  //down       
            iStart = m;
            iEnd = 1;
            iIncr = -1;
    }
    /*
    if ele = 0 || ele = nextEle
        ele = ele + nextEle
        put everything down
    */
   for(i=iStart;i<iEnd;i = i + iIncr){
        for(j=jStart;j<jEnd;j = j + jIncr){
            if(array[i][j] == 0 || array[i][j] == array[i+1][j]){
                array[i][j] = array[i+1][j] + array[i][j];
                for(k=i+1;k<m-1;k++){
                    array[k][j] = array[k+1][j];
                }
                array[m-1][j] = 0;
            }
        }
    }
    
}

void newUp(int *a, int m, int n){
    int i,j,k;
    //lets simply create array so code becomes simpler
    int array[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            array[i][j] = *(a + (i*m) + j);
    }
    /*
    if ele = 0 || ele = nextEle
        ele = ele + nextEle
        put everything down
    */
    for(i=0;i<m-1;i++){
        for(j=0;j<n;j++){
            if(array[i][j] == 0 || array[i][j] == array[i+1][j]){
                array[i][j] = array[i+1][j] + array[i][j];
                for(k=i+1;k<m-1;k++){
                    array[k][j] = array[k+1][j];
                }
                array[m-1][j] = 0;
            }
        }
    }
    //the manipulation on array is done so give the shit back to pointers (ITS C LOL)
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            *(a + (i*m) + j) = array[i][j];
    }

}
void findZeroPlaces(int *a, int m, int n){
    int i=0,array[m*n],length=0;
    for(i=0;i<m*n;i++){
        if(*(a+i) == 0){
            // printf("%d ", i);
            array[length] = i;
            length++;
        }
    }
    
    int r = rand() % length;
    *(a + array[r]) = 2;

    // printf("%d ", array[ rand() % length]);
    // printf("%d ", array[ rand() % length]);
    // printf("%d ", aa);
    // printf("%d", ab);
}
void leftAndRight(int *a, int m, int n,int pd){
    /**
     * pd = 0 => left
     * pd = 1 => right
     * pd = 2 => up
     * pd = 3 => down
    */
    // printf("start");
    int i,j,k;
    //lets simply create array so code becomes simpler
    int array[m][n];

    for(i=0;i<m;i++){
        // printf("%d", i);
        for(j=0;j<n;j++){
        switch(pd){
        case 4: //left
            array[i][j] = *(a + ( i * m ) + j);
            break;
        case 6: //right
            array[i][j] = *(a + ( i * m ) + n - 1 - j);
            break;
        case 8: //up
            array[i][j] = *(a + ( j * m ) + i);
            break;
        case 2: //down
            array[i][j] = *(a + ( ( m - 1 - j ) * m) +  i);
            break;
        }
        }
    }
    // for(i=0;i<m;i++){
    //     for(j=0; j<n ; j++)
    //         printf("%d ", array[i][j]);
    //     printf("\n");
    // }
    for(i=0;i<m;i++){
        for(j=0; j<n-1 ; j++){
            int z = 0;
            for(k=j+1; k < n ;k++){
                if(array[i][k] != 0){
                    if(array[i][j] == 0 || array[i][j] == array[i][k]){
                    int temp = array[i][j]; //storing in temp to check later
                    array[i][j] = array[i][j] + array[i][k];
                    array[i][k] = 0;
                    // printf("%d %d \n", array[i][j], array[i][k]);
                    if(temp == 0)
                        j--;
                    break;
                    }
                    break;
                }
            }
            /*
            if ele = 0
                find first none0 and replace with it 
            if ele = nextEle
                ele = ele + nextEle
                put everything down
            */
    
            // if(array[i][j] == 0){
            //     // printf("inside %d %d \n", i,j);
            //     int z = 0;
            //     for(k=j+1;k<n;k++){
            //         if(array[i][k] != 0){
            //             z = array[i][k];
            //             array[i][k] = 0;
            //             break;
            //         }
            //     }
            //     // printf("%d \n",z);
            //     array[i][j] = z;
            // } 
            // if(array[i][j] == 0 || array[i][j] == array[i][j+1]){
            //     array[i][j] = array[i][j] + array[i][j+1];
            //     for(k=j+1; k < n-1 ;k++){
            //         array[i][k] = array[i][k+1];
            //     }
            //     array[i][n-1] = 0;
            // }
        }
    }
    //the manipulation on array is done so give the shit back to pointers (ITS C LOL)
    // printf("abc");
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            switch(pd){
            case 4: //left
                *(a + (i*m) + j) = array[i][j];
                break;
            case 6: //right
                *(a + (i*m) + n - 1 - j) = array[i][j];
                break;
            case 8: //up
                *(a + (j*m) + i) = array[i][j];
                break;
            case 2: //down
                *(a + ( ( m - 1 - j ) * m) +  i) = array[i][j];
                break;
            }
        }
    }
}

void main(){
    srand(time(0));
    int m = 4, n = 4;/* we will make m*n as dynamic array. static of 4 for now*/
    int dataArray[m][n];
    makeZeroArray(&dataArray[0][0], m, n);
    findZeroPlaces(&dataArray[0][0], m, n);
    findZeroPlaces(&dataArray[0][0], m, n);
    // int dataArray[4][4] = {{2,0,0,2},{2,0,0,0},{2,4,2,2},{2,2,4,2}}; //to check if we're getting data in pointer or not
    // int dataArray[4][4] = {{4,8,4,2},{2,2,2,2},{2,4,2,2},{2,2,4,2}}; //to check if we're getting data in pointer or not
    // // int dataArray[4][4] = {{11,12,13,14},{15,16,17,18},{19,20,21,22},{23,24,25,26}}; //to check if we're getting data in pointer or not
    // int i,j;
    // // printData(&dataArray[0][0], m, n);
    // // makeZeroArray(&dataArray[0][0], m, n);
    // printData(&dataArray[0][0], m, n);
    // // newUp(&dataArray[0][0], m, n);
    // // part();
    // leftAndRight(&dataArray[0][0], m, n, 0);
    // part();
    // printData(&dataArray[0][0], m, n);
    // leftAndRight(&dataArray[0][0], m, n, 1);
    // part();
    // printData(&dataArray[0][0], m, n);
    // leftAndRight(&dataArray[0][0], m, n, 2);
    // part();
    // printData(&dataArray[0][0], m, n);
    // leftAndRight(&dataArray[0][0], m, n, 3);
    // part();
    // printData(&dataArray[0][0], m, n);
    
    printData(&dataArray[0][0], m, n);
    part();
    for(;;){
        int choice; //int right now because char nai avadtu
        printf("Choice?");
        scanf("%d", &choice);
        leftAndRight(&dataArray[0][0], m, n, choice);
        part();
        findZeroPlaces(&dataArray[0][0], m, n);
        printData(&dataArray[0][0], m, n);
    }

    }
