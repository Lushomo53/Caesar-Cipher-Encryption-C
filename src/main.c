#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_SIZE 26
#define ENCRYPT 1
#define DECRYPT 0

char letters[ALPHA_SIZE];

void fill_letters() {
    //fill letters array with letters from A to Z
    for (int c = 'A', i = 0; c <= 'Z' && i < ALPHA_SIZE; c++, i++) {
        letters[i] = c;
    }
}

int get_pos(char c) {
    //get the index position of letter in alphabet
    return c - 'A';
}

char *cipher(const char *text, int action) {
    //returns either encrypted or decrypted text based on conditon 'action'
    char *encstr = (char *) malloc(sizeof(char) * (strlen(text)+ 1));

    if (!encstr) {
        fprintf(stderr, "Error occured during memory allocation to encstr\n");
        exit(EXIT_FAILURE);
    }

    int i;
    size_t len = strlen(text);
    for (i = 0; i < len; i++) {
        //convert to uppercase if needed
        char c = isupper(text[i]) ? text[i] : toupper(text[i]);

        if (isspace(c)) { //no need to decrypt/encrypt white spaces
            encstr[i] = c;
            continue;
        }

        if (!isalpha(c)) {  //check if input is valid
            fprintf(stderr, "Cannot encrypt/decrypt non alphabetical characters\n");
            exit(EXIT_FAILURE);
        }

        int npos = get_pos(c);
        //map character between shifted alphabets
        int shift = (action ? npos + 3 : npos - 3) % ALPHA_SIZE;

        if (shift < 0) {
            shift += ALPHA_SIZE; //wrap around
        }
        char encchar = letters[shift];
        encstr[i] = isupper(text[i]) ? encchar : tolower(encchar); //preserve shift
    }

    encstr[i] = '\0'; //add delimetre
    return encstr;
}

int main() {
    fill_letters();
    char text[] = "Encryption adds saftey to communication";

    char *encstr = cipher(text, ENCRYPT);
    char *decstr = cipher(encstr, DECRYPT);

    printf("%s, %s\n", encstr, decstr);
    //free allocated memory
    free(encstr);
    free(decstr);
    return 0;
}

