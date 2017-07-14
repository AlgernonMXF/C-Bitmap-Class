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

	//��ͼ���ļ�
	pic.readFile(inFile);

	int height = pic.infoHeader.biHeight;			//ͼƬ�߶�
	int width = pic.infoHeader.biWidth;				//ͼƬ����
	int size = height * width * pic.infoHeader.biBitCount / 8;				//ͼ�������ֽ���

	//��ʱ��֧����ѹ����biBitCount = 24��bmpͼ��
	if (pic.infoHeader.biBitCount / 8 != 3)
	{
		cerr << "��ʱ��֧�ָýṹͼ��" << endl;
		exit(0);
	}

	//test: ��ͼƬ��B,Gͨ��ֵȫ����Ϊ0
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			pic.buffer[i * 3 * width + j * 3 + 0] = 0;
			pic.buffer[i * 3 * width + j * 3 + 1] = 0;
		}
	}

	//��������ͼ��
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