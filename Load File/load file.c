// Fungsi untuk load database dari file
int loadDatabase(Inventory item[], const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
	    printf("\n File error...\n");
	    return 0;
	}
	int count = 0;
	while (fscanf(file, "%[^,],%[^,],%d\n", item[count].name, item[count].category, &item[count].quantity) != EOF) {
	    count++;
	    if (count >= DATABASE) break; // Mencegah overflow
	}
	fclose(file);
	printf("\n Data %d loaded dari %s...\n", count, filename);
	return count;
}
