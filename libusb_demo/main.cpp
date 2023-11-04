#include "libusb.h"
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <iostream>

#define MAX_BUF_SZ  256

int main(int argc, char *argv[])
{
    libusb_context *ctx = NULL;
    libusb_device **devs;
    ssize_t lst_cnt = 0;

    assert(libusb_init(&ctx) == 0);

    // libusb device list end with NULL pointer
    lst_cnt = libusb_get_device_list(ctx, &devs);
    if (lst_cnt < 0) {
        libusb_exit(ctx);
        return -1;
    }
    std::cout << "device list number:" << lst_cnt << std::endl;

    // do something print devices
    for (int i = 0; i < lst_cnt - 1; ++i) {
        int ret  = 0;
        unsigned char buffer[MAX_BUF_SZ];
        libusb_device_handle *handle; 
        struct libusb_device_descriptor desc;

        // open device and get libusb handler
        ret = libusb_open(devs[i], &handle);
        if (ret < 0) {
            fprintf(stderr, "open device[%d]:%s\n", i, libusb_strerror(ret));
            continue;
        }

        // Get USB device descriptor
        ret = libusb_get_device_descriptor(devs[i], &desc);
        if (ret < 0) {
            fprintf(stderr, "get device descriptor error\n");
            libusb_exit(ctx);
            return -1;
        }

        // Get manufacture strings
        printf("[0x%04x,0x%04x]:", desc.idVendor, desc.idProduct);
        libusb_get_string_descriptor_ascii(handle, desc.iManufacturer, buffer, MAX_BUF_SZ);
        printf("%s\t", buffer);
        libusb_get_string_descriptor_ascii(handle, desc.iProduct, buffer, MAX_BUF_SZ);
        printf("%s\n", buffer);
    }

    // free devices
    libusb_free_device_list(devs, 1);

    libusb_exit(ctx);

    return 0;
}
