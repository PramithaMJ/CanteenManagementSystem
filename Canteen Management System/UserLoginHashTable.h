#pragma once
#include"admin.h"
#include"linkedList.h"
#include"queueWithLinkedList.h"
#include<stdlib.h>
#include"FoodItemAsAdmin.h"
#include"preOder.h"
#include <iostream>
#include <string>
#include <vector>
#include <string>
using namespace std;

//Login using Hash Table
class HashTable {
public:
	HashTable(int size) : table(new Node* [size]()), size(size) {}

	~HashTable() {
		for (int i = 0; i < size; i++) {
			Node* current = table[i];
			while (current != nullptr) {
				Node* next = current->next;
				delete current;
				current = next;
			}
		}
		delete[] table;
	}
	//Insert key and value to hash table
	void insert(const string& key, const string& value) {
		int index = hash(key);
		Node* current = table[index];
		while (current != nullptr) {
			if (current->key == key) {
				current->value = value;
				return;
			}
			current = current->next;
		}
		Node* new_node = new Node{ key, value, table[index] };
		table[index] = new_node;
	}
	// Check the password is true or not
	bool lookup(const string& key, string& value) {
		int index = hash(key);
		Node* current = table[index];
		while (current != nullptr) {
			if (current->key == key) {
				value = current->value;
				return true;//If the username and password is correct it returns the true
			}
			current = current->next;
		}
		return false;
	}

private:
	struct Node {
		string key;
		string value;
		Node* next;
	};

	int hash(const string& key) {
		int hash_value = 0;
		for (char c : key) {
			hash_value += c;
		}
		return hash_value % size;
	}
	Node** table;
	int size;
};