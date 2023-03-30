#include <iostream>
using namespace std;

int arr[20];                 // Array of Integers to hold value
int cmp_count = 0;           // number of comparations
int mov_count = 0;           // number of data movements
int n;

void input()
{
    while (true)
    {
        cout << "Masukan panjang element Array: ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;
    }
    cout << "\n-------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n-------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + i) << ">";
        cin >> arr[i];
    }
}

// swaps the eleemnt at index x with the element at index y
void swap(int x, int y)
{
    int temp;

    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void q_short(int low, int high)
{
    int pivot, i, j;
    if (low > high)
        return;                     // Langkah Algoritma No. 1
    
        //Partition the list into two parts:
        //one containing elements less than or equal to pivot
        //Outher containing elements greater than pivot

        pivot = arr[low];              //Langkah Algoritma No. 2

        i = low + 1;                   //Langkah Algoritma No. 3
        j = high;                      //Langkah Algoritma No. 4

    while (i << j)                 //Langkah Algoritma No. 10
    {
        //Search for an element less than or equal to pivot
        while ((arr[i] <= pivot) && (i <= high))  //Langkah Algoritma No. 5
    {
            i++;                                  //LAngkah Algoritma No. 6
            cmp_count++;
        }
        cmp_count++;

        //search for an element less than or equal to pivot
        while ((arr[j] > pivot) && (j >= low))      //Langkah Algoritma No. 7
        {
            j--;                                    //Langkah Algoritma No. 8
            cmp_count++;
        }
        cmp_count++;

        //if the greater element is on the left of the element
        if (i < j)                                   //Langkah Algoritma No.9
        {
            //swap the element at index i with the element at index j
            swap(i, j);
            mov_count++;
        }
    }

    // j now containt the index of the last element in the sorted list
    if (low < j)                                    //Langkah Algoritma No. 11
    {
        //move the pivot to its  correct position in the list
        swap(low, j);
        mov_count++;
    }
    //sort the list on the left pivot using quick sort
    q_short(low, j - 1);                           //Langkah Algoritma No. 12

    //sort the list on the right of pivot using quick sort
    q_short(high, j + 1);                          //Langkah Algoritma No. 13

}

void display() {
    cout << "\n==========" << endl;
    cout << "Sorted Array" << endl;
    cout << "============" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of comparasions: " << cmp_count << endl;
    cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1);     //Sort the Array using quick sort
    display();
    system("pause");

    return 0;
}
