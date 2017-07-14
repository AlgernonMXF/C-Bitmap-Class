# C-Bitmap-Class
## A C++ Bitmap Class
C++ Bitmap类的定义

2017.7.14<br>
Bitmap.h及Bitmap.cpp中给出了Bitmap类的定义<br>
类中bool readFile(char \*filename)方法能够从文件名为filename的bmp文件中读取图像数据<br>
test.cpp中包含对该类的测试，读入input.bmp文件，将其各像素点的B，G分量设为0后写入输出图像output.bmp.
test.cpp中的程序现在仅能读取24位色图像
