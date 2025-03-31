#include "PmergeMe.hpp"
#include "Utils.hpp"

PmergeMe::PmergeMe() : 
    _vecSortStart(0), _vecSortEnd(0), _dequeSortStart(0), _dequeSortEnd(0) 
{
    Utils::printMsg("PmergeMe default constructor called", "yellow");
}

PmergeMe::PmergeMe(const PmergeMe& other) : 
    _vecContainer(other._vecContainer), 
    _dequeContainer(other._dequeContainer),
    _originalSequence(other._originalSequence),
    _vecSortStart(other._vecSortStart), 
    _vecSortEnd(other._vecSortEnd),
    _dequeSortStart(other._dequeSortStart), 
    _dequeSortEnd(other._dequeSortEnd) 
{
    Utils::printMsg("PmergeMe copy constructor called", "yellow");
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    Utils::printMsg("PmergeMe assignment operator called", "yellow");
    if (this != &other) {
        _vecContainer = other._vecContainer;
        _dequeContainer = other._dequeContainer;
        _originalSequence = other._originalSequence;
        _vecSortStart = other._vecSortStart;
        _vecSortEnd = other._vecSortEnd;
        _dequeSortStart = other._dequeSortStart;
        _dequeSortEnd = other._dequeSortEnd;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
    Utils::printMsg("PmergeMe destructor called", "magenta");
}

// Parsing
bool PmergeMe::parseInput(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        std::string arg = av[i];
        
        if (!isNumber(arg))
            return (Utils::printErr("Error: Invalid argument: " + arg), false);
        
        long num = std::atol(arg.c_str());
        if (num <= 0 || num > INT_MAX) 
            return (Utils::printErr("Error: Number out of range: " + arg), false);
        
        int value = static_cast<int>(num);
        _originalSequence.push_back(value);
        _vecContainer.push_back(value);
        _dequeContainer.push_back(value);
    }
    
    return true;
}

void PmergeMe::sortContainers() {
    _vecSortStart = clock();
    fordJohnsonSort(_vecContainer);
    _vecSortEnd = clock();
    
    _dequeSortStart = clock();
    fordJohnsonSort(_dequeContainer);
    _dequeSortEnd = clock();
}

void PmergeMe::displayResults() const {
    // Display before and after
    std::string beforeMsg = "Before: ";
    for (size_t i = 0; i < _originalSequence.size(); ++i) {
        beforeMsg += Utils::toStr(_originalSequence[i]) + " ";
    }
    Utils::printMsg(beforeMsg, "cyan");

    std::string afterMsg = "After:  ";
    for (size_t i = 0; i < _vecContainer.size(); ++i) {
        afterMsg += Utils::toStr(_vecContainer[i]) + " ";
    }
    Utils::printMsg(afterMsg, "green");
    
    // Calculate and display time measurements
    double vecTime = static_cast<double>(_vecSortEnd - _vecSortStart) / CLOCKS_PER_SEC * 1000000;
    double dequeTime = static_cast<double>(_dequeSortEnd - _dequeSortStart) / CLOCKS_PER_SEC * 1000000;
    
    std::stringstream vecTimeMsg;
    vecTimeMsg << "Time to process a range of " << _vecContainer.size() 
               << " elements with std::vector : " << std::fixed << std::setprecision(5) 
               << vecTime << " us";
    Utils::printMsg(vecTimeMsg.str(), "yellow");
              
    std::stringstream dequeTimeMsg;
    dequeTimeMsg << "Time to process a range of " << _dequeContainer.size() 
                 << " elements with std::deque : " << std::fixed << std::setprecision(5) 
                 << dequeTime << " us";
    Utils::printMsg(dequeTimeMsg.str(), "yellow");
}

bool PmergeMe::isNumber(const std::string& str) {
    if (str.empty()) return false;
    
    for (size_t i = 0; i < str.length(); ++i) {
        if (i == 0 && (str[i] == '+' || str[i] == '-')) {
            if (str.length() == 1) return false;
            continue;
        }
        if (!std::isdigit(str[i])) return false;
    }
    
    return true;
}

// Ford-Johnson Merge-Insert Sort implementation
template <typename Container>
void PmergeMe::fordJohnsonSort(Container& container) {
    if (container.size() <= 1) return;
    
    // Use a threshold for insertion sort vs merge sort
    size_t threshold = 16;
    hybridSort(container, 0, container.size() - 1, threshold);
}

template <typename Container>
void PmergeMe::insertionSort(Container& container, size_t start, size_t end) {
    for (size_t i = start + 1; i <= end; ++i) {
        typename Container::value_type key = container[i];
        size_t j = i;
        
        while (j > start && container[j - 1] > key) {
            container[j] = container[j - 1];
            --j;
        }
        
        container[j] = key;
    }
}

template <typename Container>
void PmergeMe::mergeSort(Container& container, size_t start, size_t mid, size_t end) {
    // Calculate sizes of subarrays
    size_t leftSize = mid - start + 1;
    size_t rightSize = end - mid;
    
    // Create temporary arrays
    typename Container::value_type* leftArr = new typename Container::value_type[leftSize];
    typename Container::value_type* rightArr = new typename Container::value_type[rightSize];
    //  We create two dynamic arrays to hold copies of the data. 
    //  The typename Container::value_type tells the compiler what type of elements are stored in the container

    // Copy data to temporary arrays
    for (size_t i = 0; i < leftSize; i++)
        leftArr[i] = container[start + i];
    for (size_t j = 0; j < rightSize; j++)
        rightArr[j] = container[mid + 1 + j];
        
    // Merge the temporary arrays back
    size_t i = 0, j = 0, k = start;
    
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            container[k] = leftArr[i];
            i++;
        } else {
            container[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < leftSize) {
        container[k] = leftArr[i];
        i++;
        k++;
    }
    
    while (j < rightSize) {
        container[k] = rightArr[j];
        j++;
        k++;
    }
    
    // Free temporary arrays
    delete[] leftArr;
    delete[] rightArr;
}

template <typename Container>
void PmergeMe::hybridSort(Container& container, size_t start, size_t end, size_t threshold) {
    if (start < end) {
        if (end - start <= threshold) {
            insertionSort(container, start, end); // Insertion sort for small ranges
        } else {
            // To avoid overflow, imagine start = 2 mil and end = 2.5 mil, a total of 4.5 mil > INT_MAX
            // There for subtracting is better than adding (start + end) / 2) doesn't work
            size_t mid = start + (end - start) / 2; 
            
            // Sort first and second halves
            hybridSort(container, start, mid, threshold);
            hybridSort(container, mid + 1, end, threshold);
            
            mergeSort(container, start, mid, end); // Merge both halves
        }
    }
}

// Explicit template instantiations
template void PmergeMe::fordJohnsonSort<std::vector<int> >(std::vector<int>&);
template void PmergeMe::fordJohnsonSort<std::deque<int> >(std::deque<int>&);
template void PmergeMe::insertionSort<std::vector<int> >(std::vector<int>&, size_t, size_t);
template void PmergeMe::insertionSort<std::deque<int> >(std::deque<int>&, size_t, size_t);
template void PmergeMe::mergeSort<std::vector<int> >(std::vector<int>&, size_t, size_t, size_t);
template void PmergeMe::mergeSort<std::deque<int> >(std::deque<int>&, size_t, size_t, size_t);
template void PmergeMe::hybridSort<std::vector<int> >(std::vector<int>&, size_t, size_t, size_t);
template void PmergeMe::hybridSort<std::deque<int> >(std::deque<int>&, size_t, size_t, size_t);

// Getters
const std::vector<int>& PmergeMe::getVectorContainer() const {
    return _vecContainer;
}

const std::deque<int>& PmergeMe::getDequeContainer() const {
    return _dequeContainer;
}

/**
    *   The Ford-Johnson algorithm (merge-insert sort) combines merge sort with insertion sort
    *   It switches strategies based on input size (merge for large sets, insertion for small ones) to achieve a more efficient sorting algorithm for large datasets.
    *   This implementation uses a threshold to switch between merge sort and insertion sort.
    
    *   The hybridSort function recursively sorts the array using merge sort for larger ranges and insertion sort for smaller ranges.
    *   The mergeSort function merges two sorted halves into a single sorted array.

    *   The insertionSort function performs insertion sort on a small range of elements.
    *   The fordJohnsonSort function is the main entry point for sorting the container.

    *   The explicit template instantiations ensure that the correct types are used for the containers.
    *   The getVectorContainer and getDequeContainer functions are used for testing and debugging.


    *   void PmergeMe::insertionSort(Container& container, size_t start, size_t end)
            Starting array: [5, 2, 4]
            First iteration (i=1):

            key = 2 (the element at position 1)
            j = 1 (current position)
            Compare: Is 5 > 2? Yes
            Move 5 right: [5, 5, 4]
            Decrease j to 0
            j equals start (0), so exit the while loop
            Place key at position j: [2, 5, 4]

            After first iteration: [2, 5, 4]
            Second iteration (i=2):

            key = 4 (the element at position 2)
            j = 2 (current position)
            Compare: Is 5 > 4? Yes
            Move 5 right: [2, 5, 5]
            Decrease j to 1
            Compare: Is 2 > 4? No
            Exit the while loop
            Place key at position j: [2, 4, 5]

            Final sorted array: [2, 4, 5]
    
    *   void PmergeMe::mergeSort(Container& container, size_t start, size_t mid, size_t end)
            Original Container: [7, 2, 4, 1, 5, 3]
            Working Range (index 1 to 4): [2, 4, 1, 5]

            Start: 1, Mid: 2, End: 4

            leftSize = mid - start + 1 = 2 - 1 + 1 = 2
            rightSize = end - mid = 4 - 2 = 2

            Left array: [2, 4]
            Right array: [1, 5]

            for (size_t i = 0; i < leftSize; i++)
                leftArr[i] = container[start + i];
            When i = 0: leftArr[0] = container[1 + 0] = container[1] = 2
            When i = 1: leftArr[1] = container[1 + 1] = container[2] = 4

            for (size_t j = 0; j < rightSize; j++)
                rightArr[j] = container[mid + 1 + j];
            When j = 0: rightArr[0] = container[2 + 1 + 0] = container[3] = 1
            When j = 1: rightArr[1] = container[2 + 1 + 1] = container[4] = 5

            i = 0, j = 0, k = 1
            while (i < leftSize && j < rightSize) {
                    if (leftArr[i] <= rightArr[j]) {
                    container[k] = leftArr[i];
                    i++;
                } else {
                    container[k] = rightArr[j];
                    j++;
                }
                    k++;
            }

            First while loop (merging elements from both arrays):
            
            Iteration 1:
                Left array: [2, 4]
                Right array: [1, 5]
                Compare leftArr[0] (2) <= rightArr[0] (1)? No
                So take rightArr[0]: container[1] = 1
                Original Container: [7, 2, 4, 1, 5, 3]
                Current array:      [7, 1, 4, 1, 5, 3] (Only modified index 1)
                Now: i = 0, j = 1, k = 2
            
            Iteration 2:
                Left array: [2, 4]
                Right array: [1, 5]
                Compare leftArr[0] (2) <= rightArr[1] (5)? Yes
                So take leftArr[0]: container[2] = 2
                Original Container: [7, 2, 4, 1, 5, 3]
                Current array:      [7, 1, 2, 1, 5, 3] (Modified indexes 1-2)
                i becomes 1, k becomes 3
                Now: i = 1, j = 1, k = 3
                
            Iteration 3:
                Left array: [2, 4]
                Right array: [1, 5]
                Compare leftArr[1] (4) <= rightArr[1] (5)? Yes
                So take leftArr[1]: container[3] = 4
                Original Container: [7, 2, 4, 1, 5, 3]
                Current array:      [7, 1, 2, 4, 5, 3] (Modified indexes 1-3)
                i becomes 2, k becomes 4
                Now: i = 2, j = 1, k = 4
                
            At this point i = 2 which equals leftSize, so we exit the first while loop.
            
            Second while loop (copy any remaining elements from left array):
            Since i = 2 and leftSize = 2, i is not less than leftSize, so this loop is skipped.
            
            Third while loop (copy any remaining elements from right array):
            Since j = 1 and rightSize = 2, we still have elements to copy:
            
            Iteration 1:
                Left array: [2, 4] (fully used)
                Right array: [1, 5]
                Remaining elements to copy: rightArr[1] = 5
                Original Container: [7, 2, 4, 1, 5, 3]
                Current array:      [7, 1, 2, 4, 5, 3] (Modified indexes 1-4)
                j becomes 2, k becomes 5
                Now: j = 2, k = 5
            
            At this point j = 2 which equals rightSize, so we exit the third while loop.
            
            Before mergeSort:   [7, 2, 4, 1, 5, 3]
            After mergeSort:    [7, 1, 2, 4, 5, 3] (Sorted portion: [1, 2, 4, 5])
            
            Note: This is just one merge operation within the larger sorting process. The full 
            fordJohnsonSort would perform multiple recursive calls to hybridSort, which in turn
            would make multiple calls to mergeSort to sort different sections of the array until
            the entire array is sorted.
*/
