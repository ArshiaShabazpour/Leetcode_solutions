class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0:
            return False
        flag = True 
        degree = 10
        reverse = 10
        while(x%degree !=x):
            degree = degree*10
        while(degree >=reverse):
            y = x%degree - (x%(degree/10))
            z = x%reverse - (x%(reverse/10))
            if y//(degree/10) != z//(reverse/10) :
                flag = False
            degree = degree /10
            reverse = reverse *10
        return flag 