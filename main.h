#pragma once
#ifndef MAIN_H_
#define MAIN_H_

template <class T>
class LList {
	typedef struct n {
		T data;
		n* next;
	} node; // data structure

	node* head; // first element of the list
	node* tail; // last element of the list

	int size; // size of the list

	void remove(T, LList<T>*); // abstracting
public:
	LList(); // empty constructor
	~LList(); // destructor

	bool is_empty(); // check if the list is empty or not
	bool contains(const T); // check if the list contains this element or not
	void remove(T); // remove element by data
	//void remove(int pos); // remove element by position *overloaded*
	void change(T, T); // change the element data
	void push_back(T); // adds the data element at the end of list
	void push_front(T); // adds the data element at the beginning of list
	T& pop_back(); // removes the last element of the list and returns it
	T& pop_front(); // removes the first element of the list and returns it
	T back(); // returns the last element in the list
	T front(); // returns the first element in the list
	int get_size() const;
	void print(); // print the whole list
	
	LList<T> operator+=(const LList<T>& list) {
		*this = *this + list;
		return *this;
	}
	friend LList<T>& operator+(const LList<T>& list_1, const LList<T>& list_2) {
		LList<T>* list = new LList<T>();

		node* iterator = list_1.head;
		while(iterator) {
			list->push_back(iterator->data);
			iterator = iterator->next;
		}

		iterator = list_2.head;
		while(iterator) {
			list->push_back(iterator->data);
			iterator = iterator->next;
		}

		delete iterator;
		return *list;
	}
	friend std::ostream& operator<<(std::ostream& os, const LList<T>& list) {
		if(!list.head) { // check if the list is empty or not
			std::cerr << "cannot print an empty list" << std::endl;
			return os;
		}

		node* iterator = list.head;
		while(iterator) {
			os << iterator->data;

			if(iterator->next) {
				os << ", ";
			}

			iterator = iterator->next;
		}
		os << std::endl;

		delete iterator;
		return os;
	}
};

#endif
