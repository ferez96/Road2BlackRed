# https://codelearn.io/Training/Detail?Id=188560
# Jack and Jane are naughty kids. They love walking along the street at night and shout loudly so that the neighbor 
# can't sleep. One day, they are bored of shouting meaningless sound and come up with new game called “AHH”. They take 
# turn to shout the word “AHH” as quick as possible. Assuming that in turn k – 1, the first one will shout: AHH. Next, 
# the person in turn k will take the copy of the word of the person in k–1, then shout AH...H with k+2 characters H and 
# then take another copy of the word of the person in k–1. The neighbor was very angry with that game. They think about 
# a challenge for Jack and Jane. They ask Jack and Jane to find the nth character in the string they shouted. If Jack 
# and Jane can find it, they will be given a lot of candies; otherwise, they must stop this game. Jack and Jane are so 
# confident that they agree very quickly. However, the game is more challenging than they think. Help them to solve this

# Example: 

# For input n = 11. The output should be:  findNthCharacter(n) = 'A'. 
# Because:
# Turn 0: Word = AHH
# Turn 1: Word = AHHAHHHAHH = (AHH) + (AHHH) + (AHH)
# Turn 2: Word = AHHAHHHAHHAHHHHAHHAHHHAHH = (AHHAHHHAHH) + (AHHHH) + (AHHAHHHAHH)
# In turn 0 and 1, the length of word the player in these turn shouts are smaller than n, so we can not get the answer. 
# In turn 2, the length of word the player in this turn shouts is greater than n, and the 11th character is A.
# Input/Output:

# [Execution time limit] 0.5s (C++), 3s (Java , C#), 4s (Python,JavaScript, Go)

# [Input] integer n

#  1 ≤ n ≤ 109 

# [Output] integer
# The nth character of word (1-based)

# f(k) = 2*f(k-1) + (k+1)
# = 2^2.f(k-2) + 2k + k+1
# = 2^3.f(k-3) + 2^2(k-1) + 2k + k+1
# = Sigma(2^x(k-x+1))
# = (k+1)Sigma(2^x)+ Sigma(x2^x)

def findNthCharacter(n):
    return 'A'
