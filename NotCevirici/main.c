#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "Not Hesaplama Programi");
    SetTargetFPS(60);

    Image ikonResmi = LoadImage("ikonlar/kucukikon.png");
    if (ikonResmi.data != NULL) {
        SetWindowIcon(ikonResmi);
        UnloadImage(ikonResmi);
    }

    Font benimFontum = LoadFont("Fontlar/arial.ttf");

    Rectangle vizeBox = { 330, 150, 140, 50 };
    Rectangle finalBox = { 330, 230, 140, 50 };

    char vizeText[10] = "\0";
    char finalText[10] = "\0";
    int vizeCount = 0;
    int finalCount = 0;
    int activeBox = 0;
    
    float ortalama = -1.0f;
    char durumMetni[60] = "";
    Color durumRengi = GRAY;

    Color arkaPlan = { 18, 18, 18, 255 };
    Color kutuRengi = { 37, 37, 37, 255 };
    Color altinSarisi = { 212, 175, 55, 255 };
    Color yesilRenk = { 46, 204, 113, 255 };
    Color kirmiziRenk = { 231, 76, 60, 255 };

    while (!WindowShouldClose()) {
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            if (CheckCollisionPointRec(mouse, vizeBox)) {
                activeBox = 1;
            } else if (CheckCollisionPointRec(mouse, finalBox)) {
                activeBox = 2;
            } else {
                activeBox = 0;
            }
        }

        int key = GetCharPressed();
        while (key > 0) {
            if ((key >= '0' && key <= '9') || key == '.') {
                if (activeBox == 1 && vizeCount < 3) {
                    vizeText[vizeCount] = (char)key;
                    vizeText[vizeCount + 1] = '\0';
                    vizeCount++;
                } else if (activeBox == 2 && finalCount < 3) {
                    finalText[finalCount] = (char)key;
                    finalText[finalCount + 1] = '\0';
                    finalCount++;
                }
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            if (activeBox == 1 && vizeCount > 0) {
                vizeCount--;
                vizeText[vizeCount] = '\0';
            } else if (activeBox == 2 && finalCount > 0) {
                finalCount--;
                finalText[finalCount] = '\0';
            }
        }

if (vizeCount > 0 && finalCount > 0) {
            float vize = atof(vizeText);
            float final = atof(finalText);
            
            if (vize > 100 || final > 100) {
                ortalama = -2.0f;
            }
            else { 
                ortalama = (vize * 0.40f) + (final * 0.60f);

                if (final < 50.0f) {
                    strcpy(durumMetni, "Kaldi");
                    durumRengi = kirmiziRenk;
                } else if (ortalama >= 60.0f) {
                    strcpy(durumMetni, "Dogrudan Gecti");
                    durumRengi = yesilRenk;
                } else if (ortalama >= 50.0f) {
                    strcpy(durumMetni, "Kosullu Gecti");
                    durumRengi = altinSarisi;
                } else {
                    strcpy(durumMetni, "Dersten Kaldi");
                    durumRengi = kirmiziRenk;
                }
            }
        }
        else {
            ortalama = -1.0f;
        }
        BeginDrawing();
            ClearBackground(arkaPlan);

            DrawTextEx(benimFontum, "NOT HESAPLAMA PROGRAMI", (Vector2){ 220, 50 }, 28, 2, altinSarisi);

            DrawTextEx(benimFontum, "Vize Notu:", (Vector2){ 180, 160 }, 22, 1, RAYWHITE);
            DrawRectangleRec(vizeBox, kutuRengi);
            DrawRectangleLinesEx(vizeBox, 2, (activeBox == 1) ? altinSarisi : GRAY);
            DrawTextEx(benimFontum, vizeText, (Vector2){ vizeBox.x + 15, vizeBox.y + 12 }, 22, 1, RAYWHITE);

            DrawTextEx(benimFontum, "Final Notu:", (Vector2){ 180, 240 }, 22, 1, RAYWHITE);
            DrawRectangleRec(finalBox, kutuRengi);
            DrawRectangleLinesEx(finalBox, 2, (activeBox == 2) ? altinSarisi : GRAY);
            DrawTextEx(benimFontum, finalText, (Vector2){ finalBox.x + 15, finalBox.y + 12 }, 22, 1, RAYWHITE);

            if (ortalama >= 0.0f) {
                DrawTextEx(benimFontum, TextFormat("Ortalama: %.2f", ortalama), (Vector2){ 200, 330 }, 26, 1, RAYWHITE);
                DrawTextEx(benimFontum, TextFormat("Durum: %s", durumMetni), (Vector2){ 200, 370 }, 22, 1, durumRengi);
            }
            else if (ortalama == -2.0f) {
                DrawTextEx(benimFontum, "NOTLAR 100'DEN BUYUK OLAMAZ.", (Vector2){ 200, 350 }, 18, 1, RED);
            }
            else {
                DrawTextEx(benimFontum, "Lutfen Vize ve Final notlarini giriniz.", (Vector2){ 200, 350 }, 18, 1, GRAY);
            }

            DrawTextEx(benimFontum, "Kutuya tiklayip rakam yazin. Silmek icin BACKSPACE.", (Vector2){ 180, 520 }, 16, 1, DARKGRAY);

        EndDrawing();
    }

    UnloadFont(benimFontum);
    CloseWindow();
    return 0;
}