#include "1AHTB.h"
#include <stdlib.h>
#include <stdio.h>

void sort_huffman(CharOcc** o, int s) {
	// assume it is sorted for now
	return;
}


HuffNode* create_huffman_tree(CharOcc** o, int s) {
	if(s == 1) // base case: only one character
		return o[0];

	sort_huffman(o,s);
	int ts, te, ns; // Tree Start, Tree End, Node Start
	int i, j;
	HuffNode* hn; // Hufman Node

	// combine first two
	hn = malloc(sizeof(HuffNode));
	hn->left = o[0];
	hn->right = o[1];
	hn->o = o[0]->o + o[1]->o;
	o[0] = hn;

	// set variables
	ts = 0;
	te = 1;
	ns = 2;
	
	// loop for non trees
	while (ns < s)
	{ // while there are nodes left
		//find smallest 2
		if(o[ts]->o < o[ns]->o) {
			i = ts++;
			j = ns>=s || o[i]->o < o[ns]->o ? ts++ : ns++;
		} else {
			i = ns++;
			j = ns<s && o[i]->o < o[ts]->o ? ns++ : ts++;
		}
		hn = malloc(sizeof(HuffNode));
		hn->left = o[i];
		hn->right = o[j];
		hn->o = o[i]->o + o[j]->o;
		hn->c = 0;
		o[te++] = hn;
	}

	// loop for trees
	while(ts < te - 1)
	{ //While there are more than 1 tree
		hn = malloc(sizeof(HuffNode));
		hn->o = 0;
		hn->left = o[ts];
		hn->o += o[ts++]->o;
		hn->right = o[ts];
		hn->o += o[ts++]->o;
		hn->c = 0;
		o[te++] = hn;
	}

	printf("ended at %i\n", te - 1);
	return o[te - 1];
}

void print_huffman(HuffNode* t) {
	if(t->c != 0)
	{ //It's a leaf
		printf("leaf: %c-%i\n", t->c, t->o);
		return;
	} else
	{ //It's internal
		printf("node: %i\n", t->o);
		printf("\n");
		print_huffman(t->left);
		printf("\n");
		print_huffman(t->right);
	}
}
