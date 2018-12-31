#include "1AHTB.h"
#include <stdlib.h>
#include <stdio.h>

#define BITTYPE long int


HuffNode* create_huffman_tree(CharOcc** o, int s) {
	if(s == 1) // base case: only one character
		return o[0];

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
	
	// return the last tree
	return o[te - 1];
}

void print_huffman_internal(HuffNode* t, BITTYPE prefix, unsigned int depth) {
	if( t->c != 0 )
	{ // node is a leaf
		int f=0, c;
 		for(int i=sizeof(BITTYPE) - 1;i>=0;i--) {
 			c = (prefix >> i) & 1;
 			f = f || c == 1;
			if(i+1 <= depth)
 				printf("%i", c);
 			else
 				printf(" ");
 		}
		printf("\t%c\n", t->c, depth);
	
	} else {
		prefix = (prefix << 1) & ~1;
		depth++;
		print_huffman_internal(t->left, prefix, depth);
		prefix = prefix | 1;
		print_huffman_internal(t->right, prefix, depth);
	}

}

void print_huffman(HuffNode* t) {
	print_huffman_internal(t, 0, 0);
}

