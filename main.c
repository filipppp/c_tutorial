#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "math.h"

// Initializing Structs
typedef struct Buecher {
    char  titel[50];
    char  autor[50];
    char  genre[100];
    int   buchID;
} Buch;


// Initializing Unions
union Data {
    int i;
    char string[40];
    double nummer;
};

void passPointer(int *passByReference) {
    printf("%d \n", *passByReference);
}

void printArray(int array[], unsigned int length) {
    for (int i = 0; i < length; i++) {
        printf("%d \n", array[i]);
    }
}

void bubbleSort(int array[], unsigned int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if(array[j] > array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printString(char string[]) {
    printf("%s", string);
}

int main() {

    // ez pointer
    int var = 1;
    int *pointerToVar = &var;
    printf("%d \n", *pointerToVar);
    passPointer(pointerToVar);
    passPointer(&var);


    // Variable Save in Register
    register unsigned long long int kek = 10000000000000000;
    printf("%lld \n \n", kek);


    // Initialize Array
    int coolesArray[] = {200, 331, -1, 2, -10, 2, 40, 39, 40, 12, -300, 99, 100};


    // Bubble Sort call
    unsigned int coolLength = sizeof(coolesArray) / sizeof(int);
    bubbleSort(coolesArray, coolLength);


    Buch buch1 = {
            .titel = "Cooler Titel",
            .autor = 2,
            .genre = "Roman xD",
            .buchID = 10
    };
    Buch buch3[] = {buch1};
    printf("%s \n", buch1.genre);


    union Data mehreArtenAnDaten;
    strncpy(mehreArtenAnDaten.string, "Hey", 4);
    printf("%s \n", mehreArtenAnDaten.string);


    // read and write files

    FILE *fp = fopen("/home/filip/Projekte/c/resources/input.txt", "r");
    if(fp == NULL) {
        perror("Error opening given file");
    }
    char input[100];
    fgets(input, sizeof(input), fp);

    fclose(fp);
    printString(input);



    // Own Math Library
    printf("%f", multiply())


    return 0;
}




