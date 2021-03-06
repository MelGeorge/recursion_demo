#include <iostream>
#include <cassert>

// Lab 10 -- live coding starter code

using namespace std;

// Function for determining the summation of all
// natural numbers up to (and including) n
int summation(int n) {
    if(n == 1) {
        return 1;
    }
    else {
        return n + summation(n - 1);
    }
}

// Helper function
int summation_helper(int sum_so_far, int nums_to_add) {
    if(nums_to_add == 1) {
        return sum_so_far + 1;
    }
    else {
        return summation_helper(sum_so_far + nums_to_add, nums_to_add - 1);
    }
}

// A tail recursive implementation of the above
// summation function-- still determines the
// summation of all natural numbers up to
// (and including) n
int summation_tail(int n) {
    return summation_helper(0, n);
}

// Function for determining the nth fibonnacci
// number: remember that fibonacci numbers go
// like this: 0 1 1 2 3 5 8 13 21 34 ...
// Where each number is the sum of the previous 2
// Let's define fibonacci(0) = 0, fibonacci(1) = 1
int fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void print_usage_message() {
    cout << "Usage: ./recursion.exe --option--" << endl;
    cout << "option1: summation" << endl;
    cout << "option2: summation_tail" << endl;
    cout << "option3: fibonacci" << endl;
}

// Use this program to test one of the above
// functions at a time. Run w/ one of these 3:
// ./recursion.exe summation
// ./recursion.exe summation_tail
// ./recursion.exe fibonacci
int main(int argc, char * argv[]) {
    if(argc != 2) {
        print_usage_message();
        return 1;
    }
    string option = string(argv[1]);
    
    if(option == "summation") {
        assert(summation(1) == 1);
        assert(summation(2) == 3);
        assert(summation(3) == 6);
        assert(summation(10) == 55);
        cout << "Passed summation!" << endl;
    } else if(option == "summation_tail") {
        assert(summation_tail(1) == 1);
        assert(summation_tail(2) == 3);
        assert(summation_tail(3) == 6);
        assert(summation_tail(10) == 55);
        cout << "Passed summation_tail!" << endl;
    } else if(option == "fibonacci") {
        assert(fibonacci(0) == 0);
        assert(fibonacci(1) == 1);
        assert(fibonacci(2) == 1);
        assert(fibonacci(8) == 21);
        cout << "Passed fibonacci!" << endl;
    } else {
        print_usage_message();
        return 1;
    }
    return 0;
}

