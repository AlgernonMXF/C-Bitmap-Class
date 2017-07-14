#include "MyBitmap.h"

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	char inFile[] = "input.bmp";
	char outBmp[] = "output.bmp";
	int i, j;

	MyBitmap pic;

	//读图像文件
	pic.readFile(inFile);

	int height = pic.infoHeader.biHeight;			//图片高度
	int width = pic.infoHeader.biWidth;				//图片长度
	int size = height * width * pic.infoHeader.biBitCount / 8;				//图像数据字节数

	//暂时仅支持无压缩，biBitCount = 24的bmp图像
	if (pic.infoHeader.biBitCount / 8 != 3)
	{
		cerr << "暂时不支持该结构图像！" << endl;
		exit(0);
	}

	//test: 将图片的B,G通道值全部设为0
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			pic.buffer[i * 3 * width + j * 3 + 0] = 0;
			pic.buffer[i * 3 * width + j * 3 + 1] = 0;
		}
	}

	//输出处理后图像
	FILE *output = fopen(outBmp, "wb");
	if (!output)
	{
		cout << "Cannot open output file!\n";
		exit(0);
	}

	fwrite(&pic.fileHeader, 1, sizeof(MYBITMAPFILEHEADER), output);
	fwrite(&pic.infoHeader, 1, sizeof(MYBITMAPINFOHEADER), output);
	fwrite(pic.buffer, 1, size, output);
	fclose(output);

	return 0;
}