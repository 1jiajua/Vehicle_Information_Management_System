#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
void Input(struct car *p,int n);//¼�복����Ϣ����
void Browse(struct car *p,int n);//���������Ϣ����
void Query(struct car *p,int n);//��ѯ������Ϣ����
void Chaxun1(struct car *p,int n,int x);//��ѯ������Ϣ�Ӻ���1
void Chaxun2(struct car *p,int n);//��ѯ������Ϣ�Ӻ���2
void Modify(struct car *p,int n);//�޸ĳ�����Ϣ����
void Xiugai(struct car *p,int n,int x,int j);//�޸ĳ�����Ϣ�Ӻ���
void Delet(struct car *p,int n);//ɾ��������Ϣ����
void Shanchu1(struct car *p,int n,int x);//ɾ��������Ϣ�Ӻ���1
void Shanchu2(struct car *p,int n);//ɾ��������Ϣ�Ӻ���2
void Sort(struct car *p,int n);//��������Ϣ����
void Paixu(struct car *p,int n,int x);//��������Ϣ�Ӻ���
void Initialize();//��ʼ��ϵͳ����
struct car
{
	int jlh;//��¼��
	char xh[10];//�ͺ�
	char cs[10];//����
	char cx[10];//����
	int zws;//��λ��
	float pl;//����
	char bsx[20];//������
	char ys[10];//��ɫ
	float jg;//�۸�
}che[50];
int main()
{
	FILE *fp;
	int i,n;
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                      ��ӭʹ�ó�����Ϣ����ϵͳ\n\n");
	printf("\t\t\t                          ��1����ϵͳ�˵�\n\n");
	printf("\t\t\t                            ��2�˳�ϵͳ\n\n");
	scanf("%d",&i);
	if(i==1)
		break;
	else if(i==2)
		exit(0);
	}while(1);
	do{
	if((fp=fopen("������Ϣ.txt","rb"))==NULL)
	{
		printf("�޷����ļ�\n");
		exit(0);
	}
	n=fread(che,sizeof(struct car),50,fp);
	fclose(fp);
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                         ��ѡ��Ҫ���еĲ���\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           1.¼�복����Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           2.���������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           3.��ѯ������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           4.�޸ĳ�����Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           5.ɾ��������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           6.��������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           7.��ʼ��ϵͳ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                           8.�˳�ϵͳ\n");
	printf("\t\t\t                         ------------------\n\n");
	scanf("%d",&i);
	switch(i)
	{
	case 1:system("cls");Input(che,n);break;//¼�복����Ϣ
	case 2:system("cls");Browse(che,n);break;//���������Ϣ
	case 3:system("cls");Query(che,n);break;//��ѯ������Ϣ
	case 4:system("cls");Modify(che,n);break;//�޸ĳ�����Ϣ
	case 5:system("cls");Delet(che,n);break;//ɾ��������Ϣ
	case 6:system("cls");Sort(che,n);break;//��������Ϣ
	case 7:system("cls");Initialize();break;//��ʼ��ϵͳ
	case 8:exit(0);//�˳�ϵͳ
	}
	}while(1);
	return 0;
}
//ϵͳ�˵�
void Input(struct car *p,int n)
{
	FILE *fp;
	int i,x;
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ¼�복����Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	do{
	n++;
	i=n-1;
	(p+i)->jlh=n;
	printf("\t\t\t�������¼��%d�������ͺţ�",n);
	scanf("%s",(p+i)->xh);
	printf("\t\t\t�������¼��%d�����ĳ��̣�",n);
	scanf("%s",(p+i)->cs);
	printf("\t\t\t�������¼��%d�����ĳ��ͣ�",n);
	scanf("%s",(p+i)->cx);
	printf("\t\t\t�������¼��%d��������λ����",n);
	scanf("%d",&(p+i)->zws);
	printf("\t\t\t�������¼��%d����������(��λ:T)��",n);
	scanf("%f",&(p+i)->pl);
	printf("\t\t\t�������¼��%d�����ı����䣺",n);
	scanf("%s",(p+i)->bsx);
	printf("\t\t\t�������¼��%d��������ɫ��",n);
	scanf("%s",(p+i)->ys);
	printf("\t\t\t�������¼��%d�����ļ۸�(��λ:��)��",n);
	scanf("%f",&(p+i)->jg);
	if((fp=fopen("������Ϣ.txt","ab"))==NULL)
	{
		printf("�޷����ļ�\n");
		exit(0);
	}
	if(fwrite(&che[i],sizeof(struct car),1,fp)!=1)
		printf("�ļ�д��ʧ��\n");
	fclose(fp);
	printf("\n\n��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�");
	printf("\n\n  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("��¼��%d������Ϣ¼����ϣ���Ϣ���ϣ�����¼���밴1������ϵͳ�˵��밴������\n",n);
	scanf("%d",&x);
	if(x!=1)
		break;
	}while(1);
}
//¼�복����Ϣ
void Browse(struct car *p,int n)
{
	int i;
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ���������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("ϵͳ������%d��������Ϣ���������£�\n\n",n);
	printf("��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
	for(i=0;i<n;i++)
		printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("\n");
	system("pause");
}
//���������Ϣ
void Query(struct car *p,int n)
{
	int x;
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ��ѯ������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          1.��[�ͺ�]��ѯ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          2.��[����]��ѯ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          3.��[����]��ѯ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          4.��[�۸�Χ]��ѯ\n");
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
//��ѯ������Ϣ
void Chaxun1(struct car *p,int n,int x)
{
	int i=0,j;
	char a[5],b[10];
	if(x==1)
		strcpy(a,"�ͺ�");
	else if(x==2)
		strcpy(a,"����");
	else if(x==3)
		strcpy(a,"����");
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ��ѯ������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          ��[%s]��ѯ����\n\n",a);
	printf("\t\t\t������%s���Բ�ѯ��Ӧ������",a);
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
		printf("\n%sΪ[%s]�ĳ�������%d������Ϣ���£�\n\n",a,b,j);
		printf("��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
	}
	else
		printf("\n\n\t\t\t                         ��%sΪ[%s]�ĳ���\n\n",a,b);
	if(x==1)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->xh,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	else if(x==2)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->cs,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	else if(x==3)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->cx,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
}
//��ѯ������Ϣ��1
void Chaxun2(struct car *p,int n)
{
	int i,j;
	float a,b;
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ��ѯ������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                        ��[�۸�Χ]��ѯ����\n\n");
	printf("\t\t\t��ֱ�������ͼ۸�����߼۸�(��λ:��)���Բ�ѯ��Ӧ������");
	scanf("%f%f",&a,&b);
	if(a>b)
	{
		printf("\n\t\t\t                  �۸�Χ���������3����������룡\n");
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
		printf("\n�۸�ΧΪ%.2f��~%.2f��ĳ�������%d������Ϣ���£�\n\n",a,b,j);
		printf("��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
		for(i=0;i<n;i++)
			if(((p+i)->jg>=a)&&((p+i)->jg<=b))
				printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	else
		printf("\n\n\t\t\t                  �޼۸�ΧΪ%.2f��~%.2f��ĳ���\n\n",a,b);
	break;
	}while(1);

}
//��ѯ������Ϣ��2
void Modify(struct car *p,int n)
{
	int i,j=0,x;
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            �޸ĳ�����Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
	for(i=0;i<n;i++)
		printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("\n");
	printf("\t\t\t���г�����Ϣ���ϣ�������Ҫ�޸ĳ����ļ�¼�ţ�");
	do{
		scanf("%d",&x);
		for(i=0;i<n;i++)
		{
			if((p+i)->jlh==x)
			{
				j++;
				printf("\n\n��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
				printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
				break;
			}
		}
		if(j==0)
		{
			printf("\t\t\t�޴˼�¼�ţ�������������ȷ��¼�ţ�");
			continue;
		}
		break;
	}while(1);
	j=x;
	printf("\n\t\t\t                         ��ѡ��Ҫ�޸ĵĲ���\n\t\t\t                           --------------\n");
	printf("\t\t\t                             1.�����ͺ�\n\t\t\t                           --------------\n");
	printf("\t\t\t                             2.����\n\t\t\t                           --------------\n");
	printf("\t\t\t                             3.���ͼ���\n\t\t\t                           --------------\n");
	printf("\t\t\t                             4.��λ��\n\t\t\t                           --------------\n");
	printf("\t\t\t                             5.����\n\t\t\t                           --------------\n");
	printf("\t\t\t                             6.������\n\t\t\t                           --------------\n");
	printf("\t\t\t                             7.������ɫ\n\t\t\t                           --------------\n");
	printf("\t\t\t                             8.�����۸�\n\t\t\t                           --------------\n");
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
		default:printf("\t\t\t                          ��������ȷѡ��");
		}
		if(x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8)
		{
			printf("\n\t\t\t                          ������Ϣ�޸ĳɹ���\n");
			system("pause");
			break;
		}
	}while(1);
}
//�޸ĳ�����Ϣ
void Xiugai(struct car *p,int n,int x,int j)
{
	FILE *fp;
	int i=j-1,k;
	float f;
	char a[10];
	switch(x)
	{
	case 1:
		printf("\t\t\t�������µĳ����ͺţ�");
		scanf("%s",a);
		strcpy((p+i)->xh,a);
		break;
	case 2:
		printf("\t\t\t�������µĳ��̣�");
		scanf("%s",a);
		strcpy((p+i)->cs,a);
		break;
	case 3:
		printf("\t\t\t�������µĳ��ͼ���");
		scanf("%s",a);
		strcpy((p+i)->cx,a);
		break;
	case 4:
		printf("\t\t\t�������µ���λ����");
		scanf("%d",&k);
		((p+i)->zws)=k;
		break;
	case 5:
		printf("\t\t\t�������µ�������");
		scanf("%f",&f);
		((p+i)->pl)=f;
		break;
	case 6:
		printf("\t\t\t�������µı����䣺");
		scanf("%s",a);
		strcpy((p+i)->bsx,a);
		break;
	case 7:
		printf("\t\t\t�������µ���ɫ��");
		scanf("%s",a);
		strcpy((p+i)->ys,a);
		break;
	case 8:
		printf("\t\t\t�������µļ۸�");
		scanf("%f",&f);
		((p+i)->jg)=f;
	}
	if((fp=fopen("������Ϣ.txt","wb"))==NULL)
	{
		printf("�޷����ļ�\n");
		exit(0);
	}
	if(fwrite(che,sizeof(struct car),n,fp)!=n)
		printf("�޸�ʧ��\n");
	else
	{
		printf("\n��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
		printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	fclose(fp);
}
//�޸ĳ�����Ϣ��
void Delet(struct car *p,int n)
{
	int x;
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ɾ��������Ϣ\n");
	printf("\t\t\t                       ----------------------\n");
	printf("\t\t\t                        1.��[�ͺ�]���ң���ɾ��\n");
	printf("\t\t\t                       ----------------------\n");
	printf("\t\t\t                        2.��[����]���ң���ɾ��\n");
	printf("\t\t\t                       ----------------------\n");
	printf("\t\t\t                        3.�鿴ȫ������ɾ��\n");
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
//ɾ��������Ϣ
void Shanchu1(struct car *p,int n,int x)
{
	FILE *fp;
	int i,j,k,t,c[50];
	char a[5],b[10];
	if(x==1)
		strcpy(a,"�ͺ�");
	else
		strcpy(a,"����");
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ɾ��������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                            ��[%s]����\n\n",a);
	printf("\t\t\t������%s���Բ�����Ӧ������",a);
	scanf("%s",b);
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ɾ��������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                            ��[%s]����\n\n",a);
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
		printf("\n%sΪ[%s]�ĳ�������%d������Ϣ���£�\n\n",a,b,j);
		printf("��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
	}
	else
	{
		printf("\n\t\t\t                         ��%sΪ[%s]�ĳ���\n\n\n",a,b);
		system("pause");
		break;
	}
	if(x==1)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->xh,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	else if(x==2)
	{
		for(i=0;i<n;i++)
			if(strcmp((p+i)->cs,b)==0)
				printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	}
	printf("\n\t\t\t                         ��ѡ��Ҫ���еĲ���\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             1.����ɾ��\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             2.ȫ��ɾ��\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             3.ȡ��\n");
	printf("\t\t\t                           --------------\n");
	scanf("%d",&k);
	if(k==1)
	{
		printf("\t\t\t������Ҫɾ�������ļ�¼�ţ�");
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
						printf("\n��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
						printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
						break;
					}
				}
			}
			if(!k)
			{
				printf("\t\t\t��%sΪ[%s]�Ҽ�¼��Ϊ%d�ĳ�����������������ȷ��¼�ţ�",a,b,x);
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
		if((fp=fopen("������Ϣ.txt","wb"))==NULL)
		{
			printf("�޷����ļ�\n");
			exit(0);
		}
		if(fwrite(che,sizeof(struct car),n-1,fp)!=n-1)
			printf("ɾ��ʧ��\n");
		else
			printf("\n\t\t\t                          ������Ϣɾ���ɹ���\n\t\t\t                     ����¼���Ѱ�˳�����¸�ֵ��\n");
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
		if((fp=fopen("������Ϣ.txt","wb"))==NULL)
		{
			printf("�޷����ļ�\n");
			exit(0);
		}
		if(fwrite(che,sizeof(struct car),n-j,fp)!=n-j)
			printf("ɾ��ʧ��\n");
		else
			printf("\t\t\t                  %sΪ[%s]�ĳ���ȫ��ɾ���ɹ���\n\t\t\t                     ����¼���Ѱ�˳�����¸�ֵ��\n",a,b);
		fclose(fp);
		system("pause");
		break;
	}
	else if(k==3)
		break;
	}while(1);
}
//ɾ��������Ϣ��1
void Shanchu2(struct car *p,int n)
{
	FILE *fp;
	int i,x;
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ɾ��������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                              �鿴ȫ��\n\n");
	printf("��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
	for(i=0;i<n;i++)
		printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("\n\t\t\t                          ȫ��������Ϣ����\n");
	printf("\t\t\t                         ��ѡ��Ҫ���еĲ���\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             1.����ɾ��\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             2.ȫ��ɾ��\n");
	printf("\t\t\t                           --------------\n");
	printf("\t\t\t                             3.ȡ��\n");
	printf("\t\t\t                           --------------\n");
	scanf("%d",&x);
	if(x==1)
	{
		printf("\t\t\t������Ҫɾ�������ļ�¼�ţ�");
		do{
			scanf("%d",&x);
			for(i=0;i<n;i++)
			{
				if((p+i)->jlh==x)
				{
					printf("\n\n��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
					printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
					break;
				}
			}
			if(x<1||x>n)
			{
				printf("\t\t\t�޴˼�¼�ţ�������������ȷ��¼�ţ�");
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
		if((fp=fopen("������Ϣ.txt","wb"))==NULL)
		{
			printf("�޷����ļ�\n");
			exit(0);
		}
		if(fwrite(che,sizeof(struct car),n-1,fp)!=n-1)
			printf("ɾ��ʧ��\n");
		else
			printf("\n\t\t\t                          ������Ϣɾ���ɹ���\n\t\t\t                     ����¼���Ѱ�˳�����¸�ֵ��\n");
		fclose(fp);
		system("pause");
		break;
	}
	else if(x==2)
	{
		if((fp=fopen("������Ϣ.txt","wb"))==NULL)
		{
			printf("ɾ��ʧ��\n");
			exit(0);
		}
		printf("\t\t\t                           ȫ��ɾ���ɹ���\n");
		system("pause");
		break;
	}
	else if(x==3)
		break;
	}while(1);
}
//ɾ��������Ϣ��2
void Sort(struct car *p,int n)
{
	int x;
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ��������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          1.��[�۸�]����\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          2.��[����]����\n");
	printf("\t\t\t                         ------------------\n");
	printf("\t\t\t                          3.��[��λ��]����\n");
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
//��������Ϣ
void Paixu(struct car *p,int n,int x)
{
	FILE *fp;
	struct car t;
	int i,j,k;
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                            ��������Ϣ\n");
	printf("\t\t\t                         ------------------\n");
	switch(x)
	{
	case 1:
		printf("\t\t\t                          ��[�۸�]������\n\n");
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
		printf("\t\t\t                          ��[����]������\n\n");
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
		printf("\t\t\t                         ��[��λ��]������\n\n");
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
	printf("��¼��    �����ͺ�     ����        ���ͼ���    ��λ��    ����    ������     ������ɫ    �����۸�\n\n");
	for(i=0;i<n;i++)
		printf("  %-8d%-13s%-12s%-12s%d��       %-0.1fT    %-11s%-12s%-0.2f��\n",(p+i)->jlh,(p+i)->xh,(p+i)->cs,(p+i)->cx,(p+i)->zws,(p+i)->pl,(p+i)->bsx,(p+i)->ys,(p+i)->jg);
	printf("\n\n\t\t\t              ������ɣ��������Ϣ���ϣ��Ƿ�ȷ�����棿\n");
	printf("\t\t\t                     ����¼���Ѱ�˳�����¸�ֵ��\n\n");
	printf("\t\t\t                          1.ȷ��   2.ȡ��\n");
	scanf("%d",&k);
	if(k==1)
	{
		if((fp=fopen("������Ϣ.txt","wb"))==NULL)
		{
			printf("�޷����ļ�\n");
			exit(0);
		}
		if(fwrite(che,sizeof(struct car),n,fp)!=n)
			printf("�ļ�д��ʧ��\n");
		fclose(fp);
		printf("\t\t\t                             ����ɹ���\n");
		system("pause");
		break;
	}
	else if(k==2)
		break;
	}while(1);
}
//��������Ϣ��
void Initialize()
{
	FILE *old,*neww;
	int i;
	do{
	system("cls");
	printf("\t\t\t                         *������Ϣ����ϵͳ*\n");
	printf("\t\t\t====================================================================\n\n");
	printf("\t\t\t                             ��ʼ��ϵͳ\n");
	printf("\t\t\t                         ------------------\n\n");
	printf("\t\t\t           �Ƿ�ȷ����ʼ��ϵͳ����������Ϣ��ԭ�������Ϣ��\n\n");
	printf("\t\t\t                          1.ȷ��   2.ȡ��\n");
	scanf("%d",&i);
	if(i==1)
	{
		if((old=fopen("������Ϣ.txt","wb"))==NULL)
		{
			printf("�޷����ļ�\n");
			exit(0);
		}
		if((neww=fopen("��ʼ����Ϣ.txt","rb"))==NULL)
		{
			printf("�޷����ļ�\n");
			exit(0);
		}
		if(fread(che,sizeof(struct car),10,neww)!=10)
			printf("��ʼ����Ϣ�������\n");
		if(fwrite(che,sizeof(struct car),10,old)!=10)
			printf("��ʼ����Ϣд�����\n");
		fclose(old);
		fclose(neww);
		printf("\t\t\t                          ϵͳ��ʼ���ɹ���\n");
		system("pause");
		break;
	}
	else if(i==2)
		break;
	}while(1);
}
//��ʼ��ϵͳ