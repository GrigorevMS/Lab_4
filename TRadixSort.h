#pragma once
#include"TQueue.h"
#include<iostream>
using namespace std;

/// ����������� ����������_____________________________
template<class Type>
class TRadixSort {
private:
	Type* arrValue;    /// ������ ����������� ��������
	int arrCount;    /// ���-�� ����������� ��������
	int valCount;    /// ������������ �������� �������
	int digCount;    /// ������������ ���-�� ��������
	TQueue<Type>** queueArr;    /// ������ �������� ��� ������������� ��������
public:
	TRadixSort(Type* arrValue_copy, Type arrCount_copy, Type valCount_copy);    /// �����������
	~TRadixSort();    /// ����������
	void doRadixSort();    /// ��������� ����������� ����������
public:
	int setDigCount();    /// ���������� ������������ ���-�� ��������
	int getQueueInd(Type Value, int pos);    /// ������ ������ � �������
	void printArr();    /// ������� ������
	void printQue();    /// ������� ��������� ��������
};

/// �����������_____________________________
template<class Type>
TRadixSort<Type>::TRadixSort(Type* arrValue_copy, Type arrCount_copy, Type valCount_copy) {
	arrValue = arrValue_copy;
	arrCount = arrCount_copy;
	valCount = valCount_copy;
	digCount = setDigCount();
	queueArr = new TQueue<Type>*[valCount_copy + 1];
	for (int i = 0; i < valCount_copy + 1; i++)
		queueArr[i] = new TQueue<Type>();
}

/// ����������_____________________________
template<class Type>
TRadixSort<Type>::~TRadixSort() {
	arrValue = nullptr;
	for (int i = 0; i < valCount; i++) {
		delete queueArr[i];
	}
	delete[] queueArr;
	arrCount = 0;
	valCount = 0;
}

/// ���������� ������������ ���-�� ��������_____________________________
template<class Type>
int TRadixSort<Type>::setDigCount() {
	int max = 0;
	for (int i = 0; i < arrCount; i++) {
		int temp_count = 0;
		Type temp = arrValue[i];
		while (temp != 0) {
			temp = temp / 10;
			temp_count++;
		}
		if (temp_count > max)
			max = temp_count;
	}
	return max;
}

/// ������ ������ �������_____________________________
template<class Type>
int TRadixSort<Type>::getQueueInd(Type Value, int pos) {
	Type length = 0;
	Type* arr = new Type [digCount];
	Type temp;
	while (Value != 0) {
		temp = Value % 10;
		Value = Value / 10;
		arr[length] = temp;
		length++;
	}
	temp = arr[pos];
	delete[]arr;
	if (pos >= length)
		return 0;
	return temp; /// ���� pos �������� ��� ������ �������� � ��������
}

/// ������� ������_____________________________
template<class Type>
void TRadixSort<Type>::printArr() {
	cout << "�������� ������:" << endl;
	for (int i = 0; i < arrCount; i++) {
		cout << arrValue[i] << " ";
	}
	cout << endl;
}

/// ������� ��������� ��������_____________________________
template<class Type>
void TRadixSort<Type>::printQue() {
	for (int i = 0; i < valCount + 1; i++) {
		if (!(*(queueArr[i])).isEmpty()) {
			cout << i << ")    ";
			(*(queueArr[i])).printQueue();
		}
	}
}

/// ��������� ����������� ����������_____________________________
template<class Type>
void TRadixSort<Type>::doRadixSort() {
	for (int i = 0; i < digCount; i++) {
		cout << "��� " << i + 1 << endl;
		for (int j = 0; j < arrCount; j++) {
			int kek = getQueueInd(arrValue[j], i);

			queueArr[kek]->Put(arrValue[j]);
		}
		printArr();
		printQue();
		int ind = 0;
		for (int j = 0; j < valCount + 1; j++) {
			while (!(*(queueArr[j])).isEmpty()) {
				//arrValue[ind] = queueArr[j]->Get();
				arrValue[ind] = queueArr[j]->Get();
				ind++;
			}
		}
		cout << "==================================================" << endl;
	}
}