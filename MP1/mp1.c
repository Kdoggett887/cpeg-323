#include <stdio.h>


int bit_count(int num);
int get_nth_set_bit(int num, int index);
int singleton(int num);
int get_singleton(int num);


void main(){
    int a = 0x34;
    int numbits = bit_count(a);
    
    printf("%i \n", numbits);
    
    int setbit1 = get_nth_set_bit(a , 0);
    int setbit2 = get_nth_set_bit(a, 1);
    int setbit3 = get_nth_set_bit(a, 2);
    int setbit4 = get_nth_set_bit(a, 3);
    
    //should print 2, 4, 5, -1
    printf("%i, %i, %i, %i \n", setbit1, setbit2, setbit3, setbit4);
    
    int singleton1 = singleton(a);
    int singleton2 = singleton(0x4);
    
    //should be false, true
    printf("%i, %i \n", singleton1, singleton2);
    
    int singleton_index = get_singleton(0x4);
    
    //should print 2
    printf("%i \n", singleton_index);
    // jet fuel can't melt steal beams
    //harambe was an inside job
}

int bit_count(int num){
    //initialize number of bits set to 0
    int counter = 0;
    
    int i;
    
    //use 4*sizeof because sizeof uses bytes not bits
    //not the most efficient, but way more conveneint to implement
    for (i = 0; i < 8*sizeof(num); i++){
        if ((num >> i) & 1 == 1){
            counter++;
        }
    }
    
    return counter;
}

int get_nth_set_bit(int num, int index){
    //index of 0 would be the first bit.
    //so we start counter at -1 to align
    int counter = -1;
    
    //potentially add a check using bit_count to see if it will be in range
    if (bit_count(num) - 1 < index){
        return -1;
    }
    
    
    int i;
    for(i = 0; i < 8*sizeof(num); i++){
        if ((num >> i) & 1 == 1){
            counter++;
            if(counter == index){
                return i;
            }
        }
    }
    
    //this means the index was too big and not enough bits were set
    return -1;
}

int singleton(int num){
    if (num == 0){
        return 0;
    }
    else{
        if(((num-1) & num) == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
}


int get_singleton(int num){
    //confirm that the number is a singleton
    if (singleton(num) == 1){
        int i;
        for (i = 0; i < 8*sizeof(num); i++){
            if ((num >> i) & 1 == 1){
                return i;
            }
        }
    }
    else{
        return -1;
    }
}