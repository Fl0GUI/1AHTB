// created by Flor Guilini
// implementation of static huffman tree building



typedef struct node {
	int c;
	struct node* left;
    struct node* right;

	int o;
} HuffNode, CharOcc ;

/*
 * implementation for building a huffman tree
 * param: o, array of symbols and their occurences in the text
 * param: s, length of o
 * return: pointer to root of huffman tree
 */
HuffNode* create_huffman_tree(CharOcc** o, int s);

void print_huffman(HuffNode* t);
