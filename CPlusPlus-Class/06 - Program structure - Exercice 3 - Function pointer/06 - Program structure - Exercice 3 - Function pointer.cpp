
#include <iostream>
#include <vector>

class NumberStorage
{
    // a collection of integers
	std::vector<int> numbers;
    // Pointer to the mysterious function
    void (*callback)(int);

public:
    // This method add a number into the vector then call the mysterious function
    void add(int numbertoAdd)
    {
        numbers.emplace_back(numbertoAdd);
        callback(numbers.back());
    }

    // The function pointer is private, we need a method to connect
	void connectCallback(void(*functionToCall)(int))
    {
        callback = functionToCall;
    }

};

// Message to display into your function
const std::string message = "Int to display : ";

// The mysterious function
void callbackDisplay(int numberToDisplay)
{
    // Fill the function
    // Display a message and the value of the number
    std::cout << message << numberToDisplay << std::endl;
}

int main()
{
    NumberStorage myNumberStorage;

    // Connect together callback(int) member
    myNumberStorage.connectCallback(callbackDisplay);

    // Add some number, each addtion should call callbackDisplay
    myNumberStorage.add(2);
    myNumberStorage.add(20);
}
