#ifndef GRADIENT_H
#define GRADIENT_H

#include <vector>
#include <functional>

class Gradient{

public:
 /**
  * @brief Construct a new Gradient object 
  */
  Gradient();

  /**
   * @brief Destroy the Gradient object
  */
  ~Gradient();

  /**
   * @brief Function to add a pointer to the object function.
   * @param objFn
   * @return void
   * @note The object function is the function that is to be optimized.
  */
  void setObjectFn(std::function<double(std::vector<double>*)> objFn);

  /**
   * @brief Function to set the start point.
   * @param startPoint
   * @return void
   * @note The start point is the point from which the gradient descent algorithm starts.
   */
  void setStartPoint(const std::vector<double> startPoint);


  /**
   * @brief Function to set the step size. 
   * @param stepSize  
   * @return void
   * @note The step size is the size of the step taken in the direction of the gradient.
  */
  void setStepSize(double stepSize);

  /**
   * @brief Set the Max Iterations object
   * @param maxIterations 
   * @return void
   * @note The max iterations is the maximum number of iterations the gradient descent algorithm will run for.
   */
  void setMaxIterations(int maxIterations);

  /**
   * @brief Function to set the gradient threshold.
   *  @param gradientThreshold
   * @return void
   * @note The gradient threshold is the minimum value of the gradient at which the gradient descent algorithm will stop.
   */
  void setGradientThreshold(double gradientThreshold);

  /**
   * @brief Function to perform the optimization.
   * @param funcLoc   
   * @param funcVal 
   * @return bool
   * @note The function returns true if the optimization was successful and false otherwise.
   */
  bool Optimize(std::vector<double> *funcLoc, double *funcVal);

private:
  
/**
 * @brief Function to compute the gradient in the specified dimension.
 * @param dim 
 * @return double 
 * 
 */
  double computeGradient(int dim);

  /**
   * @brief Function to compute the gradient vector.
   * @return std::vector<double> 
   * @note The gradient vector is the vector of gradients in each dimension.
   */ 
  std::vector<double> computeGradientVector();

  /**
   * @brief  Function to compute the gradient magnitude.
   * @param gradientVector 
   * @return double 
   */
  double computeGradientMagnitude(std::vector<double> gradientVector);


private:

  int m_nDimensions;

  int m_stepSize;

  int m_maxIterations;

  double m_gradientStepSize;

  double m_gradientThreshold;

  std::vector<double> m_startPoint;

  std::vector<double> m_currentPoint;

  std::function<double(std::vector<double>*)> m_objectFunction;
};  

#endif