/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Q 1. )Check if the ith bit is set or not
bool IsIthBitSet(uint32_t In, uint8_t BitPos)
{
	return((In & (1 << BitPos) )!= 0);
}
// Q 2.) Set the ith bit of a number.
void SetIthBit(uint32_t *In, uint8_t BitPos) {
	*In |= (1 << BitPos);
}
// Q 3.) clear the ith bit of a number.
void ClearIthBit(uint32_t *In, uint8_t BitPos) 
{ 
    *In &= ~(1 << BitPos); 
}
// Q 4.) Remove the last set bit of a number.
void ClearLastSetBit(uint32_t *In) 
{ 
    *In = (-*In ^ *In)& *In; 
//OR
	*In = *In & (*In - 1);
}
// Q 5. ) Find whether a number is even or odd
bool IsOdd(uint32_t In) 
{ 
    return ((In & 0x1)!=0); 
}
// Q 6.) Check if the number is a power of 2?
bool IsPwrOf2(uint32_t In) 
{ 
    return !(In & (In - 1)); 
}
// Q 7.) Check if a number is a power of 4?
bool IsPwrOf4(uint32_t In) { return (!(In & 0x3)); }
// Q 8.) Check if a number is a power of 8?
// Q 9.) Check if a number is a power of 16?
// Q 10.) Toggle ith Bit of a number?
void ToggleIthBit(uint32_t In)
{

}
// Q 11.) Count the number of set bits in a number
uint8_t NoOfSetBit(uint32_t In)
{
	uint8_t count = 0;
	while (In) {
		/* code */
        if ((In & 0x1) == 0x1)
        {
            /* code */
			count++;
		}
		In = In >> 1;
	}
	return count;
}
// Q 12.) Find the two non-repeating elements in an array of repeating elements/ Unique
// Numbers 2
void PrintNonRepeated(uint8_t *arr, uint8_t size)
{
	bool IsAvailale = false;
	uint8_t count = 0;
	for (uint8_t i = 0; i < size; i++) {
		/* code */
		for (uint8_t j = 0; j < size; j++) {
			/* code */
            if (*(arr+j) == *(arr+i))
            {
                /* code */
				count++;
			}
		}
        if (count > 1)
        {
            /* code */
			printf("%d ", *(arr + i));
		}
		count = 0;
	}
}


// Q 13.) Convert Uppercase to LowerCase:
char UpperToLowerCase(char In) { return (In + 32); }
// Q 14.). Convert Lowercase to Uppercase
char LowerToUpperCase(char In)
{
    if ((In >= 'a')&& (In <= 'z'))
    {
        /* code */
		return (In - 32);
	}
}
// Q 15.). Invert Alphabet’s Case
// Q 16.). Find Letter Position in alphabet

// Q 17. ) Given a set of numbers where all elements occur an even number of times except
// one number, find the odd occurring number.

// Q 18.) Swap two numbers using Bit manipulation:
void Swap(uint32_t *a, uint32_t *b) 
{ 
    *a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
// Q 19. ) Calculate XOR from 1 to n
uint32_t XorOfN(uint8_t n)
{
	uint32_t result = 1;
	for (uint8_t i = 1; i < n; i++) {
		/* code */
		result ^= i;
	}
	return result;
}
/// @brief /////
/// @param n
/// @return
// n = 4k + r,  where r = 0,1,2,3
// uint32_t XorOfN(uint32_t n) {
// 	switch (n % 4) {
// 	case 0:
// 		return n;
// 	case 1:
// 		return 1;
// 	case 2:
// 		return n + 1;
// 	case 3:
// 		return 0;
// 	}
// }
// Q 20.) Find XOR of numbers from the range [L,R]
uint32_t XorOfRange(uint32_t Start, uint32_t End)
{
	uint32_t Range = End - Start + 1;

    
}
// Q 21.) Check whether the number is even or not


// Q 22.) Find the XOR of the XOR of all subsets of an array:
// Q 23.) Count Number of bits to be flipped to convert A to B:
int BitsToBeFlipped(uint32_t A, uint32_t B)
{
    // uint32_t
}


// Q 24.) Find missing number in an array:
// Q 25. ) Print the binary representation of decimal number:
// Q 26.) Reverse the bits of a number:
// Q 27.) Swap the ith and Jth bit.
// Q 28.) Swap all even and odd bits
// Q 29.) Copy set bits in a range, toggle set bits in a range:
// Q 30.) Divide two integers without using Multiplication, Division and mod operator:
// Q 31.) One unique rest thrice
// Q 32.) Reduce a Number to 1
// Q 33.) Detect if two integers have opposite sign
// Q 34.) Add 1 to an integer
// Q 35.) Find Xor of a number without using XOR operator
// Q 36.) Determine if two integers are equal without using comparison and arithmetic
// operators
// Q 37.) Find minimum or maximum of two integers without using branching
// Q 38.) Find missing and repeating number / Set mismatch:
// Q 39.) Maximum Product of Word Lengths
// Q 40.) Check if a String Contains all binary codes of size k
// Q 41.) Find the Duplicate Number

int IsPalindrom(const char *ptr)
{

	int strlength = strlen(ptr);

    for (int i = 0; i <= strlength / 2; i++)
    {
        if ((*(ptr + i)) != (*(ptr + strlength - 1 - i)))
            return false;
    }
    return true;
}

int NoOfOnesCount(int in)
{
    int count = 0;
    while (in)
    {
        in &= (in - 1);
        count++;
    }

    // for (size_t i = 0; i < __UINT32_MAX__; i++)
    // {
    //     /* code */
    //     if ((in & 0x1) == 0x1)
    //         count++;
    //     in = in >> 1;
    // }
    return count;
}

int facorial(int n)
{
    if (n < 2)
    {
        return 1;
    }
    return (facorial(n - 1) * n);
}

bool IsPowerOf2(int n)
{
    
    return !((n - 1) & n);
}

void FileReadWrite(void)
{
    FILE *fptr;
    char datatowrote[] = "fagadmjdajda";

    fptr = fopen("example.txt", "w");

    fprintf(fptr, "%s", datatowrote);

    fclose(fptr);

}

//////////////////////////LINK LIST /////////////////////
struct LinkList {
	int data;
	struct LinkList* NextNode;
}LinkList;

void PrintLinkList(struct LinkList *List)
{
	int count = 0;
	while (List!= NULL) {
		/* code */
		count++;
		printf("Data is:%d and Element is:%d\n", List->data, count);
		List = List->NextNode;
	}
}

void add(int data, struct LinkList *List)
{
    while (List->NextNode != NULL)
    {
        /* code */
		List = List->NextNode;
	}

	struct LinkList* ListElem = malloc(sizeof(LinkList));
	ListElem->data = data;
	ListElem->NextNode = NULL;
	List->NextNode = ListElem;
}

void DelElement(int key,struct LinkList * List)
{
	struct LinkList *temp;
	while (List->data != key) {
		/* code */
		temp = List;
		List = List->NextNode;
	}

    if (List->data != key && List->NextNode == NULL)
    {
        /* code */
		printf("Key not found");
		// return 0;
	}

	temp->NextNode = List->NextNode;


}
// struct LinkList *List = malloc(sizeof(LinkList));
// List->data = 2;
// List->NextNode = NULL;

// // PrintLinkList(List);
// add(55, List);
// add(5, List);
// add(7, List);
// add(8, List);

// PrintLinkList(List);

// DelElement(5, &List);

// printf("Deleting element 5\n");
// PrintLinkList(List);
/////////////////////////////////////////////////////////////////////
//SOrting
void Sort(int *arr)
{
	int count = 10;
	for (size_t i = 0; i < count-1; i++) {
		/* code */
        for (size_t j = 0; j < count-1; j++)
        {
            /* code */
            if (arr[j] > arr[j+1])
            {
                /* code */
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
		}
	}
}

// int arr[10] = {1, 3, 6, 3, 9, 3, 45, 63, 232, 9};

// for (size_t i = 0; i < 10; i++) {
// 	/* code */
// 	printf("%d\n", arr[i]);
// }

// Sort(arr);

// for (size_t i = 0; i < 10; i++) {
// 	/* code */
// 	printf("%d\n", arr[i]);
// }
#define BUFFSIZE 10
////////Ring Buffer/////////////////
typedef struct RingBuffer{
	uint8_t *buff;
	uint8_t head;
	uint8_t tail;
	// uint8_t count;
	bool full;
	// uint8_t size;
} RingBuffer;

typedef RingBuffer *RbuffHandler;

void RbuffInit(RingBuffer *Rbuffp, uint8_t *buff, uint8_t size) {
	RingBuffer *RbuffPtr = malloc(sizeof(RingBuffer));
	// assert(RingBuffer);

	RbuffPtr->buff = buff;
	RbuffPtr->head = 0;
	RbuffPtr->tail = 0;
	RbuffPtr->size = size;
}

void pushData( RingBuffer * Rbuff, uint16_t data)
{
    if (Rbuff->tail == Rbuff->head)
    {
        /* code */
		printf("R Buffer is full\n");
	}
    else
    {
        /* code */
		Rbuff->buff[Rbuff->tail] = data;
		Rbuff->tail++;
	}
    	
}

void popData( RingBuffer *Rbuff, uint16_t *data)
{
	*data = Rbuff->buff[Rbuff->head] ;
	Rbuff->head++;
}

void printData(RingBuffer *Rbuff)
{
    while (condition)
    {
        /* code */
    }
    
}

// void update



////////============////////////////
#include <stdio.h>

int main() {

	RingBuffer Rbuff = malloc(sizeof(RingBuffer));
	*Rbuff->buff = NULL;
	Rbuff->tail = 0;
	Rbuff->head = 0;

	pushData(Rbuff, 34);

	return 0;
}
