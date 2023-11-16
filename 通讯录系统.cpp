#include<iostream>
#include<string>
#define MAX 1000  //�궨�� 
using namespace std;


void showMenu()
{
	cout<<"*************************"<<endl;
	cout<<"***** 1. �����ϵ�� *****"<<endl;
	cout<<"***** 2. ��ʾ��ϵ�� *****"<<endl;
	cout<<"***** 3. ɾ����ϵ�� *****"<<endl;
	cout<<"***** 4. ������ϵ�� *****"<<endl;
	cout<<"***** 5. �޸���ϵ�� *****"<<endl;
	cout<<"***** 6. �����ϵ�� *****"<<endl;
	cout<<"***** 0. �˳�ͨѶ¼ *****"<<endl;
	cout<<"*************************"<<endl;
	cout<<"�������Ӧ��ָ�";
}
struct r
{
	string Name;
	string Xy;
	int Age;
	string Num;
	string Home;
	}x;
struct addressbooks
{
	struct r personArray[MAX];
	int size; 
};
void addPerson(addressbooks * abs)  //ָ����յ�ַ 
{
	if(abs->size==MAX)
	{
	cout<<"ͨѶ¼�������޷����"<<endl;
	return;
}
	else 
	cout<<"������������"<<endl;
	string name;
	cin>>name; 
	abs->personArray[abs->size].Name=name; 
	cout<<"�������Ա�"<<endl;
	while(true)
	{
	string xy;
	cin>>xy;
	if(xy=="��"||xy=="Ů")
	{
	abs->personArray[abs->size].Xy=xy; 
	break;
}
	else
	cout<<"����������������룺"<<endl;
}
	cout<<"���������䣺"<<endl;
	while(true)
	{
	int age;
	cin>>age;
	if(age>0)
	{
	abs->personArray[abs->size].Age=age; 
	break;
}
	else
	cout<<"����������������룺"<<endl;
}
	cout<<"��������ϵ�绰��"<<endl;
	while(true)
	{
	string num;
	cin>>num;
	if(num.length()==11)
	{
	abs->personArray[abs->size].Num=num;
	break; 
}
	else
	cout<<"��ʽ��������������"<<endl;
}
	cout<<"�������ͥסַ��"<<endl;
	string home;
	cin>>home; 
	abs->personArray[abs->size].Home=home; 
	abs->size++;
	cout<<"��ӳɹ���"<<endl;
	system("pause");
	system("cls");
}
void showPerson(addressbooks * abs)
{
	if(abs->size==0)
	cout<<"��ǰ��¼Ϊ��"<<endl;
	else
	{
	for(int i=0;i<abs->size;i++)
	{
	cout<<"������"<<abs->personArray[i].Name<<'\t'
	<<"�Ա�"<<abs->personArray[i].Xy<<'\t'
	<<"���䣺"<<abs->personArray[i].Age<<'\t'
	<<"�绰��"<<abs->personArray[i].Num<<'\t'
	<<"סַ��"<<abs->personArray[i].Home<<'\t'<<endl;
	}
}
	system("pause");
	system("cls");
}
int isExist(addressbooks * abs,string name)
{
	for(int i=0;i<abs->size;i++)
	{
	if(abs->personArray[i].Name==name)
	{
		return i;
	} 
	}
	return -1;
}
void deletePerson(addressbooks * abs)
{
	cout<<"��������Ҫɾ������ϵ��"<<endl;
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
	for(int i=ret;i<abs->size;i++)
	{
	abs->personArray[i]=abs->personArray[i+1];
	} 
	abs->size--;
	cout<<"ɾ���ɹ���"<<endl;
	}
	else
	cout<<"���޴���"<<endl;
	system("pause");
	system("cls"); 
} 
void findPerson(addressbooks * abs)
{
	cout<<"����������Ҫ���ҵ���ϵ�ˣ�";
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
	cout<<"������"<<abs->personArray[ret].Name<<'\t'
	<<"�Ա�"<<abs->personArray[ret].Xy<<'\t'
	<<"���䣺"<<abs->personArray[ret].Age<<'\t'
	<<"�绰��"<<abs->personArray[ret].Num<<'\t'
	<<"סַ��"<<abs->personArray[ret].Home<<'\t'<<endl;
}
	else
	cout<<"���޴���"<<endl;
	system("pause");
	system("cls"); 
}
void modifyPerson(addressbooks * abs)
{
	cout<<"��������Ҫ�޸ĵ���ϵ��:";
	string name;
	cin>>name;
	int ret=isExist(abs,name);
	if(ret!=-1)
	{
	cout<<"������������"<<endl;
	string name;
	cin>>name; 
	abs->personArray[ret].Name=name; 
	cout<<"�������Ա�"<<endl;
	while(true)
	{
	string xy;
	cin>>xy;
	if(xy=="��"||xy=="Ů")
	{
	abs->personArray[ret].Xy=xy; 
	break;
}
	else
	cout<<"����������������룺"<<endl;
}
	cout<<"���������䣺"<<endl;
	while(true)
	{
	int age;
	cin>>age;
	if(age>0)
	{
	abs->personArray[ret].Age=age; 
	break;
}
	else
	cout<<"����������������룺"<<endl;
}
	cout<<"��������ϵ�绰��"<<endl;
	while(true)
	{
	string num;
	cin>>num;
	if(num.length()==11)
	{
	abs->personArray[ret].Num=num;
	break; 
}
	else
	cout<<"��ʽ��������������"<<endl;
}
	cout<<"�������ͥסַ��"<<endl;
	string home;
	cin>>home; 
	abs->personArray[ret].Home=home; 
	abs->size++;
	cout<<"�޸ĳɹ���"<<endl;
	system("pause");
	system("cls");
}
	else
	cout<<"���޴���"<<endl;
}
void clearPerson(addressbooks * abs)
{
	abs->size=0;  //�߼���գ�����ϵ����������Ϊ0 
	cout<<"ͨѶ¼�����"<<endl;
	system("pause");
	system("cls");
} 
int main()
{
	addressbooks abs;
	abs.size=0;
	while(true)
	{
	showMenu(); 
	int num;
	cin>>num; 
	switch(num)
	{
	case 0:cout<<"��ӭ�´�ʹ�ã�"<<endl;
	return 0;
	break;
	case 1:addPerson(&abs);
	break;
	case 2:showPerson(&abs);
	break;
	case 3:deletePerson(&abs);
	break;
	case 4:findPerson(&abs);
	break;
	case 5:modifyPerson(&abs); 
	break;
	case 6:clearPerson(&abs); 
	break;
	}
}
	return 0;
}
