import sys

#Helper function to print array. For testing
def printArray(args):
    print " ".join(args)    

#Helper function to print error messages then exit the program
def throw_error(err):
    print err
    exit(1)

#Helper functiont to check if string is an integer
def is_int(str):
    try:
        float(str)
        return True
    except ValueError:
        return False

#Helper function to validate matrix elements(R and F only valid entries)
def valid_matrix(matrix, numRows, numCols):
    for y in range(0,numRows):
        for x in range(0,numCols):
            
            #if cell has valid element
            if matrix[y][x] != 'R' and matrix[y][x] != 'F':
                return False
                
    return True

#Generate 2D array from input file
def build_matrix(file):
    matrixDimensions = file.readline().split()
    numRows, numCols = int(matrixDimensions[0]), int(matrixDimensions[1])
    if not(numRows > 0) or not(numCols > 0):
        throw_error("Invalid Matrix Dimensions")
   
    matrix = list()
    line = file.readline()
    while 1:
        if not line.strip():
            break
        else:
            matrix.append(line.split())
            line = file.readline()
    
    return matrix, numRows, numCols

def find_second_max_area(count, numRows, numCols, y, x, area_1):
	#find second largest area
	area_2 = 0
	
	for y in range(0, numRows):
		for x in range(0, numCols):
			if count[y][x] == area_1:
				temp_area_2 = second_max_area(count, numRows, numCols, y, x, area_1)
				if temp_area_2 > area_2:
					area_2 = temp_area_2
				if area_2 == area_1:
					return area_2
	return area_2

def second_max_area(count, numRows, numCols, y_coord, x_coord, area_1):
	temp_max, max = 0, 0;
	#remove largest square from matrix
	for x in range(0, area_1):
		for y in range(0, area_1):
			count[y_coord + y][x_coord + x] = 0
            
	for y in range(0, numRows):
		for x in range(0, numCols):
			temp_max = count[y][x]
			if temp_max > max:
				max = temp_max
				if area_1 == max:
					return max
	return max
	
def max_area(matrix, numRows, numCols):
    
    """
    max list contains {maximum size of square, 
                        y coordinate of top right of square,
                        x coordinate of top right of square}
    """
    max, largest_square_y, largest_square_x, = 0,0,0
    
    
    #each cell in the count matrix keeps track of how big a square 
    #could be made if we used the corresponding cell in the matrix 
    #as the top left corner of the square
    count = [[9 for x in range(numCols)] for y in range(numRows)]
    count[numRows-1][numCols-1] = 1
    count[numRows-1][0] = 1

    #numRows corresponds to y
    #numCols corresponds to x
    for y in reversed(range(0,numRows)):
        for x in reversed(range(0,numCols)):
            
            #if cell is reserved
            if matrix[y][x] == 'R':
                count[y][x] = 0
                
            #if not a boundary or a corner    
            elif y != numRows - 1 and x !=numCols - 1:
                count[y][x] = 1 + min(count[y][x+1],
                                      count[y+1][x+1], 
                                      count[y+1][x])
            
            #handles boundary and corner cases
            else:
                count[y][x] = 1
                
            if count[y][x] > max:
                max = count[y][x]
                largest_square_y, largest_square_x = y, x
            
            
    return count, max, largest_square_y, largest_square_x
    
    

#Open input file. If incorrect # of arguments are given, throw error
if(len(sys.argv) < 3):
    throw_error("Both input and output file must be specified")
infile = open(sys.argv[1], 'r')
outfile = open(sys.argv[2], 'w')
numberOfMatrices = infile.readline()

if not is_int(numberOfMatrices):
    throw_error("Invalid value for the # of Matrices in input file")
    
else:
    numberOfMatrices = int(numberOfMatrices)
    
    
area_1, area_2, temp_area_2, y_coord, x_coord = 0, 0, 0, 0, 0

#For each matrix in input file, find largest
#and 2nd largest square of 'F' values
for i in range(0, numberOfMatrices):
    
    #build matrix from input file
    matrix, numRows, numCols = build_matrix(infile)
    
    if not valid_matrix(matrix, numRows, numCols):
        throw_error("Invalid Matrix Entries")
    
    #find largest area
    count, area_1, y_coord, x_coord = max_area(matrix, numRows, numCols)
    
    area_2 = find_second_max_area(count, numRows, numCols, y_coord, x_coord, area_1)
    

    
    print >> outfile, area_1**2, area_2**2
    
    
