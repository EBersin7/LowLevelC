/* 
 * File: Assignment1_Code
 * Author: Edward Bersin
 * Created on August 30, 2015, 4:16 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define LEN_A 10

void print_array(int[], int);
void reverse(int[], int);
double average(int[], int);
void insert(int[], int, int, int);
int less_than_average(int[], int);
void rotate_right(int[], int, int);
void array_copy(int[], int[], int);
void initialize(int[], int, int);
void evens_on_left(int[], int);
int find(int A[], int len, int x);
int findLast(int A[], int len, int x);
int secondLargest(int A[], int length);

int main(int argc, char **argv) {

    int A[] = {9, 21, 321, 117, 27, 64, 13, 9, 12, 208};
    int B[LEN_A + 1];
    int newValue = 505;

    printf("A[] is:\n");
    print_array(A, LEN_A);
    printf("\n");

    initialize(B, LEN_A + 1, 0);
    printf("B[] is:\n");
    print_array(B, LEN_A + 1);

    array_copy(B, A, LEN_A);
    printf("but now it's:\n");
    print_array(B, LEN_A + 1);
    printf("\n");

    insert(B, newValue, 0, LEN_A);
    printf("and after inserting %d at the beginning it's:\n", newValue);
    print_array(B, LEN_A + 1);
    printf("\n");

    printf("The average of A[] is %f\n", average(A, LEN_A));
    printf("There are %d items in A[] less than this.\n", less_than_average(A, LEN_A));
    printf("\n");

    reverse(A, LEN_A);
    printf("After reversing A[], it now reads:\n");
    print_array(A, LEN_A);
    printf("\n");

    rotate_right(A, LEN_A, 3);
    printf("Next, rotating the array to the right %d spaces yields:\n", 3);
    print_array(A, LEN_A);
    printf("\n");

    evens_on_left(A, LEN_A);
    printf("Finally, separating the evens from the odds presents:\n");
    print_array(A, LEN_A);
    printf("\n");

    printf("The index of the first occurrence of %d is %d.\n", 9, find(A, LEN_A, 9));
    printf("The index of the last occurrence of %d is %d.\n", 9, findLast(A, LEN_A, 9));
    printf("\n");

    printf("The second largest value is %d.\n", secondLargest(A, LEN_A));

    return 0;
}

/* prints A[] inside parentheses with each value separated
   by commas to stdout (which will be the screen)*/
void print_array(int A[], int length) {
    
    printf("(");
    for (int i = 0; i < length; i++) {
        printf("%d, ", A[i]);
    }
    printf(")\n");
}

/* returns the average of the items in A[] */
double average(int A[], int length) {
    
    int sum = 0;
    double average = 0;

    for (int i = 0; i < length; i++) {
        sum += A[i];
    }

    average = (double) sum / (double) length;

    return average;
}

/* returns the number of items in A that are less than the
   average of the items in A */
int less_than_average(int A[], int length) {
    
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (A[i] < average(A, length)) {
            count++;
        }
    }

    return count;
}

/* Reverses the values in A[].  For example, if before the function,
   A[] contained [1,2,3,4,5], after the function, A[] contains
   [5,4,3,2,1] */
void reverse(int A[], int length) {
    
    for (int i = 0; i < length / 2; i++) {
        int temp = A[i];
        A[i] = A[length - 1 - i];
        A[length - 1 - i] = temp;
    }
}

/* returns the second largest item in A[], or -1 if length < 2 */
int secondLargest(int A[], int length) {

    if (length < 2) {
        return -1;
    } else {
        int largestValue = 0;
        int secondLargestValue = 0;

        for (int i = 0; i < length; i++) {
            if (A[i] > largestValue) {
                secondLargestValue = largestValue;

                largestValue = A[i];
            } else if (A[i] > secondLargestValue) {
                secondLargestValue = A[i];
            }
        }

        return secondLargestValue;
    }
}

/* rotates the values in the array numPlaces to the right 
   for example, if A[] is initially 10,20,30,40,50, and numPlaces=2
   after the function finishes, A[] would be 40,50,10,20,30 */
void rotate_right(int A[], int length, int numPlaces) {
    
    int B[length];
    array_copy(B, A, length);

    for (int i = 0, j = numPlaces; i < length; i++) {
        if (j == length) {
            j = 0;
            A[j] = B[i];
            j++;
        } else {
            A[j] = B[i];
            j++;
        }
    }
}

/* inserts the value n in A[] at the given index and shifts
   all other values up one position.  A[] contains length items.
   It is up to the caller to make sure that there is enough space
   in A[] to accomodate the new item, and that the index is valid. */
void insert(int A[], int n, int index, int length) {
    
    int B[length];
    array_copy(B, A, length);

    A[index] = n;
    for (int i = 0, j = 1; i < length; i++) {
        A[j] = B[i];
        j++;
    }
}

/* copies the first numItems from S to D. */
void array_copy(int D[], int S[], int numItems) {

    for (int i = 0; i < numItems; i++) {
        D[i] = S[i];
    }

}

/* sets the first len elements of A to initialValue */
void initialize(int A[], int len, int initialValue) {
    
    for (int i = 0; i < len; i++) {
        A[i] = initialValue;
    }
}

/* shuffles the values in A so that the even values
   are all to the left of the odd values */
void evens_on_left(int A[], int len) {
    
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < len; i++) {
        if (A[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    int evens[evenCount];
    int odds[oddCount];

    for (int i = 0, j = 0, k = 0; i < len; i++) {
        if (A[i] % 2 == 0) {
            evens[j] = A[i];
            j++;
        } else {
            odds[k] = A[i];
            k++;
        }
    }

    for (int i = 0, j = 0, k = 0; i < len; i++) {
        if (j < evenCount) {
            A[i] = evens[j];
            j++;
        } else {
            A[i] = odds[k];
            k++;
        }
    }
}

/* returns the index of the first occurrence of
   x in A[] or -1 if x doesn't exist in A[] */
int find(int A[], int len, int x) {

    int indexOf = 0;

    while (indexOf < len) {
        if (A[indexOf] == x) {
            return indexOf;
        }
        indexOf++;
    }

    return -1;
}

/* returns the index of the last occurrence of
   x in A[] or -1 if x doesn't exist in A[] */
int findLast(int A[], int len, int x) {

    int indexOf = len - 1;

    while (indexOf > 0) {
        if (A[indexOf] == x) {
            return indexOf;
        }
        indexOf--;
    }

    return -1;
}

