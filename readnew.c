#include <stdio.h>
#include <stdlib.h>
     
int main()
{
       char ch1, files[25],c,c1;
       FILE *fo1=fopen("cache.txt","w");
      // FILE *fo2=fopen("file2.txt","w");
       FILE *fm=fopen("cachedb.txt","r");
       FILE *fm1=fopen("cachedb.txt","r");
      FILE *fm2=fopen("cachedb.txt","r");
      
  
     
       if (fm == NULL)
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }
      
       
       int count=0,f=0;
        c1=fgetc(fm);
        //printf("c1 = %c\n",c1);
       
       while((c1  != EOF ))
       {
        
          if(c1=='\n'){f=0;c1=fgetc(fm);
          fputc('\n',fo1);}
           
               
                while (c1!=EOF &&c1!='/' && c1!='\n' && f==0)//(c!=EOF && c!='\n')//(c!=EOF ||c!='\n'|| c!=',' || c!=' ')
                {
                    fputc(c1, fo1); 
                    c1 = fgetc(fm); 
                    
                    if(c1=='/'){f=1;}
                    
                }
               // fputc('\n',fo1);   
           c1=fgetc(fm);
           }fputc('\n',fo1); //now
            
       ch1=fgetc(fm1);
       printf("ch1 = %c",ch1);
        while((ch1  != EOF ))
       {
        
          if(ch1=='\n'){count=0;ch1=fgetc(fm1);
          fputc('\n',fo1);}
           
               
                while (ch1!=EOF&& ch1!='\n' && count<=1)//(c!=EOF && c!='\n')//(c!=EOF ||c!='\n'|| c!=',' || c!=' ')
                {
                    fputc(ch1, fo1); 
                    ch1 = fgetc(fm1); 
                    
                    if(ch1=='/'){count++;}
                    
                }
                ch1=fgetc(fm1);
         }fputc('\n',fo1); //now
   
   c=fgetc(fm2);
   count=0;
       while((c  != EOF ))
       {
        
          if(c=='\n'){count=0;c=fgetc(fm2);
          fputc('\n',fo1);}
           
               
                while (c!=EOF&& c!='\n' && count<=2)//(c!=EOF && c!='\n')//(c!=EOF ||c!='\n'|| c!=',' || c!=' ')
                {
                    fputc(c, fo1); 
                    c = fgetc(fm2); 
                    
                    if(c=='/'){count++;}
                    
                }
                c=fgetc(fm2);
               
        } fputc('\n',fo1);//now
         
       fclose(fm);
       fclose(fo1); 
       //fclose(fo2); 
    
       return 0;
}
