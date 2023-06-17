#pragma once
#include<iostream>
#include"FoodItemAsAdmin.h"
#include"FoodItemLinkedList.h"
#include "preOderLinkedList.h"
#include"PreOderQueue.h"
#include"preOder.h"
using namespace std;
class BillCal  : public Pre_Oder_Linked_list,Linked_list_Food_Add{
public:
	int foodPriceCalculate() 
	{
		//This bilcaculate is done in preOder section and admin header files
		int Reg_No;
		cout << "\tEnter The Reg No (@billcl)" << endl;
		cin >> Reg_No;

		int priceofpreoder = 0;
	
		int Totalprice = 0;
		preOdernode* currentPreOder;//preoder linked list
		currentPreOder = searchPreOder2(Reg_No);
	}

};
