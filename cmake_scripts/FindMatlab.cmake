execute_process(COMMAND sh -c "echo $(readlink `which matlab` | xargs dirname)/../extern/include"
        OUTPUT_VARIABLE MATLAB_INC_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE)
#message(${MATLAB_INC_DIR})
execute_process(COMMAND sh -c "echo $(readlink `which matlab` | xargs dirname)/../simulink/include"
        OUTPUT_VARIABLE SIMULINK_INC_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE)
#message(${SIMULINK_INC_DIR})

execute_process(COMMAND sh -c "echo $(readlink `which matlab` | xargs dirname)/glnxa64"
        OUTPUT_VARIABLE MATLAB_LIB_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE)
#message(${MATLAB_LIB_DIR})

FIND_PATH(MATLAB_INCLUDE_DIR mat.h
	PATHS $ENV{MATLAB_ROOT}/extern/include ${MATLAB_INC_DIR})
FIND_PATH(SIMULINK_INCLUDE_DIR simulink.h
	PATHS $ENV{MATLAB_ROOT}/simulink/include ${SIMULINK_INC_DIR})
FIND_LIBRARY(MATLAB_LIBRARIES_MAT mat
	PATHS $ENV{MATLAB_ROOT}/bin/glnxa64 ${MATLAB_LIB_DIR})
FIND_LIBRARY(MATLAB_LIBRARIES_MX mx
	PATHS $ENV{MATLAB_ROOT}/bin/glnxa64 ${MATLAB_LIB_DIR})

if (MATLAB_LIBRARIES_MAT AND MATLAB_LIBRARIES_MX)
	set(MATLAB_LIBRARIES ${MATLAB_LIBRARIES_MAT} ${MATLAB_LIBRARIES_MX})
endif()
if (MATLAB_INCLUDE_DIR AND SIMULINK_INCLUDE_DIR)
	set(MATLAB_INCLUDE_DIRS ${MATLAB_INCLUDE_DIR} ${SIMULINK_INCLUDE_DIR})
endif()

#message(STATUS "values:")
#message(STATUS ${MATLAB_INCLUDE_DIRS})
#message(STATUS ${MATLAB_LIBRARIES})

IF(MATLAB_INCLUDE_DIRS AND MATLAB_LIBRARIES)
    SET(MATLAB_FOUND TRUE)
ENDIF()

IF(MATLAB_FOUND)
    IF(NOT MATLAB_FIND_QUIETLY)
        MESSAGE(STATUS "Found MATLAB (lib): ${MATLAB_LIBRARIES}")
        MESSAGE(STATUS "Found MATLAB (inc): ${MATLAB_INCLUDE_DIRS}")
    ENDIF()
ELSE()
    IF(MATLAB_FIND_REQUIRED)
        MESSAGE(FATAL_ERROR "Could not find MATLAB. Try defining the MATLAB_ROOT environment variable.")
    ENDIF()
ENDIF()

