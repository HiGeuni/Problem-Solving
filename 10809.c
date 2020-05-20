#include<stdio.h>

int main() {
	int arr[26], j = 0;
	char ch[101];
	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}
	scanf("%s", ch);

	while (1) {
		if (ch[j] == '\0')
			break;
		for (int i = 0; i < 26; i++) {
			if (arr[i] == -1) {
				if (ch[j] - 'a' == i) {

					arr[i] = j;
					break;
				}
			}
		}
		j++;
	}

	for (int i = 0; i < 26; i++) printf("%d ", arr[i]);
	return 0;
}
