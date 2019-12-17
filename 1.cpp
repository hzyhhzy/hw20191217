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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

