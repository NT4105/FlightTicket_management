#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 100
#define SEAT_FILE_PATH "database\\seats.txt"


struct Seat {
    int seatNumber;
    int flightNumber;
    int booked;
};

struct Seat seats[MAX_SEATS];
int numSeats = 0;

void saveToSeat() {
    FILE *file = fopen("seats.txt", "w");
    if (file == NULL) {
        printf("Khong mo duoc file de ghi.\n");
        return;
    }

    for (int i = 0; i < numSeats; i++) {
        fprintf(file, "%d %d %d\n", seats[i].seatNumber, seats[i].flightNumber, seats[i].booked);
    }

    fclose(file);
}

void loadFromSeat() {
    FILE *file = fopen("seats.txt", "r");
    if (file == NULL) {
        printf("File khong ton tai hoac khong mo duoc.\n");
        return;
    }

    while (fscanf(file, "%d %d %d", &seats[numSeats].seatNumber, &seats[numSeats].flightNumber, &seats[numSeats].booked) != EOF) {
        numSeats++;
    }

    fclose(file);
}

void displayMenu() {
    printf("\n======= Airplane Seat Management System =======\n");
    printf("1. Them cho ngoi\n");
    printf("2. Xoa cho ngoi\n");
    printf("3. Chinh sua thong tin cho ngoi\n");
    printf("4. Hien thi het cho ngoi\n");
    printf("5. Luu thong tin vao file\n");
    printf("6. Exit\n");
    printf("===============================================\n");
    printf("Nhap lua chon cua ban: ");
}

void addSeat() {
    if (numSeats >= MAX_SEATS) {
        printf("Chuyen bay da dat den gioi han cho ngoi.\n");
        return;
    }

    printf("Nhap so ghe ngoi: ");
    scanf("%d", &seats[numSeats].seatNumber);
    printf("Nhap so chuyen bay: ");
    scanf("%d", &seats[numSeats].flightNumber);
    printf("Nhap tinh trang dat ve (1 cho da duoc dat, 0 cho khong duoc dat): ");
    scanf("%d", &seats[numSeats].booked);

    if (seats[numSeats].booked != 0 && seats[numSeats].booked != 1) {
        printf("Tinh trang dat ve khong hop le. Mac dinh tinh trang khong dat ve.\n");
        seats[numSeats].booked = 0;
    }

    (__GCC_IEC_559)++;
    printf("Cho ngoi da duoc them thanh cong.\n");
}

void deleteSeat() {
    int seatNum, i;
    printf("Nhap ghe ngoi de xoa: ");
    scanf("%d", &seatNum);

    for (i = 0; i < numSeats; i++) {
        if (seats[i].seatNumber == seatNum) {
            for (int j = i; j < numSeats - 1; j++) {
                seats[j] = seats[j + 1];
            }
            numSeats--;
            printf("Ghe ngoi xoa thanh cong.\n");
            return;
        }
    }

    printf("Ghe ngoi khong tim thay duoc.\n");
}

void editSeat() {
    int seatNum, i;
    printf("Nhap so ghe ngoi de chinh sua: ");
    scanf("%d", &seatNum);

    for (i = 0; i < numSeats; i++) {
        if (seats[i].seatNumber == seatNum) {
            printf("Nhap ghe ngoi moi: ");
            scanf("%d", &seats[i].seatNumber);
            printf("Nhap chuyen bay moi: ");
            scanf("%d", &seats[i].flightNumber);
            printf("Thong tin cua ghe ngoi duoc cap nhat thanh cong.\n");
            return;
        }
    }

    printf("Ghe ngoi .\n");
}

void displaySeats() {
    printf("\n=== Danh sach ghe ngoi ===\n");
    printf("So cho ngoi.\tSo chuyen bay.\tTinh trang dat ve\n");
    for (int i = 0; i < numSeats; i++) {
        printf("%d\t\t%d\t\t%s\n", seats[i].seatNumber, seats[i].flightNumber, seats[i].booked ? "Co" : "Khong");
    }
    printf("====================\n");
}

int menuSeat() {
    int choice;

    loadFromSeat(); 

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSeat();
                break;
            case 2:
                deleteSeat();
                break;
            case 3:
                editSeat();
                break;
            case 4:
                displaySeats();
                break;
            case 5:
                saveToSeat();
                printf("Du lieu da duoc luu vao file.\n");
                break;
            case 6:
                printf("Dang thoat...\n");
                break;
            default:
                printf("Du lieu khong hop le. Vui long nhap so tu 1 den 6.\n");
        }
    } while (choice != 6);

    return 0;
}
