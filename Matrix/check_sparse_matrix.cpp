#include<iostream>
#include <exception>
using namespace std;

class mismatchDimension:public exception
{
	public:
	void error_Msg()const;
};
template<class T>
class matrix
{
	int row;
	int col;
	T ele[10][10];
	public:
	void get();
	bool check_Sparse();
	matrix add(matrix&);
	void print();
};

void mismatchDimension::error_Msg()const{
    cout<<"Dimension of matrices do not match"<<endl;
}
template<class T> 
void matrix<T>::get()
{
    int m,n;
    cin>>row>>col;
    for(m=0;m<row;m++)
    {
        for(n=0;n<col;n++)
        {
            cin>>ele[m][n];
        }
    }
}

template<class T>
bool matrix <T>::check_Sparse()
{
    int m=0,n,c=0;
    int t=row*col;
    for(;m<row;m++)
    {
        for(n=0;n<col;n++)
        {
            if(ele[m][n]==0)
            c++;
        }
    }
    if(c>t/2)
    return true;
    else
    return false;
}

template<class T> 
matrix<T> matrix<T>::add(matrix<T> &a)
{
    int m,n;
    if(row!=a.row || col!=a.col)
    throw mismatchDimension();
    else
    for(m=0;m<row;m++)
    {
        for(n=0;n<col;n++)
        {
            a.ele[m][n]+=ele[m][n];
        }
    }
    return a;
}

template<class T> 
void matrix<T>::print()
{
    int m=0,n;
    for(;m<row;m++)
    {
        for(n=0;n<col;n++)
        {
            cout<<ele[m][n]<<endl;
        }
    }
}

int main()
{
	matrix<int> m1,m2,m3;
	m1.get();
	m2.get();
	try	
	{
	m3 = m1.add(m2);
	m3.print();	
	}catch(mismatchDimension &m)
	{
	m.error_Msg();
	}
	if(m1.check_Sparse())
	cout<<"Matrix is sparse"<<endl;
	else
	cout<<"Matrix is not sparse"<<endl;
	
}
