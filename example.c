#include <stdio.h>

#include "strkvm.h"
#include "strutils.h"

static void example_01(void)
{
  st_strkvm strkvm;
  char *str = NULL;
  size_t length = 0;

  strkvm_init(&strkvm);
  strkvm_add(&strkvm, "name1");
  strkvm_add(&strkvm, "name2");
  strkvm_add(&strkvm, "number1");
  strkvm_add(&strkvm, "number2");
  strkvm_add(&strkvm, "float1");
  strkvm_add(&strkvm, "b1");
  strkvm_add(&strkvm, "b2");
  strkvm_tostring(&strkvm, &str, &length);
  strkvm_free(&strkvm);

  printf("Ex 01: %.*s\n", (int)length, str);

  free(str);
}

static void example_02(void)
{
  st_strkvm strkvm;
  char *str = NULL;
  size_t length = 0;

  strkvm_init(&strkvm);
  strkvm_add_string(&strkvm, "name1", "value1");
  strkvm_add_string(&strkvm, "name2", "value2");
  strkvm_add_int(&strkvm, "number1", 1);
  strkvm_add_int(&strkvm, "number2", 2);
  strkvm_add_float(&strkvm, "float1", 1.1);
  strkvm_add_bool(&strkvm, "b1", true);
  strkvm_add_bool(&strkvm, "b2", false);
  strkvm_remove(&strkvm, "b2");
  strkvm_remove(&strkvm, "name2");
  strkvm_remove(&strkvm, "number2");
  strkvm_tostring(&strkvm, &str, &length);
  strkvm_free(&strkvm);

  printf("Ex 02: %.*s\n", (int)length, str);

  free(str);
}

static void example_03(void)
{
  char *str = NULL;
  bool b = false;
  int i = 0;
  float f = 0.0;
  char check_str[] = "bool=true;float=1.1;number=10;name=hello world;";
  st_strkvm strkvm;

  strkvm_init(&strkvm);
  strkvm_parse(&strkvm, check_str, strlen(check_str));
  strkvm_get_bool(&strkvm, "bool", &b);
  strkvm_get_float(&strkvm, "float", &f);
  strkvm_get_int(&strkvm, "number", &i);
  strkvm_get_string(&strkvm, "name", &str);
  strkvm_free(&strkvm);

  free(str);
}

static void example_04(void)
{
  char str[] = " this is a string, a simple  string      to test string utils, just test. ";
  char** array = NULL;
  uint32_t count  = 0;
  int i;

  printf("Ex 04     : '%s'\n", str);
  
  strutils_trim(str);
  printf("       trim: '%s'\n", str);

  strutils_one_space(str);
  printf("  one space: '%s'\n", str);

  strutils_no_space(str);
  printf("   no space: '%s'\n", str);

  printf("count match: '%s' have %d comma\n", str, strutils_count_matches(str, ','));

  strutils_split(str, ',', &array, &count);
  for (i = 0; i < count; i++) {
    printf("   split[%d]: '%s'\n", i, array[i]);
    free(array[i]);
  }
}

int main(int argc, char** argv)
{
  example_01();
  example_02();
  example_03();
  example_04();

  return 0;
}
