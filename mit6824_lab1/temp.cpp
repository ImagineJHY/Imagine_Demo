#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <memory>
#include <functional>

using namespace std;

int main()
{
    int write_fd = open("testfile.txt", O_CREAT | O_RDWR, 0777);
    int read_fd = open("testfile.txt.bak", O_RDWR, 0777);
    int ret;
    char c;
    while((ret = read(read_fd, &c, 1))) {
        if (c == ' ') {
            continue;
        }else {
            if (c == '\r') {
                printf("here1\n");
            }
            if (c == '\n') {
                printf("here2\n");
            }
            write(write_fd, &c, 1);
        }
    }
    close(read_fd);
    close(write_fd);

    return 0;
}