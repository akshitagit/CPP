#include<iostream>
using namespace std;
class DM
{	
    float meter;
	float centimeter;
    public:
	void getdata()
		{cout<< "enter distance in meters: " ;
			cin>>meter  ;
		cout<<"enter distance in centimeters : ";
		    cin>>centimeter;
		}
	friend void add();
} a1;

class DB
{	
    float inch;
	float feets;
    public:
	
	void getdata() 
		{cout<< "enter distance in feets: " ;
			cin>>feets  ;
		cout<<"enter distance in inches :";
		    cin>>inch;
		}
	friend void add();
} a2;

void add()
{	float a,aa,b,bb,res;
	a=a1.meter;
	b=a1.centimeter;
	aa=a2.feets;
	bb=a2.inch;
	cout<<"Summation of both Mesurment in Meter and Centimter"<<endl;
	res = a + (aa*0.305);
	cout<<res<<": Meters"<<"\t";
	res = b + (bb*2.54);
	cout<<res<<":Centimeter"<<endl;
	

} 
int main()
{	a1.getdata();
	a2.getdata();
	add();

	return 0;
	
}