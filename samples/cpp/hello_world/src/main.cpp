/*
 * Copyright (c) 2023, Meta
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <iostream>
#include <platform_math.hpp>

#ifdef __cplusplus
extern "C" {
	#include <libfoo.h>
}
#endif

int main(void)
{
	std::cout << "SigmoidF32: " << arm::math::MathUtils::SigmoidF32(2.3) << std::endl;
	std::cout << "result: " << foo_sample(2) << std::endl;	
	std::cout << "Hello, C++ world! " << CONFIG_BOARD << std::endl;
	return 0;
}
