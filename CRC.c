#include <stdio.h>
#include <stdlib.h>

#define NumberBits 32

void CRCcalcul(unsigned char *trame, int NumberOfBits, unsigned char *inputData){
    unsigned char CRC[NumberOfBits];
    unsigned char POLY[NumberOfBits];
    POLY[0] = 1;
    POLY[1] = 1;
    for(int i = 2; i < NumberOfBits; i ++){ // à vérifier car peut-etre on n'aura pas besoin de faire ceci
        if(rand() % 2 == 0){
            POLY[i] = 1;
        }else{
            POLY[i] = 0;
        }
    }
    for(int i = 0; i < NumberOfBits ; i ++){
        CRC[i] = 1;
    }
    int zeroflag = 1;
    int operationflag = 0;
    for(int j = 0; j < NumberBits; j++){
        CRC[j] = CRC[j] ^ inputData[j];
    }
    for (int i = 0; i < NumberBits ; ){
        while(CRC[0] == 0){
            for(int j = 0; j < NumberBits - 1 ; j++){
                CRC[j] = CRC[j + 1];

            }
            CRC[NumberBits - 1] = 0;
            zeroflag = 1;
            operationflag = 0;
            i++;
        }
        if(CRC[0] == 1 && zeroflag == 1){
            zeroflag = 0;
            for(int j = 0; j < NumberBits - 1 ; j++){
                CRC[j] = CRC[j + 1];

            }
            CRC[NumberBits - 1] = 0;
            i++;
        }
        for(int j = 0; j < NumberBits; j++){
            CRC[j] = CRC[j] ^ POLY[j];
        }
    }
    for(int i = 0; i < NumberOfBits; i ++){
        trame[i] = CRC[i];
    }

}

int main(){

    unsigned char CRC[NumberBits];
    unsigned char inputData[NumberBits] = {1,0,0,0,0,0,1,1,1,0,1,0,1,0,1,0, 1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0};
    CRCcalcul(&CRC[0], NumberBits, &inputData[0]);


    for(int i = 0; i < NumberBits ; i++){
        printf("%d", CRC[i]);
    }

    return 0;
}
