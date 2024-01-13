cmake_minimum_required(VERSION 3.8)

add_executable(libusb_demo "main.cpp")

target_include_directories(libusb_demo PRIVATE ${CMAKE_SOURCE_DIR}/Middleware/libusb/include)
target_link_libraries(libusb_demo ${CMAKE_SOURCE_DIR}/Middleware/libusb/VS2015/MS32/static/getopt.lib)
target_link_libraries(libusb_demo ${CMAKE_SOURCE_DIR}/Middleware/libusb/VS2015/MS32/static/libusb-1.0.lib)