# 1st Order Linear Ordinary Differential Equation Solver

![_badge](https://img.shields.io/badge/Project-FOLODE%20Solver-green?style=for-the-badge&logo=C)

This application takes in a text file detailing 1st order ODE of linear time invarient system and solves it using Euler Forward Method or Modified Euler Forward Method or Runge-Kutta 4 Method. The solution then can be save to a CSV file or plot of the solution can be obtained.

![Demogif](./6_ImagesAndVideos/folodesolver.gif)

## Code Quality Badges

| Codacy | Build | Cppcheck | Valgrind | Unity |
|-|-|-|-|-|
| [![Codacy Badge](https://app.codacy.com/project/badge/Grade/0eeda194d63a4ac49703bf8a1344102c)](https://www.codacy.com/gh/bgvmysore/miniproject_stepin/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=bgvmysore/miniproject_stepin&amp;utm_campaign=Badge_Grade) | [![C/C++ CI - Build Status](https://github.com/bgvmysore/miniproject_stepin/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/bgvmysore/miniproject_stepin/actions/workflows/c-cpp.yml) | [![Cppcheck](https://github.com/bgvmysore/miniproject_stepin/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/bgvmysore/miniproject_stepin/actions/workflows/cppcheck.yml) | [![Valgrind](https://github.com/bgvmysore/miniproject_stepin/actions/workflows/valgrind.yml/badge.svg)](https://github.com/bgvmysore/miniproject_stepin/actions/workflows/valgrind.yml) | [![Unit Tests](https://github.com/bgvmysore/miniproject_stepin/actions/workflows/unity.yml/badge.svg)](https://github.com/bgvmysore/miniproject_stepin/actions/workflows/unity.yml) |

## Folder Structure

Folder             | Description
-------------------| -----------------------------------------
`1_Requirements`   | Documents detailing requirements and research
`2_Design`         | Documents specifying design details
`3_Implementation` | All code and documentation
`4_Test_plan`      | Documents with test plans and procedures
`6_ImagesAndVideos`| All images and videos related to project
`7_Other`          | Other documents related to project

## Contributors List and Summary

|SF No.   |  Name     |    Features    | Issuess Raised |Issues Resolved|No Test Cases|Test Case Pass|
|-|-|-|-|-|-|-|
|`258009` | Bhargav R | Main application and features detailed in requirements | None | - | 11 | 11 |

## External Libraries Used

*   This project utilizes [gnuplot_i](http://ndevilla.free.fr/gnuplot/) library to interface with **gnuplot**
*   [Unity](https://github.com/ThrowTheSwitch/Unity) from Throw The Switch as unit test framework

## Project Dependencies

1. GCC
2. Make
3. Gnuplot

## Challenges Faced and How Was It Overcome

1. Github actions, github badges all these things seemed difficult at first but then I slowly learnt about these things with help of study materials uploaded at futureskill platform and overcame the difficulties faced.

2. Time management became a issue at first then I planned my work using github's project feature to list out the tasks and followed them accordingly

3. I had to use a different computer during the final week as my computer wouldn't work. Github was very useful as I carried out work from another machine until my PC was fixed.

## Learning Resources

1. [markdownBasics](https://guides.github.com/features/mastering-markdown/)

2. [github workflow](https://docs.github.com/en/actions/learn-github-action)

3. [gnuplot_i docs](http://ndevilla.free.fr/gnuplot/gnuplot_i/index.html)

4. [Unity docs](https://github.com/ThrowTheSwitch/Unity/tree/master/docs)
