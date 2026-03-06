# CMPT_225

A repository for CMPT 225 assignments taken in the Spring 2025 semester


## Assignment02 - Linked List Queue

This is a QueueT template class to store data of any type. The queue is implemented using a singly linked list of nodes. The enqueue and dequeue methods are implemented in constant time.

#### Class Description
Class is named QueueT and supports these operations:

- Creating an empty queue
- Inserting a value
- Removing a value
- Finding the size of the queue
- Overloading the insertion operator to print the contents of the queue

#### Class Attributes
The class contains the following private member variables:

- A pointer to a NodeT that represents the front of the queue
- A pointer to a NodeT that represents the back of the queue
- An int that records the current size of the queue (i.e. the number of values in the queue)

#### QueueT Public Methods
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
    - A friend function (not a class method) to overload the insertion (output) operator (<<) to print the contents of a queue.

---

#### NodeT Class
The NodeT class has a template type attribute for its data and a pointer to the next NodeT in the list. The class should have constructors as you see fit 

The NodeT class is written in the QueueT.h file, above and outside the QueueT class definition.

---

### Queue Functions
Three template functions (described below) create new queues from existing queues. These functions are implemented in a separate file from your QueueT.h file. This file is named QFunctions.h. All three of the functions have the pre-condition that the input and output queues must contain the same type of data.

- qconcatenate – returns a QueueT object that contains the contents of its two QueueT parameters. The returned object contains the contents of the first parameter followed by the contents of the second parameter. If the first parameter contains {1,4,1}, and the second contains {7,6,8.3}, the returned queue should contain {1,4,1,7,6,8.3}.

- qmerge – returns a QueueT object that contains the contents of its two QueueT parameters. The returned object contains the merged contents of both parameters starting with the first value in the first parameter, followed by the first value in the second parameter, subsequent values should be copied – in order – from the two queues alternating between them. If the first parameter contains the values {a,b,c,d,e}, and the second contains the values {r,s,t}, the returned queue should contain {a,r,b,s,c,t,d,e}.

- qreverse – returns a QueueT object that contains the reversed contents of its single QueueT parameter. Your solution must be implemented using the STL stack template class. If the parameter contains the values {egg, dog, duck, cat}, the returned queue should contain {cat, duck, dog , egg}.


### Main Function

The main function is in a separate file from the QueueT class. The main function (and other test functions) is used to test the class and function methods.


## Assignment04 - Linked List Stack

A class called Stack represents a stack using a linked list data structure.

### Functionalities/Constructors:

**default constructor:** creates an empty tree whose root is a null pointer.

**copy constructor:** a constructor that creates a deep copy of its AVLTree reference parameter.

**operator= :** overloads the assignment operator for AVLTree objects to make a deep copy of its AVLTree reference parameter and return a reference to the calling object. The operator should behave correctly under self assignment.

**destructor:** deletes dynamic memory allocated by the tree

**insert:** if the tree does not contain the method's first parameter which represents the key, inserts the key and value (the second parameter) and returns true; otherwise returns false without insertion; i.e. the tree does not contain duplicate keys; both both key and value should be template parameters and may be different types

**remove:** removes the key and associated value from the tree where the key matches the method's parameter and returns true; if the tree does not contain the a key matching the parameter returns false

**search:** searches the tree for the key that equals the method's single parameter, returning the corresponding value if it is found and throwing a runtime_error exception if it is not

**values:** returns a vector that contains all of the values in the tree; the contents of the vector are in ascending key — not value — order; if the tree is empty the returned vector should also be empty

**keys:** returns a vector that contains all of the keys in the tree; the contents of the vector are in ascending order; if the tree is empty the returned vector should also be empty

**size:** returns an unsigned int equal to the number of items stored in the tree

**getRoot:** this method is provided to you in the .h file and you should not change it in any way. It returns a pointer to the tree's root node. Note that this violates class design principles, and in combination with the public AVLTreeNode class it allows other programmers access to the internal workings of the tree : again, not something to do in practice. Its purpose is to allow us access to the structure of your tree so that we can make sure that it is a valid AVL tree.



## Assignment05 - HashTable

### Functionalities/Constructors:

**default constructor:** creates a hash table of default size: 101; sets all array elements to the empty string (""); sets P2, the value used by h2 (which is described below under Second Hash Function)

**Constructor:** creates a hash table to store n items where the value of n is given by the constructor's single integer parameter, the size of the underlying array should be the smallest prime number equal to or greater than 2n; sets all array elements to the empty string; sets the value for P2 that is used by h2

**Copy Constructor:** a constructor that creates a deep copy of its HashTable reference parameter

**Destructor:** de-allocates any dynamic memory associated with the calling object

**operator= :** overloads the assignment operator for HashTable 

## objects
makes the calling object a deep copy of its HashTable reference parameter; returns a reference to the 
calling object

## insert
searches the hash table for the method's string parameter, if a matching string is not found it inserts the parameter string into the hash table; if the hash table's load factor is greater then 0.67 after insertion (1) creates a new hash table of size equal to the first prime number greater than twice the size of the original table, (2) sets the value used by h2 and (3) inserts the original contents in the new table at the appropriate places

## find
returns true if its string parameter is in the hash table, returns false if it is not

## size
returns the number of items stored in the hash table

## maxSize
returns the size of the hash table’s underlying array

## loadFactor
returns the load factor of the hash table as a double

## Hash Function
    string_value % array_size

Function must first generate the integer string_value from a given string. This value should be calculated by assigning the values 1 to 26 to the letters a to z (regardless of letter case) and calculating a unique value for each string by multiplying each character's value by 33letter position. A string of length n therefore has the following value:

    ch0 + ch1 * 331 + ch2 * 332 + … chn-1 * 33n-1
Where $ch_{0}$ is the left most character of the string and $n$ is the size of the string. For example, the string "cat" has this value:

    3 + 1 * 331 + 20 * 332 = 44,256
Note that using the result of this calculation on large strings will cause overflow. You should therefore use Horner's method to perform the calculation and apply the mod operator after computing each expression in Horner's method.  Horner's method was discussed in class.

To find the integer corresponding to a lower-case character at position i in a string str subtract 96 from the character:

    int asc = str[i] - 96; // ASCII a = 97

You may assume that your hash table will only be required to store strings with lowercase letters, and will not be tested with other characters.

## Second Hash Function for Collisions
The hash function to determine the distance to move from the initial index in the event of a collision should be generated by h2:

    P2 – (string_value % P2) 
where string_value is an integer representation of the string (discussed above) and P2 is the first prime number greater than array_size / 2. P2 should be stored as an attribute of the HashTable object and be calculated on construction of the object and when the hash table size doubles on insertion. This attribute should not be named P2 but should be given some descriptive name.


## Functions for spellcheck.h

### Return Values
#### success
if word parameter is in dict the result should contain word, and no other strings.
#### near-miss
if word is not in dict but dict contains strings similar to word – as determined by the function – the result should contain these near-misses in alphabetic order.
#### failure
if word is not in dict and dict contains no strings similar to word – as determined by the function – the result should be empty.

#### extraLetter
if word is not in dict returns all strings in dict that can be made by deleting a single letter from word

#### transposition
if word is not in dict returns all strings in dict that can be made swapping any two adjacent letters in word

#### missingSpace
if word is not in dict returns all pairs of strings in dict that can be made by inserting a single space in word; each string in the result should consist of the two strings from dict separated by a space

#### missingLetter
if word is not in dict returns all strings in dict that can be made by inserting any single letter of the alphabet at any position in word

#### incorrectLetter
if word is not in dict returns all strings in dict  that can be made by changing any single letter of word to a different letter in the alphabet