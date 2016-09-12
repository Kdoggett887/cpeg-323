#include <stdio.h>

//helper function to convert int to binary readout
void print_bin(unsigned int x){
    printf("%i \n", x);
}


//handles the inversion logic
void invert(unsigned int x, int p, int n){
    //generate number that needs to be xor'd with x
    //start building a binary number at position p
    unsigned int inverter = 0;
    
    //if n = 0, no bits are converted
    if (n > 0){
        //where to start building the number
        int workingBit = n + p - 1;
        while(workingBit >= p){
            //define the exponent and what we will be adding to the inverter
            int exponent = workingBit;
            unsigned int addition = 1;
            

            while(exponent > 0){
                addition = addition*2;    
                exponent -= 1;
                unsigned short test = exponent > 0;
            }
        
            //add the new binary digit to inverter
            inverter += addition;
            
            //move to the next right bit
            workingBit -= 1;
        }
        
        unsigned int invertedNum = x ^ inverter;
        
        print_bin(invertedNum);
    }
}


int main(){
    unsigned int var = 0b1111;
    
    //works
    invert(var, 2, 1);
    
    unsigned int var2 = 0b1111;
    
    invert(var2, 2, 2);
    
    unsigned int var3 = 0b0000;
    
    invert(var3, 1, 3);
    
    invert(var3, 0, 2);
    
    //all works
    invert(var, 0, 2);
    
    return 0;
}