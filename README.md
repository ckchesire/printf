# 0x11. C - printf Team Project

Welcome to the 0x11. C - printf team project! This project involves creating a custom implementation of the `printf` function in C. Below are the tasks and requirements for the project.

## Tasks

### 0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
Write a function that produces output according to a format.
- '%c': character
- '%s': string
- '%%': percent sign

### 1. Education is when you read the fine print. Experience is what you get if you don't
Handle the following conversion specifiers:
- `%d` and `%i`: signed integer

### 2. With a face like mine, I do better in print
Handle the following custom conversion specifiers:
- `%b': binary

### 3. What one has not experienced, one will never understand in print
Handle the following conversion specifiers:
- `%u`: unsigned integer
- `%o`: unsigned octal
- `%x`: unsigned hexadecimal (lowercase)
- `%X`: unsigned hexadecimal (uppercase)

### 4. Nothing in fine print is ever good news
Use a local buffer of 1024 chars in order to call `write` as little as possible.

### 5. My weakness is wearing too much leopard print
Handle the following custom conversion specifier:
- `%S`: string with non-printable characters (prints this as `\x`, followed by the ASCII code value in hexadecimal of the character).

### 6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print
Handle the following conversion specifier:
- `%p`: pointer address

### 7. The big print gives and the small print takes away
Handle the following flag characters for non-custom conversion specifiers:
- `+`: forces to precede the result with a plus or minus sign (+ or -) even for positive numbers
- ` ` (space): if no sign is going to be written, a blank space is inserted before the value

### 8. Sarcasm is lost in print
Handle the following length modifiers for non-custom conversion specifiers:
- `l`: long
- `h`: short

Conversion specifiers to handle:
- `%d`, `%i`: signed integer
- `%u`: unsigned integer
- `%o`: unsigned octal
- `%x`, `%X`: unsigned hexadecimal

### 9. Print some money and give it to us for the rain forests
Handle the field width for non-custom conversion specifiers.

### 10. The negative is the equivalent of the composer's score, and the print the performance
Handle the precision for non-custom conversion specifiers.

### 11. It's depressing when you're still around and your albums are out of print
Handle the `0` flag character for non-custom conversion specifiers.

### 12. Every time that I wanted to give up, if I saw an interesting textile, print whatever, suddenly I would see a collection
Handle the `-` flag character for non-custom conversion specifiers.

### 13. Print is the sharpest and the strongest weapon of our party
Handle the following custom conversion specifier:
- `%r`: prints the reversed string

### 14. The flood of print has turned reading into a process of gulping rather than savoring
Handle the following custom conversion specifier:
- `%R`: prints the ROT13 string

### 15. * All the above options work well together.

## Conclusion
The goal of this project is to gain a deeper understanding of how the `printf` function works in C by implementing our own version. By completing the tasks above, one isable to develop skills in handling various format specifiers, managing buffer usage, and implementing custom conversion specifiers.
