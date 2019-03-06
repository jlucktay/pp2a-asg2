##
# makefile
##

CC = gcc
FLAGS = -ansi -pedantic -Wall

all: partA partB-A partB-C partB-D partB-E partC partD partE

# Part A - Ordered Array, Linear Search
#

partA: ord-array-linear.o test-driver-1-pA.o
	$(CC) -o ord-array-linear ord-array-linear.o test-driver-1-pA.o

ord-array-linear.o: ord-array-linear.c ord-array-linear.h
	$(CC) $(FLAGS) -c ord-array-linear.c

test-driver-1-pA.o: test-driver-1.c ord-array-linear.h
	$(CC) $(FLAGS) -c -o test-driver-1-pA.o \
	-DWORDCOLL_HEADER=\"ord-array-linear.h\" test-driver-1.c



# Part B - Benchmark Driver
#
#    compile individual benchmark executables for all implementations


# Bench: Ordered Array, Linear Search

partB-A: ord-array-linear.o main-bench-pA.o
	$(CC) -o bench-ord-array-linear ord-array-linear.o main-bench-pA.o

main-bench-pA.o: main-bench.c ord-array-linear.h
	$(CC) -c -o main-bench-pA.o \
	-DWORD_COLL=\"ord-array-linear.h\" main-bench.c


# Bench: Linked List, Linear Search

partB-C: ord-linked-list.o main-bench-pC.o
	$(CC) -o bench-ord-linked-list ord-linked-list.o main-bench-pC.o

main-bench-pC.o: main-bench.c ord-linked-list.h
	$(CC) -c -o main-bench-pC.o \
	-DWORD_COLL=\"ord-linked-list.h\" main-bench.c


# Bench: Ordered Array, Binary Search

partB-D: ord-array-binary.o main-bench-pD.o
	$(CC) -o bench-ord-array-binary ord-array-binary.o main-bench-pD.o

main-bench-pD.o: main-bench.c ord-array-binary.h
	$(CC) -c -o main-bench-pD.o \
	-DWORD_COLL=\"ord-array-binary.h\" main-bench.c


# Bench: Unbalanced Binary Search Tree

partB-E: unbal-binary-search-tree.o main-bench-pE.o
	$(CC) -o bench-unbal-binary-search-tree unbal-binary-search-tree.o \
	main-bench-pE.o

main-bench-pE.o: main-bench.c unbal-binary-search-tree.h
	$(CC) -c -o main-bench-pE.o \
	-DWORD_COLL=\"unbal-binary-search-tree.h\" main-bench.c



# Part C - Linked List, Linear Search
#

partC: ord-linked-list.o test-driver-1-pC.o
	$(CC) -o ord-linked-list ord-linked-list.o test-driver-1-pC.o

ord-linked-list.o: ord-linked-list.c ord-linked-list.h
	$(CC) $(FLAGS) -c ord-linked-list.c

test-driver-1-pC.o: test-driver-1.c ord-linked-list.h
	$(CC) $(FLAGS) -c -o test-driver-1-pC.o \
	-DWORDCOLL_HEADER=\"ord-linked-list.h\" test-driver-1.c



# Part D - Ordered Array, Binary Search
#

partD: ord-array-binary.o test-driver-1-pD.o
	$(CC) -o ord-array-binary ord-array-binary.o test-driver-1-pD.o

ord-array-binary.o: ord-array-binary.c ord-array-binary.h
	$(CC) $(FLAGS) -c ord-array-binary.c

test-driver-1-pD.o: test-driver-1.c ord-array-binary.h
	$(CC) $(FLAGS) -c -o test-driver-1-pD.o \
	-DWORDCOLL_HEADER=\"ord-array-binary.h\" test-driver-1.c



# Part E - Unbalanced Binary Search Tree
#

partE: unbal-binary-search-tree.o test-driver-1-pE.o
	$(CC) -o unbal-binary-search-tree unbal-binary-search-tree.o \
	test-driver-1-pE.o

unbal-binary-search-tree.o: unbal-binary-search-tree.c unbal-binary-search-tree.h
	$(CC) $(FLAGS) -c unbal-binary-search-tree.c

test-driver-1-pE.o: test-driver-1.c unbal-binary-search-tree.h
	$(CC) $(FLAGS) -c -o test-driver-1-pE.o \
	-DWORDCOLL_HEADER=\"unbal-binary-search-tree.h\" test-driver-1.c
