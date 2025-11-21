
# Caesar Cipher Encryption in C

A **C program** that implements a **Caesar cipher** for text encryption and decryption. It supports uppercase and lowercase letters while preserving spaces, and provides a simple example to demonstrate encryption and decryption.

Project repository: [GitHub](https://github.com/Lushomo53/Caesar-Cipher-Encryption-C.git)

---

## Features

* Encrypts and decrypts text using a **shift of 3** (classic Caesar cipher).
* Preserves **letter case** (uppercase/lowercase).
* Preserves **whitespace** in input text.
* Validates input to ensure only alphabetical characters are processed.
* Simple demonstration of **dynamic memory allocation** and **string manipulation** in C.

---

## Files

* `main.c` – Contains the implementation of the Caesar cipher and example usage.

---

## Usage

1. **Clone the repository**:

```bash
git clone https://github.com/Lushomo53/Caesar-Cipher-Encryption-C.git
```

2. **Compile the program**:

```bash
gcc main.c -o caesar_cipher
```

3. **Run the program**:

```bash
./caesar_cipher
```

4. Example output:

```
HQFUBSWLRQ DGGV VDIWHB WR FRPPXQLFDWLRQ, ENCRYPTION ADDS SAFTEY TO COMMUNICATION
```

* The first part is the encrypted string.
* The second part is the decrypted string (matches original input).

---

## How It Works

* **`fill_letters()`** – Initializes an array of letters from `A` to `Z`.
* **`get_pos(char c)`** – Returns the alphabetical index (0–25) of a letter.
* **`cipher(const char *text, int action)`** – Performs the Caesar cipher:

  * `action = 1` → encryption
  * `action = 0` → decryption
  * Shifts letters by ±3 positions.
  * Preserves case and ignores spaces.
* **Memory management** – Dynamically allocates memory for the result string, which must be freed after use.

---

## Notes

* Only **alphabetical characters** are allowed; any non-alphabetic input will terminate the program with an error.
* The program uses **modular arithmetic** to wrap around the alphabet when shifting.
* Freeing allocated memory (`free()`) is performed after encryption and decryption to avoid memory leaks.

---

## Author

**Lushomo Lungo** – Developed as a C learning project implementing classical cryptography.
