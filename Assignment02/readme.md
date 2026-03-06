# Linked list queue assignment 2

## Part 1 - Queue Class
This is a QueueT template class to store data of any type. The queue is implemented using a singly linked list of nodes. The enqueue and dequeue methods are implemented in constant time.

### Class Description
Class is named QueueT and supports these operations:

- Creating an empty queue
- Inserting a value
- Removing a value
- Finding the size of the queue
- Overloading the insertion operator to print the contents of the queue

### Class Attributes
The class contains the following private member variables:

- A pointer to a NodeT that represents the front of the queue
- A pointer to a NodeT that represents the back of the queue
- An int that records the current size of the queue (i.e. the number of values in the queue)

### QueueT Public Methods
 The QueueT class implements the following public methods:

- constructor – creates an empty queue
- copy constructor – a constructor that creates a deep - copy of its constant QueueT reference parameter
- destructor – deallocates dynamic memory allocated by the queue
- operator= – overloads the assignment operator for QueueT – (deep) copies its constant QueueT reference parameter into the calling object and returns a reference to the calling object after de-allocating any dynamic memory associated with the original contents of the calling object; if the calling object is the parameter the operator should not copy it
- enqueue – inserts its template type parameter at the back of the queue
- dequeue – removes and returns the value at the front of the queue; if the queue is empty throws a runtime_error (this error class is defined in the stdexcept library file)
- empty – returns true if the queue is empty, false otherwise
- size – returns the number of items stored in the queue

**QueueT Friend Function**
    - A friend function (not a class method) to overload the insertion (output) operator (<<) to print the contents of a queue. You can find a discussion about how to do this in the Operator Overloading Lab.

### Requirements Notes
- The calling object should be made constant for any method where the calling object's attribute values should not change
- You may implement helper methods if you wish (for example, you might want to implement a private method that does the work of copying the parameter to the calling object and then call it in both the copy constructor and the overloaded assignment operator)
- Your class may include other private attributes that you deem necessary - unless the entail significant changes to the structure of the queue described in this document
- Method parameters and return values are noted (and highlighted) in the method descriptions – you must not add additional parameters to the methods; if the method description does not mention a parameter it does not have one, similarly if no return value is mentioned the method is void (or a constructor or destructor)
- The parameter type for enqueue and the return type of dequeue should be your template variable – see the implementation notes near the end of this document

### NodeT Class
The NodeT class has a template type attribute for its data and a pointer to the next NodeT in the list. The class should have constructors as you see fit 
- I would suggest one with two parameters that sets the data and next NodeT (pointer) to the parameter values and one with a single template type parameter that sets its next pointer to a nullptr.

The NodeT class is written in the QueueT.h file, above and outside the QueueT class definition. Your NodeT constructors should be written in the NodeT class definition, and not in a separate NodeT.cpp file.

### Implementation Notes
The way I would suggest approaching writing the assignment is something like this:

1. Create a new project with a file that contains a main function that you will use for testing; add a new (empty) QueueT class to the project; then compile and run your project to make sure it is set up correctly
2. Write your NodeT and QueueT classes as regular, non-template, classes that store a base type, like an int, testing methods as you implement them
3. Write, and thoroughly test, one or two functions at a time.
4. Once your class is working perfectly convert it into a template class
    
    Note that Bjarne Stroustrup. recommends implementing template classes by first implementing a non-template class version - and I suspect his advice is worth following!

### Template Testing
Test the template class with at least one non-numeric type

### File Structure
Template classes are often contained in a single .h file as there are compilation issues with breaking them down into separate files, and this is what I want you to do for this assignment. I still want you to keep the implementation separate from the interface as much as possible within this structure, so your method implementations should appear below your QueueT class definition. Your .h file will therefore have this general structure.

```
//include statements
class NodeT{
         //… includes constructor definitions …
};

class QueueT{
         //…
};

//QueueT method implementations
QueueT::QueueT()
{
         //…
}
...
```
## Part 2 - Queue Functions
Three template functions (described below) create new queues from existing queues. These functions are implemented in a separate file from your QueueT.h file. This file is named QFunctions.h. All three of the functions have the pre-condition that the input and output queues must contain the same type of data.

- qconcatenate – returns a QueueT object that contains the contents of its two QueueT parameters. The returned object contains the contents of the first parameter followed by the contents of the second parameter. If the first parameter contains {1,4,1}, and the second contains {7,6,8.3}, the returned queue should contain {1,4,1,7,6,8.3}.
- qmerge – returns a QueueT object that contains the contents of its two QueueT parameters. The returned object contains the merged contents of both parameters starting with the first value in the first parameter, followed by the first value in the second parameter, subsequent values should be copied – in order – from the two queues alternating between them. If the first parameter contains the values {a,b,c,d,e}, and the second contains the values {r,s,t}, the returned queue should contain {a,r,b,s,c,t,d,e}.
- qreverse – returns a QueueT object that contains the reversed contents of its single QueueT parameter. Your solution must be implemented using the STL stack template class. If the parameter contains the values {egg, dog, duck, cat}, the returned queue should contain {cat, duck, dog , egg}.
### Notes
The QueueT parameters should not be reference parameters - that is they should be passed by value. Make sure your copy constructor works correctly (by testing it carefully) before implementing these three functions.
Since you are to use the STL stack template class, your header file must include <stack>.
Simple Test

Below is a test function for the QueueT class. It is a very simple and incomplete test of each of the methods. To reiterate - this is not an adequate test of the class! However, if you can't compile and run this simple test then the assignment is not ready for submission.
```
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
 
	cout << "END SIMPLE TEST;
}
````

## Main Function
The main function is in a separate file from the QueueT class. The main function (and other test functions) is used to test the class and function methods. Do not submit the file containing the main function.

I would strongly suggest compiling and running your program after you complete each method (or couple of methods), do not try to complete the entire class before testing it as this will almost certainly end up being considerably more work.

## Submission
Submit the assignment online as a .zip file containing your QueueT.h and QFunctions.h files and no other files or folders.

If you are unable to complete a method or function you must write a stub for it.

