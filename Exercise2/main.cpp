#include <iostream>
#include <fstream>
#include <sstream>
#include "src/Utils.hpp"

using namespace std;

int main()
{
    string inputFileName = "./data.txt";
    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    

    if(!ImportData(inputFileName, S, n, w, r)){
        cerr << "Something goes wrong with import"<< endl;
        return -1;
    }

    double RateofReturn;
    double V;
    ComputeRateofReturn(S, n, w, r, RateofReturn, V);

    ExportResult(cout, S, n, w, r, RateofReturn, V);

    string outputFileName = "./result.txt";
    ofstream ofs;
    ofs.open(outputFileName);

    if (!ofs.fail())
    {
        ExportResult(ofs, S, n, w, r, RateofReturn, V);
    }

    ofs.close();

    delete[] w;
    delete[] r;



    return 0;
}

