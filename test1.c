#include <stdio.h>   
#include <stdlib.h> 
#include <assert.h>

typedef struct {
	char* type;
	char* color;
	char* name;
} Animal;

typedef struct {
	size_t size;
	size_t last_index;
	Animal *animals;
	char *title;
} AnimalsList;


void add_animal_to_list(AnimalsList *list, Animal new_animal){
	if(list->last_index == list->size){
		if(list->size == 0){
			list->animals = (Animal*) malloc (sizeof(Animal));

			assert(list->animals != NULL);
			list->size = 1;

		}
		else{
			Animal *buff = NULL;
			buff = (Animal*) realloc (list->animals, sizeof(Animal) * ((int)list->last_index * 2));

			assert(buff != NULL);
			list->size *= 2;
			list->animals = buff;
		}	
	}

	list->animals[list->last_index] = new_animal;
	list->last_index += 1;
}


int main(){
	AnimalsList tts;
	tts.size = 0;
	tts.last_index = 0;
	tts.animals = NULL;
	tts.title = NULL;

	Animal p;
	p.type = NULL;
	p.color = NULL;
	p.name = NULL;

	add_animal_to_list(&tts, p);

	free(tts.animals);

}
