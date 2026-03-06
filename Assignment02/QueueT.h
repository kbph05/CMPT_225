/**
 * @file QueueT.h
 * @author Kirstin Horvat
 * @date 31/01/2025
 * @brief Declarations for the QueueT and NodeT classes
 * 
 */
/**
 QueueT class methods:
 * constructor – creates an empty queueS
    copy constructor – a constructor that creates a deep - copy of its constant QueueT reference parameter
    destructor – deallocates dynamic memory allocated by the queue
    operator= – overloads the assignment operator for QueueT – (deep) copies its constant QueueT reference parameter into the calling object and returns a reference to the calling object after de-allocating any dynamic memory associated with the original contents of the calling object; if the calling object is the parameter the operator should not copy it
    enqueue – inserts its template type parameter at the back of the queue
    dequeue – removes and returns the value at the front of the queue; if the queue is empty throws a runtime_error (this error class is defined in the stdexcept library file)
    empty – returns true if the queue is empty, false otherwise
    size – returns the number of items stored in the queue
    QueueT Friend Function - A friend function (not a class method) to overload the insertion (output) operator (<<) to print the contents of a queue. You can find a discussion about how to do this in the Operator Overloading Lab.
*/

#pragma once

//include statements
class NodeT{
         //… includes constructor definitions …
};

class QueueT{
         //…
};

// //QueueT method implementations
// QueueT::QueueT()
// {
//          //…
// }