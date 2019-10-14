#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000000];
	scanf("%[^\n]s", str);
	int len = strlen(str);
	int cnt = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == ' ')
		{
			if (str[i + 1] == ' ' || str[i+1] == '\0')
				continue;
			
			cnt++;
		}
	if (str[0] == ' ')
		printf("%d", cnt);
	else
		printf("%d", cnt+1);
}