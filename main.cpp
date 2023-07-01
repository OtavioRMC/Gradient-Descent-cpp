#include "Gradient.cpp"
#include <iostream>
#include <functional>

double ObjectFnc(std::vector<double> *funcLoc){
  double x = funcLoc->at(0);
  return (x*x);
}

int main(){

  std::function<double(std::vector<double>*)> p_ObjectFcn{ObjectFnc};

  // Test instance.
  Gradient solver;

  // Asign the object function.
   solver.setObjectFn(p_ObjectFcn);

  std::vector<double> startPoint = {-1.0};
  solver.setStartPoint(startPoint);
  
  solver.setMaxIterations(50);
  solver.setStepSize(0.2);

  std::vector<double> funcLoc;
  double funcVal;
  solver.Optimize(&funcLoc,&funcVal);

  
  std::cout << "Function Location(x) : " << funcLoc[0] << std::endl;
  std::cout << "Function value(y): " << funcVal << std::endl;

  return 0;
} 

