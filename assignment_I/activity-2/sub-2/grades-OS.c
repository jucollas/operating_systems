#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_CATEGORIES 6

const float p[6] = {0.05, 0.25, 0.2, 0.15, 0.2, 0.15};

struct Student {
  char* id;
  char* name;
  float* notes;  // Cambiar a float
  float total;
};

struct Student cStudent(char* id, char* name, float* notes) {
  struct Student s;
  s.id = (char*) malloc((strlen(id) + 1) * sizeof(char));  
  s.name = (char*) malloc((strlen(name) + 1) * sizeof(char)); 
  s.notes = (float*) malloc(6 * sizeof(float));  // Cambiar a float

  if (s.id != NULL && s.name != NULL && s.notes != NULL) {  
    strcpy(s.id, id);
    strcpy(s.name, name);
    s.total = 0;
    for (int i = 0; i < 6; i++) {
      s.notes[i] = notes[i];
      s.total += notes[i] * p[i];
    }
  }
  return s;
}

void delStudent(struct Student s) {
  free(s.id);
  free(s.name);
  free(s.notes);
}

void printStudents(struct Student* students, int n) {
  printf("| %-6s | %-25s | %-5s | %-5s | %-5s | %-5s | %-5s | %-5s | %-7s |\n", 
         "ID", "NAME", "N1", "N2", "N3", "N4", "N5", "N6", "Total");
  printf("|--------|---------------------------|-------|-------|-------|-------|-------|-------|---------|\n");

  for (int i = 0; i < n; i++) {
    printf("| %-6s | %-25s |", students[i].id, students[i].name);
    for (int j = 0; j < 6; j++) {
      printf(" %-5.2f |", students[i].notes[j]);
    }
    printf(" %-7.2f |\n", students[i].total);
  }
}

void inputNotes(float* notes) {
  const char* categories[NUM_CATEGORIES] = {
    "Returning to C", 
    "Process", 
    "Threads and synchronization", 
    "Scheduling", 
    "Input-Output (I/O)", 
    "Memoria"
  };

  for (int i = 0; i < NUM_CATEGORIES; i++) {
    float grade;
    do {
      printf("Enter the grade for %s (%.1f%%): ", categories[i], p[i]);
      scanf("%f", &grade);
      if (grade < 0.0 || grade > 5.0) {
        printf("Invalid grade. Please enter a grade between 0.0 and 5.0.\n");
      }
    } while (grade < 0.0 || grade > 5.0);
    
    notes[i] = grade;
  }
}


void addStudentByTerminal(struct Student** students, int* n) {
  char id[20];
  char *name = NULL;
  size_t len = 0;
  float notes[6];
  size_t read;

  printf("Enter ID: ");
  scanf("%s", id);
  getchar();

  printf("Enter name: ");
  read = getline(&name, &len, stdin);
  if (read == -1) {
    printf("Error reading name\n");
    free(name);
    return;
  }
  if (name[read - 1] == '\n') {
    name[read - 1] = '\0';
  }

  inputNotes(notes);

  *students = (struct Student*) realloc(*students, (*n + 1) * sizeof(struct Student));
  (*students)[*n] = cStudent(id, name, notes);
  (*n)++;

  free(name);
}

void addStudentsByFile(struct Student** students, int* n, const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error: Could not open file.\n");
    return;
  }

  char line[256];
  char id[20];
  char name[50];
  float notes[NUM_CATEGORIES];

  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = '\0';

    char* token = strtok(line, "|");
    if (token != NULL) {
      strncpy(id, token, sizeof(id));
      id[sizeof(id) - 1] = '\0';

      token = strtok(NULL, "|");
      if (token != NULL) {
        strncpy(name, token, sizeof(name));
        name[sizeof(name) - 1] = '\0';

        for (int i = 0; i < NUM_CATEGORIES; i++) {
          token = strtok(NULL, "|");
          if (token != NULL) {
            notes[i] = strtof(token, NULL);
          } else {
            notes[i] = 0.0;
          }
        }

        *students = (struct Student*) realloc(*students, (*n + 1) * sizeof(struct Student));
        (*students)[*n] = cStudent(id, name, notes);
        (*n)++;
      }
    }
  }

  fclose(file);
}


void info(){
  printf("\nMenu:\n");
  printf("1. Add student by terminal\n");
  printf("2. Add students by file\n");
  printf("3. Show students\n");
  printf("4. Exit\n");
}

int main() {
  struct Student* students = NULL;
  int n = 0;  // Número de estudiantes
  int option;
  char filename[50];

  info();
  printf("Choose an option: ");
  scanf("%d", &option);
  while (option != 4){
    switch (option) {
      case 1:
        addStudentByTerminal(&students, &n);
        break;
      case 2:
        printf("Enter the filename: ");
        scanf("%s", filename);
        addStudentsByFile(&students, &n, filename);
        break;
      case 3:
        printStudents(students, n);
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid option.\n");
    }
    info();
    printf("Choose an option: ");
    scanf("%d", &option);
  }

  for (int i = 0; i < n; i++) {
    delStudent(students[i]);
  }
  free(students);

  return 0;
}
