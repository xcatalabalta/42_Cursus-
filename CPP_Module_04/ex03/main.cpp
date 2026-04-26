/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:04:09 by fcatala-          #+#    #+#             */
/*   Updated: 2025/03/15 08:46:37 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.class.hpp"
#include "Character.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include <cstdio>

int main(void)
{
    ///*
	{
		std::cout << "\n===== The given main =====" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
        me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
        delete src;
        std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section: Character Deep Copy."
                << std::endl;
        getchar();
		std::cout << "\n===== I don't miss you norminette =====" << std::endl;
	}
    //*/
    ///*
	{
		std::cout   << "\n===== Testing Character Deep Copy =====" << std::endl;

        std::cout   << "First we create a Character (Mike):" << std::endl;
        Character mike("Mike");
        std::cout   << "\nThen we silently create a IMateriaSource*" << std::endl;
        IMateriaSource* src = new MateriaSource();
        std::cout   << "and we learn Ice and Cure:" << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
        std::cout   << "\nFrom a AMateria* tmp (yes, a pointer)" << std::endl;
        AMateria* tmp;
        std::cout   << "\nWe create an ice" << std::endl;
		tmp = src->createMateria("ice");
        std::cout   << "\nAnd we put it in Mike's equip." << std::endl;
        mike.equip(tmp);
        std::cout   << "\nNow we create a Character who is a copy of Mike" << std::endl;
        Character baby(mike);
        std::cout   << "\nNow we create another Character (empty)" << std::endl;
        Character miguel;
        std::cout   << "\nAnd we equalize the empty Character to mike." << std::endl;
        miguel = mike;
        std::cout   << "We display the equipment of all 3 characters." << std::endl;
        mike.display();
        baby.display();
        miguel.display();
        std::cout   << "As we see, they have the same name (they are copies).\n" 
                    << "But their materials are located at different directions"
                    << " (they are deep copies) " << std::endl;
        std::cout   << "\nTake your time to revise the accuracy "
                    << "of the above implementation.\n"
                    << "Enter any key to continue with the test Character Deep Copy."
                    << std::endl;
        getchar();
        std::cout   << "\nNow we are going to create a cure and equip it to the original"
                    << std::endl;
        tmp = src->createMateria("cure");
        mike.equip(tmp);   
        std::cout   << "\nNow we are going to equip 2 cure to the last character"
                    << std::endl;
        for (int i = 0; i < 2; i++)
        {
            tmp = src->createMateria("cure");
            miguel.equip(tmp);
        }
        std::cout   << "\nWe display again the equipment of all 3 characters." << std::endl;
        mike.display();
        baby.display();
        miguel.display();
        std::cout   << "As we see, they have the same name (they are copies).\n" 
                    << "But their materials are different!"
                    << " (they are deep copies) " << std::endl;
        std::cout   << "\nTake your time to revise the accuracy "
                    << "of the above implementation.\n"
                    << "Enter any key to continue with the the next section:"
                    << " Ice Deep Copy.\n"
                    << "After cleaning and deleting the scene."
                    << std::endl;   
        getchar();     
        std::cout << "===== End of Character Deep Copy Test =====" << std::endl;
        delete src;        
    }
    //*/
   ///*
    // Test 2: Deep copy of Ice
    {
        std::cout << "\n===== Testing Ice Deep Copy =====" << std::endl;
        Ice*        ice = new Ice();
        Ice         cubito;
        Ice         glasson;
        Character   bob("Bob");

        std::cout << "\nUsing Ice objects:" << std::endl;
        ice->use(bob);
        cubito.use(bob);
        glasson.use(bob);
        std::cout << "\nCopying Ice objects:" << std::endl;
        Ice*        copyice = new Ice(*ice);
        Ice         berg(cubito);
        glasson = cubito;
        std::cout << "\nUsing copied Ice objects:" << std::endl;
        copyice->use(bob);
        glasson.use(bob);
        berg.use(bob);
        std::cout << "\nDeletion of original Ice objects:" << std::endl;
        delete ice;
        cubito.~Ice();
        std::cout 	<< "\nUsing copied Ice object after deletion of the original:" 
					<< std::endl;
        copyice->use(bob);
        glasson.use(bob);
        berg.use(bob);
        std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section: Cure Deep Copy."
                << std::endl;
        getchar();
        delete copyice;
        std::cout << "===== End of Ice Deep Copy Test =====" << std::endl;
    }
    //*/
   ///*
    // Test 3: Deep copy of Cure
    {
        std::cout << "\n===== Testing Cure Deep Copy =====" << std::endl;
        
        Cure*       cure = new Cure();
        Cure        ventura;
        Cure        lula;
        Character   charlie("Charlie");

        std::cout << "\nUsing Cure objects:" << std::endl;
        cure->use(charlie);
        ventura.use(charlie);
        lula.use(charlie);
        std::cout << "\nCopying Cure objects:" << std::endl;
        Cure*       copycure = new Cure(*cure);
        Cure        meme(ventura);
        lula = ventura;
        std::cout << "\nUsing copied Cure objects:" << std::endl;
        copycure->use(charlie);
        meme.use(charlie);
        lula.use(charlie);
        std::cout << "\nDeletion of original Ice objects:" << std::endl;
        delete cure;
        ventura.~Cure();
		std::cout 	<< "\nUsing copied Cure object after deletion of the original:" 
					<< std::endl;
        copycure->use(charlie);
        meme.use(charlie);
        lula.use(charlie);
        std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the next section: Inventory Management."
                << std::endl;
        getchar();
        std::cout << "===== End of Cure Deep Copy Test =====" << std::endl;
        delete copycure;
    }
    //*/
    ///*
    {
		std::cout << "\n===== Testing Inventory Management =====" << std::endl;
		IMateriaSource* src = new MateriaSource();
        AMateria*       thing[1024];
        int             dropped = 0;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Cure());
        src->learnMateria(new Ice());
		ICharacter* me = new Character("Xavier");
        ICharacter* bob = new Character("bob");
        Character   john("John");
        Character   juan("Juan");
		AMateria* tmp;

        std::cout   << "\nWe are going to try to equip an unexisitng materia (fire) to "
                    << bob->getName()
                    << std::endl;
        tmp = src->createMateria("fire");
        bob->equip(tmp);       
        std::cout   << "\nWe are going to try to equip 18 materials"
                    << " distributed among Xavier, John & Juan (nothing for bob).\n"
                    << "Check the code to see how they are distributed, "
                    << "you can also check the previous implementation.\n"
                    << "Enter any key to continue with the test."
                    << std::endl;
        getchar();

        for (int i = 1; i < 18; i++)
        {
            if (i % 2)
            {
                tmp = src->createMateria("ice");
                if (((Character *)me)->getInvSize() < INV)
                {
                    me->equip(tmp);
                }
                else if (john.getInvSize() < INV)
                {
                    john.equip(tmp);
                }
                else
                {
                    thing[dropped++] = tmp;
                    std::cout   << me->getName() << " and " << john.getName()
                                << " have their inventory full.\n"
                                << "Material " << tmp->getType()
                                << " has been sent to the bin."
                                << std::endl;
                }
            }
            else
            {
                tmp = src->createMateria("cure");
                if (((Character *)me)->getInvSize() < INV)
                {
                    me->equip(tmp);
                }
                else if (juan.getInvSize() < INV)
                {
                    juan.equip(tmp);
                }
                else
                {
                    thing[dropped++] = tmp;
                    std::cout   << me->getName() << " and " << juan.getName()
                                << " have their inventory full.\n"
                                << "Material " << tmp->getType()
                                << " has been sent to the bin."
                                << std::endl;
                }
            }
        }
        std::cout   << "\nLet's see their equipment:"
                    << std::endl;
        me->display();
        john.display();
        juan.display();
        std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the test."
                << std::endl;
        getchar();
        std::cout   << "\nNow we are going to unequip the 2nd material of " 
                    << me->getName()
                    << std::endl;
        thing[dropped++] = ((Character *)me)->getMateria(1);
        std::cout   << "We have dropped ... " << thing[dropped -1]->getType()
                    << std::endl;
        me->unequip(1);
        me->display();
        std::cout   << "\nNow we are going to try to equip twice a material to " 
                    << me->getName()
                    << std::endl;
        tmp = src->createMateria("cure");
        me->equip(tmp);
        me->equip(tmp);
        me->display();
        std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the test (use of materials)."
                << std::endl;
        getchar();
        
        for (int i = 0; i < INV + 3; i++)
        {
            john.use(i, juan);
            juan.use(i, *me);
            me->use(i, *bob);
        }
        std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the test "
                << "(use of materials after copying characters)."
                << std::endl;
        getchar();
        john = juan;
        john.display();
        juan.display();
        std::cout   << "\nWe are going to equip a new Ice to John\n"
                    << "(whose actual name is " << john.getName() <<")"
                    << std::endl;
        if (john.getInvSize() == INV)
        {
            thing[dropped++] = john.getMateria(3);
            john.unequip(3);
        }
        john.equip(new Ice());
        john.display();
        juan.display();
        for (int i = 0; i < INV; i++)
        {
            john.use(i, juan);
            juan.use(i, *me);
            me->use(i, *bob);
        }
        std::cout   << "\nTake your time to revise the accuracy "
                << "of the above implementation.\n"
                << "Enter any key to continue with the test (deletion)."
                << std::endl;
        getchar();
        for (int i = 0; i < dropped; i++)
        {
            if (thing[i])
            {
                std::cout   << "Deleting materia " << thing[i]->getType()
                            << std::endl;
                delete thing[i];
            }
        }
        std::cout   << "Trash bin empty!\nLet's finish the cleanning ...\n\n"
                    << std::endl;
		delete me;
        delete bob;
		delete src;

    }
    //*/
    return (0);
}