/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:56:31 by fcatala-          #+#    #+#             */
/*   Updated: 2025/02/01 13:53:37 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
//#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"
#include <cstdio>

static void ft_ciao(const Animal *a, const Animal *b, const Animal *c)
{
            std::cout << "\n\nNot this one Son of fruta!\n" << std::endl;
            delete a;
            delete b;
            delete c;
}

int main (void)
{
    //Variables used They are declared inside and checked with sounds
    //const Animal*       meta = new Animal();
    //const Animal*       j = new Dog();
    //const Animal*       i = new Cat();
    //const Animal*       w = new Cat();
    //Dog                 dok;
    //const WrongAnimal*  wr_meta = new WrongAnimal();
    //const WrongAnimal*  wr_i = new WrongCat();
    //WrongCat            wr_gat;
           
    std::string     line;//To control the content of the line to improve UiX

    std::cout << "Constructors and noise functions." << std::endl;
    std::cout << "\nCreate and listen \"meta\" (it's a random animal)" << std::endl;
    const   Animal* meta = new Animal();
    std::cout << "\tI am an "<< meta->getType() << std::endl;
    meta->makeSound();  
    std::cout << "\nCreate and listen \"i\" (it's a cat born as animal)" << std::endl;
    const Animal* i = new Cat();
    std::cout << "\tI am a "<< i->getType() << std::endl;
    i->makeSound();    
    std::cout << "\nCreate and listen \"j\" (it's a dog born as animal)" << std::endl;
    const Animal* j = new Dog();
    std::cout << "\tI am j, a "<< j->getType() << std::endl;
    j->makeSound();
    std::cout << "\nCreate and listen \"dok\" a real and simple dog" << std::endl;
    Dog dok;
    std::cout << "\tI am dok, a "<< dok.getType() << std::endl;
    dok.makeSound();
    std::cout   << "\nTake your time to revise the above implementation.\n"
                << "Next code is to check of equalities. " 
                << "Enter (any key) to continue ";
    getline(std::cin,line);
    if (!std::cin)
    {
        ft_ciao(i, meta, j);
        return (0);
    }
    line.clear();
    std::cout   << "\nCreate and listen \"w\" (it's another cat born as animal)" << std::endl;
    const Animal* w = new Cat();
    w->makeSound();
    std::cout   << "\nLet's make \"i\" (cat born as animal) = \"w\" "
                << "(another cat born as animal) and listen to them" 
                << std::endl;
    delete i;
    i = w;
    i->makeSound();
    w->makeSound();
    std::cout << "\nLet's make j = dok and listen to them" << std::endl;
    delete j;
    j = &dok;
    j->makeSound();
    dok.makeSound();
    std::cout << "\nHave you seen the constructor/s or the destructor/s? Enter (any key) to continue ";
    getline(std::cin,line);
    line.clear();
    std::cout << "\nLet's create and listen 2 new random animals (pointer) mita: \033[3mAnimal* mita = new Animal()\033[0m" << std::endl;
    Animal* mita = new Animal();
    mita->makeSound();
    std::cout << "\nAnd a new pointer \033[3mAnimal* muta = mita\033[0m" << std::endl;
    Animal* muta = mita;
    muta->makeSound();
    std::cout   << "\nHave you seen the constructor/s or the destructor/s? Enter (any key) to continue ";
    getline(std::cin,line);
    if (!std::cin)
    {
        ft_ciao(mita, meta, w);
        return (0);
    }
    line.clear();
    std::cout   << "\nLet's check the types of muta and mita: \n"
                << "\tMuta is " << muta->getType() << " and mita is " << mita->getType() 
                << "\n" << std::endl;
    std::cout   << "\nLet's change the type of mita." << std::endl;
    std::string newtype;
    newtype.clear();
    while (newtype.empty())
    {
        std::cout   << "Enter your new type: ";
        std::getline(std::cin, newtype);
        if (!std::cin)
        {
            ft_ciao(mita, meta, w);
            return(0);
        }
        if (newtype.empty())
        {
            std::cout << "\033[A\033[2K";
        }
    }
    mita->setType(newtype);
    std::cout   << "\nLet's check the types of muta and mita: \n"
                << "\tMuta is " << muta->getType() << " and mita is " << mita->getType() 
                << std::endl;
    std::cout   << "\nAre they shallow copies? "
                << "\nNooooo, they are pointers who behave as pointers."
                << "\nEnter (any key) to continue ";
    getline(std::cin,line);
    if (!std::cin)
    {
        ft_ciao(mita, meta, w);
        return (0);
    }
    line.clear();
    std::cout   << "\nLet's create another simple and real dog (pup)" << std::endl;
    Dog pup;
    std::cout   << "\nLet's make pup = dok" << std::endl;
    pup = dok;
    std::cout   << "\nLet's create and listen another simple and real dog (pupy) copied from pup" << std::endl;
    Dog pupy(pup);
    pupy.makeSound();
    std::cout   << "\n\"pup\" will evolve to a Wolf (well, it thinks so)"
                << std::endl; 
    pup.setType("Wolf");
    std::cout   << "\nNow \"pup\" thinks it is a " << pup.getType() 
                << " and \"pupy\" thinks is a " << pupy.getType()
                << std::endl;
    std::cout   << "\nThey are not shallow copies! Enter (any key) to continue ";
    getline(std::cin,line);
    if (!std::cin)
    {
        ft_ciao(mita, meta, w);
        return (0);
    }
    line.clear();
    std::cout   << "\nKilling time 1" << std::endl;
    delete meta;
    delete mita;
    delete w;
    //Here starts the wrongies
    std::cout << "\033[32mLet's check the wrongies (non stop)\033[0m" << std::endl;
    const WrongAnimal*  wr_meta = new WrongAnimal();
    std::cout << "I am a "<< wr_meta->getType() << std::endl;
    wr_meta->makeSound();
    const WrongAnimal*  wr_i = new WrongCat();
    std::cout   << "Now listen the wrong i (it's a wrong cat born as wrong animal) "
                << wr_i->getType() << " " << std::endl;
    wr_i->makeSound();
    WrongCat wr_gat;
    std::cout   << "Now listen again the wrong i (it's a wrong cat born as wrong animal but equalized to a real wrong cat) " << std::endl;
    delete wr_i;
    wr_i = &wr_gat;
    wr_i->makeSound();
    std::cout   << "\nDeconstruction of \"wr_meta\" (No loger required)" 
                << " and construction of another WrongCat as copy of \"wr_gat\"\n"
                << std::endl;
    delete wr_meta;
    WrongCat kitty(wr_gat);
    std::cout   << "\nkitty (quite obvious name) is a wrongcat copied from wr_gat\n"
                << "Say \'Hello\' kitty: (bad joke time)"
                << std::endl;
    kitty.makeSound();
    std::cout << "\nEvolution of wr_gat from cat to TIGER" << std::endl;
    wr_gat.setType("TIGER");
    std::cout   <<"\nNow wr_gat is a " << wr_gat.getType() 
                << " and kitty is a " << kitty.getType()
                << std::endl;
    kitty = wr_gat;
    wr_gat.setType("linx");
    std::cout   <<"\nNow wr_gat has a new identity. It is a " << wr_gat.getType() 
                << " and kitty is a " << kitty.getType()
                << std::endl;
    std::cout   << "\nCheck the implementation."
                << "\nEnter (any key) to proceed to the extermination: "
                << std::endl;
    getchar();
    std::cout   << "\nKilling them all!!!!!\n" << std::endl;
    /*
    //Final checks
    std::cout << "\033[32mLet's check the equalities\033[0m" << std::endl;
    Dog Bobby;
    dok = Bobby;
    Bobby.makeSound();
    dok.makeSound();
    Animal kosa;
    kosa.makeSound();
    Animal thing;
    thing.makeSound();
    kosa = thing;
    kosa.makeSound();
    thing.makeSound();
    Animal* beast;//not intialized yet
    beast = &thing;//initialized here
    beast->makeSound();
    Animal* swamp = new Animal();
    std::cout << "\033[36mAble to make noise" << std::endl;
    swamp->makeSound();
    std::cout << "\033[0m";
    delete swamp;
    swamp = beast;
    swamp->makeSound();
    Cat* Kitten;//not intialized yet
    Cat mishi;
    Kitten = &mishi;//initialized here
    Kitten->makeSound();
    mishi.makeSound();
    Cat* vicky = new Cat();
    std::cout << "\033[36mAble to make noise" << std::endl;
    vicky->makeSound();
    std::cout << "\033[0m";
    delete vicky;
    */
    return (0);
}