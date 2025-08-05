/*
Interactive quiz game key terms & code
*/

#include <stdio.h>

int main() {

    // Main game 

    char questions[][80] = {"What is the capital of France?",
                            "What is the largest planet in the solar system?",
                            "What is the name of the first US president?",
                            "Who painted the Mona Lisa?"};

    char choices[][80] = {"A. London\nB. Brussels\nC. Paris\nD. New York",
                          "A. Neptune\nB. Jupiter\nC. Mars\nD. Saturn",
                          "A. George Bush\nB. Donald Trump\nC. John F Kennedy\nD. George Washington",
                          "A. Leonardo da Vinci\nB. Vincent van Gogh\nC. Pablo Picasso\nD. Michelangelo"};
                          
    char answers[] = {'C', 'B', 'D', 'A'};

    int num_of_questions = sizeof(questions) / sizeof(questions[0]);

    char guess = '\0';
    int score = 0;
    int i = 0;

    printf("#### Quiz Game! ####");
    while (i <= num_of_questions) {
        printf("%s", questions[i]);
        pritnf("%s", choices[i]);
        printf("Please enter an answer: ");
        scanf("%c", &guess);
        
        if (guess == answers[i]) {
            printf("Correct!");
            score++;
            i++;
        } else {
            prinf("Incorrect! Try again.");
        }
    }

    printf("Quiz over");
    printf("Your score was: %d", score);

    return 0;
}