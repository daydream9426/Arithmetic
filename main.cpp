#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include "operation.h"
#include "fraction.h"
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	srand(static_cast<unsigned> (time(NULL)));
	int prompt;
	cout<<"请选择提示语言，输入1为中文，输入2为英文。"<<endl;
	cout<<"Please select the prompt language，click “1”means you need Chinese prompt language,whlie “2”means english."<<endl;
	cin>>prompt;
	int n;

	if(prompt==1)
	{
		cout<<"输入题目数量:";
		cin >> n;
		cout<<"你可以随时按e终止答题，当前题目不计入成绩"<<endl;
	}
	else if(prompt==2)
	{
		cout<<"Enter the number of topics:"<<endl;
		cin >> n;
		cout<<"You can press e to stop answering at any time,while the question you are answering will no judged."<<endl;
	}
	else {cout << "Error: The input is wrong"<<endl; return 1;}
	int corrnum=0;
	int wrongnum=0;

	int num=0;
	int len;
	int x;
	int i;
	int j;
	char ans[100];
	int intans[100];
	int judge=0;
	int wrongquenum[100];
	Operation *a[1000];
	for(i=0;i<1000;i++)
	{
		a[i]=NULL;
	}
	for(x=0;x<n;x++)
	{
		a[x]=new Operation();
		cout<<x+1<<". ";
		(a[x])->print();
		cout<<" = ";
		cin>>ans;
		len=strlen(ans);
		judge = 0;
		for(i=0;i<len;i++)
		{
			if(ans[i]=='e')
			{
				judge=1;//judge=1 means it contains 'e'
			}
			if(judge==1)
			break;
		}
		if(judge==1)
			break; 
		num=0;
		judge=0;
		if (ans[0]=='-') judge=1;
		for(i=0;i<len;i++)
			{ 
				if ((judge==1)&&(i==0)) continue;
				num+=(static_cast<int>(pow(10,len-i-1)*(ans[i]-48)));
			}
		if (judge==1) intans[x]=0-num;
		else intans[x]=num;
		Fraction *p;
		p=new Fraction(intans[x],1); 
		if((a[x]->getans())==*p)
		{
			corrnum++;
		}
		else
		{
			wrongquenum[wrongnum]=x;
			wrongnum++;
		}
		delete p;
	}

	cout << "-----------------------------------"<<endl;

	if (prompt == 1)
	{
		cout << "总计:" << n << setw(12) << "正确题数:" << corrnum << setw(12) << "错误题数:" << wrongnum << endl;
	}
	else if (prompt == 2)
	{
		cout << "Total:" << n << setw(12)<< "True:" << corrnum <<setw(12)<< "False:" << wrongnum << endl;
	}

	cout << "-----------------------------------" << endl;

	if(wrongnum>0)
	{
		if(prompt==1)
		cout<<"错误详情："<<endl;
		else if(prompt==2)
		cout<<"Mistake："<<endl;
		for(i=0;i<wrongnum;i++)
		{
			j=wrongquenum[i];
			cout << endl;
			if(prompt==1)
			{
				cout<<j+1<<". ";
				(a[j])->print();
				cout<<" = ";
				((a[j])->getans()).print();
				cout<<endl;
				cout<<"  你的答案:"<<intans[j]<<endl;
			}
			else if(prompt==2)
			{
				cout<<j+1<<". ";
				(a[j])->print();
				cout<<" = ";
				((a[j])->getans()).print();
				cout<<endl;
				cout<<"  Your answer is "<<intans[j]<<endl;
			}
		}
	}

	for (i = 0; i<1000; i++)
	{
		delete(a[i]);
	}
}
