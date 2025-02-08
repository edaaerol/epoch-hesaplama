#include <stdio.h>
#include <time.h>

// tarih bilgilerini tutacak struct 
struct Tarih{
	int yil,ay,gun;
	
};

// saat bilgilerini tutacak struct 
struct Zaman{
	int saat,dakika,saniye;
	
};


// Tarih ve saat bilgilerini birlestiren union
// Bu union, iki farklı veri temsilini aynı bellek alanında saklamayı sağlıyor:
union TarihZaman{
	struct{
		struct Tarih tarih;
		struct Zaman zaman;
		
	} tarihZaman;
	
	time_t epoch; // time_t, zamana dair bilgileri saniye cinsinden saklayan bir veri türüdür.
	// Epoch zamanı, 1 Ocak 1970 00:00:00 UTC'den itibaren geçen toplam saniye sayısıdır.
};

// Tarih ve saat bilgilerini epoch'a çeviren fonksiyon
time_t EpochaCevir(struct Tarih tarih, struct Zaman zaman) {
    struct tm tm_zaman;
    
    tm_zaman.tm_year = tarih.yil - 1900; // Yıl 1900'den itibaren hesaplanır
    tm_zaman.tm_mon = tarih.ay - 1;      // Ay 0'dan başlar, 1 çıkarılır
    tm_zaman.tm_mday = tarih.gun;
    tm_zaman.tm_hour = zaman.saat;
    tm_zaman.tm_min = zaman.dakika;
    tm_zaman.tm_sec = zaman.saniye;
    
    return mktime(&tm_zaman); // mktime ile epoch zamanına çevir
}

int main(){
	union TarihZaman tarihZaman1, tarihZaman2;
	
	
    printf("EPOCH ZAMANI VE TARIH FARKI HESAPLAYICI \n\n");
    
	/* Epoch nedir?
   Epoch (Unix zamani), 1 Ocak 1970 00:00:00 UTC'den bu yana gecen saniye sayisidir.
   Bu, bilgisayar sistemlerinde zamani temsil etmek icin kullanilan standart bir yontemdir. */
    
    // Ilk tarih icin giris
    printf("Ilk tarihi giriniz:\n");
    
    printf("Yil: ");
    scanf("%d", &tarihZaman1.tarihZaman.tarih.yil); 
	if (tarihZaman1.tarihZaman.tarih.yil < 1970) {
        printf("Hata! Yil 1970'ten kucuk olamaz! Tekrar deneyiniz! \n");
    }
    
    printf("Ay (1-12): ");
    scanf("%d", &tarihZaman1.tarihZaman.tarih.ay);
    if (tarihZaman1.tarihZaman.tarih.ay < 1 || tarihZaman1.tarihZaman.tarih.ay > 12) {
        printf("Hata! Ay 1 ile 12 arasinda olmalidir! Tekrar deneyiniz! \n");
    }
    
    printf("Gun: ");
    scanf("%d", &tarihZaman1.tarihZaman.tarih.gun);
     if (tarihZaman1.tarihZaman.tarih.gun < 1 || tarihZaman1.tarihZaman.tarih.gun > 31) {
        printf("Hata! Gun 1 ile 31 arasinda olmalidir! Tekrar deneyiniz! \n");
    }
    
    printf("Saat: ");
    scanf("%d", &tarihZaman1.tarihZaman.zaman.saat);
	if (tarihZaman1.tarihZaman.zaman.saat < 0 || tarihZaman1.tarihZaman.zaman.saat > 23) {
        printf("Hata! Saat 0 ile 23 arasinda olmalidir! Tekrar deneyiniz! \n");
    }
    
    printf("Dakika: ");
    scanf("%d", &tarihZaman1.tarihZaman.zaman.dakika);
	if (tarihZaman1.tarihZaman.zaman.dakika < 0 || tarihZaman1.tarihZaman.zaman.dakika > 59) {
        printf("Hata! Dakika 0 ile 59 arasinda olmalidir! Tekrar deneyiniz! \n");
    }
    
    printf("Saniye: ");
    scanf("%d", &tarihZaman1.tarihZaman.zaman.saniye);
    if (tarihZaman1.tarihZaman.zaman.saniye < 0 || tarihZaman1.tarihZaman.zaman.saniye > 59) {
        printf("Hata! Saniye 0 ile 59 arasinda olmalidir!Tekrar deneyiniz! \n");
    }
    
    // Ikinci tarih icin giris
    printf("\nIkinci tarihi giriniz:\n");
    
    printf("Yil: ");
    scanf("%d", &tarihZaman2.tarihZaman.tarih.yil);
    if (tarihZaman1.tarihZaman.tarih.yil < 1970) {
        printf("Hata! Yil 1970'ten kucuk olamaz! Tekrar deneyiniz! \n");
    }
    
    printf("Ay (1-12): ");
    scanf("%d", &tarihZaman2.tarihZaman.tarih.ay);
    if (tarihZaman1.tarihZaman.tarih.ay < 1 || tarihZaman1.tarihZaman.tarih.ay > 12) {
        printf("Hata! Ay 1 ile 12 arasinda olmalidir! Tekrar deneyiniz! \n");
    }
    
    printf("Gun: ");
    scanf("%d", &tarihZaman2.tarihZaman.tarih.gun);
     if (tarihZaman1.tarihZaman.tarih.gun < 1 || tarihZaman1.tarihZaman.tarih.gun > 31) {
        printf("Hata! Gun 1 ile 31 arasinda olmalidir! Tekrar deneyiniz! \n");
    }
    
    printf("Saat: ");
    scanf("%d", &tarihZaman2.tarihZaman.zaman.saat);
	if (tarihZaman1.tarihZaman.zaman.saat < 0 || tarihZaman1.tarihZaman.zaman.saat > 23) {
        printf("Hata! Saat 0 ile 23 arasinda olmalidir! Tekrar deneyiniz! \n");
    }
    
    
    
    printf("Dakika: ");
    scanf("%d", &tarihZaman2.tarihZaman.zaman.dakika);    
	if (tarihZaman1.tarihZaman.zaman.dakika < 0 || tarihZaman1.tarihZaman.zaman.dakika > 59) {
        printf("Hata! Dakika 0 ile 59 arasinda olmalidir! Tekrar deneyiniz! \n");
    }
    
    printf("Saniye: ");
    scanf("%d", &tarihZaman2.tarihZaman.zaman.saniye);
    if (tarihZaman1.tarihZaman.zaman.saniye < 0 || tarihZaman1.tarihZaman.zaman.saniye > 59) {
        printf("Hata! Saniye 0 ile 59 arasinda olmalidir!Tekrar deneyiniz! \n");
    }
    
    // Tarihleri epoch'a çevirme  
    tarihZaman1.epoch = EpochaCevir(tarihZaman1.tarihZaman.tarih, tarihZaman1.tarihZaman.zaman);
    tarihZaman2.epoch = EpochaCevir(tarihZaman2.tarihZaman.tarih, tarihZaman2.tarihZaman.zaman);

    // Epoch farkını hesaplama  
    time_t fark = difftime(tarihZaman2.epoch, tarihZaman1.epoch);

    printf("\nIlk tarih epoch: %lld\n", (long long)tarihZaman1.epoch);
    printf("Ikinci tarih epoch: %lld\n", (long long)tarihZaman2.epoch);
    printf("Iki tarih arasindaki fark (saniye): %lld\n", (long long)fark);

    
}

