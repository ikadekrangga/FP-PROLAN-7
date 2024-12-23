// Fungsi untuk save database ke file
void saveDatabase(Inventory item[], int n, const char *filename) {
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
	    printf("\n File error...\n");
	    return;
	}
	for (int i = 0; i < n; i++) {
	    fprintf(file, "%s,%s,%d\n", item[i].name, item[i].category, item[i].quantity);
	}
	fclose(file);
	printf("\n Data tersimpan ke %s...\n", filename);
}
