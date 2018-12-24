#include <stdio.h>
#include <stdlib.h>
#include "1AHTB.h"

int main(int argc, char** argv) {
	int l = 6;
	CharOcc** list = malloc(l*sizeof(CharOcc*));
	for(int i = 0; i < l; i++) {
		list[i] = malloc(sizeof(CharOcc));
		list[i]->c = 'a' + i;
		list[i]->o = i + 1;
	}
	HuffNode* res = create_huffman_tree(list, l);
	print_huffman(res);
}
