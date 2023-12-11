#include <stdio.h>
#include <stdlib.h>

// �inh nghia cau tr�c du li?u
struct Data {
    int id;
    float value;
};

int main() {
    // Ghi du lieu v�o tep tin nhi ph�n
    FILE *file = fopen("data.bin", "wb");

    if (file == NULL) {
        printf("Khong the mo hoac tao file.\n");
        return 1;
    }

    struct Data data1 = {1, 3.15};
    struct Data data2 = {2, 3.06};

    // Ghi du lieu v�o tep tin
    fwrite(&data1, sizeof(struct Data), 1, file);
    fwrite(&data2, sizeof(struct Data), 1, file);

    // ��ng tep tin
    fclose(file);

    // �oc du lieu tu tep tin nhi ph�n v� hien thi ra m�n h�nh
    file = fopen("data.bin", "rb");

    if (file == NULL) {
        printf("Khong the mo file.\n");
        return 1;
    }

    struct Data readData;

    // �oc du lieu tu tep tin
    while (fread(&readData, sizeof(struct Data), 1, file) == 1) {
        // Hien thi du lieu ra m�n h�nh
        printf("ID: %d, Value: %.2f\n", readData.id, readData.value);
    }

    // ��ng tep tin
    fclose(file);

    return 0;
}

