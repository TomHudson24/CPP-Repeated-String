#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <stdlib.h>
#include <stdio.h>

//Basic solution
//Works on small test cases but not on large strings
#if 0
long long int repeatedString(std::string s, long long int n)
{
	for(long long int i = 0; i < n; i++)
	{
		s.push_back(s[i]);
	}
	std::cout << s << " " << n << std::endl;
	
	long long int count = 0;
	for(long long int i = 0; i < n; i++)
	{
		if(s[i] == 'a') 
		{
			count++;
		}
	}
	return count;
	
}
#endif
//A solution
//So taking the size of the string go into a for loop and check for every a in the actual string then for however big the infinite version is increase the count if there is still some leftover.
long int repeatedString(std::string s, long int n)
{
	int size = s.size();
	int count1 = 0;
	int count2 = 0;
	int res = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] == 'a') {
			count1++;
			if (i < n % size)
				count2++;
		}
	}
	return count1 * (n / size) + count2;
}
int main()
{
	
	//std::ofstream fout(std::getenv("OUTPUT_PATH"));

	std::string s;;
	std::getline(std::cin, s);
	long int n = 0;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	long result = repeatedString(s, n);

	std::cout << result << "\n";

	

	return 0;
}