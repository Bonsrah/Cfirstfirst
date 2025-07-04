#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6


//Struct with word and hint
struct wordWithHint {
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};




//display current state of word
void displayWord(const char word[], const bool guessed[]);

//draw hangman 
void drawHangman(int tries);


int main(){
    srand(time(NULL)); // random time by the computer
    
    struct wordWithHint wordList[] =  {
    {"geeksforgeeks","Computer Coding"},
    {"elephant", "A large mammal with a truck"},
    {"myoa","girl of my dreams"},
    {"matrix","Movie about the real world"},
    {"shounen","Manga for boys"}
    }; // 2 dimensional array of structs
    
    // selecting a random word from words
    
    int wordIndex = rand() % 5 ; //randome index modulo
    
    const char * secretWord = wordList[wordIndex].word ;// word to reveal returns address , pointer to constant data
    const char * hint = wordList[wordIndex].hint ; // returns address 
    
    
    int wordLength = strlen(secretWord) ; //returns length of word
    char guessedWord[MAX_WORD_LENGTH] = {0}; // initializes an empty array of strings 
    bool guessedLetters[26] = {false}; // all 26 members initialised to false
    
    printf("Welcome to Hangman!\n");
    printf("Hint: %s\n", hint);
    
    int tries = 0 ;
    
    while(tries < MAX_TRIES){
        printf("\n");
        displayWord(secretWord,guessedLetters);
        drawHangman(tries);
        
        char guess;
        printf("Enter a letter:");
        scanf(" %c",&guess);
        guess = tolower(guess);
        
        
        if (guessedLetters[guess - 'a']) {
            printf("You've already guessed that letter. "
                   "Try again.\n"); // if element at position of guessed letters is true, print and , continue
            continue;
        }

        guessedLetters[guess - 'a'] = true; // if false , make true 
    
        bool found = false ;
        for (int i = 0 ; i<= wordLength; i++ ){
            if (secretWord[i] == guess){
               found = true;
               guessedWord[i] = guess;
            }
        }
        
        if(found){
            printf("Good guess!\n");
        }
        else {
            printf("Sorry, the letter '%c' is not in the "
                   "word.\n",
                   guess);
            tries++;
        }
        
        
        
        if (strcmp(secretWord, guessedWord) == 0) {  // end condition after adding all letters to guessedWord
            printf("\nCongratulations! You've guessed the "
                   "word: %s\n",
                   secretWord);
            break;
        }
 

        if (tries >= MAX_TRIES) {
        printf("\nSorry, you've run out of tries. The word "
               "was: %s\n",
               secretWord);
    }

 
        
    
    }
    
    
    
   


}


void displayWord(const char word[], const bool guessed[]){
    printf("Word:");
    for (int i = 0 ; word[i] != '\0'; i++ ){  // loop through all of word and 
        if (guessed[word[i]-'a']){ 
            printf("%c",word[i]);
        } // if true print the character at that position
        else {
            printf("_");
        }
    }
    printf("\n");
    
}

void drawHangman(int tries){
    const char * hangmanParts[] = {
        "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |"
    };
    
    printf("\n");
    for(int i =0 ; i <= tries; i++){
    printf ("%s\n", hangmanParts[i]);
    }
}

