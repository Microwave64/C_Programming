#include <stdio.h>
#include <stdlib.h>

int path_detector(char **pointer_arr, int current_row, int current_column, int column_size, int row_size);

char left(char **pointer_arr,int row, int column){
    return pointer_arr[row][column - 1];
}

char right(char **pointer_arr, int row, int column){
    return pointer_arr[row][column + 1];
}

char up(char **pointer_arr, int row, int column){
    return pointer_arr[row - 1][column];
}

char down(char **pointer_arr, int row, int column){
    return pointer_arr[row + 1][column];
}

int unprinted = 1;


int main() {

    /* TODO: Implement here */
    
    
    int i, j, init_row, init_column, len_flag = 1, column_index = 1, row_size = 0, column_size = 1;
    char ch, **pointer_arr, *column_arr;

    scanf("%d ", &init_column);
    scanf("%d ", &init_row);

   
    
    pointer_arr = (char **) malloc(sizeof(char*) * 1);
    while ((ch = getchar()) != EOF){
        if (ch == '\n'){
            /* Getting rid of the \n in starting coordinates */
            continue;
        }
        row_size++;
        pointer_arr = (char **) realloc(pointer_arr, sizeof(char*) * row_size);
        pointer_arr[row_size-1] = (char *) malloc(sizeof(char) * column_size);
        pointer_arr[row_size-1][0] = ch;
        while ((ch = getchar()) != '\n' && ch != EOF){
            if (len_flag){
                pointer_arr[row_size-1] = (char *) realloc(pointer_arr[row_size-1], sizeof(char) * (column_index+1));
                column_size = column_index + 1;
            }
            pointer_arr[row_size - 1][column_index] = ch;
            column_index++;
        }
        
        column_index = 1;
        len_flag = 0;

    }


    path_detector(pointer_arr, init_row, init_column, column_size, row_size);

    if (unprinted){
        for(i = 0; i < row_size; i++){
            for (j = 0; j < column_size; j++){
                printf("%c", pointer_arr[i][j]);
            }
            printf("\n");
        }    
    }

    for(i = 0; i < row_size; i++){
        free(pointer_arr[i]);
    }
    free(pointer_arr);
    
    
    return 0;
}






int path_detector(char **pointer_arr, int current_row, int current_column, int column_size, int row_size){
    int i = 0, j = 0;
    
    if ((current_column >=  column_size-1) ||(current_column <= 0)|| (current_row >= row_size-1) || (current_row <= 0)){
        if (unprinted){
            unprinted = 0;
            pointer_arr[current_row][current_column] = '*';
            for(i = 0; i < row_size; i++){
                for (j = 0; j < column_size; j++){
                    if (pointer_arr[i][j] == '.'){
                        printf(" ");
                    }
                    else{
                        printf("%c", pointer_arr[i][j]);
                    }
                }
                printf("\n");
            }    
        }       
    }
    else if(unprinted){
        if(unprinted && (left(pointer_arr, current_row, current_column) != 'X') && (left(pointer_arr, current_row, current_column) != '.') && (left(pointer_arr, current_row, current_column) != '*')){
            pointer_arr[current_row][current_column] = '*';
            path_detector(pointer_arr, current_row, current_column - 1, column_size, row_size);
        }
        if(unprinted && (up(pointer_arr, current_row, current_column) != 'X') && (up(pointer_arr, current_row, current_column) != '.') && (up(pointer_arr, current_row, current_column) != '*')){
            pointer_arr[current_row][current_column] = '*';
            path_detector(pointer_arr, current_row - 1, current_column, column_size, row_size);
        }
        if(unprinted && (right(pointer_arr, current_row, current_column) != 'X') && (right(pointer_arr, current_row, current_column) != '.') && (right(pointer_arr, current_row, current_column) != '*')){
            pointer_arr[current_row][current_column] = '*';
            path_detector(pointer_arr, current_row, current_column + 1, column_size, row_size);
        }
        if(unprinted && (down(pointer_arr, current_row, current_column) != 'X') && (down(pointer_arr, current_row, current_column) != '.') && (down(pointer_arr, current_row, current_column) != '*')){
            pointer_arr[current_row][current_column] = '*';
            path_detector(pointer_arr, current_row + 1, current_column, column_size, row_size);
        }
          
        pointer_arr[current_row][current_column] = '.';
        

    }


    return 0;
}
