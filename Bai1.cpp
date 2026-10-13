#include <stdio.h>
#define MAX_SHELF_WEIGHT 500.0

typedef struct {
    int pallet_id;
    float weight_kg;
    float temp_celsius;
} PalletItem;

typedef struct {
    int shelf_id;
    int is_cold_storage;
    float current_weight_kg;
} WarehouseShelf;

int kiem_tra_an_toan_nhap_kho(WarehouseShelf shelf, PalletItem item) {
    float tong_trong_luong = shelf.current_weight_kg + item.weight_kg;
    if (tong_trong_luong > MAX_SHELF_WEIGHT) {
        printf("[LOI QUA TAI] Tong trong luong sau khi xep (%.1f kg) vuot qua gioi han cho phep cua ke (%.1f kg)!\n", 
               tong_trong_luong, MAX_SHELF_WEIGHT);
        return 0;
    }

    if (shelf.is_cold_storage == 1) {
        if (item.temp_celsius < -18.0 || item.temp_celsius > 5.0) {
            printf("[LOI KHO LANH] Nhiet do bao quan %.1f do C khong dat chuan (-18 do C den 5 do C)!\n", item.temp_celsius);
            return 0;
        }
    }

    return 1;
}

int main() {
    WarehouseShelf ke_lanh_101 = {101, 1, 400.0};
    PalletItem pallet_moi = {5001, 150.0, 12.0};

    printf("=== HE THONG GIAM SAT AN TOAN NHAP KHO LOGISTICS ===\n");
    printf("Thong tin ke 101 : Tai trong hien tai = %.1f kg | Loai kho = %s\n", 
           ke_lanh_101.current_weight_kg, 
           ke_lanh_101.is_cold_storage ? "Kho Lanh" : "Kho Thuong");
    printf("Kien hang nhap   : Ma = %d | Nang = %.1f kg | Nhiet do = %.1f do C\n",
           pallet_moi.pallet_id, pallet_moi.weight_kg, pallet_moi.temp_celsius);
    printf("----------------------------------------------------\n");

    int ket_qua = kiem_tra_an_toan_nhap_kho(ke_lanh_101, pallet_moi);

    if (ket_qua == 1) {
        printf("=> KET QUA: [DUYET] Du dieu kien nhap kho!\n");
    } else {
        printf("=> KET QUA: [TU CHOI] Vi pham quy dinh an toan luu kho!\n");
    }

    return 0;
}
