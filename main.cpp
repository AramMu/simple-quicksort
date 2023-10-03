#include <iostream>
#include <cstdlib>
#include <random>
#include <algorithm>
#include <time.h>

//void insertionSort(int *arr, int left, int right);

void quickSort(int *arr, int left, int right);

void printArr(int *arr, int size);



int main()
{
    int size = 0;
    int *arr = 0;

    std::cout << "Enter size: ";
    std::cin >> size;

    arr = new int [size];

    for( int i = 0; i < size; ++i){
        arr[ i ] =  rand() % 50;
    }

    int leftElement = 0;
    int rightElement = size - 1;

    std::cout << std::endl;

    printArr(arr, size);

    quickSort(arr, leftElement, rightElement);          // Quick function

    printArr(arr, size);

    return 0;
}

//void insertionSort(int *arr, int left, int right)
//{
//    int j = 0;
//    for( int i = left; i <= right; ++i )
//    {
//        j = i;
//           while( j > 0 && arr[ j ] < arr[ j - 1 ] )
//            {
//               std::swap(arr[ j ], arr[ j - 1]);
//               --j;
//            }
//    }

//}

void quickSort(int *arr, int left, int right)
{
    struct Range {
        int left;
        int right;
    };
    std::vector <Range> ranges;
    ranges.push_back({left, right});
    while (!ranges.empty()) {
        Range r = ranges.back();
        ranges.pop_back();
        if (r.right <= r.left) {
            continue;
        }
        if (r.right - r.left <= 32) {
            //Insert sort
            //int j = 0;
            for( int i = left+1; i <= right; ++i )
            {
                int j = i-1;
                int temp = arr[i];
                while( j >= left && arr[ j ] > temp )
                {
                     //std::swap(arr[ j ], arr[ j - 1]);
                    arr[j+1] = arr[j];
                    --j;
                }
                arr[j+1] = temp;
            }
        } else {
            //Quick sort
            int ind = r.left;
            for (int i = r.left; i <= r.right; ++i) {
                if (arr[i] <= arr[r.right]) {
                    std::swap (arr[ind], arr[i]);
                    ind++;
                }
            }

            ranges.push_back({r.left, ind-2});
            ranges.push_back({ind, r.right});
        }
    }
    /*
    int l = left;
    int r = right;
    int temp = 0;

    int supportElement = arr[(left + right ) / 2];



     while(l <= r)
     {
        while(arr[l] < supportElement){
            ++l;
        }

        while(arr[r] > supportElement){
            --r;
        }

        if( l <= r )
        {
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;

            ++l;
            --r;
        }
     }

      while( arr[ l ] == arr[r]) {
          ++l;
          --r;
      }

     if(left < r)
     {
        if( r - left <= 32 )
        {
         insertionSort(arr, left, r);
        }
         else if(r - left > 32)
        {
            quickSort(arr, left, r);
        }
     }

     if(l < right)
     {
        if(right - l <= 32)
        {
            insertionSort(arr, l, right);
        }
        else if(right - l > 32)
        {
            quickSort(arr, l, right);
        }
     }
     */
}

void printArr(int *arr, int size)
{
    for( int i = 0; i < size; ++i )
    {
        std::cout << arr[ i ] << ' ';
    }
    std::cout << std::endl;
}
