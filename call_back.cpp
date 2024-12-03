#include <iostream>

using namespace std;

void myfun(int a)
{
    cout << a << endl;
}

void sqr2(int x)
{
    cout << x * x << endl;
}

bool compare(int x, int y)
{
    return x > y;
}

void callthisfun(int ar[], int size, bool (*fff)(int, int))
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (fff(ar[i], ar[j]))
            {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
}

void anotherfun(int val,void (*fu)(int) ){
	fu(val);
}

int main3()
{
    int ggg = 54;
	anotherfun(ggg,sqr2);
	anotherfun(ggg,myfun);

    auto com = [](int a, int b) -> bool
    {
        return a > b;
    };
    int a[]{4, 5, 3, 56, 5, 23, 5};

    callthisfun(a, 7, com);
    cout<<"after com : ";
	for (int i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int a1[]{4, 5, 3, 56, 5, 23, 5};

	callthisfun(a1, 7, compare);
    cout<<"after compare : ";
	for (int i = 0; i < 7; i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl;

    int a2[]{4, 5, 3, 56, 5, 23, 5};

    callthisfun(a2, 7, [](int a, int b) -> bool
                {
                    return a > b;
                });
    cout<<"after inline : ";
    for (int i = 0; i < 7; i++)
    {
        cout << a2[i] << " ";
    }
    cout << endl;


    return 0;
}