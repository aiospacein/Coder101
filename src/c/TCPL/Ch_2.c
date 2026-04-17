#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.

*/
/*
int main()
{
    char a;
    signed char f;
    unsigned char e;
    int b;
    unsigned int c;
    signed int g;
    bool d;
    short unsigned int q;
    short signed int h;
    long i;
    signed long j;
    long long k;
    unsigned long l;
    long double m;
    double n;
    long double o;
    long long int p;
    long long unsigned int r;

    printf("Char:%d\nInt:%d\nunsigned int:%d\nbool:%d\nunsigned char: %d\nusigned char:%d\n \
        signed char: %d\nsigned int:%d\nshort signed int:%d\nlong:%d\nsigned long:%d\n \
        long long:%d\n unsigned long:%d\nlong double%d\n%d\n%d\n%d\n%d\n",
           sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e), sizeof(f), sizeof(g), sizeof(h),
           sizeof(i), sizeof(j), sizeof(k), sizeof(l), sizeof(m), sizeof(n), sizeof(o), sizeof(p), sizeof(q), sizeof(r));
}
*/
/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

*/

/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F.

*/
// int pwr(int base, int p)
// {
//     if (p==0)
//     {
//         /* code */
//         return 1;
//     }

//     return (base * pwr(base, p - 1));
// }

// int htoi(char *p)
// {
//     if ((*p == '0') && ((*(p + 1) == 'x') || (*(p + 1) == 'X')))
//         p += 2;

//     int ret = 0, i = 0;

//     while (*(p + i) != '\0')
//         i++;
//     int idx = 0;
//     while (i--)
//     {
//         /* code */
//         char c = *(p + i);

//         if ((c >= 'A') && (c <= 'F'))
//         {
//             /* code */
//             int x = c - 'A' + 10;
//             ret += x*pwr(16, idx++);
//         }
//         else if ((c >= 'a') && (c <= 'f'))
//         {
//             /* code */
//             int x = c - 'a' + 10;
//             ret += x * pwr(16, idx++);
//         }
//         else if ((c >= '0') && (c <= '9'))
//         {
//             /* code */
//             int x = c - '0';
//             ret += x * pwr(16, idx++);
//         }
//         else
//         {
//             printf("Invalid Number\n");
//         }
//     }
//     return ret;
// }
// int main()
// {

//     char *c = "0xFF";
//     int rest = htoi(c);

//     printf("%d\n", rest);
// }

/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.

*/
// void squeez(char* s1, char *s2)
// {
//     int i = 0;
//     while (s2[i] != '\0')
//     {
//         /* code */
//         int j, k;
//         for (k=0, j = 0; s1[j] != '\0'; j++)
//         {
//             /* code */
//             if (s1[j] != s2[i])
//             {
//                 /* code */
//                 s1[k++] = s1[j];
//             }
//         }
//         s1[k] = '\0';
//         i++;
//     }
// }

// int main()
// {

//     char src[] = "kusgfvusaevf'ioaevhoiq";
//     char fltr[] = "sae";
//     squeez(src, fltr);
//     printf("%s\n", src);
// }

/* Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)

*/
// char * strbbrk(char *s1, char *s2)
// {
//     int i = 0;
//     char c;
//     while ((c = s1[i++]) != '\0')
//     {
//         /* code */
//         for (int j = 0; s2[j] != '\0' ; j++)
//         {
//             /* code */
//             if (c == s2[j])
//             {
//                 /* code */
//                 return (s1 + (i - 1));
//             }
//         }

//     }
//     return -1;
// }

// int main()
// {

//     char src[] = "kgusgfvusaevf'ioaevhoiq";
//     char fltr[] = "gsae";
//     char *pc = strbbrk(src, fltr);
//     printf("%p\n%c\n",pc , *pc);
// }

/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y, leaving the other bits unchanged.
*/
// uint32_t setbits(uint32_t x, uint32_t p, uint32_t n, uint32_t y)
// {
//     uint32_t bitcopy = (y & ((1 << n) - 1)) << (p - n);
//     // uint32_t BitMask = ~((((1 << p) - 1) >> (p - n)) << (p - n));
//     uint32_t BitMask = ~(((1 << n) - 1) << (p - n + 1));
//     x = x & BitMask;
//     return (x | bitcopy);
// }

// int main()
// {
//     uint32_t x = 0b10101000;
//     uint32_t y = 0b00000111;
//     printf("%b\n", setbits(x, 4, 3, y));
// }
/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/
// uint32_t invert(uint32_t x, uint32_t p, uint32_t n)
// {
//     uint32_t BitMask = (((1 << n) - 1) << (p - n + 1));
//     // return ((x & ~BitMask) | (~x & BitMask));
//     return (x ^BitMask);
// }

// int main()
// {
//     uint32_t x = 0b10101000;
//     printf("%b\n", invert(x, 7, 5));
// }
/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.
*/
// int pwr(int base, int p)
// {
//     if (p==0)
//     {
//         /* code */
//         return 1;
//     }

//     return (base * pwr(base, p - 1));
// }
// int rightrot(int x , int pos)
// {
//     int tmp1 = x % pwr(10, pos);
//     int tmp2 = x / pwr(10, pos);
//     return ((tmp1 * pwr(10, pos - 1)) + tmp2);
// }

// uint32_t rightrotbits(uint32_t x, uint32_t pos)
// {
//     uint32_t BitMask = (((1 << pos) - 1)&x) << ((sizeof(uint32_t) * 8) - pos);
//     return (x >> pos) | (BitMask);
// }

// int main()
// {
//     uint32_t x = 0b101001011010111;
//     printf("%b\n", rightrotbits(x, 5));
// }
/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.
*/
// int bitcount(uint32_t x)
// {
//     int count = 0;
//     while (x)
//     {
//         /* code */
//         x &= (x - 1);
//         count++;
//     }
//     return count;
// }
// int main()
// {
//     uint32_t x = 0b101001011010111;
//     printf("%d\n", bitcount(x));
// }
/* Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.

*/
// void lower(char *s1)
// {
//     int i = 0;
//     while (s1[i] != '\0')
//     {
//         /* code */
//         ((s1[i] >= 'A') && (s1[i] <= 'Z')) ? s1[i] += 32 : s1[i];
//         i++;
//     }
// }

// int main()
// {

//     char src[] = "kgusgHAADSCANCevfioaevhoiq";
//     lower(src);
//     printf("%s\n", src);
// }