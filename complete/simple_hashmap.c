/*
Hashmap test
*/

#include <stdio.h>
#include <stdlib.h>

#define PRIME 31 // my magic number

typedef struct {
    void** values;
    size_t len;
} hashmap;

hashmap* hashmap_init(){
    hashmap* map = (hashmap*) malloc(sizeof(hashmap));
    (*map).len = PRIME;
    (*map).values = (void**) malloc(sizeof(void**) * (*map).len);
    int i = 0;
    char** val = (char**) (*map).values;
    for (i = 0; i < (*map).len; i++) val[i] = (char*) NULL;
    return map;
}

size_t hashmap_hash(char* key, size_t len){
    size_t i = 0, sum = 0;
    for (i = 0; i < len; i++){
        if (!key[i]) break;
        sum += i * key[i];
    }
    sum *= sum;
    sum /= i;
    
    return sum % len;
}

void hashmap_free(hashmap* map){
    if (map && (*map).values) 
        free((*map).values);
    if (map) free(map);
}

int main(){
    hashmap* map = hashmap_init();
    hashmap_free(map);
    char* key = "cheese";
    printf("%s - %llu\n", key, hashmap_hash(key, PRIME));
    key = "cehese";
    printf("%s - %llu\n", key, hashmap_hash(key, PRIME));
    key = "lskdfj;a";
    printf("%s - %llu\n", key, hashmap_hash(key, PRIME));
    key = "dfidsfojvf";
    printf("%s - %llu\n", key, hashmap_hash(key, PRIME));
    key = "crackers";
    printf("%s - %llu\n", key, hashmap_hash(key, PRIME));
    key = "1111111";
    printf("%s - %llu\n", key, hashmap_hash(key, PRIME));
    key = "    ";
    printf("%s - %llu\n", key, hashmap_hash(key, PRIME));
    key = "asldkfjas;flkdsjfa;flkdf;alsdkfajsdf;dlsak";
    printf("%s - %llu\n", key, hashmap_hash(key, PRIME));
    

    return 0;
}
