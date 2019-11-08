#include <iostream>
using namespace std;

int my_strlen(const char* str) {
	int len = 0;
	while (*str++ != '\0') len++;
	return len;
}

int my_strcmp(const char* s1, const char* s2) {
	while (*s1 != '\0') {
		if (*s1 > *s2) return 1;
		else if (*s1 < *s2) return -1;
		s1++; s2++;
	}
	if (*s2 != '\0') return -1;
	else return 0;
}

char* my_strcat(char* dest, const char* src) {
	char* temp = dest;
	while (*dest++ != '\0');
	my_strcpy(--dest, src);
	return temp;
}

char* my_strcpy(char* dest, const char* src) {
	char* temp = dest;
	while (*src != '\0') *dest++ = *src++;
	*dest = '\0';
	return temp;
}

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
	char s1[20] = "abc", s2[20] = "xyz", s3[20] = "dsfasfcvjdz";
	cout << my_strlen(s3) << endl;
	cout << my_strcmp("abc", "abc") << " " << my_strcmp("abc", "abcd") << " " << my_strcmp("abd", "abc") << endl;
	cout << my_strcat(s1, "def") << endl;
	cout << my_strcpy(s3, s2) << endl;
	char str[10] = "1234123", toSave[20] = "";
	int num = 4321321;

	printf("str:%s to int:%d\n", str, strToInt(str));
	printf("int:%d to str(return):%s str(orginal):%s\n", num, intToStr(num, toSave), toSave);


	return 0;
}