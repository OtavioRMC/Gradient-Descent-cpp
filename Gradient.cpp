#include "Gradient.hpp"
#include <math.h>
#include <iostream>
#include <functional>
#include <vector>

Gradient::Gradient() {
    m_nDimensions = 0;
    m_stepSize = 0.0;
    m_maxIterations = 1;
    m_gradientStepSize = 0.001;
    m_gradientThreshold = 1e-09;
}

Gradient::~Gradient(){
 
}

void Gradient::setObjectFn(std::function<double(std::vector<double>*)> objFn){
    m_objectFunction = objFn;
}

void Gradient::setStartPoint(const std::vector<double> startPoint){
    m_startPoint = startPoint;
    m_nDimensions = startPoint.size();
}

void Gradient::setStepSize(double stepSize){
    m_stepSize = stepSize;
}

void Gradient::setMaxIterations(int maxIterations){
    m_maxIterations = maxIterations;
}

void Gradient::setGradientThreshold(double gradientThreshold){
    m_gradientThreshold = gradientThreshold;
}


bool Gradient::Optimize(std::vector<double> *funcLoc, double *funcVal){


    m_currentPoint = m_startPoint;
    int iterCount =0;
    double gradientMagnitude = 1.0;
    while((iterCount < m_maxIterations) && (gradientMagnitude > m_gradientThreshold)){
        std::vector<double> gradientVector = computeGradientVector();
        gradientMagnitude = computeGradientMagnitude(gradientVector);

        std::vector<double> newPoint = m_currentPoint;
        for(int i = 0;i < m_nDimensions;i++){
            newPoint[i] += -(gradientVector[i] * m_stepSize);
        }

        m_currentPoint = newPoint;
        iterCount++;
    }
    *funcLoc = m_currentPoint;
    *funcVal = m_objectFunction(&m_currentPoint);
    return true;
}

double Gradient::computeGradient(int dim){
    std::vector<double> newPoint = m_currentPoint;

    newPoint[dim] += m_gradientStepSize;

    double funcVal1 = m_objectFunction(&m_currentPoint);
    double funcVal2 = m_objectFunction(&newPoint);

    return (funcVal2 - funcVal1) / m_gradientStepSize; 
}

std::vector<double> Gradient::computeGradientVector(){
  
  std::vector<double> gradientVector = m_currentPoint;
  for (int i = 0; i < m_nDimensions; i++) {
    gradientVector[i] = computeGradient(i);
  }
  return gradientVector;
}

double Gradient::computeGradientMagnitude(std::vector<double> gradientVector){

    double gradientMagnitude = 0.0;
    for (int i = 0; i <  m_nDimensions; i++) {
        gradientMagnitude += gradientVector[i] * gradientVector[i];
    }
    return sqrt(gradientMagnitude);
}
