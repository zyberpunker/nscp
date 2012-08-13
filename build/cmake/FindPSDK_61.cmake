IF(WIN32)
	FIND_PATH(PSDK_61_INCLUDE_DIRS Windows.h
		PATHS
		${INC_PSDK_61}
		${INC_PSDK_61}/include
		"C:/Program Files/Microsoft SDKs/Windows/v6.1/include"
		NO_DEFAULT_PATH
	)
	IF(CMAKE_CL_64)
		FIND_PATH(PSDK_61_LIBRARY_DIRS WSock32.Lib
			PATHS
			${INC_PSDK_61}/lib/x64
			"C:/Program Files/Microsoft SDKs/Windows/v6.1/lib/x64"
		)
	ELSE(CMAKE_CL_64)
		FIND_PATH(PSDK_61_LIBRARY_DIRS WS2_32.Lib
			PATHS
			${INC_PSDK_61}/lib
			"C:/Program Files/Microsoft SDKs/Windows/v6.1/lib"
		)
	ENDIF(CMAKE_CL_64)
	IF(PSDK_61_INCLUDE_DIRS AND PSDK_61_LIBRARY_DIRS)
		SET(PSDK_61_FOUND TRUE)
	ELSE(PSDK_61_INCLUDE_DIRS AND PSDK_61_LIBRARY_DIRS)
		SET(PSDK_61_FOUND FALSE)
	ENDIF(PSDK_61_INCLUDE_DIRS AND PSDK_61_LIBRARY_DIRS)
ENDIF(WIN32)
