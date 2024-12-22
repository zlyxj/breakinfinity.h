#include<bits/stdc++.h>
using namespace std;
/*
使c++支持10^10^308的大数字 
以下为补充内容
*/
struct Num{
	long double base;
	long double exp;
Num operator+(const Num& n)
{
	Num m;
	m.base=this->base;
	m.exp=this->exp;
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
	while (fabs(result.base)<=0.1)
	{
		result.base*=10;
		result.exp-=1;
	}
	return result;
}
Num operator-(const Num& n)
{
	Num m;
	m.base=-(n.base);
	m.exp=n.exp;
	Num o;
	o.base=this->base;
	o.exp=this->exp;
	Num result;
	result=m+o;
	return result;
}
Num operator*(const Num& n)
{
	Num m;
	m.base=this->base;
	m.exp=this->exp;
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
Num operator/(const Num& n)
{
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
	Num t;
	t.exp=this->exp;
	t.base=this->base;
	return (t*result);
}
};
Num ToNum(long double a,long double b)
{
	Num r;
	r.base=a;
	r.exp=b;
	return r;
}
int NumToInt(Num a)
{
	return a.base*pow(10,a.exp);
}
double NumToDouble(Num a)
{
	return a.base*pow(10,a.exp);
}
long double NumToLD(Num a)
{
	return a.base*pow(10,a.exp);
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
