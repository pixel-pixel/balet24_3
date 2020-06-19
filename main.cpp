#include <iostream>

//void print(int** matrix, int size){
//    for(int j = 0; j < size; j++){
//        for(int i = 0; i < size; i++){
//            std::cout << matrix[i][j] << ' ';
//        }
//        std::cout << std::endl;
//    }
//}

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

//int main(){
//    const int SIZE = 4;
//
//    int** matrix = new int* [SIZE];
//
//    for(int i = 0; i < SIZE; i++){
//        matrix[i] = new int [SIZE];
//        for(int j = 0; j < SIZE; j++) matrix[i][j] = 0;
//    }
//
//    matrix[0][2] = 1;
//    matrix[0][3] = 1;
//    matrix[2][0] = 1;
//    matrix[2][3] = 1;
//    matrix[3][0] = 1;
//    matrix[3][2] = 1;
//
//    print(matrix, SIZE);
//
//    std::cout << isConnected(matrix, SIZE, 0);
//}
