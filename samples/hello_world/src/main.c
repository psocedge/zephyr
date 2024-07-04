/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <pe_math.h>
#include <pe_log.h>
#include <zephyr/kernel.h>

int main(void)
{	
	PE_INFO("SigmoidF32: %f\n", pe_sigmoid_f32(3.3));
	PE_INFO("Hello World! %s\n", CONFIG_BOARD_TARGET);

	k_msleep(100);

	return 0;
}
