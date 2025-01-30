class Solution:
    def maxArea(self, height: list[int]) -> int:
        pointer_back = 0
        pointer_front = len(height) - 1
        max_area = 0
        
        while pointer_back < pointer_front:
            current_height = min(height[pointer_back], height[pointer_front])
            current_width = pointer_front - pointer_back
            current_area = current_height * current_width
            max_area = max(max_area, current_area)
            
            if height[pointer_back] < height[pointer_front]:
                pointer_back += 1
            else:
                pointer_front -= 1
        
        return max_area

solution = Solution()
print(solution.maxArea([2,3,4,5,18,17,6]))

        