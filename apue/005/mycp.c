#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define BUFFERSIZE 4096

int main(int argc, char* argv[])
{
    int srcfd = open(argv[1], O_RDONLY); // 以只读方式打开一个存在的文件
    // 创建一个新文件，这个文件只能写，权限为0666
    int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);

    int len = 0;
    char buffer[BUFFERSIZE] = {0}; // 临时缓冲区

    while ((len = read(srcfd, buffer, BUFFERSIZE)) > 0) // 循环读取数据
    {
        write(dstfd, buffer, len); // 写入数据
    }
    close(srcfd); // 关闭文件
    close(dstfd);
    return 0;
}