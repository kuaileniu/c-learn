# include<stdio.h>
#include<stdlib.h>

/**
 * 指向文件的指针
 *    FILE *p
 * fopen(fpen_s)
 *    打开模式： w+ 读写模式，文件不存在则创建，存在则清空
 *    打开模式： r+ 读写模式，文件必须存在
 *    打开模式： a+ 读写模式，文件不存在则创建，存在则在文件末尾追加
 *    打开模式： w  写模式，文件不存在则创建，存在则清空
 *    打开模式： r  读模式，文件必须存在
 *    打开模式： a  写模式，文件不存在则创建，存在则在文件末尾追加
 * fclose(p)
 *    关闭文件
 * fwrite(p, size, count, f) 以二进制形式写入数据
 *    向文件写入数据
 *    p: 指向数据的指针
 *    size: 每个数据的大小
 *    count: 数据的个数
 *    f: 文件指针
 * *    返回值: 成功返回写入的元素个数，失败返回 0
 *    注意: fwrite() 函数会将数据以二进制形式写入文件，
 *    如果需要写入文本数据，可以使用 fprintf() 函数。
 *    示例:
 *    FILE *f = fopen("output.bin", "wb");
 *    if (f == NULL) {
 *        perror("Failed to open file");
 *        return;
 *    }
 *    int data[] = {1, 2, 3, 4, 5};
 *    size_t count = fwrite(data, sizeof(int), 5, f);
 *    if (count != 5) {
 *        perror("Failed to write data");
 *    }
 *    fclose(f);
 *    上述示例中，fwrite() 将整数数组 data 的内容以二进制形式写入到文件 "output.bin" 中。
 *    如果 fwrite() 函数失败，它会返回 0，并且不会写入任何数据到文件。
 *    如果 fwrite() 成功，它会返回写入的元素个数，并且数据会被写入到文件中。
 *    注意: fwrite() 函数的实现可能会有所不同，
 *    具体取决于编译器和标准库的实现。
 *    fwrite() 函数通常用于写入二进制数据到文件，
 *    如果需要写入文本数据，可以使用 fprintf() 函数。
 *    fwrite() 函数的使用注意事项是应该确保文件指针已经打开，
 *    并且文件指针处于可写状态，否则可能会导致未定义行为。
 *    fwrite() 函数的使用示例:
 *    FILE *f = fopen("output.bin", "wb");
 *    if (f == NULL) {
 *        perror("Failed to open file");
 *        return;
 *    }
 *    int data[] = {1, 2, 3, 4, 5};
 *    size_t count = fwrite(data, sizeof(int), 5, f);
 *    if (count != 5) {
 *        perror("Failed to write data");
 *    }
 *    fclose(f);
 *    上述示例中，fwrite() 将整数数组 data 的内容以二进制形式写入到文件 "output.bin" 中。
 *    如果 fwrite() 函数失败，它会返回 0，并且不会写入任何数据到文件。
 *    如果 fwrite() 成功，它会返回写入的元素个数，并且数据会被写入到文件中。
 *    注意: fwrite() 函数的实现可能会有所不同，
 *    具体取决于编译器和标准库的实现。
 *    fwrite() 函数通常用于写入二进制数据到文件，
 *    如果需要写入文本数据，可以使用 fprintf() 函数。
 *    fwrite() 函数的使用注意事项是应该确保文件指针已经打开，
 *    并且文件指针处于可写状态，否则可能会导致未定义行为。
 *    fwrite() 函数的使用示例:  
 * fread(p, size, count, f) 以二进制形式读取数据
 *    从文件中读取数据
 *    p: 存储读取数据的指针
 *    size: 每个数据的大小
 *    count: 数据的个数
 *    f: 文件指针
 *    返回值: 成功返回读取的元素个数，失败返回 0
 * fprint(f, format, ...)
 *    向文件写入格式化数据
 *    f: 文件指针
 *    format: 格式化字符串
 *    ...: 可变参数
 *    返回值: 成功返回写入的字符数，失败返回负数
 *    注意: fprint() 是一个非标准函数，通常使用 fprintf() 替换
 *    示例:
 *    FILE *f = fopen("output.txt", "w");
 *    if (f == NULL) {
 *        perror("Failed to open file");
 *        return;
 *    }
 *    int num = 42;
 *    fprint(f, "The answer is %d\n", num);
 *    fclose(f);
 *    上述示例中，fprint() 向文件 "output.txt" 写入了格式化字符串 "The answer is 42\n"。
 *    如果 fprint() 函数失败，它会返回一个负数，并且不会写入任何数据到文件。
 *    如果 fprint() 成功，它会返回写入的字符数，并且数据会被写入到文件中。
 *    注意: fprint() 函数的实现可能会有所不同，具体取决于编译器和标准库的实现。
 * fprintf(f, format, ...)
 *    向文件写入格式化数据
 *    f: 文件指针
 *    format: 格式化字符串
 *    ...: 可变参数
 * fgets(buffer, size, f)
 *    从文件中读取一行数据
 *    buffer: 存储读取数据的缓冲区
 *    size: 缓冲区大小
 *    f: 文件指针
 *    返回值: 成功返回指向缓冲区的指针，失败返回 NULL
 * fgetc(f)
 *    从文件中读取一个字符
 *    f: 文件指针
 *    返回值: 成功返回读取的字符，失败返回 EOF
 * fputc(c, f)
 *    向文件中写入一个字符
 *    c: 要写入的字符
 *    f: 文件指针
 *    返回值: 成功返回写入的字符，失败返回 EOF
 * feof(f)
 *    检查文件是否到达末尾
 *    f: 文件指针
 *    返回值: 如果到达末尾返回非零值，否则返回 0
 * ferror(f)
 *    检查文件是否发生错误
 *    f: 文件指针
 *    返回值: 如果发生错误返回非零值，否则返回 0
 * fflush(f)
 *    刷新文件缓冲区，将缓冲区中的数据写入文件
 *    f: 文件指针
 *    返回值: 成功返回 0，失败返回 EOF
 * ftell(f)
 *    获取文件指针当前位置
 *    f: 文件指针
 *    返回值: 成功返回当前位置的偏移量，失败返回 -1
 * fseek(f, offset, whence)
 *    设置文件指针位置
 *    f: 文件指针
 *    offset: 偏移量
 *    whence: 位置标志
 *        SEEK_SET: 从文件开头开始偏移
 *        SEEK_CUR: 从当前位置开始偏移
 *        SEEK_END: 从文件末尾开始偏移
 *    返回值: 成功返回 0，失败返回 -1
 * rewind(f)
 *    将文件指针重新定位到文件开头
 *    f: 文件指针
 *    返回值: 无返回值
 * remove(filename)
 *    删除文件
 *    filename: 要删除的文件名
 *    返回值: 成功返回 0，失败返回 -1
 * rename(oldname, newname)
 *    重命名文件
 *    oldname: 原文件名
 *    newname: 新文件名
 *    返回值: 成功返回 0，失败返回 -1
    * tmpfile() 
    * 创建一个临时文件，文件会在关闭时自动删除
 *    返回值: 成功返回指向临时文件的指针，失败返回 NULL
 *    注意: 临时文件的内容不保证是空的，可能包含之前的内容
 *    使用完临时文件后，应该使用 fclose() 关闭文件，以释放资源
 *    临时文件的路径通常在系统的临时目录中，可以使用 getenv("TMPDIR") 获取临时目录路径
 *    临时文件的名称通常是系统自动生成的，不需要手动指定
 *    临时文件的权限通常是只能被创建它的进程访问，其他进程无法访问
 *    临时文件的生命周期通常是从创建到关闭，关闭后文件会被删除
 *    临时文件的使用场景通常是需要临时存储数据，但不需要持久化到磁盘的情况
 *    临时文件的优点是可以避免手动管理文件
 *    临时文件的缺点是可能会被其他进程删除，导致数据丢失
 *    临时文件的使用注意事项是应该在使用完后及时关闭文件，以释放资源
 *    临时文件的使用示例:
 *    FILE *temp = tmpfile();
 *    if (temp == NULL) {
 *        perror("Failed to create temporary file");
 *        return;
 *    }
 *    fprintf(temp, "This is a temporary file.\n");
 *    rewind(temp); // 将文件指针重新定位到开头
 *    char buffer[256];
 *    while (fgets(buffer, sizeof(buffer), temp) != NULL) {
 *        printf("%s", buffer);
 *    }     
 */
void file_show_test(void)
{
    FILE *f1 = fopen("test.txt", "a");

    if (f1 == NULL) {
        perror("Failed to open file");
        return;
    }
    
    // fwrite("fwrite你好中文汉字Hello, World!\n", sizeof(char), 20,f1);
    // fwrite("fwrite你好中文汉字Hello, World!\n", sizeof(char), 45,f1);
    fprintf(f1, "fwrite你好中文汉字Hello, World!\n");
    // fprintf(f1, "fprintf 写入你好中文汉字Hello, World!\n");
    fputc('A', f1);
    fputs("fputs 写入你好中文汉字Hello, World!\n", f1);
    fclose(f1);

    f1 = fopen("test.txt", "r");
    if (f1 == NULL) {
        perror("Failed to open file for reading");
        return;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f1) != NULL) {
        printf("%s", buffer);
    }

    fclose(f1);

    // FILE* f2 = NULL;
    // f2 = fopen("test2.txt", "w+");
    // if (f2 == NULL) {
    //     perror("Failed to open file");
    //     return;
    // }

    // fprintf(f2, "你好中文汉字Hello, World!\n");
    // fclose(f2);
}