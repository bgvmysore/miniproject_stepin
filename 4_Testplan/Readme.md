# Test Plan

## High Level Test Plan

| Test ID | Description | Exp I/P | Exp O/P | Actual Out | Type of Test|
|-|-|-|-|-|-|
| HTP01 | Test to verify read from input data text file | Text File | Objects containing problem Info | PASS | Technical |
| HTP02 | Test to verify solution of ODE solver | Objects containing problem Info | PASS | Technical |
| HTP03 | Test to verify output methods i.e, csv or plot | Solution Data | File or invoke a program | PASS | Requirement Based|

## Low Level Test Plan

| Test ID | Description | Exp I/P | Exp O/P | Actual Out | Type of Test|
|-|-|-|-|-|-|
| LTP01-a | Test the function *fileToFOLODEnSolObj* | test_inputData.txt | FirstOrderLinearODE and OdeSOlverObject with right data from text file | FirstOrderLinearODE and OdeSOlverObject with right data from text file | Technical |
| LTP02-a | Test basic input function | time value or independent variable | Value of the input function as per standards | Values as Desired | Senario |
| LTP02-b | Test the state equation | time, previous state, ODE object | Value of rate of change of state at t | Value of rate of change of state | Senario |
| LTP02-c | Test the 3 solver functions Euler Forward, Modified Euler and RK4 | ODE object, solver Object | solution array and time array | solution array and time array as expected | Requirement Based |
| LTP03-a | Test save to CSV function | solution array from solver | csv file with solution | csv file saved as expected | Requirement Based|
| LTP03-b | Test disp solution as plot function | solution array from solver | gnuplot window with solution plotted | gnuplot window with solution plotted as expected | Requirement based |