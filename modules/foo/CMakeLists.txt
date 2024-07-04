# Copyright (c) 2023 Meta Platforms
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_LIBFOO)

  set(LIB_FOO_DIR ${ZEPHYR_CURRENT_MODULE_DIR})

  zephyr_library()

  zephyr_library_compile_options(-Ofast)

  zephyr_include_directories(
    ${LIB_FOO_DIR}/include
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

  # source files
  set(FOO_SOURCES ${LIB_FOO_DIR}/src/plain.c)

  zephyr_library_sources(${FOO_SOURCES})

endif()
