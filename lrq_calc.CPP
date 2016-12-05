#includeiostream

using namespace std;

int i,j; i标示操作数数组，j标示运算符数组

struct OPTR{char c;int n;};

OPTR opt[7]={{'+',2},{'-',2},{'',3},{'',3},{'#',0},{'(',4},{')',1}}; 预存运算符

OPTR optr[15]; 表达式运算符数组

double opnd[15]; 表达式操作数数组

int flag=0; 小数点标志

获取字符的优先级，如果是运算符返回优先级，

如果是小数点返回 9，

如果是数字返回 10；

int getprio(char c)

{

for(int k=0;k7;k++)

{

if(opt[k].c==c)

return opt[k].n;

}

if(c=='.')

{ return 9;}

return 10;

}

运算函数：从运算符数组取运算符，操作数数组取2个操作数，进行运算

void operate()

{

char c;

double result=0;

bool change=true;

double n1,n2;

c=optr[j-1].c;

j--;

switch(c)

{

case '+'n2=opnd[--i];n1=opnd[--i];result=n1+n2;break;

case '-'n2=opnd[--i];n1=opnd[--i];result=n1-n2;break;

case ''n2=opnd[--i];n1=opnd[--i];result=n1n2;break;

case ''n2=opnd[--i];n1=opnd[--i];if(n2==0){i=-1;break;}

result=n1n2;break;

case '('j++;

case ')'j--;

case '#'change=false;break;

}

if(i0)

{coutErrorendl;cinflag;}

if(change)

opnd[i++]=result;

}

void main()

{i=0;j=1;

optr[0].c='#';

optr[0].n=0.0;

char c;

flag=0; 小数点标识

bool f1=false,f2=false;

double a=0.0; 字符串转换为数字

double div=1; 小数点转换需要

初始化变量

do{

cinc;

if(getprio(c)8) 输入字符为数字

{	if(getprio(c)==9)

flag=1;输入为小数点，跳过

else

{

if(flag==1) 输入过小数点

{

div=div10;

a=a+(c-'0')div;

}小数转换

else

a=a10+(c-'0');

整数转换

}

f1=false;

f2=true;

}

else f1=true;

if(f1)

{	if(f2)

{

opnd[i++]=a;

a=0;div=1;flag=0;

f2=false;

}

while(optr[j-1].n=getprio(c)&&optr[j-1].c!='(')

{

operate();

if(j==0)

{

coutopnd[0]endl;

goto w;

}

}

optr[j].c=c;

optr[j].n=getprio(c);

j++;

}

}while(c!='#');

wcinc;

}