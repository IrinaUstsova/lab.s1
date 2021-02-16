//
// Created by uscova on 16.02.21.
//

#include "vector.h"

vector::vector()
{
    kr = new int [10];
}

vector::vector(const int &n1, const int &m1): n(n1), m(m1)
{
    values = new float*[n];
    for (size i=0; i<n; ++i)
    {
        values[i]=new float[m];
        for (size j=0; j<m; ++m)
            values [i][j]= values_[i][j];
    }
}
