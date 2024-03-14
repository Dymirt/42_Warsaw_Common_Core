#include "libft.h"
#include <fcntl.h>
#include <string.h>

void test_ft_putnbr_fd();

int main() {
	test_ft_putnbr_fd();
}

void test_ft_putnbr_fd()
{
    //Test 1: Output to a .txt file
    int fd1 = open("nbr.txt", O_WRONLY | O_CREAT, 0666);
    char *str1 = "-12345";
    int n1 = atoi(str1);
    ft_putnbr_fd(n1, fd1);
    close(fd1);
    fd1 = open("nbr.txt", O_RDONLY);
    char* result1 = (char*) calloc(10, sizeof(char));
    int x = read(fd1, result1, strlen(str1));
    int result = strcmp(result1, str1) == 0;
    printf("Test 1: ft_putnbr_fd(\"-12345\", fd), Result: %s, Expected: %s - %s\n",
        result1, str1, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    close(fd1);
    free(result1);
	unlink("nbr.txt");

    //Test 2: Output min int to a .txt file
    int fd2 = open("nbr.txt", O_WRONLY | O_CREAT, 0666);
    char *str2 = "-2147483648";
    int n2 = atoi(str2);
    ft_putnbr_fd(n2, fd2);
    close(fd2);
    fd1 = open("nbr.txt", O_RDONLY);
    char* result2 = (char*) calloc(13, sizeof(char));
    x = read(fd2, result2, strlen(str2));
    result = strcmp(result2, str2) == 0;
    printf("Test 2: ft_putnbr_fd(\"-2147483648\", fd), Result: %s, Expected: %s - %s\n",
        result2, str2, result ? GREEN "PASS" NORMAL : RED "FAIL" NORMAL);
    close(fd2);
    free(result2);
	unlink("nbr.txt");

    //Test 3: Stdout
    char *str3 = "111111";
    int n3 = atoi(str3);
    ft_putnbr_fd(n3, 1);
    printf("Test 3: ft_putnbr_fd(\"111111\", 1): if this line starts with 111111, stdout is working\n");
}
