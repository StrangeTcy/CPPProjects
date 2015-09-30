#include <iostream>
#include <string>


using namespace std;

int getMonth(string& month)
{
	if (month == "January")
 return 1;
	else if	(month == "February")
			return 2;
			
	else if	(month == "March")
			return 3;
			
	else if	(month == "April")
			return 4;
			
	else if	(month == "May")
			return 5;
			
	else if	(month == "June")
			return 6;
			
	else if	(month == "July")
			return 7;
			
		else if	(month == "August")
			return 8;
			
		else if	(month == "September")
			return 9;
				
		else if	(month == "October")
			return 10;
			
		else if	(month == "November")
			return 11;
			
		else if	(month == "December")
			return 12;
				
}


string dayofweek(int d, int m, int y)
{
    unsigned short int result;
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    result =  ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
	switch(result)
	{
		case 0:
			return "Sunday";
			break;
		case 1:
			return "Monday";
			break;
		case 2:
			return "Tuesday";
			break;
		case 3:
			return "Wednesday";
			break;
		case 4:
			return "Thursday";
			break;
		case 5:
			return "Friday";
			break;
		case 6:
			return "Saturday";
			break;
	}
}


int main()
{
   	unsigned short int d;
	string M;
	unsigned int y;
	
	cin >> d >> M >> y;
	cout << dayofweek(d,getMonth(M),y) << "\n";

    return 0;
}
