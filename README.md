# Counting_Integral
Program counting an integral from specific function, using Trapezoidal rule, and the romberg method.

Function integrated: sin(PI*(1+sqrt(x)/(1+x^2))*e^-x,  0 to infinity.
Function in every repetition of the loop counts an integral using trapezoidal rule, with step of integration stored in a variable called tempStep.
After counting an integral, program is extrapolating new result, using 2 previous results(of trapeze integrating, or previous extrapolation)
Loop is repeating until the current extrapolated result is different from previous by more than preset accuracy.
