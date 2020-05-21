#include "List.h"

int main()
{
	List<int> lst;
	lst.insertFirst(5);
	lst.insertFirst(7);
	lst.insertFirst(101);
	lst.insertFirst(102);
    cout << "List of entered elements:" << endl;
	lst.print();
	cout << endl << "Last element will now be deleted" << endl << endl;
	lst.deleteLast();
	cout << "New list:" << endl;
	lst.print();
	int z=lst.getFirst();
	cout <<"\nFirst element: " << z;
	z=lst.getLast();
	cout <<"\nLast element: " << z;
	return 0;
}

