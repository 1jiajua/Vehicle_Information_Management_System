#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
void Input(struct car *p,int n);//录入车辆信息函数
void Browse(struct car *p,int n);//浏览车辆信息函数
void Query(struct car *p,int n);//查询车辆信息函数
void Chaxun1(struct car *p,int n,int x);//查询车辆信息子函数1
void Chaxun2(struct car *p,int n);//查询车辆信息子函数2
void Modify(struct car *p,int n);//修改车辆信息函数
void Xiugai(struct car *p,int n,int x,int j);//修改车辆信息子函数
void Delet(struct car *p,int n);//删除车辆信息函数
void Shanchu1(struct car *p,int n,int x);//删除车辆信息子函数1
void Shanchu2(struct car *p,int n);//删除车辆信息子函数2
void Sort(struct car *p,int n);//排序车辆信息函数
void Paixu(struct car *p,int n,int x);//排序车辆信息子函数
void Initialize();//初始化系统函数
struct car
{
	int jlh;//记录号
	char xh[10];//型号
	char cs[10];//厂商
	char cx[10];//车型
	int zws;//座位数
	float pl;//排量
	char bsx[20];//变速箱
	char ys[10];//颜色
	float jg;//价格
}che[50];
int main()
{
	FILE *fp;
	int i,n;
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                      欢迎使用车辆信息管理系统\n\n");
	printf("\t\t\t                          按1进入系统菜单\n\n");
	printf("\t\t\t                            按2退出系统\n\n");
	scanf("%d",&i);
	if(i==1)
		break;
	else if(i==2)
		exit(0);
	}while(1);
	do{
	if((fp=fopen("车辆信息.txt","rb"))==NULL)
	{
		printf("无法打开文件\n");
		exit(0);
	}
	n=fread(che,sizeof(struct car),50,fp);
	fclose(fp);
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                         请选择要进行的操作\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           1.录入车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           2.浏览车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           3.查询车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           4.修改车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           5.删除车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           6.排序车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           7.初始化系统\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           8.退出系统\n");
	printf("\t\t\t                         ------------------\n\n");
	scanf("%d",&i);
	switch(i)
	{
	case 1:system("cls");Input(che,n);break;//录入车辆信息
	case 2:system("cls");Browse(che,n);break;//浏览车辆信息
	case 3:system("cls");Query(che,n);break;//查询车辆信息
	case 4:system("cls");Modify(che,n);break;//修改车辆信息
	case 5:system("cls");Delet(che,n);break;//删除车辆信息
	case 6:system("cls");Sort(che,n);break;//排序车辆信息
	case 7:system("cls");Initialize();break;//初始化系统
	case 8:exit(0);//退出系统
	}
	}while(1);
	return 0;
}
//系统菜单
void Input(struct car *p,int n)
{
	FILE *fp;
	int i,x;
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            录入车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	do{
	n++;
	i=n-1;
	(p+i)->jlh=n;
	printf("\t\t\t请输入记录号%d车辆的型号：",n);
	scanf("%s",(p+i)->xh);
	printf("\t\t\t请输入记录号%d车辆的厂商：",n);
	scanf("%s",(p+i)->cs);
	printf("\t\t\t请输入记录号%d车辆的车型：",n);
	scanf("%s",(p+i)->cx);
	printf("\t\t\t请输入记录号%d车辆的座位数：",n);
	scanf("%d",&(p+i)->zws);
	printf("\t\t\t请输入记录号%d车辆的排量(单位:T)：",n);
	scanf("%f",&(p+i)->pl);
	printf("\t\t\t请输入记录号%d车辆的变速箱：",n);
	scanf("%s",(p+i)->bsx);
	printf("\t\t\t请输入记录号%d车辆的颜色：",n);
	scanf("%s",(p+i)->ys);
	printf("\t\t\t请输入记录号%d车辆的价格(单位:万)：",n);
	scanf("%f",&(p+i)->jg);
	if((fp=fopen("车辆信息.txt","ab"))==NULL)
	{
		printf("无法打开文件\n");
		exit(0);
	}
	if(fwrite(&che[i],sizeof(struct car),1,fp)!=1)
		printf("文件写入失败\n");
	fclose(fp);
	printf("\n\n记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格");
	printf("\n\n  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("记录号%d车辆信息录入完毕，信息如上，继续录入请按1，返回系统菜单请按其他键\n",n);
	scanf("%d",&x);
	if(x!=1)
		break;
	}while(1);
}
//录入车辆信息
void Browse(struct car *p,int n)
{
	int i;
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            浏览车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("系统共存有%d辆车的信息，具体如下：\n\n",n);
	printf("记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
	for(i=0;i<n;i++)
		printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("\n");
	system("pause");
}
//浏览车辆信息
void Query(struct car *p,int n)
{
	int x;
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            查询车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          1.按[型号]查询\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          2.按[厂商]查询\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          3.按[车型]查询\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          4.按[价格范围]查询\n");
	printf("\t\t\t                         ------------------\n");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
	case 2:
	case 3:Chaxun1(p,n,x);break;
	case 4:Chaxun2(p,n);
	}
	if(x==1||x==2||x==3||x==4)
	{
		printf("\n");
		system("pause");
		break;
	}
	}while(1);
}
//查询车辆信息
void Chaxun1(struct car *p,int n,int x)
{
	int i=0,j;
	char a[5],b[10];
	if(x==1)
		strcpy(a,"型号");
	else if(x==2)
		strcpy(a,"厂商");
	else if(x==3)
		strcpy(a,"车型");
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            查询车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          按[%s]查询车辆\n\n",a);
	printf("\t\t\t请输入%s，以查询相应车辆：",a);
	scanf("%s",b);
	if(x==1)
	{
		for(i=0,j=0;i<n;i++)
			if(strcmp((p+i)->xh,b)==0)
				j++;
	}
	else if(x==2)
	{
		for(i=0,j=0;i<n;i++)
			if(strcmp((p+i)->cs,b)==0)
				j++;
	}
	else if(x==3)
	{
		for(i=0,j=0;i<n;i++)
			if(strcmp((p+i)->cx,b)==0)
				j++;
	}
	if(j!=0)
	{
		printf("\n%s为[%s]的车辆共有%d辆，信息如下：\n\n",a,b,j);
		printf("记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
	}
	else
		printf("\n\n\t\t\t                         无%s为[%s]的车辆\n\n",a,b);
	if(x==1)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->xh,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	else if(x==2)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->cs,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	else if(x==3)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->cx,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
}
//查询车辆信息子1
void Chaxun2(struct car *p,int n)
{
	int i,j;
	float a,b;
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            查询车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                        按[价格范围]查询车辆\n\n");
	printf("\t\t\t请分别输入最低价格与最高价格(单位:万)，以查询相应车辆：");
	scanf("%f%f",&a,&b);
	if(a>b)
	{
		printf("\n\t\t\t                  价格范围输入错误，请3秒后重新输入！\n");
		Sleep(3000);
		continue;
	}
	else
	{
		for(i=0,j=0;i<n;i++)
			if(((p+i)->jg>=a)&&((p+i)->jg<=b))
				j++;
	}
	if(j!=0)
	{
		printf("\n价格范围为%.2f万~%.2f万的车辆共有%d辆，信息如下：\n\n",a,b,j);
		printf("记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
		for(i=0;i<n;i++)
			if(((p+i)->jg>=a)&&((p+i)->jg<=b))
				printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	else
		printf("\n\n\t\t\t                  无价格范围为%.2f万~%.2f万的车辆\n\n",a,b);
	break;
	}while(1);

}
//查询车辆信息子2
void Modify(struct car *p,int n)
{
	int i,j=0,x;
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            修改车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
	for(i=0;i<n;i++)
		printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("\n");
	printf("\t\t\t所有车辆信息如上，请输入要修改车辆的记录号：");
	do{
		scanf("%d",&x);
		for(i=0;i<n;i++)
		{
			if((p+i)->jlh==x)
			{
				j++;
				printf("\n\n记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
				printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
				break;
			}
		}
		if(j==0)
		{
			printf("\t\t\t无此记录号，请重新输入正确记录号：");
			continue;
		}
		break;
	}while(1);
	j=x;
	printf("\n\t\t\t                         请选择要修改的参数\n\t\t\t                           --------------\n");
	printf("\t\t\t                             1.车辆型号\n\t\t\t                           --------------\n");
	printf("\t\t\t                             2.厂商\n\t\t\t                           --------------\n");
	printf("\t\t\t                             3.车型级别\n\t\t\t                           --------------\n");
	printf("\t\t\t                             4.座位数\n\t\t\t                           --------------\n");
	printf("\t\t\t                             5.排量\n\t\t\t                           --------------\n");
	printf("\t\t\t                             6.变速箱\n\t\t\t                           --------------\n");
	printf("\t\t\t                             7.车身颜色\n\t\t\t                           --------------\n");
	printf("\t\t\t                             8.车辆价格\n\t\t\t                           --------------\n");
	do{
		scanf("%d",&x);
		switch(x)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:Xiugai(p,n,x,j);break;
		default:printf("\t\t\t                          请重新正确选择：");
		}
		if(x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8)
		{
			printf("\n\t\t\t                          车辆信息修改成功！\n");
			system("pause");
			break;
		}
	}while(1);
}
//修改车辆信息
void Xiugai(struct car *p,int n,int x,int j)
{
	FILE *fp;
	int i=j-1,k;
	float f;
	char a[10];
	switch(x)
	{
	case 1:
		printf("\t\t\t请输入新的车辆型号：");
		scanf("%s",a);
		strcpy((p+i)->xh,a);
		break;
	case 2:
		printf("\t\t\t请输入新的厂商：");
		scanf("%s",a);
		strcpy((p+i)->cs,a);
		break;
	case 3:
		printf("\t\t\t请输入新的车型级别：");
		scanf("%s",a);
		strcpy((p+i)->cx,a);
		break;
	case 4:
		printf("\t\t\t请输入新的座位数：");
		scanf("%d",&k);
		((p+i)->zws)=k;
		break;
	case 5:
		printf("\t\t\t请输入新的排量：");
		scanf("%f",&f);
		((p+i)->pl)=f;
		break;
	case 6:
		printf("\t\t\t请输入新的变速箱：");
		scanf("%s",a);
		strcpy((p+i)->bsx,a);
		break;
	case 7:
		printf("\t\t\t请输入新的颜色：");
		scanf("%s",a);
		strcpy((p+i)->ys,a);
		break;
	case 8:
		printf("\t\t\t请输入新的价格：");
		scanf("%f",&f);
		((p+i)->jg)=f;
	}
	if((fp=fopen("车辆信息.txt","wb"))==NULL)
	{
		printf("无法打开文件\n");
		exit(0);
	}
	if(fwrite(che,sizeof(struct car),n,fp)!=n)
		printf("修改失败\n");
	else
	{
		printf("\n记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
		printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	fclose(fp);
}
//修改车辆信息子
void Delet(struct car *p,int n)
{
	int x;
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            删除车辆信息\n");
	printf("\t\t\t                       ----------------------\n");
	printf("\t\t\t                        1.按[型号]查找，并删除\n");
	printf("\t\t\t                       ----------------------\n");
	printf("\t\t\t                        2.按[厂商]查找，并删除\n");
	printf("\t\t\t                       ----------------------\n");
	printf("\t\t\t                        3.查看全部，并删除\n");
	printf("\t\t\t                       ----------------------\n");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
	case 2:Shanchu1(p,n,x);break;
	case 3:Shanchu2(p,n);
	}
	if(x==1||x==2||x==3)
		break;
	}while(1);
}
//删除车辆信息
void Shanchu1(struct car *p,int n,int x)
{
	FILE *fp;
	int i,j,k,t,c[50];
	char a[5],b[10];
	if(x==1)
		strcpy(a,"型号");
	else
		strcpy(a,"厂商");
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            删除车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                            按[%s]查找\n\n",a);
	printf("\t\t\t请输入%s，以查找相应车辆：",a);
	scanf("%s",b);
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            删除车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                            按[%s]查找\n\n",a);
	if(x==1)
	{
		for(i=0,j=0;i<n;i++)
			if(strcmp((p+i)->xh,b)==0)
			{
				c[j]=i;
				j++;
			}
	}
	else if(x==2)
	{
		for(i=0,j=0;i<n;i++)
			if(strcmp((p+i)->cs,b)==0)
			{
				c[j]=i;
				j++;
			}
	}
	if(j!=0)
	{
		printf("\n%s为[%s]的车辆共有%d辆，信息如下：\n\n",a,b,j);
		printf("记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
	}
	else
	{
		printf("\n\t\t\t                         无%s为[%s]的车辆\n\n\n",a,b);
		system("pause");
		break;
	}
	if(x==1)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->xh,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	else if(x==2)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->cs,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	printf("\n\t\t\t                         请选择要进行的操作\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             1.单个删除\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             2.全部删除\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             3.取消\n");
	printf("\t\t\t                           --------------\n");
	scanf("%d",&k);
	if(k==1)
	{
		printf("\t\t\t请输入要删除车辆的记录号：");
		do{
			scanf("%d",&x);
			for(i=0,k=0;i<j;i++)
				if(c[i]==x-1)
					k++;
			if(k)
			{
				for(i=0;i<n;i++)
				{
					if((p+i)->jlh==x)
					{
						printf("\n记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
						printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
						break;
					}
				}
			}
			if(!k)
			{
				printf("\t\t\t无%s为[%s]且记录号为%d的车辆，请重新输入正确记录号：",a,b,x);
				continue;
			}
			break;
		}while(1);
		for(i=x-1;i<n;i++)
		{
			*(p+i)=*(p+i+1);
		}
		for(i=0;i<n-1;i++)
			(p+i)->jlh=i+1;
		if((fp=fopen("车辆信息.txt","wb"))==NULL)
		{
			printf("无法打开文件\n");
			exit(0);
		}
		if(fwrite(che,sizeof(struct car),n-1,fp)!=n-1)
			printf("删除失败\n");
		else
			printf("\n\t\t\t                          车辆信息删除成功！\n\t\t\t                     （记录号已按顺序重新赋值）\n");
		fclose(fp);
		system("pause");
		break;
	}
	else if(k==2)
	{
		for(i=0,k=0,t=0;k<n;i++,k++)
		{
			if(k==c[t])
			{
				t++;
				i--;
				continue;
			}
			*(p+i)=*(p+k);
		}
		for(i=0;i<n-j;i++)
			(p+i)->jlh=i+1;
		if((fp=fopen("车辆信息.txt","wb"))==NULL)
		{
			printf("无法打开文件\n");
			exit(0);
		}
		if(fwrite(che,sizeof(struct car),n-j,fp)!=n-j)
			printf("删除失败\n");
		else
			printf("\t\t\t                  %s为[%s]的车辆全部删除成功！\n\t\t\t                     （记录号已按顺序重新赋值）\n",a,b);
		fclose(fp);
		system("pause");
		break;
	}
	else if(k==3)
		break;
	}while(1);
}
//删除车辆信息子1
void Shanchu2(struct car *p,int n)
{
	FILE *fp;
	int i,x;
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            删除车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                              查看全部\n\n");
	printf("记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
	for(i=0;i<n;i++)
		printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("\n\t\t\t                          全部车辆信息如上\n");
	printf("\t\t\t                         请选择要进行的操作\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             1.单个删除\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             2.全部删除\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             3.取消\n");
	printf("\t\t\t                           --------------\n");
	scanf("%d",&x);
	if(x==1)
	{
		printf("\t\t\t请输入要删除车辆的记录号：");
		do{
			scanf("%d",&x);
			for(i=0;i<n;i++)
			{
				if((p+i)->jlh==x)
				{
					printf("\n\n记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
					printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
					break;
				}
			}
			if(x<1||x>n)
			{
				printf("\t\t\t无此记录号，请重新输入正确记录号：");
				continue;
			}
			break;
		}while(1);
		for(i=x-1;i<n;i++)
		{
			*(p+i)=*(p+i+1);
		}
		for(i=0;i<n-1;i++)
			(p+i)->jlh=i+1;
		if((fp=fopen("车辆信息.txt","wb"))==NULL)
		{
			printf("无法打开文件\n");
			exit(0);
		}
		if(fwrite(che,sizeof(struct car),n-1,fp)!=n-1)
			printf("删除失败\n");
		else
			printf("\n\t\t\t                          车辆信息删除成功！\n\t\t\t                     （记录号已按顺序重新赋值）\n");
		fclose(fp);
		system("pause");
		break;
	}
	else if(x==2)
	{
		if((fp=fopen("车辆信息.txt","wb"))==NULL)
		{
			printf("删除失败\n");
			exit(0);
		}
		printf("\t\t\t                           全部删除成功！\n");
		system("pause");
		break;
	}
	else if(x==3)
		break;
	}while(1);
}
//删除车辆信息子2
void Sort(struct car *p,int n)
{
	int x;
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            排序车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          1.按[价格]排序\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          2.按[排量]排序\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          3.按[座位数]排序\n");
	printf("\t\t\t                         ------------------\n");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
	case 2:
	case 3:Paixu(p,n,x);break;
	}
	if(x==1||x==2||x==3)
		break;
	}while(1);
}
//排序车辆信息
void Paixu(struct car *p,int n,int x)
{
	FILE *fp;
	struct car t;
	int i,j,k;
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            排序车辆信息\n");
	printf("\t\t\t                         ------------------\n");
	switch(x)
	{
	case 1:
		printf("\t\t\t                          按[价格]排序车辆\n\n");
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(((p+i)->jg)>((p+j)->jg))
				{
					t=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=t;
				}
		break;
	case 2:
		printf("\t\t\t                          按[排量]排序车辆\n\n");
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(((p+i)->pl)>((p+j)->pl))
				{
					t=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=t;
				}
		break;
	case 3:
		printf("\t\t\t                         按[座位数]排序车辆\n\n");
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(((p+i)->zws)>((p+j)->zws))
				{
					t=*(p+i);
					*(p+i)=*(p+j);
					*(p+j)=t;
				}
	}
	for(i=0;i<n;i++)
			(p+i)->jlh=i+1;
	printf("记录号    车辆型号     厂商        车型级别    座位数    排量    变速箱     车身颜色    车辆价格\n\n");
	for(i=0;i<n;i++)
		printf("  %-8d%-13s%-12s%-12s%d座       %-0.1fT    %-11s%-12s%-0.2f万\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("\n\n\t\t\t              排序完成，排序后信息如上，是否确定保存？\n");
	printf("\t\t\t                     （记录号已按顺序重新赋值）\n\n");
	printf("\t\t\t                          1.确定   2.取消\n");
	scanf("%d",&k);
	if(k==1)
	{
		if((fp=fopen("车辆信息.txt","wb"))==NULL)
		{
			printf("无法打开文件\n");
			exit(0);
		}
		if(fwrite(che,sizeof(struct car),n,fp)!=n)
			printf("文件写入失败\n");
		fclose(fp);
		printf("\t\t\t                             保存成功！\n");
		system("pause");
		break;
	}
	else if(k==2)
		break;
	}while(1);
}
//排序车辆信息子
void Initialize()
{
	FILE *old,*neww;
	int i;
	do{
	system("cls");
	printf("\t\t\t                         *车辆信息管理系统*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                             初始化系统\n");
	printf("\t\t\t                         ------------------\n\n");
	printf("\t\t\t           是否确定初始化系统，将车辆信息还原至最初信息？\n\n");
	printf("\t\t\t                          1.确定   2.取消\n");
	scanf("%d",&i);
	if(i==1)
	{
		if((old=fopen("车辆信息.txt","wb"))==NULL)
		{
			printf("无法打开文件\n");
			exit(0);
		}
		if((neww=fopen("初始化信息.txt","rb"))==NULL)
		{
			printf("无法打开文件\n");
			exit(0);
		}
		if(fread(che,sizeof(struct car),10,neww)!=10)
			printf("初始化信息读入出错\n");
		if(fwrite(che,sizeof(struct car),10,old)!=10)
			printf("初始化信息写入出错\n");
		fclose(old);
		fclose(neww);
		printf("\t\t\t                          系统初始化成功！\n");
		system("pause");
		break;
	}
	else if(i==2)
		break;
	}while(1);
}
//初始化系统