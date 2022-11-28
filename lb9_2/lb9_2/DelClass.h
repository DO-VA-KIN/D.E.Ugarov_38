#pragma once
#include <vector>
#include <math.h>
#include <algorithm>
#include <iterator>


using namespace std;

template<class T>
class DelVector : public vector<unsigned int> {
private:
    //template <typename T1> friend ostream& operator << (ostream&, const DelVector<T1>&);
public:
    unsigned int X;
    DelVector(unsigned int x)
    {
        X = x;
        for (unsigned int i = 1; i <= x; i++)
            if (x % i == 0) this->push_back(i);

    }
};

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& rhs)
{
	copy(rhs.begin(), rhs.end(), ostream_iterator<T>(os, " "));
	return os;
}


