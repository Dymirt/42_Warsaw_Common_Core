#include "libft.h"
#include <fcntl.h>
#include <string.h>

void test_ft_putstr_fd();

int main() {
	test_ft_putstr_fd();
}

void test_ft_putstr_fd()
{
    //Test 1: Output to a .txt file
    int fd1 = open("str.txt", O_WRONLY | O_CREAT, 0666);
	if (fd1 == -1){
		printf("Error opening file\n");
	}
    char *str1 = "Hello World!";
    ft_putstr_fd(str1, fd1);
    close(fd1);

    fd1 = open("str.txt", O_RDONLY);
	if (fd1 == -1){
		printf("Error opening file again\n");
	}
    char* result1 = (char*)malloc((strlen(str1) + 1) * sizeof(char));
    int x = read(fd1, result1, strlen(str1));
    int result = strcmp(result1, str1) == 0;
    printf("Test 1: ft_putstr_fd(\"Hello World!\", fd), Result: %s, Expected: %s - %s\n",
        result1, str1, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    close(fd1);
    free(result1);
	unlink("str.txt");

    //Test 2: Stdout
    char *str2 = "\t~~~~!";
    ft_putstr_fd(str2, 1);
    printf("Test 2: ft_putstr_fd('\\t~~~~!', 1): if this line starts with tab, stdout is working\n");
}
