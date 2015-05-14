#include <iostream>
#include <cmath>
#include <time.h>
#include <omp.h>


using namespace std;

int main()
{
	clock_t t;
	t = clock();

	double prectime=omp_get_wtime();
	
	double a = 0;
	double b = 1;
	const unsigned int N = 1000*1000;
	double s = 0;
	double h = (b - a)/N;
	unsigned int i;
	#pragma omp parallel for shared(s) private(i) num_threads(2) ordered
 
	for(i = 0; i < N; i++)
	{
		double x = a + h*i;
		s+= ( pow(2,x)+1/(log(2)) )*(((i == 0) || (i == N)) ? 1 : ((i&1)==0) ? 2 : 4);	// this hack is actually
												// the Simpson's formula
												// that computes an integral numerically
	}

	s *= h/3;

	prectime=omp_get_wtime()-prectime;	
	t=clock()-t;
	cout << "The integral is " << s << ", calculated in  " << t << "clicks("<< ((float)t)/CLOCKS_PER_SEC <<" seconds) " << endl;
	cout << "Actual time spent is probably " << prectime << "seconds "<< endl;
	//cout << 2/(log(2)) << endl;
	return 0;
}
