#pragma once
#include <iostream>
#include"FoodItemLinkedList.h"
//#include"admin.h"
//#include"customer.h"
//#include"linkedList.h"
//#include"queueWithLinkedList.h"


using namespace std;

//--------------ADD FOOD(ADMIN)---------------
class Food_Add_Admin :public Linked_list_Food_Add {//inherited the linkedlist classto food add admin class
public:
	int food_Code, food_price, available_Quanity;
	string food_name;

	Linked_list_Food_Add* mainListfromFoodDetailsInput;
	void Food_details_input() {// Input the food details input
		
		cout << "\tEnter Food Name\t\t: ";
		cin >> food_name;
		cout << endl;
		cout << "\tEnter Food Price\t: ";
		cin >> food_price;
		cout << endl;
		cout << "\tEnter Available Quantity\t: ";
		cin >> available_Quanity;
		cout << "\n\tSuccessfully Added Food!!!" << endl;
		cout << endl;
	}
	void Available_Food_Add_Admin() {
		Food_details_input();
		int food_Code = generate_Code_For();//generate automatic code for food
		mainListfromFoodDetailsInput = Food_Add_InsertFirst2(food_Code, food_name, food_price, available_Quanity);	//food details input to the main list
	}

	Linked_list_Food_Add* getAddressOfFoodList() {
		return mainListfromFoodDetailsInput;
	}
};