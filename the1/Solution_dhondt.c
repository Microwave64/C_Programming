#include <stdio.h>

int main() {
    
    /* TODO: Implement here */
    int i, j, N, M, max_deputy, max_deputy_index = 0, deputy_index = 0;
    double max_ratio = 0, ratio, vote, divisor;
    int Votes_of_parties[26], Deputy_of_parties[26];

    scanf("%d %d", &N, &M);
    
    for(i = 0; i < N; i++)
    {
        scanf("%d",&Votes_of_parties[i]);
        Deputy_of_parties[i] = 0;
    }

    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            vote = Votes_of_parties[j];
            divisor = (Deputy_of_parties[j]+1);
            ratio = vote / divisor;
            if  (ratio > max_ratio)
            {
                deputy_index = j;
                max_ratio = ratio;
            }

            else if  ((ratio == max_ratio) && (Votes_of_parties[j] > Votes_of_parties[deputy_index]))
            {
                
                deputy_index = j;
                max_ratio = ratio;
            }
        
        }   
    Deputy_of_parties[deputy_index] += 1;
    max_ratio = 0;
    }


    max_deputy = Deputy_of_parties[0];
    
    i = 0;
    while (i < N) 
    {
        for(j = 0; j < N; j++)
        {
            if (max_deputy < Deputy_of_parties[j])
            {
                max_deputy_index = j;
                max_deputy = Deputy_of_parties[j]; 
            }
        }
        if (max_deputy == 0) 
            break;
        else
        {
            printf("%c: %d\n", 65 + max_deputy_index, max_deputy);
            Deputy_of_parties[max_deputy_index] = 0;
            max_deputy_index = 0;
            max_deputy = Deputy_of_parties[0];
        }
        i++;
    }
    
    return 0;
}
