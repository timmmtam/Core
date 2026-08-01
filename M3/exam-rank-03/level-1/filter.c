#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 42

void filter(char *result, char *target) {
  size_t i;
  size_t j;
  size_t k;
  size_t target_len;

  target_len = strlen(target);
  i = 0;
  printf("%s\n", result);
  while (result[i] != '\0') {
    j = 0;
    while (target[j] != '\0' && result[i + j] == target[j])
      j++;
    if (j == target_len) {
      for (k = 0; k < target_len; k++)
        write(1, "*", 1);
      i += target_len;
    } else {
      write(1, &result[i], 1);
      i++;
    }
  }
}

int main(int ac, char **av) {
  ssize_t read_bytes;
  ssize_t total_read;
  char buffer[BUFFER_SIZE + 1];
  char *result;

  if (ac != 2 || av[1][0] == '\0')
    return (1);
  total_read = 0;
  result = NULL;
  while ((read_bytes = read(0, buffer, BUFFER_SIZE)) > 0) {
    buffer[BUFFER_SIZE] = '\0';
    result = realloc(result, total_read + read_bytes + 1);
    if (!result)
      return (perror("Realloc"), 1);
    memmove(result + total_read, buffer, read_bytes + 1);
    total_read += read_bytes;
  }
  if (read_bytes < 0)
    return (free(result), perror("Read"), 1);
  if (!result)
    return (0);
  filter(result, av[1]);
  return (free(result), 0);
}
