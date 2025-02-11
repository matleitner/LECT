def matmult(A, B):
   C = [len(B[0])*[0] for i in range(len(A))]
   for l in range(len(A)):
      for c in range(len(B[0])):
         for i in range(len(A[0])):
            C[l][c]+=A[l][i]*B[i][c]
            print(C, "aa")
   return C
matmult(	
[[1, 0], [2, 3]], [[4, 5], [0,6]])