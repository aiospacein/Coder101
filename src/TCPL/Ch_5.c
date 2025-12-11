#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
/*
Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.
Our version of getint returns EOF for end of file, zero if the next input is not a number, and a
positive value if the input contains a valid number
*/

// #define MAX_C_BUF 10
// int buff[MAX_C_BUF] = {0};
// int pbuf = -1;

// int getch(void)
// {
//     int c;
//     c = (pbuf == -1) ? getchar() : buff[pbuf--];
//     return c;
// }

// void ungetch(int c)
// {
//     if (pbuf < (MAX_C_BUF - 1))
//     {
//         /* code */
//         buff[++pbuf] = c;
//     }
// }

// int getint(int *pint)
// {
//     int c, sign = 1, i = 0;
//     while (((c = getch()) != EOF) && ((c == ' ') || (c == '\t'))) // || (c == '\n')))
//         ;
//     *pint = 0;
//     if (c == EOF)
//     {
//         /* code */
//         return EOF;
//     }

//     if (c == '-')
//         sign = -1;
//     else if (c == '+')
//         sign = 1;
//     else if (isdigit(c))
//     {
//         /* code */
//         *pint = c - '0';
//         i++;
//     }
//     else
//     {
//         /* code */
//         ungetch(c);
//         return 0;
//     }

//     while (isdigit(c = getch()))
//     {
//         /* code */
//         *pint = 10 * *pint + (c - '0');
//     }
//     ungetch(c);

//     *pint *= sign;

//     if (*pint)
//     {
//         /* code */
//         return 1;
//     }
//     else
//         return 0;
// }

// int main()
// {
//     int x;

//     printf("%d\n%d\n", x, getint(&x));
// }
/*Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat
return as its function value?
*/
// #define BUFSIZE 100
// char buf[BUFSIZE];
// int bufp = 0;
// /* buffer for ungetch */
// /* next free position in buf */
// int getch(void) /* get a (possibly pushed-back) character */
// {
//     return (bufp > 0) ? buf[--bufp] : getchar();
// }
// void ungetch(int c)
// /* push character back on input */
// {
//     if (bufp >= BUFSIZE)
//         printf("ungetch: too many characters\n");
//     else
//         buf[bufp++] = c;
// }

// int getfloat(double *fl)
// {
//     int c, dec = 1, sign = 0;

//     while (((c = getch()) != EOF) && ((c == ' ') || (c == '\t'))) // || (c == '\n')))
//         ;

//     if (c == EOF)
//         return EOF;

//     if ((c == '+') || (c == '-'))
//     {
//         sign = (c == '-') ? -1 : 1;
//         if (!isdigit(c = getch()))
//         {
//             ungetch(c);
//             return 0;
//         }
//         *fl = 0;
//         *fl = c - '0';
//     }

//     while (isdigit(c = getch()) && (c != '.'))
//         *fl = 10 * *fl + (c - '0');

//     if (c == '.')
//     {
//         while (isdigit(c = getch()))
//         {
//             *fl = 10 * *fl + (c - '0');
//             dec *= 10;
//         }
//     }
//     else
//     {

//         return 0;
//     }

//     *fl /= (double)dec;
//     *fl *= sign;

//     return 1;
// }

// int main()
// {
//     double x;
//     int y = getfloat(&x);

//     printf("%g\n%d\n", x, y);
// }

/*Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2:
strcat(s,t) copies the string t to the end of s.
*/
// void strcat;
/*Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.
*/
// int strend(char *s, char *t)
// {
//     int lent = strlen(t);
//     int lens = strlen(s);

//     while (lent)
//     {
//         /* code */
//         if (*(s + (lens-- - 1)) != (*(t + (lent-- - 1))))
//         {
//             /* code */
//             break;
//         }
//     }
//     if (lent != -1)
//         return 0;
//     else
//         return 1;
// }
/*Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n)
 copies at most n characters of t to s. Full descriptions are in Appendix B.
*/
// void strncpy(char *s, char *t, int n)
// {
//     int i = 0;
//     while ((*(t + i)) || (i < n))
//     {
//         *(s + i) = *(t + i);
//         i++;
//     }
//     *(s + i) = '\0';
// }

// void strncat(char *s, char *t, int n)
// {
//     int lens = strlen(s);
//     int i = 0;

//     while ((i < n) && *(t + i))
//     {
//         /* code */
//         *(s + lens + i) = *(t + i);
//         i++;
//     }
//     *(s + lens + i) = '\0';
// }

// int strnstr(char *s, char *t, int n)
// {
//     for (int i = 0; *(s + i) != '\0' && n; i++)
//         for (int j = 0, k = i; *(t + j) != '\0' && n--; j++, k++)
//         {
//             if (*(s + k) != *(t + j))
//                 break;
//         }
//     if (n == 0)
//         return 1;
//     else
//         return 0;
// }

// int strncmp(const char *s1, const char *t1, int n)
// {
//     while ((*s1 == *t1)&& (n>0))
//     {
//         /* code */
//         s1++;
//         t1++;
//         n--;
//     }
//     if (n==0)
//     {
//         /* code */
//         return 0;
//     }
//     else
//     {
//         return (*t1 - *s1);
//     }
// }

// int main()
// {
//     char s[] = "abcdef";
//     char t[] = "cd";
//     int n = 3;

//     int result = strnstr(s, t, n);
//     printf("%d\n", result);
// }
/*Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises with pointers
instead of array indexing. Good possibilities include getline (Chapters 1 and 4), atoi, itoa,
and their variants (Chapters 2, 3, and 4), reverse (Chapter 3), and strindex and getop
(Chapter 4).
*/

/*Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than
calling alloc to maintain storage. How much faster is the program?
*/
#define MAXLINES 5000
#define MAXARR 100000
char *lineptr[MAXLINES];

int ggetline(char *buff, int len)
{
    char c,*initptr = buff;
    while (((c = getchar()) != '\n') && (c != EOF) && (len-- > 1))
    {
        *buff = c;
        buff++;
    }
    *buff = '\0';
    return buff - initptr + 1;
}

int readlines(char *lineptr[], int nlines, char *buff, int buffsize)
{
    int linelength,currentline =0,oldlinelength=0;
    // read a line till end or nlines are read
    while (((linelength = ggetline(buff, buffsize)) > 0) && (nlines-- > 0) && (buffsize > 0))
    {
        buffsize -= linelength;
        lineptr[currentline++] = buff + oldlinelength;
        oldlinelength = linelength;
    }

    // move it to buff and dec the buff size

    return currentline;
}

void writelines(char *lineptr[], int nlines)
{
    int i = 0;
    while (nlines--)
    {
        printf("%s\n", lineptr[i++]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapc(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *lineptr[], int low, int hight)
{

    int pivotidx = (low + hight) / 2;

    char piviotvalue = *lineptr[pivotidx];

    swapc((lineptr + hight), lineptr + pivotidx);

    int j = low - 1;
    for (int i = low; i < hight; i++)
    {
        if (*lineptr[i] <= piviotvalue)
        {
            j++;
            swapc(lineptr + j, lineptr + i);
        }
    }

    swapc(lineptr + ++j, lineptr + hight);

    return j;
}

// void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *))
void qqsort(char *lineptr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivotidx = partition(lineptr, left, right);

    // // quick sort left
    qqsort(lineptr, left, pivotidx - 1);

    // // quick sort right
    qqsort(lineptr, pivotidx + 1, right);
}

// int numcmp(char *, char *)
// {
// }

int main(int argc, char *argv[])
{
    int nlines;
    int arr[MAXARR];
    // read while line is available or no of lines reached ad update the lineptr
    if ((nlines = readlines(lineptr, MAXLINES, arr, MAXARR)) > 0)
    {
        qqsort(lineptr, 0, nlines);
        writelines(lineptr, nlines);
    }

    // sort the lineptr

    // print the lines
}
/*Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.
 */

/*Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
indexing.
*/

/*Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + * evaluates 2 * (3+4).
*/

/*Exercise 5-11. Modify the program entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.
*/

/*Exercise 5-12. Extend entab and detab to accept the shorthand entab -m +n
to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
default behavior.
*/

/*Exercise 5-13. Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
tail -n prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size.
*/

/*Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse
(decreasing) order. Be sure that -r works with -n.
*/

/*Exercise 5-15. Add the option -f to fold upper and lower case together, so that case
distinctions are not made during sorting; for example, a and A compare equal.
*/

/*Exercise 5-16. Add the -d (``directory order'') option, which makes comparisons only on
letters, numbers and blanks. Make sure it works in conjunction with -f.
*/

/*Exercise 5-17. Add a field-searching capability, so sorting may bee done on fields within lines,
each field sorted according to an independent set of options. (The index for this book was
sorted with -df for the index category and -n for the page numbers.)
*/

/*Exercise 5-18. Make dcl recover from input errors.
 */

/*Exercise 5-19. Modify undcl so that it does not add redundant parentheses to declarations.
 */

/*Exercise 5-20. Expand dcl to handle declarations with function argument types, qualifiers like
const, and so on.
*/