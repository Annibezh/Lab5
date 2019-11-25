#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <ctype.h>

static struct option long_opts[] = {
		{"help", no_argument, NULL,  'h' },
		{"size", optional_argument, NULL, 's'},
		{"file", required_argument, NULL,  'f' },
		{"add", no_argument, NULL,  'a' },
};

bool printedOpts[] = { false, false, false, false };

void printArg(int id) {
	if (printedOpts[id]) return;

	if (optarg) {
		std::cout << "Argument: " << long_opts[id].name << " Value: " << optarg << std::endl;
	}
	else {
		std::cout << "Argument: " << long_opts[id].name << std::endl;
	}
	printedOpts[id] = true;
}

int main(int argc, char** argv) {
	int rez = 0;
	int option_index;
	while (true) {
		rez = getopt_long(argc, argv, "advc:maf:", long_opts, &option_index);
		if (rez == -1) break;

		switch (rez) {
		case 'h':
			printArg(0);
			break;
		case 's':
			printArg(1);
			break;
		case 'f':
			printArg(2);
			break;
		case 'a':
			printArg(3);
			break;
		default:
			printf("Unknown argument!\n");
		}
	}
	return 0;
}
