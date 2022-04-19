#include <QCoreApplication>
#include <QDebug>
#include <windows.h>
#include <iostream>

using namespace std;

void FillArray(int* arr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
 arr[i] = rand();
    }
}

void QuickSort(int* arr, int first, int last)
{
    if (first < last) {
        int left = first;
        int right = last;
        int middle = arr[(left + right) / 2];
        do {
            while (arr[left] < middle) {
 left++;
            }
            while (arr[right] > middle) {
 right--;
            }
            if (left <= right) {
                int temp = arr[left];
 arr[left] = arr[right];
 arr[right] = temp;
 left++;
                right--;
            }
        } while (left < right);
        QuickSort(arr, first, right);
        QuickSort(arr, left, last);
    }
}

void merge(int* array, int l, int m, int r) {
    int i, j, k, nl, nr;

    nl = m - l + 1; nr = r - m;
    int* larr = new int[nl];
    int* rarr = new int[nr];

    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0; j = 0; k = l;

    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        }
        else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {
        array[k] = larr[i];
        i++; k++;
    }
    while (j < nr) {
        array[k] = rarr[j];
        j++; k++;
    }

    delete[] larr;
    delete[] rarr;
}

void mergeSort(int* array, int l, int r) {
    int m;
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }

}


void BubbleSort(int* arr, int Size)
{
    int temp;
    for (int i = 0; i < Size; i++)
    {
        for (int k = 0; k < Size; k++)
        {
            for (int j = 0; j < Size; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

void insertionSort(int* arr,int size)
{
    size++;
    int i, count, j;
    for (i = 1; i < size; i++) {
        count = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > count) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = count;
    }
}

void SelectionSort(int* arr, int size)
{
    size++;
    int i, j, min_ind;

    for (i = 0; i < size - 1; i++)
    {
        min_ind = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min_ind])
                min_ind = j;
        swap(arr[min_ind], arr[i]);
    }
}



void heapify(int* arr, int size, int i)
{
    int largest = i;

    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] > arr[largest])
        largest = l;


    if (r < size && arr[r] > arr[largest])
        largest = r;


    if (largest != i)
    {
        swap(arr[i], arr[largest]);


        heapify(arr, size, largest);
    }

}


void HeapSort(int* arr,int n, int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);


    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void CombSort(int* arr, int size)
{
    int temp, k;
    int s = size;
    long long count = 0;
    while (size > 1) {
        s /= 1.247f;
        if (s < 1) s = 1;
        k = 0;
        for (int i = 0; i + s < size; ++i)
        {
            if (arr[i] / 10 > arr[i + s] / 10)
            {
                temp = arr[i];
                arr[i] = arr[i + s];
                arr[i + s] = temp;
                k = i;
            }
            ++count;
        }
        if (s == 1)
            size = k + 1;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FILE* f1;
      f1= fopen("qsort.dat","w");
      int size = 1000000;

      srand(time(0));

      for (int i=1;i<size;i+=1000)
      {
          int* arr = new int[i];

          FillArray(arr, i);
          long int time = GetTickCount64();
          BubbleSort(arr, i);
          time = (GetTickCount64() - time);
          fprintf(f1, "%d\t%d\n", i, time);

          FillArray(arr, i);
          time = GetTickCount();
          insertionSort(arr, i);
          time = (GetTickCount64() - time);
          fprintf(f1, "%d\t%d\n",i, time);

          FillArray(arr, i);
          time = GetTickCount();
          SelectionSort(arr, i);
          time = (GetTickCount64() - time);
          fprintf(f1, "%d\t%d\n",i, time);

          FillArray(arr,i);time = GetTickCount();
          QuickSort(arr,1,size);
          time= (GetTickCount64() - time);
          fprintf(f1,"%d\t%d\n",i,time);

          FillArray(arr,i);
          time = GetTickCount();
          mergeSort(arr, 0, i-1);
          time= (GetTickCount64() - time);
          fprintf(f1,"%d\t%d\n",i,time);

          FillArray(arr,i);
          time = GetTickCount();
          CombSort(arr,i);
          time= (GetTickCount64() - time);
          fprintf(f1,"%d\t%d\n",i,time);

          FillArray(arr,i);
          time = GetTickCount();
          HeapSort(arr, size/2 ,i);
          time= (GetTickCount64() - time);

          fprintf(f1,"%d\t%d\n",i, time);

          delete [] arr;
          cout<<i<<endl;

      }
      fclose(f1);
    return a.exec();
}
