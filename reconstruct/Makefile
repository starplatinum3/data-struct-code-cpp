main.o : test.o build_tree.o print_tree.o queue.o tree.o
	gcc -o main.o test.o build_tree.o print_tree.o queue.o tree.o
test.o: test_for_print_tree.c
	gcc -c test_for_print_tree.c -o test.o
build_tree.o: build_tree.h build_tree.c
	gcc -c build_tree.c -o build_tree.o
print_tree.o: print_tree.h print_tree.c
	gcc -c print_tree.c -o print_tree.o
queue.o: queue.h queue.c
	gcc -c queue.c -o queue.o
tree.o: tree.h tree.c
	gcc -c tree.c -o tree.o
clean:
	rm *.o



