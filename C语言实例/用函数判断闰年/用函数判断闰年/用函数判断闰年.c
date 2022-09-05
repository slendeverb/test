#include <stdio.h>

int is_leap_year(int x)
{
	if (x % 4 == 0 && x % 100 != 0)
		return 1;
	else if (x % 400 == 0)
		return 1;
	else
		return 0;
}
int main()
{
	int y = 0;
	scanf("%d", &y);
	if (is_leap_year(y) == 1)
	{
		printf("������\n");
	}
	else
	{
		printf("��������\n");
	}
	return 0;
}