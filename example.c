#include <Elementary.h>

#define SIZE_X 500
#define SIZE_Y 500
#define EDJE_FILE "example.edj"

#define EDJE_GROUP "mygroup"

EAPI_MAIN int elm_main(int argc, char** argv) {

   (void)argc;
   (void)argv;

   Evas_Object *win, *layout;

   win = elm_win_util_standard_add("Edje", "Edje Example");
   elm_policy_set(ELM_POLICY_QUIT, ELM_POLICY_QUIT_LAST_WINDOW_CLOSED);
   elm_win_autodel_set(win, EINA_TRUE);
   layout = elm_layout_add(win);

   elm_layout_file_set(layout, EDJE_FILE, EDJE_GROUP);

   evas_object_resize(layout, SIZE_X, SIZE_Y);
   evas_object_resize(win, SIZE_X, SIZE_Y);

   evas_object_show(layout);
   evas_object_show(win);

   elm_run();
   elm_shutdown();
   return EXIT_SUCCESS;
}
ELM_MAIN();

