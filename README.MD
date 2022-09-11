# ft_printf

Own realisation of c standart printf function

## About

This project is part of program in [School 21](https://21-school.ru/) ([Ecole 42](42.fr)).  
That's my own partial implementation of printf function.  
The main goal of this project is to get deep inside of how
does standart c functions works.

## Requirements

- GNU GCC
- GNU Make

## Installation and usage

1. Download/Clone this repo

   > git clone https://github.com/shalfbea/ft_printf

2. Get into the root directory of project and run make command

   > cd ft_printf
   > make
3. (Optional) Run make bonus to get some additional functionality

   > make bonus

4. Now you have compiled version of this library - libftprintf.a, which you can use in your projects

## Technical task

The full task can be found here: [ft_printf_subject](https://github.com/shalfbea/ft_printf/blob/main/ft_printf_subject.pdf)

### Quick summary:

- Only using c language is allowed
- Code-style should respect the [The Norm](https://github.com/MagicHatJo/-42-Norm/blob/master/norme.en.pdf)
- No memory leaks, segmentation faults, undefined behavior
- Only allowed functions: malloc, free, write,va_start, va_arg, va_copy, va_end
- Can also use [libft](https://github.com/shalfbea/libft) (own implementation of part of the library functions)
- Handle the following conversions: cspdiuxX%

### Bonus:

- Manage any combination of the following flags: "-", "0", "." and the field minimum width under all conversions.
- Manage all the following flags: "#", " ", "+" (Yes, one of them is a space)

### Evaluation result:
<img width="1278" alt="ft_printf_evaluation_result" src="https://user-images.githubusercontent.com/92727363/187229317-4a8ae684-49f9-45d8-a8e1-831515810e6f.png">
