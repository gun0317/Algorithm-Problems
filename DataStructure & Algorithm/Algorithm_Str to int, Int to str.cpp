#include <iostream>
using namespace std;

int strToInt(char* str) {
	int toReturn = 0;
	while (*str != '\0') 
		toReturn = toReturn * 10 + *str++ - '0';
	return toReturn;
}

// Make sure to send enough length to save num to 'saveHere'.
char* intToStr(int num, char* saveHere) {
	int len = 0;
	// temp for saving the first element's pointer(array's pointer) 
	// prior to pointer calculations(str++)
	char* toReturn = saveHere;	
	while (num > 0) {
		len++;
		*saveHere++ = num % 10 + '0';
		num /= 10;
	}
	for (int i = 0; i <= len / 2; i++) {
		char temp = toReturn[len - 1 - i];
		toReturn[len - 1 - i] = toReturn[i];
		toReturn[i] = temp;
	}
	saveHere[len - 1] = '\0';
	return toReturn;
}

int main() {
	char str[10] = "1234123", toSave[20] ="";
	int num = 4321321;

	printf("str:%s to int:%d\n", str, strToInt(str));
	printf("int:%d to str(return):%s str(orginal):%s\n", num, intToStr(num,toSave),toSave);


	return 0;
}