# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_cpp_world)

zephyr_compile_options(-DARM_MATH_LOOPUNROLL -DCPU_CORTEX_M55 -DCPU_HEADER_FILE=\"ARMCM55.h\" -mlittle-endian -mfloat-abi=hard -flax-vector-conversions -funsigned-char -march=armv8.1-m.main+mve.fp+fp.dp -fno-function-sections -fdata-sections)

target_sources(app PRIVATE src/main.cpp)
