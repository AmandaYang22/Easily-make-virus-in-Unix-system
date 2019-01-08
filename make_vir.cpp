#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fstream>
#include <string>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;
void function(int);
char *const arg[50]={0};
int main(int argc,const char* argv[])
{
	sigset_t intmask1,intmask2;
	signal(SIGINT,function);
	sigemptyset(&intmask1);//初始化信号集
	sigaddset(&intmask1,SIGINT);//添加SIGINT信号到信号集

	sigprocmask(SIG_SETMASK,&intmask2,NULL);//将当前信号集设为信号阻塞集合
	sigprocmask(SIG_UNBLOCK,&intmask1,&intmask2);

	
	while(1)
	{
		cout<<"loop "<<endl;
		pause();
	}
	return 0;	
}
void function(int)
{
	FILE *fp1,*fp2,*fp3;
	string temp,s,name="",nameo,symbol1=" ",symbol2="./",command1,command2;
	char convername[20],convercommand1[60],convercommand2[40];
	
	char str[53]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	pid_t pid,ppid,childpid;
	int count=0;
		
	
	srand((unsigned)time(NULL));//get file name
	for(int i=0;i<5;i++){
		temp=str[rand()%(strlen(str))];
		s=s+temp;
	}
	name=s+".cpp";
	cout<<"processer name: "<<name<<endl;
	nameo=s+".o";//name+".o"
	cout<<"nameo: "<<nameo<<endl;
	strcpy(convername,name.c_str());
	
	fp1=fopen(convername,"w");
	const char *p="#include <iostream>%c#include <stdio.h>%c#include <stdlib.h>%c#include <signal.h>%c#include <fstream>%c#include <string>%c#include <string.h>%c#include <time.h>%c#include <unistd.h>%cusing namespace std;%cvoid function(int);%cconst char *const arg[50]={0};%cint main(int argc,const char* argv[])%c{%csigset_t intmask1,intmask2;%csignal(SIGINT,function);%csigemptyset(&intmask1);%csigaddset(&intmask1,SIGINT);%csigprocmask(SIG_SETMASK,&intmask2,NULL);%csigprocmask(SIG_UNBLOCK,&intmask1,&intmask2);%cwhile(1)%c{%ccout<<%cloop %c<<endl;%cpause();}%creturn 0;%c}%cvoid function(int)%c{%cFILE *fp1,*fp2,*fp3;%cstring temp,s,name=%c%c,nameo,symbol1=%c %c,%csymbol2=%c./%c,command1,command2;%cchar convername[20],convercommand1[60],convercommand2[40];%cchar str[53]=%cABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz%c;%cpid_t pid,ppid,childpid;%cint count=0;%csrand((unsigned)time(NULL));%cfor(int i=0;i<5;i++)%c{%c	temp=str[rand()%(strlen(str))];%c	s=s+temp;%c}%cname=s+%c.cpp%c;%ccout<<%cprocesser name: %c<<name<<endl;%cnameo=s+%c.o%c;%cstrcpy(convername,name.c_str());%cfp1=fopen(convername,%cw%c);%cconst char *p=%c%s%c;%cfprintf(fp1,p,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,34,34,10,10,10,10,10,10,10,34,34,34,34,10,34,34,10,10,34,34,10,10,10,10,10,10,10,10,10,34,34,10,34,34,10,34,34,10,10,34,34,10,34,p,34,10,10,34,34,34,34,10,10,10,10,10,10,10,10,34,34,10,34,34,10,10,10,34,34,10,10,10,34,34,34,34,10,34,34,10,34,34,10,10,34,34,34,34,10,10,34,34,10,10,34,34,10,10,34,34,34,34,10,10,10,34,34,34,34,10,10,34,34,10,10,10,10,10,34,34,10,10);%ccommand1=%cg++%c+symbol1+name+symbol1+%c-o%c+symbol1+nameo;%ccommand2=nameo;%cstrcpy(convercommand1,command1.c_str());%cstrcpy(convercommand2,command2.c_str());%cfclose(fp1);%csystem(convercommand1);%cpid=getpid();%cppid=getppid();%ccout<<%cpid:%c<<pid<<endl;%ccout<<%cppid:%c<<ppid<<endl;%cchildpid=fork();%cif(childpid<0)%ccout<<%cfork error%c<<endl;%celse if(childpid==0)%c{%c	fp2=fopen(%cin.txt%c,%cr%c);%c	fscanf(fp2,%c%%d%c,&count);%c	cout<<%cread count from file%c<<count<<endl;%c fclose(fp2);%c fp2=fopen(%cin.txt%c,%cw%c);%c count=count-1;%c	fprintf(fp2,%c%%d%c,count);%c	fclose(fp2);%c  cout<<%cmodefiy count%c<<count<<endl;%c	if(count>0)%c		execlp(%c/home/summer/new%c,%c./%c,convercommand2,NULL);%c	else%c		exit(0);%c	/*fp3=fopen(%cin.txt%c,%cw%c);%c	count=count-1;%c	fprintf(fp3,%c%%d%c,count);%c	fclose(fp3);*/%c}%c else%c{%c	cout<<%cparent proccessor%c<<endl;%c	exit(0);}%c}";
	
	fprintf(fp1,p,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,34,34,10,10,10,10,10,10,10,34,34,34,34,10,34,34,10,10,34,34,10,10,10,10,10,10,10,10,10,34,34,10,34,34,10,34,34,10,10,34,34,10,34,p,34,10,10,34,34,34,34,10,10,10,10,10,10,10,10,34,34,10,34,34,10,10,10,34,34,10,10,10,34,34,34,34,10,34,34,10,34,34,10,10,34,34,34,34,10,10,34,34,10,10,34,34,10,10,34,34,34,34,10,10,10,34,34,34,34,10,10,34,34,10,10,10,10,10,34,34,10,10);
	command1="g++"+symbol1+name+symbol1+"-o"+symbol1+nameo;
	command2=nameo;
	strcpy(convercommand1,command1.c_str());
	strcpy(convercommand2,nameo.c_str());
	cout<<convercommand2<<endl;
	fclose(fp1);
	system(convercommand1);//produce .o file 
	
	pid=getpid();
	ppid=getppid();
	cout<<"pid:"<<pid<<endl;
	cout<<"ppid:"<<ppid<<endl;

	childpid=fork();
	
	if(childpid<0)
		cout<<"fork error"<<endl;
	else if(childpid==0)//子进程
	{
		fp2=fopen("in.txt","r"); //read number from file
		fscanf(fp2,"%d",&count);
		cout<<"count"<<count<<endl;
		fclose(fp2);
		fp2=fopen("in.txt","w");
		count=count-1;
		fprintf(fp2,"%d",count);
		fclose(fp2);
		cout<<"modefiy count"<<count<<endl;	

		if(count>=0){
			execlp("/home/summer/new","./",convercommand2,NULL);
			cout<<"execv"<<endl;}
		else
			exit(0);

		/*fp3=fopen("in.txt","w");//modefiy number into file
		cout<<"count:"<<count<<endl;
		count=count-1;
		fprintf(fp3,"%d",count);
		cout<<"modefiy count"<<count<<endl;
		fclose(fp3);	*/
	}
	else //父进程
	{
		cout<<"parent proccessor"<<endl;
		exit(0);
	}
}






