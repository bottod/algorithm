    #include <iostream>  
    #include <cstring>  
    using namespace std;  
    void reverse_str(char *a,int size){  
        for(int i=0;i<size/2;++i){  
            char t=a[i];  
            a[i]=a[size-i-1];  
            a[size-i-1]=t;  
        }  
    }  
      
    int f_to_i(char *a,char *c){//将浮点数字符串转化为整形字符串,并返回浮点数小数部分的长度  
        int len=strlen(a);  
        char *p1=a;  
        char *p2=NULL;  
        for(int i=0;i<len;++i){  
            if(a[i]=='.'){  
                a[i]='\0';  
                p2=&a[i+1];  
                break;  
            }  
        }  
        strcat(p1,p2);  
        strcpy(c,p1);  
        return strlen(p2)+1;  
    }  
      
    //核心思想就是按照小数点位置坐对其处理,小数部分较短的那个数补0  
    void large_float_sum(char a[],char b[],char c[]){//打印出结果并把结果放到c中  
        char p1[20000]={0};  
        char p2[20000]={0};  
        int pos1=f_to_i(a,p1);  
        int pos2=f_to_i(b,p2);  
        int max_pos;  
        if(pos1>pos2){//给小数部分长度较短的那个数补0,以便后续的大数加法处理  
            int t=pos1-pos2;  
            int len=strlen(p2);  
            int i;  
            for(i=0;i<t;++i){  
                p2[i+len]='0';  
            }  
            p2[i+len]='\0';  
            max_pos=pos1;  
        }else{  
            int t=pos2-pos1;  
            int len=strlen(p1);  
            int i;  
            for(i=0;i<t;++i){  
                p1[len+i]='0';  
            }  
            p1[i+len]='\0';  
            max_pos=pos2;  
        }  
      
    //  cout<<p1<<endl;  
    //  cout<<p2<<endl;  
      
        int a_len=strlen(p1);  
        int b_len=strlen(p2);  
        reverse_str(p1,a_len);  
        reverse_str(p2,b_len);  
        int max_len=a_len>b_len?a_len:b_len;  
        int i;  
        for(i=0;i<a_len||i<b_len;++i){  
            c[i]+=p1[i]+p2[i]-'0'-'0';  
            if(i>=a_len||i>=b_len){  
                c[i]+='0';  
            }  
            if(c[i]>9){  
                c[i]-=10;  
                c[i+1]+=1;  
            }  
        }  
      
      
        int j;  
        for(j=max_len;j>0;--j){//去0  
            if(c[j]!=0){  
                break;  
            }  
        }  
        for(int i=j;i>=max_pos;--i){  
            cout<<(int)c[i];  
        }  
        cout<<".";  
        for(int i=max_pos-1;i>=0;--i){  
            cout<<(int)c[i];  
        }  
        cout<<endl;  
    }  

    bool judgeflag(char* x)
    {
    	int pointnum = 0;
    	long size = strlen(x);
    	for(int i =0;i<size;i++)
    	{
    		if(x[i]>57 || x[i]<45)
    			return false;
    		if(x[i] == 47)
    			return false;
    		if(x[i] == 46)
    		{
    			pointnum +=1;
    			if(pointnum > 1)
    				return false;
    		}
    	}
    	return true;
    }
      
    int main(){  
        char a[20000]={0};  
        char b[20000]={0};  
        char c[40001]={0};  
        cin>>a;
        if(!judgeflag(a))  return 0;
        cin>>b;  
        if(!judgeflag(b))  return 0;
        large_float_sum(a,b,c);  
        return 0;  
    }  