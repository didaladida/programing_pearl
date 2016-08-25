#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstdlib>
#include<unordered_set>
#include<bitset>
#include<algorithm>
#include<ctime>
using namespace std;
#define START start=clock();
#define END  finish=clock();totaltime=(double)(finish-start)/CLOCKS_PER_SEC;cout<<"\n此程序的运行时间为"<<totaltime<<"秒！\n"<<endl;
// generate a random number between i and k,
// both i and k are inclusive.
int randint(int i, int k)
{
	if (i > k)
	{
		int t = i; i = k; k = t; // swap
	}
	int ret = i + rand() % (k - i + 1);
	return ret;
}

// take m samples to result from input of n items.
bool reservoir_sampling(const int *input, int n, int *result, int m)
{
	srand(time(NULL));
	if (n < m || input == NULL || result == NULL)
		return false;
	for (int i = 0; i != m; ++i)
		result[i] = input[i];

	for (int i = m; i != n; ++i)
	{
		int j = randint(0, i);
		if (j < m)
			result[j] = input[i];
	}
	return true;
}
int myrandint(int l,int u){
    return l+rand()%(u-l+1);
}
int bigrand(){
    //srand(time(NULL));
    return rand()*32767+rand();
}
int *gene_m_n_v2(int n,int m){
    srand(time(NULL));
    int *arr=new int[m];
    int idx=0;
    for(int i=0;i<n;i++){
        if(bigrand()%(n-i)<m){
            arr[idx++]=i;
            m--;
        }
    }
    return arr;
}

int* gene_m_from_n(int n,int m){
    srand(time(NULL));
    unordered_set<int> res;
    while(res.size()<m){
        res.insert(bigrand()%n);
    }
    int *arr=new int[res.size()];
    int idx=0;
    for(int x:res){
        arr[idx++]=x;
    }
    return arr;
}
/**
*使用qsort排序
*/
int mycmp(const void * p1,const void *p2){
    return *((int*)p1)-*((int*)p2);
}

/**
*bit排序
*/
void test_bit_sort(int *arr,int m){
    bitset<10000005> foo;
    for(int i=0;i<m;++i){
        foo.set(arr[i],1);
    }
    int idx=0;
    for(int i=0;i<10000005;i++){
        if(foo[i])
            arr[idx++]=i;
    }
}
/**
*
*/
void test_stl_sort(int *arr,int m){
    sort(arr,arr+m);
}
int main()
{
    clock_t start,finish;
    double totaltime;
    srand(time(NULL));
    START
    int *arr=gene_m_from_n(10000000,1000000);
    END
    delete[] arr;
    START
    arr=gene_m_n_v2(10000000,1000000);
    END
    START
    arr=gene_m_from_n(10000000,1000000);
    END
    //qsort
    START
    cout<<"---qsort---"<<endl;
    qsort(arr,1000000,sizeof(int),mycmp);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    END
    //bitsort

    cout<<"----bitsort----"<<endl;

    arr=gene_m_from_n(10000000,1000000);

    START
    test_bit_sort(arr,1000000);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    END

    cout<<"----stl_sort-----"<<endl;
    arr=gene_m_from_n(10000000,1000000);
    START
    test_stl_sort(arr,1000000);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    END
    return 0;
}
