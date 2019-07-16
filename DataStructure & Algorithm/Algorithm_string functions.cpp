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
	for (--dest; *src != '\0'; *dest++ = *src++);
	return temp;
}

char* my_strcpy(char* dest, const char* src) {
	char* temp = dest;
	while (*src != '\0') *dest++ = *src++;
	*dest = '\0';
	return temp;
}

int main() {
	char s1[20] = "abc", s2[20] = "xyz", s3[20] = "dsfasfcvjdz";
	cout << my_strlen(s3) << endl;
	cout << my_strcmp("abc", "abc") << " " << my_strcmp("abc", "abcd") << " " << my_strcmp("abd", "abc") << endl;
	cout << my_strcat(s1, "def") << endl;
	cout << my_strcpy(s3, s2) << endl;


	return 0;
}