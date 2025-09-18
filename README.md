# Ceaser Cipher in C

This program implements a simple **Ceasar cipher** in C.
It encrypts and decrypts messages with a fixed shift (currently 3)
and preserves letter case while ignoring whitespaces.

## Features

- Encypts andd decrypts text with a fixed shift.
- Preserves uppercase and lowercase letters.
- Ignores whitespaces during encryption/decryption.
- Checks for non-alphabetical characters and exits gracefully with an error message.
- Demonstrates memory management in c ('malloc' and 'free').

## File Structure

encryption/          <- Root project folder 
├── src/                <- Source code folder 
│   └── main.c          <- Main C program implementing the Caesar cipher 
├── README.md           <- Project documentation 
└── .gitignore          <- Git ignore file for compiled/binary files


## Compilation

Compile the program using `gcc`:

```bash
gcc -o cipher src/main.c
```
This will generate an executable called cipher

##Usage

Run the program on a termial: 

./cipher

The program encrypts a predefined message then decrypts it

Example output:

Original text: Encryption adds safety to communication

Encrypted: Hqfubswlrq dggv vdiwhb wr frppxqlfdwlrq
Decrypted: Encryption adds safety to communication

## Sample Usage in C

    char text[] = "Encryption adds saftey to communication";

    char *encstr = cipher(text, ENCRYPT);
    char *decstr = cipher(encstr, DECRYPT);

    printf("%s, %s\n", encstr, decstr);
    //free allocated memory
    free(encstr);
    free(decstr);

## Notes
- The shift is currently hard-coded to 3, but the code can be modiffied for variable shifts
- Memory allocated by cipher() must be freed by the caller to avoid memory leaks.
- Non-alphabetical characters will cause the program to exit with an error.

## License

This project is open-source under the **MIT License**


