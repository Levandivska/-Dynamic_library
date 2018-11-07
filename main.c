#include <stdio.h>
#include "my_lib.h"
#include <memory.h>

int main() {
    my_str_t my_str;
    my_str_t *source = &my_str;
    int test_create = my_str_create(source, 32);
    char *my_f = "../file.txt";
    FILE *file1 = fopen(my_f, "r");

    printf("\n\nTesting my_str_read\n");
    my_str_t read_to;
    int test_cr = my_str_create(&read_to,32);
    int test_read2 = my_str_read(&read_to);
    if (test_read2 == -1)
        printf("\nWrong argument");
    else {
        printf("The string read is ");
        print_str(&read_to);
    }

    printf("\nTesting my_str_create:");
    if (test_create == -1)
        printf("\nBuffer NULL, failed to allocate memory in my_str_create");
    else
        printf("\nCreated an instance of type my_str_t with capacity 32");

    printf("\n\nTesting my_str_capacity:");
    size_t test_capacity = my_str_capacity(source);
    if (test_capacity != source->capacity_m)
        printf("\nWrong result in my_str_capacity");
    else
        printf("\nCapacity of our string is %zu", source->capacity_m);

    printf("\n\nTesting my_str_from_cstr:");
    int test_cstr = my_str_from_cstr(source, "women");
    if (test_cstr == -1) {
        printf("\nBuffer size < cstr size");
    } else if (test_cstr == -2) {
        printf("\nBuffer NULL, failed to allocate memory in my_str_from_cstr");
    } else {
        printf("\nWrote a c-string to our string: ");
        print_str(source);
    }

    printf("\n\nTesting my_str_empty:");
    int test_empty = my_str_empty(source);
    if (test_empty == 0){
        if (source->size_m == 0) {
            printf("\nWrong result in my_str_empty");
        } else {
            printf("\nOur string is not empty");
        }
    } else if (test_empty == 1) {
        if (source->size_m != 0) {
            printf("\nWrong result in my_str_empty");
        } else {
            printf("\nOur string is empty.");
        }
    }

    printf("\n\nTesting my_str_getc:");
    int test_getc_1 = my_str_getc(source, 1);
    if (test_getc_1 != source->data[1])
        printf("\nWrong symbol in my_str_getc");
    else
        printf("\nThe symbol at index 1 is '%c'",test_getc_1);

    printf("\n\nTesting my_str_putc:");
    int test_putc1 = my_str_putc(source, 3, 'a');
    if (test_putc1 == -1)
        printf("\nIndex too big in my_str_putc");
    else {
        printf("\nThe string after putting 'a' at index 3 is '");
        print_str(source);
        printf("'");
    }

    printf("\n\nTesting my_str_pushback:");
    int test_pushback = my_str_pushback(source, 's');
    if (test_pushback == -1)
        printf("\nInvalid arguments");
    else {
        printf("\nAfter pushing 's' the string is '");
        print_str(source);
        printf("'");
    }

    printf("\n\nTesting my_str_popback:");
    char last = source->data[source->size_m - 1];
    int test_popback = my_str_popback(source);
    if (test_popback == -1) {
        printf("\nBuffer ended or Invalid arguments");
    } else if (last != test_popback) {
        printf("\nWrong symbol");
    } else {
        printf("\nSymbol '%c' was popped and the string now is '",test_popback);
        print_str(source);
        printf("'");
    }

    printf("\n\nTesting my_str_size:");
    size_t test_size = my_str_size(source);
    if (test_size != source->size_m)
        printf("\nWrong size in my_str_size");
    else
        printf("\nThe size of the string is %zu",test_size);

    printf("\n\nTesting my_str_copy:");
    my_str_t to_str;
    int str_cr1 = my_str_create(&to_str, 32);
    int test_copy = my_str_copy(source,&to_str,1);
    if (test_copy == -1)
        printf("\nInvalid arguments");
    for (int i = 0; i < source->size_m; i++)
        if (source->data[i] != to_str.data[i])
            printf("\nWrong result");
    printf("\nCopied ");
    print_str(source);
    printf(" to some string_2");


    printf("\n\nTesting my_str_insert_c:");
    my_str_t my_str_inser;
    int create_str = my_str_create(&my_str_inser,32);
    int add_cstr = my_str_from_cstr(&my_str_inser,"dmsel");
    int test_insert_c = my_str_insert_c(&my_str_inser, 'a', 1);
    if (test_insert_c == -1)
        printf("\nInvalid arguments");
    else {
        printf("\nInserted 'a' into '");
        print_str(&my_str_inser);
        printf("'");
    }


    printf("\n\nTesting my_str_clear:");
    my_str_clear(&to_str);
    if ((&to_str)->size_m != 0)
        printf("\nDid not work");
    else
        printf("\nString was cleared");

    printf("\n\nTesting my_str_insert_cstr:");
    my_str_t str_ins;
    int cr_ins = my_str_create(&str_ins,32);
    int cstr_ins = my_str_from_cstr(&str_ins,"ladybird");
    int test = my_str_insert_cstr(&str_ins, "miss",4);
    printf("\nInserted 'miss' at index 4 into 'ladybird' : ");
    print_str(&str_ins);

    printf("\n\nTesting my_str_insert:");
    my_str_t str_in;
    my_str_t str_to;
    int cr_to = my_str_create(&str_to,32);
    int cr_in = my_str_create(&str_in,32);
    int cstr_in = my_str_from_cstr(&str_in,"birdman");
    int cstr_to = my_str_from_cstr(&str_to, "boy");
    int test_1 = my_str_insert(&str_in, &str_to,4);
    printf("\nInserted 'boy' at index 4 into 'birdman' : ");
    print_str(&str_in);

    printf("\n\nTesting my_str_append:");
    my_str_t to_string;
    int str_cr2 = my_str_create(&to_string, 32);
    int str_from_str_c2 = my_str_from_cstr(&to_string, "lady");
    int test_append = my_str_append(&to_string,source);
    if (test_append == -1)
        printf("\nInvalid arguments");
    size_t len_from_str = source->size_m;
    for (int i = 0; i < len_from_str; i++)
        if (to_string.data[i+to_string.size_m - len_from_str] != source->data[i])
            printf("\nWrong result");
    printf("\nAppended 'woman' to 'lady' : ");
    print_str(&to_string);

    printf("\n\nTesting my_str_append_cstr:");
    my_str_t old_my_str;
    int str_cr3 = my_str_create(&old_my_str, 32);
    int t_copy = my_str_copy(source,&old_my_str,1);
    char cstr_to_append[13] = "mademoiselle";
    int test_append_cstr = my_str_append_cstr(source, cstr_to_append);
    if (test_append_cstr == -1)
        printf("\nInvalid arguments");
    for (int i = 0; i < old_my_str.size_m; i++)
        if (source->data[i] != old_my_str.data[i])
            printf("\nWrong result of my_str_append_cstr");
    for (int i = 0; i < strlen(cstr_to_append); i++)
        if (source->data[i + old_my_str.size_m] != cstr_to_append[i])
            printf("\nWrong result of my_str_append_cstr");
    printf("\nAppended '%s' to 'woman' : ",cstr_to_append);
    print_str(source);


    printf("\n\nTesting my_str_find:");
    my_str_t str_to_find;
    int str_cr4 = my_str_create(&str_to_find, 32);
    int from_cstr = my_str_from_cstr(&str_to_find,"sel");
    size_t test_find = my_str_find(source,&str_to_find,0);
    if (test_find == -1)
        printf("\nSubstring not found or starting point > string size in my_str_find");
    if (test_find != 12)
        printf("\nWrong index of substring in my_str_find");
    printf("\nSubstring 'sel' was found starting at index %zu",test_find);

    printf("\n\nTesting my_str_find_c:");
    size_t test_find_c = my_str_find_c(source, 'w', 0);
    if (test_find_c == -1)
        printf("\nChar not found or starting point > string size in my_str_find_c");
    if (test_find_c != 0)
        printf("\nWrong index of character in my_str_find_c");
    printf("\nChar 'w' was found at index %zu",test_find_c);




    printf("\n\nTesting my_str_find_if:");
    size_t test_find_if = my_str_find_if(source, test_func_for_str_find_if);
    if (test_find_if != 0)
        printf("\nWrong symbol index");
    printf("\nThe first symbol in string '");
    print_str(source);
    printf("' to appear in string 'emma' is at index %zu",test_find_if);
    print_str(&to_string);
    printf("' is at index %zu",test_find_if);

    printf("\n\nTesting my_str_read_file:\n'");
    my_str_t read_file;
    int test_read_str = my_str_create(&read_file,60);
    int test_read = my_str_read_file(&read_file, file1);
    if (test_read == -1)
        printf("\nCouldn't read_file");
    print_str(&read_file);
    printf("' was read from file as a string of capacity 60.");
    fclose(file1);

    printf("\n\nTesting my_str_read_until_blankspace\n '");
    my_str_t read_blank;
    int test_blank = my_str_create(&read_blank,32);
    FILE *file2 = fopen(my_f, "r");
    int test_r = my_str_read_file_until_blankspace(&read_blank, file2);
    if (test_r == -1)
        printf("\nInvalid arguments");
    else {
        print_str(&read_blank);
        printf("' was read as the symbols before blankspace");
    }
    fclose(file2);


    printf("\n\nTesting my_str_substr_cstr:");
    my_str_t str_1_sub;
    char str_2_sub[] = "";
    int cr_1 = my_str_create(&str_1_sub,32);
    int add_1 = my_str_from_cstr(&str_1_sub,"wonderwoman");
    size_t beg = 3;
    size_t end = 9;
    int test_sub = my_str_substr_cstr(&str_1_sub, str_2_sub, beg, end);
    if (test_sub == -1)
        printf("\nInvalid arguments");
    else {
        printf("\nThe substring of '");
        print_str(&str_1_sub);
        printf("' from index 3 to 9 was written to string: %s", str_2_sub);
    }
    printf("\n\nTesting my_str_cmp:\n");
    char string_2[] = "mothers";
    int create = my_str_from_cstr(source, "mother");
    int test_cmp = my_str_cmp(source, string_2);
    int test_using_strcmp = strcmp(source->data, string_2);
    if (test_cmp == 1) {
        if (test_using_strcmp <= 0)
            printf("Wrong results: ");
        printf("%s > %s\n", source->data, string_2);
    } else if (test_cmp == -1) {
        if (test_using_strcmp >= 0)
            printf("\nWrong results: ");
        printf("%s < %s", source->data, string_2);
    } else if (test_cmp == 0) {
        if (test_using_strcmp != 0)
            printf("\nWrong results: ");
        printf("%s == %s", source->data, string_2);
    }

    printf("\n\nTesting my_str_reserve:");
    int old_cap = (int) my_str_capacity(source);
    int test_reserve = my_str_reserve(source, 12);
    int capacity = (int) source->capacity_m;
    if (test_reserve == -1)
        printf("\nInvalid arguments/NULL happened\n");
    else {
        printf("\nChanged the capacity of '");
        print_str(source);
        printf("' from %d to %d", old_cap, capacity);
    }
    printf("\n\nTesting my_str_shrink_to_fit:");
    int test_shrink = my_str_shrink_to_fit(source);
    if (source->size_m != source->capacity_m)
        printf("\nDid not shrink: ");
    printf("\nCapacity of '%s' changed from %d to %d", source->data, capacity, (int) source->capacity_m);

    printf("\n\nTesting my_str_read_until_delim:");
    my_str_t string_3;
    char delim = 'd';
    FILE *file3 = fopen(my_f, "r");
    int create_2 = my_str_create(&string_3, 32);
    int test_delim = my_str_read_file_delim(&string_3, file3, delim);
    if (test_delim != 0)
        printf("\nInvalid arguments/NULL happened\n");
    else {
        printf("\nRead from file %s until delimiter '%c' : ", my_f, delim);
        print_str(&string_3);
    }
    fclose(file3);

    printf("\n\nTesting my_str_resize to 10 (with partial deletion):");
    my_str_t old_str;
//    FILE *file4 = fopen(my_f, "r");
    int create_old1 = my_str_create(&old_str,32);
    int old_src1 = my_str_copy(&string_3,&old_str,0);
    int test_resize = my_str_resize(&string_3, 10, 'd');
    printf("\nChanged from '");
    print_str(&old_str);
    printf("' to '");
    print_str(&string_3);

    printf("'\n\nTesting my_str_resize to 10 (with partial addition of symbol 'd'):");
    my_str_t old_source;
    int create_old = my_str_create(&old_source,32);
    int old_src = my_str_copy(source,&old_source,0);
    int test_resize2 = my_str_resize(&my_str, 10, 'd');
    printf("\nChanged from '");
    print_str(&old_source);
    printf("' to '");
    print_str(source);
    printf("'");

    my_str_free(source);

    return 0;
}