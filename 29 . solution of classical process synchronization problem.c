#include <dirent.h>
#include <stdio.h>

int main(void) 
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    return 0;
}

/* Output
postfix_expression_evaluation.exe
prims.cpp
prims.exe
queue.cpp
queue.exe
quick_sort.cpp
quick_sort.exe
quotient_remainder.cpp
quotient_remainder.exe
red_black_tree.cpp
red_black_tree.exe
roots_of_quadratic.cpp
roots_of_quadratic.exe
sizeof_char_int_float_double.cpp
sizeof_char_int_float_double.exe
sjf.cpp
sjf.exe
smallest_ex_time.cpp
smallest_ex_time.exe
stack.cpp
stack.exe
sum_of_natural_numbers_using_loop.cpp
sum_of_natural_numbers_using_loop.exe
Swapping_two_numbers.cpp
Swapping_two_numbers.exe
Untitled1.cpp
Untitled1.exe
vowel_or_consonant.cpp
vowel_or_consonant.exe
--------------------------------
Process exited after 0.02037 seconds with return value 0
Press any key to continue . . .
