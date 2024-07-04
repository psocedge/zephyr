/*
 * Copyright (c) 2023, Meta
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <iostream>
#include <vector>
#include <pe_log.h>
#include <pe_math.h>

int main(void)
{
	std::cout << "SigmoidF32: " << pe_sigmoid_f32(3.3) << std::endl;
	std::vector<float> vec_flt{1.1, 1.2, 1.56, 1.75};
	pe_softmax_f32(vec_flt.data(), vec_flt.size());
	for (auto it : vec_flt) {
		std::cout << "SoftMaxF32: " << it << std::endl;
	}	
	// std::cout << "result: " << foo_sample(2) << std::endl;	
	std::cout << "Hello, C++ world! " << CONFIG_BOARD << std::endl;
	
	return 0;
}
