/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:33:54 by fcatala-          #+#    #+#             */
/*   Updated: 2025/06/17 20:01:00 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib> //for random
//#include <iostream> // already included at Array.class.hpp
#include <typeinfo>
#include "incl/Array.class.hpp"

#define MAX_VAL 50

template <typename T, unsigned int n >
unsigned int arrayLength(T (&)[n])
{
    return (n);
}

template <typename T>
unsigned int arrayLength(T &a)
{
    return a.size();
}

template <typename T>
void display (T (&a), std::string one)
{
    std::cout       <<"Displaying "<< one << std::endl;
    for (unsigned int i = 0; i < arrayLength(a); i++)
    {
        std::cout   << "Value["<< i <<"] of "<< one << ":\t";
        if (typeid(a[i]) == typeid(char))
        {
                std::cout << "'" << a[i] << "'" << "\n";
        }
        else
        {
                std::cout << a[i] << "\n";      
        }
    }
}

template <typename T, typename U>
void  compare (T (&a), U (&b), std::string one, std::string two)
{
    unsigned int  size = std::min(arrayLength(a), arrayLength(b));

    if (arrayLength(a) == 0 && arrayLength(b) == 0)
    {
        std::cout   << "\nBoth arrays are \033[1;5;35mempty\033[0m!" << std::endl;
        return ;
    }
    if (arrayLength(a) == 0 && arrayLength(b) > 0)
    {
        std::cout   << "\n\033[1;5;35m" << one <<"\033[0m is empty!" << std::endl;
        ::display(b, two);
        return ;
    }
    if (arrayLength(b) == 0 && arrayLength(a) > 0)
    {
        std::cout   << "\n\033[1;5;35m" << two <<"\033[0m is empty!" << std::endl;
        ::display(a, one);
        return ;
    }
    std::cout       <<"\nComparison between "
                    << one << " and "<< two << std::endl;
    for (unsigned int i = 0; i < size; i++)
    {
        try 
        {
            std::cout   << i + 1 << " Value of " << one << ":\t";
            if (typeid(a[i]) == typeid(char))
            {
                std::cout   << "'" << a[i] << "'" << "\n";
            }
            else
            {
                std::cout << a[i] << "\n";      
            }
            std::cout   << i + 1 << " Value of " << two << ":\t";
            if (typeid(b[i]) == typeid(char))
            {
                std::cout   << "'" << b[i] << "'" << "\n";
            }
            else
            {
                std::cout << b[i] << "\n";          
            }
        }
        catch (const std::exception& e)
        { 
                std::cout   << e.what() << " at value " << i
                            << std::endl;
        }
        catch (...)
        {
            std::cout   << "Unexpected error." << std::endl;
        }
    }
}

template <typename T>
void debugPrint(const T& value, int line, const char* file = __FILE__)//, int line = __LINE__) 
{
    std::cerr   << "DEBUG: " << file << "\t\033[1;31mline:" << line 
                << "\tvariable value: " << value << "\033[0m"
                << std::endl;
}

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

int main(int, char**)
{
    {   
        std::cout << "\nThe +/- given main starts here.\n\n" << std::endl;
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        int line = 0;
        int testVal = 0;
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            line = __LINE__;
            testVal = -2;
            numbers[testVal] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            debugPrint(testVal, line);
        }
        try
        {
            line = __LINE__;
            testVal = MAX_VAL;
            numbers[testVal] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            debugPrint(testVal, line);
        }
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;
        std::cout << "\nThe +/- given main ends here." << std::endl;
        goNext("\nAssignation and comparison of different types of arrays using templates");
    }
    {
        unsigned int tigg = 8;
        const std::string group[5] = {"hola!", "que", "hases", "por", "aqui?"};
        std::string gang[6] = {"Sylvie", "Tom", "Rita", "Oscar", "Nath", "Gael"};
        Array<std::string> lista(tigg);
        Array<std::string> copy;
        Array<int> nums(tigg);
        Array<char> buid;
        Array<char> charito(tigg);
        int line = 0;

        std::cout   << "We are going to store random values of " << std::endl;
        display(group, "group");
        std::cout   << "In an array of " << tigg << " elements\n" 
                    << "At the same time we try to fill an array of "<< tigg << " integers "
                    << "with a loop of " << lista.size() + 3 << " iterations.\n"
                    << "The random selection will try to pick elements from 0 to "<< tigg << "\n"
                    << "In other words, a real mine camp for the code.\n\n"
                    << "Let's enjoy the try catch\n"
                    << std::endl;
        for (unsigned int i = 0; i < lista.size() + 3; ++i)
        {
            try
            {
                unsigned int value = static_cast<unsigned int> (rand() % tigg);
                nums[i] = value;
                std::cout << "Iteration "<< i << std::endl;
                std::cout << "Trying to take the element number "<< value << std::endl;
                if (value >= arrayLength(group))
                {
                    std::cout   << value << " is larger than the size of the group (from 0 to "
                                << arrayLength(group) - 1 << ").\n"
                                << "The ["<< value % 5 << "] element is going to be marked and taken."
                                << std::endl;                    
                    lista[i] = group[value % 5] + "\033[3;32mX\033[0m";
                    std::cout   << lista[i] << " stored." << value
                                << std::endl;
                    throw ("Value changed\n");
                }
                else
                {
                    lista[i] = group[value];
                }
                std::cout << "Filled element[" << i <<"]: "<< lista[i]<< std::endl;;
            }
            catch (const std::exception& e)
            { 
                std::cout   << "\033[31mError: \033[0m"<< e.what() << " at value " << i
                            << std::endl;
                line = __LINE__;
                debugPrint(i, line);
            }
            catch (const char* msg)
            {
                line = __LINE__;
                std::cout << "\033[31m" << msg << "\033[0m";
                debugPrint(lista[i], line);
            }
            catch (...)
            {
                std::cout << "Unexpected exception" << std::endl;
                line = __LINE__;
                debugPrint(lista.size() + 3, line);
            }
        }
        for (unsigned int i = 0; i < charito.size() + 3; i++)
        {
            try
            {
                charito[i] = gang[i % (arrayLength(gang))][0];
            }
            catch (const std::exception& e)
            { 
                std::cout   << e.what() << " at value " << i
                            << std::endl;
                line = __LINE__;
                debugPrint(i, line);
            }
            catch (...)
            {
                std::cout << "Unexpected exception" << std::endl;
                line = __LINE__;
                debugPrint(lista.size() + 3, line);
            }
        }
        goNext("\nCopy and compare");
        std::cout << "\nLet's make copy = lista and compare them" << std::endl;
        copy = lista;
        ::compare(lista, copy, "lista", "copy");
        goNext("\nComparing arrays of diffent types and lengths");
        ::compare(lista, group, "lista", "group");
        ::compare(group, lista, "group", "lista");
        ::compare(nums, copy, "\033[1;31mnums\033[0m", "copy");
        ::compare(group, gang, "\033[1;34mgroup\033[0m", "\033[7;4;34mgang\033[0m");
        ::compare(nums, group, "\033[1;31mnums\033[0m", "group");
        ::compare(gang, charito, "gang", "charito");
        goNext("\nComparing arrays of diffent types and lengths with empty arrays");
        ::compare(copy, buid, "copy", "buid");
        ::compare(buid, nums, "buid", "nums");
        ::compare(buid, charito, "buid", "charito");
        ::compare(buid, buid, "buid", "buid");
        std::cout << "\nLet's make buid = charito and compare them" << std::endl;
        buid = charito;
        ::compare(buid, charito, "buid", "charito");
        goNext("\nMessing around with multidimensional arrays.(Part 1)");
    }
    {
        const std::string   part_1[4] = {"The one", "The other", "And", "The one of the motorbike"};
        std::string         part_2[4] = {" is ", " was ", " loves ", " hates "};
        std::string         part_3[4] = {"Jonh", "Elmo", "Chris", "Paul Bazos"};
        Array<std::string>  test[4];

        std::cout   << "\nLet's display the sources:\n" << std::endl;
        ::display(part_1, "Const string array");
        ::display(part_2, "String array");
        ::display(part_3, "Another string array");

        std::cout   << "\nLet's combine the sources creating Array<std::string>  test[4];"
                    << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            test[i] = Array<std::string>(3);
            test[i][0] = part_1[i];
            test[i][1] = part_2[i];
            test[i][2] = part_3[i];

        }
        std::cout   << "\nLet's show Array<std::string>  test[4];"
                    << std::endl;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                std::cout << test[i][j];
            }
            std::cout << std::endl;
        }
        goNext("\nMessing around with multidimensional arrays.(Part 2)");
    }
    {
        const std::string   part_1[4] = {"The one", "The other", "And", "The one of the motorbike"};
        std::string         part_2[4] = {" is ", " was ", " loves ", " hates "};
        std::string         part_3[4] = {"Jonh", "Elmo", "Chris", "Paul Bazos"};
        Array<std::string>  test[3][4];
        Array<std::string>  test_1(3);
        std::cout   << "\nLet's display the sources:\n" << std::endl;
        ::display(part_1, "Const string array");
        ::display(part_2, "String array");
        ::display(part_3, "Another string array");
        std::cout   << "\nLet's incorporate the sources in a multidemsional array.\n" 
                    << "While ceating Array<std::string>  test_1(3)"
                    << std::endl;
        for (int i = 0; i < 3; i++) 
        {
            if (i % 3 == 0)
            {
                test_1[i] = part_1[i];
            }
            else if (i % 3 == 1)
            {
                test_1[i] = part_2[i];
            }
            else
            {
                test_1[i] = part_3[i];
            }
            for (int j = 0; j < 4; j++) 
            {
                test[i][j] = Array<std::string>(1);
            }
        }
        for (int j = 0; j < 4; j++) 
        {
            test[0][j][0] = part_1[j];
            test[1][j][0] = part_2[j]; 
            test[2][j][0] = part_3[j];
        }
        std::cout   << "Let's see the result of putting the sources in a Array<std::string>  test[3][4]: "
                    << std::endl;
        for (int i = 0; i < 3; i++) 
        {
            std::cout << "Row " << i << ": ";
            for (int j = 0; j < 4; j++)
            {
                std::cout << "[" << test[i][j][0] << "]";
            }
            std::cout << std::endl;
        }
        ::display(test_1, "test_1");
        std::cout << std::endl;
        goNext("\nEnd of the evaluation and => Outstanding project\033[5;24m💥\033[25m");
    }
    return 0;
}

        /*
        const std::string* sources[3] = {part_1, part_2, part_3};

        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                test[i][j] = Array<std::string>(1);
                test[i][j][0] = sources[i][j];
            }
        }
        */
