#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Load the dictionary of words from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadDictionary(char *filename, int *size);

// Search the dictionary for the target string
// Return the found string or NULL if not found.
char * searchDictionary(char *target, char **dictionary, int size);

int main(int argc, char *argv[])
{
	if (argc < 1)
	{
		fprintf(stderr, "Must supply a dictionary filename\n");
		exit(1);
	}
	
	int dlen;
	char **d = loadDictionary(argv[1], &dlen);
	
	printf("Dictionary loaded.\n");
	
	while(1)
	{
		char target[100];
		printf("Word to search for: ");
		fgets(target, 100, stdin);
		
		// Trim newline
		char *nl = strchr(target, '\n');
		if (nl) *nl = '\0';
		
		if (strcmp(target, "DONE") == 0) break;
		
		char *found = searchDictionary(target, d, dlen);
		if (found)
			printf("Found: %s\n", found);
		else
			printf("Not found!\n");
	}
}

char ** loadDictionary(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open dictionary");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings.
	// Read the dictionary line by line.
	// Copy each line into the array of strings.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array of strings.
	return NULL;
}

char * searchDictionary(char *target, char **dictionary, int size)
{
    if (dictionary == NULL) return NULL;
    
	for (int i = 0; i < size; i++)
	{
	    if (strcmp(target, dictionary[i]) == 0)
	    {
	        return dictionary[i];
	    }
	}
	return NULL;
}