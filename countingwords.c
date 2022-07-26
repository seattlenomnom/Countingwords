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
 * 08/01/2022 countingwords is "finished" as the example program.
 * Next is problem 2 on page 230. I wants to fix two problems. How do I
 * approach this with git and github. Use local git to fix the problems, then
 * push to origin.
 *
 * Problem 1: lamb's is two words.
 * Solution 1: in isAlphabetic added || (c== '\'').
 *
 * problem 2: handling numbers (and their commas and periods)
 * solution2: modded isalphabetic to look for special characters. added
 * isspecialchar function. isspecialchar function looks for numbers(and ass-
 * ociated commas and periods), and single apostrophes. next might implement
 * isspecial character with a switch to clean upt the logic. if i do that, i
 * should creat a git branch to experiment then merge the branch to main.
 *
*/


#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isAlphabetic(const char c);
int countwords(const char buffer[]);
bool isSpecialChar(const char c);
bool isNumber(const char c);

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
    buffer[i] = '\0';

    number_of_words = countwords(buffer);

    printf("\nword count - %i\n", number_of_words);

    return(0);
}

bool isAlphabetic(const char c) {

    bool isAlpha;

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || isSpecialChar(c))
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


bool isSpecialChar(const char c) {


    bool isSpecial;


    if((c == '\'') || (isNumber(c)) || (c == '.') || (c == ','))
        isSpecial = true;
    else
        isSpecial = false;


    return(isSpecial);
}


bool isNumber(const char c) {

    bool number;

    if(isdigit(c) != 0)
        number = true;
    else
        number = false;

    return(number);
}
