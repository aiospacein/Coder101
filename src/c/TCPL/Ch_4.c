#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none.

*/
// int strindex(char *s, char *m)
// {
//     int matchlen = strlen(m);
//     int j = 0;
//     for (int i = 0; s[i] != '\0'; i++)
//     {
//         /* code */
//         if (s[i] == m[j])
//         {
//             /* code */
//             if (j == matchlen - 1)
//             {
//                 /* code */
//                 return (i-(matchlen-1));
//             }

//             j++;
//         }
//         else
//         {
//             j = 0;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     char src[] = "hello world";
//     char mtch[] = "world";

//     printf("%d\n", strindex(src, mtch));
// }
/*Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.
*/

// #undef atof
// double atoff(char *s)
// {

//     int sign, expval = 0, expsign = 0, pwr = 1, dec = 0, i = 0;
//     char c;
//     double exppwr = 1.0, ret = 0.0;

//     sign = (*(s) == '-') ? -1 : 1;

//     while ((c = s[i++]) != '\0')
//     {
//         /* code */
//         if ((c >= '0') && (c <= '9'))
//         {
//             if (!expsign)
//             {
//                 if (dec == 1)
//                 {
//                     /* code */
//                     pwr *= 10;
//                 }
//                 ret = (c - '0') + ret * 10;
//             }
//             else
//             {

//                 expval = (c - '0') + expval * 10;
//             }
//         }
//         if (c == '.')
//         {
//             /* code */
//             dec = 1;
//         }

//         if ((c == 'e') || (c == 'E'))
//         {
//             /* code */
//             expsign = s[i++] == '-' ? -1 : 1;
//         }
//     }

//     if (expsign != 0)
//     {
//         /* code */
//         if (expsign == -1)
//         {
//             /* code */
//             while (expval--)
//             {
//                 /* code */
//                 exppwr /= 10.0;
//             }
//         }
//         else
//         {
//             /* code */
//             while (expval--)
//             {
//                 /* code */
//                 exppwr *= 10.0;
//             }
//         }
//     }
//     printf("%lf\n", exppwr);
//     return (double)sign * (ret / (double)pwr) * exppwr;
// }

// int main()
// {
//     char b[] = "123.45e-6";
//     double f = atoff(b);

//     printf("%lf\n", f);
// }

/*Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add the
modulus (%) operator and provisions for negative numbers.
*/
// #include <ctype.h>
// #include <math.h>

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

// #define MAXOP 100
// #define NUMBER '\0'

// #define MAXVAL 100
// int sp = 0;
// double val[MAXVAL];
/* maximum depth of val stack */
/* next free stack position */
/* value stack */
/* push: push f onto value stack */
// void push(double f)
// {
//     if (sp < MAXVAL)
//         val[sp++] = f;
//     else
//         printf("error: stack full, can't push %g\n", f);
// }
// /* pop: pop and return top value from stack */
// double pop(void)
// {
//     if (sp > 0)
//         return val[--sp];
//     else
//     {
//         printf("error: stack empty\n");
//         return 0.0;
//     }
// }

// /* getop: get next character or numeric operand */
// int getop(char s[])
// {
//     int i, c, next;
//     while ((s[0] = c = getch()) == ' ' || c == '\t')
//         ;
//     s[1] = '\0';

//     // If not digit, decimal, or minus → return operator immediately
//     if (!isdigit(c) && c != '.' && c != '-')
//         return c;

//     // Check if minus is unary (negative number) or operator
//     if (c == '-')
//     {
//         next = getch();
//         if (!isdigit(next) && next != '.')
//         {
//             // it is a minus operator
//             ungetch(next);
//             return '-';
//         }
//         // negative number: keep '-'
//         s[i++] = next;
//         c = next;
//     }

//     if (isdigit(c))
//         /* collect integer part */
//         while (isdigit(s[++i] = c = getch()))
//             ;
//     if (c == '.')
//         /* collect fraction part */
//         while (isdigit(s[++i] = c = getch()))
//             ;
//     s[i] = '\0';
//     if (c != EOF)
//         ungetch(c);
//     return NUMBER;
// }

/* reverse Polish calculator */
// main()
// {
//     int type;
//     double op2;
//     int mod;
//     char s[MAXOP];
//     while ((type = getop(s)) != EOF)
//     {
//         switch (type)
//         {
//         case NUMBER:
//             push(atof(s));
//             break;
//         case '+':
//             push(pop() + pop());
//             break;
//         case '*':
//             push(pop() * pop());
//             break;
//         case '-':
//             op2 = pop();
//             push(pop() - op2);
//             break;
//         case '/':
//             op2 = pop();
//             if (op2 != 0.0)
//                 push(pop() / op2);
//             else
//                 printf("error: zero divisor\n");
//             break;
//         case '%':
//             mod = (int)pop();
//             if (mod != 0)
//                 push((int)pop() % mod);
//             else
//                 printf("error: zero modulus\n");
//             break;
//         case '\n':
//             printf("\t%.8g\n", pop());
//             break;
//         default:
//             printf("error: unknown command %s\n", s);
//             break;
//         }
//     }

//     return 0;

// }
/*Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.
*/
// void peek(void)
// {
//     if (sp > 0)
//     {
//         int sp1 = sp - 1;
//         printf("%g Top val is : ", val[sp1]);
//     }
//     else
//     {
//         printf("error: stack empty\n");
//     }
// }

// void swap(void)
// {
//     if (sp > 1)
//     {
//         double temp = val[sp - 1];
//         val[sp - 1] = val[sp - 2];
//         val[sp - 2] = temp;
//     }
//     else
//     {
//         printf("error: stack empty\n");
//     }
// }

// void clear(void)
// {
//     sp = 0;
// }

/*Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in
Appendix B, Section 4.
*/

/*Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.
*/

/*Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp, or should it just use ungetch?
*/

/*Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.
*/

/*Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide
what their properties ought to be if an EOF is pushed back, then implement your design.
*/

/*Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.
*/

/*Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal
static variable.
*/

/*Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert
an integer into a string by calling a recursive routine.
*/


/*Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the
string s in place.
*/
// void recreverse(char *p, int len)
// {
//     if (len < 1)
//     {
//         /* code */

//         return;
//     }

//     char temp = *p;
//     *p = *(p + len);
//     *(p + len) = temp;

//     return recreverse(p + 1, len - 2);
// }

// int main()
// {
//     char s1[] = "afdwsfrwrgwe";
//     recreverse(s1, strlen(s1) - 1);
//     printf("%s\n", s1);
// }
/*Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.)

*/
// BETTWER WAY IS DO WHILE
/*
#define SWAP(t, x, y) \
    {                 \
        t temp = x;   \
        x = y;        \
        y = temp;     \
    }
*/