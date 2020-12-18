#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

void print_an_array(int an_array[10], bool without_brackets) {
	for (int i = 0; i <= 9; i++) printf("%d ", an_array[i]);
}
void print_an_array(int an_array[10]) {
	int i;
	bool bracket_closed = false;
	printf("\n[ ");
	for (i = 0; i <= 9; i++) {
		printf("%d ", an_array[i]);
		if (!(an_array[i] <= an_array[i + 1]) && !bracket_closed) { printf("] "); bracket_closed = true; }

	}
}
void print_an_array(int an_array[10], int sorted_lenght) {
	int i;
	bool bracket_closed = false;
	printf("\n[ ");
	for (i = 0; i <= 9; i++) {
		printf("%d ", an_array[i]);
		if (!sorted_lenght && !(an_array[i] <= an_array[i + 1]) && !bracket_closed) { printf("] "); bracket_closed = true; }
		if (sorted_lenght && i == sorted_lenght - 1 ) { printf("] "); bracket_closed = true; }
	}
}

int find_minimum(int an_array[10], int sorted_lenght) {
	int i = sorted_lenght, minimum_index = sorted_lenght, minimum = an_array[sorted_lenght];
	for (i; i < 10; i++) if (minimum > an_array[i]) {minimum = an_array[i]; minimum_index = i;}
	return minimum_index;
}
bool array_is_sorted(int an_array[10]) { 
	int i;
	for (i = 0; i < 9; i++) if (!(an_array[i] <= an_array[i + 1])) return false;
	return true;
}
void insert_in_array(int an_array[10], int x, int position) {
	int i, y;
	for (i = position - 1; i <= 9; i++) {
		y = an_array[i];
		an_array[i] = x;
		x = y;
	}
}
void delete_in_array(int an_array[10], int position) {
	int i = position, y, x = an_array[9];
	for (i = 8; i >= position; i--) {
		y = an_array[i];
		an_array[i] = x;
		x = y;
	}
}
int calculate_sorted_lenght(int an_array[10]) {
	int counter = 1;
	for (int i = 0; i < 9; i++) { if (an_array[i] <= an_array[i + 1]) counter++; else return counter; }
	return counter;
}


void simple_insertion_sort(int unsorted_array[10]) {
	int x, i, j, sorted_lenght = calculate_sorted_lenght(unsorted_array);
	for (i = 1; i < 10; i++) {
		sorted_lenght = calculate_sorted_lenght(unsorted_array);
		i = sorted_lenght;
		x = unsorted_array[i];
		printf("\nsorted len: %d x: %d", sorted_lenght, x);
		if (unsorted_array[i-1]>x)
			for (j = sorted_lenght - 1; j >= 0; j--) {
				if (unsorted_array[j] <= x) { delete_in_array(unsorted_array, i); insert_in_array(unsorted_array, x, j + 2); print_an_array(unsorted_array); break; }
				
				if (j == 0 && unsorted_array[j] >= x) { delete_in_array(unsorted_array, i); insert_in_array(unsorted_array, x, 1); print_an_array(unsorted_array); break;}
			}
	
	}

}
void my_choice_sort(int unsorted_array[10]) {
	int x, i, sorted_lenght = 0;
	while (sorted_lenght < 10) {
		i = find_minimum(unsorted_array, sorted_lenght);
		x = unsorted_array[i];
		printf("\nsorted len: %d index of min el: %d", sorted_lenght, i);
		sorted_lenght++;
		delete_in_array(unsorted_array, i);
		insert_in_array(unsorted_array, x, sorted_lenght);
		print_an_array(unsorted_array, sorted_lenght);
	}
}


void insertion_sort(int unsorted_array[10]) {
	int sorted_lenght = 1, x;
	for (int i = 1; i < 10; i++) {
		x = unsorted_array[i];
		printf("\nx :%d", x);
		for (int j = sorted_lenght - 1; j >= 0; j--)
		{
			if (unsorted_array[j] <= x) 
			{	sorted_lenght++; unsorted_array[j + 1] = x; 
				print_an_array(unsorted_array, sorted_lenght); 
				break; }
			if (unsorted_array[j] >= x) 
			{	unsorted_array[j + 1] = unsorted_array[j]; 
				print_an_array(unsorted_array, 
				sorted_lenght); }
			if (j == 0 && unsorted_array[j] >= x) 
			{	sorted_lenght++; 
				unsorted_array[j] = x; 
				print_an_array(unsorted_array, sorted_lenght); 
				break; }

		}
	}
}

void choice_sort(int unsorted_array[10]) {
	int x, i, min_i, sorted_lenght = 0;
	for (i = 0; i < 10; i++)
	{
		min_i = find_minimum(unsorted_array, sorted_lenght);
		swap(unsorted_array[sorted_lenght], unsorted_array[min_i]);
		sorted_lenght++;
		print_an_array(unsorted_array, sorted_lenght);
	}

}

void shell_sort(int unsorted_array[10])              
{
	int step, i, j, x, sorted_lenght = 0;
	int size = 10;

	// Выбор шага
	
	for (step = size / 2; step > 0; step /= 2) 
	{
		// 10 20 9 64 44 0 1 1 2 2
		printf("\n=====");
		printf("\nStep: %d\n", step);
		print_an_array(unsorted_array, false);
		printf("\n=====\n");
		for (i = 0; i + step + 1 < size; i++)
		{
			if (unsorted_array[i] > unsorted_array[i + step + 1]) {
				printf("\n-----\n");
				print_an_array(unsorted_array, false);
				printf("\n%d exchange %d\n", unsorted_array[i], unsorted_array[i+step + 1]);
				swap(unsorted_array[i], unsorted_array[i + step + 1]);
				print_an_array(unsorted_array, false);
				printf("\n-----\n");
			}
		}
	}

	insertion_sort(unsorted_array);
}

void bubble_sort(int unsorted_array[10])
{
    int i=0, pos=0, n = 10, res, j, k, id = 0;
	int sorted_length;
	bool flag;

    for (i = 0; i < n; i++)
    {
        flag=true;        
        for (j = n-1; j>id ; j--)
        {
            if (unsorted_array[j-1] > unsorted_array[j])
            {
                flag = false;
                swap(unsorted_array[j-1], unsorted_array[j]); 
                pos = j - 1;
            }            
        } 
        id = pos;
        if (flag)
            break;
		print_an_array(unsorted_array, i + 1);
    }
}


void main() {
	int unsorted_array[10] = { 10, 20, 9, 64, 44, 0, 1, 1, 2, 2 };
	printf("PRESS 1 FOR INSERTION SORT\nPRESS 2 FOR CHOICE SORT:\nPRESS 3 FOR SHELL SORT:\nPRESS 4 FOR BUBBLE SORT:");
	int menu;
	scanf("%d", &menu);

	if (menu == 1) {
		printf("INSERTION SORT:\n");
		print_an_array(unsorted_array, false);
		insertion_sort(unsorted_array);
	}
	if (menu==2)
	{
		printf("\n\nCHOICE SORT:\n");
		print_an_array(unsorted_array, false);
		choice_sort(unsorted_array);
	}

	if (menu == 3)
	{
		printf("\n\nSHELL SORT:\n");
		print_an_array(unsorted_array, false);
		shell_sort(unsorted_array);
	}

	if (menu == 4)
	{
		printf("\n\nBUBBLE SORT:\n");
		print_an_array(unsorted_array, false);
		bubble_sort(unsorted_array);
		print_an_array(unsorted_array);
	}
}
