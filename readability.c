#include <stdio.h>    // For printf, fgets, stdin
#include <string.h>   // For strlen, strcspn
#include <ctype.h>    // For isalpha
#include <math.h>     // For round

// Function prototypes
int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);

int main(void)
{
    // Create a buffer to store the user's text
    char text[1024];

    // Prompt the user for input and read the text
    printf("Text: ");
    if (fgets(text, sizeof(text), stdin))
    {
        // Remove the newline character that fgets() adds at the end
        text[strcspn(text, "\n")] = '\0';
    }

    // Count the letters, words, and sentences
    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // Calculate L (average letters per 100 words) and S (average sentences per 100 words)
    float L = (float) letter_count / word_count * 100.0;
    float S = (float) sentence_count / word_count * 100.0;

    // Apply the Coleman-Liau formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round the result to the nearest integer to get the grade level
    int grade = round(index);

    // Print the final grade based on the rules
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

/**
 * Counts the number of alphabetic characters in a string.
 */
int count_letters(char *text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

/**
 * Counts the number of words in a string, assuming words are separated by single spaces.
 */
int count_words(char *text)
{
    int count = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

/**
 * Counts the number of sentences, identified by periods, exclamation marks, or question marks.
 */
int count_sentences(char *text)
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}