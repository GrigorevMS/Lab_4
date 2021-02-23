#pragma once
#include<iostream>
using namespace std;
#include"TItem.h"
template<class Type>
class TQueue {
private:
	TItem<Type>* pFirst;    /// Указатель на первый элемент очереди
	TItem<Type>* pLast;    /// Указатель на последний элемент очереди
public:
	TQueue();    /// Конструктор
	~TQueue();    /// Детсруктор
	bool isEmpty();    /// Проверка на пустоту
	void Put(Type temp);    /// Поставить элемент в очередь
	Type Get();    /// Взять ээлемент из очереди
	void printQueue();    /// Вывести очередь на консоль
};

/// Конструктор_____________________________
template<class Type>
TQueue<Type>::TQueue() {
	pFirst = nullptr;
	pLast = nullptr;
}

/// Детсруктор_____________________________
template<class Type>
TQueue<Type>::~TQueue() {
	pFirst = nullptr;
	pLast = nullptr;
}

/// Проверка на пустоту_____________________________
template<class Type>
bool TQueue<Type>::isEmpty() {
	if (pFirst == nullptr)
		return true;
	return false;
}

/// Поставить элемент в очередь_____________________________
template<class Type>
void TQueue<Type>::Put(Type temp) {
	TItem<Type>* pNew = new TItem<Type>(temp);
	if (pFirst == nullptr) {
		pFirst = pNew;
		pLast = pNew;
	}
	else {
		(*pLast).SetNext(pNew);
		pLast = pNew;
	}
}

/// Взять ээлемент из очереди_____________________________
template<class Type>
Type TQueue<Type>::Get() {
	Type temp = (*pFirst).GetValue();
	TItem<Type>* next_copy = (*pFirst).GetNext();
	delete pFirst;
	pFirst = next_copy;
	return temp;
}

/// Вывести очередь на консоль_____________________________
template<class Type>
void TQueue<Type>::printQueue() {
	TItem<Type>* next_copy = pFirst;
	while (next_copy != nullptr) {
		cout << (*next_copy).GetValue() << "  ";
		next_copy = (*next_copy).GetNext();
	}
	cout << endl;
}