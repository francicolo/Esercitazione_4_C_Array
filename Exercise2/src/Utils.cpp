#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

bool ImportData(const string& inputFilePath,
                double& S, 
                size_t& n,
                double*& w,
                double*& r)
    {
        ifstream ifs;
        ifs.open(inputFilePath);
        if (ifs.fail()){
            cerr << "file open failed" << endl;
            return false;
        }
        string line; //riga generica del file
        string sum;
        string n_assets;
        string weight;
        string rate;
        char sep = ';';

        getline(ifs, line, sep);
        getline(ifs, sum);
        istringstream convertS;
        convertS.str(sum);
        convertS >> S;
        
        getline(ifs, line, sep);
        getline(ifs, n_assets);
        istringstream convertN;
        convertN.str(n_assets);
        convertN >> n;

        getline(ifs, line); //riga w;r, la ignoro
        w = new double[n];
        r = new double[n];
        unsigned int i = 0;
        while (!ifs.eof()){
            
            getline(ifs, weight, sep);
            istringstream convertW;
            convertW.str(weight);
            convertW >> w[i];

            getline(ifs, rate);
            istringstream convertR;
            convertR.str(rate);
            convertR >> r[i];

            i++;
        
        }
        ifs.close();
        return true;
    }


void ComputeRateofReturn(const double& S,
                        const size_t& n,
                        const double* const& w,
                        const double* const& r,
                        double& RateofReturn,
                        double& V)
    {
        V = S; //capitale iniziale
        for(unsigned i=0; i < n; i++){
            V += r[i] * S * w[i]; //capitale guadagnato nell'i-esimo asset 
        }
        RateofReturn = (V/S) - 1; //V=(1+RateofReturn)*S
    }       

void ExportResult(ostream& ostr,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                double& RateofReturn,
                double& V)
    {
        ostr << fixed << showpoint << setprecision(2) <<
        "S = " << S << ", n = " << n << endl;

        ostr << "w = " << ArraytoString(n,w) << endl;

        ostr << "r = " << ArraytoString(n,r) << endl;

        ostr << fixed << showpoint << setprecision(4) <<
        "Rate of return of the portfolio: " << RateofReturn << endl;

        ostr << fixed << showpoint << setprecision(2) <<
        "V: " << V << endl;
    }

string ArraytoString(const size_t& n,
                    const double* const& v)

    {
        ostringstream toString;
        toString << "[ ";
        for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
        toString << "]";

        return toString.str();

    }


