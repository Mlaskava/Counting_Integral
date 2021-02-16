#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>


double integral(double x1, double x2){

    double result = 0;
    result += sin((M_PI*(1+sqrt(x1))) / (1 + pow(x1, 2))) * pow(M_E, -x1);
    result += sin((M_PI*(1+sqrt(x2))) / (1 + pow(x2, 2))) * pow(M_E, -x2);
    result *= (17.0 / 2.0) * (1.0 / (17.0 / (x2 - x1)));
    return result;
}


double trapezeRomberg(std::vector<std::vector<double>> A, double a, double b){
    double step = (b-a)/2;
    double border = 0.586 * pow(10, -7);
    double result = 0;
    double tempStep = a;


    A.emplace_back();
    A[0].push_back(integral(a, b));
    std::cout<<A[0][0]<<std::endl<<std::endl;
    int i = 0;
    do{
        i++;
        A.emplace_back();
        while(tempStep <= b){
            result += integral(tempStep, tempStep + step);
            tempStep += step;
        }

        A[i].push_back(result);
        std::cout<<A[i][0]<<" ";
        for(int j = 1; j <= i; j++){
            A[i].push_back((1/(pow(4, j) - 1))*((pow(4, j)*A[i][j - 1]) - A[i - 1][j - 1]));
            std::cout<<A[i][j]<<" ";
        }
        std::cout<<std::endl<<std::endl;


        tempStep = a;
        result = 0;
        step /= 2;
    }

    while(A[i - 1][i - 1] - A[i][i] >  border || A[i - 1][i - 1] - A[i][i] < -1*border);
    return A.back().back();
}

int main() {
    std::vector<std::vector<double>> A = {};
    double result = 0;
    result += trapezeRomberg(A, 0, 1);
    result += trapezeRomberg(A, 1, 17);
    std::cout<<std::endl<<std::endl<<"Wynik: "<<result;
    return 0;
}
