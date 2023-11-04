TARGET = libusb_demo
CC = g++


INC_DIR = I:\\software\\libusb-1.0.26-binaries\\libusb-MinGW-x64\\include\\libusb-1.0
LIB_DIR = I:\\software\\libusb-1.0.26-binaries\\libusb-MinGW-x64\\lib
LIB = usb-1.0

SRC =.\\main.cpp

all:
	$(CC) -o $(TARGET) $(SRC) -I$(INC_DIR) -L$(LIB_DIR) -l$(LIB)

.PHONY:clean

clean:
	@del $(TARGET).exe a.exe
