#include "LinkedList.h"
#include <stdio.h>
#include <string>

using namespace std;
int main(){
	double dVal;
	string strVal;
	LinkedList<double> dList;
	LinkedList<string> strList;
	dList.Insert(3.14);
	dList.Insert(123456);
	dList.Insert(-0.98723);
	dList.Print();
	dList.Delete(dVal);
	cout<<"삭제된 마지막원소: "<<dVal<<endl;
	dList.Print();

	strList.Insert("This");
	strList.Insert("is a");
	strList.Insert("Template");
	strList.Insert("Example");
	strList.Print();
	strList.Delete(strVal);
	cout<<"삭제된 마지막 워소 : "<<strVal<<endl;

	return 0;
}
