#pragma once

/// Элемент списка
template<class Type>
class TItem {
private:
	Type Value;    /// Значение
	TItem* Next;    /// Указатель на следующий элемент
public:
	TItem(Type value_copy = 0);    /// Конструктор 
	~TItem();    /// Деструктор
	Type GetValue();    /// Получить значение
	void SetValue(Type value_copy);    /// Установить значение
	TItem * GetNext();    /// Получить указатель на следующий элемент
	void SetNext(TItem* next_copy);    /// Установить указатель на следующий элемент
};

/// Конструктор_____________________________
template<class Type>
TItem<Type>::TItem(Type value_copy) {
	Value = value_copy;
	Next = nullptr;
}

/// Деструктор_____________________________
template<class Type>
TItem<Type>::~TItem() {
	Value = 0;
	Next = nullptr;
}

/// Получить значение_____________________________
template<class Type>
Type TItem<Type>::GetValue() {
	return Value;
}

/// Установить значение_____________________________
template<class Type>
void TItem<Type>::SetValue(Type value_copy) {
	Value = value_copy;
}

/// Получить указатель на следующий элемент_____________________________
template<class Type>
TItem<Type>* TItem<Type>::GetNext() {
	return Next;
}

/// Установить указатель на следующий элемент_____________________________
template<class Type>
void TItem<Type>::SetNext(TItem* next_copy) {
	Next = next_copy;
}