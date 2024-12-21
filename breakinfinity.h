using namespace std;
//breakinfinity.h v1.0
//使c++支持-ee4932~+ee4932的大数字 
//以下为补充内容
//ToNum(a,b):返回Num，a*10^b
//printNum(r):输出r，一个Num
//Add(a,b),Mul(a,b):a+b和a*b
//Neg(a):返回-a
//Reci(a):返回1÷a
struct Num{
	long double base;
	long double exp;
};
Num ToNum(long double a,long double b)
{
	Num r;
	r.base=a;
	r.exp=b;
	return r;
}
void printNum(Num r)
{
	if(r.base==0)printf("%d\n",0);
	else if(fabs(r.exp)<9)
	{
		printf("%.0Lf\n",r.base*pow(10,r.exp));
	}
	else if(fabs(r.exp)<1e9)
	{
		printf("%.3Lfe%.0Lf\n",r.base,r.exp);
	}
	else printf("e%.3Lfe%.0Lf\n",r.exp/pow(10,int(log10(r.exp))),static_cast<long double>(float(int(log10(r.exp)))));
}
Num Add(Num m,Num n)
{
	Num m1,n1;
	if(m.exp==n.exp)
	{
		m1=m;
		n1=n;
	}
	else if(fabs(m.exp-n.exp)<=25.0)
	{
		if(m.exp<n.exp)
		{
			m1.base=pow(0.1,(n.exp-m.exp))*m.base;
			m1.exp=n.exp;
			n1=n;
		}
		else
		{
			n1.base=pow(0.1,(m.exp-n.exp))*n.base;
			n1.exp=m.exp;
			m1=m;
		}
	}
	else
	{
		if(m.exp>n.exp)
		{
			n1.exp=m.exp;
			n1.base=0;
			m1=m;
		}
		else{
			m1.exp=n.exp;
			m1.base=0;
			n1=n;
		}
	}
	Num result;
	result.exp=n1.exp;
	result.base=n1.base+m1.base;
	if (fabs(result.base)>=10)
	{
		result.base/=10;
		result.exp+=1;
	}
	return result;
}
Num Neg(Num n){
	Num result;
	result.exp=n.exp;
	result.base=-(n.base);
}
Num Mul(Num m,Num n)
{
	Num result;
	result.exp=n.exp+m.exp;
	result.base=n.base*m.base;
	while (fabs(result.base)>=10)
	{
		result.base/=10;
		result.exp+=1;
	}
	return result;
}
Num Reci(Num n){
	Num result;
	result.exp=-(n.exp);
	result.base=1/(n.base);
	while (fabs(result.base)>=10)
	{
		result.base/=10;
		result.exp+=1;
	}
	while (fabs(result.base)<=0.1)
	{
		result.base*=10;
		result.exp-=1;
	}
}
//以上为补充内容 
