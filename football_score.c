#include <stdio.h>

// global variables
int SCORES[] = {8, 7, 6, 3, 2};
char results[256][256];
int results_found = 0;


void print_scores(int score_counts[]){
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n",
    score_counts[0],
    score_counts[1],
    score_counts[2],
    score_counts[3],
    score_counts[4]);

}

int main(){

    int user_input;
    
    while (1) {
        // get user input
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &user_input);
        
        if (user_input <= 1){
            return 0;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", user_input);

        const int SCORES[] = {8, 7, 6, 3, 2};

        // extremely slow
        // check every permutation of 0 - userinput, five in a row.
        for (int a = 0; a < user_input; a++){
            for (int b = 0; b < user_input; b++){
                for (int c = 0; c < user_input; c++){
                    for(int d = 0; d < user_input; d++){
                        for (int e = 0; e < user_input; e++){

                            // check if it is valid
                            int sum = a * SCORES[0] + b * SCORES[1] + c * SCORES[2] + d * SCORES[3] + e * SCORES[4];
                            if (sum == user_input){
                                int score_counts[] = {a,b,c,d,e};
                                print_scores(score_counts);
                            }
                        }
                    }
                }
            }
        }

        // print newline
        printf("\n");

    } 

    
}