# Copyright (c) 2023 Meta Platforms
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_PE_LOG)

    set(LIB_PE_LOG_DIR ${ZEPHYR_CURRENT_MODULE_DIR})
    zephyr_interface_library_named(pe_log)

    zephyr_library_compile_options(-Ofast)

    zephyr_include_directories(
        ${LIB_PE_LOG_DIR}/include
    )    

    if (CONFIG_ARMV8_1_M_MVEI OR CONFIG_ARMV8_1_M_MVEF)
        if (CONFIG_CMSIS_DSP_LAX_VECTOR_CONVERSIONS)
            zephyr_library_compile_options($<$<STREQUAL:${CMAKE_C_COMPILER_ID},GNU>:-flax-vector-conversions>)
            zephyr_library_compile_options($<$<STREQUAL:${CMAKE_C_COMPILER_ID},ARMClang>:-flax-vector-conversions=integer>)
        else()
            zephyr_library_compile_options($<$<STREQUAL:${CMAKE_C_COMPILER_ID},GNU>:-fno-lax-vector-conversions>)
            zephyr_library_compile_options($<$<STREQUAL:${CMAKE_C_COMPILER_ID},ARMClang>:-flax-vector-conversions=none>)
        endif()
    endif()

    zephyr_library_compile_options(-Ofast)

    zephyr_compile_definitions_ifndef(CONFIG_ARM __GNUC_PYTHON__)   

endif()
