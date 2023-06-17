#pragma once
#include<iostream>
#include<limits>


using namespace std;
class preOdernode {//create pre oder linked list
public:
	int Pre_Oder_food_Code, RegNumber, food_quanity;
	
	preOdernode* next;
	preOdernode()
	{
		RegNumber = NULL;
		food_quanity = 0;
		Pre_Oder_food_Code = 0;
		next = NULL;
	}
	preOdernode( int regno, int food_val, int foodqunty) {
		RegNumber = regno;
		Pre_Oder_food_Code = food_val;
		food_quanity = foodqunty;
		next = NULL;
	}
};


class Pre_Oder_Linked_list
{
public:
	int PreOderposition;
	int RegNumber;
	int food_quanity, Pre_Oder_food_Code;
	preOdernode* head2;
	preOdernode* tail2;
	int size;

	Pre_Oder_Linked_list()
	{
		Pre_Oder_food_Code = NULL;
		food_quanity = 0;
		RegNumber = NULL;
		PreOderposition = NULL;
		head2 = NULL;
		tail2 = NULL;
		size = 0;
	}
	void insertPreOderFirst(int RegNumber, int food_Code, int food_quanity) {
		//create the node
		preOdernode* temp = new preOdernode(RegNumber, food_Code, food_quanity);

		if (head2 == NULL) {
			//list is empty
			head2 = temp;
			tail2 = temp;
			size++;
		}
		else {
			//list is non-empty
			temp->next = head2;
			head2 = temp;
			size++;
		}
	}
	void insertPreOderLast(int RegNumber, int food_Code, int food_quanity) {
		//create a node
		preOdernode* temp = new preOdernode(RegNumber, food_Code, food_quanity);
		if (head2 == NULL) {
			head2 = temp;
			tail2 = temp;
			size++;
		}
		else {
			tail2->next = temp;
			tail2 = temp;
			size++;
		}
	}
	void insertPreOderAt(int PreOderpos, int RegNumber, int food_Code, int food_quanity) {

		if (PreOderpos<0 || PreOderpos>size) {
			cout << "\tInvalid Position" << endl;
			return;
		}
		else if (PreOderpos == 0) {
			insertPreOderFirst(RegNumber, food_Code, food_quanity);
		}
		else if (PreOderpos == size) {
			insertPreOderLast(RegNumber, food_Code, food_quanity);
		}
		else {
			preOdernode* temp = new preOdernode(RegNumber, food_Code, food_quanity);
			preOdernode* currentPreOder = head2;

			for (int i = 0; i < PreOderpos - 1; i++) {
				currentPreOder = currentPreOder->next;
			}
			temp->next = currentPreOder->next;
			currentPreOder->next = temp;
		}
		size++;
	}
	void deletePreOderFirst() {
		if (head2 == NULL)
			cout << "\tList is empty" << endl;
		else {
			preOdernode* temp = head2;
			if (size == 1) {
				delete temp;
				head2 = NULL;
				tail2 = NULL;
			}
			else {
				head2 = head2->next;// head = temp->next;
				delete temp;
			}
			size--;
		}
	}
	void deletePreOderLast() {
		if (head2 == NULL)
			cout << "\tList is empty" << endl;
		else {
			preOdernode* temp = tail2;
			if (size == 1) {
				delete temp;
				head2 = NULL;
				tail2 = NULL;
			}
			else {
				preOdernode* currentPreOder = head2;
				for (int i = 0; i < size - 2; i++) {
					currentPreOder = currentPreOder->next;
				}
				tail2 = currentPreOder;
				tail2->next = NULL;
				delete temp;
			}
			size--;
		}
	}
	void deletePreOderAt(int PreOderpos) {
		if (PreOderpos < 0 || PreOderpos >= size)
			cout << "\tInvalid position" << endl;
		else {
			if (PreOderpos == 0)
				deletePreOderFirst();
			else if (PreOderpos == size - 1)
				deletePreOderLast();
			else {
				preOdernode* currentPreOder = head2;
				for (int i = 0; i < PreOderpos - 1; i++) {
					currentPreOder = currentPreOder->next;
				}
				preOdernode* temp = currentPreOder->next;
				//current->next = temp->next; this can also do
				currentPreOder->next = (currentPreOder->next)->next;
				delete temp;
			}
			size--;
		}
	}
	//----------------------------------------------------------------------------------------------------------------------
	void deletePreOder(int RegNumber) {
		preOdernode* current = head2;
		preOdernode* previous = NULL;

		while (current != NULL) {
			if (current->RegNumber == RegNumber) {
				if (previous == NULL) {
					head2 = current->next;
				}
				else {
					previous->next = current->next;
				}
				delete current;
				cout << "\tPre-Oder with Reg. No. " << RegNumber << " deleted successfully from pre oder list." << endl;
				return;
			}
			previous = current;
			current = current->next;
		}

		cout << "\tPre-Oder with Reg. No. " << RegNumber << " not found in Pre-Oder list or already deleted or invalid registation number." << endl;
	}
	//-----------------------------------------------------------------------------------------------------------------------
	void searchPreOder(int RegNumber) {
		preOdernode* currentPreOder = head2;

		for (int i = 0; i < size; i++) {
			if (currentPreOder->RegNumber == RegNumber)
				PreOderposition = i;
			currentPreOder = currentPreOder->next;
		}
		cout << endl;
	}

	preOdernode* searchPreOder2(int RegNumber3) {
		preOdernode* currentPreOder = head2;
		preOdernode* currentPreOder2 = NULL;
		
		while (currentPreOder != NULL) {
			if (currentPreOder->RegNumber == RegNumber3)
			{
				//cout << "found";
				currentPreOder2 = currentPreOder;
			}

			currentPreOder = currentPreOder->next;
		}
	//	cout << endl;
		return currentPreOder2;
	}
	preOdernode* searchPreOderAdmin(int RegNumber3) {
		preOdernode* currentPreOder = head2;
		preOdernode* searchPreOderAdmin = NULL;

		while (currentPreOder != NULL) {
			if (currentPreOder->RegNumber == RegNumber3)
			{
				cout <<"\tPre odered food code: " << currentPreOder->Pre_Oder_food_Code << endl;
				cout <<"\tPre odered food quantity: " << currentPreOder->food_quanity << endl;
				
				//cout << "found";
				searchPreOderAdmin = currentPreOder;
			}

			currentPreOder = currentPreOder->next;
		}
		//	cout << endl;
		return searchPreOderAdmin;
		
	}

	void displayPreOder()
	{
		preOdernode* currentPreOder = head2;
		if (currentPreOder == NULL) {
			cout << "\tNO any Pre oder or deleted all pre-oders" << endl;
		}
		else {
			while (currentPreOder != NULL) {
					cout << "\tReg No: " << currentPreOder->RegNumber << "\t |";
					cout << "\tFood Name: " << currentPreOder->Pre_Oder_food_Code << "\t |";

					//	cout << "Food Name: " << currentPreOder-> << "\t |";
					cout << "\tFood Quantity: " << currentPreOder->food_quanity << " ";
					cout << endl;

					currentPreOder = currentPreOder->next;
			}
				cout << endl;
		}
	}

	void displayOderFoods() {
		preOdernode* currentNode = head2;
		while (currentNode != NULL) {
			cout << "\tFood Name: " << currentNode->Pre_Oder_food_Code << "\t |";
			cout << "\tFood Quantity: " << currentNode->food_quanity << " ";
			cout << endl;
			currentNode = currentNode->next;
		}
	}

	void getAllPreOrdersForId(int regNo) //for hash table
	{
		preOdernode* currentPreOder = head2;
		while (currentPreOder != NULL) {
			if (currentPreOder->RegNumber == regNo)
			{
				cout << "\tReg No: " << currentPreOder->RegNumber << "\t |";
				cout << "\tFood Name: " << currentPreOder->Pre_Oder_food_Code << "\t |";
				cout << "\tFood Quantity: " << currentPreOder->food_quanity << " ";
				cout << endl;
			}
			currentPreOder = currentPreOder->next;
		}
	}

	void displayPreOders() {
		preOdernode* current = head2;
		while (current != NULL) {
			cout << "\tFood Fode : "<<current->Pre_Oder_food_Code << " \t";
			cout <<"\tFood quanity :"<< current->food_quanity;
			current = current->next;
			cout << endl;
		}
		cout << endl;
	}
	int sumofPreOderFoodSummary() {
		int sumofOder = 0;
		preOdernode* current = head2;
		//cout <<"----" << Pre_Oder_food_Code;
		for (int i = 1; i <= 10; i++) {
			while (current != NULL) {
				if (current->Pre_Oder_food_Code == 1) {
					sumofOder += current->food_quanity;
				}
			}
		}
		cout << "\tNo Any Pre-Oder Today" << endl;
		return sumofOder;
	}
	//-----------------------------------------Insertion sort--------------------------------------------------------

	void insertionSort() {
		if (head2 == NULL || head2->next == NULL) {
			return;
		}

		preOdernode* sorted = NULL;
		preOdernode* current = head2;

		while (current != NULL) {
			preOdernode* next = current->next;

			if (sorted == NULL || current->Pre_Oder_food_Code < sorted->Pre_Oder_food_Code) {
				current->next = sorted;
				sorted = current;
			}
			else {
				preOdernode* temp = sorted;
				while (temp->next != NULL && current->Pre_Oder_food_Code > temp->next->Pre_Oder_food_Code) {
					temp = temp->next;
				}
				current->next = temp->next;
				temp->next = current;
			}

			current = next;
		}

		head2 = sorted;
	}
};
