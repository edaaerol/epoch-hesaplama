#include <stdio.h>
#include <time.h>

// Tarih bilgilerini tutacak struct
struct Date {
    int year;
    int month;
    int day;
};

// Saat bilgilerini tutacak struct
struct Time {
    int hour;
    int minute;
    int second;
};

// Tarih ve saat bilgilerini birlestiren union
union DateTime {
    struct {
        struct Date date;
        struct Time time;
    } dt;
    time_t epoch;
};

// Tarih ve saat bilgilerini epoch'a ceviren fonksiyon
time_t convertToEpoch(struct Date date, struct Time time) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = date.year - 1900;  // tm_year 1900'den baslar
    timeinfo.tm_mon = date.month - 1;     // tm_mon 0'dan baslar
    timeinfo.tm_mday = date.day;
    timeinfo.tm_hour = time.hour;
    timeinfo.tm_min = time.minute;
    timeinfo.tm_sec = time.second;
    
    return mktime(&timeinfo);
}

int main() {
    union DateTime dt1, dt2;
    
    printf("EPOCH ZAMANI VE TARIH FARKI HESAPLAYICI \n\n");
    
   /* Epoch nedir?
   Epoch (Unix zamani), 1 Ocak 1970 00:00:00 UTC'den bu yana gecen saniye sayisidir.
   Bu, bilgisayar sistemlerinde zamani temsil etmek icin kullanilan standart bir yontemdir. */
    
    // Ilk tarih icin giris
    printf("Ilk tarihi giriniz:\n");
    printf("Yil: ");
    scanf("%d", &dt1.dt.date.year);
    printf("Ay (1-12): ");
    scanf("%d", &dt1.dt.date.month);
    printf("Gun: ");
    scanf("%d", &dt1.dt.date.day);
    printf("Saat: ");
    scanf("%d", &dt1.dt.time.hour);
    printf("Dakika: ");
    scanf("%d", &dt1.dt.time.minute);
    printf("Saniye: ");
    scanf("%d", &dt1.dt.time.second);
    
    // Ikinci tarih icin giris
    printf("\nIkinci tarihi giriniz:\n");
    printf("Yil: ");
    scanf("%d", &dt2.dt.date.year);
    printf("Ay (1-12): ");
    scanf("%d", &dt2.dt.date.month);
    printf("Gun: ");
    scanf("%d", &dt2.dt.date.day);
    printf("Saat: ");
    scanf("%d", &dt2.dt.time.hour);
    printf("Dakika: ");
    scanf("%d", &dt2.dt.time.minute);
    printf("Saniye: ");
    scanf("%d", &dt2.dt.time.second);
    
    // Tarihleri epoch'a cevirme
    time_t epoch1 = convertToEpoch(dt1.dt.date, dt1.dt.time);
    time_t epoch2 = convertToEpoch(dt2.dt.date, dt2.dt.time);
    
    // Sonuclari yazdirma
    printf("\n SONUCLAR \n");
    printf("Ilk tarih epoch degeri: %ld\n", (long)epoch1);
    printf("Ikinci tarih epoch degeri: %ld\n", (long)epoch2);
    printf("Iki tarih arasindaki fark (saniye): %ld\n", (long)difftime(epoch2, epoch1));
    
    // Farki gun, saat, dakika ve saniye olarak gosterme
    long diff = labs((long)difftime(epoch2, epoch1));
    int days = diff / (24 * 3600);
    int hours = (diff % (24 * 3600)) / 3600;
    int minutes = (diff % 3600) / 60;
    int seconds = diff % 60;
    
    printf("Fark: %d gun, %d saat, %d dakika, %d saniye\n", 
           days, hours, minutes, seconds);
    
    return 0;
}
