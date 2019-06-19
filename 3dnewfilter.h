#include<stdio.h>
#include<stdlib.h>
#include"murmur.h"

int seed=98899;
//int seed1=10007; 
//int x=103,y=107,z=109; //diemnsion of the 2D filter.
//int x=9973,y=10007;//,z=137;  //dimension of the 2D filter. A prime number is a candidate for good hashing.
//int x=5647,y=6151;

int x=113,y=107,z=109;
//int x=61,y=67,z=71;
//int x=11,y=11,z=17;
//
//int x=3, y=7, z=11;//Wrong Answer 664
//int x=5, y=9, z=13;//Rt Answer
//int x=5, y = 7, z=13;//RT ans
//int x=3, y=3, z=13;//501
//int x=3,y=3,z=3;//3612
//int x=3,y=3,z=5;//2838
//int x=3,y=5,z=5;//2838
//int x=5,y=5,z=5;//3563
//int x=5,y=5,z=7;//2838
//int x=5,y=7,z=7;
//int x=7,y=7,z=7;//3612
//int x=7,y=7,z=11;//664
//int x=5,y=5,z=11;//241
//int x=2,y=2,z=2;//Unable to allocate
//int x=2,y=3,z=3;//3612
//int x=2,y=2,z=3;//Unable to allocate!
                //Segmentation fault (core dumped)
//int x=13,y=5,z=5;
/*
Allocate 3D array (dimension of x,y) and Initialized with zero.
*/
unsigned long int inCount=0;
unsigned long int str=0;
unsigned long int ***allocate()
{
	int i,j,k;
	unsigned long int ***a=(unsigned long int ***)malloc(x*sizeof(unsigned long int **));
	if(a==NULL)
	{
		printf("Unable to allocate!\n");
		return NULL;
	}
	
	for(i=0;i<x;i++)
	{
		a[i]=(unsigned long int **)malloc(y*sizeof(unsigned long int));
		if(a[i]==NULL)
		{
			printf("Unable to allocate!\n");
			return NULL;
		}
		for(j=0;j<y;j++)
			a[i][j]=(unsigned long int *)malloc(z*sizeof(unsigned long int));
			if(a[i][j]==NULL)
			{
				printf("Unable to allocate!\n");
				return NULL;
			}
	}
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
		  for(k=0;k<z;k++)
			a[i][j][k]=0;
	printf("\nAllocated and Initilized Successfully...\n");
	return a;
}


//Read the file and differenciate in two file based on comments(# and @)
void read(){
       char ch, files[25],c,c1;
       FILE *fo1=fopen("output@.txt","w");
       FILE *fo2=fopen("output#.txt","w");
       FILE *fp=fopen("user.txt","r");
      
     
       if (fp == NULL)
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }
     
       while((ch = fgetc(fp)) != EOF)
       {
        
        
            if(ch=='@')
            {
                c = fgetc(fp); 
                while (c != EOF && c!='\n')
                {
                    fputc(c, fo1); 
                    c = fgetc(fp); 
                }
                fputc('\n',fo1);   
            } 
            else if(ch=='#')
            {
                c1 = fgetc(fp); 
                while (c1 != EOF && c1!='\n')
                {
                    fputc(c1, fo2); 
                    c1 = fgetc(fp); 
                }
                fputc('\n',fo2);   
            } 
       
            printf("%c", ch);
        }
       fclose(fp);
}

/*
Set a particular bit of a[i][j]
*/

void _set_(unsigned long int ***a,int i, int j,int k, int pos)
{
	//int i=c;
	unsigned long int d=a[i][j][k];
	unsigned long int p=1<<pos;
	a[i][j][k]=d | p;	
}

/*
Test whether a bit is set or not in a[i][j]
*/

int _test_(unsigned long int ***a,int i, int j, int k, int pos)
{

	unsigned long int d=a[i][j][k];
	unsigned long int p=1<<pos;
	unsigned long int r=d^p;
	unsigned long int t=r & p;
	//printf("D=%ld\tP=%ld\tR=%ld\tT=%ld\tPos=%d\n",d,p,r,t,pos);
	if((t==0) && (d!=0))
		return 1;
	return 0;
}

/*
Resetting particular bit of a[i][j];
*/
void _del_(unsigned long int ***a,int i, int j, int k, int pos)
{
	unsigned long int d=a[i][j][k];
	unsigned long int p=1<<pos;
	unsigned long int r=d^p;
	if((p|d)==d)
		a[i][j][k]=r;
}

/*
Insert the member w[] into a[][];
*/
void setMember(unsigned long int ***a,char w[])
{
	int i,pos;
	int j=0,k;//l,m,n,pos1;
	unsigned long int h=0;
	
	/*for(i=0;w[i]!='\0';i++)
	{
		sum+=(w[i]*(i+1))*seed;
	}*/
	h=murmur2(w,strlen(w),seed);
	i=h%x;
	j=h%y;
	k=h%z;
	pos=h%63; 
	_set_(a,i,j,k,pos);

}

/*
Test existing of the member w[] in a[][];
*/
int testMember(unsigned long int ***a,char w[])
{
	int i,pos;
	int j=0,k;//,l,m,n,pos1;
	unsigned long int h=0;
	int flag=1;
	/*for(i=0;w[i]!='\0';i++)
	{
		sum+=(w[i]*(i+1))*seed;
	}*/
	h=murmur2(w,strlen(w),seed);
	i=h%x; 
	j=h%y;
	k=h%z;
	pos=h%63;
	flag =flag & _test_(a,i,j,k,pos); 
	if(flag==1)
		return 1;
	return 0;
}


void _free_(unsigned long int ***a1,unsigned long int ***a2,unsigned long int ***a3,unsigned long int ***a4,unsigned long int ***a5,unsigned long int ***a6,unsigned long int ***a7,unsigned long int ***a8)
{
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	printf("\nMemory freed successfully...\n");
}


