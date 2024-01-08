#include <iostream>
#include  <string>

#include <stdlib.h>

//string literals are always stored in read-only memory which means you cant modify it directly
int main() {
	const char name[8] = "Cher\0no";//if there is a '\0' in the string,the computer will consider its the end of the string;
	char name5[] = "Cherno"; //this actually create a varible store the copy of the "Cherno" string literal so that we could modify it
	name5[2] = 'a';

	const char* name1 = u8"Cherno";//this is a char pointer points to the read-only memory
	const wchar_t* name2 = L"Cherno";//the size of widechar depends on the compiler,2 bytes in windows,4 bytes in Linux
	const char16_t* name3 = u"Cherno";//usually use char16_t to 2 bytes char
	const char32_t* name4 = U"Cherno";
	
	std::cout << name << std::endl;
	std::cin.get();
}