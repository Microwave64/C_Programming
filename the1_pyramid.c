#include <stdio.h>

double calculate_pressure_on_block(int row, int column, double block_weight);

double helper(int row, int column, double block_weight);





double caller(int row, int column, double block_weight, int row_index)
{
    double repress;
    if (row_index < row)
    {
        if (row_index < column)
        {
            column = 0;
            row_index++;
        }
        if (row_index < row)
        {
        repress = helper(row_index, column, block_weight);
        printf("(%d,%d) %.8lf\n", row_index, column, repress);
        caller(row, column + 1, block_weight, row_index);
        }
    }
    return 0;
}





int main(){
    
    /* TODO: Implement here */
    double weight;
    int row;
    scanf("%d %lf", &row, &weight);

    calculate_pressure_on_block(row, 0, weight);

    return 0;
}




double calculate_pressure_on_block(int row, int column, double block_weight){
    
    caller(row,  column,  block_weight, -1);
    return 0;
    
}    





double helper(int row, int column, double block_weight){    
    if (row == 0 && column == 0){  
        return 0; 
    }

    else if (column == 0){
        return helper(row - 1, column, block_weight) * 0.15 + (block_weight/2);
    }
 
    else if (column == row){
        return helper(row - 1, column - 1, block_weight) * 0.15 + (block_weight/2);
    }
 
    else{
        return (helper(row - 1, column - 1, block_weight) * 0.15 + (block_weight/2)) + ((block_weight/2) + 0.15 * helper(row - 1, column, block_weight));
    }

}



