#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // variabel untuk mencatat waktu mulai dan selesai
    clock_t start_time, end_time;
    double execution_time;

    // Variabel untuk file input dan output serta operasi
    FILE *inputFile, *outputFile;
    char operator;  // Untuk menyimpan operator ('+', '-', '*', '/')
    double ang1, ang2, hasil;
    int masukkan; // Untuk menyimpan hasil pembacaan operator yang sebelumnya

    // Catat waktu mulai
    start_time = clock();

    // Membuka file input_7.txt untuk membaca
    inputFile = fopen("input_7.txt", "r");
    if (inputFile == NULL) {
        printf("File input_7.txt tidak dapat dibuka!\n");
        return 1;
    }

    // Membuka atau membuat file output_7.txt untuk menulis
    outputFile = fopen("output_7.txt", "w");
    if (outputFile == NULL) {
        printf("File output_7.txt tidak dapat dibuat!\n");
        fclose(inputFile);
        return 1;
    }

    // Membaca setiap baris dari file input dan memproses operasinya
    while (fscanf(inputFile, "%lf %c %lf", &ang1, &operator, &ang2) == 3) {  // Perbaikan untuk format pembacaan
       
        
        // Memeriksa operator dan melakukan operasi
        if (operator == '+') { // Penjumlahan
            hasil = ang1 + ang2;
            // Menulis hasil ke file output
            fprintf(outputFile, "%.4f + %.4f = %.4f\n", ang1, ang2, hasil);
        } 
        else if (operator == '-') { // Pengurangan
            hasil = ang1 - ang2;
         
            // Menulis hasil ke file output
            fprintf(outputFile, "%.4f - %.4f = %.4f\n", ang1, ang2, hasil);
        } 
        else if (operator == '*') { // Perkalian
            hasil = ang1 * ang2;
          
            // Menulis hasil ke file output
            fprintf(outputFile, "%.4f * %.4f = %.4f\n", ang1, ang2, hasil);
        } 
        else if (operator == '/') { // Pembagian
            // Pembagian dengan nol
            if (ang2 != 0) {
                hasil = ang1 / ang2;
               
                // Menulis hasil ke file output
                fprintf(outputFile, "%.4f / %.4f = %.4f\n", ang1, ang2, hasil);
            } else {
                // Menulis error ke file output
                fprintf(outputFile, " %.4f / %.4f = Error! Pembagian dengan nol.\n", ang1, ang2);
            }
        }
        else {
            fprintf(outputFile, "%.4f ^ %.4f = Error: Operator tidak valid\n", ang1, ang2);
        }
    }

    // Menutup file setelah selesai
    fclose(inputFile);
    fclose(outputFile);

    // Catat waktu selesai
    end_time = clock();

    // Hitung waktu eksekusi dalam detik
    execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Menampilkan waktu eksekusi
    printf("Proses selesai. Hasil disimpan di output_7.txt\n");
    printf("Waktu eksekusi: %.4f detik\n", execution_time);

    return 0;
}
