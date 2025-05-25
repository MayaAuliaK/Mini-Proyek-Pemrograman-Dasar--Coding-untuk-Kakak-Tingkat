#include <stdio.h>      // Untuk fungsi input/output (printf, scanf)
#include <stdlib.h>     // Untuk fungsi system("pause")
#include <windows.h>    // Untuk fungsi Sleep() dan Beep(), hanya berjalan di Windows

// Array berisi daftar nama-nama bencana alam
const char* daftarBencana[] = {
    "Gempa Bumi",
    "Tsunami",
    "Gunung Meletus",
    "Banjir",
    "Kebakaran Hutan"
};

// Fungsi untuk menampilkan menu pilihan bencana
void tampilkanMenu() {
    printf("=== SISTEM PERINGATAN DINI BENCANA ALAM ===\n");
    printf("Pilih jenis bencana:\n");
    
    // Loop untuk mencetak semua isi array daftarBencana
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, daftarBencana[i]);
    }

    printf("------------------------------------------\n");
    printf("Masukkan pilihan Anda (1-5): ");
}

// Fungsi untuk menampilkan peringatan dan membunyikan alarm
void alarmBencana(const char* jenis) {
    printf("\nDeteksi %s dalam proses...\n", jenis);
    Sleep(1000); // Delay 1 detik untuk simulasi deteksi

    printf("Data sensor dikonfirmasi...\n");
    Sleep(1000); // Delay lagi untuk kesan real-time

    printf("PERINGATAN: %s TERDETEKSI!!\n", jenis);

    // Loop untuk membunyikan alarm sebanyak 3 kali
    for (int i = 0; i < 3; i++) {
        Beep(1000, 500); // Bunyi dengan frekuensi 1000Hz selama 500ms
        Sleep(500);      // Jeda 0,5 detik antar bunyi
    }

    printf("!!! Segera lakukan evakuasi sesuai prosedur !!!\n\n");
}

int main() {
    int pilihan; // Variabel untuk menyimpan input pengguna

    tampilkanMenu(); // Tampilkan menu pilihan
    scanf("%d", &pilihan); // Ambil input dari pengguna

    // Validasi agar input hanya antara 1 sampai 5
    if (pilihan >= 1 && pilihan <= 5) {
        // Ambil nama bencana dari array berdasarkan input dan kirim ke fungsi alarm
        alarmBencana(daftarBencana[pilihan - 1]);
    } else {
        // Jika input tidak valid, beri peringatan
        printf("Pilihan tidak valid. Silakan jalankan ulang program.\n");
    }

    system("pause"); // Supaya program tidak langsung tertutup setelah dijalankan
    return 0;
}
