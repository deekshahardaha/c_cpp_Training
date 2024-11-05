
#include <iostream>

using namespace std;

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printarr(int arr[],int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
        arr[i]+=2;
    }
    cout<<endl;
}

void printarr2(int* arr,int n){
    for (int i = 0; i < n; i++) {
        cout << arr[i]<<endl;
        arr[i]+=2;
    }
    cout<<endl;
}

void myFunc()
{
  cout << "Inside myFunc" << endl;
}

int main()
{

    // int a1[4] = {4, 5, 6, 7};
    // printarr(a1,4);
    // printarr2(a1,4);
    // for (int i = 0; i < 4; i++) {
    //     cout << a1[i] << endl;
    // }
    
// Feature	malloc	calloc
// Memory Initialization	Uninitialized (garbage values)	Initialized to zero
// Number of Parameters	1 (total size in bytes)	2 (number of elements, size of each)
// Use Case	General-purpose allocation	Allocation for arrays with zero-initialization

    // int *p1 = a1;
    // cout<<*p1<<endl;
    // p1++;
    // cout<<*p1<<endl;
    // int ar[2][2] = {{1,2},{3,4}};

    // int *arr = ar[0];
    // cout<<*arr<<endl;
    // for (int i = 0; i < 2; i++) {
    //     // Traverse columns of 2D matrix
    //     for (int j = 0; j < 2; j++) {
    //         // Print the element
    //         printf("%d ", *((arr + i * 2) + j));
    //     }
    //     printf("\n");
    // }

    
    // ptr1++;
    // cout<<*ptr1<<endl;
    // ptr1++;
    // cout<<*ptr1<<endl;
    // for (int i=0;i<2;i++){
    //     for (int j=0;j<2;j++){
    //     cout<<&arr[i][j]<<" " <<arr[i][j]<<endl;
    //     }
    // }
    // cout<<*((ptr1+0)+2)<<endl;
    // cout<<((ptr1+1)+2)<<endl;

    // int a = 5;
    // int *ptr=&a;

    // Increment/Decrement of pointers by the number equal to the size of the data type for which it is a pointer.
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;
    // cout<<--ptr<<endl;
    // cout<<*ptr<<endl; // giving garbage value.

    // Addition/subtraction of Integer to Pointer: the int value is first multiplied by the size of the data type and then added/subtracted to the pointer.
    // cout<<ptr<<endl;
    // ptr+=4;
    // cout<<ptr<<endl; //the output will be the address after adding int*4 in the ptr.
    // ptr-=2;
    // cout<<ptr<<endl;

    // The subtraction of two pointers is possible only when they have the same data type. The result is calculating the difference between the addresses of the two pointers and calculating how many bits of data it is according to the pointer data type.
    // int b = 7868876;
    // int *p3 = a1;
    // int *p4= &a1[0];
    // int *p1 = &a;
    // int *p2 = &b;
    // cout << p1 << " " << p2 << endl; // ef0,eec
    // cout << p2 - p1 << endl;         // -1
    // cout << sizeof(p3) << endl;      // 4
    // cout << p3 << endl;
    // cout << p1 - p3 << endl;    //-1

    // cout<<((p1==p2) ? 1:0)<<endl;  // 0
    // cout<<((p3==p4) ? 1:0)<<endl; //1

    // int x = 10, y = 20;
    // swap(&x, &y);
    // printf("%d %d\n", x, y);


    #ifdef NDEBUG
    cout << "Inside DEBUG"<<endl;
    #endif
    // int a[3] = {1, 2, 3};

    // int* p = a;

    // cout << p << " " << *p << endl;
    // ++p;
    // cout << p << " " << *p << endl;


    int a2[3][3] = { {1, 2, 3}, { 11, 22, 33 }, { 17, 28, 39 } };
    // int a2[3][3][2] = { {{1, 2}, { 3, 4}, { 5, 6}},{{11, 22}, { 33, 44}, { 55, 66}},{{101, 102}, { 103, 104 }, { 105, 106 } }};
    cout<<&a2[1]<<endl;
    // cout << a2[2][2][1] << endl;     //*(*(*(a2 + 2) + 2) + 1)
    // int* p1 = a2[0];
    // cout<<*p1<<endl;
    // cout << a2[2][1] << endl;
    // cout << *(*(*(a2 + 2) + 2)+1) << endl;

    // int a[]={1,2,3};
    // int a[2][2] = { {1,2},{3,4} };
    // int* p = a+2;
    // cout<<*p<<endl;


    int(*p) = a2[0];

    // cout <<*(*(p+2)+2);


    return 0;
}