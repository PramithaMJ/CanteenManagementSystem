#pragma once
#include <iostream>
#include"PreOderQueue.h"
#include "FoodItemLinkedList.h"
#include "admin.h"

using namespace std;

class preOder : public Pre_Oder_Queue_LinkedList {//inherited pre oder and  Pre_Oder_Queue_LinkedList classes
public:
	preOder* preOrderThisAddress = this;

	preOder* getAddressOfPreOrderList() {
		return preOrderThisAddress;
	}

	void Pre_Oder_details_input() {//pre oder user inputs
		cout << "\tEnter your Reg. No.\t: ";
		cin >> RegNumber;//Reg No.
		cout << endl;
		cout << "\tEnter Food code\t: ";
		cin >> Pre_Oder_food_Code;
		cout << endl;
		cout << "\tEnter Food quantity\t: ";
		cin >> food_quanity;
		cout << "\n\tPre Oder Successfully Added" << endl;
		cout << endl;
	
	}

	int create_Pre_Oder_First(Linked_list_Food_Add* listt) {//element=reg.No
		//create the node
		Pre_Oder_details_input();
		//PRE-ODER BY QUEUES
		enQueuePreOder(RegNumber, Pre_Oder_food_Code, food_quanity);//Add pre oder to the queue
	//	insertLast2( &head2, RegNumber, Pre_Oder_food_Code, food_quanity);
		int Totalprice = 0;
		preOdernode* CP;//preoder linked list
		CP = searchPreOder2(RegNumber);
		if (CP != NULL)
		{
			cout << endl;
			//cout << CP->Pre_Oder_food_Code;
			int kk = listt->Food_Add_Search2(CP->Pre_Oder_food_Code,CP->food_quanity);
			cout << "\tFood Code\t: " << CP->Pre_Oder_food_Code << " | ";
			cout << "\tFood Quantity\t: " << CP->food_quanity << " | ";
			cout << "\tTotal pre oder bill\t: ";
			cout << " Rs." << kk << "\n" << endl;
			cout << endl;
			
		}
		return 0;
	}

	int preOderBill(Linked_list_Food_Add* listt) {//calculate the pre oder bill
		int Totalprice = 0;// set the initial price to 0
		preOdernode* CP;//preoder linked list
		CP = searchPreOder2(RegNumber);
		if (CP != NULL)
		{
			int kk = listt->Food_Add_Search2(CP->Pre_Oder_food_Code, CP->food_quanity);
			/*cout << "\tFood Code: " << CP->Pre_Oder_food_Code << " : ";
			cout << "\tFood Quantity: " << CP->food_quanity << endl;*/
			cout << "\tTotal pre oder bill\t: ";
			cout << " Rs." << kk << "\n" << endl;//print the pre oder bill
			cout << endl;
		}
		return 0;
	}

		void searchPreOrder22() {//element=reg.No
		//create the node
		//Pre_Oder_details_input();
		/*	Pre_Oder_Queue_LinkedList newList;
			newList.enQueuePreOder(RegNumber, Pre_Oder_food_Code, food_quanity);*/

		//preOrderSearch2();
	}
		//Default price list in daily
	void priceList() {
        cout << "\tPrice List" << endl << "\t------------" << endl << endl;
        cout << "\tBreakfast\n" << endl;
        cout << "\t- Main Meals" << endl;
        cout << "\t\tMilk Rice 1 piece with Onionsambol\t\t\t Rs.  30" << endl;
        cout << "\t\tBread 1 piece with Dhal/Polsambol\t\t\t Rs.  50" << endl;
        cout << "\t\tString Hoppers 1 packet\t\t\t\t\t Rs.  70" << endl;
        cout << "\t\tRice & Curries (Dhal, Polsambol, Onionsambol)\t\t Rs. 100" << endl;
        cout << "\t\tRice & Curries (Dhal, Polsambol, Onionsambol) + Egg\t Rs. 150" << endl;



        cout << "\t- Short eats" << endl;
        cout << "\t\tParata\t\t\t\t\t\t\t Rs.  50" << endl;
        cout << "\t\tCream Bun\t\t\t\t\t\t Rs.  50" << endl;
        cout << "\t\tFish Bun\t\t\t\t\t\t Rs.  70" << endl;
        cout << "\t\tEgg Bun\t\t\t\t\t\t\t Rs.  80" << endl;
        cout << "\t\tVegetable Rotti\t\t\t\t\t\t Rs.  80" << endl;
        cout << "\t\tEgg Rotti\t\t\t\t\t\t Rs. 100" << endl;

        cout << "\n\tLunch & Dinner\n" << endl;
        cout << "\t\tRice with 3 Curries \t\t\t\t\t Rs. 100" << endl;
        cout << "\t\tRice with 3 Curries + Egg\t\t\t\t Rs. 150" << endl;
        cout << "\t\tRice with 3 Curries + Fish\t\t\t\t Rs. 150" << endl;
        cout << "\t\tRice with 3 Curries + Sausage\t\t\t\t Rs. 170" << endl;
        cout << "\t\tRice with 3 Curries + Chicken\t\t\t\t Rs. 180" << endl;
		cout << "\n" << endl;
		
	}
	//--------------------customer pre oder-----------------

	
};