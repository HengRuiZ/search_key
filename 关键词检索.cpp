#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"iostream"
using namespace std;
FILE*fp;
int search(int l,char* s1,char* s2)
{
	if(strlen(s1)<strlen(s2))
	return 0;
	int i,j,k[20],m;
	int next[100];
	j=0;i=-1;next[0]=-1;
	while(j<=strlen(s2)-1)
		if(i==-1||s2[j]==s2[i])
		{
			j++;i++;
			if(s2[j]!=s2[i])next[j]=i;
			else next[j]=next[i];
		}
		else i=next[i];
	i=j=m=0;
	while(i<strlen(s1))
	{
		if(j==-1||s1[i]==s2[j]){i++,j++;}
		else j=next[j];
		if(j==strlen(s2)){k[0];k[m++]=i-j;j=0;}
	}
	if(m)
	{
		printf("第%d行：",l);
		for(j=0;j<m;j++)
			printf("第%d位",k[j]+1);
		printf("\n");
	}
	return m;
}
main()
{
	int i,j=0;
	char s1[200],s2[200];
	cout<<"请输入文件名"<<endl;
	cin>>s1;
	if((fp=fopen(s1,"r+"))==NULL)
	{
		cout<<"打开文件失败！"<<endl;
		return 0;
	}
	while(1){
	cout<<"请输入关键词"<<endl;
	cin>>s2;
	fseek(fp,0,0);
	for(i=1;!feof(fp);i++)
	{
		j=0;
		s1[0]=fgetc(fp);
		while(s1[j]!='\n'&&!feof(fp)) 
		{j++;s1[j]=fgetc(fp);}
		s1[j]='\0';
		search(i,s1,s2);
	}
	}
	fclose(fp);
}
