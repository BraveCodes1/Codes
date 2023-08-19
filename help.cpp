#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    return n*fact(n-1);
}
int czero(int n)
{
    int c=0;
    for(int i=5;i<n;i=5*i)
    {
        c=c+n/i;
    }
    return c;
}

int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

bool isprime(int n)
{
    if(n==1)
    {
        return false;
    }
    if(n==2 || n==3)
    {
        return true;
    }
    if(n%2==0 || n%3==0)
    {
        return false;
    }
    for(int i=5;i*i<=n;i=i+6)
    {
        if(n%i==0 || n%i+2==0)
        {
            return false;
        }
    }
    return true;
}
void primeFactors(int n)
{
    if(n<=1) return;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i<<"\n";
            n=n/i;
        }
    }
    if(n>1)
    {
        cout<<n;
    }
}

void div(int n)
{
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            cout<<n/i<<"\n";
        }


    }
}

int power(int n, int x)
{
    if(x==0)
    {
        return 1;
    }
    int temp = power(n,x/2);
    temp=temp*temp;
    if(x%2==0)
    {
        return temp;
    }
    else
    {
        return temp*n;
    }
}
bool kbit(int n, int k)
{
    if(n&(1<<(k-1))==1)
        return true;
    return false;
}

int setb(int n)
{
    int b=0;
    while(n>0)
    {
        n=(n&(n-1));
        b++;
    }
    return b;
}
bool pow2(int n)
{
    int temp = n&(n-1);
    if(temp==0)
    {
        return true;
    }
    return false;
}
int oddo(int arr[], int n)
{
    int res=arr[0];
    for(int i=1;i<n;i++)
    {
        res=res^arr[i];
    }
    return res;
}

void oddtwo(int arr[], int n)
{
    int XOR=0;
    int res1=0, res2=0;
    for(int i=0;i<n;i++)
    {
        XOR=XOR^arr[i];
    }
    int sn = XOR & ~(XOR-1);
    for(int i=0;i<n;i++)
    {
        if((arr[i]&sn)!=0)
        {
            res1 = res1^arr[i];
        }
        else
        {
            res2= res2^arr[i];
        }
    }  
    cout<<res1<<" "<<res2;
}

void powset(string s)
{
    int n=s.length();
    int powsize=power(2,n);
    for(int counter=0;counter<powsize;counter++)
    {
        for(int j=0;j<n;j++)
        {
            if((counter&(1<<j))!=0)
            {
                cout<<s[j];
            }
        }
        cout<<"\n";
    }
}

int gsum(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n+gsum(n-1);
}

bool palind(string str,int start, int end)
{
    if(start>=end)
    {
        return true;
    }
    return ((str[start]==str[end])&palind(str,start+1,end-1));
}

int sdig(int n)
{
    if(n<=0)
        return 0;
    return (n%10)+sdig(n/10);
}

int maxPieces(int n,int a,int b,int c)
{
    if(n==0) 
    {return 0;}
    if(n<0)
    {return -1;}
    int res = max(maxPieces(n-a,a,b,c),
                  max(maxPieces(n-b,a,b,c),
                  maxPieces(n-c,a,b,c)));
    if(res==-1)
    {return -1;}
    return res+1;
}

void subsets(string s,string curr="", int i=0)
{
    if(i==s.length())
    {
        cout<<curr<<"\n";
        return;
    }
    subsets(s,curr,i+1);
    subsets(s,curr+s[i],i+1);
}

void TOH(int n,int A,int B,int C)
{
    if(n==1)
    {
        cout<<"Move 1 from "<<A<<" to "<<C<<endl;
        return;
    }
    TOH(n-1,A,C,B);
    cout<<"Move "<<n<<" from "<<A<<" to "<<C<<endl;
    TOH(n-1,B,A,C);
}

int jos(int n,int k)
{
    if(n==1)
    {
        return 0;
    }
    return (jos(n-1,k)+k)%n;
}

//Count Subsets woth given sum
int countsum(int arr[], int n,int sum)
{
    if(n==0)
    {
        return (sum==0)?1:0;
    }
    return countsum(arr,n-1,sum)+countsum(arr,n-1,sum-arr[n-1]);
}
int main() 
{
    int arr[] = {10,20,15};
    cout<<countsum(arr,3,25);
    return 0;
}
