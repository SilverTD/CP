"""
5
      *
     ***
*********
 ***
  *
  
10
               *
              ***
             *****
            *******
           *********
*********************
 *********
  *******
   *****
    ***
     *
"""

n = int(input())

rows = n // 2
for i in range(0, rows):
    for j in range(i, rows + (2*rows)):
        print(end=" ")
    for j in range(i):
        print(end="*")
    for j in range(i + 1):
        print(end="*")
    print("\r")

print("*" * (2*(2 * rows + 1) - 1))

for i in range(0, rows):
    for j in range(i + 1):
        print(end=" ")
    for j in range(i, rows - 1):
        print(end="*")
    for j in range(i, rows):
        print(end="*")
    print("\r")
