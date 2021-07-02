cmake_policy(VERSION 3.9)
cmake_minimum_required(VERSION 3.9)

project(platfm VERSION 1.202006261423 LANGUAGES CXX)
#<major>[.<minor>[.<patch>[.<tweak>

if (1)
    set(PclVision_VERSION_MAJOR 2)
    set(PclVision_VERSION_MINOR 202006261423)
endif ()

#set(CMAKE_CXX_STANDARD  17 )
set(CMAKE_CXX_STANDARD  11 )
set(CMAKE_CXX_STANDARD_REQUIRED True)

#------------------qt5 must --------------------
#注意，在一个大工程里，这几个开关一定要尽量放在前面打开，否则有可能会报无法生成ui文件的错误
set(CMAKE_AUTOMOC ON)#自动翻译信号与槽
set(CMAKE_AUTORCC ON)#自动翻译资源文件为cpp文件
set(CMAKE_AUTOUIC ON)#自动翻译界面文件为cpp文件
set(CMAKE_INCLUDE_CURRENT_DIR ON)

##-------------- 自己的库libHello -------------

include_directories(${PROJECT_SOURCE_DIR}/libHello)
#target_link_libraries(hello libhello)
#link_directories(${PROJECT_SOURCE_DIR})
link_directories("${PROJECT_BINARY_DIR}/lib")
link_directories("${PROJECT_BINARY_DIR}/lib")
message("(lk)___________show: PROJECT_SOURCE_DIR____________________  ")
message(${PROJECT_SOURCE_DIR})
message("(lk)___________show: PROJECT_SOURCE_DIR finish ____________  ")

#----------------------------------------version------------------------------
############################################
option(USE_MYMATH "Use tutorial provided math implementation" ON)
#configure_file(TutorialConfig.h.in TutorialConfig.h)
#Since the configured file will be written into the binary tree, we must add that directory to the list of paths to search for include files. Add the following lines to the end of the CMakeLists.txt file:


##-----------------------------------------qt5-------------------------------
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)
message("(0)(lk)________ Qt5 _______:  ")
#FIND_PACKAGE (QT5 REQUIRED)
#INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
ADD_DEFINITIONS(${QT_DEFINITIONS})

find_package(Qt5Widgets)
set(CMAKE_PREFIX_PATH $ENV{QTDIR594})
#find_package(Qt5 COMPONENTS Widgets    Core Gui Qml Quick REQUIRED)
find_package(Qt5 COMPONENTS Core Gui Widgets Qml Quick REQUIRED)
#message(${Qt5Widgets})

INCLUDE_DIRECTORIES("F:/win10/Qt5.12.3/5.12.3/msvc2017/include/QtWidgets")
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Gui)
find_package(Qt5OpenGL)
find_package(Qt5Xml)
message("  find   qt5   finish.\n\n")


#----------------------------------------header soruces -------------------------------
set(HEADERS
        ui/mainwindow.h
        common/commonfunc.h
        tools/mainapp.h
        tools/ToolBasic.h
        test.h
        )

#set(SOURCES
#    main.cpp    mainwindow.cpp    test.h
#    commonfunc.h    mainapp.h    mainwindow.h
#    )

set(RESOURCES
        pro.qrc    #  tools/ToolBase.cpp
#        ToolBasic.cpp ToolBasic.h
        utility/utilities.cpp utility/utilities.h
#        tools/ToolNameLst.cpp
#        tools/toolNames.h
        tools/ToolProducer.cpp
        tools/ToolProducer.h tools/ImageSourceManager.cpp tools/ImageSourceManager.h)

#set(QMLS
#    main.qml
#)


# 搜集指定目录 . 和./MyClass 下的源文件，将输出结果列表储存到变量ALL_SOURCE中
 aux_source_directory(${PROJECT_SOURCE_DIR}/src ALL_SOURCE)
aux_source_directory(./ ALL_SOURCE)
aux_source_directory(./common ALL_SOURCE)
aux_source_directory(./tools ALL_SOURCE)
aux_source_directory(./ui ALL_SOURCE)
aux_source_directory(  utility   ALL_SOURCE)

# 包含进目录 gen_pcd/
include_directories("${PROJECT_BINARY_DIR}")
#ui_mainwindow.h
link_directories("${PROJECT_BINARY_DIR}/lib")

include_directories("${PROJECT_SOURCE_DIR}/libHello")
include_directories("${CMAKE_BINARY_DIR}")
include_directories("${CMAKE_AUTOGEN_ORIGIN_DEPENDS}")
include_directories("${CMAKE_AUTOMOC_COMPILER_PREDEFINES}"    )
include_directories("./" ./common ./tools ./ui   utility)


#------------------------------------ --------------------------------------
qt5_wrap_ui(ui_FILES *.ui)
file(GLOB_RECURSE FORMS "*.ui")
set(Lib_dep_root "F:/win10/pcl191X64/thirdpartx64")
#----------------------opencv -411---cuda10.1------------------------
#    F:\win10\opencv411Origin\build
if (0)
    find_package(OpenCV REQUIRED
            #   PATHS  "${Lib_dep_root}/opencv411x64debug"
            )
    #    set( OpenCV_INCLUDE_DIRS    "${Lib_dep_root}/opencv411x64debug/include" )
    #    set( OpenCV_LIBRARY_DIRS    "${Lib_dep_root}/opencv411x64debug/x64/vc16/lib" )
    include_directories(${OpenCV_INCLUDE_DIRS})
    link_directories(${OpenCV_LIBRARY_DIRS})
    add_definitions(${OpenCV_DEFINITIONS})

    message("opencv info(lk):  ")
    message(${OpenCV_INCLUDE_DIRS})
    message(${OpenCV_LIBRARY_DIRS})
    message(${OpenCV_LIBRARIES})
    foreach (var in ${OpenCV_LIBRARIES})
        message(${var})
    endforeach ()
    message("  find   opencv   finish.\n\n\n")
endif ()

#D:\win10\cv310Vs2015DebugReleaseNoCaffe\x64\vc14\lib
if (MSVC)
    set(dep_lib_path "d:\\win10")
    if (1)
        set(OPencv_base_dir "${dep_lib_path}\\cv341Vs2015Cuda8")
        set(OPencv_base_dir "${dep_lib_path}\\cv310Vs2015DebugReleaseNoCaffePlus")
        # set(OPencv_base_dir  "${dep_lib_path}\\Cv451OpenCLVs2015")
        set(OPencv_base_dir "${dep_lib_path}\\cv3413")
        #    set(OpenCV_DIR  "${OPencv_base_dir}/x64/vc14/lib"  )
        set(OpenCV_DIR "${OPencv_base_dir}/build/x64/vc15/lib")
        set(OpenCV_DIR "${OPencv_base_dir}/build/x64/vc14/lib")
        find_package(OpenCV                EXACT 3.4.13
                #    EXACT 2.4.13.6
                REQUIRED PATHS "${OPencv_base_dir}"
                NO_DEFAULT_PATH
                NO_PACKAGE_ROOT_PATH
                NO_CMAKE_PATH
                NO_CMAKE_ENVIRONMENT_PATH
                NO_SYSTEM_ENVIRONMENT_PATH
                NO_CMAKE_PACKAGE_REGISTRY
                NO_CMAKE_BUILDS_PATH  # Deprecated; does nothing.
                NO_CMAKE_SYSTEM_PATH
                )
        LINK_DIRECTORIES("${OPencv_base_dir}/x64/vc14/lib")
        INCLUDE_DIRECTORIES("${OPencv_base_dir}/include")
    endif ()
    if (1)
        set(eigen_dir "${dep_lib_path}\\DepBundleCVBaseCV451/eigen-3.3.7\\x64\\share\\eigen3\\cmake")
        find_package(EIGEN3 REQUIRED PATHS "${dep_lib_path}\\DepBundleCVBaseCV451/eigen-3.3.7/x64")
        INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIRS})
        INCLUDE_DIRECTORIES("${dep_lib_path}\\DepBundleCVBaseCV451/eigen-3.3.7\\x64\\include\\eigen3")
        add_definitions(${EIGEN3_DEFINITIONS})
    endif ()
elseif (UNIX)
    #REQUIRED
    #set(OpenCV_DIR     ~/installCv3414Ubun2104FullNew/share/OpenCV     )
    #set(Opencv_rot_my   ~/cv3414Bundle/installCv3414Ubun2104FullNew  )
    set(Opencv_rot_my /home/alex/installCv3414Ubun2104FullNew)
    set(OpenCV_DIR ${Opencv_rot_my}/share/OpenCV)
    find_package(opencv PATHS ${Opencv_rot_my}/share/OpenCV)
    include_directories(${Opencv_rot_my}/include
            ${Opencv_rot_my}/include/opencv
            ${Opencv_rot_my}/include/opencv2
            )
    link_directories(${Opencv_rot_my}/lib)

    include_directories("/home/alex/halcon-19.11.0.0-linux/include/halconcpp"
            "/home/alex/halcon-19.11.0.0-linux/include")
    link_directories("/home/alex/halcon-19.11.0.0-linux/lib/x64-linux")
endif ()


include_directories(     thirdPart    )


##--------------------------加子文件夹 添加子库  输出目标文件夹 MathFunctions------------------------
##add_library(libMyMath01 mysqrt.cpp  )
#if(USE_MYMATH)
#    add_subdirectory(MathFunctions)
#    list(APPEND EXTRA_LIBS MathFunctions)
#    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
#endif()

#-----------------------------------------添加子文件夹，不添加子库--------------------------------------------------
# 用include 和 aux_source_directory allsource
link_directories("${PROJECT_BINARY_DIR}/lib")

#--------------------------------------------project------------------------------------------------------
##################################### ########################################################
#----------------------------------------------
if (0)
    #add_library( aa.lib   SHARED   ${HEADERS} ${SOURCES} ${FORMS} )  # ALL_SOURCE
    add_library(aa.lib SHARED ${HEADERS} ${ALL_SOURCE} ${FORMS})  # ALL_SOURCE
    target_link_libraries(aa.lib PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Qml Qt5::Quick
            ${PCL_LIBRARIES} ${BOOST_LIBRARIES} ${VTK_LIBRARIES}
            libboost_atomic-vc141-mt-gd-x32-1_68
            ${EXTRA_LIBS}
            ${OpenCL_LIBRARIES}
            ${GLFW3_LIBRARIES}
            ${CUDA_LIBRARIES}
            OpenCL cuda cudadevrt cudart
            ${VULKAN_LIBRARIES}
            #  ${glew_LIBRARIES}
            ${freeglut_LIBRARIES}
            glew32d
            )
endif ()

if (UNIX)
    set(LIBS_RELATED ${OpenCV_LIBS}
            libopencv_core.so libopencv_highgui.so libopencv_imgcodecs.so
            libopencv_imgproc.so libopencv_videoio.so libopencv_ml.so
            libopencv_features2d.so libopencv_flann.so libopencv_objdetect.so
            #    -lpng  -lthread -ljpeg  -lpng16
            #     nlohmann_json::nlohmann_json
            #     tinyxml2::tinyxml2
            #     glog::glog
            -lhalconcpp -lhalcon -lXext -lX11 -ldl -lpthread)
elseif (MSVC)
    set(LIBS_RELATED ${OpenCV_LIBS}
            libopencv_core.so libopencv_highgui.so libopencv_imgcodecs.so
            libopencv_imgproc.so libopencv_videoio.so libopencv_ml.so
            libopencv_features2d.so libopencv_flann.so libopencv_objdetect.so
            #    -lpng  -lthread -ljpeg  -lpng16
            #     nlohmann_json::nlohmann_json
            #     tinyxml2::tinyxml2
            #     glog::glog
            -lhalconcpp -lhalcon -lXext -lX11 -ldl -lpthread)
endif ()

######################################生成exe#######################################################
#set(EXECUTABLE_OUTPUT_PATH   ${PROJECT_BINARY_DIR}/../bin)
#set(LIBARARY_OUTPUT_PATH   ${PROJECT_BINARY_DIR}/../lib )
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)


add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES} ${ALL_SOURCE} ${FORMS} ${RESOURCES} ${HEADERS})

# ${EXTRA_LIBS}
if (1)
    target_link_libraries(${PROJECT_NAME}
            Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Qml Qt5::Quick
             ${EXTRA_LIBS}
             ${OpenCV_LIBRARIES} ${LIBS_RELATED}
            )
endif ()


message("(6)(lk)__________ project ___________:  ")
message("project info(lk):  ")
message(${PROJECT_NAME})
#message( ${HEADERS})
#message( ${SOURCES})
#message( ${ALL_SOURCE})
#message( ${FORMS} )


#------------------------------------------- version ------------------------------------------------
include_directories(${PROJECT_BINARY_DIR}
        ${PROJECT_SOURCE_DIR}/MathFunctions
        ${PROJECT_SOURCE_DIR}/gen_kcd
        ${PROJECT_SOURCE_DIR}/usages
        ${OpenCL_INCLUDE_DIRS}

        )
#PclVision
target_include_directories(${PROJECT_NAME} PUBLIC
        ${PROJECT_BINARY_DIR}
        ${EXTRA_INCLUDES})


#-------------------install  destation ---------------------------
#set( DESTINATION  "../install/")
set(CMAKE_INSTALL_PREFIX "../install/")
#          And to the end of the top-level CMakeLists.txt we add:
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
#install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"  DESTINATION include  )


if (0)
    include(GNUInstallDirs)
    install(
            TARGETS
            ${PROJECT_NAME}
            EXPORT
            ${PROJECT_NAME}Targets
            LIBRARY DESTINATION
            ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION
            ${CMAKE_INSTALL_BINDIR}
            ARCHIVE DESTINATION
            ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION
            include
            PUBLIC_HEADER DESTINATION
            include
    )

    install(
            EXPORT
            ${PROJECT_NAME}Targets
            FILE
            ${PROJECT_NAME}Targets.cmake
            NAMESPACE
            ${PROJECT_NAME}::
            DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    )

    #
    # Add version header
    #

    configure_file(
            ${CMAKE_CURRENT_LIST_DIR}/cmake/version.hpp.in
            include/${PROJECT_NAME_LOWERCASE}/version.hpp
            @ONLY
    )

    install(
            FILES
            ${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME_LOWERCASE}/version.hpp
            DESTINATION
            include/${PROJECT_NAME_LOWERCASE}
    )

    #
    # Install the `include` directory
    #

    install(
            DIRECTORY
            #    include/${PROJECT_NAME_LOWERCASE}
            interfaceA/${PROJECT_NAME_LOWERCASE}
            DESTINATION
            include
    )

    #verbose_message("Install targets succesfully build. Install with `cmake --build <build_directory> --target install --config <build_config>`.")

    #
    # Quick `ConfigVersion.cmake` creation
    #

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            ${PROJECT_NAME}ConfigVersion.cmake
            VERSION
            ${PROJECT_VERSION}
            COMPATIBILITY
            SameMajorVersion
    )

    configure_package_config_file(
            ${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            INSTALL_DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    )

    install(
            FILES
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
            DESTINATION
            ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
    )

    #
    # Generate export header if specified
    #

    if (${PROJECT_NAME}_GENERATE_EXPORT_HEADER)
        include(GenerateExportHeader)
        generate_export_header(${PROJECT_NAME})
        install(
                FILES
                ${PROJECT_BINARY_DIR}/${PROJECT_NAME_LOWERCASE}_export.h
                DESTINATION
                include

        )

        message(STATUS "Generated the export header `${PROJECT_NAME_LOWERCASE}_export.h` and installed it.")
    endif ()

    message(STATUS "Finished building requirements for installing the package.\n")

    #
    # Unit testing setup
    #
    if (0)
        if (${PROJECT_NAME}_ENABLE_UNIT_TESTING)
            enable_testing()
            message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
            add_subdirectory(test)
        endif ()
    endif ()


endif ()


