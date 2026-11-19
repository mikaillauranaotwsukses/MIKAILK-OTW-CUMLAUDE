
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char magic[4];
    uint32_t version_major;
    uint32_t version_minor;
    uint32_t auth_block_size;
    uint32_t aux_block_size;
    char release_string[16];
} vbmeta_hdr;

int main() {
    vbmeta_hdr hdr;

    char label[50];
    char temp_magic[50];
    char temp_release[64];
    char penanda[50];

    // Membaca penanda awal
    scanf("%s", penanda);

    // Membaca magic
    scanf("%s %s", label, temp_magic);
    memcpy(hdr.magic, temp_magic, 4);

    // Membaca versi mayor
    scanf("%s %u", label, &hdr.version_major);

    // Membaca versi minor
    scanf("%s %u", label, &hdr.version_minor);

    // Membaca ukuran authentication block
    scanf("%s %u", label, &hdr.auth_block_size);

    // Membaca ukuran auxiliary block
    scanf("%s %u", label, &hdr.aux_block_size);

    // Membaca release string
    scanf("%s %s", label, temp_release);
    strncpy(hdr.release_string, temp_release, 16);

    // Membaca penanda akhir
    scanf("%s", penanda);

    // Validasi 1: Magic
    if (strncmp(hdr.magic, "AVB0", 4) != 0) {
        printf("ERROR: Invalid vbmeta magic!\n");
    }

    // Validasi 2: Versi
    else if (hdr.version_major != 1 || hdr.version_minor > 3) {
        printf("ERROR: Unsupported libavb version!\n");
    }

    // Validasi 3: Release string
    else if (hdr.release_string[15] != '\0') {
        printf("ERROR: Release string does not end with NUL!\n");
    }

    // Validasi 4: Ukuran block
    else if (hdr.auth_block_size % 64 != 0 ||
             hdr.aux_block_size % 64 != 0) {
        printf("ERROR: Block size is not a multiple of 64!\n");
    }

    // Semua validasi berhasil
    else {
        uint32_t total = 256 + hdr.auth_block_size + hdr.aux_block_size;

        printf("Release: %s\n", hdr.release_string);
        printf("Version: %u.%u\n", hdr.version_major, hdr.version_minor);
        printf("Auth block: %u bytes\n", hdr.auth_block_size);
        printf("Aux block: %u bytes\n", hdr.aux_block_size);
        printf("Total: %u bytes\n", total);
        printf("STATUS: VBMETA OK\n");
    }

    return 0;
}
