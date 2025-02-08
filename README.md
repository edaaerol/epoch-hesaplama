#EPOCH Zaman Hesaplayıcı

Bu proje, iki farklı tarih ve saat bilgisini alarak bunları Unix epoch zamanına çevirir ve aralarındaki farkı hesaplar.


Kullanım

Programı çalıştırın.

İlk tarih ve saat bilgilerini girin.

İkinci tarih ve saat bilgilerini girin.

Program, girilen tarihleri epoch zamanına çevirerek iki tarih arasındaki farkı saniye cinsinden hesaplar ve ekrana yazdırır.


Yapı

struct Tarih: Yıl, ay ve günü tutar.

struct Zaman: Saat, dakika ve saniyeyi tutar.

union TarihZaman: Hem tarih/saat bilgilerini hem de epoch zamanını tek bir bellekte saklar.

EpochaCevir(): Tarih ve saat bilgisini epoch zamanına çevirir.


Notlar

Yıl 1970'ten küçük olamaz.

Ay 1 ile 12 arasında olmalıdır.

Gün 1 ile 31 arasında olmalıdır.

Saat 0 ile 23 arasında olmalıdır.

Dakika ve saniye 0 ile 59 arasında olmalıdır.

