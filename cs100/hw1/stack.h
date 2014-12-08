#define STACK_CAPACITY 50
class Stack
{
	char data[STACK_CAPACITY];
	int current; //Next available data location
	
	public:
	
	Stack(); // constructor for a stack
	
	void push(char c); //adds c to the top of the stack
	
	char pop(); // removes top element, returns it
	
	char top(); // returns the top element
	
	bool isEmpty(); // returns true iff the stack is empty
	
	~Stack(); // destructor for a stack
	
};
