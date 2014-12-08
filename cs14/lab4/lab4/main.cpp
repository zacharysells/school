#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack<int> stack;
    Stack<int> stack_final;
    stack.postfix_eval("numb.txt");

    stack.print();
    
}//end main()
