#include <stdio.h>
#include <stdlib.h>

//dinh nghia cau truc book 
typedef struct {
    char ten[50];
    char tacGia[50];
    float gia;
} Book;

int main() {
    int n; //so luong sach
    printf("Nhap so luong sach: ");
    scanf("%d", &n);
    
    //cap phat dong mang book voi kich thuoc n
    Book* books = (Book*) malloc(n * sizeof(Book));
    
    // Nhap thong tin cho tung sach
    int i = 0;
    for (; i < n; i++) {
        printf("Nhap ten sach thu %d: ", i + 1);
        scanf("%s", books[i].ten);
        printf("Nhap tac gia cua sach thu %d: ", i + 1);
        scanf("%s", books[i].tacGia);
        printf("Nhap gia cua sach thu %d: ", i + 1);
        scanf("%f", &books[i].gia);
    }
    
    //hien thi thong tin sach
    printf("\nThong tin cac sach:\n");
    for (; i < n; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("Ten: %s\n", books[i].ten);
        printf("Tac gia: %s\n", books[i].tacGia);
        printf("Gia: %.2f\n", books[i].gia);
        printf("\n");
    }
    
    //giai phong bo nho da cap phat dong
    free(books);
    
    return 0;
}
