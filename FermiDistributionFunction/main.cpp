//
//  main.cpp
//  FermiDistributionFunction
//
//  Created by iseki on 2013/09/10.
//  Copyright (c) 2013年 iseki. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>

#include "Constants.hpp"

long double
calcFermiPseudoPotentialConduction(long double n)
{
	return E_c + powl(3.0*M_PI*M_PI, 2.0/3.0)*(hbar*hbar/(2*m_ee))*powl(n, 2.0/3.0);
}

long double
calcFermiDistribution(long double E_fc,long double E_ch)
{
	return 1.0 / (1.0 + exp2l( ( m_eh/(m_eh+m_ee)*(E_ch - E_g) - E_fc + E_c ) / (k_b*T) ));
}

int main(int argc, const char * argv[])
{
	std::string fname = "data/conduction.csv";
	std::ofstream ofs(fname);
	if (&ofs == NULL) {
		std::cout << fname << "can't open.";
		return -1;
	}
	long double n = 1e15;
	long double E_fc = calcFermiPseudoPotentialConduction(n);
	long double t;
	std::cout << E_c << std::endl;
	std::cout << E_v << std::endl;
	std::cout << E_c - E_v << std::endl;
	std::cout << E_g << std::endl;
	std::cout << E_fc << std::endl;
	
	const long double coeff = 1e-20;
	for (long double i=1.71e-19; i<2.7e-19; i+=coeff/100.0) {
		t = calcFermiDistribution(E_fc, i);
		ofs << i << "," << t << std::endl;
		std::cout << i << "," << t << std::endl;
	}
}

