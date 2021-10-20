#include "chain.h"
#include "chain_given.cpp"
#include <cmath>
#include <iostream>

// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain()
{
    // Your code here -- hint: this one is a single line!
    clear();
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
void Chain::insertBack(const Block &ndata)
{
    // Your code here
}


/**
 * Swaps the two nodes at the indexes "node1" and "node2".
 * The indexes of the nodes are 1 based.
 * assumes i and j are valid (in {1,length_} inclusive)
 * 
 */
void Chain::swap(int i, int j)
{
    // Your code here!
}

/**
 * Reverses the chain
 */
void Chain::reverse()
{
    // Your code here!
}

/*
* Modifies the current chain by "rotating" every k nodes by one position.
* In every k node sub-chain, remove the first node, and place it in the last 
* position of the sub-chain. If the last sub-chain has length less than k,
* then don't change it at all. 
* Some examples with the chain a b c d e:
*   k = 1: a b c d e
*   k = 2: b a d c e
*   k = 3: b c a d e
*   k = 4: b c d a e
*/
void Chain::rotate(int k)
{
    // Your code here!
}

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear()
{
    // //Any node you create on the heap (using the 'new' statement) should be deleted
    //     //TODO: NEW APPROACH AFTER OH
    //     //other approach - work off structure of linkedlist. Other cases may get taken care of
    //     //else:
    //         //for loop - length - then delete the tail
    //         //iterate w/ 2 ptrs
    //             //1 for access to curr (so can delete after we've moved)
    //             //1 for access to next

    //     if (head_ == NULL) {
    //         //do nothing
    //     } else if (length_ == 0) {
    //         //only need to clear head and tail sentinels
    //         //head_->next = NULL; // superfluous
    //         //tail_->prev = NULL; // superfluous
    //         delete head_;
    //         head_ = NULL;
    //         delete tail_;
    //         tail_ = NULL;
    //     } else { //length_ > 0; have at least 1 data node
    //         //for loop over length_, then delete the tail
    //         //iterate w/ 2 ptrs
    //             //1 for access to curr (so can delete after we've moved)
    //             //1 for access to next
    //         Node* curr;
    //         Node* nextPtr;
    //         curr = head_;
    //         head_ = NULL;

    //         for (int i = 0; i <= length_ ; i++) {
    //             nextPtr = curr->next;
    //             //curr->next = NULL; //FIxME: optional?
    //             //nextPtr->prev = NULL; //FIXME: optional. Dubious - how much do I trust the length?
    //             delete curr;
    //             curr = nextPtr;
    //         }

    //         //FIXME: need to check if curr == tail_? b/c this should always be the case 
    //             //if you trust the rest of the surrounding program, don't need to check. If you want to be careful
    //         delete tail_; //may want to delete curr. But can also check curr == tail
    //         tail_ = NULL;
    //     }

    Node * curr = head_;
    Node * next;

    while (curr != NULL) {
        next = curr->next;
        delete(curr);
        curr = next;
    }
}


/* makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other)
{
    // // Your code here!
    // //FIXME: 'this' is a ptr to the current obj, correct? 
    //     //i.e. *this/(*)this/this-> gives us access to curr obj's member vars?
    // if (other.head_ == NULL || other.tail_ == NULL) {
    //     //do nothing. Structure must be broken. 
    // } else {
    //     this->head_ = new Node(); //FIXME: same as saying head_ = new Node();?
    //     this->tail_ = new Node();
    //     this->head_->prev = NULL; //FIXME: redundant, because it's init as NULL?
    //     this->tail_->next = NULL; //FIXME: above
    //     if (other.head_->next == other.tail_) { // && other.tail_->prev == other.head_ && length_ == 0 //FIXME: added robustness? Can't conceive of a 0-length case in which this isn't true 
    //         //implicitly, length = 0
    //         this->head_->next = this->tail_;
    //         this->tail_->prev = this->head_;

    // } else { // length > 0

    // }    
    // }
}

/***********************************
 * swapColumns
 * parameters: 1 <= i <= numCols_
 *              1 <= j <= numCols_
 *
 * Swaps the positions of columns i and j
 * in the original grid of blocks by
 * moving nodes in the chain.
 *
 ***********************************/

void Chain::swapColumns(int i, int j) {

    // Your code here
}

/***********************************
 * swapRows
 * parameters: 1 <= i <= numRows_
 *              1 <= j <= numRows_
 * 
 * Swaps the positions of rows i and j
 * in the original grid of blocks by
 * moving nodes in the chain.
 *
 ***********************************/
void Chain::swapRows(int i, int j) {

    // Your code here
}

