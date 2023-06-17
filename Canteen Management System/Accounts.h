#pragma once
#include <iostream>
#include <unordered_map>
#include "preOderLinkedList.h"


using namespace std;
// Search user details by using Hash Table
class Account {
public:
	int id;
	string name;
	int phoneNumber;
	Account() {
		id = 0;
		name = "d";
		phoneNumber = 555;
	}

	Account(int id2, string name2, int pn) {
		id = id2;
		name = name2;
		phoneNumber = pn;
	}

	void printAcc() {
		cout << endl;
		cout << "\tRegistation number of customer\t: |  " << id << "  |" << endl;
		cout << "\tName of customer\t\t: |  " << name << "  |" << endl;
		cout << "\tCustomer phone number\t\t: |  " << phoneNumber << "  |" << endl;
	}
};

class Accounts 
{
public:
	unordered_map<int, Account> umap = 
	{
		{100, Account(0, "kk", 55)}
	};
	Accounts() {
		umap[0] = Account(0, "kk", 55);
	}

	void insertAnAccount(Account* newAccount)
	{
		
		umap[newAccount->id] = Account(newAccount->id,newAccount->name,newAccount->phoneNumber);
	}

	void searchAccount(int id, preOder* preAddr)
	{
		if (umap.find(id) == umap.end())
		{
			cout << "\tNot found...";
		}
		else {
			umap[id].printAcc();
			preAddr->getAllPreOrdersForId(id);
		}
	}
	void deleteAccount(int id)
	{
		if (umap.find(id) == umap.end())
		{
			//cout << "\tAccount not found... or Already Deleted" << endl;
		}
		else {
			umap.erase(id);
			//cout << "\tAccount with ID " << id << " has been deleted." << endl;
		}
	}
};