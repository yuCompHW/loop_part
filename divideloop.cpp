/*
 * divideloop.cpp
 *
 * 寻找小数循环节
 *
 * reference: http://edisonx.pixnet.net/blog/post/69611581-%5Bc%26%2B%2B%5D-%E5%88%86%E6%95%B8%E5%8C%96%E5%BE%AA%E7%92%B0%E5%B0%8F%E6%95%B8
 *  Created on: 12 Mar 2016
 *      Author: zeroxwj
 */

#include <iostream>
#include <string>

int main() {

	//input
	unsigned int numerator;	//被除数
	unsigned int denominator; //除数

	const unsigned int MAX_SZ = 16384;
	char loop_part[MAX_SZ];

	std::cin >> numerator >> denominator;

	// make the numerator smaller than denominator
	unsigned int module = numerator % denominator;

	// trivial case:
	if (module == 0) {
		loop_part[0] = '0';
		loop_part[1] = '\0';
		std::cout << "the loop part is: " << loop_part << std::endl;
		return 0;
	}

	numerator = module;	// now numerator must be smaller than denominator

	// do the 2/5 decomposition
	unsigned len_noloop = 0;
	unsigned cnt2 = 0;
	unsigned cnt5 = 0;

	unsigned int cpy_denominator = denominator;
	while ((cpy_denominator % 2) == 0) {
		cpy_denominator /= 2;
		++cnt2;
	}

	while ((cpy_denominator % 5) == 0) {
		cpy_denominator /= 5;
		++cnt5;
	}

	// trivial case: if the denominator can be decomposed with all 2 and 5, no loop
	if (cpy_denominator == 1) {
		loop_part[0] = '0';
		loop_part[1] = '\0';
		std::cout << "the loop part is: " << loop_part << std::endl;
		return 0;
	}

	len_noloop = ((cnt2 > cnt5) ? cnt2 : cnt5);

	unsigned int i;
	// consume the non-loop part
	for (i = 0; i < len_noloop; ++i) {
		numerator *= 10;
		numerator %= denominator;
	}

	// output the loop part
	unsigned int original_numerator = numerator;

	unsigned int pos = 0;
	do {
		numerator *= 10;
		loop_part[pos] = char(numerator/denominator + 48);	//convert int to char
		pos++;
		numerator %= denominator;
	} while (numerator != original_numerator);
	loop_part[pos] = '\0';

	std::cout << "the loop part is: " << loop_part << std::endl;
	return 0;
}








