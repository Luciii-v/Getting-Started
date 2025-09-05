#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Array to store point values for each letter
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function to compute a word's score
int compute_score(char *word) {
    int score = 0;
    // Iterate through each character in the string
    for (int i = 0; word[i] != '\0'; i++) {
        char c = word[i];
        if (islower(c)) {
            score += POINTS[c - 'a'];
        } else if (isupper(c)) {
            score += POINTS[c - 'A'];
        }
    }
    return score;
}

int main(void) {
    char word1[50];
    char word2[50];
    
    // Get input for Player 1
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0'; // Remove the newline character
    
    // Get input for Player 2
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0'; // Remove the newline character

    // Compute scores for both players
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine and print the winner
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}