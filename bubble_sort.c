#include <stdio.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void print_array(int arr[], int n)
{
    for (int k = 0; k - n; k++)
        printf("%d ", arr[k]);
    printf("\n");
}

void bubble_sort(int *arr, int sz_arr)
{
    for (int j = 0; j < sz_arr - 1; j++)
    {
        for(int i = 0; i < sz_arr - 1 - j; i++)
        {
            if(*(arr+i) > *(arr + i + 1))
                swap(arr + i, arr + i + 1);
            printf("%d ", i);

            if(sz_arr - 1 - j == 1)
                return;
        }
        printf("\nj = %d\n", j);
    }
}

int main()
{
    int arr[] = {4, 9, 2, 1, 7, 8};
    int n = sizeof(arr)/ sizeof(int);

    printf("Array before: \n");
    print_array(arr, n);

    printf("Bubble sort the hell out of them: \n");
    bubble_sort(arr, n);

    printf("Array after: \n");
    print_array(arr, n);
}
