#pragma once
#include <iostream>
#include "FoodItemAsAdmin.h"
#include "preOderLinkedList.h"
#include "linkedList.h"
#include "FoodItemAsAdmin.h"
//#include"admin.h"
//#include"customer.h"
//#include"linkedList.h"
//#include"queueWithLinkedList.h"
using namespace std;

//-------------------Add food Item Linked List---------------------------

class node {//create node
public:
	int food_Code, food_price, available_Quanity;
	string food_name;
	node* Next;
	node()
	{
		food_price = NULL;
		available_Quanity = 0;
		food_Code = 0;
		Next = NULL;
	}
	node(int fod_val, string fdnme, int fdpnber, int fdqunty) {
		food_Code = fod_val;
		food_name = fdnme;
		food_price = fdpnber;
		available_Quanity = fdqunty;
		Next = NULL;
	}
};

class Linked_list_Food_Add 
{
public:
	Linked_list_Food_Add* thisP = this;
	int Position;
	node* Head;
	node* Tail;
	int Size;
public:
	

	Linked_list_Food_Add()
	{
		Linked_list_Food_Add* thisP = this;
		Position = NULL;
		Head = NULL;
		Tail = NULL;
		Size = 0;
	}
	// For create the food code
	int generate_Code_For() {

		int food_Code = 1;
		node* Current = Head;
		while (Current != NULL) {
			Current = Current->Next;
			food_Code++;
		}
		cout << food_Code;
		cout << endl;
		return food_Code;
	}

	void Food_Add_InsertFirst(int food_Code, string food_name, int food_price, int available_Quanity) {
		//create the node
	
		node* Temp = new node(food_Code, food_name, food_price, available_Quanity);

		if (Head == NULL) {
			//list is empty
			Head = Temp;
			Tail = Temp;
			Size++;
		}
		else {
			//list is non-empty
			Temp->Next = Head;
			Head = Temp;
			Size++;
		}
	}

	//adding food list
	Linked_list_Food_Add* Food_Add_InsertFirst2(int food_Code, string food_name, int food_price, int available_Quanity) {
		//create the node

		node* Temp = new node(food_Code, food_name, food_price, available_Quanity);

		if (Head == NULL) {
			//food list is empty
			Head = Temp;
			Tail = Temp;
			Size++;
		}
		else {
			//food list is non-empty
			Temp->Next = Head;
			Head = Temp;
			Size++;
		}
		return thisP;
	}

	void Food_Add_InsertLast(int food_Code, string food_name, int food_price, int available_Quanity) {
		//create a node
		node* Temp = new node(food_Code, food_name, food_price, available_Quanity);
		if (Head == NULL) {
			Head = Temp;
			Tail = Temp;
			Size++;
		}
		else {
			Tail->Next = Temp;
			Tail = Temp;
			Size++;
		}
	}
	void Food_Add_InsertAt(int Pos, int food_Code, string food_name, int food_price, int available_Quanity) {

		if (Pos<0 || Pos>Size) {
			cout << "\tInvalid Position!!!" << endl;
			return;
		}
		else if (Pos == 0) {
			Food_Add_InsertFirst(food_Code, food_name, food_price, available_Quanity);
		}
		else if (Pos == Size) {
			Food_Add_InsertLast(food_Code, food_name, food_price, available_Quanity);
		}
		else {
			node* Temp = new node(food_Code, food_name, food_price, available_Quanity);
			node* Current = Head;

			for (int i = 0; i < Pos - 1; i++) {
				Current = Current->Next;
			}
			Temp->Next = Current->Next;
			Current->Next = Temp;
		}
		Size++;
	}
	void Food_Add_DeleteFirst() {
		if (Head == NULL)
			cout << "\tList is Empty" << endl;
		else {
			node* Temp = Head;
			if (Size == 1) {
				delete Temp;
				Head = NULL;
				Tail = NULL;
			}
			else {
				Head = Head->Next;// head = temp->next;
				delete Temp;
			}
			Size--;
		}
	}
	void Food_Add_DeleteLast() {
		if (Head == NULL)
			cout << "\tList is Empty" << endl;
		else {
			node* Temp = Tail;
			if (Size == 1) {
				delete Temp;
				Head = NULL;
				Tail = NULL;
			}
			else {
				node* Current = Head;
				for (int i = 0; i < Size - 2; i++) {
					Current = Current->Next;
				}
				Tail = Current;
				Tail->Next = NULL;
				delete Temp;
			}
			Size--;
		}
	}
	void Food_Add_deleteAt(int Pos) {
		if (Pos < 0 || Pos >= Size)
			cout << "\tInvalid Position" << endl;
		else {
			if (Pos == 0)
				Food_Add_DeleteFirst();//if position is zero it detele the first node
			else if (Pos == Size - 1)
				Food_Add_DeleteLast();
			else {
				node* Current = Head;
				for (int i = 0; i < Pos - 1; i++) {
					Current = Current->Next;
				}
				node* Temp = Current->Next;

				Current->Next = (Current->Next)->Next;
				delete Temp;
			}
			Size--;
			cout << "\n\tSuccessfully Deleted The Food Item!!!" << endl;
		}
	}
	void Food_Add_Search(int food_Code) {
		node* Current = Head;
		//cout << "Food Code: " << food_Code << " : ";
		for (int i = 0; i < Size; i++) {
			if (Current->food_Code == food_Code)
				Position = i;
			Current = Current->Next;
		}
		cout << endl;
	}
	void deleteFoodAdds(int foodCode) {
		node* current = Head;
		node* previous = NULL;

		while (current != NULL) {
			if (current->food_Code == foodCode) {
				if (previous == NULL) {
					Head = current->Next;
				}
				else {
					previous->Next = current->Next;
				}
				delete current;
				cout << "Food with code " << foodCode << " deleted Successfully from food list." << endl;
				return;
			}
			previous = current;
			current = current->Next;
		}

		cout << "Food with code number " << foodCode << " not found in list or already deleted..." << endl;
	}
	// search pre oder food code equal code at the food at linked list and get the price of foood add linked list 
	int Food_Add_Search2(int food_Code2,int quant) {
		node* Current = Head;
		int k=0;

		for (int i = 0; i < Size; i++) {
					
			if (Current->food_Code == food_Code2)
				k += (quant * Current->food_price);//pre oder quantity multyply by ordered pre-oder  food price 
			Current = Current->Next;
		}
		return k;
		cout << endl;
	}
	void foodModifyPrice(int food_Code2) {
		node* Current = Head;
		int k = 0;
		int food_price_new;
		cout << "\tFood Price " << " : ";
		cin >> food_price_new;
		for (int i = 0; i < Size; i++) {
			
			if (Current->food_Code == food_Code2)
				
				Current->food_price=food_price_new;
				Current = Current->Next;
		}
		cout << endl;
	}
		// modify the food quantity
	void foodModifyQuantity(int food_Code2) {
		node* Current = Head;
		int k = 0;
		int food_quanity_new;
		cout << "\tFood Quantity " << " : ";
		cin >> food_quanity_new;// new value of food quantity

		for (int i = 0; i < Size; i++) {
			if (Current->food_Code == food_Code2)
				Current->available_Quanity = food_quanity_new;
			Current = Current->Next;
		}
		cout << endl;
	}
	//To display the available food
	void available_Food_Display() {
		node* Current = Head;
		if (Current==NULL) {
			cout << "\tFoods are not available" << endl;
		}
		else {
			while (Current != NULL) {
				cout << "\tFood Number\t: " << Current->food_Code << "\t |";
				cout << "\tFood Name\t: " << Current->food_name << "\t |";
				cout << "\tFood Price\t: " << Current->food_price << "\t |";
				cout << "\tAvailable Food Quantity: " << Current->available_Quanity << " ";
				cout << endl;

				Current = Current->Next;
			}
				cout << endl;
		}
		
	}
	 int length() {

		node* currentlenght = Head;
		int count = 0;
		while (currentlenght != NULL) {
			count++;
			currentlenght = currentlenght->Next;
		}
		return count;
	}
};