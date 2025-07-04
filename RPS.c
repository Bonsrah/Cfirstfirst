//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>


#define ROCK_THRESHOLD 33
#define PAPER_THRESHOLD 66

int game (char me, char computer){
    int decisions[3][3] = {
    {-1,1,0},
    {0,-1,1},
    {1,0,-1}};
    int me_ind = (me == 's')? 0: (me == 'p')? 1 : 2;
    int comp_ind = (computer == 's')? 0: (computer == 'p')? 1 : 2;
    return decisions[me_ind][comp_ind]; // pick from the matrix of return values
    
}

int main () {
    char me , computer , playAgain;
    int wins = 0 , losses = 0 , draws = 0  ;
    srand(time(NULL));
 
    do {
    
    // computurs choice 
        
        int n = rand() % 100;
        char computer = (n <= ROCK_THRESHOLD)? 's' : (n<= PAPER_THRESHOLD)? 'p' : 'z';
        
        do {
        //players choice
            printf("\t\t\t\t\t\t\t\tWelcome! Are you ready for some Rock , Paper , Scissors?!!\t\t\t\t\t\t\t\t\n");
             printf ("\t\t\t\t\t\t\t\t\t\t\tplease input one of the options : \n \t\t\t\t\t\t\t\t\t\t\t s for Rock \n \t\t\t\t\t\t\t\t\t\t\t p for paper \n \t\t\t\t\t\t\t\t\t\t\t z for scissors\t\t\t\t\t\t\t\t\t\t\t\t\n");
            scanf(" %c",&me);
            
            me = tolower(me) ;//make all input lowercase
        } while (me != 's' && me !='p' && me != 'z');
        
        
        printf("Computer's turn ....\t\t");
        fflush(stdout); // delay computer's response
        sleep(1);
        printf("%c!\n", computer);
   
    
        int result = game(me , computer);
    
        if (result == 0){
            printf("Well done!, you beat me\n");
            wins++;
        }
        else if (result == 1){
            printf("hahaha , better luck next time\n");
            losses++;
    }
        else if (result == -1){
            printf("Draw!, great minds\n");
            draws++;
    }
        else{
            printf ("Oop, not an option! Try again\n");
    }
    
        
        printf("Score: W-%d L-%d D-%d\n", wins, losses, draws);
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    
    }while ( tolower(playAgain)=='y');
    
}





