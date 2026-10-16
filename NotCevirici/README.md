# 🎓 Not Çevirici ve Hesaplayıcı

Karabük Üniversitesi ve Türkiye genelindeki üniversitelerin 100'lük not sistemine tam uyumlu, masaüstü (GUI) vize/final hesaplama uygulamasıdır. Standart siyah konsol ekranlarına bağlı kalmadan, doğrudan C dili ve Raylib grafik kütüphanesi kullanılarak sıfırdan geliştirilmiştir.

## 🚀 Projenin Amacı ve Özellikleri

Bu proje, temel algoritma mantığını, bellek yönetimini ve kullanıcı girdilerini (input validation) görsel bir arayüzle birleştirerek sorunsuz bir masaüstü deneyimi sunmak için tasarlanmıştır.

* **Dinamik Masaüstü Arayüzü (GUI):** Fare tıklamalarını algılayan, odaklanabilir (focus) metin kutuları ve anlık ekran yenileme.
* **Ağırlıklı Ortalama:** Vize (%40) ve Final (%60) notlarının standartlara uygun hesaplanması.
* **Akıllı Durum Analizi:**
  * **Doğrudan Geçti:** 60 ve üzeri ortalama (Yeşil bildirim).
  * **Koşullu Geçti:** 50 - 59.99 arası ortalama (Sarı bildirim - AGNO bağımlı).
  * **Dersten Kaldı:** 50'nin altındaki ortalamalar (Kırmızı bildirim).
  * **Final Barajı Kontrolü:** Final sınavından 50'nin altında alınması durumunda doğrudan başarısız sayılma kontrolü.
* **Hata Yakalama (Validation):** Kullanıcının 100'den büyük bir değer girmesini anında tespit edip engelleyen sınır kontrol mekanizması.

## 🛠️ Kullanılan Teknolojiler

* **Programlama Dili:** C
* **Grafik Motoru:** Raylib
* **Derleyici:** GCC / MinGW
* **Geliştirme Araçları:** Visual Studio Code, Git

## ⚙️ Kurulum ve Derleme (Windows)

Projeyi kendi ortamınızda derlemek için sisteminizde GCC derleyicisi ve Raylib kütüphanesinin kurulu olması gerekmektedir. 

Arka planda çalışan konsol penceresini gizleyerek (`-mwindows`) doğrudan saf bir Windows masaüstü uygulaması elde etmek için terminalde şu komutu çalıştırabilirsiniz:

```powershell
gcc main.c resource.o -o NotCevirici.exe -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows