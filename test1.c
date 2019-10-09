#include <stdio.h>   
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define AnimalsList struct AnimalsList
#define Animal struct Animal


Animal{
	char* type;
	char* color;
	char* name;
};

AnimalsList{
	size_t size;
	size_t last_index;
	Animal *animals;
	char *title;
};

void add_animal_to_list(AnimalsList *list, Animal new_animal){
	if(list->last_index == list->size){
		if(list->size == 0){
			list->animals = (Animal*) malloc (sizeof(Animal));

			assert(list->animals == NULL);
			list->size = 1;

		}
		else{
			Animal *buff = NULL;
			buff = (Animal*) realloc (list->animals, sizeof(Animal) * ((int)list->last_index * 2));

			assert(buff == NULL);
			list->size *= 2;
			list->animals = buff;
		}	
	}

	list->animals[list->last_index] = new_animal;
	list->last_index += 1;
}

void sort(AnimalsList list_to_sort, AnimalsList *dogs, AnimalsList *cats, AnimalsList *other){
	for(int c = 0; c < list_to_sort.last_index; ++c){
		if(strcmp(list_to_sort.animals[c].type, "dog") == 0){
			add_animal_to_list(dogs, list_to_sort.animals[c]);
		}
		else if(strcmp(list_to_sort.animals[c].type, "cat") == 0){
			add_animal_to_list(cats, list_to_sort.animals[c]);
		}
		else{
			add_animal_to_list(other, list_to_sort.animals[c]);
		}
	}
}

void show(const AnimalsList *animals_list){
	printf("%s:\n", animals_list->title);
	for(int c = 0; c < animals_list->last_index; ++c){
		printf("	%s %s %s\n", animals_list->animals[c].type, 
			animals_list->animals[c].color, animals_list->animals[c].name);
	}
	printf("\n");
}

void task(Animal *animals, size_t animals_count){

	AnimalsList list;
	list.size = animals_count;
	list.last_index = animals_count;
	list.animals = animals;
	
	char DOGS[] = "DOGS";
	AnimalsList dogs;
	dogs.size = 0;
	dogs.last_index = 0;
	dogs.animals = NULL;
	dogs.title = &DOGS[0];

	char CATS[] = "CATS";
	AnimalsList cats;
	cats.size = 0;
	cats.last_index = 0;
	cats.animals = NULL;
	cats.title = &CATS[0];

	char OTHER[] = "OTHER";
	AnimalsList other;
	other.size = 0;
	other.last_index = 0;
	other.animals = NULL;
	other.title = &OTHER[0];

	sort(list, &dogs, &cats, &other);

	show(&list);
	show(&dogs);
	show(&cats);
	show(&other);

	free(list.animals);
	free(dogs.animals);
	free(cats.animals);
	free(other.animals);
}

int main(){
	task(NULL, 0);
	//run task
	//printf("%d %d\n", TTSSES);
}