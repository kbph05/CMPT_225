

#include <iostream>
#include "QueueT.h"
#include <iostream>  

using namespace std;

void simpleTest()
{
	cout << "SIMPLE TEST" << endl;
	QueueT<int> q1;
 
	q1.enqueue(2);
	q1.enqueue(4);
	q1.enqueue(6);
 
	cout << "empty: 0 = " << q1.empty() << endl;
	cout << "print: {2,4,6} = ";
	cout << q1 << endl;
	cout << "size: 3 = " << q1.size() << endl;
 
	QueueT<int> q2(q1);
	QueueT<int> q3;
        q3.enqueue(42);
	q3 = q1;
 
	q1.dequeue();
 
	cout << "q1 post copy: {4,6} = " << q1 << endl ;
	cout << "q2 (copy): {2,4,6} = " << q2 << endl ;
	cout << "q3 (op=): {2,4,6} = " << q3 << endl ;
 
	cout << "END SIMPLE TEST" << endl;
}

int main() {
    simpleTest();
    return 0;
}
