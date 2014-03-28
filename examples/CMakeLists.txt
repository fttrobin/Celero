# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #

SET(PROJECT_TEST_NAME celeroDemoComparison)

#
# Add Sources
#

add_executable(${PROJECT_TEST_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/DemoComparison.cpp
  )

#
# Celero Project Dependencies
#

add_dependencies(${PROJECT_TEST_NAME} celero)
target_link_libraries(${PROJECT_TEST_NAME} celero)

#
# Broiler Plate
#

# VS2012 doesn't support true variadic templates
if(MSVC) 
  add_definitions( /D _VARIADIC_MAX=10 )
endif()

include_directories(${HEADER_PATH})

# Show here how to automate running after a build:
# if(CELERO_RUN_EXAMPLE_ON_BUILD)
#	add_custom_command(TARGET ${PROJECT_TEST_NAME} POST_BUILD COMMAND $<TARGET_FILE:${PROJECT_TEST_NAME}>)
# endif()

# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #

SET(PROJECT_TEST_NAME celeroDemoSimple)

#
# Add Sources
#

add_executable(${PROJECT_TEST_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/DemoSimple.cpp
  )

#
# Celero Project Dependencies
#

add_dependencies(${PROJECT_TEST_NAME} celero)
target_link_libraries(${PROJECT_TEST_NAME} celero)

#
# Broiler Plate
#

# VS2012 doesn't support true variadic templates
if(MSVC) 
  add_definitions( /D _VARIADIC_MAX=10 )
endif()

include_directories(${HEADER_PATH})

# Show here how to automate running after a build:
# Will leave this one operational for demonstrational purposes
add_custom_command(TARGET ${PROJECT_TEST_NAME} POST_BUILD COMMAND $<TARGET_FILE:${PROJECT_TEST_NAME}>)

# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #

SET(PROJECT_TEST_NAME celeroDemoJUnit)

#
# Add Sources
#

add_executable(${PROJECT_TEST_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/DemoSimpleJUnit.cpp
  )

#
# Celero Project Dependencies
#

add_dependencies(${PROJECT_TEST_NAME} celero)
target_link_libraries(${PROJECT_TEST_NAME} celero)

#
# Broiler Plate
#

# VS2012 doesn't support true variadic templates
if(MSVC) 
  add_definitions( /D _VARIADIC_MAX=10 )
endif()

include_directories(${HEADER_PATH})

# Show here how to automate running after a build:
# if(CELERO_RUN_EXAMPLE_ON_BUILD)
#	add_custom_command(TARGET ${PROJECT_TEST_NAME} POST_BUILD COMMAND $<TARGET_FILE:${PROJECT_TEST_NAME}>)
# endif()

# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #

SET(PROJECT_TEST_NAME celeroDemoSort)

#
# Add Sources
#

add_executable(${PROJECT_TEST_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/DemoSort.cpp
  )

#
# Celero Project Dependencies
#

add_dependencies(${PROJECT_TEST_NAME} celero)
target_link_libraries(${PROJECT_TEST_NAME} celero)

#
# Broiler Plate
#

# VS2012 doesn't support true variadic templates
if(MSVC) 
  add_definitions( /D _VARIADIC_MAX=10 )
endif()

include_directories(${HEADER_PATH})

# Show here how to automate running after a build:
# if(CELERO_RUN_EXAMPLE_ON_BUILD)
#	add_custom_command(TARGET ${PROJECT_TEST_NAME} POST_BUILD COMMAND $<TARGET_FILE:${PROJECT_TEST_NAME}>)
# endif()

# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #

SET(PROJECT_TEST_NAME celeroDemoTransform)

#
# Add Sources
#

add_executable(${PROJECT_TEST_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/DemoTransform.cpp)

#
# Celero Project Dependencies
#

add_dependencies(${PROJECT_TEST_NAME} celero)
target_link_libraries(${PROJECT_TEST_NAME} celero)

#
# Broiler Plate
#

# VS2012 doesn't support true variadic templates
if(MSVC) 
  add_definitions( /D _VARIADIC_MAX=10 )
endif()

include_directories(${HEADER_PATH})

# Show here how to automate running after a build:
# if(CELERO_RUN_EXAMPLE_ON_BUILD)
#	add_custom_command(TARGET ${PROJECT_TEST_NAME} POST_BUILD COMMAND $<TARGET_FILE:${PROJECT_TEST_NAME}>)
# endif()

# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #

SET(PROJECT_TEST_NAME celeroDemoParameterPassing)

#
# Add Sources
#

add_executable(${PROJECT_TEST_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/DemoParameterPassing.cpp)

#
# Celero Project Dependencies
#

add_dependencies(${PROJECT_TEST_NAME} celero)
target_link_libraries(${PROJECT_TEST_NAME} celero)

#
# Broiler Plate
#

# VS2012 doesn't support true variadic templates
if(MSVC) 
  add_definitions( /D _VARIADIC_MAX=10 )
endif()

include_directories(${HEADER_PATH})

# Show here how to automate running after a build:
# if(CELERO_RUN_EXAMPLE_ON_BUILD)
#	add_custom_command(TARGET ${PROJECT_TEST_NAME} POST_BUILD COMMAND $<TARGET_FILE:${PROJECT_TEST_NAME}>)
# endif()

# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #

SET(PROJECT_TEST_NAME celeroDemoSleep)

#
# Add Sources
#

add_executable(${PROJECT_TEST_NAME} 
  ${CMAKE_CURRENT_SOURCE_DIR}/DemoSleep.cpp)

#
# Celero Project Dependencies
#

add_dependencies(${PROJECT_TEST_NAME} celero)
target_link_libraries(${PROJECT_TEST_NAME} celero)

#
# Broiler Plate
#

# VS2012 doesn't support true variadic templates
if(MSVC) 
  add_definitions( /D _VARIADIC_MAX=10 )
endif()

include_directories(${HEADER_PATH})

# Show here how to automate running after a build:
# if(CELERO_RUN_EXAMPLE_ON_BUILD)
#	add_custom_command(TARGET ${PROJECT_TEST_NAME} POST_BUILD COMMAND $<TARGET_FILE:${PROJECT_TEST_NAME}>)
# endif()


