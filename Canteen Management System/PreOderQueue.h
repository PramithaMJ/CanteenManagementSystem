#pragma once
#include<iostream>
#include<limits>
#include"preOderLinkedList.h"
using namespace std;

class Pre_Oder_Queue_LinkedList :public Pre_Oder_Linked_list {

public:
	//To add pre oder to the queue 
	void enQueuePreOder(int RegNumber, int food_Code, int food_quanity) {
		preOdernode* temp = new preOdernode(RegNumber, food_Code, food_quanity);
		if (head2 == NULL) {
			head2 = temp;
			tail2 = temp;
			size++;
		}
		else {
			insertPreOderLast(RegNumber, food_Code, food_quanity);
			//size++;
		}
	}
	int deQueuePreOder() {
		if (head2 == NULL) {
			cout << "\tNO Any Pre-Oder" << endl;
			return INT_MIN;
		}
		else {
			int ret_val = head2->RegNumber;
			deletePreOderFirst();
			return ret_val;
		}
	}

    //-----------------------------------------------------------------------------------------------------------------------------
    // Node structure for linked list


    // Function to merge two sorted linked lists
    preOdernode* mergeLists(preOdernode* list1, preOdernode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->RegNumber < list2->RegNumber) {
            list1->next = mergeLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeLists(list1, list2->next);
            return list2;
        }
    }

    // Function to perform merge sort on a linked list
    preOdernode* mergeSort(preOdernode* head) {
        if (!head || !head->next) return head;

        preOdernode* slow = head2;
        preOdernode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        preOdernode* list2 = slow->next;
        slow->next = nullptr;

        return mergeLists(mergeSort(head), mergeSort(list2));
    }
    void printSorted() {
        cout << endl;
        cout << "\tSorted by Registation  Number: " << endl;
  
        preOdernode* currentSorted = head2;
        while (currentSorted!=NULL) {
            cout << "\tReg. No.\t\t" << currentSorted->RegNumber << "\t";
            cout << "\tPre-Oder Code\t" << currentSorted->Pre_Oder_food_Code << "\t";
            cout << "\tFood Quantity\t" << currentSorted->food_quanity << "\t" << endl;
            currentSorted = currentSorted->next;
        }
    }
};