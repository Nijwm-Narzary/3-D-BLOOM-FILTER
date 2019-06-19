#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"3dnewfilter.h"


int main()
{
	
	
	
	// Seperate the file base
	//read();
	
	
	
	FILE *fp=fopen("asha.txt","r");
	FILE *ft=fopen("nijwm.txt","r");
	char buff[1024];
	long int i=0,scount=0,str=0;
	int k,j,flag=0;// flag used to confirm that all tests cases are passed
	unsigned long int ***a1=allocate();  
	unsigned long int ***a2=allocate();  
	unsigned long int ***a3=allocate();  
	unsigned long int ***a4=allocate();  
	unsigned long int ***a5=allocate();  
	unsigned long int ***a6=allocate();  
	unsigned long int ***a7=allocate();  
	unsigned long int ***a8=allocate();  
	//unsigned long int ***aR=allocate();
	char ch,buff1[512],buff2[512],buff3[512],buff4[512],buff5[512],buff6[512],buff7[512],buff8[512];
	
	FILE *f=fopen("Found1.txt","w");//to write the all matched strings 
	int count=0;
	clock_t start, end;
	//printf("here");
	if(fp == NULL)
   	{
      		printf("Error!");   
      		exit(1);             
   	}

	while((ch = fgetc(fp)) != EOF)		//scanning character by character from input file
	{
	    i=0;
		while(ch!='\n')
		{
			buff1[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		if(ch=='\n')
		{
			
			buff1[i]='\0';
			
			//for buffer 2
			for(j=0;j<i;j++) 
			{
				buff2[j]=buff1[j];
			}
			buff2[j++]=1;buff2[j]='\0';
			
			
			//for buffer 3
			for(i=0;i<j;i++){
			    buff3[i]=buff2[i];
			}
			buff3[i++]=1;buff3[i]='\0';
			
			//for buffer 4
			for(j=0;j<i;j++) 
			{
				buff4[j]=buff3[j];
			}
			buff4[j++]=1;buff4[j]='\0';
			
			
			//for buffer 5
			for(i=0;i<j;i++){
			    buff5[i]=buff4[i];
			}
			buff5[i++]=1;buff5[i]='\0';
			
			//for buffer 6
			for(j=0;j<i;j++) 
			{
				buff6[j]=buff5[j];
			}
			buff6[j++]=1;buff6[j]='\0';
			
			
			//for buffer 7
			for(i=0;i<j;i++){
			    buff7[i]=buff6[i];
			}
			buff7[i++]=1;buff7[i]='\0';
			
			
			//for buffer 6
			for(j=0;j<i;j++) 
			{
				buff8[j]=buff7[j];
			}
			buff8[j++]=1;buff8[j]='\0';
			
			str++;
		}
	
		setMember(a1,buff1);
		setMember(a2,buff2);
		setMember(a3,buff3);
		setMember(a4,buff4);
		setMember(a5,buff5);
		setMember(a6,buff6);
		setMember(a7,buff7);
		setMember(a8,buff8);
	}
	
	while((ch = fgetc(ft)) != EOF)		//scanning character by character from input file
	{
	    flag=0;
	    i=0;
	/*	while(ch!='\n')
		{
			buff1[i]=ch;
			i++;
			ch=fgetc(ft);
		}*/
		int x=i+1;
		if(ch=='\n')
		{
			
			buff1[i]='\0';
			
			//for buffer 2
			for(j=0;j<i;j++) 
			{
				buff2[j]=buff1[j];
			}
			buff2[j++]=1;buff2[j]='\0';
			
			
			//for buffer 3
			for(i=0;i<j;i++){
			    buff3[i]=buff2[i];
			}
			buff3[i++]=1;buff3[i]='\0';
			
			//for buffer 4
			for(j=0;j<i;j++) 
			{
				buff4[j]=buff3[j];
			}
			buff4[j++]=1;buff4[j]='\0';
			
			
			//for buffer 5
			for(i=0;i<j;i++){
			    buff5[i]=buff4[i];
			}
			buff5[i++]=1;buff5[i]='\0';
			
			//for buffer 6
			for(j=0;j<i;j++) 
			{
				buff6[j]=buff5[j];
			}
			buff6[j++]=1;buff6[j]='\0';
			
			
			//for buffer 7
			for(i=0;i<j;i++){
			    buff7[i]=buff6[i];
			}
			buff7[i++]=1;buff7[i]='\0';
			
			
			//for buffer 6
			for(j=0;j<i;j++) 
			{
				buff8[j]=buff7[j];
			}
			buff8[j++]=1;buff8[j]='\0';
		}
		
			
		if(testMember(a1,buff1)==1)			
			if(testMember(a2,buff2)==1)
			    if(testMember(a3,buff3)==1)
			         if(testMember(a4,buff4)==1)
			              if(testMember(a5,buff5)==1)
			                  if(testMember(a6,buff6)==1)
			                       if(testMember(a7,buff7)==1)
			                           if(testMember(a8,buff8)==1)
			                             {
			                                 //All the test is overcomed
			                                   
			                                  flag=1;
			                                  count++;
			                                 
			                               }
		
		if(flag){
		 fputc('\n',f);	
		    fputs(buff1,f);
		   	    
		 } 	                            
		//printf("%c ",buff1);	                             
    }
	printf("Number of match found: %d\n",count);

	return 0;
}
