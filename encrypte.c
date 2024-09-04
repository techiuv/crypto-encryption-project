#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_file(const char *input_file, const char *output_file, const char *key) {
    FILE *fin = fopen(input_file, "rb");
    if (!fin) {
        fprintf(stderr, "Error: Cannot open input file '%s' for reading.\n", input_file);
        exit(EXIT_FAILURE);
    }

    FILE *fout = fopen(output_file, "wb");
    if (!fout) {
        fprintf(stderr, "Error: Cannot open output file '%s' for writing.\n", output_file);
        fclose(fin);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t n;
    size_t key_len = strlen(key);

    while ((n = fread(buffer, 1, BUFFER_SIZE, fin)) > 0) {
        for (size_t i = 0; i < n; ++i) {
            buffer[i] ^= key[i % key_len];  // Enhanced XOR with dynamic key
        }
        if (fwrite(buffer, 1, n, fout) != n) {
            fprintf(stderr, "Error: Writing to output file '%s' failed.\n", output_file);
            fclose(fin);
            fclose(fout);
            exit(EXIT_FAILURE);
        }
    }

    if (ferror(fin)) {
        fprintf(stderr, "Error: Reading from input file '%s' failed.\n", input_file);
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    encrypt_file(argv[1], argv[2], argv[3]);

    printf("File encrypted successfully: %s -> %s\n", argv[1], argv[2]);
    return 0;
}
