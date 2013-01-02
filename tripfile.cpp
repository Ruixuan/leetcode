#include<stdio>

int main(){
    FILE  *fp;
    FILF  *output;
    int c;
    fp = fopen("output.csv","r");
    output = fopen("trimed.csv","w");
    c = 0;
    while(1){
       c = fgetc(fp);
       if (c == EOF) break;
       if (c != 10)
          if (c <32 || c>128 )
             continue;
       fputc(c , output);
       
    }   
    fclose(fp);
    fclose(output);
    return 0;
}
