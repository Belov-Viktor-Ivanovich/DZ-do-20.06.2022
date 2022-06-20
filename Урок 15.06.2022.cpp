// Связные списки Linked List
// 1. Односвязный список

#include <iostream>
#include"LinkedList.cpp"



int main()
{
	Man man1("Viktor", 30);
	Man man2("Ivan", 30);
	Man man3("Petr", 30);
	LinkedList<Man>list1(man1);
	list1.AddToHead(man2);
	list1.AddToHead(man3);
	list1.AddToTail(man3);
	list1.Show();
	//cout << list1[1] << endl;;
	list1.DeleteFromHead();
	cout << endl << endl;
	list1.Show();
	list1.DeleteFromTail();
	cout << endl << endl;
	list1.Show();
	list1.insert(man3, 1);
	cout << endl << endl;
	list1.Show();
	list1.removeAt(2);
	cout << endl << endl;
	list1.Show();
	list1.clear();
	cout << endl << endl;
	list1.Show();
}

