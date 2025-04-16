#pragma once

#include  <iostream>
using namespace std;
bool ImportData(const string& inputFilePath,
                double& S, 
                size_t& n,
                double*& w,
                double*& r);


void ComputeRateofReturn(const double& S,
                        const size_t& n,
                        const double* const& w,
                        const double* const& r,
                        double& rateOfReturn,
                        double& V);
        

void ExportResult (ostream& ostr,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                double& rateOfReturn,
                double& V);

string ArraytoString(const size_t& n,
                    const double* const& v);


