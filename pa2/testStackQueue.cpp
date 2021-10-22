#define CATCH_CONFIG_MAIN
#include <iostream>
#include "cs221util/catch.hpp"
#include "stack.h"
#include "queue.h"
#include <assert.h>

//using namespace cs221util;
using namespace std;

TEST_CASE("stack::Anirudh's test - basic push & isEmpty", "[weight=1][part=stack]") {
    cout << "Testing stack -- Anirudh's test for basic push & isEmpty..." << endl;
    Stack<int> intStack;

    bool initiallyEmptyTrue = intStack.isEmpty();
    REQUIRE(initiallyEmptyTrue == true);

    intStack.push(1);

    bool eventuallyEmptyFalse = intStack.isEmpty();
    REQUIRE(eventuallyEmptyFalse == false);
}

TEST_CASE("stack::Anirudh's test - basic pop", "[weight=1][part=stack]") {
    cout << "Testing stack -- Anirudh's test for basic pop" << endl;
    Stack<int> intStack;

    bool initiallyEmptyTrue = intStack.isEmpty();
    REQUIRE(initiallyEmptyTrue == true);

    intStack.push(1);
    intStack.push(2);

    int poppedTwo = intStack.pop();
    REQUIRE(poppedTwo == 2);
    bool intermediateEmptyFalse = intStack.isEmpty();
    REQUIRE(intermediateEmptyFalse == false);

    int poppedOne = intStack.pop();
    REQUIRE(poppedOne == 1);
    bool eventuallyEmptyTrue = intStack.isEmpty();
    REQUIRE(eventuallyEmptyTrue == true);
}

// TEST_CASE("stack::basic functions","[weight=1][part=stack]"){
//     //cout << "Testing Stack..." << endl;
//     Stack<int> intStack;
//     vector<int> result;
//     vector<int> expected;

//     for (int i = 10; i > 0; i--) {
//         expected.push_back(i);
//     }

//     for (int i = 1; i <= 10; i++) {
//         intStack.push(i);
//     }

//     //cout << intStack.peek() << endl;
//     while (!intStack.isEmpty()) {
//         result.push_back(intStack.pop());
//         //cout << intStack.pop() << " ";
//     }

//     REQUIRE( result == expected);
// }



// TEST_CASE("stack::Anirudh's test -- peek w/o removing", "[weight=1][part=stack]") {
//     cout << "Testing stack -- Anirudh's test for peek w/o removing..." << endl;
//     Stack<int> intStack;

//     intStack.push(0);
//     int shouldBeZero = intStack.peek();
//     bool isEmptyShouldBeFalse = intStack.isEmpty();
//     REQUIRE(shouldBeZero == 0);
//     REQUIRE(isEmptyShouldBeFalse == false);
// }

// TEST_CASE("stack::Anirudh's test -- peek then pop then peek", "[weight=1][part=stack]") {
//     cout << "Testing stack -- Anirudh's test for peek then pop then peek..." << endl;
//     Stack<int> intStack;

//     intStack.push(0);
//     intStack.push(1);

//     int shouldBeOnePeeked = intStack.peek();
//     int shouldBeOnePopped = intStack.pop();
//     int shouldBeZeroPeeked = intStack.peek();
//     bool isEmptyShouldBeFalse = intStack.isEmpty();

//     REQUIRE(shouldBeOnePeeked == 1);
//     REQUIRE(shouldBeOnePopped == 1);
//     REQUIRE(shouldBeZeroPeeked = 0);
//     REQUIRE(isEmptyShouldBeFalse == false);
// }


// TEST_CASE("queue::basic functions","[weight=1][part=queue]"){
//     //cout << "Testing Queue..." << endl;
//     Queue<int> intQueue;
//     vector<int> result;
//     vector<int> expected;
//     for (int i = 1; i <= 10; i++) {
//         expected.push_back(i);
//     }
//     for (int i = 1; i <= 10; i++) {
//         intQueue.enqueue(i);
//     }
//     //cout << intStack.peek() << endl;
//     while (!intQueue.isEmpty()) {
//         result.push_back(intQueue.dequeue());
//         //cout << intStack.pop() << " ";
//     }
//     REQUIRE( result == expected);
// }

