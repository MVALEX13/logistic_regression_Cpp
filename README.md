# logistic_regression_Cpp

Welcome to the logistic_regression_Cpp wiki!

This program realize the a logistic regression that aims to separate 2 sets of points by a line. The points used in this project are 2D points with coordinates **(x1,x2)**.

The model of the logistic regression follow the equation : θ0 + θ1*x1 + θ2*x2 with   (θ0; θ1; θ2) the vector of parameters to optimize.

The optimization figures displayed in real time.

The computation of the optimization is realized in C++ and the displaying of the graphs are done using python because... it's way simpler 🙂 .

the optimization graphs after 380 iterations
![image](https://user-images.githubusercontent.com/82118574/215275046-7ad4898a-73bb-48dd-90da-d28b87edbeee.png)

the optimization graphs after 1400 iterations
![image](https://user-images.githubusercontent.com/82118574/215274107-c97c7aec-acc3-475d-9e56-9fe7fb75138f.png)


To run the programm the program on your computer:

* Import the source code on yout local machine using `git clone https://github.com/MVALEX13/logistic_regression_Cpp.git`
* You need a C++ compiler, In this project we assume you have g++ (if you have another, you'll have to modify the Makefile by replacing each instance of "g++" with the name of your C++ compiler)
* run `make` to compile the project. Once compiled you'll have an executable named "main"
* run the executable in your shell using `./main`
