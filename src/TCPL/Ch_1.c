#include <stdio.h>
#include <stdlib.h>
// #define EX_1_1
// #define EX_1_2
// #define EX_1_3
// #define EX_1_4
#define EX_1_5

#ifdef EX_1_1
/*Exercise 1-1. Run the ``hello, world'' program on your system. Experiment with leaving out
parts of the program, to see what error messages you get.*/
int main(int test, char **argv)
{
    printf("Hello, World");
}
#endif

#ifdef EX_1_2
// bascically addingg /c where c is soem keyword to get idea about speciat character
/*Exercise 1-2. Experiment to find out what happens when prints's argument string contains
\c, where c is some character not listed above.*/
int main(int test, char **argv)
{
    printf("Hello, World \f");
}
#endif

#ifdef EX_1_3
/*Exercise 1-3. Modify the temperature conversion program to print a heading above the table.*/
/*The next program uses the formula oC=(5/9)(oF-32) to print the following table of Fahrenheit
temperatures and their centigrade or Celsius equivalents:*/
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
#define MAXTEMP 300
int main(int test, char **argv)
{
    float far = 1;
    printf("Farnhite \tCelcious\n");
    while (far <= 300.0f)
    {
        /* code */
        printf("%8.0f \t%.3f\n", far, (5.0f / 9.0f) * (far - 32.0f));

        far += 20;
    }
}
#endif

#ifdef EX_1_4
/*Exercise 1-3. Modify the temperature conversion program to print a heading above the table.*/
/*The next program uses the formula oC=(5/9)(oF-32) to print the following table of Fahrenheit
temperatures and their centigrade or Celsius equivalents:*/
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
#define MAXTEMP 300
int main(int test, char **argv)
{
    float cel = 1;
    printf("Celcious \tFarnite\n");
    while (cel <= 300.0f)
    {
        /* code */
        printf("%8.0f \t%.3f\n", cel, (cel / (5.0f / 9.0f)) + 32.0f);
        cel += 20;
    }
}
#endif

#ifdef NF
/*Exercise 1-5. Modify the temperature conversion program to print the table in reverse order,
that is, from 300 degrees to 0.*/
#define MAXTEMP 300
int main(int test, char **argv)
{

    printf("Celcious \tFarnite\n");
    for (float cel = MAXTEMP; cel <= 0.0; cel -= 20)
    {
        /* code */
        printf("%8.3f\t%-6.3f\n", cel, (cel / (5.0f / 9.0f)) + 32);
    }
}
#endif

#if 0
/*Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1. Ans: its 1
Exercise 1-7. Write a program to print the value of EOF.Ans: -1*/
int main(int test, char **argv)
{

    char c;
    while ((c=getchar()) != EOF)
    {
        /* code */
        printf("%d\n", EOF);
        putchar(c);
    }
}
#endif

#if 1
/*Exercise 1-8. Write a program to count blanks, tabs, and newlines.
Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.
Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each
backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
unambiguous way.*/
// int main(int test, char **argv)
// {
//     int c;
//     int bl = 0, tab = 0, nl = 0;
//     while ((c = getchar()) != EOF)
//     {
//         /* code */
//         if (c== '\t')
//         {
//             /* code */
//             tab++;
//         }
//         else if (c == '\n')
//         {
//             /* code */
//             nl++;
//         }
//         else if (c==' ')
//         {
//             /* code */
//             bl++;
//         }
//         printf("Blank: %d \tTab: %d\t NewLine:%d", bl, tab, nl);
//     }
// }

// int main (int argc,int **argv)
// {
//     int c,space=0;
//     while ((c=getchar())!= EOF)
//     {
//         /* code */
//         if (c == ' ')
//         {
//             /* code */
//             space++;
//         }
//         else if (space!=0)
//         {
//             /* code */
//             putchar(' ');
//             putchar(c);
//             space = 0;
//         }
//         else{
//             putchar(c);
//         }
//     }
// }

// int main (int argc, char **argv)
// {
//     int c;
//     while ((c=getchar())!= EOF)
//     {
//         /* code */
//         if (c=='\t')
//         {
//             /* code */
//             putchar('\\');
//             putchar('t');
//         }
//         if (c == '\b')
//         {
//             /* code */
//             putchar('\\');
//             putchar('b');
//         }
//         if (c == '\\')
//         {
//             /* code */
//             putchar('\\');
//             putchar('\\');
//         }
//         else
//         {
//             putchar(c);
//         }
//         }

// }
#endif

/*
Exercise 1-11. How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any?*/
// int main()
// {
//     int c,wc=0,instring;
//     while ((c= getchar())!= EOF)
//     {
//         /* code */
//         if (c == '\t' || c== '\n' || c== ' ')
//         {
//             if (instring == 1)
//             {
//                 /* code */
//                 instring = 0;
//                 wc++;
//             }
//         }
//         else
//         {

//             instring = 1;
//         }
//         printf("%d\n", wc);
//     }
// }
/*Exercise 1-12. Write a program that prints its input one word per line.*/
// int main()
// {
//     int c, wc = 0, instring;
//     while ((c = getchar()) != EOF)
//     {
//         /* code */
//         if (c == '\t' || c == '\n' || c == ' ')
//         {
//             if (instring == 1)
//             {
//                 /* code */
//                 instring = 0;
//                 wc++;
//                 putchar('\n');
//             }
//         }
//         else
//         {
//             putchar(c);
//             instring = 1;
//         }
//         // printf("%d\n", wc);
//     }
// }

/*Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.*/
// int main()
// {
//     int c, wl =0, wc = 0, instring=0;
//     int wlb[10] = {0};

//     while ((c = getchar()) != EOF)
//     {
//         /* code */
//         if (c == '\t' || c == '\n' || c == ' ')
//         {
//             if (instring == 1)
//             {
//                 /* code */
//                 wlb[wl]++;
//                 instring = wl = 0;
//                 wc++;
//                 // putchar('\n');
//             }
//         }
//         else
//         {
//             // putchar(c);
//             instring = 1;
//             wl++;
//         }
//         // printf("%d\n", wc);
//     }
//     for (size_t i = 1; i < sizeof(wlb)/sizeof(wlb[0]); i++)
//     {
//         /* code */
//         int count = wlb[i];
//         printf("WL:%d\t", i);
//         while (count--)
//         {
//             /* code */
//             printf("|");
//         }
//         printf("\n");
//     }
// }
/*Exercise 1-14. Write a program to print a histogram of the frequencies of different characters
in its input.*/
// int main()
// {
//     int c, wl = 0, wc = 0, instring = 0;
//     int wlb[26] = {0};

//     while ((c = getchar()) != EOF)
//     {
//         /* code */

//         if ((c >= 65) && (c <= (65 + 25)))
//         {
//             wlb[c - 65]++;
//         }
//         if ((c >= 97) && (c <= (97 + 25)))
//         {
//             /* code */
//             wlb[c - 97]++;
//         }
//     }

//     for (size_t i = 0; i < sizeof(wlb) / sizeof(wlb[0]); i++)
//     {
//         /* code */
//         int count = wlb[i];
//         printf("WL:%d\t", i);
//         while (count--)
//         {
//             /* code */
//             printf("|");
//         }
//         printf("\n");
//     }
// }
/*Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.*/

/*Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text.*/
/*
read length of line//methood
compare witdth last line length//methood
update the longestline param//methood
do till list list
print the lastline and length
*/
// #define MAXLEN 1000

// int linelegth(char *src)
// {
//     int len = 0;
//     while (((*src = getchar()) != EOF) && (*src != '\n'))
//     {
//         /* code */
//         if (len < MAXLEN - 1)
//         {
//             src += 1;
//         }
//         len++;
//     }
//     *src = '\0';

//     // printf("Length 0 %d", len);
//     return len;
// }

// // int compare();

// void copy(char *src, char *dst)
// {
//     while ((*dst++ = *src++) != '\0')
//         ;
// }

// int main(int argc, char **argv)
// {
//     int c = 0, prelen = 0, len = 0;
//     char prebuff[MAXLEN] = {0};
//     char buff[MAXLEN] = {0};
//     char *print = '\0';
//     while ((len = linelegth(buff)) > 0)
//     {
//         // printf("Length %d", len);
//         if (prelen < len)
//         {
//             /* code */
//             prelen = len;
//             copy(buff, prebuff);

//             // printf("length is:%d and string is \n%s\n", prelen, prebuff);
//         }
//     }

//     printf("length is:%d and string is \n%s", prelen, prebuff);
// }

/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.*/
// int main(int argc, char **argv)
// {
//     int len = 0;
//     char buff[MAXLEN] = {0};
//     while ((len = linelegth(buff)) > 0)
//     {
//         if (len>8)
//         {
//             printf("string is \n%s\n",  buff);
//         }
//     }

//     // printf("length is:%d and string is \n%s", prelen, prebuff);
// }
/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.*/
/*
//read each line
//do: till new line
//check if char is blank or tab keep couting for consuctive else  reset
//check if connsecutive new line
//add null count elment before
//

check if last
*/
// int main()
// {

// }
/*Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.*/
/*
Arch:
input : line
output: line in reverse
Sub-Task:
Read the string
Reverse the string
print the string
Edge Case:
Max Buffer
Flow: Sub-Task

*/
// #define MAXBUFF 100
// int readline(char a[])
// {
//     int c = 0, len = 0;

//     while ((len < MAXBUFF-1)&&((c = getchar())!=EOF) && (c != '\n'))
//     {
//         /* code */
//         a[len++] = c;
//     }

//     a[len] = '\0';
//     return len;
// }

// void swapchar(char*dst,char*src)
// {
//     *dst ^= *src;
//     *src ^= *dst;
//     *dst ^= *src;
// }

// void reversestring(char a[],int len)
// {
//     //read fist and last char
//     // swap
//     // read till reach mid string (even odd case no difference)
//     for (int i = 0; i < (len/2);i++)
//         swapchar((a+len - i - 1), (a+i));
// }

// int main()
// {
//     char buff[MAXBUFF] = {0};
//     int len = 0;
//     while ((len = readline(buff))>0)
//     {
//         /* code */
//         reversestring(buff,len);
//         printf("STIRING IS :::::::\n%s\n", buff);
//     }
// }
/*Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
Arch:
Input: String
Output: String with tab aligned text
Sub-Task:
detab

*/

#define MAXLEN 100
#define TABLEN 4
int readline(char *buff)
{
    int c, len = 0;

    while ((len < MAXLEN - 1) && (c = getchar()) != EOF && (c != '\n'))
    {
        /* code */
        buff[len++] = c;
    }
    buff[len] = '\0';
    return len;
}

//
void detab(char *buff, int len)
{
    int i =0, col = 0;
    while (buff[col] != '\0')
    {
        /* code */
        if (buff[col] == '\t')
        {
            /* code */
            int space = TABLEN - ( i % TABLEN);

            while (space-- > 0)
            {
                /* code */
                putchar(' ');
                i++;
            }
        }
        else
        {
            /* code */
            putchar(buff[col]);
            i++;
            if (buff[i] == '\n') // ADDED
                i = 0;         // ADDED
        }

        col++;
    }
}

int main()
{
    char buff[MAXLEN] = {0};
    int len = 0;
    while ((len = readline(buff)) > 0)
    {
        /* code */
        detab(buff, len);
        // printf("%s\n", buff);
    }
}
/*Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?

*/

/*Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.

*/

/*Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/

/*Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full generality.)
*/