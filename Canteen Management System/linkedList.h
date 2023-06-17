#pragma once
#include<iostream>
#include<limits>

//#include"Queues_LinkedList.h"

using namespace std;

class Node {
public:
	//element = registration number
	int element, phoneNumber;
	string name;
	Node* next;
	Node()
	{
		phoneNumber = NULL;
		element = 0;
		next = NULL;
	}
	Node(int val, string nme, int pnber) {
		element = val;
		name = nme;
		phoneNumber = pnber;
		next = NULL;
	}
};

class Linked_list//Customer details input linked list
{
public:
	int position, PreRegisterrPosition;
	Node* head;
	Node* tail;
	int size;

	Linked_list()
	{
		position = NULL;
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void insertFirst(int element, string name, int phoneNumber) {//customerdetails input in the first of the list
		//create the node
		Node* temp = new Node(element, name, phoneNumber);

		if (head == NULL) {
			//list is empty
			head = temp;
			tail = temp;
			size++;
		}
		else {
			//list is non-empty
			temp->next = head;
			head = temp;
			size++;
		}
	}
	void insertLast(int element, string name, int phoneNumber) {//customer details input at last of the list
		//create a node
		Node* temp = new Node(element, name, phoneNumber);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}
	void insertAt(int pos, int element, string name, int phoneNumber) {//customer details input ad specific point

		if (pos<0 || pos>size) {
			cout << "\tInvalid Position" << endl;
			return;
		}
		else if (pos == 0) {
			insertFirst(element, name, phoneNumber);
		}
		else if (pos == size) {
			insertLast(element, name, phoneNumber);
		}
		else {
			Node* temp = new Node(element, name, phoneNumber);
			Node* current = head;

			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}
		size++;
	}
	void deleteFirst() {//detete the first node
		if (head == NULL)
			cout << "\tList is empty" << endl;
		else {
			Node* temp = head;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
			}
			else {
				head = head->next;// head = temp->next;
				delete temp;
			}
			size--;
		}
	}
	void deleteLast() { //delete the last node of customer registation
		if (head == NULL)
			cout << "\tList is Empty" << endl;
		else {
			Node* temp = tail;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
			}
			else {
				Node* current = head;
				for (int i = 0; i < size - 2; i++) {
					current = current->next;
				}
				tail = current;
				tail->next = NULL;
				delete temp;
			}
			size--;
		}
	}
	void deleteAt(int pos) {// detele specific point
		if (pos < 0 || pos >= size)
			cout << "\tInvalid position" << endl;
		else {
			if (pos == 0)
				deleteFirst();
			else if (pos == size - 1)
				deleteLast();
			else {
				Node* current = head;
				for (int i = 0; i < pos - 1; i++) {
					current = current->next;
				}
				Node* temp = current->next;
				//current->next = temp->next; this can also do
				current->next = (current->next)->next;
				delete temp;
			}
			size--;
			
		}
	}
	int search(int element) { //serch customer details in linked list
		Node* current = head;
		for (int i = 0; i < size; i++) {
			if (current->element == element) 
				position = i;
				current = current->next;
		}
		return position;
		cout << endl;
		
	}
	void deleteRegisterDetailsNode(int regNo) {
		Node* current = head;
		Node* previous = NULL;

		while (current != NULL) {
			if (current->element == regNo) {
				if (previous == NULL) {
					head = current->next;
				}
				else {
					previous->next = current->next;
				}
				delete current;
				cout << "\tReg. No of " << regNo << " has been deleted from list." << endl;
				return;
			}
			previous = current;
			current = current->next;
		}
		cout << "\tReg No. " << regNo << " not found in list." << endl;
	}

	bool searchIfRegister(int element) {
		Node* current = head;
		for (int i = 0; i < size; i++) {
			if (current->element == element)
				return true;
			current = current->next;
		}
	}

	void display() {
		Node* current = head;
		if (current == NULL) {
			cout << "\tNon of user registered to the system" << endl;
		}
		else{
			while (current != NULL) {
				cout << "\tRegistation number: " << current->element << "\t |";
				cout << "\tCustomer Name: " << current->name << "\t |";
				cout << "\tContact Number: " << current->phoneNumber << " ";
				cout << endl;

				current = current->next;
			}
		}
		cout << endl;
	}
};