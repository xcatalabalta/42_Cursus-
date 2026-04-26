/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 10:55:49 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/09 10:39:40 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/iter.class.hpp"
#include <climits>


// Defining set of colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BLINK 	"\033[5m"

void 	goNext(std::string msg)
{
	std::string line;
	std::cout   << "\033[32m\nTake your time to revise the accuracy "
					<< "of the above implementation.\n"
				<< "Enter any key to continue with the next section:"
				<< "\033[1;4m" << msg << "\033[0m"
				<< std::endl;
	std::getline(std::cin, line);
	line.clear();	
}
// Testing a more compressed way to code
// Classes
class IntClass
{
	private:
		int m_n;

	public:
		IntClass(void) : m_n(42) {return;}
		IntClass(int n) : m_n(n) {return;}
		IntClass &operator=(const IntClass & other) {this->m_n = other.m_n; return (*this);}
		~IntClass(){}
		int get(void) const {return this->m_n;}
		void set(const int &num) {this->m_n = num; return;}
};

//Overides
std::ostream & operator<<(std::ostream & o, IntClass const & rhs)
{
	o << rhs.get();
	return o;
}
// Functors
class MultiplyBy 
{
	private:
		int m_factor;
	public:
		MultiplyBy(int factor) : m_factor(factor) {}
    	void operator()(int& num) const 
		{
        	std::cout << "Number: " << num << " x " << m_factor << " = "
        	          << num * m_factor << std::endl;
			num *= m_factor;
    	}
};

class MultipIntClass 
{
	private:
    	int m_value;
	public:
    	MultipIntClass(int value) : m_value(value) {}
    	void operator()(IntClass &obj) const 
    	{
        	obj.set(obj.get()*m_value);
    	}
};

// Flexible functor able to multiply or assign integers
// Private must be written at the end to use enum
class FlexSetIntClass
{
	public:
		enum Mode {MULTIPLY, ASSIGN};
		FlexSetIntClass()
			: m_value(42), m_mode(ASSIGN) {}
		FlexSetIntClass(int value, Mode mode = ASSIGN)
			: m_value(value), m_mode(mode) {}
		FlexSetIntClass& operator()(Mode new_mode)
    	{
        	m_mode = new_mode;
        	return *this;
    	}
	void operator()(IntClass &obj) const 
    {
        if (m_mode == MULTIPLY)
            obj.set(obj.get() * m_value);
        else
            obj.set(m_value);
    }
	void setValue(int new_value) {m_value = new_value;}
	void setMode(Mode new_mode) {m_mode = new_mode;}
	
	private:
    	int m_value;
    	Mode m_mode;
	
};

class MaxTracker 
{
		private:
    	int m_max;
		
		public:
    	MaxTracker() : m_max(INT_MIN) {}
    	void operator()(int num) 
    	{
        	if (num > m_max) 
        	{
            	this->m_max = num;
        	}
    	}
    	int getMax() const { return m_max; }
};

//Templates
template< typename T >
void display(T& element)
{
	std::cout << element << std::endl;
	return;
}


template<typename T>
void fourTimes(T& element)
{
	element*= 4;
}

template<typename T>
void incrElement(T &element)
{
	++element;
}

// Override for string
void incrElement(std::string &element)
{
	std::cout << "Not possible to sum String" << std::endl;
	static_cast<void>(element);
}

//Numeric Functions
void doubleValue(int &value) 
{
	value *= 2;
	std::cout << "Doubled value: " << value << std::endl;
}

//It doesn't modify the values of the array
void sumFloat(float f) 
{
	f += 3.14f;
	std::cout << "Added a float: " << f << std::endl;
}

//String functions
void strToUpper(std::string *str)
{
	for (size_t i = 0; i < str->size(); i++)
	{
		(*str)[i] = static_cast<char>(std::toupper((*str)[i]));
	}
	return ;
}

void strToUpper(std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = static_cast<char>(std::toupper((str)[i]));
	}
}

void shout(std::string str) 
{
	strToUpper(&str);
	std::cout << RED << "HEY! " << str << "!!!" << RESET << std::endl;
}


void checkEvenOdd(int &num) 
{
	if (num % 2 == 0)
		std::cout << num << " is even." << std::endl;
	else
		std::cout << num << " is odd." << std::endl;
}

//Char function
void checkEvenOdd(char &c) 
{
	if (c % 2 == 0)
		std::cout << "'" << c << "' is even (ASCII " << static_cast<int>(c) << ")." << std::endl;
	else
		std::cout << "'" << c << "' is odd (ASCII " << static_cast<int>(c) << ")." << std::endl;
}

int main(void) 
{
	{
		std::cout << GREEN << "Testing numbers" << RESET << std::endl;
		int arr1[] = {1, 2, 3, 4, 5, 6, 17, 8, 9, 10};
		int arr2[] = {42, 17, 99, 0, -8};
		std::cout << GREEN << "Displaying arr1:" << RESET << std::endl;
		iter(arr1, 10, display);
		std::cout << GREEN << "\nDisplaying arr2:" << RESET << std::endl;
		iter(arr2, 5, display);
		std::cout << GREEN << "\nTest Int Array x 2 in arr1" << RESET << std::endl;
		iter(arr1, 10, doubleValue);
		std::cout << GREEN << "\nChecking even or odd:" << RESET << std::endl;
		iter(arr2, 5, checkEvenOdd);
		std::cout << GREEN << "\nChecking multiplication by a number:" << RESET << std::endl;
		iter(arr2, 5, MultiplyBy(32));
		std::cout << GREEN << "\nModified array:" << RESET << std::endl;
		iter(arr2, 5, display);
		goNext("");
		std::cout << GREEN << "\nChecking increasing values (++element)" << RESET << std::endl;
		std::cout << GREEN << "Displaying arr1:" << RESET << std::endl;
		iter(arr1, 10, display);
		iter(arr1, 10, incrElement);
		std::cout << GREEN << "\nModified array:" << RESET << std::endl;
		iter(arr1, 10, display);
		std::cout << GREEN << "\nChecking multiplying first 5 values of arr1 x 4" << RESET << std::endl;
		iter(arr1, 5, fourTimes);
		std::cout << GREEN << "\nModified array:" << RESET << std::endl;
		iter(arr1, 10, display);
		goNext("");
		std::cout << BLUE << "\nGetting a max from an array of ints (arr1 after modification)" << RESET << std::endl;
		MaxTracker tracker;
		iter(arr1, 10, tracker);
		std::cout << "The max of arr1 is => " << BLINK << RED << tracker.getMax() << RESET << std::endl;
		goNext("");
		std::cout << GREEN << "\nTest floats (array not modified)" << RESET << std::endl;		
		float floatArr[] = {1.1f, 2.2f, 3.3f};
		std::cout << GREEN << "Displaying floatArr:" << RESET << std::endl;
		iter(floatArr, 3, display);
		std::cout << GREEN << "\nJust to make something with a float" << RESET << std::endl;
		iter(floatArr, 3, sumFloat);
		std::cout << GREEN << "\nModifying values of floatArr*=4" << RESET << std::endl;
		iter(floatArr, 3, fourTimes);
		std::cout << GREEN << "\nDisplaying floatArr:" << RESET << std::endl;
		iter(floatArr, 3, display);
		std::cout << GREEN << "\nTesting arrays of objects (IntClass)" << RESET << std::endl;
		IntClass bum(22);
		bum = IntClass(69);
		IntClass tab2[5];
		IntClass tab3[] = {IntClass(1), bum, IntClass(-42)};
		int modif = 10;
		std::cout << GREEN << "\nDisplaying first object:" << RESET << std::endl;
		iter(tab2, 5, display);
		std::cout << GREEN << "\nSetting a new value ("<< modif <<" * original value) to first Object:" << RESET << std::endl;
		iter(tab2, 5, MultipIntClass(modif));
		std::cout << GREEN << "\nRe-displaying first object (modified):" << RESET << std::endl;
		iter(tab2, 5, display);
		std::cout << GREEN << "\nDisplaying second object:" << RESET << std::endl;
		iter(tab3, 3, display);
		modif = -34;
		std::cout << GREEN << "\nSetting a new value ("<< modif <<" * original value) to second Object:" << RESET << std::endl;
		iter(tab3, 3, MultipIntClass(modif));
		std::cout << GREEN << "\nRe-displaying second object (modified):" << RESET << std::endl;
		iter(tab3, 3, display);
		goNext("\033[36m\nTesting a flexible modifyier, setter class\033[0m");
	}
	{
		IntClass arrInt[3] = {IntClass(1), IntClass(2), IntClass(3)};
		int modif = 10;
		std::cout << CYAN << "\nDisplaying object:" << RESET << std::endl;
		iter(arrInt, 3, display);
		std::cout << CYAN << "\nMultiplying object by: "<< modif << RESET << std::endl;
		FlexSetIntClass multi(modif, FlexSetIntClass::MULTIPLY);
		iter(arrInt, 3, multi);
		iter(arrInt, 3, display);
		std::cout << CYAN << "\nSetting all values to: "<< modif << RESET << std::endl;
		FlexSetIntClass setter(modif);
		iter(arrInt, 3, setter);
		iter(arrInt, 3, display);
		modif = 25;
		setter.setValue(modif);
		setter.setMode(FlexSetIntClass::MULTIPLY);
		std::cout << CYAN << "\nMultiplying object by: "<< modif << RESET << std::endl;
		iter(arrInt, 3, setter);
		iter(arrInt, 3, display);
		goNext("\nTesting chars and strings");
	}
	{
		//std::cout << GREEN << "\nTesting chars and strings" << RESET << std::endl;
		std::cout << std::endl << GREEN << "Test Char Array before increasing values (++element)" << RESET << std::endl;
		char arrChar[3] = {'a', 'b', 'c'};
		size_t size = 3;
		iter(arrChar, size, display);
		std::cout << std::endl << GREEN << "Test Char Array after increase" << RESET << std::endl;
		iter(arrChar, size, incrElement);
		iter(arrChar, size, display);
		std::cout << std::endl << GREEN << "Test Char Array after even/odd" << RESET << std::endl;
		iter(arrChar, size, checkEvenOdd);
		std::string arrStr[3] = {"Xavier", "Merceditas", "Rigoberto"};
		std::cout << GREEN << "\nTest Str Array: display" << RESET << std::endl;
		iter(arrStr, 3, display);
		std::cout << GREEN << "\nTest Str Array: incrElement and shouting first 2 elements" << RESET << std::endl;
		iter(arrStr, 3, incrElement);
		std::cout << GREEN << "\nTest Str Array: Shouting first 2 elements (shouting doesn't change anything)" << RESET << std::endl;
		iter(arrStr, 2, shout);
		std::cout << GREEN << "\nTest Str Array: display that nothing has changed after shouting" << RESET << std::endl;
		iter(arrStr, 3, display);
		std::cout << GREEN << "\nTest Str Array: Capitalizing the array" << RESET << std::endl;
		iter(arrStr, 3, strToUpper);
		iter(arrStr, 3, display);
	}
		
	return 0;
}