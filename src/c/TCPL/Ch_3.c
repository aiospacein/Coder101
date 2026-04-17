#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and measure
the difference in run-time.
*/

// #define N 1000000
// #define R 5000000

// int binsearch_original(int x, int v[], int n)
// {
//     int low = 0, high = n - 1, mid;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (x < v[mid])
//             high = mid - 1;
//         else if (x > v[mid])
//             low = mid + 1;
//         else
//             return mid;
//     }
//     return -1;
// }

// int binsearch(int x, int v[], int n)
// {
//     int low, high, mid;
//     low = 0;
//     high = n - 1;
//     while (low <= high)
//     {
//         mid = (low + high) / 2;
//         if (x <= v[mid])
//             high = mid - 1;
//         else
//             low = mid + 1;
//     }
//     /* Outside the loop, we only need to check one spot */
//     if (low < n && v[low] == x)
//         return low;

//     return -1;
// }

// double benchmark(int (*func)(int, int *, int), int *arr, int n)
// {
//     clock_t start = clock();
//     for (int i = 0; i < R; i++)
//         func(777777, arr, n); // search element near the end
//     clock_t end = clock();

//     return (double)(end - start) / CLOCKS_PER_SEC;
// }

// int main()
// {
//     int *arr = malloc(sizeof(int) * N);
//     for (int i = 0; i < N; i++)
//         arr[i] = i; // sorted array

//     printf("Benchmarking, please wait...\n\n");

//     double t1 = benchmark(binsearch_original, arr, N);
//     double t2 = benchmark(binsearch, arr, N);

//     printf("Original (two-test) version : %f sec\n", t1);
//     printf("Single-test version         : %f sec\n", t2);
//     printf("Speedup: %.2f%% faster\n",
//            ((t1 - t2) / t1) * 100.0);

//     free(arr);
//     return 0;
// }

/*Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
function for the other direction as well, converting escape sequences into the real characters.
*/
// void escape(char *s, char *t)
// {
//     int i = 0, j = 0;
//     char c;

//     while ((c = t[i++]) != '\0')
//     {
//         /* code */
//         switch (c)
//         {
//         case '\n':
//             /* code */
//             s[j++] = '\\';
//             s[j++] = 'n';
//             break;
//         case '\t':
//             /* code */
//             s[j++] = '\\';
//             s[j++] = 't';
//             break;
//         default:
//             s[j++] = c;
//             break;
//         }
//     }
//     s[j] = '\0';
// }

// void descape(char *s, char *t)
// {
//     int i = 0, j = 0;
//     char lastchar, c;

//     while ((c = t[i++]) != '\0')
//     {
//         /* code */
//         switch (c)
//         {
//         case 'n':
//             /* code */
//             if (lastchar == '\\')
//             {
//                 /* code */

//                 s[j++] = '\n';
//                 lastchar = '\0';
//             }
//             else{
//                 s[j++] = c;
//             }
//             break;
//         case 't':
//             /* code */
//             if (lastchar == '\\')
//             {
//                 /* code */

//                 s[j++] = '\t';
//                 lastchar = '\0';
//             }
//             else
//             {
//                 s[j++] = c;
//             }
//             break;
//         case '\\':
//             lastchar = c;
//             break;
//         default:
//             s[j++] = c;
//             break;
//         }
//     }
//     s[j] = '\0';
// }

// int main()
// {
//     char input[] = "Hello\\tWorld\\nLine2\\";
//     char output[200];
//     descape(output, input);
//     printf("%s\n", output);
// }
/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
leading or trailing - is taken literally.
*/
// void expand(char *s1, char *s2)
// {
//     char c;
//     int i =0, j=0;
//     char start=0, mid=0;

//     while ((c = s2[i]) != '\0')
//     {
//         if ((c >= 'a') && (c <= 'z'))
//         {
//             /* code */
//             if (!start)
//             {
//                 /* code */
//                 start = c;
//             }
//             else if ((mid == '-') && (c >= start))
//             {
//                 /* code */
//                 char c1 = start;
//                 while (c1 <= c)
//                 {
//                     /* code */
//                     s1[j++] = c1++;
//                 }
//                 start = 0;
//                 mid = 0;
//             }
//             else
//             {
//                 printf("Invalid Expression\n");
//                 break;
//             }
//         }
//         else if ((c >= 'A') && (c <= 'Z'))
//         {
//             /* code */
//             if (!start)
//             {
//                 /* code */
//                 start = c;
//             }
//             else if ((mid == '-') && (c >= start))
//             {
//                 /* code */
//                 char c1 = start;
//                 while (c1 <= c)
//                 {
//                     /* code */
//                     s1[j++] = c1++;
//                 }
//                 start = 0;
//                 mid = 0;
//             }
//             else
//             {
//                 printf("Invalid Expression\n");
//                 break;
//             }
//         }
//         else if ((c >= '0') && (c <= '9'))
//         {
//             /* code */
//             if (!start)
//             {
//                 /* code */
//                 start = c;
//             }
//             else if ((mid == '-') && (c >= start))
//             {
//                 /* code */
//                 char c1 = start;
//                 while (c1 <= c)
//                 {
//                     /* code */
//                     s1[j++] = c1++;
//                 }
//                 start = 0;
//                 mid = 0;
//             }
//             else
//             {
//                 printf("Invalid Expression\n");
//                 break;
//             }
//         }
//         else if (c == '-')
//         {
//             /* code */
//             if (!start)
//             {
//                 /* code */
//                 s1[j++] = c;
//             }
//             else
//             {
//                 mid = c;
//             }
//         }
//         else
//         {
//             s1[j++] = c;
//         }
//         i++;
//     }

//     if (start)
//     {
//         /* code */
//         s1[j++] = start;
//     }

//     if (mid)
//     {
//         /* code */
//         s1[j++] = mid;
//     }

//     s1[j++] = '\0';
// }

// int main()
// {
//     char input[] = "a-z";
//     char output[200];
//     expand(output, input);
//     printf("%s\n", output);
// }

/*Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not.
Modify it to print that value correctly, regardless of the machine on which it runs.
*/

void reverse(char *ptr)
{
    int len = strlen(ptr);

    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        /* code */
        char temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }
}

// void itoaa(int n, char s[])
// {
//     int i = 0;
//     int sign = n;

//     do
//     {
//         int digit = n % 10;

//         if (digit < 0)
//             digit = -digit;

//         s[i++] = digit + '0';
//         n /= 10;
//     } while (n != 0);

//     if (sign < 0)
//         s[i++] = '-';

//     s[i] = '\0';

//     // reverse the string
//     int j = 0, k = i - 1;
//     while (j < k)
//     {
//         char tmp = s[j];
//         s[j] = s[k];
//         s[k] = tmp;
//         j++;
//         k--;
//     }
// }

// void itoa(int n ,char *buff)
// {
//     int sign = n, i = 0;
//     if (n < 0)
//     {
//         /* code */
//         n = -n;
//     }

//     while ((n/10 ) >0)
//     {
//         /* code */
//         buff[i++] = n % 10 + '0';
//         n = n / 10;
//     }
//     buff[i++] = n % 10 + '0';

//     if (sign<0)
//     {
//         /* code */

//         buff[i++] = '-';
//     }

//     buff[i] ='\0';

//     reverse(buff);
// }

// int main()
// {
//     int n = -2147483648;
//     char output[200];
//     itoa(n, output);
//     printf("%s\n", output);
// }
/*Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s.
*/
// void itob(int n, char *s, int b)
// {
//     int i = 0;
//     int sign = n;
//     do
//     {
//         int digit = n % b;

//         if (digit<0)
//         {
//             /* code */
//             digit = -digit;
//         }

//         if (digit > 9)
//         {
//             /* code */
//             s[i++] = digit - 10 + 'A';
//         }
//         else
//         {
//             /* code */
//             s[i++] = digit + '0';
//         }

//     } while ((n/=b)!=0);

//     if(sign <0)
//         s[i++] = '-';

//     s[i++] = '\0';

//     reverse(s);
// }

// int main()
// {
//     int n = -255;
//     char output[200];
//     itob(n, output,16);
//     printf("%s\n", output);
// }
/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.

*/

// void itoa(int n, char *buff, int width)
// {
//     int sign = n, i = 0;

//     do
//     {
//         /* code */
//         int digit = n % 10 ;
//         if (digit < 0)
//         {
//             /* code */
//             digit = -digit;
//         }

//         buff[i++] = digit + '0';
      
//     } while ((n /= 10) != 0);

//     if (sign < 0)
//     {
//         buff[i++] = '-';
//     }

//     while (width > i)
//     {
//         /* code */
//         buff[i++] = ' ';
//     }

//     buff[i] = '\0';

//     reverse(buff);
// }

// int main()
// {
//     int n = -2147483648;
//     char output[200];
//     itoa(n, output, 16);
//     printf("%s\n", output);
// }