#pragma once
#include<iostream>
#include<limits>
#include"LinkedList.h"


using namespace std;

class Queue_LinkedList :public Linked_list {

public:

	void enQueue(int element, string name, int phoneNumber) {
		Node* temp = new Node(element, name, phoneNumber);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			insertLast(element, name, phoneNumber);
		}
	}
	int deQueue() {
		if (head == NULL) {
			cout << "\tEmpty" << endl;
			return INT_MIN;
		}
		else {
			int ret_val = head->element;
			deleteFirst();
			return ret_val;
		}
	}
};
