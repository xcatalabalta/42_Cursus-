/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:01:40 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/06 13:49:30 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

class Student
{
private:
    std::string _login;

public:
    Student(std::string const & login) :_login(login)
    {
        std::cout << "Student " << this->_login << " is born" << std::endl;
    }
    ~Student()
    {
        std::cout << "Student " << this->_login << " is dead" << std::endl;
    }
 // Getters   
    std::string const & getWho() const;//described outside class
    std::string const & getLogRef()//described inside class
    {
        return (this->_login);
    }
    std::string const & getLogRefConst() const;//described outside class
    std::string * getLogPtr();//described outside class
    std::string const * getLoginPtrConst() const;//describer outside

    static  Student *newStudent(std::string const login);//creates a new object of the class and initializes it
};

std::string const & Student::getWho() const
{
    return (this->_login);
}

std::string const & Student::getLogRefConst() const
{
    return (this->_login);
}

std::string * Student::getLogPtr()
{
    return &(this->_login);
}

std::string const * Student::getLoginPtrConst() const
{
    return &(this->_login);
}

Student *Student::newStudent(std::string const login)
{
    Student *nuevo = new Student (login);
    return (nuevo);
}
//Class array
class Fiesta
{
private:
    /* data */
public:
    Fiesta(/* args */);
    ~Fiesta();
};

Fiesta::Fiesta(/* args */)
{
    std::cout << "Hello! ";
}

Fiesta::~Fiesta()
{
    std::cout << std::endl << "Bye" << std::endl;
}

// Print result of changes for Ref2
void PutResult(int anotheNumber, int numberOfBalls, int* ballsPtr, int& ballsRef)
{
    std::cout <<"Directions & values: "<< std::endl;
    std::cout   <<"anotheNumber:\t" << &anotheNumber << "\t value = " << anotheNumber << std::endl
                <<"numberOfBalls:\t" << &numberOfBalls << "\t value = " << numberOfBalls << std::endl
                << "ballsPtr:\t" << ballsPtr << "\t value = " << *ballsPtr << std::endl
                << "ballsRef:\t" << &ballsRef << "\t value = " << ballsRef << std::endl;
    return ;
}

//ref2
// modifies a string passed as pointer
void    byPtr(std::string *str)
{
    *str += " and ponies";
    return ;
}

// prints a string passed as const pointer
void    byConstPtr(std::string const *str)
{
    std::cout << *str << std::endl;
    return ;
}

// modifies a string passed as reference
void    byRef(std::string &str)
{
    str += " and frutos ponies";
    return ;
}

// prints a string passed as const Ref
void    byConstRef(std::string const &str)
{
    std::cout << str << std::endl;
    return ;
}

int main ()
{
    Student bob = Student("bob fubar");
    Student* jim = new Student("jim fubar");

    std::cout << "I am " << bob.getWho() << " I live in "<< &bob.getWho() << std::endl;
    std::cout << "I am a pointer to " << jim->getWho() << std::endl;
    std::cout << "I allways will be " << jim->getLogRefConst() << std::endl;
    std::cout << "The big and unique " << *jim->getLogPtr() << std::endl;
    delete jim;
    std::cout << "I am still alive. I am " << bob.getLogRef() << std::endl;
    std::cout << "My addres from pointer is " << bob.getLogPtr() << " and named " << *bob.getLogPtr() << std::endl;
    std::string newstr = bob.getLogRefConst();
    byRef(newstr);
    byConstPtr(&newstr);

    std::cout << std::endl << "Now start the refs" << std::endl;
    int numberOfBalls = 42;
    int anotheNumber = 88;
    int finalNumber = 999999;
    int doomNumber = 666;
    int* ballsPtr = &numberOfBalls;
    int& ballsRef = numberOfBalls;

    PutResult(anotheNumber, numberOfBalls, ballsPtr, ballsRef);
    *ballsPtr = 69;
    std::cout << "\nChange *ballsRef = 69" << std::endl;
    PutResult(anotheNumber, numberOfBalls, ballsPtr, ballsRef);
    ballsRef = anotheNumber;
    std::cout << "\nChange ballsRef = anotherNumber" << std::endl;
    PutResult(anotheNumber, numberOfBalls, ballsPtr, ballsRef);
    ballsPtr = &finalNumber;
    std::cout << "\nChange ballsPtr = &finalNumber" << std::endl;
    PutResult(anotheNumber, numberOfBalls, ballsPtr, ballsRef);
    numberOfBalls = 1000;
    std::cout << "\nnumberOfBalls = 1000" << std::endl;
    PutResult(anotheNumber, numberOfBalls, ballsPtr, ballsRef);
    ballsRef = 43210;
    std::cout << "\nChange ballsRef = 43210" << std::endl;
    PutResult(anotheNumber, numberOfBalls, ballsPtr, ballsRef);
    ballsRef = doomNumber;
    std::cout << "\nChange ballsRef = doomNumber (666)" << std::endl;
    PutResult(anotheNumber, numberOfBalls, ballsPtr, ballsRef);
    *ballsPtr = anotheNumber;
    std::cout << "\nChange *ballsPtr = anotherNumber" << std::endl;
    PutResult(anotheNumber, numberOfBalls, ballsPtr, ballsRef);
    
    std::cout << std::endl << "Now start the refs2" << std::endl;
    std::string str = "I like butterflies";
 
    std::cout << str << std::endl;
    byPtr(&str);
    byConstPtr(&str);
    str = "I like dogs";
    std::cout << str << std::endl;
    byRef(str);
    byConstRef(str);
    std::cout << "Because I am " << bob.getLogRefConst() << std::endl;
    std::cout << "Here are my friends" << std::endl;
    Fiesta *party = new Fiesta[5];
    delete [] party;
    bob = Student("Bobby la loka");
    std::cout << "I am " << bob.getLogRef() << std::endl;
    Student *colegui = Student::newStudent("EL PRINGAO");
    str = *colegui->getLogPtr();
    byRef(str);
    std::cout << "My only friend is " << str << std::endl;
    str = *colegui->getLogPtr();
 
 //Writing to file test.out   
    std::ofstream ofs("test.out");
    ofs << "File starts here" << std::endl;
    ofs << *colegui->getLogPtr() << std::endl;
    ofs << bob.getLogRef() << " to file" << std::endl;
    byRef(str);
    ofs << " and .." << str << " end." << std::endl;
    std::cout << "the string is " << str << std::endl;
    str = *colegui->getLogPtr();
    std::cout << "the string is " << str << std::endl;
    delete colegui;
    ofs.close();

 //Replacing from test.out to test.copy   

    std::string line;
    std::ifstream ifs("test.out");
    std::ofstream ups("prova.txt");
    std::string rep = "tonto lava";

    if (!ifs.is_open())
    {
        std::cerr << "Unable to open file test.out" << std::endl;
        return 1;
    }
    int a = 1;
    while (std::getline(ifs, line))
    {
        std::cout << "\tReading line " << a++ << std::endl;
        std::cout << line << " is the original" << std::endl;
        while (line.find(str) != std::string::npos)
        {
            int pos = line.find(str);
            std::cout << "We are at line " << pos << std::endl;
            line.erase(pos, str.length());
            line.insert(pos, rep);
        }
        ups << line << std::endl;
        std::cout << line << " is the COPY"<< std::endl;
    }   
    ifs.close();
    ups.close();
 // Testint read numbers
    std::ifstream otro("nums.txt");
    std::ifstream mash("test.copy");
    unsigned int n1;
    unsigned int n2;
    std::string res;

    otro >> n1 >> n2 >> n1 >> res;
    std::cout << n1 << "\t" << n2 << "\t" << res << std::endl;
    for (int i = 1; i < 10; i++)
    {
        otro >> res;
    }
    std::cout << n1 << "\t" << n2 << "\t" << res << std::endl;
    otro.close();
    mash.close();
    return (0);
}
