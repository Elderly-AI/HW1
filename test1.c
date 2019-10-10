#include <stdbool.h>
#include <stdio.h>   
#include <stdlib.h> 
#include <string.h>

typedef struct {
	char* type;
	char* color;
	char* name;
} Animal;

size_t binary_search(size_t lower_bound, size_t upper_bound, const Animal *array,
					const Animal *desired_animal, size_t (*cmp)(const void *a, const void *b)){

	size_t middle_element = upper_bound;

	while(lower_bound != upper_bound){
		middle_element = lower_bound + (upper_bound - lower_bound) / 2;
			
		if(cmp(&array[middle_element], desired_animal)){
			lower_bound = middle_element + 1;
		}
		else{
			upper_bound = middle_element;
		}
	}
	return(lower_bound);
}

void insert_sort(Animal *array, size_t animals_count, size_t (*cmp)(const void *a, const void *b)){
	Animal buff;

	for(size_t c = 0; c < animals_count; ++c){
		size_t insert_index = binary_search(0, c, array, &array[c], cmp);
		buff = array[c];
		memmove(array + insert_index + 1, array + insert_index, (c - insert_index) * sizeof(Animal));
		
		array[insert_index] = buff;
	}
}

void show(Animal *array, size_t animals_count){
	for(size_t c = 0; c < animals_count; ++c){
		printf("%s\t\t%s \t\t%s\n", array[c].name, array[c].type, array[c].color);
	}
	printf("\n");
}


size_t my_custom_sort_function(const void *aa, const void *bb){
	char *aa_type = (*(Animal*)aa).type;
	char *bb_type = (*(Animal*)bb).type;

	size_t aa_type_len = strlen(aa_type);
	size_t bb_type_len = strlen(bb_type);

	size_t index = 0;
	while((index < aa_type_len) && (index < bb_type_len)){
		if(aa_type[index] != bb_type[index]){
			return(aa_type[index] <= bb_type[index]);
		}
		index += 1;
	}

	if(aa_type_len != bb_type_len){
		return(aa_type_len < bb_type_len);
	}
	else{
		return(true);
	}

	
}

void test(){
	
	size_t animals_count = 1000;	//Random Generated Test

	size_t types_count = 21;
	char types[21][10] = {"dog", "cat", "fish", "goat", "kid",
		"bull", "horse", "pig", "rabbit", "fox", "deer", "crocodile",
		"hyena", "lion", "mouse", "monkey", "mouse", "otter", "puma",
		"wolf", "zebra"};

	size_t colors_count = 8;
	char colors[8][7] = {"black", "white", "orange", "green", "yellow", "blue", "brown", "pink"};

	size_t names_count = 12;
	char names[12][8] = {"Caval", "Diamond", "Rogue", "Nelson", "Prim",
		"Rufus", "Polly", "Dicky", "Jack", "Rapid", "Freed", "Jeremy"};

	Animal *animals_array = (Animal*) malloc (sizeof(Animal) * animals_count);
	for(size_t c = 0; c < animals_count; ++c){
		Animal new_animal;
		new_animal.type = &types[rand() % types_count][0];
		new_animal.color = &colors[rand() % colors_count][0];
		new_animal.name = &names[rand() % names_count][0];
		animals_array[c] = new_animal;
	}
	
	insert_sort(animals_array, animals_count, my_custom_sort_function);

	show(animals_array, animals_count);
	free(animals_array);
}

int main(){
	test();
}
