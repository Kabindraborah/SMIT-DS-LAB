int linear(int n,int key,int s[]){
int i;
for(i=0;i<n;++i)
 if(s[i]==key)
 return i;
return -1;
}