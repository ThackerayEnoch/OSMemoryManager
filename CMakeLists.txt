cmake_minimum_required(VERSION 3.28)
project(OperatingSystemWorkQtVersion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:/QtLibrary/6.8.1/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(OperatingSystemWorkQtVersion
        main.cpp
        Sources/mainwindow.cpp
        Headers/mainwindow.h
        Sources/mainwindow.ui
        MemoryManager/AllocationStrategy.h
        MemoryManager/BestFitStrategy.h
        MemoryManager/FirstFitStrategy.h
        MemoryManager/MemoryBlock.h
        MemoryManager/MemoryException.h
        MemoryManager/MemoryManager.cpp
        MemoryManager/MemoryManager.h
        MemoryManager/NextFitStrategy.h
        MemoryManager/WorstFitStrategy.h
        Headers/manageToQt.h
        Sources/manageToQt.cpp
)

target_link_libraries(OperatingSystemWorkQtVersion
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

# 自动复制运行时依赖库和插件
if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    # 复制 Qt 核心库
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach ()
    # 复制平台插件
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    # 复制整个插件目录（推荐）
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${QT_INSTALL_PATH}/plugins"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins")
endif ()
