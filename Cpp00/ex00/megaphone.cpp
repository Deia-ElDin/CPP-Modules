#include <iostream>
#include <string>
#include <cstring>

int main(int ac, char **av)
{
	std::string result;

	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; j < av[i][j]; j++) 
			result += std::toupper(av[i][j]);
		if (i < ac - 1)
            result += " ";
	}
	std::cout << result << std::endl;
	return 0;
}

/*
	#include <iostream>: This includes the standard I/O stream library, which allows the program to use std::cout for output.

	The term output stream refers to the flow of data from your program to an output device or destination, 
		such as the console, a file, or even a network socket.

	What is std::?
		-   std:: is a namespace in C++.
		-   Namespace is like a container or a way to organize code in C++ so that names like functions, classes,
			and objects don't conflict with each other.
		-   std stands for standard. The std:: namespace contains all the standard C++ library functions, objects, 
			and types, like cout, cin, string, vector, and many more.

	Why do we need std::?
		-   Avoiding Name Conflicts: Imagine you create a function or a variable in your code named cout. If there were no namespaces, 
			the compiler wouldn’t know whether you are referring to your cout or the standard library’s cout used for printing. 
			The std:: namespace helps the compiler understand which cout you mean—yours or the standard one.

		-   Organizing Code: C++ has a vast standard library. Putting everything into one global space would make it hard to manage
			and could cause lots of conflicts. By using namespaces like std::, we can organize code better and avoid these issues.
		
	How std:: Works?
		-   When you write std::cout, you're telling the compiler, 
			"Hey, I want to use the cout that is defined in the standard (std) namespace."
		-   Without std::, the compiler wouldn't know which cout you're referring to if there’s another cout defined somewhere else.

	<< (Insertion Operator):
		-   The << operator is called the insertion operator in C++.
		-   It is used to insert data into the output stream.
		-   In this case, we are inserting the string "* LOUD AND UNBEARABLE FEEDBACK NOISE *" into the output stream std::cout.
			which carries it to the console, where it gets displayed.

	std::string
		-	Type: std::string is a class provided by the C++ Standard Library that represents a sequence of characters (a string).
			it is automatically initialized as an empty string.
		-	Memory Management: std::string automatically manages memory. You don't have to worry about allocating or freeing memory manually. 
			It dynamically adjusts its size as you add or remove characters.
		-	Functionality: std::string comes with many built-in methods for string manipulation, such as concatenation (+), finding substrings, 
			replacing parts of the string, etc.
		-	Ease of Use: std::string handles all the complexities of working with strings (like resizing, memory management, etc.) internally, 
			making it much easier and safer to use than a char* in C.

	result += std::toupper(av[i][j]);
		-	1. Clarity:
			Using std::toupper makes it clear that this function is part of the C++ Standard Library.
		-	2. Consistency with Modern C++:
			C++ encourages the use of namespaces to organize code and avoid name conflicts. By using std::toupper.
		-	3. Readability:
			When you use std::toupper, it immediately communicates to other developers (or to yourself in the future) that this is the standard library function. This makes the code easier to read and understand.
		-	4. Avoiding Potential Name Conflicts:
			By using std::, you reduce the risk of accidentally calling a function with the same name that might be defined elsewhere in your code or in another library. 
		-	Conclusion:
			While both toupper and std::toupper will work perfectly fine in C++, using std::toupper is my preference because it’s clearer, aligns with modern C++ practices, and helps prevent potential issues in larger or more complex projects. It’s a small habit that can contribute to more maintainable and understandable code.
*/
