#pragma once
#include <iostream>
#include<stdlib.h>
#include<string>
#include"linkedList.h"
#include"queueWithLinkedList.h"
#include "UserLoginHashtable.h"
#include"FoodItemAsAdmin.h"
#include"preOder.h"
#include"billCalculate.h"
#include "Accounts.h";
using namespace std;

class Admin :public Queue_LinkedList,public Food_Add_Admin,public preOder
{
private:
	BillCal B1;
public:
	
	Food_Add_Admin* mainList; 
	Accounts* CustomerAccounts = new Accounts();
	int element, phoneNumber;
	string name;

	
	void welcome() {
		int choise;
		cout << "\n\t--------------* WELCOME TO CANTEEN MANAGEMENT SYSTEM *--------------\n" << endl;
		cout << "\n\t\t1. SIGN IN " << endl;//Student & Other custermer registation to the system
		cout << "\t\t2. LOG IN " << endl;//Log in to the system customer and admin
		cout << "\t\t3. EXIT" << endl;
		cout << "\n\t\tSelect Your Option (1-3)" << endl;
		cin >> choise;
		cout << endl;

		if (choise == 1) {
			//Sign In
			system("CLS");
			SignIn_registation();
		}
		else if (choise == 2) {
			//Log In 
			system("CLS");
			login_Without_Password();
		}
		else if (choise == 3) {
			//Exit
			exit(0);
		}
		else {
			system("CLS");
			cout << "\tInvalid selection!!!" << endl;
			welcome();
		}
	}
	void login_Without_Password() {
		int choise;
		cout << "\n\t1. ADMIN " << endl;//Asked the User name and password to log in. It is done by HASH TABLE
		cout << "\t2. CUSTOMER" << endl;//Login without password
		cout << "\t3. BACK TO MAIN WINDOW" << endl;
		cout << "\t4. EXIT" << endl;
		cout << "\n\tSelect Your Option (1-4)" << endl;
		cin >> choise;
		cout << endl;

		if (choise == 1) {
			//---------------------Admin--------------------
	
			
			HashTable passwords(10);//Create HashTable in size 10 that means 10 user of admin can set the username and password.

			// Add Admin Username and Passwords
			passwords.insert("Dinithi", "EG3892");// 1. Admin user, userName: = Dinithi , Password = EG3892
			passwords.insert("Dilen", "EG3895");// 2. Admin user, userName: = Dilen , Password = EG3895
			passwords.insert("Pramitha", "EG3990");// 2. Admin user, userName: = Pramitha , Password = EG3990

			// Inserting user Username And Password
			string username, password;
			cout << "\tEnter your username: ";
			cin >> username;
			cout << "\tEnter your password: ";
			cin >> password;

			//Check user name and password is correct of not in the Hash Table
			string correct_password;
			if (passwords.lookup(username, correct_password) && correct_password == password) {
				cout << "\n\tLogin successful!\n";
				admin();
			}
			else {
				cout << "\n\tIncorrect username or password.\n";//If not found username  or password 
				login_Without_Password();
			}

		}
		else if (choise == 2) {
			//Customer
			customer();
		}
		else if (choise == 3) {
			//Back to Main Window
			welcome();
		}
		else if (choise == 4) {	
			//Exit
			exit(0);
		}
		else {
			cout << "\tInvalid selection!!!" << endl;

			welcome();
		}
	}
	int admin() {
		// ADMIN MENU
		int choise_AM;//Admin menu choise
		cout << "\n------------------ ADMIN MENU ------------------\n" << endl;
		cout << "\t1.REGISTRATION" << endl;
		cout << "\t2.SEARCH ACCOUNT" << endl;
		cout << "\t3.PRICE LIST" << endl;
		cout << "\t4.AVAILABLE FOOD ITEMS & QUANTITY" << endl;
		cout << "\t5.PRE ODER" << endl;
		cout << "\t6.PRE ODER SUMMARY " << endl;
		cout << "\t7.BILL CALCULATE" << endl;
		cout << "\t8.BACK TO MAIN MENU" << endl;
		cout << "\t9.EXIT" << endl;
		cout << "--------------------------------------------------\n" << endl;
		cout << "\tPlease Enter Your Choice(1 - 9): " << endl;
		cin >> choise_AM;
		cout << endl;
		if (choise_AM == 1) {
			//REGISTATION
			registation();
		}
		else if (choise_AM == 2) {
			//SEARCH ACCOUNT
			//Using by HASH TABLE
			preOder* addr = getAddressOfPreOrderList();
			int idd;
			cout << "\tEnter Reg. No. to search: " ;
			cin >> idd;
			CustomerAccounts->searchAccount(idd,addr);//search hash table account throught  key of idd(Register Numbber)
			admin();
		}
		else if (choise_AM == 3) {
			//PRICE LIST
			price_List();
		}
		else if (choise_AM == 4) {
			//AVAILABLE FOOD ITEM & QUANTITY
			Available_Food();
		}
		else if (choise_AM == 5) {
			//PRE ODER
			//Using by Queue
			Pre_Oder_Admin();
			admin();
		}
		else if (choise_AM == 6) {
			//PRE ODER SUMMARY
			//Using by Queue with merge sort
			
			cout << "\tSort by Food Name: " << endl;
			insertionSort();//sort food name by using food code.(Fewnumber of foods in the cateen )
			cout << endl;
			displayOderFoods();// display the sorted food list

			head2 = mergeSort(head2);
			printSorted(); // sorted pre oder customers by using merge sorting
			/*cout << "\n-----------------\n" << endl;
			cout<<sumofPreOderFoodSummary();*/
			
			admin();
			
		}
		else if (choise_AM == 7) {
			//BILL CALCULATE
			//pre-oders details are in preOderQueue and pre-odered food details in foodItem Linked list
			// create algorithem to claculate bill of pre-oder by preOderBill(foodList) function
			while (RegNumber != NULL) {
				cout << "\tLast Pre Odered customer Reg No.: " << RegNumber;
				Linked_list_Food_Add* foodList = getAddressOfFoodList();//get the address of food list
				preOderBill(foodList);// calculate the bill
				cout << endl;
				admin();
			}
		}
		else if (choise_AM == 8) {
			//BACK TO MAIN MENU
			welcome();
		}
		else if (choise_AM == 9) {
			//EXIT
			exit(0);
		}
		else {
			cout << "\tPlease Enter Your Choice(1 - 9): " << endl;
			admin();
		}
	}
	void price_List() {
		int choise;
		cout << "\t1. SHOW PRICE LIST" << endl;
		cout << "\t2. BACK TO ADMIN WINDOW" << endl;
		cout << "\t3. BACK TO MAIN WINDOW" << endl;
		cout << "\n\tSelect Your Option (1-3)" << endl;
		cin >> choise;
		cout << endl;

		if (choise == 1) {
			//Show price List
			priceList();
			cout << "\n" << endl;
			price_List();
			
		}
		else if (choise == 2) {
			//Back to Admin Window
			admin();
		}
		else if (choise == 3) {
			//Back to Main Window
			welcome();
		}
		else {
			cout << "\tInvalid selection!!!" << endl;
			price_List();
		}
	}
	//Available food can modify by the administrative of canteen
	void Available_Food() {
		int choise;
		cout << "\n\t1. SHOW AVAILABLE FOOD" << endl;
		cout << "\t2. MODIFY AVAILABLE FOOD" << endl;
		cout << "\t3. BACK TO ADMIN WINDOW" << endl;
		cout << "\t4. BACK TO MAIN WINDOW" << endl;
		cout << "\n\tSelect Your Option (1-4)" << endl;
		cin >> choise;
		cout << endl;

		if (choise == 1) {
			//Show price List
			available_Food_Display();// To display the available food add
			Available_Food();
		}
		else if (choise == 2) {
			//Modify Available Food
			system("CLS");
			Modify_Available_Food();
			Available_Food();
		}
		else if (choise == 3) {
			//Back to Admin Window
			admin();
		}
		else if (choise == 4) {
			//Back to Main Window
			welcome();
		}
		else {
			cout << "\tInvalid selection!!!" << endl;
			price_List();
		}
	}
	void Modify_Available_Food() {
		int choice;
		cout << "\n\t1. ADD FOOD ITEM " << endl;
		cout << "\t2. DELETE FOOD ITEM" << endl;
		cout << "\t3. CHANGE QUANTITY" << endl;
		cout << "\t4. CHANGE PRICE" << endl;
		cout << "\t5. DISPLAY FOOD ITEMS" << endl;
		cout << "\t6. BACK ONCE" << endl;
		cout << "\t7. BACK TO ADMIN WINDOW" << endl;
		cout << "\t8. BACK TO MAIN WINDOW" << endl;
		cout << "\n\tSelect Your Option (1-8)" << endl;
		cin >> choice;
		cout << endl;

		if (choice == 1) {
			//Add Food Item
			Available_Food_Add_Admin();
			//cout << getAddressOfFoodList();
		}
		else if (choice == 2) {
			//Delete Food Item
			available_Food_Display();//To show the available food
			//cout << "Enter Food code to delete from food list: ";
			//cin >> food_Code;//get the food code of that want to change
			//deleteFoodAdds(food_Code);// delete food correspoding to food code
			cout << endl;
			cout << "\nFood Code: ";
			cin >> food_Code;//get the food code of that want to change
			cout << endl;
			Food_Add_Search(food_Code);// get the position of the food code
			Food_Add_deleteAt(Position);// delete food correspoding to food code
			Modify_Available_Food();
			
			Modify_Available_Food();
		}
		else if (choice == 3) {
			//Change Quantity
			available_Food_Display();//To show the available food
			cout << endl;
			int foodcodemodifyQuantity;
			cout << "\tEnter the food code: ";
			cin >> foodcodemodifyQuantity;// get the food code of that want to modify quantity
			foodModifyQuantity(foodcodemodifyQuantity);// change into new quantity
			Modify_Available_Food();
		}
		else if (choice == 4) {
			//Change Price
			available_Food_Display();
			cout << endl;
			int foodcodemodifyPrice;
			cout << "\tEnter the Food Code: ";
			cin >> foodcodemodifyPrice;// get the food code of that want to modify price
			foodModifyPrice(foodcodemodifyPrice);// change into new price
			Modify_Available_Food();
		}
		else if (choice == 5) {
			//Show Added Foods
			available_Food_Display();
			//Food_details_input();
			Modify_Available_Food();
		}
		else if (choice == 6) {
			//Back to Available food Item
			Available_Food();
		}
		else if (choice == 7) {
			//Back to Admin Window
			admin();
		}
		else if (choice == 8) {
			//Back to Main Window
			welcome();
		}
		else {
			cout << "\tInvalid selection!!!" << endl;
			Modify_Available_Food();
		}
	}
	//Pre-Oders by Using Queues
	void Pre_Oder_Admin() {
		Linked_list_Food_Add* foodList = getAddressOfFoodList();
		int choice;
		cout << "\n\t1. SHOW PRE ORDERS" << endl;//done
		cout << "\t2. ADD PRE ORDER" << endl;
		cout << "\t3. SEARCH PRE ORDER" << endl;
		cout << "\t4. DELETE PRE ORDER" << endl;//done
		cout << "\t5. BACK TO ADMIN WINDOW" << endl;
		cout << "\t6. BACK TO MAIN WINDOW" << endl;
		cout << "\tSelect Your Option (1-6)" << endl;
		cin >> choice;
		cout << endl;

		if (choice == 1) {
			//Show Pre Oder
			displayPreOder();
			Pre_Oder_Admin();
		}
		if (choice == 2) {
			
			//Add Pre Oder At
			//Check if before customer register or not
			checkregisterOrNot(foodList);//check before register and create_Pre_Oder_First();//create pre order
			FRQuantity();//Update the available quantity. when oreded pre oder then reduce the quantity
			
			Pre_Oder_Admin();

		}
		if (choice == 3) {
			//Show Pre Oder
			int regPreOder;
			cout << "\tEnter Registation number to search pre oder: ";
			cin >> regPreOder;
			searchPreOderAdmin(regPreOder);//search pre oder by using register

			Pre_Oder_Admin();
		}
		else if (choice == 4) {
			//Delete Pre Oder
			
			cout << "\tEnter Reg. No. to delete Pre-oder from list: ";
			cin >> RegNumber;
			deletePreOder(RegNumber);//delete pre oder
			Pre_Oder_Admin();

		}else if (choice == 5) {
			//Back to Admin Window
			admin();
		}
		else if (choice == 6) {
			//Back to Main Window
			welcome();
		}
		else {
			cout << "\tInvalid selection!!!" << endl;
			Pre_Oder_Admin();
		}
	}
	void SignIn_registation() {
		int choise;
		cout << "\n\n\t1. STUDENT" << endl;
		cout << "\t2. ACADEMIC/NON-ACADEMIC STAFF" << endl;
		cout << "\t3. BACK TO MAIN WINDOW" << endl;
		cout << "\n\tSelect Your Option (1-3)" << endl;
		cin >> choise;
		cout << endl;

		if (choise == 1) {
			//Student
			create_Customer_Registration_First();//create customer registation by using linked list
			welcome();
		}
		else if (choise == 2) {
			//Academic / non Academic Staff
			create_Customer_Registration_First();//create ACADEMIC/NON-ACADEMIC STAFF registation by using linked list
			welcome();
		}
		else if (choise == 3) {
			//Back to Main Window
			welcome();
		}
		else {
			cout << "\tInvalid selection!!!" << endl;
			SignIn_registation();
		}
	}
	
	void user_details_input() {
		cout << "\tEnter Your Reg. No.\t\t: ";
		cin >> element;//element -> Reg No.
		cout << endl;
		cout << "\tEnter Your Name\t\t\t: ";
		cin >> name;
		cout << endl;
		cout << "\tEnter Your Contact Number\t: ";
		cin >> phoneNumber;
		cout << "\n\tSUCCESFULLY REGISTERED!!!" << endl;
		cout << endl;
	}
	int create_Customer_Registration_First() {//element=reg.No
		//create the node
		user_details_input();//input the user details
		//check if student previous register or not

		insertLast(element, name, phoneNumber);// Add customer details to the LINKED LIST

		Account* newAccount = new Account(element, name, phoneNumber); // Add customer details to HASH TABLE
		CustomerAccounts->insertAnAccount(newAccount);

		//enQueue(element, name, phoneNumber);
		return 0;
	}

	void registation() {
		int choise_AM;//Admin menu choise

		cout << "\n------------------ REGISTRATION------------------\n" << endl;
		cout << "\t1.REGISTER NEW CUSTOMER" << endl;
		cout << "\t2.DISPLAY ALL CUSTOMER DETAILS" << endl;
		cout << "\t3.MODIFY CUSTOMER RECORDS" << endl;
		cout << "\t4.DELETE CUSTOMER RECORDS" << endl;
		cout << "\t5.BACK TO ADMIN MENU" << endl;
		cout << "\t6.BACK TO MAIN MENU" << endl;
		cout << "--------------------------------------------------\n" << endl;
		cout << "\tPlease Enter Your Choice(1 - 6): " << endl;
		cin >> choise_AM;
		cout << endl;
		if (choise_AM == 1) {
			//CREATE NEW CUSTOMERS REGISTATION
			
			create_Customer_Registration_First();//create new customer using linked list
			registation();
		}
		else if (choise_AM == 2) {
			//DISPLAY ALL CUSTOMERS DETAILS
			display();
			registation();
		}
		else if (choise_AM == 3) {
			//MODIFY CUSTOMERS RECORDS
			cout << "\tEnter the Reg No, that should be modified : ";
			cin >> element;
			//enQueue(element, name, phoneNumber);
			int posi = search(element);
			cout << endl;
			user_details_input();
			insertAt(posi,  element,  name,  phoneNumber);
			deleteAt(posi+1);
			registation();
		}
		else if (choise_AM == 4) {
			//DELETE CUSTOMERS RECORDS
			cout << "\tEnter Registation Number to delete from list: ";
			cin >> element;
			deleteRegisterDetailsNode(element);//delete registation number in linked list
			CustomerAccounts->deleteAccount(element);//Delete Hash table
			registation();

		}
		else if (choise_AM == 5) {
			//BACK TO ADMIN MENU
			admin();
		}
		else if (choise_AM == 6) {
			//BACK TO MAIN MENU
			welcome();
		}
		else {
			cout << "\n\tInvalid selection!!!\n" << endl;
			registation();
		}
	}
	//-------------------------------CUSTOMER----------------------------
	void customer() {
		int choise;
		cout << "\n\t1. SHOW PRICE LIST" << endl;
		cout << "\t2. SHOW AVAILABLE FOOD ITEMS" << endl;
		cout << "\t3. PRE ORDER" << endl;
		cout << "\t4. BACK TO MAIN MENU" << endl;
		cout << "\t5. EXIT" << endl;
		cout << "\n\tSelect Your Option (1-5)" << endl;
		cin >> choise;
		cout << endl;

		if (choise == 1) {
			//Show Price List
			priceList();//showing default price list
			cout << endl;
			available_Food_Display();//showing Today available price list (By linked list)
			customer();
		}
		else if (choise == 2) {
			//Show Available food Item
			available_Food_Display();//showing default price list
			cout << endl;
			customer();
		}
		else if (choise == 3) {
			//Pre Oder
			preOderCustomer();//
			/*available_Food_Display();
			create_Pre_Oder_First();*/
			customer();
		}
		else if (choise == 4) {
			//Back to main menu
			
			welcome();
		}
		else if (choise == 5) {
			// Exit
			exit(0);
		}
		else {
			cout << "\tInvalid Selection" << endl;
			customer();
		}
	}
	//Customer Pre-Oder 
	void preOderCustomer() {
		int choice;

		Linked_list_Food_Add* foodList = getAddressOfFoodList();//get the address of foodlist
		cout << "\n\t1. SHOW AVAILABLE FOOD ITEMS" << endl;
		cout << "\t2. ADD PRE ORDER" << endl;
		//cout << "\t3. DELETE PRE ORDER" << endl;
		cout << "\t3. BACK TO MAIN MENU" << endl;
		cout << "\t4. EXIT" << endl;
		cout << "\n\tSelect Your Option (1-4)" << endl;
		cin >> choice;
		cout << endl;

		if (choice == 1) {
			//Show Show Available food Item
			available_Food_Display();//Show available food list
			preOderCustomer();
		}
		else if (choice == 2) {
			//Add Pre Oder
			checkregisterOrNot(foodList); //Checkinng the customer pre register or  nnot in the system
			FRQuantity(); // Reducing the available food quantity
			preOderCustomer();
		}
		/*else if (choice == 3) {
			//Delete Pre Oder
			cout << "\tEnter your Registation number : ";
			cin >> RegNumber;
			searchPreOder(RegNumber);//search element in the linked list
			deleteAt(PreOderposition);//delete in thelinked list 
			preOderCustomer();
		*/
		else if (choice == 4) {
			//Back to main menu
			welcome();
		}
		else if (choice == 5) {
			// Exit
			exit(0);
		}
		else {

		}
	}


	//check whether registation or not
	void checkregisterOrNot(Linked_list_Food_Add* list) {
	
		cout << "\tEnter the Reg No\t: ";//you want to ckeck if register 
		cin >> element;
		
		if (searchIfRegister(element)==true) {
			available_Food_Display();// show available foods
			create_Pre_Oder_First(list);//creadinng oders in Queues
		}
		else {
			cout << endl;
			cout << "\tCustomer is not Registered in The System" << endl;
			cout << "\tEnter The Registration Details to Register The System " << endl;
			cout << endl;
			create_Customer_Registration_First();
			cout << endl;
			available_Food_Display();
			cout << "\tInput Pre Oder Details  " << endl;
			cout << endl;
			create_Pre_Oder_First(list);
		}
	}
	//Update food quantity
	void FRQuantity() {
		
		int newFoodQuantity;//create new food quantity
		node* CurrentFoodAddLinkedList = Head; //point to the CurrentFoodAddLinkedList as the head of the node
		while (CurrentFoodAddLinkedList != NULL) {
			if (Pre_Oder_food_Code == CurrentFoodAddLinkedList->food_Code) {
				newFoodQuantity = (CurrentFoodAddLinkedList->available_Quanity) - (food_quanity);//update new quantity
				CurrentFoodAddLinkedList->available_Quanity = newFoodQuantity;
			}
			CurrentFoodAddLinkedList = CurrentFoodAddLinkedList->Next;
		}
	}
};