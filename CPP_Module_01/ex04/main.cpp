/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:45:08 by fcatala-          #+#    #+#             */
/*   Updated: 2024/11/25 16:29:49 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sys/stat.h>

/*
    Unused code and notes
    Formerly used to add a sufix:
    line.append(".replace");
    <sys/stat.h> used to check if a file exists
    <cstdlib> used to use the exit function
*/

bool    ft_fileExists(const std::string& filename)
{
    struct stat buffer;

    if (stat(filename.c_str(), &buffer) == 0)
    {
        return (true);
    }
    return (false);
}

int ft_findReplace(const std::string& file, std::string str1, std::string str2)
{
    std::ifstream   ifs(file.c_str());
    std::string     line = file;
    std::ofstream   ofs;
    int             a = 0;
    int             pos = 0;

    if (!ft_fileExists(file))
    {
        std::cerr << "Error: '" << file << "' doesn't exist." << std::endl;
        exit (1);
    }
    if (!ifs.is_open())
    {
        std::cerr << "Error: '" << file << "' Reading permission denied" << std::endl;
        exit (1);
    }
    line += ".replace";
    ofs.open(line.c_str());
    if (!ofs.is_open())
    {
        if (ft_fileExists(line))
        {
            std::cerr << "Error: '" << line <<"' Writting permission denied." << std::endl;
        }
        else
        {
            std::cerr << "Error: Unable to create output file '" << line << "'" << std::endl;
        }
        ifs.close();
        exit (1);
    }
    while (std::getline(ifs, line))
    {
        while (line.find(str1) != std::string::npos)
        {
            pos = line.find(str1);
            line.erase(pos, str1.length());
            line.insert(pos, str2);
            a++;
        }
        ofs << line << std::endl;
    }
    ifs.close();
    ofs.close();
    return (a);
}

int     main (int argc, char **argv)
{
    int ocurr = 0;
    
    if (argc != 4)
    {
        std::cout << "Error.Wrong number of arguments. Run again the program" 
                << " and provide <filename>, string to replace, and sting to "
                << "replace with" << std::endl;
        return (0);
    }
    else
    {
        ocurr = ft_findReplace(argv[1], argv[2], argv[3]);
    }
    std::cout << "Job done! ";
    if (ocurr > 0)
    {
        std::cout << ocurr << " matches found and replaced." << std::endl;
    }
    else
    {
        std::cout << "No matches found." << std::endl;
    }
    return (0);
}