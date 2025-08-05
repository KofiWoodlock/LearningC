/*
Interactive quiz game key terms & code
- toupper
    - A function that takes an alphabetic char as input converts it to upper case
*/

#include <stdio.h>
#include <ctype.h>

int main() {

    // Main game 

    char questions[][80] = {"What is the capital of France?\n",
                            "What is the largest planet in the solar system?\n",
                            "What is the name of the first US president?\n",
                            "Who painted the Mona Lisa?\n"};

    char choices[][80] = {"A. London\nB. Brussels\nC. Paris\nD. New York",
                          "A. Neptune\nB. Jupiter\nC. Mars\nD. Saturn",
                          "A. George Bush\nB. Donald Trump\nC. John F Kennedy\nD. George Washington",
                          "A. Leonardo da Vinci\nB. Vincent van Gogh\nC. Pablo Picasso\nD. Michelangelo"};
                          
    char answers[] = {'C', 'B', 'D', 'A'};

    int num_of_questions = sizeof(questions) / sizeof(questions[0]);

    char guess = '\0';
    int score = 0;
    int i = 0;

    printf("#### Quiz Game! ####\n");
    while (i < num_of_questions) {
        printf("%s", questions[i]);
        printf("%s", choices[i]);
        printf("\nPlease enter an answer: ");
        scanf(" %c", &guess);
        
        if (toupper(guess) == answers[i]) {
            printf("Correct!\n");
            score++;
            i++;
        } else {
            printf("Incorrect!\n");
            i++;
        }
    }

    printf("\n");
    printf("Quiz over\n");
    printf("Your score was: %d", score);

    return 0;
}