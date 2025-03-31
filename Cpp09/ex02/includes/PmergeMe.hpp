#ifndef __PMERGE_ME_HPP__
#define __PMERGE_ME_HPP__

#include <vector>    // For std::vector container
#include <deque>     // For std::deque container
#include <string>    // For string operations
#include <iostream>  // For input/output
#include <sstream>   // For string streams
#include <cstdlib>   // For atol
#include <ctime>     // For time measurements
#include <iomanip>   // For formatting output
#include <algorithm> // For sort operations
#include <climits>   // For INT_MAX

class PmergeMe {
    private:
        std::vector<int>    _vecContainer;
        std::deque<int>     _dequeContainer;
        std::vector<int>    _originalSequence; // Store original input for display
        
        // Time measurements
        clock_t             _vecSortStart;
        clock_t             _vecSortEnd;
        clock_t             _dequeSortStart;
        clock_t             _dequeSortEnd;
        
        // Helper methods for Ford-Johnson algorithm (merge-insert sort)
        template <typename Container>
        void fordJohnsonSort(Container& container);
        
        template <typename Container>
        void insertionSort(Container& container, size_t start, size_t end);
        
        template <typename Container>
        void mergeSort(Container& container, size_t start, size_t mid, size_t end);
        
        template <typename Container>
        void hybridSort(Container& container, size_t start, size_t end, size_t threshold);
        
        // Utility methods
        bool isNumber(const std::string& str);
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        
        // Methods
        bool parseInput(int ac, char **av);
        void sortContainers();
        void displayResults() const;
        
        // Getters 
        const std::vector<int>& getVectorContainer() const;
        const std::deque<int>&  getDequeContainer() const;
};

#endif 