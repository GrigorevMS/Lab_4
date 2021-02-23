#pragma once

/// ������� ������
template<class Type>
class TItem {
private:
	Type Value;    /// ��������
	TItem* Next;    /// ��������� �� ��������� �������
public:
	TItem(Type value_copy = 0);    /// ����������� 
	~TItem();    /// ����������
	Type GetValue();    /// �������� ��������
	void SetValue(Type value_copy);    /// ���������� ��������
	TItem * GetNext();    /// �������� ��������� �� ��������� �������
	void SetNext(TItem* next_copy);    /// ���������� ��������� �� ��������� �������
};

/// �����������_____________________________
template<class Type>
TItem<Type>::TItem(Type value_copy) {
	Value = value_copy;
	Next = nullptr;
}

/// ����������_____________________________
template<class Type>
TItem<Type>::~TItem() {
	Value = 0;
	Next = nullptr;
}

/// �������� ��������_____________________________
template<class Type>
Type TItem<Type>::GetValue() {
	return Value;
}

/// ���������� ��������_____________________________
template<class Type>
void TItem<Type>::SetValue(Type value_copy) {
	Value = value_copy;
}

/// �������� ��������� �� ��������� �������_____________________________
template<class Type>
TItem<Type>* TItem<Type>::GetNext() {
	return Next;
}

/// ���������� ��������� �� ��������� �������_____________________________
template<class Type>
void TItem<Type>::SetNext(TItem* next_copy) {
	Next = next_copy;
}