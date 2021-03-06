#include <stdio.h>
#include <string.h>

char str[100005];
char substr[100005];
int b[100009];

void kmp_process(char *substr)
{
    const int m = strlen(substr);
    int i = 0, j = -1;

    b[i] = -1;
    while(i < m)
    {
        while(j >= 0 && substr[i] != substr[j])
            j = b[j];

		i++;
        j++;
        b[i] = j;
    }
}

int kmp(char *str, char *substr)
{
    int i=0, j=0, count = 0;
    const int n = strlen(str);
    const int m = strlen(substr);

	kmp_process(substr);
    while (i<n)
    {
        while (j>=0 && str[i]!=substr[j])
            j=b[j];

        i++;
        j++;

        if (j==m)
        {
            count++;
            j=b[j];
        }
    }
    return count;
}

int main()
{
	int tc, i;

	scanf("%d", &tc);

	for(i = 0; i <tc; i++)
	{
		scanf("%s %s", str, substr);

		printf("Case %d: %d\n", i + 1, kmp(str, substr));
	}

	return 0;
}
