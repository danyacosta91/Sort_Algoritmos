#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <iostream>
using namespace std;

class Sort
{
private:
	int *A;
	int n;

	void swap( int* T, int i, int j ){
		int tmp = T[i];
		T[i] = T[j];
		T[j] = tmp;
	};

	void quick_sort(int *A,int izq, int der ){
		int i, j, x; 
		i = izq; 
		j = der; 
		x = A[(izq + der)/2]; 
	    do{ 
	        while( (A[i] < x) && (j <= der) )
	            i++;
	 
	        while( (x < A[j]) && (j > izq) )
	            j--;
	 
	        if( i <= j ){
	            swap( A, i, j );
	            i++;
	            j--; 
	        }
	         
	    }while( i <= j ); 
	 
	    if( izq < j ) 
	        quick_sort( A, izq, j ); 
	    if( i < der ) 
	        quick_sort( A, i, der ); 
	};

	void merge_sort( int *A, int tam ){
		if( tam <= 1 )
			return;
		int temp = tam/2;
		int *B = new int[temp];
		int *C = new int[tam-temp];
		for( int i = 0; i < tam; i++ ){
			if( i < temp ){
				B[i] = A[i];
			}else if( i >= temp ){
				C[i-temp] = A[i];
			}
		}

		merge_sort( B, temp );
		merge_sort( C, tam-temp );
		int b = 0, c = 0;

		for( int i = 0; i < tam; i++ ){
			if( b < temp && c < (tam-temp) ){
				if(B[b] < C[c]){
					A[i] = B[b];
					b++;
				}else{
					A[i] = C[c];
					c++;
				}
			}else if( b < temp ){
				A[i] = B[b];
				b++;
			}else{
				A[i] = C[c];
				c++;
			}
		}
	};

	int getMax(int *arr, int n)
	{
	    int max = arr[0];
	    for (int i = 1; i < n; i++){
	        if (arr[i] > max)
	            max = arr[i];
	    }
	    return max;
	};
	
	void countSort(int *arr, int n, int exp)
	{
	    int output[n];
	    int i, count[10] = {0};
	    for (i = 0; i < n; i++)
	        count[(arr[i] / exp) % 10]++;
	    for (i = 1; i < 10; i++)
	        count[i] += count[i - 1];
	    for (i = n - 1; i >= 0; i--){
	        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
	        count[(arr[i] / exp) % 10]--;
	    }
	    for (i = 0; i < n; i++)
	        arr[i] = output[i];
	};
public:
	Sort(){
		n = 1000000;
		A = new int[n];
		llenarArreglo();
	};

	void bubbleSort( int tam ){
		for( int i = tam-1; i >= 0; i-- ){
			for( int j = 0; j <= i; j++ ){
				if( A[j] > A[j+1] )
					swap( A, j, j+1 );
			}
		}
	};

	void mergeSort( int tam ){
		merge_sort( A, tam );
	};

	void quickSort( int tam ){
		quick_sort( A, 0, tam );
	};

	void selectionSort( int tam ){
		int min;
		for( int i = 0; i <= (tam-1); i++ ){
			min = i;
			for( int j = i+1; j < tam; j++ ){
				if( A[min] > A[j] )
					min = j;
			}
			swap( A, min, i );
		}
	};

	void insertionSort( int tam ){
		int i, j;
		for( i = 1; i < tam; i++ ) {
			j = i;
			while( j > 0 && A[j-1] > A[j] ){
				swap( A, j-1, j );
				j--;
			}
		}
	};

	void heapSort( int tam ){
		int item, j;
		for(int k = tam; k >= 0; k-- ){
	        for(int i = 1; i <= k; i++ ){
	            item = A[i];
	            j = i/2;
	            while( j > 0 && A[j] < item ){
	                A[i] = A[j];
	                i = j;
	                j = j/2;
	            }
	            A[i] = item;
	        }
	        swap( A, 1, k );
	    }
	};

	void radixSort( int tam ){
		int m = getMax( A, tam );
		for( int exp = 1; m/exp > 0; exp *= 10 )
			countSort( A, tam, exp );
	};

	void imprimirArreglo( int tam ){
		for (int i = 0; i < tam; ++i){
			if( i < tam-1 )
				cout << A[i] << ", ";
			else if( i == tam-1 )
				cout << A[i] << endl;
		}
	};

	void llenarArreglo(){
		srand(time(NULL));
		for (int i = 0; i < n; ++i)
			A[i] = rand()%n + 1;
	};

	~Sort(){
		free( A );
	};
};

#endif