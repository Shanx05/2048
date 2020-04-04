#include <iostream> 
#include <stdlib.h>
#include <random>
#include <ctime>
#include <chrono>

namespace randGen {
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int generateRandomNumber(int min, int max){

    std::uniform_int_distribution<> gen{min, max};
    int slot_one = gen(randGen::mersenne);
    if(slot_one == 3){
        slot_one--; 
    }
    return slot_one; 
}

int printscreen(int *p){
    std::cout<<"\n======================================================\n";
    std::cout<<*p<<"\t\t\t"<<*(p+1)<<"\t\t\t"<<*(p+2); 
    std::cout<<"\n======================================================\n";
    std::cout<<*(p+3)<<"\t\t\t"<<*(p+4)<<"\t\t\t"<<*(p+5); 
    std::cout<<"\n======================================================\n";
    std::cout<<*(p+6)<<"\t\t\t"<<*(p+7)<<"\t\t\t"<<*(p+8); 
    std::cout<<"\n======================================================\n\n\n";
    return 0; 
}

/*
int leftwards(uint arr[3][3], int temp[3]){
    std::cout<<"entered leftwards"; 
    int temp0 = 0, temp1 = 0, temp2 = 0;
    uint *p = &arr[0][0]; 

    for(int i = 0; i < 3; i++){
                for(int j = 0; j < 1; j++){
                    arr[i][j] = temp[i] + arr[i][j+1] + arr[i][j+2]; 
                }
                temp[i] = arr[i][0]; 
            }
            arr[2][2] = generateRandomNumber(2, 4); 
            //printscreen(p); 
}
*/

int leftPush(int *p){
    for(int i = 0; i <= 6; ){
        
        if(*(p+i) == 0){
            if(*(p+i+1) == *(p+i+2)){
                *(p+i) = *(p+i+1) + *(p+i+2);
                *(p+i+1) = 0;
                *(p+i+2) = 0; 
            }else if((*(p+i+1) != *(p+i+2))){
                *(p+i) = *(p+i+1);
                *(p+i+1) = *(p+i+2); 
            }
        }else if(*(p+i) != 0){
            if(*(p+i) == *(p+i+1)){
                *(p+i) = *(p+i) + *(p+i+1); 
                *(p+i+1) = *(p+i+2);
                *(p+i+2) = 0;  
            }else if (*(p+i+1) == *(p+i+2)){
                *(p+i+1) = *(p+i+1) + *(p+i+2); 
                *(p+i+2) = 0; 
            }else if ((*(p+i+1) == 0) && (*(p+i) == *(p+i+2))){
                *(p+i) = *(p+i) + *(p+i+2); 
            }else if ((*(p+i+1) == 0) && (*(p+i) != *(p+i+2))){
                *(p+i+1) = *(p+i+2);
                *(p+i+2) = 0;  
            }
        }
        i = i + 3; 
    }
    
    *(p+8) = generateRandomNumber(2,4); 
    printscreen(p); 
}

int main(){
    int temp0 = 0, temp1 = 0, temp2 = 0;
    int temp[3]{}; 
    static int arr[3][3]{{},{},{0,2,2}};
    int *p = &arr[0][0]; 
    //*(p+2) = 3; 
   // *(p+5) = generateRandomNumber(2,4); 
    *(p+8) = generateRandomNumber(2,4); 
    std::cout<<*(p+1);  
    printscreen(p);    
    char input; 
    while(1){
        std::cin>>input;
          
        switch (input)
        {
        case 2:     //leftwards(arr[3][3], temp[3]); 
                    
        case '4':   leftPush(p);  
                    break; 

        default: std::cout<<"Invalid option\n"; 

        }

    }
}