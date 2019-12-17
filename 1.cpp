#include <iostream>
#include <vector>
#include<random>
#include<ctime>
#include<fstream>
using namespace std;
std::mt19937 rnd(time(0));
inline int xyz(int x, int y, int z,int n)
{
	return x + n * (y + n * z);
}
bool hasLiberty(int x, int  y, int  z, int n, vector<char>& data)
{

	char color = data[xyz(x, y, z, n)];
	data[xyz(x, y, z, n)] += 3;
	bool hasl = false;
	if (x != 0)
	{
		bool tmp;
		if (data[xyz(x - 1, y, z, n)] == 0)hasl = true;
		else if (data[xyz(x - 1, y, z, n)] == color)
		{
			tmp = hasLiberty(x - 1, y, z, n, data);
			if (tmp)hasl = true;
		}
	}
	if (x != n - 1)
	{
		bool tmp;
		if (data[xyz(x + 1, y, z, n)] == 0)hasl = true;
		else if (data[xyz(x + 1, y, z, n)] == color)
		{
			tmp = hasLiberty(x + 1, y, z, n, data);
			if (tmp)hasl = true;
		}
	}
	if (y != 0)
	{
		bool tmp;
		if (data[xyz(x, y - 1, z, n)] == 0)hasl = true;
		else if (data[xyz(x, y - 1, z, n)] == color)
		{
			tmp = hasLiberty(x, y - 1, z, n, data);
			if (tmp)hasl = true;
		}
	}
	if (y != n - 1)
	{
		bool tmp;
		if (data[xyz(x, y + 1, z, n)] == 0)hasl = true;
		else if (data[xyz(x, y + 1, z, n)] == color)
		{
			tmp = hasLiberty(x, y + 1, z, n, data);
			if (tmp)hasl = true;
		}
	}
	if (z != 0)
	{
		bool tmp;
		if (data[xyz(x, y , z-1, n)] == 0)hasl = true;
		else if (data[xyz(x, y, z - 1, n)] == color)
		{
			tmp = hasLiberty(x, y, z - 1, n, data);
			if (tmp)hasl = true;
		}
	}
	if (z != n - 1)
	{
		bool tmp;
		if (data[xyz(x, y , z+1, n)] == 0)hasl = true;
		else if (data[xyz(x, y, z + 1, n)] == color)
		{
			tmp = hasLiberty(x, y, z + 1, n, data);
			if (tmp)hasl = true;
		}
	}
	return hasl;
}
int main()
{
	ofstream ofs("data.txt");
	for (int n = 2; n < 100; n++)
	{
		int times = 1000000;
		vector<char> data(n*n*n);
		int count = 0;

		for (int t = 0; t < times; t++)
		{
			for (int i = 0; i < data.size(); i++)
			{
				data[i] = rnd() % 3;//empty=0,b=1,w=2
			}
			//search
			bool isLegal = true;
			for (int z = 0; z < n; z++)
			{

				for (int y = 0; y < n; y++)
				{
					for (int x = 0; x < n; x++)
					{
						if (data[xyz(x, y, z, n)] == 0 || data[xyz(x, y, z, n)] >= 3)continue;
						if (hasLiberty(x, y, z, n, data))continue;
						isLegal = false;

						if (!isLegal)break;
					}
					if (!isLegal)break;
				}
				if (!isLegal)break;

			}
			if (isLegal)count++;
		}
		cout <<n<<"    "<< 1.0*count / times<<endl;
		ofs<<n<<"    "<< 1.0*count / times<<endl;
	}
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�

