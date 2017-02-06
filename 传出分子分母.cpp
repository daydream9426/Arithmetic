#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	struct uans
	{
		int numerator;//·Ö×Ó 
		int denominator;//·ÖÄ¸ 
	}uans[100];
	int num=0;
	int n=3;
	int x;
	int i;
	int j;
	int k; 
	int l;
	int len;
	char ans[20];
	int judge=0;
	for(x=0;x<n;x++)
	{
		
		//create a question
		cin>>ans;
		len=strlen(ans);
		for(i=0;i<len;i++)
		{
			
			if(ans[i]=='e')
			{
				judge=1;
			}
			if(judge==1)
			break;
		}
		if(judge==1)
		break; 
		for(i=0;i<len;i++)
		{
			if(ans[i]=='.')
			{
				num=0;
				j=i+1;
				for(j=i+1;ans[j]==0;++j)
				k=j;
				uans[x].denominator=pow(10,len-2);
				for(j;j<len;j++)
				{
					num=num*10+(ans[j]-48);
				}
				uans[x].numerator=num;
				judge=1;
			}
		}
		for(i=0;i<len;i++)
		{
			if(ans[i]=='/')
			{
				num=0;
				for(j=0;j<i;j++)
				{
					num+=pow(10,i-j-1)*(ans[j]-48);
				}
				uans[x].numerator=num;
				num=0;
				l=i+1;
				for(l;l<len;l++)
				{
					num+=pow(10,len-l-1)*(ans[l]-48);
				}
				uans[x].denominator=num;
				num=0;
				judge=2; 
			}
		}
		if(judge==0)
		{
			{
				num=0;
				uans[x].denominator=1;
				for(i=0;i<len;i++)
				{
					num+=pow(10,len-i-1)*(ans[i]-48);
				}
				uans[x].numerator=num;
			}
			for(i=0;i<len;i++)
			{
				ans[i]='\0';
			}
		
		}
		cout<<uans[x].numerator<<endl;
		cout<<uans[x].denominator<<endl;
	}	
	return 0;
 } 
