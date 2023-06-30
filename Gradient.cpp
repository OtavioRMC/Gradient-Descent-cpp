#include "Gradient.hpp"
#include <math.h>

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

