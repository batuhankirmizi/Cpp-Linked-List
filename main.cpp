#include <iostream>
#include "main.h"

using namespace std;

template <class T>
void LList<T>::remove(T data, LList<T>* list) {
	if(data == head->data) { // in case of demand to removal of the first element
		pop_front();
		return;
	}

	node* iterator = head;
	while(iterator->next && iterator->next->data != data) {
		iterator = iterator->next;
	}

	// in case of demand to removal of the last element
	if(iterator->next == tail) {
		pop_back();
		return;
	}

	node* temp = iterator->next;
	iterator->next = temp->next;
	delete temp;
	size--;
}

template <class T>
LList<T>::LList() : head(nullptr), tail(nullptr), size(0) {}

template <class T>
LList<T>::~LList() {
	cout << "...list is being destructed..." << endl;
}

template <class T>
bool LList<T>::is_empty() {
	return head == nullptr; // basically null head means null list
}

template <class T>
bool LList<T>::contains(const T data) {
	if(is_empty()) { // check if the list is empty or not
		return false;
	}

	node* iterator = head;
	while(iterator) {
		if(iterator->data == data) {
			return true;
		}

		iterator = iterator->next;
	}
	return false;
}

template <class T>
void LList<T>::remove(T data) {
	if(is_empty()) { // check if the list is empty
		cerr << "cannot remove any element from an empty list" << endl;
		return;
	}

	if(contains(data)) {
		node* iterator = head;
		while(iterator) {
			if(iterator->data == data) {
				remove(data, this);
				return;
			}

			iterator = iterator->next;
		}
	}

	cerr << "cannot find element in the list" << endl;
}

/**
 * \brief changes the data with n_data
 * \param data data to be changed
 * \param n_data new data
 */
template <class T>
void LList<T>::change(T data, T n_data) {
	if(is_empty()) { // check if the list is empty or not
		cerr << "cannot change element, list is empty" << endl;
		return;
	}

	if(contains(data)) {
		node* iterator = head;
		while(iterator && iterator->data != data) {
			iterator = iterator->next;
		}
		iterator->data = n_data;

		return;
	}

	cerr << "cannot change element, list does not contain such an element" << endl;
}

template <class T>
void LList<T>::push_back(T data) {
	if(!head) { // if first element is null, add data to the beginning
		head = new node;
		head->data = data;
		head->next = nullptr;

		tail = head;

		size++;

		return;
	}

	tail->next = new node;
	tail->next->data = data;
	tail = tail->next;
	tail->next = nullptr;
	size++;
}

template <class T>
void LList<T>::push_front(T data) {
	if(!head) { // check if the head is null
		head = new node;
		head->data = data;
		head->next = nullptr;

		tail = head;

		size++;

		return;
	}

	// if head is not null, allocate a new memory for the new element
	node* n_val = new node;
	n_val->data = data;
	n_val->next = head;

	head = n_val;

	size++;
}

template <class T>
T& LList<T>::pop_back() {
	if(is_empty()) { // check if the list is empty
		cerr << "cannot remove any element. list is empty" << endl;
		T* t = nullptr;
		return *t;
	}

	node* iterator = head;
	while(iterator->next->next) {
		iterator = iterator->next;
	}

	T rvalue = iterator->next->data;

	delete iterator->next;
	iterator->next = nullptr;

	tail = iterator;

	size--;
	return rvalue;
}

template <class T>
T& LList<T>::pop_front() {
	if(is_empty()) { // check if the list is empty
		cerr << "cannot remove any element. list is empty" << endl;
		T* t = nullptr;
		return *t;
	}

	T rvalue = head->data;

	node* temp = head;
	head = head->next;
	delete temp;

	size--;

	return rvalue;
}

template <class T>
void LList<T>::print() {
	cout << *this;
}

template <class T>
T LList<T>::front() {
	return head->data;
}

template <class T>
int LList<T>::get_size() const {
	return size;
}

template <class T>
T LList<T>::back() {
	return tail->data;
}

// consists of some test cases
int main() {
	LList<int>* list = new LList<int>;
	for(int i = 0; i < 5; ++i) {
		list->push_front((i + 1) * (i + 1));
	}
	list->print();
	for(int i = 0; i < 5; ++i) {
		list->push_back((i + 1) * 10);
	}
	list->print();

	list->pop_back();
	list->pop_back();
	list->pop_back();

	list->print();

	list->pop_front();
	list->pop_front();
	list->pop_front();

	list->print();

	list->remove(20);

	list->print();

	list->change(121, 10);
	list->change(4, 25);
	list->change(1, 16);
	list->change(10, 9);

	list->print();

	LList<int>* list_2 = new LList<int>();
	for (int i = 5; i < 10; ++i) {
		list_2->push_front(i * i);
	}

	list_2->print();

	LList<int> list_3 = *list + *list_2;
	list_3.print();

	list_3 += *list;
	list_3.print();

	delete list;
	delete list_2;

	system("pause");

	return 0;
}
// What was to be demonstrated
