
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char magic[8];
    uint32_t kernel_size;
    uint32_t kernel_addr;
    uint32_t ramdisk_size;
    uint32_t ramdisk_addr;
    char board_name[16];
} boot_img_hdr;

int main() {
    boot_img_hdr hdr;

    char label[30];
    char magicInput[20];

    uint32_t kernel_end;
    uint32_t ramdisk_end;
    uint64_t total;

    scanf("%s", label);

    scanf("%s %s", label, magicInput);
    memcpy(hdr.magic, magicInput, 8);

    scanf("%s %u", label, &hdr.kernel_size);
    scanf("%s %x", label, &hdr.kernel_addr);

    scanf("%s %u", label, &hdr.ramdisk_size);
    scanf("%s %x", label, &hdr.ramdisk_addr);

    scanf("%s %s", label, hdr.board_name);

    scanf("%s", label);

    if (strncmp(hdr.magic, "ANDROID!", 8) != 0) {
        printf("ERROR: Invalid boot magic!\n");
        return 0;
    }

    kernel_end = hdr.kernel_addr + hdr.kernel_size;
    ramdisk_end = hdr.ramdisk_addr + hdr.ramdisk_size;

    total = (uint64_t)hdr.kernel_size + hdr.ramdisk_size;

    printf("Board: %s\n", hdr.board_name);

    printf("Kernel: 0x%08X - 0x%08X (%u bytes)\n",
           hdr.kernel_addr, kernel_end, hdr.kernel_size);

    printf("Ramdisk: 0x%08X - 0x%08X (%u bytes)\n",
           hdr.ramdisk_addr, ramdisk_end, hdr.ramdisk_size);

    printf("Total: %llu bytes\n", (unsigned long long)total);

    if (hdr.kernel_addr < ramdisk_end &&
        hdr.ramdisk_addr < kernel_end) {
        printf("STATUS: BOOT FAILED (kernel overlaps ramdisk)\n");
    } else {
        printf("STATUS: BOOT OK\n");
    }

    return 0;
}
