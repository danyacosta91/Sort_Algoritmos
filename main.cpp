#include "Sort.h"
#include <time.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	Sort *_sort = new Sort();
	int n = 10, i = 0, cont = 0;
	clock_t t;

	do{
		cout << "\n------------------- n: " << n << " ------------------" << endl;
		do{
			_sort->llenarArreglo();
			t = clock();
			_sort->bubbleSort( n );
			t = clock() - t;
			cout << " ---------- BUBBLE SORT -----------" << endl;
			printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
			//_sort->imprimirArreglo( n );
			i++;
		}while( i < 10 );

		i = 0;

		do{
			_sort->llenarArreglo();
			t = clock();
			_sort->mergeSort( n );
			t = clock() - t;
			cout << "\n ---------- MERGE SORT -----------" << endl;
			printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
			//_sort->imprimirArreglo( n );
			i++;
		}while( i < 10 );

		i = 0;

		do{
			_sort->llenarArreglo();
			t = clock();
			_sort->quickSort( n );
			t = clock() - t;
			cout << "\n ---------- QUICK SORT -----------" << endl;
			printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
			//_sort->imprimirArreglo( n );
			i++;
		}while( i < 10 );

		i = 0;

		do{
			_sort->llenarArreglo();
			t = clock();
			_sort->selectionSort( n );
			t = clock() - t;
			cout << "\n ---------- SELECTION SORT -----------" << endl;
			printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
			//_sort->imprimirArreglo( n );
			i++;
		}while( i < 0 );

		i = 0;

		do{
			_sort->llenarArreglo();
			t = clock();
			_sort->insertionSort( n );
			t = clock() - t;
			cout << "\n ---------- INSERTION SORT -----------" << endl;
			printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
			//_sort->imprimirArreglo( n );
			i++;
		}while( i < 10 );

		i = 0;

		do{
			_sort->llenarArreglo();
			t = clock();
			_sort->radixSort( n );
			t = clock() - t;
			cout << "\n ---------- RADIX SORT -----------" << endl;
			printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
			//_sort->imprimirArreglo( n );
			i++;
		}while( i < 10 );

		i = 0;

		do{
			_sort->llenarArreglo();
			t = clock();
			_sort->heapSort( n );
			t = clock() - t;
			cout << "\n ---------- HEAP SORT -----------" << endl;
			printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
			//_sort->imprimirArreglo( n );
			i++;
		}while( i < 10 );

		i = 0;
		n = n*10;
		cont++;
	}while( cont < 6 );


	free( _sort );
	return 0;
}