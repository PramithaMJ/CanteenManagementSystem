

//------------------------------------CANTEEN MANAGEMENT SYSTEM-----------------------------------
// 
                                  //EG/2020/3892 DHANUSHIKA M.G.D
                                  //EG/2020/3895 DILEN S.G.
                                  //EG/2020/3990 JAYASOORIYA L.P.M.
/*----------------------------------Login In UserName and passwords-------------------------------
* 
                                UserName: Dinithi   password: EG3892
                                UserName: Dilen     password: EG3895
                                Username: Pramitha  password: EG3990


    1. Linked list for student registrationand food adding
         Use a singly linked list to store the student records(Registration), including their name, registration number, and contact number.
        Use a separate linked list to store the available food items, including food name, quantity, and price.
    2. Queues for manage the pre - orders
         Use a queue to store the pre - orders placed by students.
         When a student places an order, add it to the end of the queue.
        When the order is ready, remove it from the front of the queue.
    3. Hash Table Used to create multiple logins at admin side
        Hash table for multiple login in admin. It get username and password
        Hash table for searching student detailsand food item lookup
        Hash table for Enter Admin(Password and user Name)
         Use a hash table to quickly look up student details by their registration number.
         Use the registration number as the keyand store the details of students.
         Student registration number can be used to get their details.
    4. Merge sort and insertion sort for sorting
         Use Merge sort to sort the student records by their registration number.
        Use insertion sort to sort the sold food items by using the food code .
*/

#include <iostream>
#include"admin.h"
#include"UserLoginHashTable.h"
#include"linkedList.h"
#include"queueWithLinkedList.h"
#include <string>
#include "Canteen Management System.h"
using namespace std;


int main() {
	Admin AD1;
	AD1.welcome();
	system("pause>0");
}