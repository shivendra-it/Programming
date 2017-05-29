public class RobotMovement {

int count;
static int m = 4;
static int n = 4;

/*
	The idea of up,down,left,right is to
	check if it is possible move.
	if yes then take it and try next cominations.
	then backtrack it.
*/

void Up(int x,int y, int matrix[][])
{
	if(y==0)
		return;
	else{
		if(matrix[x][y-1]==1)
			return;
		else{
			matrix[x][y-1]=1;
			NextMove(x, y-1, matrix);
			matrix[x][y-1]=0;
			}
		}	
}
void Down(int x,int y, int matrix[][])
{
	if(x==m-1 && y==n-1){
		count++;
		matrix[x][y]=1;
		return;
	}
	else{
		if(y==3)
			return;
		else{
			if(matrix[x][y+1]==1)
				return;
			else{
				matrix[x][y+1]=1;
				NextMove(x, y+1, matrix);
				matrix[x][y+1]=0;
				}
			}
		}	
}

void Left(int x,int y, int matrix[][])
{
	if(x==0)
		return;
	else{
		if(matrix[x-1][y]==1)		
			return;		
		else{
			matrix[x-1][y]=1;
			NextMove(x-1, y, matrix);
			matrix[x-1][y]=0;
			}	
		}	
}

void Right(int x,int y, int matrix[][])
{
	if(x==m-1 && y==n-1){
		count++;
		matrix[x][y]=1;
		return;
	}
	else{
		if(x==3)
			return;
		else{
			if(matrix[x+1][y]==1)
				return;
			else{
				matrix[x+1][y]=1;
				NextMove(x+1, y, matrix);
				matrix[x+1][y]=0;
				}
			}
		}	
}

void NextMove(int x,int y,int matrix[][])
{
	// Marking Visited
		matrix[x][y]=1;
	// Check all possible move	
		Left(x,y,matrix);
		Right(x,y,matrix);
		Up(x,y,matrix);
		Down(x,y,matrix);		
}
public static void main(String[] args) {
	// Defining the matrix
		int matrix [][]= new int [m][n];
		RobotMovement obj= new RobotMovement();
		obj.count=0;
		matrix[0][0]= 1;
	// Taking First move	 
		obj.NextMove(1, 0, matrix);
		System.out.println(obj.count);
	}
}