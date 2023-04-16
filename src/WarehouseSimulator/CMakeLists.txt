cmake_minimum_required(VERSION 3.24)
project(WarehouseSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.4.2/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(WarehouseSimulator main.cpp qtWidgetUI/mainwindow.cpp qtWidgetUI/mainwindow.h qtWidgetUI/mainwindow.ui businessLogic/products/product.cpp businessLogic/products/product.h businessLogic/enums/sizes.h qtWidgetUI/productcreator.cpp qtWidgetUI/productcreator.h qtWidgetUI/productcreator.ui businessLogic/products/gamingconsole.cpp businessLogic/products/gamingconsole.h businessLogic/enums/products.h qtWidgetUI/customWidgets/productwidget.cpp qtWidgetUI/customWidgets/productwidget.h qtWidgetUI/events/clickhandler.h businessLogic/enums/accesspolicies.h businessLogic/wardrobe.cpp businessLogic/wardrobe.h businessLogic/products/gamepad.cpp businessLogic/products/gamepad.h businessLogic/products/tv.cpp businessLogic/products/tv.h businessLogic/products/keyboard.cpp businessLogic/products/keyboard.h businessLogic/storagebox.cpp businessLogic/storagebox.h businessLogic/helpers/imagehelper.cpp businessLogic/helpers/imagehelper.h)
target_link_libraries(WarehouseSimulator
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (WIN32)
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
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
