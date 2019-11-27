#include <iostream>
#include <ctime>
#include <stdlib.h>//随机函数头文件
#include <cmath>

using namespace std;


int main()
{	double P[10][3]={1,0.1,1.2,1,0.7,1.8,1,0.8,1.6,1,0.8,0.6,1,1.0,0.8,1,0.3,0.5,1,0,0.2,1,-0.3,0.8,1,-0.5,-1.5,1,-1.5,-1.3};//样本
	double T[10][2]={1,0,1,0,1,0,0,0,0,0,1,1,1,1,1,1,0,1,0,1};//理想输出
	double W[3][2]={0};//权值
    double Y[10][2]={0.00};//实际输出
	double s = 0.0;//  活化值
	double step=0.2,e=0.00;//定义学习步长和误差
	int i,j,k,pass=0;
    srand((unsigned)time(NULL));//  为避免随机数相同，以时间为种子产生随机数
	cout<<"初始的连接权值和阈值：\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<2;j++)//对权值赋初始值
		{
			W[i][j]=(rand()%100)/100.000;
			cout<<"W["<<i<<"]["<<j<<"]="<<W[i][j]<<"     ";
		}
		cout<<" \n";
	}
	do 
	{
		e=0;//误差初始值
		double max=0;//每个训练周期的误差
	    cout<<"\n";
		++pass;//记录训练次数
        /////////////////////////////////////////learning samples///////////////////
		for (i = 0; i < 10; i++)//对10样本训练
		{
			for (j = 0; j < 2; j++)
			{
            	for (k = 0; k < 3; k++)
            	{
            		s = s + P[i][k] * W[k][j];
            	}
			 	if (s < 0)//运用二值函数为作用函数
			 	{
					Y[i][j]=0;
			 	}	 
			 	else
			 	{
					Y[i][j]=1;
			 	}
			  	s=0.0;//活化值置零
			  	e=fabs(T[i][j]-Y[i][j]);//求浮点数的绝对值
			}
			if (e==0)
			{
				continue;
			}
			else
			///////////////////////////////权值修改///////////////////////////
				for (j=0;j<3;j++)//权值调整
				{
					for (k=0;k<2;k++)
					{
						ZLW[j][k]=step*(T[i][k]-Y[i][k])*P[i][j];
						W[j][k]=W[j][k]+ZLW[j][k];
					}
					
				}
		}	
	}while (e<0.1&&pass<6000);
    
	cout<<"训练次数为："<<pass<<endl;
	cout<<"输出最后的权值:";
	cout<<"\n";
	for (i=0;i<3;i++)
	{
		for (j=0;j<2;j++)
		{
			cout<<"W["<<i<<"]"<<"["<<j<<"]="<<W[i][j]<<"   ";
		}
		cout<<"\n";
	}
    cout<<"输出验证结果：训练后实际结果与理想值对比";
	cout<<"\n";
	for (i=0;i<10;i++)//十个样本验证结果
	{
		for (j=0;j<2;j++)
		{
			for (k=0;k<3;k++)
			{
				Y[i][j]=Y[i][j]+P[i][k]*W[k][j];
			}
			if(	Y[i][j]<0)
			{	
				Y[i][j]=0; 
			}
			else
			{	
				Y[i][j]=1;
			}
			cout<<"Y["<<i<<"]["<<j<<"]="<<Y[i][j]<<"   ";
			cout<<"T["<<i<<"]["<<j<<"]="<<T[i][j]<<" \n";
		}
		cout<<"\n";
	}
	return 0;
}
