
#include "test_includes.h"
int main(int argc, const char * argv[])
{
  // initialize all of Erl_Interface
  erl_init(NULL, 0);

  tidy_map_str_t opt;
  tidy_map_init(&opt);

  tidy_map_set(&opt, "TidyShowWarnings", "no");
  tidy_map_set(&opt, "TidyBodyOnly", "yes");
  // minify
  tidy_map_set(&opt, "TidyVertSpace", "auto");
  tidy_map_set(&opt, "TidyIndentSpaces", "0");

  tidy_workspace_t* w = tidy_init(&opt);

  const char *html = "<div><p id=p1><p id=p2><p id=p3><a>link</a><p id=p4><p id=p5><p id=p6></div>";
  vec_eterm_t term_array;
  eterm_vec_init(&term_array);
  parse(w, html, &term_array);
  char* result = eterm_vec_join(&term_array, "|");
  printf("-> '%s'\n", result);
  if(strcmp(result, "<div><p id=\"p1\"></p><p id=\"p2\"></p><p id=\"p3\"><a>link</a></p><p id=\"p4\"></p><p id=\"p5\"></p><p id=\"p6\"></p></div>") != 0){
    eterm_vec_destroy(&term_array);
    free(result);
    tidy_map_deinit(&opt);
    tidy_destroy(w);
    TEST_ERROR
    return 1;
  }
  eterm_vec_destroy(&term_array);
  free(result);

  // html = "<span>Hello World</span";
  // scope = "body";
  // eterm_vec_init(&term_array);
  // serialize(w, html, scope, &term_array);
  // result = eterm_vec_join(&term_array, "|");
  // printf("-> %s\n", result);
  // if(strcmp(result, "<body><span>Hello World</span></body>") != 0){
  //   eterm_vec_destroy(&term_array);
  //   free(result);
  //   tidy_destroy(w);
  //   TEST_ERROR
  //   return 1;
  // }
  // eterm_vec_destroy(&term_array);
  // free(result);

  // html = "<span Hello World";
  // scope = "body_children";
  // eterm_vec_init(&term_array);
  // serialize(w, html, scope, &term_array);
  // result = eterm_vec_join(&term_array, "|");
  // printf("-> %s\n", result);
  // if(strcmp(result, "<span hello=\"\" world=\"\"></span>") != 0){
  //   eterm_vec_destroy(&term_array);
  //   free(result);
  //   tidy_destroy(w);
  //   TEST_ERROR
  //   return 1;
  // }
  // eterm_vec_destroy(&term_array);
  // free(result);

  // html = "";
  // scope = "html";
  // eterm_vec_init(&term_array);
  // serialize(w, html, scope, &term_array);
  // result = eterm_vec_join(&term_array, "|");
  // printf("-> %s\n", result);
  // if(strcmp(result, "<html><head></head><body></body></html>") != 0){
  //   eterm_vec_destroy(&term_array);
  //   free(result);
  //   tidy_destroy(w);
  //   TEST_ERROR
  //   return 1;
  // }
  // eterm_vec_destroy(&term_array);
  // free(result);

  tidy_map_deinit(&opt);
  tidy_destroy(w);

  printf("ok\n");
  return 0;
}