#include <stdio.h>
#include <stdlib.h> //For pseudo random numbers

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-i; ++j) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

//Example of using function
int main() {
    int array_example[25];

    for (int i = 0; i < 25; ++i)
        array_example[i] = rand()%100;
    //Numbers are always the same but it's okay for showing purpose

    bubble_sort(array_example, 25);

    for (int i = 0; i < 25; ++i)
        printf("%d ", array_example[i]);

    return 0;
}

