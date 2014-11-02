/*
ID: _____
PROG: friday
LANG: C++11
*/

#include <fstream>
#include <vector>

using namespace std;


bool IsLeap(unsigned int  year)
{
	if (year % 4 != 0) return false;
	else
		if (year % 100 != 0) return true;
		else
			if (year % 400 != 0) return false;
			else
				return true;
}



int MonthLimit(int Month, int year)
{
	switch (Month)
	{
	case 4:
	case 6:
	case 9:
	case 11:
	{
		return 30;
		break;
	}
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		return 31;
		break;
	}
	case 2:
		if (IsLeap(year))
		{
			return 29;
			break;
		}
		else
		{
			return 28;
			break;
		}

	}
}

class Date
{
	public:
		unsigned short int Day;
		unsigned short int Month;
		unsigned short int Year;
		unsigned short int DayOfWeek;
		void increment_Date(Date &d);
};



void Date::increment_Date(Date &d)
{
	d.DayOfWeek = (d.DayOfWeek + 1) % 7; //increase weekday
	if (++d.Day > MonthLimit(d.Month, d.Year))    //increase day, if larger than month size...
	{
		d.Day = 1;                       //reset day to 1
		if (++d.Month > 12)              //increase month, if larger than year size
		{
			d.Month = 1;                   //reset month to 1
			d.Year++;                      //increase year
		}
	}
}


/*
We think that days are Monday(1) to Sunday(7),
			  months are from January(1) to December(12),
			  years are straighforward enough.
*/

/*
Actually we have to write something. 
Probably an iterator (not in the specific vector sense) 
that'd loop over our dates and sometimes modify our vector of counters
*/

const Date FirstDayEver = { 1, 1, 1900, 1 };  //January 1, 1900 was on a Monday.

int main()
{
	ifstream fin ("friday.in", ios::in);
	ofstream fout("friday.out", ios::out);

	unsigned short int years;
	fin >> years;

	vector<int> counters (7);   //whenever a 13th falls on a day X, we increment the Xth counter. It's that simple
							    //Actually calculating Dates is the hard part

	Date CurrentDate = FirstDayEver;

	for (Date i = FirstDayEver; !((i.Day == 31) && (i.Month == 12) && (i.Year == 1900 + years - 1)); i.increment_Date(i))
	{
		if (i.Day == 13)
			counters[i.DayOfWeek]++;
	}

	fout << counters[6] << " " << counters[0] << " " << counters[1] << " " << counters[2] << " " << counters[3] << " " << counters[4] << " " <<counters[5] << "\n";
	fin.close();
	fout.close();


	exit (0);
}

