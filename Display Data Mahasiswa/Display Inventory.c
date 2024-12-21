// Struktur untuk menyimpan data item
typedef struct {
    char name[50];
    char category[30];
    int quantity;
} Inventory;

// Tampilan data item
void printData(Inventory item[], int n) {
	printf(" +-------------------------------+---------------------------+------------+\n");
	printf(" | %-28s  | %-25s | %-10s |\n", "Items", "Category", "Quantity");
	printf(" +-------------------------------+---------------------------+------------+\n");
	for (int i = 0; i < n; i++) {
	    printf(" | %-29s | %-25s | %-10d |\n", item[i].name, item[i].category, item[i].quantity);
	    }
	printf(" +-------------------------------+---------------------------+------------+\n");
}
