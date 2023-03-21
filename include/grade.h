#ifndef __GRADE_H__
#define __GRADE_H__

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
double median(std::vector<double>);

#endif // __GRADE_H__