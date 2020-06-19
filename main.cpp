#include <iostream>

void drawConnect(int** matrix, int size, int from){
    for(int i = 0; i < size; i++){
        if(matrix[from][i] == 1){
            matrix[from][i] = 2;
            drawConnect(matrix, size, i);
        }
    }
}
//Наша функція
bool isConnected(int** matrix, int size, int from){
    bool * arr = new bool[size];

    drawConnect(matrix, size, from);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(matrix[i][j] == 2) {
                matrix[i][j] = 1;
                arr[i] = true;
                arr[j] = true;
            }
        }
    }

    for(int i = 0; i < size; i++){
        if(!arr[i]) return false;
    }

    return true;
}
