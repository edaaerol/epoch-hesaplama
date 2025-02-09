Epoch Hesaplama
Bu proje, iki tarih ve zaman arasındaki farkı saniye cinsinden hesaplayan bir C programı içerir. Epoch zamanı, 1 Ocak 1970 00:00:00 UTC'den itibaren geçen toplam saniye sayısıdır. Bu program, kullanıcıdan tarih ve zaman bilgilerini alır ve bu bilgileri Epoch zamanına çevirir.

İçindekiler
Kurulum
Kullanım
Fonksiyonlar
Katkıda Bulunanlar
Lisans
Kurulum

Bu projeyi yerel makinenizde çalıştırmak için aşağıdaki adımları izleyin:

Bu depoyu klonlayın:

git clone https://github.com/edaaerol/epoch-hesaplama.git
Ana dizine gidin:

cd epoch-hesaplama
Programı derleyin:

gcc main.c -o epoch_hesaplama
Kullanım
Programı çalıştırmak için aşağıdaki komutu kullanın:

./epoch_hesaplama

Program çalıştığında, iki farklı tarih ve zaman bilgisi girmenizi isteyecektir. Girdiğiniz değerler doğrulandıktan sonra, program bu tarihleri Epoch zamanına çevirir ve aralarındaki farkı saniye cinsinden hesaplar.

Girdi Örneği:
Code
Ilk tarihi giriniz:
Yil: 2023
Ay (1-12): 5
Gun: 15
Saat: 12
Dakika: 30
Saniye: 45

Ikinci tarihi giriniz:
Yil: 2025
Ay (1-12): 10
Gun: 20
Saat: 14
Dakika: 45
Saniye: 30

Çıktı Örneği:
Ilk tarih epoch: 1684247445
Ikinci tarih epoch: 1760971530
Iki tarih arasindaki fark (saniye): 76724085

Fonksiyonlar
EpochaCevir(struct Tarih tarih, struct Zaman zaman)
Bu fonksiyon, verilen tarih ve zaman bilgilerini Epoch zamanına çevirir.

Parametreler:
struct Tarih tarih: Yıl, ay ve gün bilgilerini içeren struct.
struct Zaman zaman: Saat, dakika ve saniye bilgilerini içeren struct.

Dönüş Değeri:
time_t: Epoch zamanını temsil eden saniye cinsinden değer.

Katkıda Bulunanlar
edaaerol - GitHub Profili

Lisans
Bu proje MIT Lisansı ile lisanslanmıştır. Daha fazla bilgi için LICENSE dosyasına bakın.
