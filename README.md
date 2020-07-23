# ft_printf
Recoding of the libc’s printf function

(42 school project)

Make creates a library libftprintf.h that contains ft_printf, a function that 

- mimic the real printf
- supports conversions: c s p d i u x X %
- manages any combination of flags - 0 . * and minimum field width

![100/100](https://github.com/k-allard/imgs/blob/master/Screenshot%202020-07-21%20at%2014.44.27.png)

To test and use:
1. git clone
2. make
3. gcc libftprintf.a main.c
