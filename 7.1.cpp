#include <stdio.h>


const int array_size = 5;


void print_array(int *array){
    for (int i = 0; i < array_size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int move, help, index;
    int array[array_size] = {2, 11, 13, 15, 17};
    int copy_array[array_size];
    print_array(array);
    move = array[0];
    if (array[0] > array_size){
        move = array[0] % array_size;
    }
    if (array[0] % 2 != 0){
        for (int c = 0; c < array_size; c++){
            index = array_size+c-move;
            if (index >= array_size){
                index = c-move;
            }
            copy_array[index] = array[c];
        }
    }
    else{
        for (int c = 0; c < array_size; c++){
            index = c+move;
            if (index >= array_size){
                index = c+move-array_size;
            }
            copy_array[index] = array[c];
        }
    }
    print_array(copy_array);
}
