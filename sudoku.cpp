#include <stdio.h>

int sudoku[9][9];

bool msmColuna(int x, int y, int num) {

    for (int i = 0; i < 9; i++) {
        if (sudoku[x][i] == num) {
            return true;
        }
    }

    return false;
}

bool msmFileira(int x, int y, int num) {

    for (int i = 0; i < 9; i++) {
        if (sudoku[i][y] == num) {
            return true;
        }
    }

    return false;
}
bool msmSubmatriz(int x, int y, int num) {

    if (x < 3) {
        x = 0;
    } else if (x < 6) {
        x = 3;
    } else {
        x = 6;
    }

    if (y < 3) {
        y = 0;
    } else if (y < 6) {
        y = 3;
    } else {
        y = 6;
    }

    for (int i = x; i < x+3; i++) {
        for (int j = y; j < y+3; j++) {
            if (sudoku[i][j] == num) {
                return true;
            }
        }
    }

    return false;
}

bool isPlaceable(int x, int y, int i){
    if(msmColuna(x, y, i) || msmFileira(x, y, i) || msmSubmatriz(x, y, i)){
        return false;
    }
    return true;
}

bool resolveSudoku(int x, int y){

    if(y > 8){
        return true;
    }

    if(sudoku[x][y] == 0){
        for(int i = 1; i < 10; i++){
            if(isPlaceable(x , y, i)){
                sudoku[x][y] = i;
                int tx = x + 1;
                int ty = y;
                if(tx > 8){
                    tx = 0;
                    ty++;
                }
                if(resolveSudoku(tx, ty)){
                    return true;
                }
            }
        }
        sudoku[x][y] = 0;
        return false;
    }
    if(sudoku[x][y] != 0){
        x++;
        if(x > 8){
            x = 0;
            y++;
        }
        return resolveSudoku(x, y);
    }
}

int main(){
    bool verifica;
    int n;
    scanf("%d", &n);
    while(n > 0){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &sudoku[i][j]);
            }
        }

        verifica = resolveSudoku(0, 0);

        if(verifica == false){
            puts("No solution");
        }
        else{
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                printf("%d ", sudoku[i][j]);
                }
                printf("\n");
            }
        }
    n--;
    }
    return 0;
}

