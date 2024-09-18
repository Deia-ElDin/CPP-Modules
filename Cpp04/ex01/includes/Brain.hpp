#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include "Utils.hpp"

class Brain
{
    private:
        std::string ideas[100];
    
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        void        setIdea(const std::string& idea);
        void        setBrain(const std::string& animalType);
        void        printIdeas() const;
};

#endif // __BRAIN_HPP__