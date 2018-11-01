#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
    int mat[10][10];
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            cin >> mat[i][j];
        }
    }
    //Troca linha 2 com a 8
    for(int i = 0; i < 10; ++i){
        int aux = mat[1][i];
        mat[1][i] = mat[7][i];
        mat[7][i] = aux;
    }
    //Troca coluna 4 com a 10
    for(int i = 0; i < 10; ++i){
        int aux = mat[i][3];
        mat[i][3] = mat[i][9];
        mat[i][9] = aux;
    }
    cout << "1." << endl;
    return 0;
}