# Epoch Zamanı Hesaplama Programı  

Bu proje, iki tarih ve zaman arasındaki farkı saniye cinsinden hesaplayan bir C programı içerir.  
Epoch zamanı, 1 Ocak 1970 00:00:00 UTC'den itibaren geçen toplam saniye sayısıdır.  

## İçindekiler  

- [Kurulum ve Çalıştırma](#kurulum-ve-çalıştırma)  
- [Örnek Kullanım](#örnek-kullanım)  
- [Fonksiyonlar](#fonksiyonlar)  
- [Katkıda Bulunanlar](#katkıda-bulunanlar)  
- [Lisans](#lisans)  

## Kurulum ve Çalıştırma  

1. C derleyicinizin kurulu olduğundan emin olun.  
GCC kullanıyorsanız aşağıdaki komutla programı derleyebilirsiniz:  

```sh
gcc epoch_hesaplama.c -o epoch_hesaplama
```

Programı çalıştırın:
```sh
./epoch_hesaplama
```
Program çalıştırıldığında, sizden iki farklı tarih ve saat girmenizi isteyecektir.
Girilen veriler doğrulandıktan sonra Epoch zamanına dönüştürülerek aralarındaki fark hesaplanacaktır.

## Örnek Kullanım
Girdi Örneği:
```sh
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
``` 
Çıktı Örneği:
```sh
Ilk tarih epoch: 1684247445  
Ikinci tarih epoch: 1760971530  
Iki tarih arasindaki fark (saniye): 76724085
```

## Fonksiyonlar
`time_t EpochaCevir(struct Tarih tarih, struct Zaman zaman)`
Bu fonksiyon, girilen tarih ve zaman bilgilerini alarak Epoch zamanına çevirir.

## Parametreler
`struct Tarih tarih` → Yıl, ay ve gün bilgilerini içerir.
`struct Zaman zaman` → Saat, dakika ve saniye bilgilerini içerir.

## Dönüş Değeri
`time_t` → Epoch zamanını temsil eden saniye cinsinden değer döndürür.

## Katkıda Bulunanlar 
- [edaaerol](https://github.com/edaaerol)

## Lisans
Bu proje MIT Lisansı altında lisanslanmıştır.
Daha fazla bilgi için [LICENSE](LICENSE) dosyasına göz atabilirsiniz.
