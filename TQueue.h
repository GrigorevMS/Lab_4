#pragma once
#include<iostream>
using namespace std;
#include"TItem.h"
template<class Type>
class TQueue {
private:
	TItem<Type>* pFirst;    /// ��������� �� ������ ������� �������
	TItem<Type>* pLast;    /// ��������� �� ��������� ������� �������
public:
	TQueue();    /// �����������
	~TQueue();    /// ����������
	bool isEmpty();    /// �������� �� �������
	void Put(Type temp);    /// ��������� ������� � �������
	Type Get();    /// ����� �������� �� �������
	void printQueue();    /// ������� ������� �� �������
};

/// �����������_____________________________
template<class Type>
TQueue<Type>::TQueue() {
	pFirst = nullptr;
	pLast = nullptr;
}

/// ����������_____________________________
template<class Type>
TQueue<Type>::~TQueue() {
	pFirst = nullptr;
	pLast = nullptr;
}

/// �������� �� �������_____________________________
template<class Type>
bool TQueue<Type>::isEmpty() {
	if (pFirst == nullptr)
		return true;
	return false;
}

/// ��������� ������� � �������_____________________________
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

/// ����� �������� �� �������_____________________________
template<class Type>
Type TQueue<Type>::Get() {
	Type temp = (*pFirst).GetValue();
	TItem<Type>* next_copy = (*pFirst).GetNext();
	delete pFirst;
	pFirst = next_copy;
	return temp;
}

/// ������� ������� �� �������_____________________________
template<class Type>
void TQueue<Type>::printQueue() {
	TItem<Type>* next_copy = pFirst;
	while (next_copy != nullptr) {
		cout << (*next_copy).GetValue() << "  ";
		next_copy = (*next_copy).GetNext();
	}
	cout << endl;
}