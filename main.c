#include <stdio.h>
#include <string.h>
struct Thuoc {
    int maThuoc;
    char tenThuoc[50];
    int soLuong;
    float donGia;
};
int timThuocTheoMa(struct Thuoc ds[], int soThuoc, int ma) {
    for (int i = 0; i < soThuoc; i++) {
        if (ds[i].maThuoc == ma) {
            return i;
        }
    }
    return -1;
}
int themThuoc(struct Thuoc ds[], int soThuoc) {
    if (soThuoc >= 50) {
        printf("Danh sach da day\n");
        return soThuoc;
    }

    int ma;
    printf("Nhap ma thuoc: ");
    scanf("%d", &ma);

    if (timThuocTheoMa(ds, soThuoc, ma) != -1) {
        printf("Ma thuoc da ton tai\n");
        return soThuoc;
    }

    ds[soThuoc].maThuoc = ma;

    printf("Nhap ten thuoc: ");
    getchar();
    fgets(ds[soThuoc].tenThuoc, sizeof(ds[soThuoc].tenThuoc), stdin);
    ds[soThuoc].tenThuoc[strcspn(ds[soThuoc].tenThuoc, "\n")] = '\0';

    do {
        printf("Nhap so luong ton (>= 0): ");
        scanf("%d", &ds[soThuoc].soLuong);
        if (ds[soThuoc].soLuong < 0) {
            printf("So luong khong hop le! Vui long nhap lai.\n");
        }
    } while (ds[soThuoc].soLuong < 0);

    do {
        printf("Nhap don gia (> 0): ");
        scanf("%f", &ds[soThuoc].donGia);
        if (ds[soThuoc].donGia <= 0) {
            printf("Don gia khong hop le! Vui long nhap lai.\n");
        }
    } while (ds[soThuoc].donGia <= 0);

    soThuoc++;
    printf("Them thuoc thanh cong\n");
    return soThuoc;
}
void hienThiDanhSach(struct Thuoc ds[], int soThuoc) {
    if (soThuoc == 0) {
        printf("Danh sach rong\n");
        return;
    }
    printf("+-----------+---------------------------+------------+-----------------+-----------------+\n");
    printf("| %-10s | %-25s | %-10s | %-15s | %-15s |\n",
           "Ma", "Ten thuoc", "So luong", "Don gia", "Thanh tien");
    printf("+------------+---------------------------+------------+-----------------+-----------------+\n");
    for (int i = 0; i < soThuoc; i++) {
        float thanhTien = ds[i].soLuong * ds[i].donGia;
        printf("| %-10d | %-25s | %-10d | %-15.0f | %-15.0f |\n",
               ds[i].maThuoc, ds[i].tenThuoc, ds[i].soLuong, ds[i].donGia, thanhTien);
        printf("+------------+---------------------------+------------+-----------------+-----------------+\n");
    }
}
void capNhatThuoc(struct Thuoc ds[], int soThuoc) {
    if (soThuoc == 0) {
        printf("Danh sach rong\n");
        return;
    }

    int ma;
    printf("Nhap ma thuoc can sua: ");
    scanf("%d", &ma);

    int viTri = timThuocTheoMa(ds, soThuoc, ma);
    if (viTri == -1) {
        printf("Khong tim thay thuoc\n");
        return;
    }

    printf("Nhap ten thuoc moi: ");
    getchar();
    fgets(ds[viTri].tenThuoc, sizeof(ds[viTri].tenThuoc), stdin);
    ds[viTri].tenThuoc[strcspn(ds[viTri].tenThuoc, "\n")] = '\0';

    do {
        printf("Nhap so luong moi (>= 0): ");
        scanf("%d", &ds[viTri].soLuong);
        if (ds[viTri].soLuong < 0) {
            printf("So luong khong hop le! Vui long nhap lai.\n");
        }
    } while (ds[viTri].soLuong < 0);

    do {
        printf("Nhap don gia moi (> 0): ");
        scanf("%f", &ds[viTri].donGia);
        if (ds[viTri].donGia <= 0) {
            printf("Don gia khong hop le! Vui long nhap lai.\n");
        }
    } while (ds[viTri].donGia <= 0);

    printf("Cap nhat thanh cong\n");
}
int xoaThuoc(struct Thuoc ds[], int soThuoc) {
    if (soThuoc == 0) {
        printf("Danh sach rong\n");
        return soThuoc;
    }

    int ma;
    printf("Nhap ma thuoc can xoa: ");
    scanf("%d", &ma);

    int viTri = timThuocTheoMa(ds, soThuoc, ma);
    if (viTri == -1) {
        printf("Khong tim thay thuoc\n");
        return soThuoc;
    }

    for (int i = viTri; i < soThuoc - 1; i++) {
        ds[i] = ds[i + 1];
    }

    soThuoc--;
    printf("Xoa thanh cong\n");
    return soThuoc;
}
void timThuocTheoTen(struct Thuoc ds[], int soThuoc) {
    char tenCanTim[50];
    printf("Nhap ten thuoc can tim: ");
    getchar();
    fgets(tenCanTim, sizeof(tenCanTim), stdin);
    tenCanTim[strcspn(tenCanTim, "\n")] = '\0';

    int timThay = 0;
    for (int i = 0; i < soThuoc; i++) {
        if (strcmp(ds[i].tenThuoc, tenCanTim) == 0) {
            if (!timThay) {
                printf("+-----------+---------------------------+------------+-----------------+-----------------+\n");
                printf("| %-10s | %-25s | %-10s | %-15s | %-15s |\n",
                       "Ma", "Ten thuoc", "So luong", "Don gia", "Thanh tien");
                printf("+------------+---------------------------+------------+-----------------+-----------------+\n");
                timThay = 1;
            }
            float thanhTien = ds[i].soLuong * ds[i].donGia;
            printf("| %-10d | %-25s | %-10d | %-15.0f | %-15.0f |\n",
                   ds[i].maThuoc, ds[i].tenThuoc, ds[i].soLuong, ds[i].donGia, thanhTien);
            printf("+------------+---------------------------+------------+-----------------+-----------------+\n");
        }
    }

    if (!timThay) {
        printf("Khong tim thay thuoc\n");
    }
}

int main() {
    struct Thuoc danhSach[50];
    int soThuoc = 0;
    int luaChon;

    do {
        printf("\n===== QUAN LY THUOC =====\n");
        printf("1. Them thuoc\n");
        printf("2. Hien thi danh sach thuoc\n");
        printf("3. Cap nhat thuoc theo ma\n");
        printf("4. Xoa thuoc theo ma\n");
        printf("5. Tim thuoc theo ten\n");
        printf("6. Thong ke kho hang\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                soThuoc = themThuoc(danhSach, soThuoc);
                break;
            case 2:
                hienThiDanhSach(danhSach, soThuoc);
                break;
            case 3:
                capNhatThuoc(danhSach, soThuoc);
                break;
            case 4:
                soThuoc = xoaThuoc(danhSach, soThuoc);
                break;
            case 5:
                timThuocTheoTen(danhSach, soThuoc);
                break;
            case 6:
                printf("Thong ke kho hang\n");
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}