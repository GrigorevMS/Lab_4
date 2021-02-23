#include"TItem.h"
#include"TQueue.h"
#include"TRadixSort.h"
#include<iostream>
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	TQueue<int> queue;
	cout << "queue = ";
	queue.printQueue();
	cout << queue.isEmpty() << endl;
	queue.Put(10);
	queue.Put(20);
	queue.Put(333);
	cout << "queue = ";
	queue.printQueue();
	cout << queue.Get() << endl;
	cout << "queue = ";
	queue.printQueue();
	cout << queue.isEmpty() << endl;
	queue.Put(228);
	cout << "queue = ";
	queue.printQueue();
	cout << endl << endl;
	cout << "==================================================" << endl;
	int mas[7] = { 1, 10, 7, 53, 8, 47, 311 };
	TRadixSort<int> temp(mas, 7, 9);
	temp.doRadixSort();
	temp.printArr();
	temp.printQue();
	cout << endl << endl;
	cout << "==================================================" << endl;
	int mass[7] = {4301, 102, 127, 45453, 874, 472, 311};
	TRadixSort<int> tempp(mass, 7, 9);
	tempp.doRadixSort();
	tempp.printArr();
	tempp.printQue();
}
