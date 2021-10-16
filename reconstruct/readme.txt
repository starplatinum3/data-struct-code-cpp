compile example

norton@norton-laptop:~/learning/sample code/tree/reconstruct$ make
gcc -c test_for_print_tree.c -o test.o
gcc -c build_tree.c -o build_tree.o
gcc -c print_tree.c -o print_tree.o
gcc -c queue.c -o queue.o
gcc -c tree.c -o tree.o
gcc -o main.o test.o build_tree.o print_tree.o queue.o tree.o
norton@norton-laptop:~/learning/sample code/tree/reconstruct$ ./main.o 
insert node to queue
root is 56
insert :73
insert :46
insert :59
insert :53
insert :98
insert :93
creat tree succuess!Tree heigh is:4
_______________________
breath begin,enter root:
              56                
      ________||________        
      46              73        
  ____||____      ____||____    
  oo      53      59      98    
__||__  __||__  __||__  __||__  
oo  oo  oo  oo  oo  oo  93  oo  
-----------
breath end!
-----------

compile example 2

rton@norton-laptop:~/learning/sample code/tree/reconstruct$ gcc print_tree_final.c 
norton@norton-laptop:~/learning/sample code/tree/reconstruct$ ./post.out
insert node to queue
root is 32
insert :42
insert :75
insert :9
creat tree succuess!Tree heigh is:3
_______________________
breath begin,enter root:
      32        
  ____||____    
   9      42    
__||__  __||__  
oo  oo  oo  75  
-----------
breath end!
-----------


