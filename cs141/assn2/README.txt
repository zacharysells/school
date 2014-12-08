Algorithm: 

For each cell in the Matrix, we want to keep a count of how big a 
square of F's could be made if we were to use that cell as the top left corner of the
square. 

Start iteration at the bottom right and move left, then up a row, until
the whole matrix has been covered.

At each iteratation, there are 3 cases:
    1.) The cell is reserved: Set count to 0. This is justified because a
    reserved cell cannot make up the top left corner of a square.
    
    2.) If cell is free and it is a bottom corner: Set count to 1. This is justified
    because a single free cell can make it's own square of size 1.
    
    3.) Otherwise: Set count to 1 plus the minimum between 
    [count(cell to the east), count(cell to the south-east), count(cell to the south)]
    
By keeping track of the maximum count throughout the iteration. We return that 
value squared to get the largest area possible. 

To get the second largest area:
    Take the largest square of F's that we got from the previous steps and set 
    each element to Reserved(R). Then calculate the second largest square by 
    repeated the above steps with the new matrix. 

Worst Time complexity:

Where 'n' is the height of a matrix, the time complexity of each segment of my
algorithm is as follows:
    
    O(n) - loading matrix from file into memory. Each line of the matrix takes 
    constant time. So for n lines we get O(n)
    
    O(n^2) - iterating through initial matrix. Once for each element in the matrix
    
    O(n^2) - iterating through secondary matrix that has had it's largest square
    removed

Adding all of these values together we get O(2n^2 + n) which is just O(n^2) in
the worst case

I used a 2D array because my algorithm requires a lot of indexing. Indexing can be 
done in constant time with arrays so that made my code more efficient.

Test Cases(input.txt):
	My test cases include:
	1.) Input matrix of size 1
	2.) Input example given in assignment description
	3.) All cells reserved
	4.) Input from matrix with prior-known correct solution
	5.) Large input(14x14)
