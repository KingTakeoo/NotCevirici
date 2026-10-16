🎓 Not Çevirici ve Hesaplayıcı (C & Raylib)

Üniversite öğrencileri için vize (%40) ve final (%60) notlarını 100'lük sisteme göre hesaplayan, final barajını (50) kontrol eden ve geçme/kalma durumunu anlık gösteren masaüstü (GUI) uygulamasıdır. C dili ve Raylib grafik kütüphanesi kullanılarak geliştirilmiştir.

🚀 Özellikler

Ağırlıklı Ortalama: Vize (%40) ve Final (%60) notlarının hesaplanması.

Final Barajı Kontrolü: Final notu 50'nin altındaysa ortalamaya bakılmaksızın doğrudan kalma uyarısı.

Anlık Arayüz Bildirimleri:

>= 60: Doğrudan Geçti (Yeşil)

50 - 59.99: Koşullu Geçti (Sarı)

< 50: Dersten Kaldı (Kırmızı)

Girdi Güvenliği (Validation): 100'den büyük sayı girilmesi durumunda dinamik hata mesajı (-2.0f hata kodu kontrolü).

Sessiz Çalışma: Arka plan siyah terminal ekranı gizlenmiştir (-mwindows).

🛠️ Kurulum, Derleme ve Çalıştırma Rehberi

Projeyi kendi bilgisayarınızda derlemek, kullanmak veya geliştirmek için sırasıyla aşağıdaki adımları izleyin:

1. Adım: Raylib Kütüphanesini Kurun

Sisteminizde C derleyicisi (GCC/MinGW) ve Raylib kurulu olmalıdır. Kurmak için MSYS2 terminalini açın ve şu komutu çalıştırın:

pacman -S mingw-w64-x86_64-raylib


2. Adım: Projeyi Bilgisayarınıza İndirin

Bağımlılıkları kurduktan sonra PowerShell veya Git Bash açarak projeyi klonlayın ve içine girin:

git clone https://github.com/KULLANICI_ADIN/REPO_ADIN.git
cd REPO_ADIN


3. Adım: Projeyi Derleyin (Kodu .exe Yapma)

Projeyi ikon dosyasıyla (resource.o) birlikte, arkada siyah konsol penceresi açılmadan saf bir arayüz olarak derlemek için PowerShell'de şu komutu çalıştırın:

gcc main.c resource.o -o NotCevirici.exe -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows


Bu komuttan sonra oluşan NotCevirici.exe dosyasına çift tıklayarak programı kullanmaya başlayabilirsiniz.

👨‍💻 Geliştirici

Muhammed Furkan

Karabük Üniversitesi - Yazılım Mühendisliği Öğrencisi
