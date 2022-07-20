/* countingwords.c
 * sourcefile for countingwords, a program that can take charcter input from
 * the console or a pipe and count the number of words that it contains. Maybe
 * add an histogram of word length.
 *
 * An example program from Kochan, Stephen G., "Programming in C 3rd ed.",
 * Sams Publishing.
 *
 * Programmer: Mark Crapser
 *
*/


#include <stdio.h>
#include <stdbool.h>

bool isAlphabetic(const char c);
int countwords(const char buffer[]);

int main(int argc, char *argv[]) {

    char buffer[801], c;
    int i, number_of_words;

    for(i = 0; i <= 800; ++i)
        buffer[i] = '\b';

    buffer[800] = '\0';
    i = 0;
    number_of_words = 0;





    /* get the text into buffer */
    while(((c = getchar()) != EOF) && i <= 799) {
        buffer[i] = c;
        ++i;
    }

    number_of_words = countwords(buffer);

    printf("word count - &i\n", number_of_words);

    return(0);
}

bool isAlphabetic(const char c) {

    bool isAlpha;

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        isAlpha = true;
    else
        isAlpha = false;

    return(isAlpha);
}

int countwords(const char string[]) {

    int i, wordcount;
    bool looking_for_word;

    i = 0;
    wordcount = 0;
    looking_for_word = true;

    for(i = 0; string[i] != '\0'; ++i)
        if(isAlphabetic(string[i])) {
            if(looking_for_word) {
                ++wordcount;
                looking_for_word = false;
            }
        }
        else
            looking_for_word = true;

    return(wordcount);
}
