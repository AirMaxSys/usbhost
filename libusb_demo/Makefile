TARGET = libusb_demo
CC = g++

INC_DIR = ../Middleware/libusb/MinGW64/include/libusb-1.0
LIB_DIR = ../Middleware/libusb/MinGW64/static/libusb-1.0
LIB = libusb-1.0

SRC = main.cpp

all:
	$(CC) -o $(TARGET) $(SRC) -I$(INC_DIR) -L$(LIB_DIR) -l$(LIB)

.PHONY:clean

clean:
	@del $(TARGET).exe a.exe
