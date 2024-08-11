#include<bits/stdc++.h>
using namespace std;
void Spiral_Number_Matrix_Clockwise(int n);   //顺时针
void Spiral_Number_Matrix_anticlockwise(int n);  //逆时针
int main(void)
{
    int n; //控制正方形边长
    scanf("%d",&n);
    Spiral_Number_Matrix_Clockwise(n);  //顺时针
	Spiral_Number_Matrix_anticlockwise(n);  //逆时针
    return 0;
}
void Spiral_Number_Matrix_Clockwise(int n)
{
    int k, a[n][n];
	int i, j, circle=1;
	int temp=1;
	for (i = 0; i < n; i++)
		a[0][i] = temp++;  //赋值第一行
	for (j = n - 1; j >= n / 2; j--) //多次循环，得到矩阵数组的所有值
		{
			for (i = circle; i <= j; i++)
				a[i][j] = temp++;   //赋值第j+1列
			for (i = j; i >= circle; i--)
				a[j][i-1] = temp++;//赋值第j+1行
			for (i = j; i > circle; i--)
				a[i - 1][circle - 1] = temp++;//赋值circle列
			for (i = circle; i < j; i++)
				a[circle][i] = temp++;//赋值circle+1列（第一次循环为第二列）
			circle++;//circle加1，依次按照以上顺序对矩阵内部进行赋值
		}
		printf("Clockwise: \n");
	for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%4d", a[i][j]);//打印矩阵	
			}          
			cout << endl;         //每行换行
		}
	cout << endl;                 //打印完整个矩阵换行
}
void Spiral_Number_Matrix_anticlockwise(int n)
{
	int k, a[n][n];
	int i, j, circle=1;
	int temp=1;
	for (i = 0; i < n; i++)
		a[i][0] = temp++;  //赋值第一列
	for (j = n - 1; j >= n / 2; j--) //多次循环，得到矩阵数组的所有值
		{
			for (i = circle; i <= j; i++)
				a[j][i] = temp++;   //赋值第j+1行（第一次循环为最后一行）
			for (i = j; i >= circle; i--)
				a[i - 1][j] = temp++;//赋值第j+1列（第一次循环为最后一列）
			for (i = j; i > circle; i--)
				a[circle - 1][i - 1] = temp++;//赋值circle行，（第一次循环为第一行）
			for (i = circle; i < j; i++)
				a[i][circle] = temp++;//赋值circle+1列（第一次循环为第二列）
			circle++;//circle加1，依次按照以上顺序对矩阵内部进行赋值
		}
	printf("anticlockwise: \n");
	for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%4d", a[i][j]);//打印矩阵	
			}          
			cout << endl;         //每行换行
		}
	cout << endl;                 //打印完整个矩阵换行
}