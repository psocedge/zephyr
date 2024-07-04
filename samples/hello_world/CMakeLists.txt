# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

target_compile_options(app PRIVATE -DACTIVATION_BUF_SZ=0x00200000 -DARMCM55 -DARM_MATH_LOOPUNROLL -DARM_NPU -DETHOSU -DETHOS_U_BASE_ADDR=0x58102000 -DETHOS_U_IRQN=56 -DETHOS_U_NPU_MEMORY_MODE=ETHOS_U_NPU_MEMORY_MODE_SHARED_SRAM -DETHOS_U_NPU_TIMING_ADAPTER_ENABLED -DETHOS_U_PRIV_ENABLED=1 -DETHOS_U_SEC_ENABLED=1 -DLOG_LEVEL=LOG_LEVEL_INFO -DTF_LITE_STATIC_MEMORY -DPRJ_DES_STR="\"ARM ML Embedded Evaluation Kit\"" -DPRJ_VER_STR=\"24.02.0\")

zephyr_compile_options(-DARM_MATH_LOOPUNROLL -DCPU_CORTEX_M55 -DCPU_HEADER_FILE=\"ARMCM55.h\" -mlittle-endian -mfloat-abi=hard -flax-vector-conversions -funsigned-char -march=armv8.1-m.main+mve.fp+fp.dp)

target_sources(app PRIVATE src/main.c)
