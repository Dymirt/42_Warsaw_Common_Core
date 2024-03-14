#include "libft.h"
#include <fcntl.h>

void test_ft_putchar_fd();

int main() {
test_ft_putchar_fd();
}

void test_ft_putchar_fd()
{
    //Test 1: Output to a .txt file
    int fd1 = open("char.txt", O_WRONLY | O_CREAT , 0666);
	if (fd1 == -1){
		printf("Error opening file\n");
	}
    char c1 = 'a';
    ft_putchar_fd(c1, fd1);
    close(fd1);

    fd1 = open("char.txt", O_RDONLY);
	if (fd1 == -1){
		printf("Error opening file\n");
	}
    char* result1 = (char*)malloc(5 * sizeof(char));
    int x = read(fd1, result1, 5);
    int result = c1 == result1[0];
    printf("Test 1: ft_putchar_fd('a', fd), Result: %s, Expected: %c - %s\n",
        result1, c1, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    close(fd1);
    free(result1);
	unlink("char.txt");

    //Test 2: Stdout
    char c2 = '\t';
    ft_putchar_fd(c2, 1);
    printf("Test 2: ft_putchar_fd('\t', 1): if this line starts with tab, stdout is working\n");
}
