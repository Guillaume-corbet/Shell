/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** main
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdlib.h>
#include <stdarg.h>

int base(char *str, va_list args, int i, ...);
int my_printf2(char *str, va_list args, ...);
int my_printf(char *str, ...);
int unsigned_to_str(unsigned int nb);
int my_put_adress(void *p);
int put_big_string(char *str);
int number_str(char *str);
char *other_octal(int nb);
int decimal_hexadecimal_low(int nb);
int decimal_hexadecimal_upp(int nb);
int decimal_octal(int nb);
int decimal_binary(unsigned int nb);
int int_to_str_print(int nb);
int string(char *str, va_list args, int i);
int integer(char *str, va_list args, int i);
int modulo(char *str, va_list args, int i);
int character(char *str, va_list args, int i);
int big_string(char *str, va_list args, int i);
int unsigned_integer(char *str, va_list args, int i);
int hexadecimal_low(char *str, va_list args, int i);
int hexadecimal_upp(char *str, va_list args, int i);
int pointer(char *str, va_list args, int i);
int octal(char *str, va_list args, int i);
int binary(char *str, va_list args, int i);
int space(char *str, int i);
int display_for_space(int nb_char, int i, int test);
int display_dieze(char *str, int nb_char, int i, int test);
int dieze(char *str, int nb_char, int i);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

#define ADRESS
unsigned long nb_yes;
char res_yes[9];

#endif /* !MY_PRINTF_H_ */
