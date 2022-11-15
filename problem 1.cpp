#include <iostream>
#include<functional>
using namespace std;
class Function{
    virtual double evaluateat(double value)=0;
};
class simplefunction : public Function {
private :
    std::function<double(double)> fun;
public :
    simplefunction(function<double(double)>){
    this->fun=fun;
}
double evaluateat(double value){
    return fun(value);
}
};
class comopstefunction : public Function{
private :
    function <double(double)>f;
function<double(double)>g;
public :
    compositefunction(function<double(double)>f,
                      function<double(double)>g){
    this->f=f;
    this->g=g;
}
};
double cube(double x){
    return x*x*x;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
