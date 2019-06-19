#include <stdio.h>
#include <stdlib.h>
     
int main()
{
       char ch1, files[25],c,c1;
       FILE *fo1=fopen("usersplit.txt","w");
      // FILE *fo2=fopen("file2.txt","w");
       FILE *fm=fopen("userurl.txt","r");
       FILE *fm1=fopen("userurl.txt","r");
      FILE *fm2=fopen("userurl.txt","r");
      
  
     
       if (fm == NULL)
       {
          perror("Error while opening the file.\n");
          exit(EXIT_FAILURE);
       }
      
       
       int count=0,f=0,count1=0;
        c1=fgetc(fm);
        printf("c1 = %c\n",c1);
       
       while((c1  != EOF ))
       {
        
        if(c1=='\n'){f=0;c1=fgetc(fm);
          fputc('\n',fo1);
          }
           
               
                while (c1!=EOF &&c1!='/' && c1!='\n' && f==0)//(c!=EOF && c!='\n')//(c!=EOF ||c!='\n'|| c!=',' || c!=' ')
                {
                    fputc(c1, fo1); 
                    c1 = fgetc(fm); 
                    
                    if(c1=='/'){f=1;count1++;}
                    
                }
              fputc('\n',fo1);   
               if(c1!=EOF)
               {c1=fgetc(fm);}
           }
            
          
      
            fputc('\n',fo1);
            
       ch1=fgetc(fm1);
       printf("ch1 = %c",ch1);
        while((ch1  != EOF ))
       {
        
          if(ch1=='\n'){count=0;ch1=fgetc(fm1);
          fputc('\n',fo1);
         }
           
               
                while (ch1!=EOF&& ch1!='\n' && count<=1)//(c!=EOF && c!='\n')//(c!=EOF ||c!='\n'|| c!=',' || c!=' ')
                {
                    fputc(ch1, fo1); 
                    ch1 = fgetc(fm1); 
                    
                    if(ch1=='/'){count++;}
                    
                }
                fputc('\n',fo1);
                ch1=fgetc(fm1);
         }
   

   c=fgetc(fm2);
    fputc('\n',fo1);
   count=0;
       while((c  != EOF ))
       {
        
         if(c=='\n'){count=0;c=fgetc(fm2);
          fputc('\n',fo1);
         }
           
               
                while (c!=EOF&& c!='\n' && count<=2)//(c!=EOF && c!='\n')//(c!=EOF ||c!='\n'|| c!=',' || c!=' ')
                {
                    fputc(c, fo1); 
                    c = fgetc(fm2); 
                    
                    if(c=='/'){count++;}
                    
                }
                c=fgetc(fm2);
               
         
        }
         
       fclose(fm);
       fclose(fo1); 
       
     FILE *fo2=fopen("usersplit.txt","r");
     FILE *fo3=fopen("usersplit1.txt","w");
     char chn=fgetc(fo2);
     while(chn!=EOF)
     {
     
         if(chn=='\n')
          chn=fgetc(fo2);
          //  fputc(chn,fo3);
        
        //  fputc('\n',fo3);
          if(chn!=EOF)
            fputc(chn,fo3);
     
            
     chn=fgetc(fo2);
     }
       fclose(fo2); 
       fclose(fo3);
    
       return 0;
}
